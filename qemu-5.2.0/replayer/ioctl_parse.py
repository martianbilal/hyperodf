#!/usr/bin/python3
import csv
import sys
from io import StringIO
import re



macro_ids = {
	'MFD_CLOEXEC' : 1,
	'SEEK_END' : 2,
	'SIGHUP' : 1,
	'IPPROTO_TCP' : 6,
	'SECCOMP_SET_MODE_FILTER' : 1,
	'O_NONBLOCK' : 2048,
	'MFD_ALLOW_SEALING' : 2,
	'O_WRONLY' : 1,
	'SEEK_SET' : 0,
	'F_GETFD' : 1,
	'SOCK_STREAM' : 1,
	'PR_MCE_KILL_EARLY' : 1,
	'ARCH_SET_FS' : 4098,
	'SIGTERM' : 15,
	'F_OFD_SETLK' : 37,
	'AF_NETLINK' : 16,
	'SIG_BLOCK' : 0,
	'O_RDONLY' : 0,
	'SIGQUIT' : 3,
	'PR_SET_TIMERSLACK' : 29,
	'SIGCONT' : 18,
	'F_SETFD' : 2,
	'O_CLOEXEC' : 524288,
	'SIG_UNBLOCK' : 1,
	'SIG_SETMASK' : 2,
	'SO_OOBINLINE' : 10,
	'FD_CLOEXEC' : 1,
	'SIGCHLD' : 17,
	'O_DIRECTORY' : 65536,
	'O_CREAT' : 64,
	'IPPROTO_IP' : 0,
	'SIGUSR1' : 10,
	'O_LARGEFILE' : 32768,
	'NETLINK_ROUTE' : 0,
	'F_SETFL' : 4,
	'O_RDWR' : 2,
	'RLIMIT_STACK' : 3,
	'MFD_HUGETLB' : 4,
	'AF_INET' : 2,
	'SOL_SOCKET' : 1,
	'SOL_TCP' : 6,
	'SOCK_NONBLOCK' : 2048,
	'SOCK_DGRAM' : 2,
	'F_SETLK' : 6,
	'SO_REUSEADDR' : 2,
	'SOCK_CLOEXEC' : 524288,
	'SIGPIPE' : 13,
	'SEEK_CUR' : 1,
	'TCP_NODELAY' : 1,
	'AF_UNIX' : 1,
	'IPV' : 0,
	'EFD_NONBLOCK' : 2048,
	'SOCK_RAW' : 3,
	'F_GETFL' : 3,
	'PR_MCE_KILL_SET' : 1,
	'SIGINT' : 2,
	'PR_MCE_KILL' : 33,
	'F_OFD_GETLK' : 36,
	'SECCOMP_FILTER_FLAG_TSYNC' : 1,
	'EFD_CLOEXEC' : 524288,
	'SOL_IPV6' : 41,
}



