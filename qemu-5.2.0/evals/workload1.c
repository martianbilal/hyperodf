#include <stdio.h>
#include <sys/mman.h>
#include <sys/io.h>


#define NUM_PAGES 100000
#define HYPERVISOR_PORT 0x301
#define DONE_WORKLOAD 'z'
#define HYPERCALL DONE_WORKLOAD

int main(void){
    // just mmap a bunch of memmory 
    // and then write a byte to each
    // page in the mapping 

    // get mmap 
    void *ptr = mmap(NULL, NUM_PAGES*4096, PROT_READ|PROT_WRITE, MAP_ANONYMOUS|MAP_PRIVATE, -1, 0);
    ioperm(HYPERVISOR_PORT, 5, 1);
    outb(HYPERCALL, HYPERVISOR_PORT);

    for(int i = 0; i < NUM_PAGES; i++){
        // write a byte to each page
        // if(i%1000 == 0)
            // printf("Writing to page %d\n", i);
        *((char*)ptr + i*4096) = 1;
    }

    // at the end send hypercall to the hypervisor 

}