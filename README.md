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
rustup install 1.46.0
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


## Usage

### Global Variables to be set

- `KVMSAMPLES` - The path to the kvm-samples directory
- `MOD_QEMU` - The path to the modified qemu source directory
- `IMAGE` - The path to the image file to be used for the VM
- `KERNEL` - The path to the kernel file to be used for the VM