ioctl_ids = {
	'KVM_RUN' : 0xae80,
	'KVM_GET_API_VERSION' : 0xae00,
	'KVM_CREATE_VM' : 0xae01,
	'KVM_ENABLE_CAP' : 0x4068aea3,
	'KVM_GET_MSR_INDEX_LIST' : 0xc004ae02,
	'KVM_GET_MSR_FEATURE_INDEX_LIST' : 0xc004ae0a,
	'KVM_SET_IDENTITY_MAP_ADDR' : 0x4008ae48,
	'KVM_SET_TSS_ADDR' : 0xae47,
	'KVM_CREATE_IRQCHIP' : 0xae60,
	'KVM_IOEVENTFD' : 0x4040ae79,
	'KVM_GET_SUPPORTED_CPUID' : 0xc008ae05,
	'KVM_X86_GET_MCE_CAP_SUPPORTED' : 0x8008ae9d,
	'KVM_GET_MSRS' : 0xc008ae88,
	'KVM_CREATE_VCPU' : 0xae41,
	'KVM_GET_VCPU_MMAP_SIZE' : 0xae04,
	'KVM_GET_TSC_KHZ' : 0xaea3,
	'KVM_X86_SETUP_MCE' : 0x4008ae9c,
	'KVM_SET_CPUID2' : 0x4008ae90,
	'KVM_SET_MSRS' : 0x4008ae89,
	'KVM_GET_CLOCK' : 0x8030ae7c,
	'KVM_SET_USER_MEMORY_REGION' : 0x4020ae46,
	'KVM_SET_GSI_ROUTING' : 0x4008ae6a,
	'KVM_REGISTER_COALESCED_MMIO' : 0x4010ae67,
	'KVM_UNREGISTER_COALESCED_MMIO' : 0x4010ae68,
	'KVM_CREATE_PIT2' : 0x4040ae77,
	'KVM_SET_SREGS' : 0x4138ae84,
	'KVM_SET_TSC_KHZ' : 0xaea2,
	'KVM_SET_REGS' : 0x4090ae82,
	'KVM_SET_XSAVE' : 0x5000aea5,
	'KVM_SET_XCRS' : 0x4188aea7,
	'KVM_SET_VCPU_EVENTS' : 0x4040aea0,
	'KVM_SET_MP_STATE' : 0x4004ae99,
	'KVM_SET_DEBUGREGS' : 0x4080aea2,
	'KVM_GET_VCPU_EVENTS' : 0x8040ae9f,
	'KVM_GET_MP_STATE' : 0x8004ae98,
	'KVM_GET_REGS' : 0x8090ae81,
	'KVM_GET_XSAVE' : 0x9000aea4,
	'KVM_GET_XCRS' : 0x8188aea6,
	'KVM_GET_SREGS' : 0x8138ae83,
	'KVM_GET_LAPIC' : 0x8400ae8e,
	'KVM_GET_DEBUGREGS' : 0x8080aea1,
	'KVM_GET_PIT2' : 0x8070ae9f,
	'KVM_SET_PIT2' : 0x4070aea0,
	'KVM_SET_IRQCHIP' : 0x8208ae63,
	'KVM_TPR_ACCESS_REPORTING' : 0xc028ae92,
	'KVM_SET_VAPIC_ADDR' : 0x4008ae93,
	'KVM_SET_LAPIC' : 0x4400ae8f,
	'KVM_SET_CLOCK' : 0x4030ae7b,
	'KVM_KVMCLOCK_CTRL' : 0xaead,
	'KVM_SMI' : 0xaeb7,
	'KVM_GET_DIRTY_LOG' : 0x4010ae42,
}

