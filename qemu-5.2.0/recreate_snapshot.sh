#!/bin/sh
echo "Starting recreate_snapshot.sh"
cd $TEST_IMAGE;
$MOD_QEMU/build/qemu-img create -f qcow2 -o backing_file=stretch.img stretch_backup.qcow2;
echo "Created stretch_backup.qcow2";
cd ~/kvm-samples/qemu-5.2.0;
echo "returned to qemu directory"