

## rePLAYER

rePlayer provides the functionality to dynamically attach strace to a running program, record the system calls and re run them in the child process, this can help with re-establishing the kernel state of the child process after the fork. 

*Documentation for rePlayer API can be found in .h files and corresponding function definitions.*



- logs : this directory has the raw traces from strace
- src : source code for the rePlayer, does the parsing of the strace logs and replays these syscalls
    - *sub-src directory [coming soon]*




