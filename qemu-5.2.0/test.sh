#!/bin/bash
# make 
# make install
/usr/local/bin/qemu-system-x86_64 \
  -L ./pc-bios \
  -cpu host,vmx=on \
  -device loader,file=./boot-sect.bin,force-raw=on,cpu-num=0 \
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log
