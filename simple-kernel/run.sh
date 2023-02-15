#!/bin/bash
  # -drive file=./bootloader.qcow2,format=qcow2 \
  # -monitor unix:qemu-monitor-socket,server,nowait \  # -hda ./bootloader.bin \
  # -device loader,file=./bootloader.bin,force-raw=on,cpu-num=0 \
  # --trace events=./events\
  # -drive file=../qcowimage,format=qcow2 \
  # -boot d -hda ./bootloader.bin \
  # -drive file=../qcowimage,format=qcow2 \
  # -drive file=./bootloader.qcow2,format=qcow2,share-rw=on \
  # -drive file=./bootloader.qcow2,format=qcow2 \
  # -device loader,file=./bootloader.bin,force-raw=on,cpu-num=0 \
  # -drive file=./snapshot.qcow2,format=qcow2 \
  # -blockdev driver=qcow2,file.filename=./bootloader.qcow2,file.locking=off,file.driver=file,node-name=hd \
  # -L ../qemu-5.2.0/pc-bios \
  # -pidfile vm.pid \
  # -enable-kvm \
  qemu-system-x86_64 \
  -cpu host,vmx=on \
  -L /root/kvm-samples/qemu-5.2.0/roms/seabios/out \
  -bios bios.bin \
  -enable-kvm \
  -d int\
  -m 1G \
  -snapshot \
  -drive file=./snapshot.qcow2,format=qcow2 \
  -nographic \
  -D vm.asm.log \
  -monitor unix:qemu-monitor-socket,server,nowait \
  2>&1 | tee vm.log
  
  reset;
  cat vm.log;
