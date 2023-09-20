/*
 * Accelerator CPUS Interface
 *
 * Copyright 2020 SUSE LLC
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef KVM_CPUS_H
#define KVM_CPUS_H

#include "sysemu/cpus.h"

// #define DBG_KVM
#ifdef DBG_KVM
#define DEBUG_PRINT(fmt, args...) fprintf(stderr, "[%s():%d] " fmt, \
    __func__,  __LINE__, ##args)
#else
#define DEBUG_PRINT(fmt, args...) /* do nothing */
#endif

extern const CpusAccel kvm_cpus;

int kvm_init_vcpu(CPUState *cpu, Error **errp);
int kvm_cpu_exec(CPUState *cpu);
void kvm_destroy_vcpu(CPUState *cpu);
void kvm_cpu_synchronize_post_reset(CPUState *cpu);
void kvm_cpu_synchronize_post_init(CPUState *cpu);
void kvm_cpu_synchronize_pre_loadvm(CPUState *cpu);
void kvm_irqchip_create(KVMState *s);
int dump_cpu_state(CPUState *cpu, char *filename);
int read_cpu_state(CPUState *cpu, char* filename);
int kvm_establish_child(CPUState *cpu, KVMState **sp, struct kvm_run **runp, struct cpu_prefork_state *prefork_state);

#endif /* KVM_CPUS_H */
