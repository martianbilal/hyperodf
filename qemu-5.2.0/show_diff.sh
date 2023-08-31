#!/bin/bash

# This script is used to show the diff of a qemu file between default 
# and our version of QEMU -> it shows the diff in the vscode

# $1 is the qemu file to diff -- full address of file in qemu repo
file=$1

code --diff ~/tools/qemu/"$file" ~/tools/qemu-vmfork/qemu-5.2.0/"$file"
