#include <assert.h>
#include "qemu/osdep.h"
#include "sysemu/sysemu.h"
#include "cpu.h"
#include "qemu/main-loop.h"

#include "hyperodf/post_fork_handle.h"


VMChangeStateHandler* change_kvm_clock_handler = NULL;
VMChangeStateHandler* change_kvm_pit_handler = NULL;
VMChangeStateHandler* change_cpu_handler = NULL;
void* change_kvm_clock_opaque = NULL;
void* change_kvm_pit_opaque = NULL;
void* change_cpu_opaque = NULL;

void call_change_handlers(void){
    return;
}

void add_change_handler(VMChangeStateHandler *cb, void *opaque, int id){
    return;
}
