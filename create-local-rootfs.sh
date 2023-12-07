#!/bin/bash
export distro="ubuntu" # example
export ROOTFS_DIR="$(realpath kata-containers/tools/osbuilder/rootfs-builder/rootfs)"
sudo rm -rf "${ROOTFS_DIR}"
pushd kata-containers/tools/osbuilder/rootfs-builder/ || exit
script -fec 'sudo -E AGENT_INIT=yes USE_DOCKER=true ./rootfs.sh "${distro}"'
popd || exit