syscall_ids = {
	'read' : 0,
	'write' : 1,
	'open' : 2,
	'close' : 3,
	'stat' : 4,
	'fstat' : 5,
	'lstat' : 6,
	'poll' : 7,
	'lseek' : 8,
	'mmap' : 9,
	'mprotect' : 10,
	'munmap' : 11,
	'brk' : 12,
	'rt_sigaction' : 13,
	'rt_sigprocmask' : 14,
	'rt_sigreturn' : 15,
	'ioctl' : 16,
	'pread64' : 17,
	'pwrite64' : 18,
	'readv' : 19,
	'writev' : 20,
	'access' : 21,
	'pipe' : 22,
	'select' : 23,
	'sched_yield' : 24,
	'mremap' : 25,
	'msync' : 26,
	'mincore' : 27,
	'madvise' : 28,
	'shmget' : 29,
	'shmat' : 30,
	'shmctl' : 31,
	'dup' : 32,
	'dup2' : 33,
	'pause' : 34,
	'nanosleep' : 35,
	'getitimer' : 36,
	'alarm' : 37,
	'setitimer' : 38,
	'getpid' : 39,
	'sendfile' : 40,
	'socket' : 41,
	'connect' : 42,
	'accept' : 43,
	'sendto' : 44,
	'recvfrom' : 45,
	'sendmsg' : 46,
	'recvmsg' : 47,
	'shutdown' : 48,
	'bind' : 49,
	'listen' : 50,
	'getsockname' : 51,
	'getpeername' : 52,
	'socketpair' : 53,
	'setsockopt' : 54,
	'getsockopt' : 55,
	'clone' : 56,
	'fork' : 57,
	'vfork' : 58,
	'execve' : 59,
	'exit' : 60,
	'wait4' : 61,
	'kill' : 62,
	'uname' : 63,
	'semget' : 64,
	'semop' : 65,
	'semctl' : 66,
	'shmdt' : 67,
	'msgget' : 68,
	'msgsnd' : 69,
	'msgrcv' : 70,
	'msgctl' : 71,
	'fcntl' : 72,
	'flock' : 73,
	'fsync' : 74,
	'fdatasync' : 75,
	'truncate' : 76,
	'ftruncate' : 77,
	'getdents' : 78,
	'getcwd' : 79,
	'chdir' : 80,
	'fchdir' : 81,
	'rename' : 82,
	'mkdir' : 83,
	'rmdir' : 84,
	'creat' : 85,
	'link' : 86,
	'unlink' : 87,
	'symlink' : 88,
	'readlink' : 89,
	'chmod' : 90,
	'fchmod' : 91,
	'chown' : 92,
	'fchown' : 93,
	'lchown' : 94,
	'umask' : 95,
	'gettimeofday' : 96,
	'getrlimit' : 97,
	'getrusage' : 98,
	'sysinfo' : 99,
	'times' : 100,
	'ptrace' : 101,
	'getuid' : 102,
	'syslog' : 103,
	'getgid' : 104,
	'setuid' : 105,
	'setgid' : 106,
	'geteuid' : 107,
	'getegid' : 108,
	'setpgid' : 109,
	'getppid' : 110,
	'getpgrp' : 111,
	'setsid' : 112,
	'setreuid' : 113,
	'setregid' : 114,
	'getgroups' : 115,
	'setgroups' : 116,
	'setresuid' : 117,
	'getresuid' : 118,
	'setresgid' : 119,
	'getresgid' : 120,
	'getpgid' : 121,
	'setfsuid' : 122,
	'setfsgid' : 123,
	'getsid' : 124,
	'capget' : 125,
	'capset' : 126,
	'rt_sigpending' : 127,
	'rt_sigtimedwait' : 128,
	'rt_sigqueueinfo' : 129,
	'rt_sigsuspend' : 130,
	'sigaltstack' : 131,
	'utime' : 132,
	'mknod' : 133,
	'uselib' : 134,
	'personality' : 135,
	'ustat' : 136,
	'statfs' : 137,
	'fstatfs' : 138,
	'sysfs' : 139,
	'getpriority' : 140,
	'setpriority' : 141,
	'sched_setparam' : 142,
	'sched_getparam' : 143,
	'sched_setscheduler' : 144,
	'sched_getscheduler' : 145,
	'sched_get_priority_max' : 146,
	'sched_get_priority_min' : 147,
	'sched_rr_get_interval' : 148,
	'mlock' : 149,
	'munlock' : 150,
	'mlockall' : 151,
	'munlockall' : 152,
	'vhangup' : 153,
	'modify_ldt' : 154,
	'pivot_root' : 155,
	'_sysctl' : 156,
	'prctl' : 157,
	'arch_prctl' : 158,
	'adjtimex' : 159,
	'setrlimit' : 160,
	'chroot' : 161,
	'sync' : 162,
	'acct' : 163,
	'settimeofday' : 164,
	'mount' : 165,
	'umount2' : 166,
	'swapon' : 167,
	'swapoff' : 168,
	'reboot' : 169,
	'sethostname' : 170,
	'setdomainname' : 171,
	'iopl' : 172,
	'ioperm' : 173,
	'create_module' : 174,
	'init_module' : 175,
	'delete_module' : 176,
	'get_kernel_syms' : 177,
	'query_module' : 178,
	'quotactl' : 179,
	'nfsservctl' : 180,
	'getpmsg' : 181,
	'putpmsg' : 182,
	'afs_syscall' : 183,
	'tuxcall' : 184,
	'security' : 185,
	'gettid' : 186,
	'readahead' : 187,
	'setxattr' : 188,
	'lsetxattr' : 189,
	'fsetxattr' : 190,
	'getxattr' : 191,
	'lgetxattr' : 192,
	'fgetxattr' : 193,
	'listxattr' : 194,
	'llistxattr' : 195,
	'flistxattr' : 196,
	'removexattr' : 197,
	'lremovexattr' : 198,
	'fremovexattr' : 199,
	'tkill' : 200,
	'time' : 201,
	'futex' : 202,
	'sched_setaffinity' : 203,
	'sched_getaffinity' : 204,
	'set_thread_area' : 205,
	'io_setup' : 206,
	'io_destroy' : 207,
	'io_getevents' : 208,
	'io_submit' : 209,
	'io_cancel' : 210,
	'get_thread_area' : 211,
	'lookup_dcookie' : 212,
	'epoll_create' : 213,
	'epoll_ctl_old' : 214,
	'epoll_wait_old' : 215,
	'remap_file_pages' : 216,
	'getdents64' : 217,
	'set_tid_address' : 218,
	'restart_syscall' : 219,
	'semtimedop' : 220,
	'fadvise64' : 221,
	'timer_create' : 222,
	'timer_settime' : 223,
	'timer_gettime' : 224,
	'timer_getoverrun' : 225,
	'timer_delete' : 226,
	'clock_settime' : 227,
	'clock_gettime' : 228,
	'clock_getres' : 229,
	'clock_nanosleep' : 230,
	'exit_group' : 231,
	'epoll_wait' : 232,
	'epoll_ctl' : 233,
	'tgkill' : 234,
	'utimes' : 235,
	'vserver' : 236,
	'mbind' : 237,
	'set_mempolicy' : 238,
	'get_mempolicy' : 239,
	'mq_open' : 240,
	'mq_unlink' : 241,
	'mq_timedsend' : 242,
	'mq_timedreceive' : 243,
	'mq_notify' : 244,
	'mq_getsetattr' : 245,
	'kexec_load' : 246,
	'waitid' : 247,
	'add_key' : 248,
	'request_key' : 249,
	'keyctl' : 250,
	'ioprio_set' : 251,
	'ioprio_get' : 252,
	'inotify_init' : 253,
	'inotify_add_watch' : 254,
	'inotify_rm_watch' : 255,
	'migrate_pages' : 256,
	'openat' : 257,
	'mkdirat' : 258,
	'mknodat' : 259,
	'fchownat' : 260,
	'futimesat' : 261,
	'newfstatat' : 262,
	'unlinkat' : 263,
	'renameat' : 264,
	'linkat' : 265,
	'symlinkat' : 266,
	'readlinkat' : 267,
	'fchmodat' : 268,
	'faccessat' : 269,
	'pselect6' : 270,
	'ppoll' : 271,
	'unshare' : 272,
	'set_robust_list' : 273,
	'get_robust_list' : 274,
	'splice' : 275,
	'tee' : 276,
	'sync_file_range' : 277,
	'vmsplice' : 278,
	'move_pages' : 279,
	'utimensat' : 280,
	'epoll_pwait' : 281,
	'signalfd' : 282,
	'timerfd_create' : 283,
	'eventfd' : 284,
	'fallocate' : 285,
	'timerfd_settime' : 286,
	'timerfd_gettime' : 287,
	'accept4' : 288,
	'signalfd4' : 289,
	'eventfd2' : 290,
	'epoll_create1' : 291,
	'dup3' : 292,
	'pipe2' : 293,
	'inotify_init1' : 294,
	'preadv' : 295,
	'pwritev' : 296,
	'rt_tgsigqueueinfo' : 297,
	'perf_event_open' : 298,
	'recvmmsg' : 299,
	'fanotify_init' : 300,
	'fanotify_mark' : 301,
	'prlimit64' : 302,
	'name_to_handle_at' : 303,
	'open_by_handle_at' : 304,
	'clock_adjtime' : 305,
	'syncfs' : 306,
	'sendmmsg' : 307,
	'setns' : 308,
	'getcpu' : 309,
	'process_vm_readv' : 310,
	'process_vm_writev' : 311,
	'kcmp' : 312,
	'finit_module' : 313,
	'sched_setattr' : 314,
	'sched_getattr' : 315,
	'renameat2' : 316,
	'seccomp' : 317,
	'getrandom' : 318,
	'memfd_create' : 319,
	'kexec_file_load' : 320,
	'bpf' : 321,
	'execveat' : 322,
	'userfaultfd' : 323,
	'membarrier' : 324,
	'mlock2' : 325,
	'copy_file_range' : 326,
	'preadv2' : 327,
	'pwritev2' : 328,
	'pkey_mprotect' : 329,
	'pkey_alloc' : 330,
	'pkey_free' : 331,
	'statx' : 332,
	'io_pgetevents' : 333,
	'rseq' : 334,
	'pidfd_send_signal' : 424,
	'io_uring_setup' : 425,
	'io_uring_enter' : 426,
	'io_uring_register' : 427,
	'open_tree' : 428,
	'move_mount' : 429,
	'fsopen' : 430,
	'fsconfig' : 431,
	'fsmount' : 432,
	'fspick' : 433,
	'pidfd_open' : 434,
	'clone3' : 435,
	'close_range' : 436,
	'openat2' : 437,
	'pidfd_getfd' : 438,
	'faccessat2' : 439,
	'process_madvise' : 440,
	'epoll_pwait2' : 441,
	'mount_setattr' : 442,
	'quotactl_fd' : 443,
	'landlock_create_ruleset' : 444,
	'landlock_add_rule' : 445,
	'landlock_restrict_self' : 446,
	'memfd_secret' : 447,
	'process_mrelease' : 448,
	'COMPAT_rt_sigaction' : 512,
	'COMPAT_rt_sigreturn' : 513,
	'COMPAT_ioctl' : 514,
	'COMPAT_readv' : 515,
	'COMPAT_writev' : 516,
	'COMPAT_recvfrom' : 517,
	'COMPAT_sendmsg' : 518,
	'COMPAT_recvmsg' : 519,
	'COMPAT_execve' : 520,
	'COMPAT_ptrace' : 521,
	'COMPAT_rt_sigpending' : 522,
	'COMPAT_rt_sigtimedwait' : 523,
	'COMPAT_rt_sigqueueinfo' : 524,
	'COMPAT_sigaltstack' : 525,
	'COMPAT_timer_create' : 526,
	'COMPAT_mq_notify' : 527,
	'COMPAT_kexec_load' : 528,
	'COMPAT_waitid' : 529,
	'COMPAT_set_robust_list' : 530,
	'COMPAT_get_robust_list' : 531,
	'COMPAT_vmsplice' : 532,
	'COMPAT_move_pages' : 533,
	'COMPAT_preadv' : 534,
	'COMPAT_pwritev' : 535,
	'COMPAT_rt_tgsigqueueinfo' : 536,
	'COMPAT_recvmmsg' : 537,
	'COMPAT_sendmmsg' : 538,
	'COMPAT_process_vm_readv' : 539,
	'COMPAT_process_vm_writev' : 540,
	'COMPAT_setsockopt' : 541,
	'COMPAT_getsockopt' : 542,
	'COMPAT_io_setup' : 543,
	'COMPAT_io_submit' : 544,
	'COMPAT_execveat' : 545,
	'COMPAT_preadv2' : 546,
	'COMPAT_pwritev2' : 547,
	'inform' : 548,
}


