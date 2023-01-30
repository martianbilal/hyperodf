#!/bin/sh


cd build || exit
cmake ..
make
cd ..
./build/proc_fork