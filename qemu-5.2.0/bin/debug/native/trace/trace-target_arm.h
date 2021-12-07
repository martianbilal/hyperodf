/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_TARGET_ARM_GENERATED_TRACERS_H
#define TRACE_TARGET_ARM_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_ARM_GT_RECALC_EVENT;
extern TraceEvent _TRACE_ARM_GT_RECALC_DISABLED_EVENT;
extern TraceEvent _TRACE_ARM_GT_CVAL_WRITE_EVENT;
extern TraceEvent _TRACE_ARM_GT_TVAL_WRITE_EVENT;
extern TraceEvent _TRACE_ARM_GT_CTL_WRITE_EVENT;
extern TraceEvent _TRACE_ARM_GT_IMASK_TOGGLE_EVENT;
extern TraceEvent _TRACE_ARM_GT_CNTVOFF_WRITE_EVENT;
extern TraceEvent _TRACE_KVM_ARM_FIXUP_MSI_ROUTE_EVENT;
extern uint16_t _TRACE_ARM_GT_RECALC_DSTATE;
extern uint16_t _TRACE_ARM_GT_RECALC_DISABLED_DSTATE;
extern uint16_t _TRACE_ARM_GT_CVAL_WRITE_DSTATE;
extern uint16_t _TRACE_ARM_GT_TVAL_WRITE_DSTATE;
extern uint16_t _TRACE_ARM_GT_CTL_WRITE_DSTATE;
extern uint16_t _TRACE_ARM_GT_IMASK_TOGGLE_DSTATE;
extern uint16_t _TRACE_ARM_GT_CNTVOFF_WRITE_DSTATE;
extern uint16_t _TRACE_KVM_ARM_FIXUP_MSI_ROUTE_DSTATE;
#define TRACE_ARM_GT_RECALC_ENABLED 1
#define TRACE_ARM_GT_RECALC_DISABLED_ENABLED 1
#define TRACE_ARM_GT_CVAL_WRITE_ENABLED 1
#define TRACE_ARM_GT_TVAL_WRITE_ENABLED 1
#define TRACE_ARM_GT_CTL_WRITE_ENABLED 1
#define TRACE_ARM_GT_IMASK_TOGGLE_ENABLED 1
#define TRACE_ARM_GT_CNTVOFF_WRITE_ENABLED 1
#define TRACE_KVM_ARM_FIXUP_MSI_ROUTE_ENABLED 1
#include "qemu/log-for-trace.h"


#define TRACE_ARM_GT_RECALC_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_RECALC) || \
    false)

static inline void _nocheck__trace_arm_gt_recalc(int timer, int irqstate, uint64_t nexttick)
{
    if (trace_event_get_state(TRACE_ARM_GT_RECALC) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_recalc " "gt recalc: timer %d irqstate %d next tick 0x%" PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer, irqstate, nexttick);
    }
}

static inline void trace_arm_gt_recalc(int timer, int irqstate, uint64_t nexttick)
{
    if (true) {
        _nocheck__trace_arm_gt_recalc(timer, irqstate, nexttick);
    }
}

#define TRACE_ARM_GT_RECALC_DISABLED_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_RECALC_DISABLED) || \
    false)

static inline void _nocheck__trace_arm_gt_recalc_disabled(int timer)
{
    if (trace_event_get_state(TRACE_ARM_GT_RECALC_DISABLED) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_recalc_disabled " "gt recalc: timer %d irqstate 0 timer disabled" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer);
    }
}

static inline void trace_arm_gt_recalc_disabled(int timer)
{
    if (true) {
        _nocheck__trace_arm_gt_recalc_disabled(timer);
    }
}

#define TRACE_ARM_GT_CVAL_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_CVAL_WRITE) || \
    false)

static inline void _nocheck__trace_arm_gt_cval_write(int timer, uint64_t value)
{
    if (trace_event_get_state(TRACE_ARM_GT_CVAL_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_cval_write " "gt_cval_write: timer %d value 0x%" PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer, value);
    }
}

static inline void trace_arm_gt_cval_write(int timer, uint64_t value)
{
    if (true) {
        _nocheck__trace_arm_gt_cval_write(timer, value);
    }
}

#define TRACE_ARM_GT_TVAL_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_TVAL_WRITE) || \
    false)

static inline void _nocheck__trace_arm_gt_tval_write(int timer, uint64_t value)
{
    if (trace_event_get_state(TRACE_ARM_GT_TVAL_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_tval_write " "gt_tval_write: timer %d value 0x%" PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer, value);
    }
}

static inline void trace_arm_gt_tval_write(int timer, uint64_t value)
{
    if (true) {
        _nocheck__trace_arm_gt_tval_write(timer, value);
    }
}

#define TRACE_ARM_GT_CTL_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_CTL_WRITE) || \
    false)

static inline void _nocheck__trace_arm_gt_ctl_write(int timer, uint64_t value)
{
    if (trace_event_get_state(TRACE_ARM_GT_CTL_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_ctl_write " "gt_ctl_write: timer %d value 0x%" PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer, value);
    }
}

static inline void trace_arm_gt_ctl_write(int timer, uint64_t value)
{
    if (true) {
        _nocheck__trace_arm_gt_ctl_write(timer, value);
    }
}

#define TRACE_ARM_GT_IMASK_TOGGLE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_IMASK_TOGGLE) || \
    false)

static inline void _nocheck__trace_arm_gt_imask_toggle(int timer, int irqstate)
{
    if (trace_event_get_state(TRACE_ARM_GT_IMASK_TOGGLE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_imask_toggle " "gt_ctl_write: timer %d IMASK toggle, new irqstate %d" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , timer, irqstate);
    }
}

static inline void trace_arm_gt_imask_toggle(int timer, int irqstate)
{
    if (true) {
        _nocheck__trace_arm_gt_imask_toggle(timer, irqstate);
    }
}

#define TRACE_ARM_GT_CNTVOFF_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_ARM_GT_CNTVOFF_WRITE) || \
    false)

static inline void _nocheck__trace_arm_gt_cntvoff_write(uint64_t value)
{
    if (trace_event_get_state(TRACE_ARM_GT_CNTVOFF_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:arm_gt_cntvoff_write " "gt_cntvoff_write: value 0x%" PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , value);
    }
}

static inline void trace_arm_gt_cntvoff_write(uint64_t value)
{
    if (true) {
        _nocheck__trace_arm_gt_cntvoff_write(value);
    }
}

#define TRACE_KVM_ARM_FIXUP_MSI_ROUTE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_KVM_ARM_FIXUP_MSI_ROUTE) || \
    false)

static inline void _nocheck__trace_kvm_arm_fixup_msi_route(uint64_t iova, uint64_t gpa)
{
    if (trace_event_get_state(TRACE_KVM_ARM_FIXUP_MSI_ROUTE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:kvm_arm_fixup_msi_route " "MSI iova = 0x%"PRIx64" is translated into 0x%"PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , iova, gpa);
    }
}

static inline void trace_kvm_arm_fixup_msi_route(uint64_t iova, uint64_t gpa)
{
    if (true) {
        _nocheck__trace_kvm_arm_fixup_msi_route(iova, gpa);
    }
}
#endif /* TRACE_TARGET_ARM_GENERATED_TRACERS_H */