# All the place where you might need
# to change the addresses manually are 
# marked by CHANGE


#CHANGE here
helloworlddir = "/root/kvm-samples/qemu-5.2.0"
replayerdir = helloworlddir + "/replayer"


#
#   IDs for the syscalls 
#
#   0 => ioctl
#   1 => open
#   2 => close
#   3 => fstats
#   4 => arch_prctls
#


#
#
#   Arrangement of the output csv file
#   1st row => [number of syscalls, types/ids of syscalls.....]
#   2nd row => 1st syscall
#   3rd row => 2nd syscall
#   ..... so on .. until .. num of syscall + 1
#
#
#
#

syscall_types = [] #ids based on the above comment
syscalls = []
ioctls = []
opens = []
closes = []
fstats = []
arch_prctls = []


comma_sep_syscalls = []
comma_sep_ioctls = []
comma_sep_opens = []

# def parse_add_open():
#     print("==== open list ===== ")
#     comma_sep_open = []
#     for opn in opens:
#         opn = opn.split("(")[1]
#         res = opn.split("= ")[1].strip("\n")
#         opn = opn.split(")")[0]
#         opn = opn.split(",")
#         opn[1] = opn[1][1:]
#         print(opn)
#         comma_sep_open.append(opn[0])
#         comma_sep_open.append(str(opn[1]))
#         comma_sep_open.append(int(res, 16))
#         # comma_sep_opens.append(comma_sep_open)
#         comma_sep_syscalls.append(comma_sep_open)
#         comma_sep_open = []

