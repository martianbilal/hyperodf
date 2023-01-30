#!/bin/bash
# make 
# make install
  # -device loader,file=./boot-sect.bin,force-raw=on,cpu-num=0 \
  # -drive file=./bootloader.qcow2,format=qcow2 \
./build/qemu-system-x86_64 \
  -L ./pc-bios \
  -cpu host,vmx=on \
  -hda ../simple-kernel/snapshot.qcow2 \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log
