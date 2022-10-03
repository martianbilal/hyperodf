/**
 * Simple test program for testing replay_ptrace 
 * with 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>
#include <stdint.h>
#include <linux/kvm.h>



int main(){
    int ret = 0;
    int kvm_dev = 0;
    kvm_dev = open("/dev/kvm", O_RDWR);
    close(kvm_dev);
    printf("HELLO KVM TESTS === PTRACE\n");
    

    return ret;
}