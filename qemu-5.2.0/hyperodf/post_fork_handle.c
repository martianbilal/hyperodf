#include <assert.h>
#include "qemu/osdep.h"
#include "sysemu/sysemu.h"
#include "qemu/main-loop.h"

#include "hyperodf/post_fork_handle.h"


VMChangeStateHandler* change_kvm_clock_handler = NULL;
VMChangeStateHandler* change_kvm_pit_handler = NULL;
VMChangeStateHandler* change_cpu_handler = NULL;
void* change_kvm_clock_opaque = NULL;
void* change_kvm_pit_opaque = NULL;
void* change_cpu_opaque = NULL;

void call_change_handlers(void){
    assert(change_kvm_clock_handler && change_kvm_pit_handler && change_cpu_handler);

    change_kvm_clock_handler(change_kvm_clock_opaque, 1, RUN_STATE_RUNNING);
    change_kvm_pit_handler(change_kvm_pit_opaque, 1, RUN_STATE_RUNNING);
    change_cpu_handler(change_cpu_opaque, 1, RUN_STATE_RUNNING);
    return;
}

void add_change_handler(VMChangeStateHandler *cb, void *opaque, int id){
    switch(id){
        case RELOAD_HANDLER_KVM_CLOCK:
            change_kvm_clock_handler = cb;
            change_kvm_clock_opaque = opaque;
            return;
        case RELOAD_HANDLER_KVM_PIT:
            change_kvm_pit_handler = cb;
            change_kvm_pit_opaque = opaque;
            return;
        case RELOAD_HANDLER_KVM_CPU:
            change_cpu_handler = cb;
            change_cpu_opaque = opaque;
            return;
        default:
            abort();
    }

    return;
}
