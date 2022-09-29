#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <linux/kvm.h>  /* for reading kvm_regs test.. */

int main(){
    int ret = 0;
    FILE *infile;
    char filename[] = "/root/kvm-samples/dumps/kvm.structs";
    struct kvm_regs regs;

    /* read data from the file */
    infile = fopen(filename,"r");
    if(infile == NULL){
        fprintf(stderr, "\nError opening struct dump!!\n");
        exit(1);
    }

    while(fread(&regs, sizeof(struct kvm_regs), 1, infile)){
        printf("Read kvm_regs\n");

        //printing single register for testing
        printf("regs.rax\t:\t%p\n", regs.rax);
    }

    fclose(infile);


    return ret;
}