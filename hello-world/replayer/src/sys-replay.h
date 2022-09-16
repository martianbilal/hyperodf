#include <stdio.h>
#include <stdlib.h>     // for malloc and stuff
#include <assert.h>     // for using assertions

#define max_ioctls 100

typedef struct ioctl_args
{
    /* data */
    void *fd;
    void *ioctl_id;
    void *ioctl_struct;
} ioctl_args;


// array of ioctl args
ioctl_args **ioctls;
