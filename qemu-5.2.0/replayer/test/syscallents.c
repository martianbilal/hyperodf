/*
 * Generated file (for kernel version 5.14.0-rc7-mm1+ on x86_64). Do not edit manually or check in VCS.
 *
 */
#include "syscallents.h"


const syscall_entry_t syscalls[] = {
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:10: 0	common	read			sys_read */
/* ../../hyperodf/fs/read_write.c:635: SYSCALL_DEFINE3(read, unsigned int, fd, char __user *, buf, size_t, count) */
  [__SNR_read] = {
    .name  = "read",
    .func  = read,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:11: 1	common	write			sys_write */
/* ../../hyperodf/fs/read_write.c:660: SYSCALL_DEFINE3(write, unsigned int, fd, const char __user *, buf, size_t, count) */
  [__SNR_write] = {
    .name  = "write",
    .func  = write,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:12: 2	common	open			sys_open */
/* ../../hyperodf/fs/open.c:1263: COMPAT_SYSCALL_DEFINE3(open, const char __user *, filename, int, flags, umode_t, mode) */
  [__SNR_open] = {
    .name  = "open",
    .func  = open,
    .nargs = 3,
    .args  = {ARG_STR, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:13: 3	common	close			sys_close */
/* ../../hyperodf/fs/open.c:1325: SYSCALL_DEFINE1(close, unsigned int, fd) */
  [__SNR_close] = {
    .name  = "close",
    .func  = close,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:14: 4	common	stat			sys_newstat */
/* ../../hyperodf/fs/stat.c:290: SYSCALL_DEFINE2(stat, const char __user *, filename, struct __old_kernel_stat __user *, statbuf) */
  [__SNR_stat] = {
    .name  = "stat",
    .func  = stat,
    .nargs = 2,
    .args  = {ARG_STR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(struct __old_kernel_stat ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:15: 5	common	fstat			sys_newfstat */
/* ../../hyperodf/fs/stat.c:316: SYSCALL_DEFINE2(fstat, unsigned int, fd, struct __old_kernel_stat __user *, statbuf) */
  [__SNR_fstat] = {
    .name  = "fstat",
    .func  = fstat,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __old_kernel_stat ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:16: 6	common	lstat			sys_newlstat */
/* ../../hyperodf/fs/stat.c:303: SYSCALL_DEFINE2(lstat, const char __user *, filename, struct __old_kernel_stat __user *, statbuf) */
  [__SNR_lstat] = {
    .name  = "lstat",
    .func  = lstat,
    .nargs = 2,
    .args  = {ARG_STR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(struct __old_kernel_stat ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:17: 7	common	poll			sys_poll */
/* ../../hyperodf/fs/select.c:1064: SYSCALL_DEFINE3(poll, struct pollfd __user *, ufds, unsigned int, nfds, int, timeout_msecs) */
  [__SNR_poll] = {
    .name  = "poll",
    .func  = poll,
    .nargs = 3,
    .args  = {ARG_PTR, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(struct pollfd ), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:18: 8	common	lseek			sys_lseek */
/* ../../hyperodf/fs/read_write.c:328: COMPAT_SYSCALL_DEFINE3(lseek, unsigned int, fd, compat_off_t, offset, unsigned int, whence) */
  [__SNR_lseek] = {
    .name  = "lseek",
    .func  = lseek,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:19: 9	common	mmap			sys_mmap */
/* ../../hyperodf/arch/x86/kernel/sys_x86_64.c:89: SYSCALL_DEFINE6(mmap, unsigned long, addr, unsigned long, len, unsigned long, prot, unsigned long, flags, unsigned long, fd, unsigned long, off) */
  [__SNR_mmap] = {
    .name  = "mmap",
    .func  = mmap,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:20: 10	common	mprotect		sys_mprotect */
/* ../../hyperodf/mm/mprotect.c:665: SYSCALL_DEFINE3(mprotect, unsigned long, start, size_t, len, unsigned long, prot) */
  [__SNR_mprotect] = {
    .name  = "mprotect",
    .func  = mprotect,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:21: 11	common	munmap			sys_munmap */
/* ../../hyperodf/mm/nommu.c:1514: SYSCALL_DEFINE2(munmap, unsigned long, addr, size_t, len) */
  [__SNR_munmap] = {
    .name  = "munmap",
    .func  = munmap,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:22: 12	common	brk			sys_brk */
/* ../../hyperodf/mm/nommu.c:381: SYSCALL_DEFINE1(brk, unsigned long, brk) */
  [__SNR_brk] = {
    .name  = "brk",
    .func  = brk,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:23: 13	64	rt_sigaction		sys_rt_sigaction */
/* ../../hyperodf/kernel/signal.c:4383: COMPAT_SYSCALL_DEFINE4(rt_sigaction, int, sig, const struct compat_sigaction __user *, act, struct compat_sigaction __user *, oact, compat_size_t, sigsetsize) */
  [__SNR_rt_sigaction] = {
    .name  = "rt_sigaction",
    .func  = rt_sigaction,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigaction ), sizeof(struct compat_sigaction ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:24: 14	common	rt_sigprocmask		sys_rt_sigprocmask */
/* ../../hyperodf/kernel/signal.c:3159: COMPAT_SYSCALL_DEFINE4(rt_sigprocmask, int, how, compat_sigset_t __user *, nset, compat_sigset_t __user *, oset, compat_size_t, sigsetsize) */
  [__SNR_rt_sigprocmask] = {
    .name  = "rt_sigprocmask",
    .func  = rt_sigprocmask,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_sigset_t ), sizeof(compat_sigset_t ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:25: 15	64	rt_sigreturn		sys_rt_sigreturn */
/* ../../hyperodf/arch/x86/ia32/ia32_signal.c:123: COMPAT_SYSCALL_DEFINE0(rt_sigreturn) */
  [__SNR_rt_sigreturn] = {
    .name  = "rt_sigreturn",
    .func  = rt_sigreturn,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:26: 16	64	ioctl			sys_ioctl */
/* ../../hyperodf/fs/ioctl.c:930: COMPAT_SYSCALL_DEFINE3(ioctl, unsigned int, fd, unsigned int, cmd, compat_ulong_t, arg) */
  [__SNR_ioctl] = {
    .name  = "ioctl",
    .func  = ioctl,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:27: 17	common	pread64			sys_pread64 */
/* ../../hyperodf/fs/read_write.c:686: SYSCALL_DEFINE4(pread64, unsigned int, fd, char __user *, buf, size_t, count, loff_t, pos) */
  [__SNR_pread64] = {
    .name  = "pread64",
    .func  = pread64,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:28: 18	common	pwrite64		sys_pwrite64 */
/* ../../hyperodf/fs/read_write.c:712: SYSCALL_DEFINE4(pwrite64, unsigned int, fd, const char __user *, buf, size_t, count, loff_t, pos) */
  [__SNR_pwrite64] = {
    .name  = "pwrite64",
    .func  = pwrite64,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:29: 19	64	readv			sys_readv */
/* ../../hyperodf/fs/read_write.c:1039: SYSCALL_DEFINE3(readv, unsigned long, fd, const struct iovec __user *, vec, unsigned long, vlen) */
  [__SNR_readv] = {
    .name  = "readv",
    .func  = readv,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:30: 20	64	writev			sys_writev */
/* ../../hyperodf/fs/read_write.c:1045: SYSCALL_DEFINE3(writev, unsigned long, fd, const struct iovec __user *, vec, unsigned long, vlen) */
  [__SNR_writev] = {
    .name  = "writev",
    .func  = writev,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:31: 21	common	access			sys_access */
/* ../../hyperodf/fs/open.c:478: SYSCALL_DEFINE2(access, const char __user *, filename, int, mode) */
  [__SNR_access] = {
    .name  = "access",
    .func  = access,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:32: 22	common	pipe			sys_pipe */
/* ../../hyperodf/fs/pipe.c:1031: SYSCALL_DEFINE1(pipe, int __user *, fildes) */
  [__SNR_pipe] = {
    .name  = "pipe",
    .func  = pipe,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:33: 23	common	select			sys_select */
/* ../../hyperodf/fs/select.c:1284: COMPAT_SYSCALL_DEFINE5(select, int, n, compat_ulong_t __user *, inp, compat_ulong_t __user *, outp, compat_ulong_t __user *, exp, struct old_timeval32 __user *, tvp) */
  [__SNR_select] = {
    .name  = "select",
    .func  = select,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(compat_ulong_t ), sizeof(compat_ulong_t ), sizeof(compat_ulong_t ), sizeof(struct old_timeval32 ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:34: 24	common	sched_yield		sys_sched_yield */
/* ../../hyperodf/kernel/sched/core.c:7871: SYSCALL_DEFINE0(sched_yield) */
  [__SNR_sched_yield] = {
    .name  = "sched_yield",
    .func  = sched_yield,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:35: 25	common	mremap			sys_mremap */
/* ../../hyperodf/mm/nommu.c:1590: SYSCALL_DEFINE5(mremap, unsigned long, addr, unsigned long, old_len, unsigned long, new_len, unsigned long, flags, unsigned long, new_addr) */
  [__SNR_mremap] = {
    .name  = "mremap",
    .func  = mremap,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:36: 26	common	msync			sys_msync */
/* ../../hyperodf/mm/msync.c:32: SYSCALL_DEFINE3(msync, unsigned long, start, size_t, len, int, flags) */
  [__SNR_msync] = {
    .name  = "msync",
    .func  = msync,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:37: 27	common	mincore			sys_mincore */
/* ../../hyperodf/mm/mincore.c:230: SYSCALL_DEFINE3(mincore, unsigned long, start, size_t, len, unsigned char __user *, vec) */
  [__SNR_mincore] = {
    .name  = "mincore",
    .func  = mincore,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(unsigned char ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:38: 28	common	madvise			sys_madvise */
/* ../../hyperodf/mm/madvise.c:1226: SYSCALL_DEFINE3(madvise, unsigned long, start, size_t, len_in, int, behavior) */
  [__SNR_madvise] = {
    .name  = "madvise",
    .func  = madvise,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:39: 29	common	shmget			sys_shmget */
/* ../../hyperodf/ipc/shm.c:744: SYSCALL_DEFINE3(shmget, key_t, key, size_t, size, int, shmflg) */
  [__SNR_shmget] = {
    .name  = "shmget",
    .func  = shmget,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:40: 30	common	shmat			sys_shmat */
/* ../../hyperodf/ipc/shm.c:1607: COMPAT_SYSCALL_DEFINE3(shmat, int, shmid, compat_uptr_t, shmaddr, int, shmflg) */
  [__SNR_shmat] = {
    .name  = "shmat",
    .func  = shmat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:41: 31	common	shmctl			sys_shmctl */
/* ../../hyperodf/ipc/shm.c:1389: COMPAT_SYSCALL_DEFINE3(shmctl, int, shmid, int, cmd, void __user *, uptr) */
  [__SNR_shmctl] = {
    .name  = "shmctl",
    .func  = shmctl,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:42: 32	common	dup			sys_dup */
/* ../../hyperodf/fs/file.c:1207: SYSCALL_DEFINE1(dup, unsigned int, fildes) */
  [__SNR_dup] = {
    .name  = "dup",
    .func  = dup,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:43: 33	common	dup2			sys_dup2 */
/* ../../hyperodf/fs/file.c:1192: SYSCALL_DEFINE2(dup2, unsigned int, oldfd, unsigned int, newfd) */
  [__SNR_dup2] = {
    .name  = "dup2",
    .func  = dup2,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:44: 34	common	pause			sys_pause */
/* ../../hyperodf/kernel/signal.c:4551: SYSCALL_DEFINE0(pause) */
  [__SNR_pause] = {
    .name  = "pause",
    .func  = pause,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:45: 35	common	nanosleep		sys_nanosleep */
/* ../../hyperodf/kernel/time/hrtimer.c:2118: SYSCALL_DEFINE2(nanosleep, struct __kernel_timespec __user *, rqtp, struct __kernel_timespec __user *, rmtp) */
  [__SNR_nanosleep] = {
    .name  = "nanosleep",
    .func  = nanosleep,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(struct __kernel_timespec ), sizeof(struct __kernel_timespec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:46: 36	common	getitimer		sys_getitimer */
/* ../../hyperodf/kernel/time/itimer.c:141: COMPAT_SYSCALL_DEFINE2(getitimer, int, which, struct old_itimerval32 __user *, value) */
  [__SNR_getitimer] = {
    .name  = "getitimer",
    .func  = getitimer,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct old_itimerval32 ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:47: 37	common	alarm			sys_alarm */
/* ../../hyperodf/kernel/time/itimer.c:306: SYSCALL_DEFINE1(alarm, unsigned int, seconds) */
  [__SNR_alarm] = {
    .name  = "alarm",
    .func  = alarm,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:48: 38	common	setitimer		sys_setitimer */
/* ../../hyperodf/kernel/time/itimer.c:378: COMPAT_SYSCALL_DEFINE3(setitimer, int, which, struct old_itimerval32 __user *, value, struct old_itimerval32 __user *, ovalue) */
  [__SNR_setitimer] = {
    .name  = "setitimer",
    .func  = setitimer,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct old_itimerval32 ), sizeof(struct old_itimerval32 ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:49: 39	common	getpid			sys_getpid */
/* ../../hyperodf/kernel/sys.c:924: SYSCALL_DEFINE0(getpid) */
  [__SNR_getpid] = {
    .name  = "getpid",
    .func  = getpid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:50: 40	common	sendfile		sys_sendfile64 */
/* ../../hyperodf/fs/read_write.c:1322: COMPAT_SYSCALL_DEFINE4(sendfile, int, out_fd, int, in_fd, compat_off_t __user *, offset, compat_size_t, count) */
  [__SNR_sendfile] = {
    .name  = "sendfile",
    .func  = sendfile,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(compat_off_t ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:51: 41	common	socket			sys_socket */
/* ../../hyperodf/net/socket.c:1561: SYSCALL_DEFINE3(socket, int, family, int, type, int, protocol) */
  [__SNR_socket] = {
    .name  = "socket",
    .func  = socket,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:52: 42	common	connect			sys_connect */
/* ../../hyperodf/net/socket.c:1917: SYSCALL_DEFINE3(connect, int, fd, struct sockaddr __user *, uservaddr, int, addrlen) */
  [__SNR_connect] = {
    .name  = "connect",
    .func  = connect,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:53: 43	common	accept			sys_accept */
/* ../../hyperodf/net/socket.c:1858: SYSCALL_DEFINE3(accept, int, fd, struct sockaddr __user *, upeer_sockaddr, int __user *, upeer_addrlen) */
  [__SNR_accept] = {
    .name  = "accept",
    .func  = accept,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:54: 44	common	sendto			sys_sendto */
/* ../../hyperodf/net/socket.c:2041: SYSCALL_DEFINE6(sendto, int, fd, void __user *, buff, size_t, len, unsigned int, flags, struct sockaddr __user *, addr, int, addr_len) */
  [__SNR_sendto] = {
    .name  = "sendto",
    .func  = sendto,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(void *), sizeof(int), sizeof(int), sizeof(struct sockaddr ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:55: 45	64	recvfrom		sys_recvfrom */
/* ../../hyperodf/net/socket.c:2104: SYSCALL_DEFINE6(recvfrom, int, fd, void __user *, ubuf, size_t, size, unsigned int, flags, struct sockaddr __user *, addr, int __user *, addr_len) */
  [__SNR_recvfrom] = {
    .name  = "recvfrom",
    .func  = recvfrom,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(int), sizeof(void *), sizeof(int), sizeof(int), sizeof(struct sockaddr ), sizeof(int )}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:56: 46	64	sendmsg			sys_sendmsg */
/* ../../hyperodf/net/socket.c:2496: SYSCALL_DEFINE3(sendmsg, int, fd, struct user_msghdr __user *, msg, unsigned int, flags) */
  [__SNR_sendmsg] = {
    .name  = "sendmsg",
    .func  = sendmsg,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct user_msghdr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:57: 47	64	recvmsg			sys_recvmsg */
/* ../../hyperodf/net/socket.c:2704: SYSCALL_DEFINE3(recvmsg, int, fd, struct user_msghdr __user *, msg, unsigned int, flags) */
  [__SNR_recvmsg] = {
    .name  = "recvmsg",
    .func  = recvmsg,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct user_msghdr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:58: 48	common	shutdown		sys_shutdown */
/* ../../hyperodf/net/socket.c:2263: SYSCALL_DEFINE2(shutdown, int, fd, int, how) */
  [__SNR_shutdown] = {
    .name  = "shutdown",
    .func  = shutdown,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:59: 49	common	bind			sys_bind */
/* ../../hyperodf/net/socket.c:1699: SYSCALL_DEFINE3(bind, int, fd, struct sockaddr __user *, umyaddr, int, addrlen) */
  [__SNR_bind] = {
    .name  = "bind",
    .func  = bind,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:60: 50	common	listen			sys_listen */
/* ../../hyperodf/net/socket.c:1731: SYSCALL_DEFINE2(listen, int, fd, int, backlog) */
  [__SNR_listen] = {
    .name  = "listen",
    .func  = listen,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:61: 51	common	getsockname		sys_getsockname */
/* ../../hyperodf/net/socket.c:1955: SYSCALL_DEFINE3(getsockname, int, fd, struct sockaddr __user *, usockaddr, int __user *, usockaddr_len) */
  [__SNR_getsockname] = {
    .name  = "getsockname",
    .func  = getsockname,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:62: 52	common	getpeername		sys_getpeername */
/* ../../hyperodf/net/socket.c:1991: SYSCALL_DEFINE3(getpeername, int, fd, struct sockaddr __user *, usockaddr, int __user *, usockaddr_len) */
  [__SNR_getpeername] = {
    .name  = "getpeername",
    .func  = getpeername,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:63: 53	common	socketpair		sys_socketpair */
/* ../../hyperodf/net/socket.c:1662: SYSCALL_DEFINE4(socketpair, int, family, int, type, int, protocol, int __user *, usockvec) */
  [__SNR_socketpair] = {
    .name  = "socketpair",
    .func  = socketpair,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:64: 54	64	setsockopt		sys_setsockopt */
/* ../../hyperodf/net/socket.c:2181: SYSCALL_DEFINE5(setsockopt, int, fd, int, level, int, optname, char __user *, optval, int, optlen) */
  [__SNR_setsockopt] = {
    .name  = "setsockopt",
    .func  = setsockopt,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:65: 55	64	getsockopt		sys_getsockopt */
/* ../../hyperodf/net/socket.c:2229: SYSCALL_DEFINE5(getsockopt, int, fd, int, level, int, optname, char __user *, optval, int __user *, optlen) */
  [__SNR_getsockopt] = {
    .name  = "getsockopt",
    .func  = getsockopt,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_STR, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(char *), sizeof(int ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:66: 56	common	clone			sys_clone */
/* ../../hyperodf/kernel/fork.c:2670: SYSCALL_DEFINE5(clone, unsigned long, clone_flags, unsigned long, newsp, int __user *, parent_tidptr, int __user *, child_tidptr, unsigned long, tls) */
  [__SNR_clone] = {
    .name  = "clone",
    .func  = clone,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int ), sizeof(int ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:67: 57	common	fork			sys_fork */
/* ../../hyperodf/kernel/fork.c:2625: SYSCALL_DEFINE0(fork) */
  [__SNR_fork] = {
    .name  = "fork",
    .func  = fork,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:68: 58	common	vfork			sys_vfork */
/* ../../hyperodf/kernel/fork.c:2641: SYSCALL_DEFINE0(vfork) */
  [__SNR_vfork] = {
    .name  = "vfork",
    .func  = vfork,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:69: 59	64	execve			sys_execve */
/* ../../hyperodf/fs/exec.c:2081: COMPAT_SYSCALL_DEFINE3(execve, const char __user *, filename, const compat_uptr_t __user *, argv, const compat_uptr_t __user *, envp) */
  [__SNR_execve] = {
    .name  = "execve",
    .func  = execve,
    .nargs = 3,
    .args  = {ARG_STR, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(compat_uptr_t ), sizeof(compat_uptr_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:70: 60	common	exit			sys_exit */
/* ../../hyperodf/kernel/exit.c:889: SYSCALL_DEFINE1(exit, int, error_code) */
  [__SNR_exit] = {
    .name  = "exit",
    .func  = exit,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:71: 61	common	wait4			sys_wait4 */
/* ../../hyperodf/kernel/exit.c:1728: COMPAT_SYSCALL_DEFINE4(wait4, compat_pid_t, pid, compat_uint_t __user *, stat_addr, int, options, struct compat_rusage __user *, ru) */
  [__SNR_wait4] = {
    .name  = "wait4",
    .func  = wait4,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_uint_t ), sizeof(int), sizeof(struct compat_rusage ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:72: 62	common	kill			sys_kill */
/* ../../hyperodf/kernel/signal.c:3755: SYSCALL_DEFINE2(kill, pid_t, pid, int, sig) */
  [__SNR_kill] = {
    .name  = "kill",
    .func  = kill,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:73: 63	common	uname			sys_newuname */
/* ../../hyperodf/kernel/sys.c:1293: SYSCALL_DEFINE1(uname, struct old_utsname __user *, name) */
  [__SNR_uname] = {
    .name  = "uname",
    .func  = uname,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct old_utsname ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:74: 64	common	semget			sys_semget */
/* ../../hyperodf/ipc/sem.c:624: SYSCALL_DEFINE3(semget, key_t, key, int, nsems, int, semflg) */
  [__SNR_semget] = {
    .name  = "semget",
    .func  = semget,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:75: 65	common	semop			sys_semop */
/* ../../hyperodf/ipc/sem.c:2281: SYSCALL_DEFINE3(semop, int, semid, struct sembuf __user *, tsops, unsigned, nsops) */
  [__SNR_semop] = {
    .name  = "semop",
    .func  = semop,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sembuf ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:76: 66	common	semctl			sys_semctl */
/* ../../hyperodf/ipc/sem.c:1821: COMPAT_SYSCALL_DEFINE4(semctl, int, semid, int, semnum, int, cmd, int, arg) */
  [__SNR_semctl] = {
    .name  = "semctl",
    .func  = semctl,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:77: 67	common	shmdt			sys_shmdt */
/* ../../hyperodf/ipc/shm.c:1731: SYSCALL_DEFINE1(shmdt, char __user *, shmaddr) */
  [__SNR_shmdt] = {
    .name  = "shmdt",
    .func  = shmdt,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:78: 68	common	msgget			sys_msgget */
/* ../../hyperodf/ipc/msg.c:314: SYSCALL_DEFINE2(msgget, key_t, key, int, msgflg) */
  [__SNR_msgget] = {
    .name  = "msgget",
    .func  = msgget,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:79: 69	common	msgsnd			sys_msgsnd */
/* ../../hyperodf/ipc/msg.c:989: COMPAT_SYSCALL_DEFINE4(msgsnd, int, msqid, compat_uptr_t, msgp, compat_ssize_t, msgsz, int, msgflg) */
  [__SNR_msgsnd] = {
    .name  = "msgsnd",
    .func  = msgsnd,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:80: 70	common	msgrcv			sys_msgrcv */
/* ../../hyperodf/ipc/msg.c:1292: COMPAT_SYSCALL_DEFINE5(msgrcv, int, msqid, compat_uptr_t, msgp, compat_ssize_t, msgsz, compat_long_t, msgtyp, int, msgflg) */
  [__SNR_msgrcv] = {
    .name  = "msgrcv",
    .func  = msgrcv,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:81: 71	common	msgctl			sys_msgctl */
/* ../../hyperodf/ipc/msg.c:768: COMPAT_SYSCALL_DEFINE3(msgctl, int, msqid, int, cmd, void __user *, uptr) */
  [__SNR_msgctl] = {
    .name  = "msgctl",
    .func  = msgctl,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:82: 72	common	fcntl			sys_fcntl */
/* ../../hyperodf/fs/fcntl.c:690: COMPAT_SYSCALL_DEFINE3(fcntl, unsigned int, fd, unsigned int, cmd, compat_ulong_t, arg) */
  [__SNR_fcntl] = {
    .name  = "fcntl",
    .func  = fcntl,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:83: 73	common	flock			sys_flock */
/* ../../hyperodf/fs/locks.c:2125: SYSCALL_DEFINE2(flock, unsigned int, fd, unsigned int, cmd) */
  [__SNR_flock] = {
    .name  = "flock",
    .func  = flock,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:84: 74	common	fsync			sys_fsync */
/* ../../hyperodf/fs/sync.c:230: SYSCALL_DEFINE1(fsync, unsigned int, fd) */
  [__SNR_fsync] = {
    .name  = "fsync",
    .func  = fsync,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:85: 75	common	fdatasync		sys_fdatasync */
/* ../../hyperodf/fs/sync.c:235: SYSCALL_DEFINE1(fdatasync, unsigned int, fd) */
  [__SNR_fdatasync] = {
    .name  = "fdatasync",
    .func  = fdatasync,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:86: 76	common	truncate		sys_truncate */
/* ../../hyperodf/fs/open.c:149: COMPAT_SYSCALL_DEFINE2(truncate, const char __user *, path, compat_off_t, length) */
  [__SNR_truncate] = {
    .name  = "truncate",
    .func  = truncate,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:87: 77	common	ftruncate		sys_ftruncate */
/* ../../hyperodf/fs/open.c:207: COMPAT_SYSCALL_DEFINE2(ftruncate, unsigned int, fd, compat_ulong_t, length) */
  [__SNR_ftruncate] = {
    .name  = "ftruncate",
    .func  = ftruncate,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:88: 78	common	getdents		sys_getdents */
/* ../../hyperodf/fs/readdir.c:522: COMPAT_SYSCALL_DEFINE3(getdents, unsigned int, fd, struct compat_linux_dirent __user *, dirent, unsigned int, count) */
  [__SNR_getdents] = {
    .name  = "getdents",
    .func  = getdents,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_linux_dirent ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:89: 79	common	getcwd			sys_getcwd */
/* ../../hyperodf/fs/d_path.c:381: SYSCALL_DEFINE2(getcwd, char __user *, buf, unsigned long, size) */
  [__SNR_getcwd] = {
    .name  = "getcwd",
    .func  = getcwd,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:90: 80	common	chdir			sys_chdir */
/* ../../hyperodf/fs/open.c:483: SYSCALL_DEFINE1(chdir, const char __user *, filename) */
  [__SNR_chdir] = {
    .name  = "chdir",
    .func  = chdir,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:91: 81	common	fchdir			sys_fchdir */
/* ../../hyperodf/fs/open.c:509: SYSCALL_DEFINE1(fchdir, unsigned int, fd) */
  [__SNR_fchdir] = {
    .name  = "fchdir",
    .func  = fchdir,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:92: 82	common	rename			sys_rename */
/* ../../hyperodf/fs/namei.c:4823: SYSCALL_DEFINE2(rename, const char __user *, oldname, const char __user *, newname) */
  [__SNR_rename] = {
    .name  = "rename",
    .func  = rename,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:93: 83	common	mkdir			sys_mkdir */
/* ../../hyperodf/fs/namei.c:3929: SYSCALL_DEFINE2(mkdir, const char __user *, pathname, umode_t, mode) */
  [__SNR_mkdir] = {
    .name  = "mkdir",
    .func  = mkdir,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:94: 84	common	rmdir			sys_rmdir */
/* ../../hyperodf/fs/namei.c:4049: SYSCALL_DEFINE1(rmdir, const char __user *, pathname) */
  [__SNR_rmdir] = {
    .name  = "rmdir",
    .func  = rmdir,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:95: 85	common	creat			sys_creat */
/* ../../hyperodf/fs/open.c:1284: SYSCALL_DEFINE2(creat, const char __user *, pathname, umode_t, mode) */
  [__SNR_creat] = {
    .name  = "creat",
    .func  = creat,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:96: 86	common	link			sys_link */
/* ../../hyperodf/fs/namei.c:4481: SYSCALL_DEFINE2(link, const char __user *, oldname, const char __user *, newname) */
  [__SNR_link] = {
    .name  = "link",
    .func  = link,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:97: 87	common	unlink			sys_unlink */
/* ../../hyperodf/fs/namei.c:4215: SYSCALL_DEFINE1(unlink, const char __user *, pathname) */
  [__SNR_unlink] = {
    .name  = "unlink",
    .func  = unlink,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:98: 88	common	symlink			sys_symlink */
/* ../../hyperodf/fs/namei.c:4299: SYSCALL_DEFINE2(symlink, const char __user *, oldname, const char __user *, newname) */
  [__SNR_symlink] = {
    .name  = "symlink",
    .func  = symlink,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:99: 89	common	readlink		sys_readlink */
/* ../../hyperodf/fs/stat.c:473: SYSCALL_DEFINE3(readlink, const char __user *, path, char __user *, buf, int, bufsiz) */
  [__SNR_readlink] = {
    .name  = "readlink",
    .func  = readlink,
    .nargs = 3,
    .args  = {ARG_STR, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:100: 90	common	chmod			sys_chmod */
/* ../../hyperodf/fs/open.c:636: SYSCALL_DEFINE2(chmod, const char __user *, filename, umode_t, mode) */
  [__SNR_chmod] = {
    .name  = "chmod",
    .func  = chmod,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:101: 91	common	fchmod			sys_fchmod */
/* ../../hyperodf/fs/open.c:600: SYSCALL_DEFINE2(fchmod, unsigned int, fd, umode_t, mode) */
  [__SNR_fchmod] = {
    .name  = "fchmod",
    .func  = fchmod,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:102: 92	common	chown			sys_chown */
/* ../../hyperodf/fs/open.c:727: SYSCALL_DEFINE3(chown, const char __user *, filename, uid_t, user, gid_t, group) */
  [__SNR_chown] = {
    .name  = "chown",
    .func  = chown,
    .nargs = 3,
    .args  = {ARG_STR, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:103: 93	common	fchown			sys_fchown */
/* ../../hyperodf/fs/open.c:763: SYSCALL_DEFINE3(fchown, unsigned int, fd, uid_t, user, gid_t, group) */
  [__SNR_fchown] = {
    .name  = "fchown",
    .func  = fchown,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:104: 94	common	lchown			sys_lchown */
/* ../../hyperodf/fs/open.c:732: SYSCALL_DEFINE3(lchown, const char __user *, filename, uid_t, user, gid_t, group) */
  [__SNR_lchown] = {
    .name  = "lchown",
    .func  = lchown,
    .nargs = 3,
    .args  = {ARG_STR, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:105: 95	common	umask			sys_umask */
/* ../../hyperodf/kernel/sys.c:1841: SYSCALL_DEFINE1(umask, int, mask) */
  [__SNR_umask] = {
    .name  = "umask",
    .func  = umask,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:106: 96	common	gettimeofday		sys_gettimeofday */
/* ../../hyperodf/kernel/time/time.c:224: COMPAT_SYSCALL_DEFINE2(gettimeofday, struct old_timeval32 __user *, tv, struct timezone __user *, tz) */
  [__SNR_gettimeofday] = {
    .name  = "gettimeofday",
    .func  = gettimeofday,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(struct old_timeval32 ), sizeof(struct timezone ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:107: 97	common	getrlimit		sys_getrlimit */
/* ../../hyperodf/kernel/sys.c:1452: COMPAT_SYSCALL_DEFINE2(getrlimit, unsigned int, resource, struct compat_rlimit __user *, rlim) */
  [__SNR_getrlimit] = {
    .name  = "getrlimit",
    .func  = getrlimit,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_rlimit ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:108: 98	common	getrusage		sys_getrusage */
/* ../../hyperodf/kernel/sys.c:1828: COMPAT_SYSCALL_DEFINE2(getrusage, int, who, struct compat_rusage __user *, ru) */
  [__SNR_getrusage] = {
    .name  = "getrusage",
    .func  = getrusage,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_rusage ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:109: 99	common	sysinfo			sys_sysinfo */
/* ../../hyperodf/kernel/sys.c:2681: COMPAT_SYSCALL_DEFINE1(sysinfo, struct compat_sysinfo __user *, info) */
  [__SNR_sysinfo] = {
    .name  = "sysinfo",
    .func  = sysinfo,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct compat_sysinfo ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:110: 100	common	times			sys_times */
/* ../../hyperodf/kernel/sys.c:1008: COMPAT_SYSCALL_DEFINE1(times, struct compat_tms __user *, tbuf) */
  [__SNR_times] = {
    .name  = "times",
    .func  = times,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct compat_tms ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:111: 101	64	ptrace			sys_ptrace */
/* ../../hyperodf/kernel/ptrace.c:1424: COMPAT_SYSCALL_DEFINE4(ptrace, compat_long_t, request, compat_long_t, pid, compat_long_t, addr, compat_long_t, data) */
  [__SNR_ptrace] = {
    .name  = "ptrace",
    .func  = ptrace,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:112: 102	common	getuid			sys_getuid */
/* ../../hyperodf/kernel/sys.c:952: SYSCALL_DEFINE0(getuid) */
  [__SNR_getuid] = {
    .name  = "getuid",
    .func  = getuid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:113: 103	common	syslog			sys_syslog */
/* ../../hyperodf/kernel/printk/printk.c:1748: SYSCALL_DEFINE3(syslog, int, type, char __user *, buf, int, len) */
  [__SNR_syslog] = {
    .name  = "syslog",
    .func  = syslog,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:114: 104	common	getgid			sys_getgid */
/* ../../hyperodf/kernel/sys.c:964: SYSCALL_DEFINE0(getgid) */
  [__SNR_getgid] = {
    .name  = "getgid",
    .func  = getgid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:115: 105	common	setuid			sys_setuid */
/* ../../hyperodf/kernel/sys.c:635: SYSCALL_DEFINE1(setuid, uid_t, uid) */
  [__SNR_setuid] = {
    .name  = "setuid",
    .func  = setuid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:116: 106	common	setgid			sys_setgid */
/* ../../hyperodf/kernel/sys.c:459: SYSCALL_DEFINE1(setgid, gid_t, gid) */
  [__SNR_setgid] = {
    .name  = "setgid",
    .func  = setgid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:117: 107	common	geteuid			sys_geteuid */
/* ../../hyperodf/kernel/sys.c:958: SYSCALL_DEFINE0(geteuid) */
  [__SNR_geteuid] = {
    .name  = "geteuid",
    .func  = geteuid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:118: 108	common	getegid			sys_getegid */
/* ../../hyperodf/kernel/sys.c:970: SYSCALL_DEFINE0(getegid) */
  [__SNR_getegid] = {
    .name  = "getegid",
    .func  = getegid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:119: 109	common	setpgid			sys_setpgid */
/* ../../hyperodf/kernel/sys.c:1039: SYSCALL_DEFINE2(setpgid, pid_t, pid, pid_t, pgid) */
  [__SNR_setpgid] = {
    .name  = "setpgid",
    .func  = setpgid,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:120: 110	common	getppid			sys_getppid */
/* ../../hyperodf/kernel/sys.c:941: SYSCALL_DEFINE0(getppid) */
  [__SNR_getppid] = {
    .name  = "getppid",
    .func  = getppid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:121: 111	common	getpgrp			sys_getpgrp */
/* ../../hyperodf/kernel/sys.c:1145: SYSCALL_DEFINE0(getpgrp) */
  [__SNR_getpgrp] = {
    .name  = "getpgrp",
    .func  = getpgrp,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:122: 112	common	setsid			sys_setsid */
/* ../../hyperodf/kernel/sys.c:1224: SYSCALL_DEFINE0(setsid) */
  [__SNR_setsid] = {
    .name  = "setsid",
    .func  = setsid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:123: 113	common	setreuid		sys_setreuid */
/* ../../hyperodf/kernel/sys.c:573: SYSCALL_DEFINE2(setreuid, uid_t, ruid, uid_t, euid) */
  [__SNR_setreuid] = {
    .name  = "setreuid",
    .func  = setreuid,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:124: 114	common	setregid		sys_setregid */
/* ../../hyperodf/kernel/sys.c:413: SYSCALL_DEFINE2(setregid, gid_t, rgid, gid_t, egid) */
  [__SNR_setregid] = {
    .name  = "setregid",
    .func  = setregid,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:125: 115	common	getgroups		sys_getgroups */
/* ../../hyperodf/kernel/groups.c:148: SYSCALL_DEFINE2(getgroups, int, gidsetsize, gid_t __user *, grouplist) */
  [__SNR_getgroups] = {
    .name  = "getgroups",
    .func  = getgroups,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(gid_t ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:126: 116	common	setgroups		sys_setgroups */
/* ../../hyperodf/kernel/groups.c:185: SYSCALL_DEFINE2(setgroups, int, gidsetsize, gid_t __user *, grouplist) */
  [__SNR_setgroups] = {
    .name  = "setgroups",
    .func  = setgroups,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(gid_t ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:127: 117	common	setresuid		sys_setresuid */
/* ../../hyperodf/kernel/sys.c:714: SYSCALL_DEFINE3(setresuid, uid_t, ruid, uid_t, euid, uid_t, suid) */
  [__SNR_setresuid] = {
    .name  = "setresuid",
    .func  = setresuid,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:128: 118	common	getresuid		sys_getresuid */
/* ../../hyperodf/kernel/sys.c:719: SYSCALL_DEFINE3(getresuid, uid_t __user *, ruidp, uid_t __user *, euidp, uid_t __user *, suidp) */
  [__SNR_getresuid] = {
    .name  = "getresuid",
    .func  = getresuid,
    .nargs = 3,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(uid_t ), sizeof(uid_t ), sizeof(uid_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:129: 119	common	setresgid		sys_setresgid */
/* ../../hyperodf/kernel/sys.c:797: SYSCALL_DEFINE3(setresgid, gid_t, rgid, gid_t, egid, gid_t, sgid) */
  [__SNR_setresgid] = {
    .name  = "setresgid",
    .func  = setresgid,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:130: 120	common	getresgid		sys_getresgid */
/* ../../hyperodf/kernel/sys.c:802: SYSCALL_DEFINE3(getresgid, gid_t __user *, rgidp, gid_t __user *, egidp, gid_t __user *, sgidp) */
  [__SNR_getresgid] = {
    .name  = "getresgid",
    .func  = getresgid,
    .nargs = 3,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(gid_t ), sizeof(gid_t ), sizeof(gid_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:131: 121	common	getpgid			sys_getpgid */
/* ../../hyperodf/kernel/sys.c:1138: SYSCALL_DEFINE1(getpgid, pid_t, pid) */
  [__SNR_getpgid] = {
    .name  = "getpgid",
    .func  = getpgid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:132: 122	common	setfsuid		sys_setfsuid */
/* ../../hyperodf/kernel/sys.c:865: SYSCALL_DEFINE1(setfsuid, uid_t, uid) */
  [__SNR_setfsuid] = {
    .name  = "setfsuid",
    .func  = setfsuid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:133: 123	common	setfsgid		sys_setfsgid */
/* ../../hyperodf/kernel/sys.c:909: SYSCALL_DEFINE1(setfsgid, gid_t, gid) */
  [__SNR_setfsgid] = {
    .name  = "setfsgid",
    .func  = setfsgid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:134: 124	common	getsid			sys_getsid */
/* ../../hyperodf/kernel/sys.c:1152: SYSCALL_DEFINE1(getsid, pid_t, pid) */
  [__SNR_getsid] = {
    .name  = "getsid",
    .func  = getsid,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:135: 125	common	capget			sys_capget */
/* ../../hyperodf/kernel/capability.c:148: SYSCALL_DEFINE2(capget, cap_user_header_t, header, cap_user_data_t, dataptr) */
  [__SNR_capget] = {
    .name  = "capget",
    .func  = capget,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:136: 126	common	capset			sys_capset */
/* ../../hyperodf/kernel/capability.c:222: SYSCALL_DEFINE2(capset, cap_user_header_t, header, const cap_user_data_t, data) */
  [__SNR_capset] = {
    .name  = "capset",
    .func  = capset,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:137: 127	64	rt_sigpending		sys_rt_sigpending */
/* ../../hyperodf/kernel/signal.c:3216: COMPAT_SYSCALL_DEFINE2(rt_sigpending, compat_sigset_t __user *, uset, compat_size_t, sigsetsize) */
  [__SNR_rt_sigpending] = {
    .name  = "rt_sigpending",
    .func  = rt_sigpending,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(compat_sigset_t ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:138: 128	64	rt_sigtimedwait		sys_rt_sigtimedwait */
/* ../../hyperodf/kernel/signal.c:3611: SYSCALL_DEFINE4(rt_sigtimedwait, const sigset_t __user *, uthese, siginfo_t __user *, uinfo, const struct __kernel_timespec __user *, uts, size_t, sigsetsize) */
  [__SNR_rt_sigtimedwait] = {
    .name  = "rt_sigtimedwait",
    .func  = rt_sigtimedwait,
    .nargs = 4,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(sigset_t ), sizeof(siginfo_t ), sizeof(struct __kernel_timespec ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:139: 129	64	rt_sigqueueinfo		sys_rt_sigqueueinfo */
/* ../../hyperodf/kernel/signal.c:3991: COMPAT_SYSCALL_DEFINE3(rt_sigqueueinfo, compat_pid_t, pid, int, sig, struct compat_siginfo __user *, uinfo) */
  [__SNR_rt_sigqueueinfo] = {
    .name  = "rt_sigqueueinfo",
    .func  = rt_sigqueueinfo,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:140: 130	common	rt_sigsuspend		sys_rt_sigsuspend */
/* ../../hyperodf/kernel/signal.c:4595: COMPAT_SYSCALL_DEFINE2(rt_sigsuspend, compat_sigset_t __user *, unewset, compat_size_t, sigsetsize) */
  [__SNR_rt_sigsuspend] = {
    .name  = "rt_sigsuspend",
    .func  = rt_sigsuspend,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(compat_sigset_t ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:141: 131	64	sigaltstack		sys_sigaltstack */
/* ../../hyperodf/kernel/signal.c:4239: COMPAT_SYSCALL_DEFINE2(sigaltstack, const compat_stack_t __user *, uss_ptr, compat_stack_t __user *, uoss_ptr) */
  [__SNR_sigaltstack] = {
    .name  = "sigaltstack",
    .func  = sigaltstack,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(compat_stack_t ), sizeof(compat_stack_t ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:142: 132	common	utime			sys_utime */
/* ../../hyperodf/fs/utimes.c:214: SYSCALL_DEFINE2(utime, char __user *, filename, struct utimbuf __user *, times) */
  [__SNR_utime] = {
    .name  = "utime",
    .func  = utime,
    .nargs = 2,
    .args  = {ARG_STR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(struct utimbuf ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:143: 133	common	mknod			sys_mknod */
/* ../../hyperodf/fs/namei.c:3845: SYSCALL_DEFINE3(mknod, const char __user *, filename, umode_t, mode, unsigned, dev) */
  [__SNR_mknod] = {
    .name  = "mknod",
    .func  = mknod,
    .nargs = 3,
    .args  = {ARG_STR, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:144: 134	64	uselib */
/* ../../hyperodf/fs/exec.c:122: SYSCALL_DEFINE1(uselib, const char __user *, library) */
  [__SNR_uselib] = {
    .name  = "uselib",
    .func  = uselib,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:145: 135	common	personality		sys_personality */
/* ../../hyperodf/kernel/exec_domain.c:38: SYSCALL_DEFINE1(personality, unsigned int, personality) */
  [__SNR_personality] = {
    .name  = "personality",
    .func  = personality,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:146: 136	common	ustat			sys_ustat */
/* ../../hyperodf/fs/statfs.c:391: COMPAT_SYSCALL_DEFINE2(ustat, unsigned, dev, struct compat_ustat __user *, u) */
  [__SNR_ustat] = {
    .name  = "ustat",
    .func  = ustat,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_ustat ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:147: 137	common	statfs			sys_statfs */
/* ../../hyperodf/fs/statfs.c:305: COMPAT_SYSCALL_DEFINE2(statfs, const char __user *, pathname, struct compat_statfs __user *, buf) */
  [__SNR_statfs] = {
    .name  = "statfs",
    .func  = statfs,
    .nargs = 2,
    .args  = {ARG_STR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(struct compat_statfs ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:148: 138	common	fstatfs			sys_fstatfs */
/* ../../hyperodf/fs/statfs.c:314: COMPAT_SYSCALL_DEFINE2(fstatfs, unsigned int, fd, struct compat_statfs __user *, buf) */
  [__SNR_fstatfs] = {
    .name  = "fstatfs",
    .func  = fstatfs,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_statfs ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:149: 139	common	sysfs			sys_sysfs */
/* ../../hyperodf/fs/filesystems.c:191: SYSCALL_DEFINE3(sysfs, int, option, unsigned long, arg1, unsigned long, arg2) */
  [__SNR_sysfs] = {
    .name  = "sysfs",
    .func  = sysfs,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:150: 140	common	getpriority		sys_getpriority */
/* ../../hyperodf/kernel/sys.c:273: SYSCALL_DEFINE2(getpriority, int, which, int, who) */
  [__SNR_getpriority] = {
    .name  = "getpriority",
    .func  = getpriority,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:151: 141	common	setpriority		sys_setpriority */
/* ../../hyperodf/kernel/sys.c:203: SYSCALL_DEFINE3(setpriority, int, which, int, who, int, niceval) */
  [__SNR_setpriority] = {
    .name  = "setpriority",
    .func  = setpriority,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:152: 142	common	sched_setparam		sys_sched_setparam */
/* ../../hyperodf/kernel/sched/core.c:7448: SYSCALL_DEFINE2(sched_setparam, pid_t, pid, struct sched_param __user *, param) */
  [__SNR_sched_setparam] = {
    .name  = "sched_setparam",
    .func  = sched_setparam,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sched_param ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:153: 143	common	sched_getparam		sys_sched_getparam */
/* ../../hyperodf/kernel/sched/core.c:7531: SYSCALL_DEFINE2(sched_getparam, pid_t, pid, struct sched_param __user *, param) */
  [__SNR_sched_getparam] = {
    .name  = "sched_getparam",
    .func  = sched_getparam,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sched_param ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:154: 144	common	sched_setscheduler	sys_sched_setscheduler */
/* ../../hyperodf/kernel/sched/core.c:7433: SYSCALL_DEFINE3(sched_setscheduler, pid_t, pid, int, policy, struct sched_param __user *, param) */
  [__SNR_sched_setscheduler] = {
    .name  = "sched_setscheduler",
    .func  = sched_setscheduler,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct sched_param ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:155: 145	common	sched_getscheduler	sys_sched_getscheduler */
/* ../../hyperodf/kernel/sched/core.c:7502: SYSCALL_DEFINE1(sched_getscheduler, pid_t, pid) */
  [__SNR_sched_getscheduler] = {
    .name  = "sched_getscheduler",
    .func  = sched_getscheduler,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:156: 146	common	sched_get_priority_max	sys_sched_get_priority_max */
/* ../../hyperodf/kernel/sched/core.c:8132: SYSCALL_DEFINE1(sched_get_priority_max, int, policy) */
  [__SNR_sched_get_priority_max] = {
    .name  = "sched_get_priority_max",
    .func  = sched_get_priority_max,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:157: 147	common	sched_get_priority_min	sys_sched_get_priority_min */
/* ../../hyperodf/kernel/sched/core.c:8159: SYSCALL_DEFINE1(sched_get_priority_min, int, policy) */
  [__SNR_sched_get_priority_min] = {
    .name  = "sched_get_priority_min",
    .func  = sched_get_priority_min,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:158: 148	common	sched_rr_get_interval	sys_sched_rr_get_interval */
/* ../../hyperodf/kernel/sched/core.c:8224: SYSCALL_DEFINE2(sched_rr_get_interval, pid_t, pid, struct __kernel_timespec __user *, interval) */
  [__SNR_sched_rr_get_interval] = {
    .name  = "sched_rr_get_interval",
    .func  = sched_rr_get_interval,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_timespec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:159: 149	common	mlock			sys_mlock */
/* ../../hyperodf/mm/mlock.c:695: SYSCALL_DEFINE2(mlock, unsigned long, start, size_t, len) */
  [__SNR_mlock] = {
    .name  = "mlock",
    .func  = mlock,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:160: 150	common	munlock			sys_munlock */
/* ../../hyperodf/mm/mlock.c:713: SYSCALL_DEFINE2(munlock, unsigned long, start, size_t, len) */
  [__SNR_munlock] = {
    .name  = "munlock",
    .func  = munlock,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:161: 151	common	mlockall		sys_mlockall */
/* ../../hyperodf/mm/mlock.c:776: SYSCALL_DEFINE1(mlockall, int, flags) */
  [__SNR_mlockall] = {
    .name  = "mlockall",
    .func  = mlockall,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:162: 152	common	munlockall		sys_munlockall */
/* ../../hyperodf/mm/mlock.c:805: SYSCALL_DEFINE0(munlockall) */
  [__SNR_munlockall] = {
    .name  = "munlockall",
    .func  = munlockall,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:163: 153	common	vhangup			sys_vhangup */
/* ../../hyperodf/fs/open.c:1360: SYSCALL_DEFINE0(vhangup) */
  [__SNR_vhangup] = {
    .name  = "vhangup",
    .func  = vhangup,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:164: 154	common	modify_ldt		sys_modify_ldt */
/* ../../hyperodf/arch/x86/um/ldt.c:373: SYSCALL_DEFINE3(modify_ldt, int , func , void __user * , ptr , unsigned long , bytecount) */
  [__SNR_modify_ldt] = {
    .name  = "modify_ldt",
    .func  = modify_ldt,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(void *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:165: 155	common	pivot_root		sys_pivot_root */
/* ../../hyperodf/fs/namespace.c:3816: SYSCALL_DEFINE2(pivot_root, const char __user *, new_root, const char __user *, put_old) */
  [__SNR_pivot_root] = {
    .name  = "pivot_root",
    .func  = pivot_root,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:166: 156	64	_sysctl			sys_ni_syscall */
/* WARNING: Found no args for syscall "_sysctl", using default (all pointers) */
  [__SNR__sysctl] = {
    .name  = "_sysctl",
    .func  = _sysctl,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:167: 157	common	prctl			sys_prctl */
/* ../../hyperodf/kernel/sys.c:2295: SYSCALL_DEFINE5(prctl, int, option, unsigned long, arg2, unsigned long, arg3, unsigned long, arg4, unsigned long, arg5) */
  [__SNR_prctl] = {
    .name  = "prctl",
    .func  = prctl,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:168: 158	common	arch_prctl		sys_arch_prctl */
/* ../../hyperodf/arch/x86/um/syscalls_64.c:78: SYSCALL_DEFINE2(arch_prctl, int, option, unsigned long, arg2) */
  [__SNR_arch_prctl] = {
    .name  = "arch_prctl",
    .func  = arch_prctl,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:169: 159	common	adjtimex		sys_adjtimex */
/* ../../hyperodf/kernel/time/time.c:269: SYSCALL_DEFINE1(adjtimex, struct __kernel_timex __user *, txc_p) */
  [__SNR_adjtimex] = {
    .name  = "adjtimex",
    .func  = adjtimex,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct __kernel_timex ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:170: 160	common	setrlimit		sys_setrlimit */
/* ../../hyperodf/kernel/sys.c:1688: SYSCALL_DEFINE2(setrlimit, unsigned int, resource, struct rlimit __user *, rlim) */
  [__SNR_setrlimit] = {
    .name  = "setrlimit",
    .func  = setrlimit,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct rlimit ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:171: 161	common	chroot			sys_chroot */
/* ../../hyperodf/fs/open.c:531: SYSCALL_DEFINE1(chroot, const char __user *, filename) */
  [__SNR_chroot] = {
    .name  = "chroot",
    .func  = chroot,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:172: 162	common	sync			sys_sync */
/* ../../hyperodf/fs/sync.c:123: SYSCALL_DEFINE0(sync) */
  [__SNR_sync] = {
    .name  = "sync",
    .func  = sync,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:173: 163	common	acct			sys_acct */
/* ../../hyperodf/kernel/acct.c:273: SYSCALL_DEFINE1(acct, const char __user *, name) */
  [__SNR_acct] = {
    .name  = "acct",
    .func  = acct,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:174: 164	common	settimeofday		sys_settimeofday */
/* ../../hyperodf/kernel/time/time.c:243: COMPAT_SYSCALL_DEFINE2(settimeofday, struct old_timeval32 __user *, tv, struct timezone __user *, tz) */
  [__SNR_settimeofday] = {
    .name  = "settimeofday",
    .func  = settimeofday,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(struct old_timeval32 ), sizeof(struct timezone ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:175: 165	common	mount			sys_mount */
/* ../../hyperodf/fs/namespace.c:3516: SYSCALL_DEFINE5(mount, char __user *, dev_name, char __user *, dir_name, char __user *, type, unsigned long, flags, void __user *, data) */
  [__SNR_mount] = {
    .name  = "mount",
    .func  = mount,
    .nargs = 5,
    .args  = {ARG_STR, ARG_STR, ARG_STR, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(char *), sizeof(int), sizeof(void *), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:176: 166	common	umount2			sys_umount */
/* WARNING: Found no args for syscall "umount2", using default (all pointers) */
  [__SNR_umount2] = {
    .name  = "umount2",
    .func  = umount2,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:177: 167	common	swapon			sys_swapon */
/* ../../hyperodf/mm/swapfile.c:3127: SYSCALL_DEFINE2(swapon, const char __user *, specialfile, int, swap_flags) */
  [__SNR_swapon] = {
    .name  = "swapon",
    .func  = swapon,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:178: 168	common	swapoff			sys_swapoff */
/* ../../hyperodf/mm/swapfile.c:2518: SYSCALL_DEFINE1(swapoff, const char __user *, specialfile) */
  [__SNR_swapoff] = {
    .name  = "swapoff",
    .func  = swapoff,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:179: 169	common	reboot			sys_reboot */
/* ../../hyperodf/kernel/reboot.c:311: SYSCALL_DEFINE4(reboot, int, magic1, int, magic2, unsigned int, cmd, void __user *, arg) */
  [__SNR_reboot] = {
    .name  = "reboot",
    .func  = reboot,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(void *), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:180: 170	common	sethostname		sys_sethostname */
/* ../../hyperodf/kernel/sys.c:1340: SYSCALL_DEFINE2(sethostname, char __user *, name, int, len) */
  [__SNR_sethostname] = {
    .name  = "sethostname",
    .func  = sethostname,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:181: 171	common	setdomainname		sys_setdomainname */
/* ../../hyperodf/kernel/sys.c:1393: SYSCALL_DEFINE2(setdomainname, char __user *, name, int, len) */
  [__SNR_setdomainname] = {
    .name  = "setdomainname",
    .func  = setdomainname,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:182: 172	common	iopl			sys_iopl */
/* ../../hyperodf/arch/x86/kernel/ioport.c:211: SYSCALL_DEFINE1(iopl, unsigned int, level) */
  [__SNR_iopl] = {
    .name  = "iopl",
    .func  = iopl,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:183: 173	common	ioperm			sys_ioperm */
/* ../../hyperodf/arch/x86/kernel/ioport.c:206: SYSCALL_DEFINE3(ioperm, unsigned long, from, unsigned long, num, int, turn_on) */
  [__SNR_ioperm] = {
    .name  = "ioperm",
    .func  = ioperm,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:184: 174	64	create_module */
/* WARNING: Found no args for syscall "create_module", using default (all pointers) */
  [__SNR_create_module] = {
    .name  = "create_module",
    .func  = create_module,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:185: 175	common	init_module		sys_init_module */
/* ../../hyperodf/kernel/module.c:4144: SYSCALL_DEFINE3(init_module, void __user *, umod, unsigned long, len, const char __user *, uargs) */
  [__SNR_init_module] = {
    .name  = "init_module",
    .func  = init_module,
    .nargs = 3,
    .args  = {ARG_PTR, ARG_INT, ARG_STR, -1, -1, -1},
    .lens  = {sizeof(void *), sizeof(int), sizeof(char *), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:186: 176	common	delete_module		sys_delete_module */
/* ../../hyperodf/kernel/module.c:912: SYSCALL_DEFINE2(delete_module, const char __user *, name_user, unsigned int, flags) */
  [__SNR_delete_module] = {
    .name  = "delete_module",
    .func  = delete_module,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:187: 177	64	get_kernel_syms */
/* WARNING: Found no args for syscall "get_kernel_syms", using default (all pointers) */
  [__SNR_get_kernel_syms] = {
    .name  = "get_kernel_syms",
    .func  = get_kernel_syms,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:188: 178	64	query_module */
/* WARNING: Found no args for syscall "query_module", using default (all pointers) */
  [__SNR_query_module] = {
    .name  = "query_module",
    .func  = query_module,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:189: 179	common	quotactl		sys_quotactl */
/* ../../hyperodf/fs/quota/quota.c:915: SYSCALL_DEFINE4(quotactl, unsigned int, cmd, const char __user *, special, qid_t, id, void __user *, addr) */
  [__SNR_quotactl] = {
    .name  = "quotactl",
    .func  = quotactl,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(void *), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:190: 180	64	nfsservctl */
/* WARNING: Found no args for syscall "nfsservctl", using default (all pointers) */
  [__SNR_nfsservctl] = {
    .name  = "nfsservctl",
    .func  = nfsservctl,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:191: 181	common	getpmsg */
/* WARNING: Found no args for syscall "getpmsg", using default (all pointers) */
  [__SNR_getpmsg] = {
    .name  = "getpmsg",
    .func  = getpmsg,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:192: 182	common	putpmsg */
/* WARNING: Found no args for syscall "putpmsg", using default (all pointers) */
  [__SNR_putpmsg] = {
    .name  = "putpmsg",
    .func  = putpmsg,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:193: 183	common	afs_syscall */
/* WARNING: Found no args for syscall "afs_syscall", using default (all pointers) */
  [__SNR_afs_syscall] = {
    .name  = "afs_syscall",
    .func  = afs_syscall,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:194: 184	common	tuxcall */
/* WARNING: Found no args for syscall "tuxcall", using default (all pointers) */
  [__SNR_tuxcall] = {
    .name  = "tuxcall",
    .func  = tuxcall,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:195: 185	common	security */
/* WARNING: Found no args for syscall "security", using default (all pointers) */
  [__SNR_security] = {
    .name  = "security",
    .func  = security,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:196: 186	common	gettid			sys_gettid */
/* ../../hyperodf/kernel/sys.c:930: SYSCALL_DEFINE0(gettid) */
  [__SNR_gettid] = {
    .name  = "gettid",
    .func  = gettid,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:197: 187	common	readahead		sys_readahead */
/* ../../hyperodf/mm/readahead.c:639: SYSCALL_DEFINE3(readahead, int, fd, loff_t, offset, size_t, count) */
  [__SNR_readahead] = {
    .name  = "readahead",
    .func  = readahead,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:198: 188	common	setxattr		sys_setxattr */
/* ../../hyperodf/fs/xattr.c:607: SYSCALL_DEFINE5(setxattr, const char __user *, pathname, const char __user *, name, const void __user *, value, size_t, size, int, flags) */
  [__SNR_setxattr] = {
    .name  = "setxattr",
    .func  = setxattr,
    .nargs = 5,
    .args  = {ARG_STR, ARG_STR, ARG_PTR, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(void *), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:199: 189	common	lsetxattr		sys_lsetxattr */
/* ../../hyperodf/fs/xattr.c:614: SYSCALL_DEFINE5(lsetxattr, const char __user *, pathname, const char __user *, name, const void __user *, value, size_t, size, int, flags) */
  [__SNR_lsetxattr] = {
    .name  = "lsetxattr",
    .func  = lsetxattr,
    .nargs = 5,
    .args  = {ARG_STR, ARG_STR, ARG_PTR, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(void *), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:200: 190	common	fsetxattr		sys_fsetxattr */
/* ../../hyperodf/fs/xattr.c:621: SYSCALL_DEFINE5(fsetxattr, int, fd, const char __user *, name, const void __user *,value, size_t, size, int, flags) */
  [__SNR_fsetxattr] = {
    .name  = "fsetxattr",
    .func  = fsetxattr,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(void *), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:201: 191	common	getxattr		sys_getxattr */
/* ../../hyperodf/fs/xattr.c:703: SYSCALL_DEFINE4(getxattr, const char __user *, pathname, const char __user *, name, void __user *, value, size_t, size) */
  [__SNR_getxattr] = {
    .name  = "getxattr",
    .func  = getxattr,
    .nargs = 4,
    .args  = {ARG_STR, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(void *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:202: 192	common	lgetxattr		sys_lgetxattr */
/* ../../hyperodf/fs/xattr.c:709: SYSCALL_DEFINE4(lgetxattr, const char __user *, pathname, const char __user *, name, void __user *, value, size_t, size) */
  [__SNR_lgetxattr] = {
    .name  = "lgetxattr",
    .func  = lgetxattr,
    .nargs = 4,
    .args  = {ARG_STR, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(void *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:203: 193	common	fgetxattr		sys_fgetxattr */
/* ../../hyperodf/fs/xattr.c:715: SYSCALL_DEFINE4(fgetxattr, int, fd, const char __user *, name, void __user *, value, size_t, size) */
  [__SNR_fgetxattr] = {
    .name  = "fgetxattr",
    .func  = fgetxattr,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(void *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:204: 194	common	listxattr		sys_listxattr */
/* ../../hyperodf/fs/xattr.c:780: SYSCALL_DEFINE3(listxattr, const char __user *, pathname, char __user *, list, size_t, size) */
  [__SNR_listxattr] = {
    .name  = "listxattr",
    .func  = listxattr,
    .nargs = 3,
    .args  = {ARG_STR, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:205: 195	common	llistxattr		sys_llistxattr */
/* ../../hyperodf/fs/xattr.c:786: SYSCALL_DEFINE3(llistxattr, const char __user *, pathname, char __user *, list, size_t, size) */
  [__SNR_llistxattr] = {
    .name  = "llistxattr",
    .func  = llistxattr,
    .nargs = 3,
    .args  = {ARG_STR, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:206: 196	common	flistxattr		sys_flistxattr */
/* ../../hyperodf/fs/xattr.c:792: SYSCALL_DEFINE3(flistxattr, int, fd, char __user *, list, size_t, size) */
  [__SNR_flistxattr] = {
    .name  = "flistxattr",
    .func  = flistxattr,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:207: 197	common	removexattr		sys_removexattr */
/* ../../hyperodf/fs/xattr.c:846: SYSCALL_DEFINE2(removexattr, const char __user *, pathname, const char __user *, name) */
  [__SNR_removexattr] = {
    .name  = "removexattr",
    .func  = removexattr,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:208: 198	common	lremovexattr		sys_lremovexattr */
/* ../../hyperodf/fs/xattr.c:852: SYSCALL_DEFINE2(lremovexattr, const char __user *, pathname, const char __user *, name) */
  [__SNR_lremovexattr] = {
    .name  = "lremovexattr",
    .func  = lremovexattr,
    .nargs = 2,
    .args  = {ARG_STR, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:209: 199	common	fremovexattr		sys_fremovexattr */
/* ../../hyperodf/fs/xattr.c:858: SYSCALL_DEFINE2(fremovexattr, int, fd, const char __user *, name) */
  [__SNR_fremovexattr] = {
    .name  = "fremovexattr",
    .func  = fremovexattr,
    .nargs = 2,
    .args  = {ARG_INT, ARG_STR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:210: 200	common	tkill			sys_tkill */
/* ../../hyperodf/kernel/signal.c:3952: SYSCALL_DEFINE2(tkill, pid_t, pid, int, sig) */
  [__SNR_tkill] = {
    .name  = "tkill",
    .func  = tkill,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:211: 201	common	time			sys_time */
/* ../../hyperodf/kernel/time/time.c:62: SYSCALL_DEFINE1(time, __kernel_old_time_t __user *, tloc) */
  [__SNR_time] = {
    .name  = "time",
    .func  = time,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(__kernel_old_time_t ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:212: 202	common	futex			sys_futex */
/* ../../hyperodf/kernel/futex.c:3990: SYSCALL_DEFINE6(futex, u32 __user *, uaddr, int, op, u32, val, const struct __kernel_timespec __user *, utime, u32 __user *, uaddr2, u32, val3) */
  [__SNR_futex] = {
    .name  = "futex",
    .func  = futex,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT},
    .lens  = {sizeof(u32 ), sizeof(int), sizeof(int), sizeof(struct __kernel_timespec ), sizeof(u32 ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:213: 203	common	sched_setaffinity	sys_sched_setaffinity */
/* ../../hyperodf/kernel/sched/core.c:7766: SYSCALL_DEFINE3(sched_setaffinity, pid_t, pid, unsigned int, len, unsigned long __user *, user_mask_ptr) */
  [__SNR_sched_setaffinity] = {
    .name  = "sched_setaffinity",
    .func  = sched_setaffinity,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(unsigned long ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:214: 204	common	sched_getaffinity	sys_sched_getaffinity */
/* ../../hyperodf/kernel/sched/core.c:7818: SYSCALL_DEFINE3(sched_getaffinity, pid_t, pid, unsigned int, len, unsigned long __user *, user_mask_ptr) */
  [__SNR_sched_getaffinity] = {
    .name  = "sched_getaffinity",
    .func  = sched_getaffinity,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(unsigned long ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:215: 205	64	set_thread_area */
/* ../../hyperodf/arch/x86/um/tls_32.c:277: SYSCALL_DEFINE1(set_thread_area, struct user_desc __user *, user_desc) */
  [__SNR_set_thread_area] = {
    .name  = "set_thread_area",
    .func  = set_thread_area,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct user_desc ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:216: 206	64	io_setup		sys_io_setup */
/* ../../hyperodf/fs/aio.c:1342: COMPAT_SYSCALL_DEFINE2(io_setup, unsigned, nr_events, u32 __user *, ctx32p) */
  [__SNR_io_setup] = {
    .name  = "io_setup",
    .func  = io_setup,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(u32 ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:217: 207	common	io_destroy		sys_io_destroy */
/* ../../hyperodf/fs/aio.c:1380: SYSCALL_DEFINE1(io_destroy, aio_context_t, ctx) */
  [__SNR_io_destroy] = {
    .name  = "io_destroy",
    .func  = io_destroy,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:218: 208	common	io_getevents		sys_io_getevents */
/* ../../hyperodf/fs/aio.c:2079: SYSCALL_DEFINE5(io_getevents, aio_context_t, ctx_id, long, min_nr, long, nr, struct io_event __user *, events, struct __kernel_timespec __user *, timeout) */
  [__SNR_io_getevents] = {
    .name  = "io_getevents",
    .func  = io_getevents,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(struct io_event ), sizeof(struct __kernel_timespec ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:219: 209	64	io_submit		sys_io_submit */
/* ../../hyperodf/fs/aio.c:1951: COMPAT_SYSCALL_DEFINE3(io_submit, compat_aio_context_t, ctx_id, int, nr, compat_uptr_t __user *, iocbpp) */
  [__SNR_io_submit] = {
    .name  = "io_submit",
    .func  = io_submit,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(compat_uptr_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:220: 210	common	io_cancel		sys_io_cancel */
/* ../../hyperodf/fs/aio.c:2003: SYSCALL_DEFINE3(io_cancel, aio_context_t, ctx_id, struct iocb __user *, iocb, struct io_event __user *, result) */
  [__SNR_io_cancel] = {
    .name  = "io_cancel",
    .func  = io_cancel,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iocb ), sizeof(struct io_event ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:221: 211	64	get_thread_area */
/* ../../hyperodf/arch/x86/um/tls_32.c:325: SYSCALL_DEFINE1(get_thread_area, struct user_desc __user *, user_desc) */
  [__SNR_get_thread_area] = {
    .name  = "get_thread_area",
    .func  = get_thread_area,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(struct user_desc ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:222: 212	common	lookup_dcookie		sys_lookup_dcookie */
/* WARNING: Found no args for syscall "lookup_dcookie", using default (all pointers) */
  [__SNR_lookup_dcookie] = {
    .name  = "lookup_dcookie",
    .func  = lookup_dcookie,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:223: 213	common	epoll_create		sys_epoll_create */
/* ../../hyperodf/fs/eventpoll.c:2007: SYSCALL_DEFINE1(epoll_create, int, size) */
  [__SNR_epoll_create] = {
    .name  = "epoll_create",
    .func  = epoll_create,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:224: 214	64	epoll_ctl_old */
/* WARNING: Found no args for syscall "epoll_ctl_old", using default (all pointers) */
  [__SNR_epoll_ctl_old] = {
    .name  = "epoll_ctl_old",
    .func  = epoll_ctl_old,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:225: 215	64	epoll_wait_old */
/* WARNING: Found no args for syscall "epoll_wait_old", using default (all pointers) */
  [__SNR_epoll_wait_old] = {
    .name  = "epoll_wait_old",
    .func  = epoll_wait_old,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:226: 216	common	remap_file_pages	sys_remap_file_pages */
/* ../../hyperodf/mm/mmap.c:3035: SYSCALL_DEFINE5(remap_file_pages, unsigned long, start, unsigned long, size, unsigned long, prot, unsigned long, pgoff, unsigned long, flags) */
  [__SNR_remap_file_pages] = {
    .name  = "remap_file_pages",
    .func  = remap_file_pages,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:227: 217	common	getdents64		sys_getdents64 */
/* ../../hyperodf/fs/readdir.c:354: SYSCALL_DEFINE3(getdents64, unsigned int, fd, struct linux_dirent64 __user *, dirent, unsigned int, count) */
  [__SNR_getdents64] = {
    .name  = "getdents64",
    .func  = getdents64,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct linux_dirent64 ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:228: 218	common	set_tid_address		sys_set_tid_address */
/* ../../hyperodf/kernel/fork.c:1705: SYSCALL_DEFINE1(set_tid_address, int __user *, tidptr) */
  [__SNR_set_tid_address] = {
    .name  = "set_tid_address",
    .func  = set_tid_address,
    .nargs = 1,
    .args  = {ARG_PTR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int ), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:229: 219	common	restart_syscall		sys_restart_syscall */
/* ../../hyperodf/kernel/signal.c:2985: SYSCALL_DEFINE0(restart_syscall) */
  [__SNR_restart_syscall] = {
    .name  = "restart_syscall",
    .func  = restart_syscall,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:230: 220	common	semtimedop		sys_semtimedop */
/* ../../hyperodf/ipc/sem.c:2253: SYSCALL_DEFINE4(semtimedop, int, semid, struct sembuf __user *, tsops, unsigned int, nsops, const struct __kernel_timespec __user *, timeout) */
  [__SNR_semtimedop] = {
    .name  = "semtimedop",
    .func  = semtimedop,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sembuf ), sizeof(int), sizeof(struct __kernel_timespec ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:231: 221	common	fadvise64		sys_fadvise64 */
/* ../../hyperodf/mm/fadvise.c:213: SYSCALL_DEFINE4(fadvise64, int, fd, loff_t, offset, size_t, len, int, advice) */
  [__SNR_fadvise64] = {
    .name  = "fadvise64",
    .func  = fadvise64,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:232: 222	64	timer_create		sys_timer_create */
/* ../../hyperodf/kernel/time/posix-timers.c:592: COMPAT_SYSCALL_DEFINE3(timer_create, clockid_t, which_clock, struct compat_sigevent __user *, timer_event_spec, timer_t __user *, created_timer_id) */
  [__SNR_timer_create] = {
    .name  = "timer_create",
    .func  = timer_create,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigevent ), sizeof(timer_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:233: 223	common	timer_settime		sys_timer_settime */
/* ../../hyperodf/kernel/time/posix-timers.c:938: SYSCALL_DEFINE4(timer_settime, timer_t, timer_id, int, flags, const struct __kernel_itimerspec __user *, new_setting, struct __kernel_itimerspec __user *, old_setting) */
  [__SNR_timer_settime] = {
    .name  = "timer_settime",
    .func  = timer_settime,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct __kernel_itimerspec ), sizeof(struct __kernel_itimerspec ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:234: 224	common	timer_gettime		sys_timer_gettime */
/* ../../hyperodf/kernel/time/posix-timers.c:738: SYSCALL_DEFINE2(timer_gettime, timer_t, timer_id, struct __kernel_itimerspec __user *, setting) */
  [__SNR_timer_gettime] = {
    .name  = "timer_gettime",
    .func  = timer_gettime,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_itimerspec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:235: 225	common	timer_getoverrun	sys_timer_getoverrun */
/* ../../hyperodf/kernel/time/posix-timers.c:777: SYSCALL_DEFINE1(timer_getoverrun, timer_t, timer_id) */
  [__SNR_timer_getoverrun] = {
    .name  = "timer_getoverrun",
    .func  = timer_getoverrun,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:236: 226	common	timer_delete		sys_timer_delete */
/* ../../hyperodf/kernel/time/posix-timers.c:1004: SYSCALL_DEFINE1(timer_delete, timer_t, timer_id) */
  [__SNR_timer_delete] = {
    .name  = "timer_delete",
    .func  = timer_delete,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:237: 227	common	clock_settime		sys_clock_settime */
/* ../../hyperodf/kernel/time/posix-timers.c:1067: SYSCALL_DEFINE2(clock_settime, const clockid_t, which_clock, const struct __kernel_timespec __user *, tp) */
  [__SNR_clock_settime] = {
    .name  = "clock_settime",
    .func  = clock_settime,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_timespec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:238: 228	common	clock_gettime		sys_clock_gettime */
/* ../../hyperodf/kernel/time/posix-timers.c:1082: SYSCALL_DEFINE2(clock_gettime, const clockid_t, which_clock, struct __kernel_timespec __user *, tp) */
  [__SNR_clock_gettime] = {
    .name  = "clock_gettime",
    .func  = clock_gettime,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_timespec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:239: 229	common	clock_getres		sys_clock_getres */
/* ../../hyperodf/kernel/time/posix-timers.c:1129: SYSCALL_DEFINE2(clock_getres, const clockid_t, which_clock, struct __kernel_timespec __user *, tp) */
  [__SNR_clock_getres] = {
    .name  = "clock_getres",
    .func  = clock_getres,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_timespec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:240: 230	common	clock_nanosleep		sys_clock_nanosleep */
/* ../../hyperodf/kernel/time/posix-timers.c:1245: SYSCALL_DEFINE4(clock_nanosleep, const clockid_t, which_clock, int, flags, const struct __kernel_timespec __user *, rqtp, struct __kernel_timespec __user *, rmtp) */
  [__SNR_clock_nanosleep] = {
    .name  = "clock_nanosleep",
    .func  = clock_nanosleep,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct __kernel_timespec ), sizeof(struct __kernel_timespec ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:241: 231	common	exit_group		sys_exit_group */
/* ../../hyperodf/kernel/exit.c:931: SYSCALL_DEFINE1(exit_group, int, error_code) */
  [__SNR_exit_group] = {
    .name  = "exit_group",
    .func  = exit_group,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:242: 232	common	epoll_wait		sys_epoll_wait */
/* ../../hyperodf/fs/eventpoll.c:2235: SYSCALL_DEFINE4(epoll_wait, int, epfd, struct epoll_event __user *, events, int, maxevents, int, timeout) */
  [__SNR_epoll_wait] = {
    .name  = "epoll_wait",
    .func  = epoll_wait,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct epoll_event ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:243: 233	common	epoll_ctl		sys_epoll_ctl */
/* ../../hyperodf/fs/eventpoll.c:2177: SYSCALL_DEFINE4(epoll_ctl, int, epfd, int, op, int, fd, struct epoll_event __user *, event) */
  [__SNR_epoll_ctl] = {
    .name  = "epoll_ctl",
    .func  = epoll_ctl,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(struct epoll_event ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:244: 234	common	tgkill			sys_tgkill */
/* ../../hyperodf/kernel/signal.c:3936: SYSCALL_DEFINE3(tgkill, pid_t, tgid, pid_t, pid, int, sig) */
  [__SNR_tgkill] = {
    .name  = "tgkill",
    .func  = tgkill,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:245: 235	common	utimes			sys_utimes */
/* ../../hyperodf/fs/utimes.c:208: SYSCALL_DEFINE2(utimes, char __user *, filename, struct __kernel_old_timeval __user *, utimes) */
  [__SNR_utimes] = {
    .name  = "utimes",
    .func  = utimes,
    .nargs = 2,
    .args  = {ARG_STR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(struct __kernel_old_timeval ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:246: 236	64	vserver */
/* WARNING: Found no args for syscall "vserver", using default (all pointers) */
  [__SNR_vserver] = {
    .name  = "vserver",
    .func  = vserver,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:247: 237	common	mbind			sys_mbind */
/* ../../hyperodf/mm/mempolicy.c:1486: SYSCALL_DEFINE6(mbind, unsigned long, start, unsigned long, len, unsigned long, mode, const unsigned long __user *, nmask, unsigned long, maxnode, unsigned int, flags) */
  [__SNR_mbind] = {
    .name  = "mbind",
    .func  = mbind,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(unsigned long ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:248: 238	common	set_mempolicy		sys_set_mempolicy */
/* ../../hyperodf/mm/mempolicy.c:1513: SYSCALL_DEFINE3(set_mempolicy, int, mode, const unsigned long __user *, nmask, unsigned long, maxnode) */
  [__SNR_set_mempolicy] = {
    .name  = "set_mempolicy",
    .func  = set_mempolicy,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(unsigned long ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:249: 239	common	get_mempolicy		sys_get_mempolicy */
/* ../../hyperodf/mm/mempolicy.c:1645: SYSCALL_DEFINE5(get_mempolicy, int __user *, policy, unsigned long __user *, nmask, unsigned long, maxnode, unsigned long, addr, unsigned long, flags) */
  [__SNR_get_mempolicy] = {
    .name  = "get_mempolicy",
    .func  = get_mempolicy,
    .nargs = 5,
    .args  = {ARG_PTR, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int ), sizeof(unsigned long ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:250: 240	common	mq_open			sys_mq_open */
/* ../../hyperodf/ipc/mqueue.c:1551: COMPAT_SYSCALL_DEFINE4(mq_open, const char __user *, u_name, int, oflag, compat_mode_t, mode, struct compat_mq_attr __user *, u_attr) */
  [__SNR_mq_open] = {
    .name  = "mq_open",
    .func  = mq_open,
    .nargs = 4,
    .args  = {ARG_STR, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(int), sizeof(struct compat_mq_attr ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:251: 241	common	mq_unlink		sys_mq_unlink */
/* ../../hyperodf/ipc/mqueue.c:940: SYSCALL_DEFINE1(mq_unlink, const char __user *, u_name) */
  [__SNR_mq_unlink] = {
    .name  = "mq_unlink",
    .func  = mq_unlink,
    .nargs = 1,
    .args  = {ARG_STR, -1, -1, -1, -1, -1},
    .lens  = {sizeof(char *), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:252: 242	common	mq_timedsend		sys_mq_timedsend */
/* ../../hyperodf/ipc/mqueue.c:1273: SYSCALL_DEFINE5(mq_timedsend, mqd_t, mqdes, const char __user *, u_msg_ptr, size_t, msg_len, unsigned int, msg_prio, const struct __kernel_timespec __user *, u_abs_timeout) */
  [__SNR_mq_timedsend] = {
    .name  = "mq_timedsend",
    .func  = mq_timedsend,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), sizeof(struct __kernel_timespec ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:253: 243	common	mq_timedreceive		sys_mq_timedreceive */
/* ../../hyperodf/ipc/mqueue.c:1287: SYSCALL_DEFINE5(mq_timedreceive, mqd_t, mqdes, char __user *, u_msg_ptr, size_t, msg_len, unsigned int __user *, u_msg_prio, const struct __kernel_timespec __user *, u_abs_timeout) */
  [__SNR_mq_timedreceive] = {
    .name  = "mq_timedreceive",
    .func  = mq_timedreceive,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_PTR, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(unsigned int ), sizeof(struct __kernel_timespec ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:254: 244	64	mq_notify		sys_mq_notify */
/* ../../hyperodf/ipc/mqueue.c:1564: COMPAT_SYSCALL_DEFINE2(mq_notify, mqd_t, mqdes, const struct compat_sigevent __user *, u_notification) */
  [__SNR_mq_notify] = {
    .name  = "mq_notify",
    .func  = mq_notify,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigevent ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:255: 245	common	mq_getsetattr		sys_mq_getsetattr */
/* ../../hyperodf/ipc/mqueue.c:1578: COMPAT_SYSCALL_DEFINE3(mq_getsetattr, mqd_t, mqdes, const struct compat_mq_attr __user *, u_mqstat, struct compat_mq_attr __user *, u_omqstat) */
  [__SNR_mq_getsetattr] = {
    .name  = "mq_getsetattr",
    .func  = mq_getsetattr,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_mq_attr ), sizeof(struct compat_mq_attr ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:256: 246	64	kexec_load		sys_kexec_load */
/* ../../hyperodf/kernel/kexec.c:257: COMPAT_SYSCALL_DEFINE4(kexec_load, compat_ulong_t, entry, compat_ulong_t, nr_segments, struct compat_kexec_segment __user *, segments, compat_ulong_t, flags) */
  [__SNR_kexec_load] = {
    .name  = "kexec_load",
    .func  = kexec_load,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_kexec_segment ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:257: 247	64	waitid			sys_waitid */
/* ../../hyperodf/kernel/exit.c:1743: COMPAT_SYSCALL_DEFINE5(waitid, int, which, compat_pid_t, pid, struct compat_siginfo __user *, infop, int, options, struct compat_rusage __user *, uru) */
  [__SNR_waitid] = {
    .name  = "waitid",
    .func  = waitid,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), sizeof(int), sizeof(struct compat_rusage ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:258: 248	common	add_key			sys_add_key */
/* ../../hyperodf/security/keys/keyctl.c:74: SYSCALL_DEFINE5(add_key, const char __user *, _type, const char __user *, _description, const void __user *, _payload, size_t, plen, key_serial_t, ringid) */
  [__SNR_add_key] = {
    .name  = "add_key",
    .func  = add_key,
    .nargs = 5,
    .args  = {ARG_STR, ARG_STR, ARG_PTR, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(void *), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:259: 249	common	request_key		sys_request_key */
/* ../../hyperodf/security/keys/keyctl.c:167: SYSCALL_DEFINE4(request_key, const char __user *, _type, const char __user *, _description, const char __user *, _callout_info, key_serial_t, destringid) */
  [__SNR_request_key] = {
    .name  = "request_key",
    .func  = request_key,
    .nargs = 4,
    .args  = {ARG_STR, ARG_STR, ARG_STR, ARG_INT, -1, -1},
    .lens  = {sizeof(char *), sizeof(char *), sizeof(char *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:260: 250	common	keyctl			sys_keyctl */
/* ../../hyperodf/security/keys/compat.c:17: COMPAT_SYSCALL_DEFINE5(keyctl, u32, option, u32, arg2, u32, arg3, u32, arg4, u32, arg5) */
  [__SNR_keyctl] = {
    .name  = "keyctl",
    .func  = keyctl,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:261: 251	common	ioprio_set		sys_ioprio_set */
/* WARNING: Found no args for syscall "ioprio_set", using default (all pointers) */
  [__SNR_ioprio_set] = {
    .name  = "ioprio_set",
    .func  = ioprio_set,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:262: 252	common	ioprio_get		sys_ioprio_get */
/* WARNING: Found no args for syscall "ioprio_get", using default (all pointers) */
  [__SNR_ioprio_get] = {
    .name  = "ioprio_get",
    .func  = ioprio_get,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:263: 253	common	inotify_init		sys_inotify_init */
/* ../../hyperodf/fs/notify/inotify/inotify_user.c:704: SYSCALL_DEFINE0(inotify_init) */
  [__SNR_inotify_init] = {
    .name  = "inotify_init",
    .func  = inotify_init,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:264: 254	common	inotify_add_watch	sys_inotify_add_watch */
/* ../../hyperodf/fs/notify/inotify/inotify_user.c:709: SYSCALL_DEFINE3(inotify_add_watch, int, fd, const char __user *, pathname, u32, mask) */
  [__SNR_inotify_add_watch] = {
    .name  = "inotify_add_watch",
    .func  = inotify_add_watch,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:265: 255	common	inotify_rm_watch	sys_inotify_rm_watch */
/* ../../hyperodf/fs/notify/inotify/inotify_user.c:773: SYSCALL_DEFINE2(inotify_rm_watch, int, fd, __s32, wd) */
  [__SNR_inotify_rm_watch] = {
    .name  = "inotify_rm_watch",
    .func  = inotify_rm_watch,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:266: 256	common	migrate_pages		sys_migrate_pages */
/* ../../hyperodf/mm/mempolicy.c:1607: SYSCALL_DEFINE4(migrate_pages, pid_t, pid, unsigned long, maxnode, const unsigned long __user *, old_nodes, const unsigned long __user *, new_nodes) */
  [__SNR_migrate_pages] = {
    .name  = "migrate_pages",
    .func  = migrate_pages,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(unsigned long ), sizeof(unsigned long ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:267: 257	common	openat			sys_openat */
/* ../../hyperodf/fs/open.c:1272: COMPAT_SYSCALL_DEFINE4(openat, int, dfd, const char __user *, filename, int, flags, umode_t, mode) */
  [__SNR_openat] = {
    .name  = "openat",
    .func  = openat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:268: 258	common	mkdirat			sys_mkdirat */
/* ../../hyperodf/fs/namei.c:3924: SYSCALL_DEFINE3(mkdirat, int, dfd, const char __user *, pathname, umode_t, mode) */
  [__SNR_mkdirat] = {
    .name  = "mkdirat",
    .func  = mkdirat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:269: 259	common	mknodat			sys_mknodat */
/* ../../hyperodf/fs/namei.c:3839: SYSCALL_DEFINE4(mknodat, int, dfd, const char __user *, filename, umode_t, mode, unsigned int, dev) */
  [__SNR_mknodat] = {
    .name  = "mknodat",
    .func  = mknodat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:270: 260	common	fchownat		sys_fchownat */
/* ../../hyperodf/fs/open.c:721: SYSCALL_DEFINE5(fchownat, int, dfd, const char __user *, filename, uid_t, user, gid_t, group, int, flag) */
  [__SNR_fchownat] = {
    .name  = "fchownat",
    .func  = fchownat,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:271: 261	common	futimesat		sys_futimesat */
/* ../../hyperodf/fs/utimes.c:202: SYSCALL_DEFINE3(futimesat, int, dfd, const char __user *, filename, struct __kernel_old_timeval __user *, utimes) */
  [__SNR_futimesat] = {
    .name  = "futimesat",
    .func  = futimesat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(struct __kernel_old_timeval ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:272: 262	common	newfstatat		sys_newfstatat */
/* ../../hyperodf/fs/stat.c:701: COMPAT_SYSCALL_DEFINE4(newfstatat, unsigned int, dfd, const char __user *, filename, struct compat_stat __user *, statbuf, int, flag) */
  [__SNR_newfstatat] = {
    .name  = "newfstatat",
    .func  = newfstatat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(struct compat_stat ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:273: 263	common	unlinkat		sys_unlinkat */
/* ../../hyperodf/fs/namei.c:4205: SYSCALL_DEFINE3(unlinkat, int, dfd, const char __user *, pathname, int, flag) */
  [__SNR_unlinkat] = {
    .name  = "unlinkat",
    .func  = unlinkat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:274: 264	common	renameat		sys_renameat */
/* ../../hyperodf/fs/namei.c:4816: SYSCALL_DEFINE4(renameat, int, olddfd, const char __user *, oldname, int, newdfd, const char __user *, newname) */
  [__SNR_renameat] = {
    .name  = "renameat",
    .func  = renameat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_STR, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(char *), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:275: 265	common	linkat			sys_linkat */
/* ../../hyperodf/fs/namei.c:4474: SYSCALL_DEFINE5(linkat, int, olddfd, const char __user *, oldname, int, newdfd, const char __user *, newname, int, flags) */
  [__SNR_linkat] = {
    .name  = "linkat",
    .func  = linkat,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:276: 266	common	symlinkat		sys_symlinkat */
/* ../../hyperodf/fs/namei.c:4293: SYSCALL_DEFINE3(symlinkat, const char __user *, oldname, int, newdfd, const char __user *, newname) */
  [__SNR_symlinkat] = {
    .name  = "symlinkat",
    .func  = symlinkat,
    .nargs = 3,
    .args  = {ARG_STR, ARG_INT, ARG_STR, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), sizeof(char *), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:277: 267	common	readlinkat		sys_readlinkat */
/* ../../hyperodf/fs/stat.c:467: SYSCALL_DEFINE4(readlinkat, int, dfd, const char __user *, pathname, char __user *, buf, int, bufsiz) */
  [__SNR_readlinkat] = {
    .name  = "readlinkat",
    .func  = readlinkat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_STR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(char *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:278: 268	common	fchmodat		sys_fchmodat */
/* ../../hyperodf/fs/open.c:630: SYSCALL_DEFINE3(fchmodat, int, dfd, const char __user *, filename, umode_t, mode) */
  [__SNR_fchmodat] = {
    .name  = "fchmodat",
    .func  = fchmodat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:279: 269	common	faccessat		sys_faccessat */
/* ../../hyperodf/fs/open.c:467: SYSCALL_DEFINE3(faccessat, int, dfd, const char __user *, filename, int, mode) */
  [__SNR_faccessat] = {
    .name  = "faccessat",
    .func  = faccessat,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:280: 270	common	pselect6		sys_pselect6 */
/* ../../hyperodf/fs/select.c:791: SYSCALL_DEFINE6(pselect6, int, n, fd_set __user *, inp, fd_set __user *, outp, fd_set __user *, exp, struct __kernel_timespec __user *, tsp, void __user *, sig) */
  [__SNR_pselect6] = {
    .name  = "pselect6",
    .func  = pselect6,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(int), sizeof(fd_set ), sizeof(fd_set ), sizeof(fd_set ), sizeof(struct __kernel_timespec ), sizeof(void *)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:281: 271	common	ppoll			sys_ppoll */
/* ../../hyperodf/fs/select.c:1097: SYSCALL_DEFINE5(ppoll, struct pollfd __user *, ufds, unsigned int, nfds, struct __kernel_timespec __user *, tsp, const sigset_t __user *, sigmask, size_t, sigsetsize) */
  [__SNR_ppoll] = {
    .name  = "ppoll",
    .func  = ppoll,
    .nargs = 5,
    .args  = {ARG_PTR, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(struct pollfd ), sizeof(int), sizeof(struct __kernel_timespec ), sizeof(sigset_t ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:282: 272	common	unshare			sys_unshare */
/* ../../hyperodf/kernel/fork.c:3134: SYSCALL_DEFINE1(unshare, unsigned long, unshare_flags) */
  [__SNR_unshare] = {
    .name  = "unshare",
    .func  = unshare,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:283: 273	64	set_robust_list		sys_set_robust_list */
/* ../../hyperodf/kernel/futex.c:4115: COMPAT_SYSCALL_DEFINE2(set_robust_list, struct compat_robust_list_head __user *, head, compat_size_t, len) */
  [__SNR_set_robust_list] = {
    .name  = "set_robust_list",
    .func  = set_robust_list,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(struct compat_robust_list_head ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:284: 274	64	get_robust_list		sys_get_robust_list */
/* ../../hyperodf/kernel/futex.c:4130: COMPAT_SYSCALL_DEFINE3(get_robust_list, int, pid, compat_uptr_t __user *, head_ptr, compat_size_t __user *, len_ptr) */
  [__SNR_get_robust_list] = {
    .name  = "get_robust_list",
    .func  = get_robust_list,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_uptr_t ), sizeof(compat_size_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:285: 275	common	splice			sys_splice */
/* ../../hyperodf/fs/splice.c:1332: SYSCALL_DEFINE6(splice, int, fd_in, loff_t __user *, off_in, int, fd_out, loff_t __user *, off_out, size_t, len, unsigned int, flags) */
  [__SNR_splice] = {
    .name  = "splice",
    .func  = splice,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(loff_t ), sizeof(int), sizeof(loff_t ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:286: 276	common	tee			sys_tee */
/* ../../hyperodf/fs/splice.c:1698: SYSCALL_DEFINE4(tee, int, fdin, int, fdout, size_t, len, unsigned int, flags) */
  [__SNR_tee] = {
    .name  = "tee",
    .func  = tee,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:287: 277	common	sync_file_range		sys_sync_file_range */
/* ../../hyperodf/fs/sync.c:382: SYSCALL_DEFINE4(sync_file_range, int, fd, loff_t, offset, loff_t, nbytes, unsigned int, flags) */
  [__SNR_sync_file_range] = {
    .name  = "sync_file_range",
    .func  = sync_file_range,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:288: 278	64	vmsplice		sys_vmsplice */
/* ../../hyperodf/fs/splice.c:1296: SYSCALL_DEFINE4(vmsplice, int, fd, const struct iovec __user *, uiov, unsigned long, nr_segs, unsigned int, flags) */
  [__SNR_vmsplice] = {
    .name  = "vmsplice",
    .func  = vmsplice,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:289: 279	64	move_pages		sys_move_pages */
/* ../../hyperodf/mm/migrate.c:2035: SYSCALL_DEFINE6(move_pages, pid_t, pid, unsigned long, nr_pages, const void __user * __user *, pages, const int __user *, nodes, int __user *, status, int, flags) */
  [__SNR_move_pages] = {
    .name  = "move_pages",
    .func  = move_pages,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), sizeof(int ), sizeof(int ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:290: 280	common	utimensat		sys_utimensat */
/* ../../hyperodf/fs/utimes.c:147: SYSCALL_DEFINE4(utimensat, int, dfd, const char __user *, filename, struct __kernel_timespec __user *, utimes, int, flags) */
  [__SNR_utimensat] = {
    .name  = "utimensat",
    .func  = utimensat,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(struct __kernel_timespec ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:291: 281	common	epoll_pwait		sys_epoll_pwait */
/* ../../hyperodf/fs/eventpoll.c:2321: COMPAT_SYSCALL_DEFINE6(epoll_pwait, int, epfd, struct epoll_event __user *, events, int, maxevents, int, timeout, const compat_sigset_t __user *, sigmask, compat_size_t, sigsetsize) */
  [__SNR_epoll_pwait] = {
    .name  = "epoll_pwait",
    .func  = epoll_pwait,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct epoll_event ), sizeof(int), sizeof(int), sizeof(compat_sigset_t ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:292: 282	common	signalfd		sys_signalfd */
/* ../../hyperodf/fs/signalfd.c:357: COMPAT_SYSCALL_DEFINE3(signalfd, int, ufd, const compat_sigset_t __user *, user_mask, compat_size_t, sigsetsize) */
  [__SNR_signalfd] = {
    .name  = "signalfd",
    .func  = signalfd,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_sigset_t ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:293: 283	common	timerfd_create		sys_timerfd_create */
/* ../../hyperodf/fs/timerfd.c:406: SYSCALL_DEFINE2(timerfd_create, int, clockid, int, flags) */
  [__SNR_timerfd_create] = {
    .name  = "timerfd_create",
    .func  = timerfd_create,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:294: 284	common	eventfd			sys_eventfd */
/* ../../hyperodf/fs/eventfd.c:456: SYSCALL_DEFINE1(eventfd, unsigned int, count) */
  [__SNR_eventfd] = {
    .name  = "eventfd",
    .func  = eventfd,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:295: 285	common	fallocate		sys_fallocate */
/* ../../hyperodf/fs/open.c:336: SYSCALL_DEFINE4(fallocate, int, fd, int, mode, loff_t, offset, loff_t, len) */
  [__SNR_fallocate] = {
    .name  = "fallocate",
    .func  = fallocate,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:296: 286	common	timerfd_settime		sys_timerfd_settime */
/* ../../hyperodf/fs/timerfd.c:558: SYSCALL_DEFINE4(timerfd_settime, int, ufd, int, flags, const struct __kernel_itimerspec __user *, utmr, struct __kernel_itimerspec __user *, otmr) */
  [__SNR_timerfd_settime] = {
    .name  = "timerfd_settime",
    .func  = timerfd_settime,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct __kernel_itimerspec ), sizeof(struct __kernel_itimerspec ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:297: 287	common	timerfd_gettime		sys_timerfd_gettime */
/* ../../hyperodf/fs/timerfd.c:576: SYSCALL_DEFINE2(timerfd_gettime, int, ufd, struct __kernel_itimerspec __user *, otmr) */
  [__SNR_timerfd_gettime] = {
    .name  = "timerfd_gettime",
    .func  = timerfd_gettime,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_itimerspec ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:298: 288	common	accept4			sys_accept4 */
/* ../../hyperodf/net/socket.c:1852: SYSCALL_DEFINE4(accept4, int, fd, struct sockaddr __user *, upeer_sockaddr, int __user *, upeer_addrlen, int, flags) */
  [__SNR_accept4] = {
    .name  = "accept4",
    .func  = accept4,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sockaddr ), sizeof(int ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:299: 289	common	signalfd4		sys_signalfd4 */
/* ../../hyperodf/fs/signalfd.c:349: COMPAT_SYSCALL_DEFINE4(signalfd4, int, ufd, const compat_sigset_t __user *, user_mask, compat_size_t, sigsetsize, int, flags) */
  [__SNR_signalfd4] = {
    .name  = "signalfd4",
    .func  = signalfd4,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_sigset_t ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:300: 290	common	eventfd2		sys_eventfd2 */
/* ../../hyperodf/fs/eventfd.c:451: SYSCALL_DEFINE2(eventfd2, unsigned int, count, int, flags) */
  [__SNR_eventfd2] = {
    .name  = "eventfd2",
    .func  = eventfd2,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:301: 291	common	epoll_create1		sys_epoll_create1 */
/* ../../hyperodf/fs/eventpoll.c:2002: SYSCALL_DEFINE1(epoll_create1, int, flags) */
  [__SNR_epoll_create1] = {
    .name  = "epoll_create1",
    .func  = epoll_create1,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:302: 292	common	dup3			sys_dup3 */
/* ../../hyperodf/fs/file.c:1187: SYSCALL_DEFINE3(dup3, unsigned int, oldfd, unsigned int, newfd, int, flags) */
  [__SNR_dup3] = {
    .name  = "dup3",
    .func  = dup3,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:303: 293	common	pipe2			sys_pipe2 */
/* ../../hyperodf/fs/pipe.c:1026: SYSCALL_DEFINE2(pipe2, int __user *, fildes, int, flags) */
  [__SNR_pipe2] = {
    .name  = "pipe2",
    .func  = pipe2,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:304: 294	common	inotify_init1		sys_inotify_init1 */
/* ../../hyperodf/fs/notify/inotify/inotify_user.c:699: SYSCALL_DEFINE1(inotify_init1, int, flags) */
  [__SNR_inotify_init1] = {
    .name  = "inotify_init1",
    .func  = inotify_init1,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:305: 295	64	preadv			sys_preadv */
/* ../../hyperodf/fs/read_write.c:1106: COMPAT_SYSCALL_DEFINE5(preadv, compat_ulong_t, fd, const struct iovec __user *, vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high) */
  [__SNR_preadv] = {
    .name  = "preadv",
    .func  = preadv,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:306: 296	64	pwritev			sys_pwritev */
/* ../../hyperodf/fs/read_write.c:1147: COMPAT_SYSCALL_DEFINE5(pwritev, compat_ulong_t, fd, const struct iovec __user *,vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high) */
  [__SNR_pwritev] = {
    .name  = "pwritev",
    .func  = pwritev,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:307: 297	64	rt_tgsigqueueinfo	sys_rt_tgsigqueueinfo */
/* ../../hyperodf/kernel/signal.c:4031: COMPAT_SYSCALL_DEFINE4(rt_tgsigqueueinfo, compat_pid_t, tgid, compat_pid_t, pid, int, sig, struct compat_siginfo __user *, uinfo) */
  [__SNR_rt_tgsigqueueinfo] = {
    .name  = "rt_tgsigqueueinfo",
    .func  = rt_tgsigqueueinfo,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:308: 298	common	perf_event_open		sys_perf_event_open */
/* ../../hyperodf/kernel/events/core.c:11963: SYSCALL_DEFINE5(perf_event_open, struct perf_event_attr __user *, attr_uptr, pid_t, pid, int, cpu, int, group_fd, unsigned long, flags) */
  [__SNR_perf_event_open] = {
    .name  = "perf_event_open",
    .func  = perf_event_open,
    .nargs = 5,
    .args  = {ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(struct perf_event_attr ), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:309: 299	64	recvmmsg		sys_recvmmsg */
/* ../../hyperodf/net/socket.c:2856: SYSCALL_DEFINE5(recvmmsg, int, fd, struct mmsghdr __user *, mmsg, unsigned int, vlen, unsigned int, flags, struct __kernel_timespec __user *, timeout) */
  [__SNR_recvmmsg] = {
    .name  = "recvmmsg",
    .func  = recvmmsg,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(struct mmsghdr ), sizeof(int), sizeof(int), sizeof(struct __kernel_timespec ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:310: 300	common	fanotify_init		sys_fanotify_init */
/* ../../hyperodf/fs/notify/fanotify/fanotify_user.c:1144: SYSCALL_DEFINE2(fanotify_init, unsigned int, flags, unsigned int, event_f_flags) */
  [__SNR_fanotify_init] = {
    .name  = "fanotify_init",
    .func  = fanotify_init,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:311: 301	common	fanotify_mark		sys_fanotify_mark */
/* ../../hyperodf/fs/notify/fanotify/fanotify_user.c:1547: SYSCALL_DEFINE5(fanotify_mark, int, fanotify_fd, unsigned int, flags, __u64, mask, int, dfd, const char  __user *, pathname) */
  [__SNR_fanotify_mark] = {
    .name  = "fanotify_mark",
    .func  = fanotify_mark,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_STR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(char *), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:312: 302	common	prlimit64		sys_prlimit64 */
/* ../../hyperodf/kernel/sys.c:1641: SYSCALL_DEFINE4(prlimit64, pid_t, pid, unsigned int, resource, const struct rlimit64 __user *, new_rlim, struct rlimit64 __user *, old_rlim) */
  [__SNR_prlimit64] = {
    .name  = "prlimit64",
    .func  = prlimit64,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct rlimit64 ), sizeof(struct rlimit64 ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:313: 303	common	name_to_handle_at	sys_name_to_handle_at */
/* ../../hyperodf/fs/fhandle.c:93: SYSCALL_DEFINE5(name_to_handle_at, int, dfd, const char __user *, name, struct file_handle __user *, handle, int __user *, mnt_id, int, flag) */
  [__SNR_name_to_handle_at] = {
    .name  = "name_to_handle_at",
    .func  = name_to_handle_at,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(struct file_handle ), sizeof(int ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:314: 304	common	open_by_handle_at	sys_open_by_handle_at */
/* ../../hyperodf/fs/fhandle.c:274: COMPAT_SYSCALL_DEFINE3(open_by_handle_at, int, mountdirfd, struct file_handle __user *, handle, int, flags) */
  [__SNR_open_by_handle_at] = {
    .name  = "open_by_handle_at",
    .func  = open_by_handle_at,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct file_handle ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:315: 305	common	clock_adjtime		sys_clock_adjtime */
/* ../../hyperodf/kernel/time/posix-timers.c:1112: SYSCALL_DEFINE2(clock_adjtime, const clockid_t, which_clock, struct __kernel_timex __user *, utx) */
  [__SNR_clock_adjtime] = {
    .name  = "clock_adjtime",
    .func  = clock_adjtime,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct __kernel_timex ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:316: 306	common	syncfs			sys_syncfs */
/* ../../hyperodf/fs/sync.c:161: SYSCALL_DEFINE1(syncfs, int, fd) */
  [__SNR_syncfs] = {
    .name  = "syncfs",
    .func  = syncfs,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:317: 307	64	sendmmsg		sys_sendmmsg */
/* ../../hyperodf/net/socket.c:2572: SYSCALL_DEFINE4(sendmmsg, int, fd, struct mmsghdr __user *, mmsg, unsigned int, vlen, unsigned int, flags) */
  [__SNR_sendmmsg] = {
    .name  = "sendmmsg",
    .func  = sendmmsg,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct mmsghdr ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:318: 308	common	setns			sys_setns */
/* ../../hyperodf/kernel/nsproxy.c:527: SYSCALL_DEFINE2(setns, int, fd, int, flags) */
  [__SNR_setns] = {
    .name  = "setns",
    .func  = setns,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:319: 309	common	getcpu			sys_getcpu */
/* ../../hyperodf/kernel/sys.c:2571: SYSCALL_DEFINE3(getcpu, unsigned __user *, cpup, unsigned __user *, nodep, struct getcpu_cache __user *, unused) */
  [__SNR_getcpu] = {
    .name  = "getcpu",
    .func  = getcpu,
    .nargs = 3,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(unsigned ), sizeof(unsigned ), sizeof(struct getcpu_cache ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:320: 310	64	process_vm_readv	sys_process_vm_readv */
/* ../../hyperodf/mm/process_vm_access.c:291: SYSCALL_DEFINE6(process_vm_readv, pid_t, pid, const struct iovec __user *, lvec, unsigned long, liovcnt, const struct iovec __user *, rvec, unsigned long, riovcnt,	unsigned long, flags) */
  [__SNR_process_vm_readv] = {
    .name  = "process_vm_readv",
    .func  = process_vm_readv,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:321: 311	64	process_vm_writev	sys_process_vm_writev */
/* ../../hyperodf/mm/process_vm_access.c:298: SYSCALL_DEFINE6(process_vm_writev, pid_t, pid, const struct iovec __user *, lvec, unsigned long, liovcnt, const struct iovec __user *, rvec, unsigned long, riovcnt,	unsigned long, flags) */
  [__SNR_process_vm_writev] = {
    .name  = "process_vm_writev",
    .func  = process_vm_writev,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:322: 312	common	kcmp			sys_kcmp */
/* ../../hyperodf/kernel/kcmp.c:135: SYSCALL_DEFINE5(kcmp, pid_t, pid1, pid_t, pid2, int, type, unsigned long, idx1, unsigned long, idx2) */
  [__SNR_kcmp] = {
    .name  = "kcmp",
    .func  = kcmp,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:323: 313	common	finit_module		sys_finit_module */
/* ../../hyperodf/kernel/module.c:4164: SYSCALL_DEFINE3(finit_module, int, fd, const char __user *, uargs, int, flags) */
  [__SNR_finit_module] = {
    .name  = "finit_module",
    .func  = finit_module,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:324: 314	common	sched_setattr		sys_sched_setattr */
/* ../../hyperodf/kernel/sched/core.c:7459: SYSCALL_DEFINE3(sched_setattr, pid_t, pid, struct sched_attr __user *, uattr, unsigned int, flags) */
  [__SNR_sched_setattr] = {
    .name  = "sched_setattr",
    .func  = sched_setattr,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sched_attr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:325: 315	common	sched_getattr		sys_sched_getattr */
/* ../../hyperodf/kernel/sched/core.c:7612: SYSCALL_DEFINE4(sched_getattr, pid_t, pid, struct sched_attr __user *, uattr, unsigned int, usize, unsigned int, flags) */
  [__SNR_sched_getattr] = {
    .name  = "sched_getattr",
    .func  = sched_getattr,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct sched_attr ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:326: 316	common	renameat2		sys_renameat2 */
/* ../../hyperodf/fs/namei.c:4809: SYSCALL_DEFINE5(renameat2, int, olddfd, const char __user *, oldname, int, newdfd, const char __user *, newname, unsigned int, flags) */
  [__SNR_renameat2] = {
    .name  = "renameat2",
    .func  = renameat2,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:327: 317	common	seccomp			sys_seccomp */
/* ../../hyperodf/kernel/seccomp.c:1988: SYSCALL_DEFINE3(seccomp, unsigned int, op, unsigned int, flags, void __user *, uargs) */
  [__SNR_seccomp] = {
    .name  = "seccomp",
    .func  = seccomp,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:328: 318	common	getrandom		sys_getrandom */
/* WARNING: Found no args for syscall "getrandom", using default (all pointers) */
  [__SNR_getrandom] = {
    .name  = "getrandom",
    .func  = getrandom,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:329: 319	common	memfd_create		sys_memfd_create */
/* ../../hyperodf/mm/memfd.c:250: SYSCALL_DEFINE2(memfd_create, const char __user *, uname, unsigned int, flags) */
  [__SNR_memfd_create] = {
    .name  = "memfd_create",
    .func  = memfd_create,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:330: 320	common	kexec_file_load		sys_kexec_file_load */
/* ../../hyperodf/kernel/kexec_file.c:354: SYSCALL_DEFINE5(kexec_file_load, int, kernel_fd, int, initrd_fd, unsigned long, cmdline_len, const char __user *, cmdline_ptr, unsigned long, flags) */
  [__SNR_kexec_file_load] = {
    .name  = "kexec_file_load",
    .func  = kexec_file_load,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:331: 321	common	bpf			sys_bpf */
/* ../../hyperodf/kernel/bpf/syscall.c:4689: SYSCALL_DEFINE3(bpf, int, cmd, union bpf_attr __user *, uattr, unsigned int, size) */
  [__SNR_bpf] = {
    .name  = "bpf",
    .func  = bpf,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(union bpf_attr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:332: 322	64	execveat		sys_execveat */
/* ../../hyperodf/fs/exec.c:2088: COMPAT_SYSCALL_DEFINE5(execveat, int, fd, const char __user *, filename, const compat_uptr_t __user *, argv, const compat_uptr_t __user *, envp, int,  flags) */
  [__SNR_execveat] = {
    .name  = "execveat",
    .func  = execveat,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(compat_uptr_t ), sizeof(compat_uptr_t ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:333: 323	common	userfaultfd		sys_userfaultfd */
/* ../../hyperodf/fs/userfaultfd.c:2056: SYSCALL_DEFINE1(userfaultfd, int, flags) */
  [__SNR_userfaultfd] = {
    .name  = "userfaultfd",
    .func  = userfaultfd,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:334: 324	common	membarrier		sys_membarrier */
/* ../../hyperodf/kernel/sched/membarrier.c:579: SYSCALL_DEFINE3(membarrier, int, cmd, unsigned int, flags, int, cpu_id) */
  [__SNR_membarrier] = {
    .name  = "membarrier",
    .func  = membarrier,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:335: 325	common	mlock2			sys_mlock2 */
/* ../../hyperodf/mm/mlock.c:700: SYSCALL_DEFINE3(mlock2, unsigned long, start, size_t, len, int, flags) */
  [__SNR_mlock2] = {
    .name  = "mlock2",
    .func  = mlock2,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:336: 326	common	copy_file_range		sys_copy_file_range */
/* ../../hyperodf/fs/read_write.c:1536: SYSCALL_DEFINE6(copy_file_range, int, fd_in, loff_t __user *, off_in, int, fd_out, loff_t __user *, off_out, size_t, len, unsigned int, flags) */
  [__SNR_copy_file_range] = {
    .name  = "copy_file_range",
    .func  = copy_file_range,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(loff_t ), sizeof(int), sizeof(loff_t ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:337: 327	64	preadv2			sys_preadv2 */
/* ../../hyperodf/fs/read_write.c:1126: COMPAT_SYSCALL_DEFINE6(preadv2, compat_ulong_t, fd, const struct iovec __user *, vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high, rwf_t, flags) */
  [__SNR_preadv2] = {
    .name  = "preadv2",
    .func  = preadv2,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:338: 328	64	pwritev2		sys_pwritev2 */
/* ../../hyperodf/fs/read_write.c:1167: COMPAT_SYSCALL_DEFINE6(pwritev2, compat_ulong_t, fd, const struct iovec __user *,vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high, rwf_t, flags) */
  [__SNR_pwritev2] = {
    .name  = "pwritev2",
    .func  = pwritev2,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:339: 329	common	pkey_mprotect		sys_pkey_mprotect */
/* ../../hyperodf/mm/mprotect.c:673: SYSCALL_DEFINE4(pkey_mprotect, unsigned long, start, size_t, len, unsigned long, prot, int, pkey) */
  [__SNR_pkey_mprotect] = {
    .name  = "pkey_mprotect",
    .func  = pkey_mprotect,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:340: 330	common	pkey_alloc		sys_pkey_alloc */
/* ../../hyperodf/mm/mprotect.c:679: SYSCALL_DEFINE2(pkey_alloc, unsigned long, flags, unsigned long, init_val) */
  [__SNR_pkey_alloc] = {
    .name  = "pkey_alloc",
    .func  = pkey_alloc,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:341: 331	common	pkey_free		sys_pkey_free */
/* ../../hyperodf/mm/mprotect.c:709: SYSCALL_DEFINE1(pkey_free, int, pkey) */
  [__SNR_pkey_free] = {
    .name  = "pkey_free",
    .func  = pkey_free,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:342: 332	common	statx			sys_statx */
/* ../../hyperodf/fs/stat.c:634: SYSCALL_DEFINE5(statx, int, dfd, const char __user *, filename, unsigned, flags, unsigned int, mask, struct statx __user *, buffer) */
  [__SNR_statx] = {
    .name  = "statx",
    .func  = statx,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), sizeof(struct statx ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:343: 333	common	io_pgetevents		sys_io_pgetevents */
/* ../../hyperodf/fs/aio.c:2206: COMPAT_SYSCALL_DEFINE6(io_pgetevents, compat_aio_context_t, ctx_id, compat_long_t, min_nr, compat_long_t, nr, struct io_event __user *, events, struct old_timespec32 __user *, timeout, const struct __compat_aio_sigset __user *, usig) */
  [__SNR_io_pgetevents] = {
    .name  = "io_pgetevents",
    .func  = io_pgetevents,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(struct io_event ), sizeof(struct old_timespec32 ), sizeof(struct __compat_aio_sigset )}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:344: 334	common	rseq			sys_rseq */
/* ../../hyperodf/kernel/rseq.c:320: SYSCALL_DEFINE4(rseq, struct rseq __user *, rseq, u32, rseq_len, int, flags, u32, sig) */
  [__SNR_rseq] = {
    .name  = "rseq",
    .func  = rseq,
    .nargs = 4,
    .args  = {ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(struct rseq ), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:347: 424	common	pidfd_send_signal	sys_pidfd_send_signal */
/* ../../hyperodf/kernel/signal.c:3830: SYSCALL_DEFINE4(pidfd_send_signal, int, pidfd, int, sig, siginfo_t __user *, info, unsigned int, flags) */
  [__SNR_pidfd_send_signal] = {
    .name  = "pidfd_send_signal",
    .func  = pidfd_send_signal,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(siginfo_t ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:348: 425	common	io_uring_setup		sys_io_uring_setup */
/* ../../hyperodf/fs/io_uring.c:10140: SYSCALL_DEFINE2(io_uring_setup, u32, entries, struct io_uring_params __user *, params) */
  [__SNR_io_uring_setup] = {
    .name  = "io_uring_setup",
    .func  = io_uring_setup,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct io_uring_params ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:349: 426	common	io_uring_enter		sys_io_uring_enter */
/* ../../hyperodf/fs/io_uring.c:9683: SYSCALL_DEFINE6(io_uring_enter, unsigned int, fd, u32, to_submit, u32, min_complete, u32, flags, const void __user *, argp, size_t, argsz) */
  [__SNR_io_uring_enter] = {
    .name  = "io_uring_enter",
    .func  = io_uring_enter,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), sizeof(void *), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:350: 427	common	io_uring_register	sys_io_uring_register */
/* ../../hyperodf/fs/io_uring.c:10586: SYSCALL_DEFINE4(io_uring_register, unsigned int, fd, unsigned int, opcode, void __user *, arg, unsigned int, nr_args) */
  [__SNR_io_uring_register] = {
    .name  = "io_uring_register",
    .func  = io_uring_register,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:351: 428	common	open_tree		sys_open_tree */
/* ../../hyperodf/fs/namespace.c:2454: SYSCALL_DEFINE3(open_tree, int, dfd, const char __user *, filename, unsigned, flags) */
  [__SNR_open_tree] = {
    .name  = "open_tree",
    .func  = open_tree,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:352: 429	common	move_mount		sys_move_mount */
/* ../../hyperodf/fs/namespace.c:3713: SYSCALL_DEFINE5(move_mount, int, from_dfd, const char __user *, from_pathname, int, to_dfd, const char __user *, to_pathname, unsigned int, flags) */
  [__SNR_move_mount] = {
    .name  = "move_mount",
    .func  = move_mount,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:353: 430	common	fsopen			sys_fsopen */
/* ../../hyperodf/fs/fsopen.c:115: SYSCALL_DEFINE2(fsopen, const char __user *, _fs_name, unsigned int, flags) */
  [__SNR_fsopen] = {
    .name  = "fsopen",
    .func  = fsopen,
    .nargs = 2,
    .args  = {ARG_STR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:354: 431	common	fsconfig		sys_fsconfig */
/* ../../hyperodf/fs/fsopen.c:314: SYSCALL_DEFINE5(fsconfig, int, fd, unsigned int, cmd, const char __user *, _key, const void __user *, _value, int, aux) */
  [__SNR_fsconfig] = {
    .name  = "fsconfig",
    .func  = fsconfig,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_STR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(char *), sizeof(void *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:355: 432	common	fsmount			sys_fsmount */
/* ../../hyperodf/fs/namespace.c:3584: SYSCALL_DEFINE3(fsmount, int, fs_fd, unsigned int, flags, unsigned int, attr_flags) */
  [__SNR_fsmount] = {
    .name  = "fsmount",
    .func  = fsmount,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:356: 433	common	fspick			sys_fspick */
/* ../../hyperodf/fs/fsopen.c:158: SYSCALL_DEFINE3(fspick, int, dfd, const char __user *, path, unsigned int, flags) */
  [__SNR_fspick] = {
    .name  = "fspick",
    .func  = fspick,
    .nargs = 3,
    .args  = {ARG_INT, ARG_STR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:357: 434	common	pidfd_open		sys_pidfd_open */
/* ../../hyperodf/kernel/pid.c:592: SYSCALL_DEFINE2(pidfd_open, pid_t, pid, unsigned int, flags) */
  [__SNR_pidfd_open] = {
    .name  = "pidfd_open",
    .func  = pidfd_open,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:358: 435	common	clone3			sys_clone3 */
/* ../../hyperodf/kernel/fork.c:2828: SYSCALL_DEFINE2(clone3, struct clone_args __user *, uargs, size_t, size) */
  [__SNR_clone3] = {
    .name  = "clone3",
    .func  = clone3,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(struct clone_args ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:359: 436	common	close_range		sys_close_range */
/* ../../hyperodf/fs/open.c:1350: SYSCALL_DEFINE3(close_range, unsigned int, fd, unsigned int, max_fd, unsigned int, flags) */
  [__SNR_close_range] = {
    .name  = "close_range",
    .func  = close_range,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:360: 437	common	openat2			sys_openat2 */
/* ../../hyperodf/fs/open.c:1235: SYSCALL_DEFINE4(openat2, int, dfd, const char __user *, filename, struct open_how __user *, how, size_t, usize) */
  [__SNR_openat2] = {
    .name  = "openat2",
    .func  = openat2,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(struct open_how ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:361: 438	common	pidfd_getfd		sys_pidfd_getfd */
/* ../../hyperodf/kernel/pid.c:687: SYSCALL_DEFINE3(pidfd_getfd, int, pidfd, int, fd, unsigned int, flags) */
  [__SNR_pidfd_getfd] = {
    .name  = "pidfd_getfd",
    .func  = pidfd_getfd,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:362: 439	common	faccessat2		sys_faccessat2 */
/* ../../hyperodf/fs/open.c:472: SYSCALL_DEFINE4(faccessat2, int, dfd, const char __user *, filename, int, mode, int, flags) */
  [__SNR_faccessat2] = {
    .name  = "faccessat2",
    .func  = faccessat2,
    .nargs = 4,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:363: 440	common	process_madvise		sys_process_madvise */
/* ../../hyperodf/mm/madvise.c:1231: SYSCALL_DEFINE5(process_madvise, int, pidfd, const struct iovec __user *, vec, size_t, vlen, int, behavior, unsigned int, flags) */
  [__SNR_process_madvise] = {
    .name  = "process_madvise",
    .func  = process_madvise,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:364: 441	common	epoll_pwait2		sys_epoll_pwait2 */
/* ../../hyperodf/fs/eventpoll.c:2334: COMPAT_SYSCALL_DEFINE6(epoll_pwait2, int, epfd, struct epoll_event __user *, events, int, maxevents, const struct __kernel_timespec __user *, timeout, const compat_sigset_t __user *, sigmask, compat_size_t, sigsetsize) */
  [__SNR_epoll_pwait2] = {
    .name  = "epoll_pwait2",
    .func  = epoll_pwait2,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct epoll_event ), sizeof(int), sizeof(struct __kernel_timespec ), sizeof(compat_sigset_t ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:365: 442	common	mount_setattr		sys_mount_setattr */
/* ../../hyperodf/fs/namespace.c:4226: SYSCALL_DEFINE5(mount_setattr, int, dfd, const char __user *, path, unsigned int, flags, struct mount_attr __user *, uattr, size_t, usize) */
  [__SNR_mount_setattr] = {
    .name  = "mount_setattr",
    .func  = mount_setattr,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_INT, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(int), sizeof(struct mount_attr ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:366: 443	common	quotactl_fd		sys_quotactl_fd */
/* ../../hyperodf/fs/quota/quota.c:971: SYSCALL_DEFINE4(quotactl_fd, unsigned int, fd, unsigned int, cmd, qid_t, id, void __user *, addr) */
  [__SNR_quotactl_fd] = {
    .name  = "quotactl_fd",
    .func  = quotactl_fd,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(void *), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:367: 444	common	landlock_create_ruleset	sys_landlock_create_ruleset */
/* ../../hyperodf/security/landlock/syscalls.c:156: SYSCALL_DEFINE3(landlock_create_ruleset, const struct landlock_ruleset_attr __user *const, attr, const size_t, size, const __u32, flags) */
  [__SNR_landlock_create_ruleset] = {
    .name  = "landlock_create_ruleset",
    .func  = landlock_create_ruleset,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:368: 445	common	landlock_add_rule	sys_landlock_add_rule */
/* ../../hyperodf/security/landlock/syscalls.c:304: SYSCALL_DEFINE4(landlock_add_rule, const int, ruleset_fd, const enum landlock_rule_type, rule_type, const void __user *const, rule_attr, const __u32, flags) */
  [__SNR_landlock_add_rule] = {
    .name  = "landlock_add_rule",
    .func  = landlock_add_rule,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:369: 446	common	landlock_restrict_self	sys_landlock_restrict_self */
/* ../../hyperodf/security/landlock/syscalls.c:392: SYSCALL_DEFINE2(landlock_restrict_self, const int, ruleset_fd, const __u32, flags) */
  [__SNR_landlock_restrict_self] = {
    .name  = "landlock_restrict_self",
    .func  = landlock_restrict_self,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:370: 447	common	memfd_secret		sys_memfd_secret */
/* ../../hyperodf/mm/secretmem.c:194: SYSCALL_DEFINE1(memfd_secret, unsigned int, flags) */
  [__SNR_memfd_secret] = {
    .name  = "memfd_secret",
    .func  = memfd_secret,
    .nargs = 1,
    .args  = {ARG_INT, -1, -1, -1, -1, -1},
    .lens  = {sizeof(int), -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:371: 448	common	process_mrelease	sys_process_mrelease */
/* ../../hyperodf/mm/oom_kill.c:1149: SYSCALL_DEFINE2(process_mrelease, int, pidfd, unsigned int, flags) */
  [__SNR_process_mrelease] = {
    .name  = "process_mrelease",
    .func  = process_mrelease,
    .nargs = 2,
    .args  = {ARG_INT, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:379: 512	x32	rt_sigaction		compat_sys_rt_sigaction */
/* ../../hyperodf/kernel/signal.c:4383: COMPAT_SYSCALL_DEFINE4(rt_sigaction, int, sig, const struct compat_sigaction __user *, act, struct compat_sigaction __user *, oact, compat_size_t, sigsetsize) */
  [__SNR_COMPAT_rt_sigaction] = {
    .name  = "rt_sigaction",
    .func  = rt_sigaction,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigaction ), sizeof(struct compat_sigaction ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:380: 513	x32	rt_sigreturn		compat_sys_x32_rt_sigreturn */
/* ../../hyperodf/arch/x86/ia32/ia32_signal.c:123: COMPAT_SYSCALL_DEFINE0(rt_sigreturn) */
  [__SNR_COMPAT_rt_sigreturn] = {
    .name  = "rt_sigreturn",
    .func  = rt_sigreturn,
    .nargs = 0,
    .args  = {-1, -1, -1, -1, -1, -1},
    .lens  = {-1, -1, -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:381: 514	x32	ioctl			compat_sys_ioctl */
/* ../../hyperodf/fs/ioctl.c:930: COMPAT_SYSCALL_DEFINE3(ioctl, unsigned int, fd, unsigned int, cmd, compat_ulong_t, arg) */
  [__SNR_COMPAT_ioctl] = {
    .name  = "ioctl",
    .func  = ioctl,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:382: 515	x32	readv			sys_readv */
/* ../../hyperodf/fs/read_write.c:1039: SYSCALL_DEFINE3(readv, unsigned long, fd, const struct iovec __user *, vec, unsigned long, vlen) */
  [__SNR_COMPAT_readv] = {
    .name  = "readv",
    .func  = readv,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:383: 516	x32	writev			sys_writev */
/* ../../hyperodf/fs/read_write.c:1045: SYSCALL_DEFINE3(writev, unsigned long, fd, const struct iovec __user *, vec, unsigned long, vlen) */
  [__SNR_COMPAT_writev] = {
    .name  = "writev",
    .func  = writev,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:384: 517	x32	recvfrom		compat_sys_recvfrom */
/* ../../hyperodf/net/socket.c:2104: SYSCALL_DEFINE6(recvfrom, int, fd, void __user *, ubuf, size_t, size, unsigned int, flags, struct sockaddr __user *, addr, int __user *, addr_len) */
  [__SNR_COMPAT_recvfrom] = {
    .name  = "recvfrom",
    .func  = recvfrom,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(int), sizeof(void *), sizeof(int), sizeof(int), sizeof(struct sockaddr ), sizeof(int )}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:385: 518	x32	sendmsg			compat_sys_sendmsg */
/* ../../hyperodf/net/socket.c:2496: SYSCALL_DEFINE3(sendmsg, int, fd, struct user_msghdr __user *, msg, unsigned int, flags) */
  [__SNR_COMPAT_sendmsg] = {
    .name  = "sendmsg",
    .func  = sendmsg,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct user_msghdr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:386: 519	x32	recvmsg			compat_sys_recvmsg */
/* ../../hyperodf/net/socket.c:2704: SYSCALL_DEFINE3(recvmsg, int, fd, struct user_msghdr __user *, msg, unsigned int, flags) */
  [__SNR_COMPAT_recvmsg] = {
    .name  = "recvmsg",
    .func  = recvmsg,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct user_msghdr ), sizeof(int), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:387: 520	x32	execve			compat_sys_execve */
/* ../../hyperodf/fs/exec.c:2081: COMPAT_SYSCALL_DEFINE3(execve, const char __user *, filename, const compat_uptr_t __user *, argv, const compat_uptr_t __user *, envp) */
  [__SNR_COMPAT_execve] = {
    .name  = "execve",
    .func  = execve,
    .nargs = 3,
    .args  = {ARG_STR, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(char *), sizeof(compat_uptr_t ), sizeof(compat_uptr_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:388: 521	x32	ptrace			compat_sys_ptrace */
/* ../../hyperodf/kernel/ptrace.c:1424: COMPAT_SYSCALL_DEFINE4(ptrace, compat_long_t, request, compat_long_t, pid, compat_long_t, addr, compat_long_t, data) */
  [__SNR_COMPAT_ptrace] = {
    .name  = "ptrace",
    .func  = ptrace,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:389: 522	x32	rt_sigpending		compat_sys_rt_sigpending */
/* ../../hyperodf/kernel/signal.c:3216: COMPAT_SYSCALL_DEFINE2(rt_sigpending, compat_sigset_t __user *, uset, compat_size_t, sigsetsize) */
  [__SNR_COMPAT_rt_sigpending] = {
    .name  = "rt_sigpending",
    .func  = rt_sigpending,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(compat_sigset_t ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:390: 523	x32	rt_sigtimedwait		compat_sys_rt_sigtimedwait_time64 */
/* ../../hyperodf/kernel/signal.c:3611: SYSCALL_DEFINE4(rt_sigtimedwait, const sigset_t __user *, uthese, siginfo_t __user *, uinfo, const struct __kernel_timespec __user *, uts, size_t, sigsetsize) */
  [__SNR_COMPAT_rt_sigtimedwait] = {
    .name  = "rt_sigtimedwait",
    .func  = rt_sigtimedwait,
    .nargs = 4,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(sigset_t ), sizeof(siginfo_t ), sizeof(struct __kernel_timespec ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:391: 524	x32	rt_sigqueueinfo		compat_sys_rt_sigqueueinfo */
/* ../../hyperodf/kernel/signal.c:3991: COMPAT_SYSCALL_DEFINE3(rt_sigqueueinfo, compat_pid_t, pid, int, sig, struct compat_siginfo __user *, uinfo) */
  [__SNR_COMPAT_rt_sigqueueinfo] = {
    .name  = "rt_sigqueueinfo",
    .func  = rt_sigqueueinfo,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:392: 525	x32	sigaltstack		compat_sys_sigaltstack */
/* ../../hyperodf/kernel/signal.c:4239: COMPAT_SYSCALL_DEFINE2(sigaltstack, const compat_stack_t __user *, uss_ptr, compat_stack_t __user *, uoss_ptr) */
  [__SNR_COMPAT_sigaltstack] = {
    .name  = "sigaltstack",
    .func  = sigaltstack,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(compat_stack_t ), sizeof(compat_stack_t ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:393: 526	x32	timer_create		compat_sys_timer_create */
/* ../../hyperodf/kernel/time/posix-timers.c:592: COMPAT_SYSCALL_DEFINE3(timer_create, clockid_t, which_clock, struct compat_sigevent __user *, timer_event_spec, timer_t __user *, created_timer_id) */
  [__SNR_COMPAT_timer_create] = {
    .name  = "timer_create",
    .func  = timer_create,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigevent ), sizeof(timer_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:394: 527	x32	mq_notify		compat_sys_mq_notify */
/* ../../hyperodf/ipc/mqueue.c:1564: COMPAT_SYSCALL_DEFINE2(mq_notify, mqd_t, mqdes, const struct compat_sigevent __user *, u_notification) */
  [__SNR_COMPAT_mq_notify] = {
    .name  = "mq_notify",
    .func  = mq_notify,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(struct compat_sigevent ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:395: 528	x32	kexec_load		compat_sys_kexec_load */
/* ../../hyperodf/kernel/kexec.c:257: COMPAT_SYSCALL_DEFINE4(kexec_load, compat_ulong_t, entry, compat_ulong_t, nr_segments, struct compat_kexec_segment __user *, segments, compat_ulong_t, flags) */
  [__SNR_COMPAT_kexec_load] = {
    .name  = "kexec_load",
    .func  = kexec_load,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_kexec_segment ), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:396: 529	x32	waitid			compat_sys_waitid */
/* ../../hyperodf/kernel/exit.c:1743: COMPAT_SYSCALL_DEFINE5(waitid, int, which, compat_pid_t, pid, struct compat_siginfo __user *, infop, int, options, struct compat_rusage __user *, uru) */
  [__SNR_COMPAT_waitid] = {
    .name  = "waitid",
    .func  = waitid,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), sizeof(int), sizeof(struct compat_rusage ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:397: 530	x32	set_robust_list		compat_sys_set_robust_list */
/* ../../hyperodf/kernel/futex.c:4115: COMPAT_SYSCALL_DEFINE2(set_robust_list, struct compat_robust_list_head __user *, head, compat_size_t, len) */
  [__SNR_COMPAT_set_robust_list] = {
    .name  = "set_robust_list",
    .func  = set_robust_list,
    .nargs = 2,
    .args  = {ARG_PTR, ARG_INT, -1, -1, -1, -1},
    .lens  = {sizeof(struct compat_robust_list_head ), sizeof(int), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:398: 531	x32	get_robust_list		compat_sys_get_robust_list */
/* ../../hyperodf/kernel/futex.c:4130: COMPAT_SYSCALL_DEFINE3(get_robust_list, int, pid, compat_uptr_t __user *, head_ptr, compat_size_t __user *, len_ptr) */
  [__SNR_COMPAT_get_robust_list] = {
    .name  = "get_robust_list",
    .func  = get_robust_list,
    .nargs = 3,
    .args  = {ARG_INT, ARG_PTR, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(compat_uptr_t ), sizeof(compat_size_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:399: 532	x32	vmsplice		sys_vmsplice */
/* ../../hyperodf/fs/splice.c:1296: SYSCALL_DEFINE4(vmsplice, int, fd, const struct iovec __user *, uiov, unsigned long, nr_segs, unsigned int, flags) */
  [__SNR_COMPAT_vmsplice] = {
    .name  = "vmsplice",
    .func  = vmsplice,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:400: 533	x32	move_pages		sys_move_pages */
/* ../../hyperodf/mm/migrate.c:2035: SYSCALL_DEFINE6(move_pages, pid_t, pid, unsigned long, nr_pages, const void __user * __user *, pages, const int __user *, nodes, int __user *, status, int, flags) */
  [__SNR_COMPAT_move_pages] = {
    .name  = "move_pages",
    .func  = move_pages,
    .nargs = 6,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, ARG_PTR, ARG_PTR, ARG_INT},
    .lens  = {sizeof(int), sizeof(int), sizeof(void *), sizeof(int ), sizeof(int ), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:401: 534	x32	preadv			compat_sys_preadv64 */
/* ../../hyperodf/fs/read_write.c:1106: COMPAT_SYSCALL_DEFINE5(preadv, compat_ulong_t, fd, const struct iovec __user *, vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high) */
  [__SNR_COMPAT_preadv] = {
    .name  = "preadv",
    .func  = preadv,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:402: 535	x32	pwritev			compat_sys_pwritev64 */
/* ../../hyperodf/fs/read_write.c:1147: COMPAT_SYSCALL_DEFINE5(pwritev, compat_ulong_t, fd, const struct iovec __user *,vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high) */
  [__SNR_COMPAT_pwritev] = {
    .name  = "pwritev",
    .func  = pwritev,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:403: 536	x32	rt_tgsigqueueinfo	compat_sys_rt_tgsigqueueinfo */
/* ../../hyperodf/kernel/signal.c:4031: COMPAT_SYSCALL_DEFINE4(rt_tgsigqueueinfo, compat_pid_t, tgid, compat_pid_t, pid, int, sig, struct compat_siginfo __user *, uinfo) */
  [__SNR_COMPAT_rt_tgsigqueueinfo] = {
    .name  = "rt_tgsigqueueinfo",
    .func  = rt_tgsigqueueinfo,
    .nargs = 4,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_PTR, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(struct compat_siginfo ), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:404: 537	x32	recvmmsg		compat_sys_recvmmsg_time64 */
/* ../../hyperodf/net/socket.c:2856: SYSCALL_DEFINE5(recvmmsg, int, fd, struct mmsghdr __user *, mmsg, unsigned int, vlen, unsigned int, flags, struct __kernel_timespec __user *, timeout) */
  [__SNR_COMPAT_recvmmsg] = {
    .name  = "recvmmsg",
    .func  = recvmmsg,
    .nargs = 5,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(struct mmsghdr ), sizeof(int), sizeof(int), sizeof(struct __kernel_timespec ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:405: 538	x32	sendmmsg		compat_sys_sendmmsg */
/* ../../hyperodf/net/socket.c:2572: SYSCALL_DEFINE4(sendmmsg, int, fd, struct mmsghdr __user *, mmsg, unsigned int, vlen, unsigned int, flags) */
  [__SNR_COMPAT_sendmmsg] = {
    .name  = "sendmmsg",
    .func  = sendmmsg,
    .nargs = 4,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, -1, -1},
    .lens  = {sizeof(int), sizeof(struct mmsghdr ), sizeof(int), sizeof(int), -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:406: 539	x32	process_vm_readv	sys_process_vm_readv */
/* ../../hyperodf/mm/process_vm_access.c:291: SYSCALL_DEFINE6(process_vm_readv, pid_t, pid, const struct iovec __user *, lvec, unsigned long, liovcnt, const struct iovec __user *, rvec, unsigned long, riovcnt,	unsigned long, flags) */
  [__SNR_COMPAT_process_vm_readv] = {
    .name  = "process_vm_readv",
    .func  = process_vm_readv,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:407: 540	x32	process_vm_writev	sys_process_vm_writev */
/* ../../hyperodf/mm/process_vm_access.c:298: SYSCALL_DEFINE6(process_vm_writev, pid_t, pid, const struct iovec __user *, lvec, unsigned long, liovcnt, const struct iovec __user *, rvec, unsigned long, riovcnt,	unsigned long, flags) */
  [__SNR_COMPAT_process_vm_writev] = {
    .name  = "process_vm_writev",
    .func  = process_vm_writev,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_PTR, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:408: 541	x32	setsockopt		sys_setsockopt */
/* ../../hyperodf/net/socket.c:2181: SYSCALL_DEFINE5(setsockopt, int, fd, int, level, int, optname, char __user *, optval, int, optlen) */
  [__SNR_COMPAT_setsockopt] = {
    .name  = "setsockopt",
    .func  = setsockopt,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_STR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(char *), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:409: 542	x32	getsockopt		sys_getsockopt */
/* ../../hyperodf/net/socket.c:2229: SYSCALL_DEFINE5(getsockopt, int, fd, int, level, int, optname, char __user *, optval, int __user *, optlen) */
  [__SNR_COMPAT_getsockopt] = {
    .name  = "getsockopt",
    .func  = getsockopt,
    .nargs = 5,
    .args  = {ARG_INT, ARG_INT, ARG_INT, ARG_STR, ARG_PTR, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(int), sizeof(char *), sizeof(int ), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:410: 543	x32	io_setup		compat_sys_io_setup */
/* ../../hyperodf/fs/aio.c:1342: COMPAT_SYSCALL_DEFINE2(io_setup, unsigned, nr_events, u32 __user *, ctx32p) */
  [__SNR_COMPAT_io_setup] = {
    .name  = "io_setup",
    .func  = io_setup,
    .nargs = 2,
    .args  = {ARG_INT, ARG_PTR, -1, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(u32 ), -1, -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:411: 544	x32	io_submit		compat_sys_io_submit */
/* ../../hyperodf/fs/aio.c:1951: COMPAT_SYSCALL_DEFINE3(io_submit, compat_aio_context_t, ctx_id, int, nr, compat_uptr_t __user *, iocbpp) */
  [__SNR_COMPAT_io_submit] = {
    .name  = "io_submit",
    .func  = io_submit,
    .nargs = 3,
    .args  = {ARG_INT, ARG_INT, ARG_PTR, -1, -1, -1},
    .lens  = {sizeof(int), sizeof(int), sizeof(compat_uptr_t ), -1, -1, -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:412: 545	x32	execveat		compat_sys_execveat */
/* ../../hyperodf/fs/exec.c:2088: COMPAT_SYSCALL_DEFINE5(execveat, int, fd, const char __user *, filename, const compat_uptr_t __user *, argv, const compat_uptr_t __user *, envp, int,  flags) */
  [__SNR_COMPAT_execveat] = {
    .name  = "execveat",
    .func  = execveat,
    .nargs = 5,
    .args  = {ARG_INT, ARG_STR, ARG_PTR, ARG_PTR, ARG_INT, -1},
    .lens  = {sizeof(int), sizeof(char *), sizeof(compat_uptr_t ), sizeof(compat_uptr_t ), sizeof(int), -1}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:413: 546	x32	preadv2			compat_sys_preadv64v2 */
/* ../../hyperodf/fs/read_write.c:1126: COMPAT_SYSCALL_DEFINE6(preadv2, compat_ulong_t, fd, const struct iovec __user *, vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high, rwf_t, flags) */
  [__SNR_COMPAT_preadv2] = {
    .name  = "preadv2",
    .func  = preadv2,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:414: 547	x32	pwritev2		compat_sys_pwritev64v2 */
/* ../../hyperodf/fs/read_write.c:1167: COMPAT_SYSCALL_DEFINE6(pwritev2, compat_ulong_t, fd, const struct iovec __user *,vec, compat_ulong_t, vlen, u32, pos_low, u32, pos_high, rwf_t, flags) */
  [__SNR_COMPAT_pwritev2] = {
    .name  = "pwritev2",
    .func  = pwritev2,
    .nargs = 6,
    .args  = {ARG_INT, ARG_PTR, ARG_INT, ARG_INT, ARG_INT, ARG_INT},
    .lens  = {sizeof(int), sizeof(struct iovec ), sizeof(int), sizeof(int), sizeof(int), sizeof(int)}},
/* ../../hyperodf/./arch/x86/entry/syscalls/syscall_64.tbl:417: 548	64	inform			sys_inform */
/* WARNING: Found no args for syscall "inform", using default (all pointers) */
  [__SNR_inform] = {
    .name  = "inform",
    .func  = inform,
    .nargs = 6,
    .args  = {ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR, ARG_PTR},
    .lens  = {sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void), sizeof(void)}},
};
