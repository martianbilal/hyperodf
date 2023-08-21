#ifndef CPU_KICK_H
#define CPU_KICK_H

#include "qemu/osdep.h"
#include <bits/pthreadtypes.h>
#include <termios.h>

#include <glib/gprintf.h>

#include "qemu-common.h"
#include "sysemu/sysemu.h"
#include "trace.h"
#include "qapi/error.h"
#include "qemu/sockets.h"
#include "qemu/thread.h"
#include "qemu/thread-posix.h"

// ======================== HODF ========================

typedef struct hodf_metadata{
    pthread_t threadid;
    QemuCond halt_cond;
} hodf_metadata;

// does the necessary initialization including creating the variables used by 
// hodf like the halt_cond array 
void h_initialize(void);

void h_cpu_kick(void);
void h_hello(void);

void h_save_metadata(QemuCond *halt_cond, pthread_t threadid, int cpu_index);

#endif // CPU_KICK_H