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



/**
 * @brief Invokes appropriate args handler for the given syscall
 * 
 * This function is invoked in the parent process 
 * When we  have intercepted child's system call
 * and we have not made the next system call
 * 
 * @arg syscall : syscall number
 * @result returns the result of running the syscall handler
 * 
*/
int invoke_sys_call_args_handler(int syscall){
    int ret = 0; 
    return ret;
}

/**
 * @brief Invokes appropriate result handler for the given syscall
 * 
 * This function is invoked in the parent process 
 * When we  have intercepted results coming in for 
 * the child's system call from the kernel
 * 
 * @arg syscall : syscall number
 * @result returns the result of running the syscall handler
 * 
*/
int invoke_sys_call_regs_handler(int syscall){
    int ret = 0;
    return ret; 
}


void init_trace(__pid_t child_pid){
    waitpid(child_pid, 0, 0); // sync with execvp
    ptrace(PTRACE_SETOPTIONS, child_pid, 0, PTRACE_O_EXITKILL);
        
    while(1){
        /* Enter next system call */
        if (ptrace(PTRACE_SYSCALL, child_pid, 0, 0) == -1) {
            FATAL("%s", strerror(errno));
        }
        if (waitpid(child_pid, 0, 0) == -1)
            FATAL("%s", strerror(errno));



        // at this point we are stopped before making the next system call 
        // so now we can print the arguments of the syscall or we can change
        // these

        
        /* Gather system call arguments */
        struct user_regs_struct regs;
        if (ptrace(PTRACE_GETREGS, child_pid, 0, &regs) == -1)
            FATAL("%s", strerror(errno));

        dbg_pr("a syscall was made with id\t:\t%lld", regs.rax);

        // if (is_syscall_blocked(regs.orig_rax)) {
        //     regs.orig_rax = -1; // set to invalid system call
        //     if (ptrace(PTRACE_SETREGS, child_pid, 0, &regs) == -1)
        //         FATAL("%s", strerror(errno));
        // }

        /* Special handling per system call (entrance) */
        switch (regs.orig_rax) {
            case SYS_exit:
                exit(regs.rdi);
            case SYS_exit_group:
                exit(regs.rdi);

        }

        /* Run system call and stop on exit */
        if (ptrace(PTRACE_SYSCALL, child_pid, 0, 0) == -1)
            FATAL("%s", strerror(errno));
        if (waitpid(child_pid, 0, 0) == -1)
            FATAL("%s", strerror(errno));

        /* Special handling per system call (exit) */
        switch (regs.orig_rax) {
            case -1:
                if (ptrace(PTRACE_POKEUSER, child_pid, RAX * 8, -EPERM) == -1)
                    FATAL("%s", strerror(errno));
                break;

            case KVM_CREATE_VM:
                dbg_pr("KVM : create VM");
                break;
        }
    }
    return;
}


// will also call init_trace for the parent
// will fork in this process
int init_child_process(int argc, char *argv_1, char **argv){
    int ret = 0;
    __pid_t child_pid = -1;

    child_pid = fork();

    assert(child_pid>=0);

    if(child_pid == 0){
        /* child */
        ptrace(PTRACE_TRACEME, 0, 0, 0);
        // execvp will now wait for the parent to attach and wait for us 
        execvp(argv_1, argv);
        // never reach here 
    }else {
        /* parent */
        init_trace(child_pid);

    }

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
    init_child_process(argc - 1, argv[1], argv + 1); 

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