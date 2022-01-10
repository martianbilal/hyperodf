#!/bin/bash
make 
make install
/usr/local/bin/qemu-system-x86_64 \
  -m 512 \
  -smp 1 \
  -hda ./boot-sect.bin \
  -net none \
  -cpu host,vmx=on \
  -enable-kvm \
  --trace events=./events \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log
