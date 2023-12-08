#!/bin/sh
echo "Starting run_ice.sh"
set +o noclobber
cd build ;
make -j 128 ;
cd .. ;
pkill -9 qemu

  
./build/qemu-system-x86_64 \
  -m 1G \
  -cpu host,vmx=on \
  -kernel $KERNEL/arch/x86/boot/bzImage \
  -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
  -drive file=$TEST_IMAGE/stretch_backup.qcow2,format=qcow2 \
  -enable-kvm \
  -nographic \
  -s \
  -monitor unix:qemu-monitor-socket,server,nowait \
  -qmp unix:qmp.sock,server,nowait \
  -pidfile vm.pid \
  2>&1 | tee vm.log
