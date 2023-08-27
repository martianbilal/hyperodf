  # -monitor unix:qemu-monitor-socket,server,nowait \

gdb -q --args ./build/qemu-system-x86_64 \
  -m 1G \
  -cpu host,vmx=on \
  -kernel $KERNEL \
  -append "console=ttyS0 root=/dev/sda earlyprintk=serial net.ifnames=0" \
  -drive file=$IMAGE/stretch_backup.qcow2,format=qcow2 \
  -net user,host=10.0.2.10,hostfwd=tcp:127.0.0.1:10021-:22 \
  -net nic,model=e1000 \
  -enable-kvm \
  -nographic \
  -s \
  -monitor unix:qemu-monitor-socket,server,nowait \
  -qmp unix:qmp.sock,server,nowait \
  -pidfile vm.pid \
  2>&1 | tee vm.log