#     print("==== open list ===== ")

def __parse_add_open(opn):
    comma_sep_open = []
    opn = opn.split("(")[1]
    res = opn.split("= ")[1].strip("\n")
    opn = opn.split(")")[0]
    opn = opn.split(",")
    opn[1] = opn[1][1:]
    print(opn)
    # first arg maybe the name of the device
    # [Bilal] [TODO] find why does it print 
    # out with three inverted commas on both
    # sides
    
    ## [TODO] [DONE] 
    ## new code was added instead of following code 
    # comma_sep_open.append(opn[0]) 
    comma_sep_open.append(opn[0][1:-1]) 
    comma_sep_open.append(str(opn[1]))
    comma_sep_open.append(int(res, 16))
    # comma_sep_opens.append(comma_sep_open)
    comma_sep_syscalls.append(comma_sep_open)
    syscall_types.append(1)

def parse_add_close():
    print("==== close list ===== ")
    print(closes)


def parse_add_fstat():
    print("==== fstat list ===== ")
    print(fstats)

def parse_add_arch_prctls():
    print("==== arch prctl list ===== ")
    print(arch_prctls)


def __parse_add_ioctl(ioctl):
    print(ioctl)
    if "unfinished" in ioctl or "resumed" in ioctl: 
        return
    comma_sep_ioctl = []
    ioctl = ioctl.split("(")[1]
    res = ioctl.split("= ")[1].strip("\n")
    ioctl = ioctl.split(")")[0]
    ioctl = ioctl.split(",")
    ioctl[1] = ioctl[1][1:]
    ioctl[2] = ioctl[2][1:]
    
    # [TODO] [Urgent] add code for specially handling the cases
    # where last arg is string 
    comma_sep_ioctl.append(int(ioctl[0], 10))
        
    comma_sep_ioctl.append(str(ioctl[1]))
    if len(ioctl) == 3:
        try:
            comma_sep_ioctl.append(int(ioctl[2], 16))
        except: 
            # [Debugging]
            comma_sep_ioctl.append(-1)
            # comma_sep_ioctl.append(str(ioctl[2]))
    else:
        comma_sep_ioctl.append(-1)
        
    if len(res) == 1: 
        comma_sep_ioctl.append(int(res, 16))
    else: 
        comma_sep_ioctl.append(int(res.split()[0], 16))
    comma_sep_ioctls.append(comma_sep_ioctl)
    comma_sep_syscalls.append(comma_sep_ioctl)
    syscall_types.append(0)


