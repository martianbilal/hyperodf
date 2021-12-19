/* This file is autogenerated by tracetool, do not edit. */

#ifndef TRACE_HW_RDMA_VMW_GENERATED_TRACERS_H
#define TRACE_HW_RDMA_VMW_GENERATED_TRACERS_H

#include "trace/control.h"

extern TraceEvent _TRACE_PVRDMA_REGS_READ_EVENT;
extern TraceEvent _TRACE_PVRDMA_REGS_WRITE_EVENT;
extern TraceEvent _TRACE_PVRDMA_UAR_WRITE_EVENT;
extern TraceEvent _TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT_EVENT;
extern TraceEvent _TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE_EVENT;
extern TraceEvent _TRACE_PVRDMA_EXEC_CMD_EVENT;
extern TraceEvent _TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA_EVENT;
extern TraceEvent _TRACE_PVRDMA_POST_CQE_EVENT;
extern uint16_t _TRACE_PVRDMA_REGS_READ_DSTATE;
extern uint16_t _TRACE_PVRDMA_REGS_WRITE_DSTATE;
extern uint16_t _TRACE_PVRDMA_UAR_WRITE_DSTATE;
extern uint16_t _TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT_DSTATE;
extern uint16_t _TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE_DSTATE;
extern uint16_t _TRACE_PVRDMA_EXEC_CMD_DSTATE;
extern uint16_t _TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA_DSTATE;
extern uint16_t _TRACE_PVRDMA_POST_CQE_DSTATE;
#define TRACE_PVRDMA_REGS_READ_ENABLED 1
#define TRACE_PVRDMA_REGS_WRITE_ENABLED 1
#define TRACE_PVRDMA_UAR_WRITE_ENABLED 1
#define TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT_ENABLED 1
#define TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE_ENABLED 1
#define TRACE_PVRDMA_EXEC_CMD_ENABLED 1
#define TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA_ENABLED 1
#define TRACE_PVRDMA_POST_CQE_ENABLED 1
#include "qemu/log-for-trace.h"


#define TRACE_PVRDMA_REGS_READ_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_REGS_READ) || \
    false)

static inline void _nocheck__trace_pvrdma_regs_read(uint64_t addr, uint64_t val)
{
    if (trace_event_get_state(TRACE_PVRDMA_REGS_READ) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_regs_read " "pvrdma.regs[0x%"PRIx64"]=0x%"PRIx64 "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , addr, val);
    }
}

static inline void trace_pvrdma_regs_read(uint64_t addr, uint64_t val)
{
    if (true) {
        _nocheck__trace_pvrdma_regs_read(addr, val);
    }
}

#define TRACE_PVRDMA_REGS_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_REGS_WRITE) || \
    false)

static inline void _nocheck__trace_pvrdma_regs_write(uint64_t addr, uint64_t val, const char * reg_name, const char * val_name)
{
    if (trace_event_get_state(TRACE_PVRDMA_REGS_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_regs_write " "pvrdma.regs[0x%"PRIx64"]=0x%"PRIx64" (%s %s)" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , addr, val, reg_name, val_name);
    }
}

static inline void trace_pvrdma_regs_write(uint64_t addr, uint64_t val, const char * reg_name, const char * val_name)
{
    if (true) {
        _nocheck__trace_pvrdma_regs_write(addr, val, reg_name, val_name);
    }
}

#define TRACE_PVRDMA_UAR_WRITE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_UAR_WRITE) || \
    false)

static inline void _nocheck__trace_pvrdma_uar_write(uint64_t addr, uint64_t val, const char * reg_name, const char * val_name, int val1, int val2)
{
    if (trace_event_get_state(TRACE_PVRDMA_UAR_WRITE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_uar_write " "uar[0x%"PRIx64"]=0x%"PRIx64" (cls=%s, op=%s, obj=%d, val=%d)" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , addr, val, reg_name, val_name, val1, val2);
    }
}

static inline void trace_pvrdma_uar_write(uint64_t addr, uint64_t val, const char * reg_name, const char * val_name, int val1, int val2)
{
    if (true) {
        _nocheck__trace_pvrdma_uar_write(addr, val, reg_name, val_name, val1, val2);
    }
}

#define TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT) || \
    false)

