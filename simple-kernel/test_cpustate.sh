#!/bin/sh
./gdb_run.sh
./extractGdbOut.py
code --diff logs/postfork_x86cpustate.txt logs/prefork_x86cpustate.txt