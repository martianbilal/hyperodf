#include <sys/ptrace.h>
#include <bits/types.h>
#include <sys/user.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <string.h>
// #include <linux/user.h>   /* For user_regs_struct


#include "syscalls.h"
#include "syscallents.h"

/* cheap trick for reading syscall number / return value. */
#ifdef __amd64__
#define eax rax
#define orig_eax orig_rax
#else
#endif

#define offsetof(a, b) __builtin_offsetof(a,b)
#define get_reg(child, name) __get_reg(child, offsetof(struct user, regs.name))

long __get_reg(pid_t child, int off) {
    long val = ptrace(PTRACE_PEEKUSER, child, off);
    assert(errno == 0);
    return val;
}

int wait_for_syscall(pid_t child) {
    int status;
    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80)
            return 0;
        if (WIFEXITED(status))
            return 1;
        fprintf(stderr, "[stopped %d (%x)]\n", status, WSTOPSIG(status));
    }
}

const char *syscall_name(int scn) {
    struct syscall_entry *ent;
    static char buf[128];
    if (scn <= MAX_SYSCALL_NUM) {
        ent = &syscalls[scn];
        if (ent->name)
            return ent->name;
    }
    snprintf(buf, sizeof buf, "sys_%d", scn);
    return buf;
}

long get_syscall_arg(pid_t child, int which) {
    switch (which) {
#ifdef __amd64__
    case 0: return get_reg(child, rdi);
    case 1: return get_reg(child, rsi);
    case 2: return get_reg(child, rdx);
    case 3: return get_reg(child, r10);
    case 4: return get_reg(child, r8);
    case 5: return get_reg(child, r9);
#else
    case 0: return get_reg(child, ebx);
    case 1: return get_reg(child, ecx);
    case 2: return get_reg(child, edx);
    case 3: return get_reg(child, esi);
    case 4: return get_reg(child, edi);
    case 5: return get_reg(child, ebp);
#endif
    default: return -1L;
    }
}

char *read_string(pid_t child, unsigned long addr) {
    char *val = malloc(4096);
    int allocated = 4096;
    int read = 0;
    unsigned long tmp;
    while (1) {
        if (read + sizeof tmp > allocated) {
            allocated *= 2;
            val = realloc(val, allocated);
        }
        tmp = ptrace(PTRACE_PEEKDATA, child, addr + read);
        if(errno != 0) {
            val[read] = 0;
            break;
        }
        memcpy(val + read, &tmp, sizeof tmp);
        if (memchr(&tmp, 0, sizeof tmp) != NULL)
            break;
        read += sizeof tmp;
    }
    return val;
}

void print_syscall_args(pid_t child, int num) {
    struct syscall_entry *ent = NULL;
    int nargs = SYSCALL_MAXARGS;
    int i;
    char *strval;

    if (num <= MAX_SYSCALL_NUM && syscalls[num].name) {
        ent = &syscalls[num];
        nargs = ent->nargs;
    }
    for (i = 0; i < nargs; i++) {
        long arg = get_syscall_arg(child, i);
        int type = ent ? ent->args[i] : ARG_PTR;
        switch (type) {
        case ARG_INT:
            fprintf(stderr, "%ld", arg);
            break;
        case ARG_STR:
            strval = read_string(child, arg);
            fprintf(stderr, "\"%s\"", strval);
            free(strval);
            break;
        default:
            fprintf(stderr, "0x%lx", arg);
            break;
        }
        if (i != nargs - 1)
            fprintf(stderr, ", ");
    }
}


typedef struct syscall_args_change{
    int n_args;
    int *args_indices; 
    void *args_values;
}syscall_args_change;



// index into this array to get info about 
// corresponding syscall
syscall_args_change *list_syscall_args;


int init_list_syscall_args(){
    int ret = 0;
    // this is a dummy function = replace it with actual rotuine that 
    // updates this list 
    list_syscall_args = malloc(sizeof(syscall_args_change) * 50);

    return ret;
}
int change_syscall_args(pid_t child_pid, int syscal_req){
    int ret = 0; 
    struct user_regs_struct regs;
    syscall_args_change args;
    int orig_val = 0;
    orig_val = get_reg(child_pid, orig_eax);
    //printf("ioctl : [%d], regs.orig_eax: [%p]\n", syscal_req, orig_val);
    
    // for the child pid 



    // check a table for finding an appropriate value of the sycall args
    args = list_syscall_args[syscal_req];

//printf("ioctl : [%d], regs.orig_eax: [%d]", syscal_req, orig_val);
    fflush(stdout);
    
    regs.orig_rax = -1;
    // also need to see which args need to be changed 
    ptrace(
        PTRACE_SETREGS,
        child_pid,
        0,
        &regs
    );


    // based on the value in the table change the value of the arg 

    return ret; 
}


