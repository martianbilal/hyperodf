#!/bin/sh
set +o noclobber
# kill -9 $(pgrep qemu)
pkill qemu
make -j 128
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
  -drive file=$TINYIMAGE/stretch_backup.qcow2,format=qcow2 \
  -enable-kvm \
  -nographic \
  -s \
  -monitor unix:qemu-monitor-socket,server,nowait \
  -pidfile vm.pid \
  2> err.log | tee vm.log
