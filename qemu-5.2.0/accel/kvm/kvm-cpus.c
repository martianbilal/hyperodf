/*
 * QEMU KVM support
 *
 * Copyright IBM, Corp. 2008
 *           Red Hat, Inc. 2008
 *
 * Authors:
 *  Anthony Liguori   <aliguori@us.ibm.com>
 *  Glauber Costa     <gcosta@redhat.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 */

#include "qemu/osdep.h"
#include "qemu/error-report.h"
#include "qemu/main-loop.h"
#include "sysemu/kvm_int.h"
#include "sysemu/runstate.h"
#include "sysemu/cpus.h"
#include "qemu/guest-random.h"
#include "qapi/error.h"
#include "util/forkall-coop.h"

#include "kvm-cpus.h"

static int post_fork_setup(struct cpu_prefork_state *prefork_state){
    #ifdef DBG
    printf("[debug] tsc_khz : %p\n", -1);
    #endif
    // printf("[debug] post fork setup! %d\n", prefork_state->);
    return 0; 
}

static void *kvm_vcpu_thread_fn(void *arg)
{
    CPUState *cpu = arg;
    int r;
    #ifdef DBG
    printf("[debug] entered vcpu thread function! \n");
    #endif

    cpu->should_wait = false;
    
    rcu_register_thread();
    ski_forkall_thread_add_self_tid();


    qemu_mutex_lock_iothread();
    qemu_thread_get_self(cpu->thread);
    cpu->thread_id = qemu_get_thread_id();
    cpu->can_do_io = 1;
    current_cpu = cpu;



    
    // will have to set up the copying mechanism over here.
    if(cpu->child_cpu){
        #ifdef DBG 
        printf("[debug] starting postfork!\n");
        #endif
        post_fork_setup(cpu->prefork_state);
        cpu->stopped = 0;
    }
    
    r = kvm_init_vcpu(cpu, &error_fatal);
    kvm_init_cpu_signals(cpu);
    


    /* signal CPU creation */
    cpu_thread_signal_created(cpu);
    qemu_guest_random_seed_thread_part2(cpu->random_seed);

    if(cpu->child_cpu){
        // dirty flag causes the register values to be overwritten
        cpu->vcpu_dirty = false;
    }


    do {
        if (cpu_can_run(cpu)) {
            r = kvm_cpu_exec(cpu);
            if (r == EXCP_DEBUG) {
                cpu_handle_guest_debug(cpu);
            }
        }
        
        if(cpu->should_wait){
            qemu_mutex_unlock_iothread();
            while(1) {
                int did_fork=1;
                int is_child; 

                ski_forkall_slave(&did_fork, &is_child);
                if(did_fork){
                    qemu_thread_get_self(cpu->thread);
                    cpu->thread_id = qemu_get_thread_id();
                    current_cpu = cpu;
                    
                    break;
                }
                sleep(0);

            }
            qemu_mutex_lock_iothread();
        }


        qemu_wait_io_event(cpu);
    } while (!cpu->unplug || cpu_can_run(cpu));

    kvm_destroy_vcpu(cpu);
    cpu_thread_signal_destroyed(cpu);
    qemu_mutex_unlock_iothread();
    rcu_unregister_thread();
    return NULL;
}

void kvm_start_vcpu_thread(CPUState *cpu)
{
    char thread_name[VCPU_THREAD_NAME_SIZE];

    #ifdef DBG
    printf("[debug] VCPU Thread create called! \n");
    #endif

    cpu->thread = g_malloc0(sizeof(QemuThread));
    cpu->halt_cond = g_malloc0(sizeof(QemuCond));
    qemu_cond_init(cpu->halt_cond);
    snprintf(thread_name, VCPU_THREAD_NAME_SIZE, "CPU %d/KVM",
             cpu->cpu_index);
    qemu_thread_create(cpu->thread, thread_name, kvm_vcpu_thread_fn,
                       cpu, QEMU_THREAD_JOINABLE);
}

const CpusAccel kvm_cpus = {
    .create_vcpu_thread = kvm_start_vcpu_thread,

    .synchronize_post_reset = kvm_cpu_synchronize_post_reset,
    .synchronize_post_init = kvm_cpu_synchronize_post_init,
    .synchronize_state = kvm_cpu_synchronize_state,
    .synchronize_pre_loadvm = kvm_cpu_synchronize_pre_loadvm,
};
