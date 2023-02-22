#!/bin/sh
kill -9 $(pgrep qemu)
make -j 128
make install
  # -append "console=ttyS0 root=/dev/vda earlyprintk=serial net.ifnames=0" \
  # -drive file=$IMAGE/stretch_backup.qcow2,id=tst,if=none \
  # -device virtio-blk-pci,scsi=off,drive=tst \
# strace --abbrev=none -f -o simple.log 
  # -loadvm init_vm \
  # -cpu host,vmx=on \
  # -enable-kvm \
  # -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
  # -net nic,model=e1000 \
  # -s \
# /usr/local/bin/qemu-system-x86_64 \
#   -m 1G \
#   -kernel $KERNEL \
#   -cpu host,vmx=on \
#   -enable-kvm \
#   -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
#   -net nic,model=e1000 \
#   -s \
#   -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
#   -drive file=$IMAGE/stretch_backup.qcow2,format=qcow2 \
#   -nographic \
#   -monitor unix:qemu-monitor-socket,server,nowait \
#   -pidfile vm.pid \
#   2> err.log | tee vm.log
/usr/local/bin/qemu-system-x86_64 \
  -m 1G \
  -kernel $KERNEL \
  -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
  -drive file=$IMAGE/stretch_backup.qcow2,format=qcow2 \
  -nographic \
  -pidfile vm.pid \
  2> err.log | tee vm.log
