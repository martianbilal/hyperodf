/*
 * Internal definitions for a target's KVM support
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_KVM_INT_H
#define QEMU_KVM_INT_H

#include "exec/memory.h"
#include "sysemu/accel.h"
#include "sysemu/kvm.h"

typedef struct KVMSlot
{
    hwaddr start_addr;
    ram_addr_t memory_size;
    void *ram;
    int slot;
    int flags;
    int old_flags;
    /* Dirty bitmap cache for the slot */
    unsigned long *dirty_bmap;
} KVMSlot;

struct cpu_prefork_state 
{ 
    struct kvm_regs regs; 
    struct kvm_sregs sregs; 
    struct kvm_fpu fpu;
    struct kvm_msrs msrs;
    struct kvm_xsave xsave;
    struct kvm_lapic_state lapic;
    struct kvm_xcrs xcrs; 
    struct kvm_irqchip irqchip[3];
    struct kvm_clock_data clock_data;
    struct kvm_pit_state2 pit2;
    struct kvm_mp_state mp_state;
    struct kvm_debugregs debugregs;
    struct kvm_cpuid2 cpuid2; 
    struct kvm_vcpu_events vcpu_events;
    int *tsc_khz;
};

typedef struct KVMMemoryListener {
    MemoryListener listener;
    /* Protects the slots and all inside them */
    QemuMutex slots_lock;
    KVMSlot *slots;
    int as_id;
} KVMMemoryListener;

void kvm_memory_listener_register(KVMState *s, KVMMemoryListener *kml,
                                  AddressSpace *as, int as_id);

void kvm_set_max_memslot_size(hwaddr max_slot_size);

/**
 * kvm_hwpoison_page_add:
 *
 * Parameters:
 *  @ram_addr: the address in the RAM for the poisoned page
 *
 * Add a poisoned page to the list
 *
 * Return: None.
 */
void kvm_hwpoison_page_add(ram_addr_t ram_addr);
#endif
