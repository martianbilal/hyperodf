// Copyright (c) 2016 Intel Corporation
//
// SPDX-License-Identifier: Apache-2.0
//

package virtcontainers

import (
	"context"
	"runtime"

	hodf "github.com/kata-containers/kata-containers/src/runtime/pkg/hodf"
	"github.com/kata-containers/kata-containers/src/runtime/pkg/katautils/katatrace"
	deviceApi "github.com/kata-containers/kata-containers/src/runtime/virtcontainers/device/api"
	deviceConfig "github.com/kata-containers/kata-containers/src/runtime/virtcontainers/device/config"
	"github.com/kata-containers/kata-containers/src/runtime/virtcontainers/pkg/cgroups"
	"github.com/kata-containers/kata-containers/src/runtime/virtcontainers/pkg/compatoci"
	vcTypes "github.com/kata-containers/kata-containers/src/runtime/virtcontainers/pkg/types"
	"github.com/sirupsen/logrus"
)

// apiTracingTags defines tags for the trace span
var apiTracingTags = map[string]string{
	"source":    "runtime",
	"packages":  "virtcontainers",
	"subsystem": "api",
}

func init() {
	runtime.LockOSThread()
}

var virtLog = logrus.WithField("source", "virtcontainers")

// SetLogger sets the logger for virtcontainers package.
func SetLogger(ctx context.Context, logger *logrus.Entry) {
	fields := virtLog.Data
	virtLog = logger.WithFields(fields)

	deviceApi.SetLogger(virtLog)
	compatoci.SetLogger(virtLog)
	deviceConfig.SetLogger(virtLog)
	cgroups.SetLogger(virtLog)
}

// CreateSandbox is the virtcontainers sandbox creation entry point.
// CreateSandbox creates a sandbox and its containers. It does not start them.
func CreateSandbox(ctx context.Context, sandboxConfig SandboxConfig, factory Factory) (VCSandbox, error) {
	span, ctx := katatrace.Trace(ctx, virtLog, "CreateSandbox", apiTracingTags)
	defer span.End()

	s, err := createSandboxFromConfig(ctx, sandboxConfig, factory)

	return s, err
}

func createSandboxFromConfig(ctx context.Context, sandboxConfig SandboxConfig, factory Factory) (_ *Sandbox, err error) {
	hodf.H_log("createSandboxFromConfig called")

	span, ctx := katatrace.Trace(ctx, virtLog, "createSandboxFromConfig", apiTracingTags)
	defer span.End()

	hodf.H_log("Creating sandbox")
	// Create the sandbox.
	s, err := createSandbox(ctx, sandboxConfig, factory)
	if err != nil {
		return nil, err
	}

	// cleanup sandbox resources in case of any failure
	defer func() {
		if err != nil {
			hodf.H_log("Error occurred, deleting sandbox")
			s.Delete(ctx)
		}
	}()

	hodf.H_log("Creating sandbox network")
	// Create the sandbox network
	if err = s.createNetwork(ctx); err != nil {
		return nil, err
	}

	// network rollback
	defer func() {
		if err != nil {
			hodf.H_log("Error occurred, removing sandbox network")
			s.removeNetwork(ctx)
		}
	}()

	// Move runtime to sandbox cgroup so all process are created there.
	if s.config.SandboxCgroupOnly {
		hodf.H_log("Creating cgroup manager for sandbox")
		if err := s.createCgroupManager(); err != nil {
			return nil, err
		}

		hodf.H_log("Setting up sandbox cgroup")
		if err := s.setupSandboxCgroup(); err != nil {
			return nil, err
		}
	}

	hodf.H_log("Starting VM")
	// Start the VM
	if err = s.startVM(ctx); err != nil {
		return nil, err
	}

	// rollback to stop VM if error occurs
	defer func() {
		if err != nil {
			hodf.H_log("Error occurred, stopping VM")
			s.stopVM(ctx)
		}
	}()

	hodf.H_log("Post creating network")
	s.postCreatedNetwork(ctx)

	hodf.H_log("Getting and storing guest details")
	if err = s.getAndStoreGuestDetails(ctx); err != nil {
		return nil, err
	}

	hodf.H_log("Creating containers")
	// Create Containers
	if err = s.createContainers(ctx); err != nil {
		return nil, err
	}

	hodf.H_log("createSandboxFromConfig done")
	return s, nil
}

// CleanupContainer is used by shimv2 to stop and delete a container exclusively, once there is no container
// in the sandbox left, do stop the sandbox and delete it. Those serial operations will be done exclusively by
// locking the sandbox.
func CleanupContainer(ctx context.Context, sandboxID, containerID string, force bool) error {
	span, ctx := katatrace.Trace(ctx, virtLog, "CleanupContainer", apiTracingTags)
	defer span.End()

	if sandboxID == "" {
		return vcTypes.ErrNeedSandboxID
	}

	if containerID == "" {
		return vcTypes.ErrNeedContainerID
	}

	unlock, err := rwLockSandbox(sandboxID)
	if err != nil {
		return err
	}
	defer unlock()

	s, err := fetchSandbox(ctx, sandboxID)
	if err != nil {
		return err
	}
	defer s.Release(ctx)

	_, err = s.StopContainer(ctx, containerID, force)
	if err != nil && !force {
		return err
	}

	_, err = s.DeleteContainer(ctx, containerID)
	if err != nil && !force {
		return err
	}

	if len(s.GetAllContainers()) > 0 {
		return nil
	}

	if err = s.Stop(ctx, force); err != nil && !force {
		return err
	}

	if err = s.Delete(ctx); err != nil {
		return err
	}

	return nil
}
