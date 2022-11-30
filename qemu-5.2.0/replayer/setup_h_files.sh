#!/bin/sh

REPLAYER_DIR=/root/kvm-samples/qemu-5.2.0/replayer
HYPERODF_DIR=/root/kvm-samples/hyperodf
HFILES_DIR=$REPLAYER_DIR/includes

mkdir -p $HFILES_DIR

$REPLAYER_DIR/gen_syscalls.py $HYPERODF_DIR $HFILES_DIR