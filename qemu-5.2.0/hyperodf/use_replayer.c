#include <assert.h>
#include "qemu/osdep.h"
#include "sysemu/sysemu.h"
#include "qemu/main-loop.h"

#include "hyperodf/post_fork_handle.h"

// use the replayer
// make the functions that abstract the calling for the 
// replayer module api 


// define the points where these functions should be called 



// function for testing if these module is compiling properly
void use_replayer_hello(){
    printf("===========HELLO FROM REPLAYER===========\n");

    return;
}

//  running all the initialization
//  stuff for the replayer module 
//  => starting tracing the qemu 
//  for the parent 
//  => ending the tracing for 
//  the child 
//  once the child resumes 
// => replay the ioctls 
//
//
//
void use_replayer_parent(){
    return;
}

void use_replayer_child(){
    return;
}