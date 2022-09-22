#include <stdio.h>
#include <stdlib.h>     // for malloc and stuff
#include <assert.h>     // for using assertions
#include <string.h>
#include <unistd.h>     // for calling exec
#include <linux/kvm.h>  // for getting KVM IOCTL identifiers

#define max_ioctls 100

typedef struct ioctl_args
{
    /* data */
    void *fd;
    void *ioctl_id;
    void *ioctl_struct;
    void *result;
} ioctl_args;


// array of ioctl args
extern ioctl_args **ioctls;

// environment 

extern char proj_root[128]; 
extern char log_directory[128]; 
extern char raw_logs[128]; 
extern char csv_logs[128];


void hello_test();
int replayer_main();


// need /proc/sys/kernel/yama/ptrace_scope to be 0 for this 
int replay_attach_strace(int pid, char *out_file);
int replay_detach_strace(void);

int replay_child(void);

