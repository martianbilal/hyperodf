#!/bin/sh
set +o noclobber
# kill -9 $(pgrep qemu)
cd build ;
make -j 128 ;
cd .. ;
pkill -9 qemu

  
./build/qemu-system-x86_64 \
  -m 1G \
  -cpu host,vmx=on \
  -kernel $KERNEL \
  -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
  -drive file=$IMAGE/stretch_backup.qcow2,format=qcow2 \
  -enable-kvm \
  -nographic \
  -s \
  -monitor unix:qemu-monitor-socket,server,nowait \
  -qmp unix:qmp.sock,server,nowait \
  -pidfile vm.pid \
  2>&1 | tee vm.log
