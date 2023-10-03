#!/bin/sh
set +o noclobber
# kill -9 $(pgrep qemu)
cd build ;
make -j 128 ;
cd .. ;
pkill -9 qemu
# make install
  # -append "console=ttyS0 root=/dev/vda earlyprintk=serial net.ifnames=0" \
  # -drive file=$IMAGE/stretch_backup.qcow2,id=tst,if=none \
  # -device virtio-blk-pci,scsi=off,drive=tst \
# strace --abbrev=none -f -o simple.log 
  # -loadvm init_vm \
# -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
#   -net nic,model=e1000 \
  
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
