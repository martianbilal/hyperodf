  # -drive file=./bootloader.qcow2,format=qcow2 \
  # -monitor unix:qemu-monitor-socket,server,nowait \  # -hda ./bootloader.bin \
  # -device loader,file=./bootloader.bin,force-raw=on,cpu-num=0 \
  # --trace events=./events\
  # -drive file=../qcowimage,format=qcow2 \
  # -boot d -hda ./bootloader.bin \
  # -boot d -hda ./bootloader.bin \
  # -drive file=../qcowimage,format=qcow2 \
  # -drive file=./bootloader.qcow2,format=qcow2,share-rw=on \
  # -drive file=./bootloader.qcow2,format=qcow2 \
  # -device loader,file=./bootloader.bin,force-raw=on,cpu-num=0 \
  # -blockdev driver=qcow2,file.filename=./bootloader.qcow2,file.locking=off,file.driver=file,node-name=hd \
/usr/local/bin/qemu-system-x86_64 \
  -L ../qemu-5.2.0/pc-bios \
  -cpu host,vmx=on \
  -hda ./snapshot.qcow2 \
  -snapshot \
  -enable-kvm \
  -nographic \
  -pidfile vm.pid \
  2>&1 | tee vm.log