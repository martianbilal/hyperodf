#!/bin/sh
nasm -fbin bootloader.asm -o bootloader
nasm -fbin ./sector2345/extendedProgram.asm -o ./sector2345/extendedProgram.bin
cat bootloader ./sector2345/extendedProgram.bin > bootloader.bin
qemu-img convert -p -f raw -O qcow2 bootloader.bin bootloader.qcow2