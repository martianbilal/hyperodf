#!/bin/sh
# make 
# make install
  # -append "console=ttyS0 root=/dev/vda earlyprintk=serial net.ifnames=0" \
  # -drive file=$IMAGE/stretch_backup.qcow2,id=tst,if=none \
  # -device virtio-blk-pci,scsi=off,drive=tst \
  # -enable-kvm \
  # -cpu host,vmx=on \

qemu-system-x86_64 -s -m 6G -smp 4 -kernel $KERNEL/arch/x86/boot/bzImage -append "console=ttyS0 root=/dev/sda rw earlyprintk=serial net.ifnames=0" -drive file=$IMAGE/stretch.img,format=raw -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 -net nic,model=e1000 -nographic -pidfile vm.pid -monitor unix:qemu-monitor-socket,server,nowait 2>&1 | tee vm.logexitls