static inline void _nocheck__trace_pvrdma_map_to_pdir_host_virt(void * vfirst, void * vremaped)
{
    if (trace_event_get_state(TRACE_PVRDMA_MAP_TO_PDIR_HOST_VIRT) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_map_to_pdir_host_virt " "mremap %p -> %p" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , vfirst, vremaped);
    }
}

static inline void trace_pvrdma_map_to_pdir_host_virt(void * vfirst, void * vremaped)
{
    if (true) {
        _nocheck__trace_pvrdma_map_to_pdir_host_virt(vfirst, vremaped);
    }
}

#define TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE) || \
    false)

static inline void _nocheck__trace_pvrdma_map_to_pdir_next_page(int page_idx, void * vnext, void * vremaped)
{
    if (trace_event_get_state(TRACE_PVRDMA_MAP_TO_PDIR_NEXT_PAGE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_map_to_pdir_next_page " "mremap [%d] %p -> %p" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , page_idx, vnext, vremaped);
    }
}

static inline void trace_pvrdma_map_to_pdir_next_page(int page_idx, void * vnext, void * vremaped)
{
    if (true) {
        _nocheck__trace_pvrdma_map_to_pdir_next_page(page_idx, vnext, vremaped);
    }
}

#define TRACE_PVRDMA_EXEC_CMD_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_EXEC_CMD) || \
    false)

static inline void _nocheck__trace_pvrdma_exec_cmd(int cmd, int err)
{
    if (trace_event_get_state(TRACE_PVRDMA_EXEC_CMD) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_exec_cmd " "cmd=%d, err=%d" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , cmd, err);
    }
}

static inline void trace_pvrdma_exec_cmd(int cmd, int err)
{
    if (true) {
        _nocheck__trace_pvrdma_exec_cmd(cmd, err);
    }
}

#define TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA) || \
    false)

static inline void _nocheck__trace_pvrdma_ring_next_elem_read_no_data(char * ring_name)
{
    if (trace_event_get_state(TRACE_PVRDMA_RING_NEXT_ELEM_READ_NO_DATA) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_ring_next_elem_read_no_data " "pvrdma_ring %s is empty" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , ring_name);
    }
}

static inline void trace_pvrdma_ring_next_elem_read_no_data(char * ring_name)
{
    if (true) {
        _nocheck__trace_pvrdma_ring_next_elem_read_no_data(ring_name);
    }
}

#define TRACE_PVRDMA_POST_CQE_BACKEND_DSTATE() ( \
    trace_event_get_state_dynamic_by_id(TRACE_PVRDMA_POST_CQE) || \
    false)

static inline void _nocheck__trace_pvrdma_post_cqe(uint32_t cq_handle, int notify, uint64_t wr_id, uint64_t qpn, uint32_t op_code, uint32_t status, uint32_t byte_len, uint32_t src_qp, uint32_t wc_flags, uint32_t vendor_err)
{
    if (trace_event_get_state(TRACE_PVRDMA_POST_CQE) && qemu_loglevel_mask(LOG_TRACE)) {
        struct timeval _now;
        gettimeofday(&_now, NULL);
        qemu_log("%d@%zu.%06zu:pvrdma_post_cqe " "cq_handle=%d, notify=%d, wr_id=0x%"PRIx64", qpn=0x%"PRIx64", opcode=%d, status=%d, byte_len=%d, src_qp=%d, wc_flags=%d, vendor_err=%d" "\n",
                 qemu_get_thread_id(),
                 (size_t)_now.tv_sec, (size_t)_now.tv_usec
                 , cq_handle, notify, wr_id, qpn, op_code, status, byte_len, src_qp, wc_flags, vendor_err);
    }
}

static inline void trace_pvrdma_post_cqe(uint32_t cq_handle, int notify, uint64_t wr_id, uint64_t qpn, uint32_t op_code, uint32_t status, uint32_t byte_len, uint32_t src_qp, uint32_t wc_flags, uint32_t vendor_err)
{
    if (true) {
        _nocheck__trace_pvrdma_post_cqe(cq_handle, notify, wr_id, qpn, op_code, status, byte_len, src_qp, wc_flags, vendor_err);
    }
}
#endif /* TRACE_HW_RDMA_VMW_GENERATED_TRACERS_H */