#!/bin/sh

pkill -9 qemu

# sleep for 100 ms
sleep 0.2s

cd $IMAGE;
qemu-img create -f qcow2 -o backing_file=stretch.img stretch_backup.qcow2;
cd ~/kvm-samples/qemu-5.2.0;

./hyperfork.sh