def parse_add_syscall():
    for id_entry, syscall in syscalls:
        if id_entry == 0:
            # IOCTL
            __parse_add_ioctl(syscall)


        elif id_entry == 1:
            # OPEN
            __parse_add_open(syscall)

        

def parse_strace(in_file: str):
    with open(in_file, "r") as __syscalls:
        for syscall in __syscalls:
            # print(f"syscall : {syscall}")
            if "ioctl" in syscall:
                syscalls.append((0, syscall))

            if "open" in syscall:
                syscalls.append((1, syscall))
                # opens.append(syscall)
            
            if "close" in syscall:
                syscalls.append((2, syscall))
            
            if "fstat" in syscall:
                syscalls.append((3, syscall))
            
            if "arch_prctl" in syscall:
                syscalls.append((4, syscall))

            # write code for adding 
            # "necessary" syscalls into
            # their corresponding lists 
            # [TODO] check the systemcalls
            #   not handled by fork and used
            #   by QEMU

    # add a function call for adding all the 
    # ioctls in the comma_sep_ioctl        
    parse_add_syscall();
    # parse_add_ioctl();
    # Add similar functions for rest of the system calls
    # parse_add_open();
    # parse_add_close();
    # parse_add_fstat();
    # parse_add_arch_prctls();

def dump_to_csv(out_file: str):
    # print(comma_sep_syscalls)
    print("[Replayer] starting dumping to csv")
    with open(out_file, "w+") as csv_file:
        csv_file.write(str(len(comma_sep_syscalls)))
        # write the syscall_types list to the opened file
        for i in syscall_types:
            csv_file.write("," + str(i))
        csv_file.write("\n")
        writer = csv.writer(csv_file)
        # writer.writerows(comma_sep_ioctls)
        writer.writerows(comma_sep_syscalls)

def print_usage():
    print("ioctl_parse.py - helper python script for replayer module")
    print("parse an ioctl trace generated by strace and outputs csv ")
    print("separating the arguments to the ioctl.")
    print("\nUsage:\t ioctl_parse.py [input_file_address] [output_file_address]\n\n")

    return


csv_dump = []

