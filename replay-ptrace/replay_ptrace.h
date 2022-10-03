/* C standard library */
#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* POSIX */
#include <unistd.h>
#include <sys/user.h>
#include <sys/wait.h>

/* Linux */
#include <syscall.h>
#include <sys/reg.h>
#include <sys/ptrace.h>

/* KVM */
#include <linux/kvm.h> 


#include <assert.h>


#define DBG

// uncomment this to use debug printing
#define DBG_PRINT 1

#define dbg_pr_verbose(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "%s:%d:%s(): [replay-ptrace]\t" fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)

#define dbg_pr(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "[replay-ptrace]\t" fmt "\n", ##__VA_ARGS__); } while (0)

#define FATAL(...) \
    do { \
        fprintf(stderr, "strace: " __VA_ARGS__); \
        fputc('\n', stderr); \
        exit(EXIT_FAILURE); \
    } while (0)


// Array containing all the handlers for syscalls
extern void **handlers_args;
extern void **handlers_results;