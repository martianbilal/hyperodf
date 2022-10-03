#include "replay_ptrace.h"


int init_env_ptrace(){
    int ret = 0;
    // init handlers
    // init translation table -> proper structure for translation
    return ret;
}

int register_sys_args_handler(int syscall, void *func_ptr){
    int ret = 0;
    // modifies **hanlders**
    return ret;
}

int register_sys_result_handler(int syscall, void *func_ptr){
    int ret = 0;
    // modifies **hanlders**
    return ret;
}


void init_trace(__pid_t child_pid){

    return;
}


// will also call init_trace for the parent
// will fork in this process
int init_child_process(){
    int ret = 0;
    return ret;
}

// this main would be used for testing our ptrace implementation
int main(int argc, char **argv){
    int ret = 0;
    int syscall = -1;
    void *func_ptr = NULL; 


    // [TODO] create a table for recording what values should be changed and for which 
    // system call | should also have their translated values

    dbg_pr("initialize the variables required for setting up the ptrace");
    init_env_ptrace();

    dbg_pr("register arg handler for a system call");
    register_sys_args_handler(syscall, func_ptr);

    dbg_pr("register result handler for a system call");
    register_sys_result_handler(syscall, func_ptr);

    dbg_pr("initialize the child process to be traced AND start tracing ");
    init_child_process(); 

    // print something when receive the corresponding system call 
        // -- goes in func_ptr funciton
        // check return value given by the kernel 
        // -- same
        // print the value given to the user by us 
        // -- all in handler beyond this point
        // return the modified value by the user 
    // printf("Hello WOrld\n");


    return ret;
}