int  change_candidates[5] = {
    16,
    -1,
    -1,
    -1,
    -1,
};


int modify_syscall_args(pid_t child, int syscall_req){
    int ret = 0;
    int num = 0;
    
    num = get_reg(child, orig_eax);
    assert(errno == 0);


    // can check the syscall at this point 
    // check a table to see if this syscall is a candidate for changing the sytem call arguments
    for(int i = 0; i < 5; i++){
        if(num == change_candidates[i]){
            //printf("ioctl called => %d\n", num);
            change_syscall_args(child, num);
            break;
        }
    }
    // change the syscall args at this point if belongs to something we know of 



    return ret;
}

int modify_syscall_retval(pid_t child, int syscall_num){
    int ret = 0;
    int num = get_reg(child, orig_eax);
    struct user_regs_struct regs;
    for(int i = 0; i < 5; i++){
        if(num == change_candidates[i]){
            //printf("ioctl called => %d\n", num);
            ptrace(PTRACE_GETREGS, child, 0, &regs);
            regs.rax = 343;
            ptrace(PTRACE_SETREGS, child, 0, &regs);
            break;
        }
    }
    return ret;
}

void print_syscall(pid_t child, int syscall_req) {
    int num;
    num = get_reg(child, orig_eax);
    assert(errno == 0);

    fprintf(stderr, "%s(", syscall_name(num));

    print_syscall_args(child, num);
    fprintf(stderr, ") = ");

    if( syscall_req <= MAX_SYSCALL_NUM) {
        pause_on( num, syscall_req);
    }
}

int pause_on(int syscall_req, int syscall) {
    if(syscall == syscall_req)
        do {
            char buf[2];
            fgets(buf, sizeof(buf), stdin); // waits until enter to continue
        } while(0);
}

int do_trace(pid_t child, int syscall_req) {
    int status;
    int retval;
    waitpid(child, &status, 0);
    assert(WIFSTOPPED(status));
    init_list_syscall_args();
    ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);
    while(1) {
        if (wait_for_syscall(child) != 0)
            break;

        print_syscall(child, syscall_req);
        // modify_syscall_args(child, syscall_req);

        if (wait_for_syscall(child) != 0)
            break;

        retval = get_reg(child, eax);
        assert(errno == 0);
        modify_syscall_retval(child, syscall_req);

        fprintf(stderr, "%d\n", retval);
    }
    return 0;
}

int do_child(int argc, char **argv) {
    char *args [argc+1];
    int i;
    for (i=0;i<argc;i++)
        args[i] = argv[i];
    args[argc] = NULL;

    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);
    return execvp(args[0], args);
}

int main(int argc, char **argv) {
    pid_t child;
    int push = 1;
    int syscall = -1;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-s <syscall int>|-n <syscall name>] <program> <args>\n", argv[0]);
        exit(1);
    }

    if(strcmp(argv[1], "-s") == 0) {
        syscall = atoi(argv[2]);
        if (syscall > MAX_SYSCALL_NUM || syscall < 0) {
            fprintf(stderr, "Error: %s is an invalid syscall\n", argv[2]);
            exit(1);
        }
        push = 3;
    }

    if(strcmp(argv[1], "-n") == 0) {
        char *syscallname = argv[2];
        struct syscall_entry *ent;
        int i;

        for(i = 0; i < sizeof(syscalls)/sizeof(*syscalls); i++) {
            ent = &syscalls[i];
            if(strcmp(syscallname, ent->name) == 0) {
                syscall = i;
                break;
            }
        }

        if(syscall == -1) {
            fprintf(stderr, "Error: %s is an invalid syscall\n", argv[2]);
            exit(1);
        }

        push = 3;
    }


    child = fork();
    if (child == 0) {
        return do_child(argc-push, argv+push);
    } else {
        return do_trace(child, syscall);
    }
}
