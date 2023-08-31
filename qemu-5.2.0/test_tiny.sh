#!/bin/sh

# set +o noclobber
# kill -9 $(pgrep qemu)
  # -initrd ../kvm-host/build/rootfs.cpio \

  # -enable-kvm \
  # -cpu host,vmx=on \
# make -j 128
  # -drive file=$IMAGE/stretch.img,format=raw \
  # -drive file=$IMAGE/stretch.img,format=raw \

./build/qemu-system-x86_64 \
  -m 1G \
  -cpu host,vmx=on \
  -kernel $TINYKERNEL/arch/x86/boot/bzImage \
  -append "nokaslr earlyprintk=serial" \
  -initrd  /home/bilal/test.img \
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2> err.log | tee vm.log
