/usr/local/bin/qemu-system-x86_64 \
  -hda ./bootloader.bin \
  -net none\
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log