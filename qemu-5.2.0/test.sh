#!/bin/bash
make 
make install
/usr/local/bin/qemu-system-x86_64 \
  -m 1G \
  -hda ./boot-sect.bin \
  -net none\
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log
