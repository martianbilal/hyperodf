#ifndef CPU_KICK_H
#define CPU_KICK_H

#include "qemu/osdep.h"
#include <bits/pthreadtypes.h>
#include <stdint.h>
#include <stdio.h>
#include <termios.h>

#include <glib/gprintf.h>

#include "qemu-common.h"
#include "sysemu/sysemu.h"
#include "trace.h"
#include "qapi/error.h"
#include "qemu/sockets.h"
#include "qemu/thread.h"
#include "qemu/thread-posix.h"
#include "qemu/event_notifier.h"
#include <sys/ioctl.h>

// ======================== HODF ===============================
#define KVM_EPT_ODF 0xC00CAEC7

#define MAX_EVENT_LEN 100
typedef struct {
    double time;
    char event[MAX_EVENT_LEN];
    int pid;
} hodf_event;

struct odf_info{
	int parent_vcpu_fd;
	int child_vcpu_fd;
	int mem_size;
};

typedef struct QemuCondList {
    GList *list;
} QemuCondList;

extern QemuCondList *qemu_cond_list;

static int parent_vcpu_fd;
static uint64_t parent_mem_size;
static int child_vcpu_fd;
static int kvm_fd;


// ======================== Global vars ========================
extern EventNotifier mon_create_event;
extern int parent_child_pipe[2];

extern hodf_event *hodf_events;
extern int hodf_events_size;

extern GMainLoop *h_iothread_main_loop;
extern int h_qmp_fd;
//==============================================================


// ======================== HODF EVAL ===============================
static FILE *h_eval_fd;
// ======================== HODF EVAL ===============================

typedef struct hodf_metadata{
    pthread_t threadid;
    QemuCond halt_cond;
} hodf_metadata;


// does the necessary initialization including creating the variables used by 
// hodf like the halt_cond array 
void h_initialize(void);

void h_cpu_kick(void);
void h_hello(void);
void h_wait_for_load_snapshot(void);
void h_signal_child_done(void);
void h_register_monitor_fd(int fd);
int h_get_monitor_fd(void);
void h_save_iothread_loop(GMainLoop *main_loop);
void h_intrpt_iothread_loop(void);
void h_set_qmp_server_fd(int fd);                          // only call with hmp or qmp monitor
int h_get_qmp_server_fd(void);
void h_set_parent_vcpu_fd(int fd);
void h_set_parent_mem_size(uint64_t mem_size);
void h_set_child_vcpu_fd(int fd);
int h_enable_ept_sharing(void);
void h_set_kvm_fd(int fd);


// ======================== HODF Cond Recording ===============================
static QemuCondList* h_qemu_cond_list_new(void);
void h_qemu_cond_list_add(QemuCondList *qcl, QemuCond *cond);
void h_qemu_cond_list_iterate(QemuCondList *qcl, void (*func)(QemuCond *));
void h_qemu_cond_list_patch(QemuCondList *qcl);
void h_print_pthread_cond(pthread_cond_t cond);
// void h_qemu_cond_cleanup(QemuCond *cond);
// void h_qemu_cond_list_cleanup(QemuCondList *qcl);
// ======================== HODF Cond Recording ===============================

// ======================== HODF EVAL ===============================
static void h_eval_initialize(const char *filename);
int h_eval_record_time(const char* name);
int h_eval_reopen_fd(const char *filename);
// ======================== HODF EVAL ===============================

void hodf_add_event(const char *eventDesc);
void hodf_print_events(void);

void h_save_metadata(QemuCond *halt_cond, pthread_t threadid, int cpu_index);

#endif // CPU_KICK_H