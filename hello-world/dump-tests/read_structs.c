#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <linux/kvm.h>  /* for reading kvm_regs test.. */



int main(){
    int ret = 0;
    FILE *infile;
    char filename[] = "/root/kvm-samples/dumps/kvm.structs";
    struct kvm_regs regs;
    struct kvm_sregs sregs;
    struct kvm_userspace_memory_region memreg;

    /* read data from the file */
    infile = fopen(filename,"r");
    if(infile == NULL){
        fprintf(stderr, "\nError opening struct dump!!\n");
        exit(1);
    }

    // while(fread(&regs, sizeof(struct kvm_regs), 1, infile)){
    //     printf("Read kvm_regs\n");

    //     //printing single register for testing
    //     printf("regs.rax\t:\t%p\n", regs.rax);
    // }

    fread(&memreg, sizeof(struct kvm_userspace_memory_region), 1, infile);
    printf("memregs.guest_addr\t:\t%p\n", memreg.guest_phys_addr);
    printf("memregs.memsize\t:\t%u\n", memreg.memory_size);
    printf("memregs.user_addr\t:\t%p\n", memreg.userspace_addr);
    printf("memregs.slot\t:\t%p\n", memreg.slot);
    fread(&regs, sizeof(struct kvm_regs), 1, infile);
    fread(&sregs, sizeof(struct kvm_sregs), 1, infile);
    fread(&regs, sizeof(struct kvm_regs), 1, infile);
    fread(&sregs, sizeof(struct kvm_sregs), 1, infile);
    fread(&regs, sizeof(struct kvm_regs), 1, infile);

    fclose(infile);


    return ret;
}