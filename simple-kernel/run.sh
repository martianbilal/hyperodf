  # -hda ./bootloader.bin \
  # -device loader,file=./bootloader.bin,force-raw=on,cpu-num=0 \
/usr/local/bin/qemu-system-x86_64 \
  -L ../qemu-5.2.0/pc-bios \
  -boot d -hda ./bootloader.bin \
  -drive file=../qcowimage,format=qcow2 \
  -net none\
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log 