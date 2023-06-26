/*
 * Wrappers around Linux futex syscall
 *
 * Copyright Red Hat, Inc. 2017
 *
 * Author:
 *  Paolo Bonzini <pbonzini@redhat.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 *
 */

#ifndef QEMU_FUTEX_H
#define QEMU_FUTEX_H

#include <stdlib.h>
#include <sys/syscall.h>
#include <linux/futex.h>
#include <stddef.h>
#include <unistd.h>
#include <errno.h>

#define qemu_futex(...)              syscall(__NR_futex, __VA_ARGS__)



static inline void qemu_futex_wake(void *f, int n)
{
    qemu_futex(f, FUTEX_WAKE, n, NULL, NULL, 0);
}


// //function from stackoverflow 
// static void full_write(int fd, const char *buf, size_t len)
// {
//         while (len > 0) {
//                 ssize_t ret = write(fd, buf, len);

//                 if ((ret == -1) && (errno != EINTR))
//                         break;

//                 buf += (size_t) ret;
//                 len -= (size_t) ret;
//         }
// }

// //function from stackoverflow
// static void print_backtrace(void)
// {
//         static const char start[] = "BACKTRACE ------------\n";
//         static const char end[] = "----------------------\n";

//         void *bt[1024];
//         int bt_size;
//         char **bt_syms;
//         int i;

//         bt_size = backtrace(bt, 1024);
//         bt_syms = backtrace_symbols(bt, bt_size);
//         full_write(STDERR_FILENO, start, strlen(start));
//         for (i = 1; i < bt_size; i++) {
//                 size_t len = strlen(bt_syms[i]);
//                 full_write(STDERR_FILENO, bt_syms[i], len);
//                 full_write(STDERR_FILENO, "\n", 1);
//         }
//         full_write(STDERR_FILENO, end, strlen(end));
//     free(bt_syms);
// }



static inline void qemu_futex_wait(void *f, unsigned val)
{   
    // if (val == 4294967295){
    // printf("[debug] waiting for futex, value : %u\n", val);
    // }
    // print_backtrace();
    // return;

    while (qemu_futex(f, FUTEX_WAIT, (int) val, NULL, NULL, 0)) {
        switch (errno) {
        case EWOULDBLOCK:
            return;
        case EINTR:
            break; /* get out of switch and retry */
        default:
            abort();
        }
    }
}

#endif /* QEMU_FUTEX_H */
