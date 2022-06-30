gdb -q --args /usr/local/bin/qemu-system-x86_64 \
  -L /root/kvm-samples/qemu-5.2.0/roms/seabios/out \
  -bios bios.bin \
  -cpu host,vmx=on \
  -snapshot \
  -drive file=./snapshot.qcow2,format=qcow2 \
  -enable-kvm \
  -nographic \