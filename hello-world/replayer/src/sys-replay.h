#include <stdio.h>
#include <stdlib.h>     // for malloc and stuff
#include <assert.h>     // for using assertions
#include <string.h>

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


void hello_test();
int replayer_main();
