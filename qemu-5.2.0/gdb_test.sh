#!/bin/bash
make 
make install
gdb -q --args /usr/local/bin/qemu-system-x86_64 \
  -cpu host,vmx=on \
  -device loader,file=./boot-sect.bin,force-raw=on,cpu-num=0 \
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log