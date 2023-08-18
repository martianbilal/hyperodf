#include "qemu/osdep.h"
#include "exec/cpu-common.h"
#include "hodf-util.h"

void h_cpu_kick(void)
{
    cpu_kick_all();
}


void h_hello(void){
    printf("Hello\n");
}