gdb -q --args /usr/local/bin/qemu-system-x86_64 \
  -m 1G \
  -cpu host,vmx=on \
  -kernel $KERNEL \
  -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
  -drive file=$IMAGE/stretch_backup.qcow2,format=qcow2 \
  -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
  -net nic,model=e1000 \
  -enable-kvm \
  -nographic \
  --trace "kvm_*" \
  -s \
  -monitor unix:qemu-monitor-socket,server,nowait \
  -pidfile vm.pid \
  2> err.log | tee vm.log