#include <stdio.h>                  // for printing stuff to stdio
#include <linux/ptrace.h>           // for PTRACE call
#include <assert.h>


#define DBG

// uncomment this to use debug printing
#define DBG_PRINT 1

#define dbg_pr_verbose(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "%s:%d:%s(): [replay-ptrace]\t" fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)

#define dbg_pr(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "[replay-ptrace]\t" fmt "\n", ##__VA_ARGS__); } while (0)

// Array containing all the handlers for syscalls
extern void **handlers_args;
extern void **handlers_results;