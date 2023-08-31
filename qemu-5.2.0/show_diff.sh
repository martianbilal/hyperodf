#!/bin/bash

# This script is used to show the diff of a qemu file between default 
# and our version of QEMU -> it shows the diff in the vscode

# $1 is the qemu file to diff -- full address of file in qemu repo
file=$1

echo "Diffing $file"
echo "Address in default qemu: /home/bilal/tools/qemu/$file"
echo "Address in qemu-vmfork: /home/bilal/tools/qemu-vmfork/qemu-5.2.0/$file"

code --diff /home/bilal/kvm-samples/qemu-5.2.0/"$file" /home/bilal/tools/qemu-vmfork/qemu-5.2.0/"$file"
