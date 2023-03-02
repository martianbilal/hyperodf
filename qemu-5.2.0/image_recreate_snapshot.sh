#!/bin/sh

cd $IMAGE;
qemu-img create -f qcow2 -o backing_file=stretch.img stretch_backup.qcow2;
cd ~/kvm-samples/qemu-5.2.0;

./run.sh


