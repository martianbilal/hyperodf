#include <stdio.h>
#include <stdlib.h>     // for malloc and stuff
#include <assert.h>     // for using assertions
#include <string.h>
#include <unistd.h>     // for calling exec
#include <linux/kvm.h>  // for getting KVM IOCTL identifiers

/* for open call */
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>

/* for ioctl call */
#include <sys/ioctl.h>

/* for mmap */
#include <sys/mman.h>




#define max_ioctls 100
#define max_fds 3

#define DBG_PRINT_IOCTL_TAB
// #define DBG_PRINT_STRUCT
// uncomment to debug freeing routines
// #define DBG_FREE
// uncomment to debug struct printing routines 
// #define DBG_PRINT_STRUCT
// uncomment to debug dumping routines
// #define DBG_DUMP 
// uncomment to print strings read from file
#define DBG_FILE_READING

// uncomment this to use debug printing
#define DBG_PRINT 1

// #define STANDALONE_BUILD

#define dbg_pr_verbose(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "%s:%d:%s(): [replayer]\t" fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)

#define dbg_pr(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "[replayer]\t" fmt "\n", ##__VA_ARGS__); } while (0)



#define FOREACH_IOCTLS_INDEX                        \
      for (int i = 0; i < CURR_IOCTLS_INDEX; i++)   \


#define FOREACH_IOCTL(function) FOREACH_IOCTLS_INDEX{(function)(ioctls[i]);}

      
#define MAX_BUFFER 100 //used for reading lines from the file



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


extern void* replay_kvm_run;

/**
 * 1st id => kvm id 
 * 2nd id => vm id
 * 3rd id => vcpu id
*/
extern unsigned long parent_fds[max_fds]; 
extern unsigned long child_fds[max_fds]; 


void hello_test();
void replay_init();
int replayer_main();


void replay_print_parent_fds();
void replay_print_child_fds();

// need /proc/sys/kernel/yama/ptrace_scope to be 0 for this 
int replay_attach_strace(int pid, char *out_file);
int replay_detach_strace(void);

void replay_generate_csv_logs(char* raw_logs, char* csv_logs);

int replay_read_csv(char *in_file);


void replay_print_ioctl_list(void);

int replay_child(void);