filters = ['write', 'futex', 'KVM_RUN', 'IRQ_LINE_STATUS', 'brk', 'madvise', 'munmap', 'mmap', 'access', 'fstat', 'resumed', 'munmap', 'sleep', 'poll', '.so.', 'mprotect', 'ENOENT', 'read', 'KVM_CHECK_EXTENSION', '---', '+++']
filters = filters + ['detached', 'clone', 'getpid', 'SIGBUS', 'TCGETS', 'TCSETS', 'KVM_SET_NESTED_STATE', 'KVM_GET_NESTED_STATE', 'sysinfo', 'stat', 'uname']
filters = filters + ['unfinished', 'gettid', 'SIGRTMIN']
def parse_strace_new(in_file: str):
    r = re.compile(r'(?:[^,{]|\{[^}]*\})+')
    with open(in_file, "r") as __syscalls:
        for syscall in __syscalls:
            skip = False
            
            for f in filters:
                if f in syscall:
                    skip = True
                    break
                    
            if skip == True:
                continue
            
            syscall_name = syscall.split("(")[0].split(" ")
            
            if len(syscall_name) == 2:
                syscall_name = syscall_name[1]
            elif len(syscall_name) == 1:
                syscall_name[0]
            else:
                print("FAILURE : unknown syscall name format")
                exit(1)
            
            
            print(syscall)
            # remove pid
            syscall_args = syscall.split("(", 1)[1]
            syscall_args = syscall_args.rsplit("=", 1)[0].rsplit(")", 1)[0]
            # syscall_args = re.rsplit(r"\) ", syscall_args)[0]
            # syscall_args = re.split(r"\).*=", syscall_args)[0]
            syscall_args = syscall_args.strip()
            # print(syscall_args)
            
	
            syscall_args = re.sub(r", \[.*\]", ", stub_arr", syscall_args)
            syscall_args = re.sub(r", {.*}", ", stub", syscall_args)
            for macro_name in macro_ids.keys(): 
                if macro_name in syscall_args:
                    print(macro_name)
                    syscall_args = syscall_args.replace(macro_name, str(macro_ids[macro_name]))
                    # syscall_args = re.sub(f"{macro_name}", macro_ids[macro_name], syscall_args)
			
            syscall_args = syscall_args.split(",")
            print(syscall_args)
            			
            for i in range(len(syscall_args)):
                syscall_args[i] = syscall_args[i].strip()
                
            # get numerical ioctl ID 
            if 'ioctl' in syscall:
                syscall_args[1] = ioctl_ids[syscall_args[1]]

            
            # print(syscall_ids[syscall_name], syscall_args)
            csv_row = [syscall_ids[syscall_name]]
            for i in range(len(syscall_args)):
                try:    
                    csv_row.append(int(syscall_args[i], 10))
                except:
                    try:
                        csv_row.append(int(syscall_args[i], 16))
                    except:
                        csv_row.append(syscall_args[i])
            
            # fill upto 6 args
            jargon_len = 6 - len(csv_row)
            for i in range(jargon_len):
                csv_row.append(-1)
            
            # add result
            # print(syscall.split("= ")[1].rsplit(" ")[0].strip())
            try:
                csv_row.append(int(syscall.split("= ")[1].rsplit(" ")[0].strip(), 10))
            except:
                try:
                    csv_row.append(int(syscall.split("= ")[1].rsplit(" ")[0].strip(), 16))
                except:
                    csv_row.append(syscall.split("= ")[1].rsplit(" ")[0].strip())
                    
            csv_dump.append(csv_row)
   
def dump_to_csv_new(out_file: str):
    # print(comma_sep_syscalls)
    print("[Replayer] [new] starting dumping to csv")
    with open(out_file, "w+") as csv_file:
        csv_file.write(str(len(csv_dump)))
        # write the syscall_types list to the opened file
        # for i in syscall_types:
        #     csv_file.write("," + str(i))
        csv_file.write("\n")
        writer = csv.writer(csv_file)
        # writer.writerows(comma_sep_ioctls)
        writer.writerows(csv_dump)         

def main():
    #CHANGE here 
    in_file =  "qemu.log"
    out_file = "qemu.csv"

    if len(sys.argv) < 3:
        print_usage();
        exit()
    
    
    
    print("[Replayer] Helper script for parsing")
    in_file = sys.argv[1]
    out_file = sys.argv[2]
    # print(f"in_file : {in_file}");
    # print(f"out_file : {out_file}");
    
    
    print("[Replayer] Parsing trace file")
    # parse_strace(in_file)
    parse_strace_new(in_file)
    print("[Replayer] Parsed trace file")
    
    # with open(out_file, 'w+') as dump_file:
    #     for row in csv_dump:
    #         print(row, file=dump_file)
    # parse_verbose_strace(in_file)
    print("[Replayer] Dumping results to CSV file")
    dump_to_csv_new(out_file)
    print("[Replayer] Done!!")



if __name__=='__main__':
    main()