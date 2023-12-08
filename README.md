# HyperODF


## Installation
### Installing Kata container

First run :
```bash
$ bash -c "$(curl -fsSL https://raw.githubusercontent.com/kata-containers/kata-containers/main/utils/kata-manager.sh)"
```

Then install go: 
```bash
wget https://go.dev/dl/go1.16.4.linux-amd64.tar.gz
rm -rf /usr/local/go && tar -C /usr/local -xzf go1.16.4.linux-amd64.tar.gz
echo 'export PATH=$PATH:/usr/local/go/bin' >> ~/.bashrc
source ~/.bashrc
go version
# version must be the one in the versions.yaml file
```

Then install rust:
```bash
sudo snap install rustup --classic
rustup install 1.47.0
```

Build and install kata containers
```bash
pushd kata-containers/src/runtime
make && sudo -E "PATH=$PATH" make install
sudo mkdir -p /etc/kata-containers/
sudo install -o root -g root -m 0640 /usr/share/defaults/kata-containers/configuration.toml /etc/kata-containers
popd
ls /usr/local/bin/ | grep kata
ls /usr/share/defaults/kata-containers/
ls /etc/kata-containers/configuration.toml
```

Configuring the kata-containers to use initrd image
```bash
sudo sed -i 's/^\(image =.*\)/# \1/g' /etc/kata-containers/configuration.toml
sudo sed -i 's/^# \(initrd =.*\)/\1/g' /etc/kata-containers/configuration.toml
```
Make sure this worked using the following command:
```bash
sudo vi /etc/kata-containers/configuration.toml
```

In order to build the custom kata-agent, use the following commands:
```bash
export ARCH="$(uname -m)"
if [ "$ARCH" = "ppc64le" -o "$ARCH" = "s390x" ]; then export LIBC=gnu; else export LIBC=musl; fi
[ "${ARCH}" == "ppc64le" ] && export ARCH=powerpc64le
rustup target add "${ARCH}-unknown-linux-${LIBC}"
make -C kata-containers/src/agent SECCOMP=no
```
These commands build kata-agent without seccomp support.

Create a local rootfs for initrd image:
```bash
export distro="ubuntu" # example
export ROOTFS_DIR="$(realpath kata-containers/tools/osbuilder/rootfs-builder/rootfs)"
sudo rm -rf "${ROOTFS_DIR}"
pushd kata-containers/tools/osbuilder/rootfs-builder/
script -fec 'sudo -E AGENT_INIT=yes USE_DOCKER=true ./rootfs.sh "${distro}"'
popd
```
Build the agent without seccomp support:
```bash
script -fec 'sudo -E AGENT_INIT=yes USE_DOCKER=true SECCOMP=no ./rootfs.sh "${distro}"'
```
Add your custom agent binary to the rootfs with the following commands:
```bash
export ARCH="$(uname -m)"
[ "${ARCH}" == "ppc64le" ] || [ "${ARCH}" == "s390x" ] && export LIBC=gnu || export LIBC=musl
[ "${ARCH}" == "ppc64le" ] && export ARCH=powerpc64le
sudo install -o root -g root -m 0550 -T "${ROOTFS_DIR}/../../../../src/agent/target/${ARCH}-unknown-linux-${LIBC}/release/kata-agent" "${ROOTFS_DIR}/sbin/init"

```

Build an initrd image:
```bash
pushd kata-containers/tools/osbuilder/initrd-builder
script -fec 'sudo -E AGENT_INIT=yes USE_DOCKER=true ./initrd_builder.sh "${ROOTFS_DIR}"'
popd
```

Install the initrd image:
```bash
pushd kata-containers/tools/osbuilder/initrd-builder
commit="$(git log --format=%h -1 HEAD)"
date="$(date +%Y-%m-%d-%T.%N%z)"
image="kata-containers-initrd-${date}-${commit}"
sudo install -o root -g root -m 0640 -D kata-containers-initrd.img "/usr/share/kata-containers/${image}"
(cd /usr/share/kata-containers && sudo ln -sf "$image" kata-containers-initrd.img)
popd
```

Build and install setup the kernel for kata-containers: 
```bash
./build-kernel.sh -v 5.10.25 -f -d setup
./build-kernel.sh -v 5.10.25 -d build
sudo ./build-kernel.sh -v 5.10.25 -d install
```

Build a custom QEMU:
```bash
qemu_version="v5.2.0"
pushd ~/tools/
git clone -b "${qemu_version}" https://github.com/qemu/qemu.git
your_qemu_directory="$(realpath qemu)"
popd
```
```bash
packaging_dir="$(realpath kata-containers/tools/packaging)"
"$packaging_dir/scripts/apply_patches.sh" "$packaging_dir/qemu/patches/5.2.x/"
```

You may need to add "--disable-werror" to the kata.cfg file.

```bash
pushd "$your_qemu_directory"
"$packaging_dir/scripts/configure-hypervisor.sh" kata-qemu > kata.cfg
eval ./configure "$(cat kata.cfg)"
make -j $(nproc --ignore=1)
Optional
sudo -E make install
popd
```

In /etc/kata-containers/configuration.toml, change path = "/path/to/qemu/build/qemu-system-x86_64" to point to the correct QEMU binary.


> ℹ️ If you are using cgroupv2, make sure you set the sandbox_cgroup_only=true in the configuration.toml file.


### Usage

### Global Variables to be set

- `KVMSAMPLES` - The path to the kvm-samples directory
- `MOD_QEMU` - The path to the modified qemu source directory
- `IMAGE` - The path to the image file to be used for the VM
- `KERNEL` - The path to the kernel file to be used for the VM

