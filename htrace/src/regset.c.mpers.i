typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
typedef signed long int __int64_t;
typedef unsigned long int __uint64_t;
typedef long int __quad_t;
typedef unsigned long int __u_quad_t;
typedef long int __intmax_t;
typedef unsigned long int __uintmax_t;
typedef unsigned long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long int __nlink_t;
typedef long int __off_t;
typedef long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void * __timer_t;
typedef long int __blksize_t;
typedef long int __blkcnt_t;
typedef long int __blkcnt64_t;
typedef unsigned long int __fsblkcnt_t;
typedef unsigned long int __fsblkcnt64_t;
typedef unsigned long int __fsfilcnt_t;
typedef unsigned long int __fsfilcnt64_t;
typedef long int __fsword_t;
typedef long int __ssize_t;
typedef long int __syscall_slong_t;
typedef unsigned long int __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef char *__caddr_t;
typedef long int __intptr_t;
typedef unsigned int __socklen_t;
typedef int __sig_atomic_t;
typedef __int8_t int8_t;
typedef __int16_t int16_t;
typedef __int32_t int32_t;
typedef __int64_t int64_t;
typedef __uint8_t uint8_t;
typedef __uint16_t uint16_t;
typedef __uint32_t uint32_t;
typedef __uint64_t uint64_t;
typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;
typedef long int int_least64_t;
typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;
typedef unsigned long int uint_least64_t;
typedef signed char int_fast8_t;
typedef long int int_fast16_t;
typedef long int int_fast32_t;
typedef long int int_fast64_t;
typedef unsigned char uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long int uint_fast64_t;
typedef long int intptr_t;
typedef unsigned long int uintptr_t;
typedef __intmax_t intmax_t;
typedef __uintmax_t uintmax_t;
typedef int __gwchar_t;

typedef struct
  {
    long int quot;
    long int rem;
  } imaxdiv_t;
extern intmax_t imaxabs (intmax_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern imaxdiv_t imaxdiv (intmax_t __numer, intmax_t __denom)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern intmax_t strtoimax (const char *__restrict __nptr,
      char **__restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t strtoumax (const char *__restrict __nptr,
       char ** __restrict __endptr, int __base) __attribute__ ((__nothrow__ , __leaf__));
extern intmax_t wcstoimax (const __gwchar_t *__restrict __nptr,
      __gwchar_t **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));
extern uintmax_t wcstoumax (const __gwchar_t *__restrict __nptr,
       __gwchar_t ** __restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__));


typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off_t off_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __time_t time_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef long unsigned int size_t;
typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));
typedef int register_t __attribute__ ((__mode__ (__word__)));
static __inline unsigned int
__bswap_32 (unsigned int __bsx)
{
  return __builtin_bswap32 (__bsx);
}
static __inline __uint64_t
__bswap_64 (__uint64_t __bsx)
{
  return __builtin_bswap64 (__bsx);
}
static __inline __uint16_t
__uint16_identity (__uint16_t __x)
{
  return __x;
}
static __inline __uint32_t
__uint32_identity (__uint32_t __x)
{
  return __x;
}
static __inline __uint64_t
__uint64_identity (__uint64_t __x)
{
  return __x;
}
typedef struct
{
  unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
} __sigset_t;
typedef __sigset_t sigset_t;
struct timeval
{
  __time_t tv_sec;
  __suseconds_t tv_usec;
};
struct timespec
{
  __time_t tv_sec;
  __syscall_slong_t tv_nsec;
};
typedef long int __fd_mask;
typedef struct
  {
    __fd_mask fds_bits[1024 / (8 * (int) sizeof (__fd_mask))];
  } fd_set;
typedef __fd_mask fd_mask;

extern int select (int __nfds, fd_set *__restrict __readfds,
     fd_set *__restrict __writefds,
     fd_set *__restrict __exceptfds,
     struct timeval *__restrict __timeout);
extern int pselect (int __nfds, fd_set *__restrict __readfds,
      fd_set *__restrict __writefds,
      fd_set *__restrict __exceptfds,
      const struct timespec *__restrict __timeout,
      const __sigset_t *__restrict __sigmask);


extern unsigned int gnu_dev_major (__dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern unsigned int gnu_dev_minor (__dev_t __dev) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern __dev_t gnu_dev_makedev (unsigned int __major, unsigned int __minor) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));

typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
struct __pthread_rwlock_arch_t
{
  unsigned int __readers;
  unsigned int __writers;
  unsigned int __wrphase_futex;
  unsigned int __writers_futex;
  unsigned int __pad3;
  unsigned int __pad4;
  int __cur_writer;
  int __shared;
  signed char __rwelision;
  unsigned char __pad1[7];
  unsigned long int __pad2;
  unsigned int __flags;
};
typedef struct __pthread_internal_list
{
  struct __pthread_internal_list *__prev;
  struct __pthread_internal_list *__next;
} __pthread_list_t;
struct __pthread_mutex_s
{
  int __lock ;
  unsigned int __count;
  int __owner;
  unsigned int __nusers;
  int __kind;
 
  short __spins; short __elision;
  __pthread_list_t __list;
 
};
struct __pthread_cond_s
{
  __extension__ union
  {
    __extension__ unsigned long long int __wseq;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __wseq32;
  };
  __extension__ union
  {
    __extension__ unsigned long long int __g1_start;
    struct
    {
      unsigned int __low;
      unsigned int __high;
    } __g1_start32;
  };
  unsigned int __g_refs[2] ;
  unsigned int __g_size[2];
  unsigned int __g1_orig_size;
  unsigned int __wrefs;
  unsigned int __g_signals[2];
};
typedef unsigned long int pthread_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_mutexattr_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
union pthread_attr_t
{
  char __size[56];
  long int __align;
};
typedef union pthread_attr_t pthread_attr_t;
typedef union
{
  struct __pthread_mutex_s __data;
  char __size[40];
  long int __align;
} pthread_mutex_t;
typedef union
{
  struct __pthread_cond_s __data;
  char __size[48];
  __extension__ long long int __align;
} pthread_cond_t;
typedef union
{
  struct __pthread_rwlock_arch_t __data;
  char __size[56];
  long int __align;
} pthread_rwlock_t;
typedef union
{
  char __size[8];
  long int __align;
} pthread_rwlockattr_t;
typedef volatile int pthread_spinlock_t;
typedef union
{
  char __size[32];
  long int __align;
} pthread_barrier_t;
typedef union
{
  char __size[4];
  int __align;
} pthread_barrierattr_t;

typedef long int ptrdiff_t;
typedef int wchar_t;
typedef struct {
  long long __max_align_ll __attribute__((__aligned__(__alignof__(long long))));
  long double __max_align_ld __attribute__((__aligned__(__alignof__(long double))));
} max_align_t;

typedef __socklen_t socklen_t;
extern int access (const char *__name, int __type) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int euidaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int eaccess (const char *__name, int __type)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int faccessat (int __fd, const char *__file, int __type, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern __off_t lseek (int __fd, __off_t __offset, int __whence) __attribute__ ((__nothrow__ , __leaf__));
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence)
     __attribute__ ((__nothrow__ , __leaf__));
extern int close (int __fd);
extern ssize_t read (int __fd, void *__buf, size_t __nbytes) ;
extern ssize_t write (int __fd, const void *__buf, size_t __n) ;
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
        __off_t __offset) ;
extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
         __off_t __offset) ;
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
   __off64_t __offset) ;
extern ssize_t pwrite64 (int __fd, const void *__buf, size_t __n,
    __off64_t __offset) ;
extern int pipe (int __pipedes[2]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int pipe2 (int __pipedes[2], int __flags) __attribute__ ((__nothrow__ , __leaf__)) ;
extern unsigned int alarm (unsigned int __seconds) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned int sleep (unsigned int __seconds);
extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     __attribute__ ((__nothrow__ , __leaf__));
extern int usleep (__useconds_t __useconds);
extern int pause (void);
extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchown (int __fd, __uid_t __owner, __gid_t __group) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchownat (int __fd, const char *__file, __uid_t __owner,
       __gid_t __group, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int chdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int fchdir (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *getcwd (char *__buf, size_t __size) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *get_current_dir_name (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *getwd (char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) __attribute__ ((__deprecated__)) ;
extern int dup (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int dup2 (int __fd, int __fd2) __attribute__ ((__nothrow__ , __leaf__));
extern int dup3 (int __fd, int __fd2, int __flags) __attribute__ ((__nothrow__ , __leaf__));
extern char **__environ;
extern char **environ;
extern int execve (const char *__path, char *const __argv[],
     char *const __envp[]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int execv (const char *__path, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execle (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execl (const char *__path, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvp (const char *__file, char *const __argv[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execlp (const char *__file, const char *__arg, ...)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int execvpe (const char *__file, char *const __argv[],
      char *const __envp[])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nice (int __inc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void _exit (int __status) __attribute__ ((__noreturn__));
enum
  {
    _PC_LINK_MAX,
    _PC_MAX_CANON,
    _PC_MAX_INPUT,
    _PC_NAME_MAX,
    _PC_PATH_MAX,
    _PC_PIPE_BUF,
    _PC_CHOWN_RESTRICTED,
    _PC_NO_TRUNC,
    _PC_VDISABLE,
    _PC_SYNC_IO,
    _PC_ASYNC_IO,
    _PC_PRIO_IO,
    _PC_SOCK_MAXBUF,
    _PC_FILESIZEBITS,
    _PC_REC_INCR_XFER_SIZE,
    _PC_REC_MAX_XFER_SIZE,
    _PC_REC_MIN_XFER_SIZE,
    _PC_REC_XFER_ALIGN,
    _PC_ALLOC_SIZE_MIN,
    _PC_SYMLINK_MAX,
    _PC_2_SYMLINKS
  };
enum
  {
    _SC_ARG_MAX,
    _SC_CHILD_MAX,
    _SC_CLK_TCK,
    _SC_NGROUPS_MAX,
    _SC_OPEN_MAX,
    _SC_STREAM_MAX,
    _SC_TZNAME_MAX,
    _SC_JOB_CONTROL,
    _SC_SAVED_IDS,
    _SC_REALTIME_SIGNALS,
    _SC_PRIORITY_SCHEDULING,
    _SC_TIMERS,
    _SC_ASYNCHRONOUS_IO,
    _SC_PRIORITIZED_IO,
    _SC_SYNCHRONIZED_IO,
    _SC_FSYNC,
    _SC_MAPPED_FILES,
    _SC_MEMLOCK,
    _SC_MEMLOCK_RANGE,
    _SC_MEMORY_PROTECTION,
    _SC_MESSAGE_PASSING,
    _SC_SEMAPHORES,
    _SC_SHARED_MEMORY_OBJECTS,
    _SC_AIO_LISTIO_MAX,
    _SC_AIO_MAX,
    _SC_AIO_PRIO_DELTA_MAX,
    _SC_DELAYTIMER_MAX,
    _SC_MQ_OPEN_MAX,
    _SC_MQ_PRIO_MAX,
    _SC_VERSION,
    _SC_PAGESIZE,
    _SC_RTSIG_MAX,
    _SC_SEM_NSEMS_MAX,
    _SC_SEM_VALUE_MAX,
    _SC_SIGQUEUE_MAX,
    _SC_TIMER_MAX,
    _SC_BC_BASE_MAX,
    _SC_BC_DIM_MAX,
    _SC_BC_SCALE_MAX,
    _SC_BC_STRING_MAX,
    _SC_COLL_WEIGHTS_MAX,
    _SC_EQUIV_CLASS_MAX,
    _SC_EXPR_NEST_MAX,
    _SC_LINE_MAX,
    _SC_RE_DUP_MAX,
    _SC_CHARCLASS_NAME_MAX,
    _SC_2_VERSION,
    _SC_2_C_BIND,
    _SC_2_C_DEV,
    _SC_2_FORT_DEV,
    _SC_2_FORT_RUN,
    _SC_2_SW_DEV,
    _SC_2_LOCALEDEF,
    _SC_PII,
    _SC_PII_XTI,
    _SC_PII_SOCKET,
    _SC_PII_INTERNET,
    _SC_PII_OSI,
    _SC_POLL,
    _SC_SELECT,
    _SC_UIO_MAXIOV,
    _SC_IOV_MAX = _SC_UIO_MAXIOV,
    _SC_PII_INTERNET_STREAM,
    _SC_PII_INTERNET_DGRAM,
    _SC_PII_OSI_COTS,
    _SC_PII_OSI_CLTS,
    _SC_PII_OSI_M,
    _SC_T_IOV_MAX,
    _SC_THREADS,
    _SC_THREAD_SAFE_FUNCTIONS,
    _SC_GETGR_R_SIZE_MAX,
    _SC_GETPW_R_SIZE_MAX,
    _SC_LOGIN_NAME_MAX,
    _SC_TTY_NAME_MAX,
    _SC_THREAD_DESTRUCTOR_ITERATIONS,
    _SC_THREAD_KEYS_MAX,
    _SC_THREAD_STACK_MIN,
    _SC_THREAD_THREADS_MAX,
    _SC_THREAD_ATTR_STACKADDR,
    _SC_THREAD_ATTR_STACKSIZE,
    _SC_THREAD_PRIORITY_SCHEDULING,
    _SC_THREAD_PRIO_INHERIT,
    _SC_THREAD_PRIO_PROTECT,
    _SC_THREAD_PROCESS_SHARED,
    _SC_NPROCESSORS_CONF,
    _SC_NPROCESSORS_ONLN,
    _SC_PHYS_PAGES,
    _SC_AVPHYS_PAGES,
    _SC_ATEXIT_MAX,
    _SC_PASS_MAX,
    _SC_XOPEN_VERSION,
    _SC_XOPEN_XCU_VERSION,
    _SC_XOPEN_UNIX,
    _SC_XOPEN_CRYPT,
    _SC_XOPEN_ENH_I18N,
    _SC_XOPEN_SHM,
    _SC_2_CHAR_TERM,
    _SC_2_C_VERSION,
    _SC_2_UPE,
    _SC_XOPEN_XPG2,
    _SC_XOPEN_XPG3,
    _SC_XOPEN_XPG4,
    _SC_CHAR_BIT,
    _SC_CHAR_MAX,
    _SC_CHAR_MIN,
    _SC_INT_MAX,
    _SC_INT_MIN,
    _SC_LONG_BIT,
    _SC_WORD_BIT,
    _SC_MB_LEN_MAX,
    _SC_NZERO,
    _SC_SSIZE_MAX,
    _SC_SCHAR_MAX,
    _SC_SCHAR_MIN,
    _SC_SHRT_MAX,
    _SC_SHRT_MIN,
    _SC_UCHAR_MAX,
    _SC_UINT_MAX,
    _SC_ULONG_MAX,
    _SC_USHRT_MAX,
    _SC_NL_ARGMAX,
    _SC_NL_LANGMAX,
    _SC_NL_MSGMAX,
    _SC_NL_NMAX,
    _SC_NL_SETMAX,
    _SC_NL_TEXTMAX,
    _SC_XBS5_ILP32_OFF32,
    _SC_XBS5_ILP32_OFFBIG,
    _SC_XBS5_LP64_OFF64,
    _SC_XBS5_LPBIG_OFFBIG,
    _SC_XOPEN_LEGACY,
    _SC_XOPEN_REALTIME,
    _SC_XOPEN_REALTIME_THREADS,
    _SC_ADVISORY_INFO,
    _SC_BARRIERS,
    _SC_BASE,
    _SC_C_LANG_SUPPORT,
    _SC_C_LANG_SUPPORT_R,
    _SC_CLOCK_SELECTION,
    _SC_CPUTIME,
    _SC_THREAD_CPUTIME,
    _SC_DEVICE_IO,
    _SC_DEVICE_SPECIFIC,
    _SC_DEVICE_SPECIFIC_R,
    _SC_FD_MGMT,
    _SC_FIFO,
    _SC_PIPE,
    _SC_FILE_ATTRIBUTES,
    _SC_FILE_LOCKING,
    _SC_FILE_SYSTEM,
    _SC_MONOTONIC_CLOCK,
    _SC_MULTI_PROCESS,
    _SC_SINGLE_PROCESS,
    _SC_NETWORKING,
    _SC_READER_WRITER_LOCKS,
    _SC_SPIN_LOCKS,
    _SC_REGEXP,
    _SC_REGEX_VERSION,
    _SC_SHELL,
    _SC_SIGNALS,
    _SC_SPAWN,
    _SC_SPORADIC_SERVER,
    _SC_THREAD_SPORADIC_SERVER,
    _SC_SYSTEM_DATABASE,
    _SC_SYSTEM_DATABASE_R,
    _SC_TIMEOUTS,
    _SC_TYPED_MEMORY_OBJECTS,
    _SC_USER_GROUPS,
    _SC_USER_GROUPS_R,
    _SC_2_PBS,
    _SC_2_PBS_ACCOUNTING,
    _SC_2_PBS_LOCATE,
    _SC_2_PBS_MESSAGE,
    _SC_2_PBS_TRACK,
    _SC_SYMLOOP_MAX,
    _SC_STREAMS,
    _SC_2_PBS_CHECKPOINT,
    _SC_V6_ILP32_OFF32,
    _SC_V6_ILP32_OFFBIG,
    _SC_V6_LP64_OFF64,
    _SC_V6_LPBIG_OFFBIG,
    _SC_HOST_NAME_MAX,
    _SC_TRACE,
    _SC_TRACE_EVENT_FILTER,
    _SC_TRACE_INHERIT,
    _SC_TRACE_LOG,
    _SC_LEVEL1_ICACHE_SIZE,
    _SC_LEVEL1_ICACHE_ASSOC,
    _SC_LEVEL1_ICACHE_LINESIZE,
    _SC_LEVEL1_DCACHE_SIZE,
    _SC_LEVEL1_DCACHE_ASSOC,
    _SC_LEVEL1_DCACHE_LINESIZE,
    _SC_LEVEL2_CACHE_SIZE,
    _SC_LEVEL2_CACHE_ASSOC,
    _SC_LEVEL2_CACHE_LINESIZE,
    _SC_LEVEL3_CACHE_SIZE,
    _SC_LEVEL3_CACHE_ASSOC,
    _SC_LEVEL3_CACHE_LINESIZE,
    _SC_LEVEL4_CACHE_SIZE,
    _SC_LEVEL4_CACHE_ASSOC,
    _SC_LEVEL4_CACHE_LINESIZE,
    _SC_IPV6 = _SC_LEVEL1_ICACHE_SIZE + 50,
    _SC_RAW_SOCKETS,
    _SC_V7_ILP32_OFF32,
    _SC_V7_ILP32_OFFBIG,
    _SC_V7_LP64_OFF64,
    _SC_V7_LPBIG_OFFBIG,
    _SC_SS_REPL_MAX,
    _SC_TRACE_EVENT_NAME_MAX,
    _SC_TRACE_NAME_MAX,
    _SC_TRACE_SYS_MAX,
    _SC_TRACE_USER_EVENT_MAX,
    _SC_XOPEN_STREAMS,
    _SC_THREAD_ROBUST_PRIO_INHERIT,
    _SC_THREAD_ROBUST_PRIO_PROTECT
  };
enum
  {
    _CS_PATH,
    _CS_V6_WIDTH_RESTRICTED_ENVS,
    _CS_GNU_LIBC_VERSION,
    _CS_GNU_LIBPTHREAD_VERSION,
    _CS_V5_WIDTH_RESTRICTED_ENVS,
    _CS_V7_WIDTH_RESTRICTED_ENVS,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS,
    _CS_LFS_LIBS,
    _CS_LFS_LINTFLAGS,
    _CS_LFS64_CFLAGS,
    _CS_LFS64_LDFLAGS,
    _CS_LFS64_LIBS,
    _CS_LFS64_LINTFLAGS,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS,
    _CS_XBS5_ILP32_OFF32_LIBS,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,
    _CS_XBS5_ILP32_OFFBIG_LIBS,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,
    _CS_XBS5_LP64_OFF64_CFLAGS,
    _CS_XBS5_LP64_OFF64_LDFLAGS,
    _CS_XBS5_LP64_OFF64_LIBS,
    _CS_XBS5_LP64_OFF64_LINTFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,
    _CS_XBS5_LPBIG_OFFBIG_LIBS,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFF32_LIBS,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V6_LP64_OFF64_LIBS,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFF32_LIBS,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS,
    _CS_POSIX_V7_LP64_OFF64_LIBS,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS,
    _CS_V6_ENV,
    _CS_V7_ENV
  };
extern long int pathconf (const char *__path, int __name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int fpathconf (int __fd, int __name) __attribute__ ((__nothrow__ , __leaf__));
extern long int sysconf (int __name) __attribute__ ((__nothrow__ , __leaf__));
extern size_t confstr (int __name, char *__buf, size_t __len) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getppid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t __getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getpgid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgid (__pid_t __pid, __pid_t __pgid) __attribute__ ((__nothrow__ , __leaf__));
extern int setpgrp (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t setsid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __pid_t getsid (__pid_t __pid) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t getuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __uid_t geteuid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getgid (void) __attribute__ ((__nothrow__ , __leaf__));
extern __gid_t getegid (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getgroups (int __size, __gid_t __list[]) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int group_member (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__));
extern int setuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setreuid (__uid_t __ruid, __uid_t __euid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int seteuid (__uid_t __uid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setgid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setregid (__gid_t __rgid, __gid_t __egid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setegid (__gid_t __gid) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getresuid (__uid_t *__ruid, __uid_t *__euid, __uid_t *__suid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int getresgid (__gid_t *__rgid, __gid_t *__egid, __gid_t *__sgid)
     __attribute__ ((__nothrow__ , __leaf__));
extern int setresuid (__uid_t __ruid, __uid_t __euid, __uid_t __suid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern int setresgid (__gid_t __rgid, __gid_t __egid, __gid_t __sgid)
     __attribute__ ((__nothrow__ , __leaf__)) ;
extern __pid_t fork (void) __attribute__ ((__nothrow__));
extern __pid_t vfork (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *ttyname (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern int isatty (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int ttyslot (void) __attribute__ ((__nothrow__ , __leaf__));
extern int link (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int linkat (int __fromfd, const char *__from, int __tofd,
     const char *__to, int __flags)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4))) ;
extern int symlink (const char *__from, const char *__to)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern ssize_t readlink (const char *__restrict __path,
    char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2))) ;
extern int symlinkat (const char *__from, int __tofd,
        const char *__to) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3))) ;
extern ssize_t readlinkat (int __fd, const char *__restrict __path,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3))) ;
extern int unlink (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int unlinkat (int __fd, const char *__name, int __flag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int rmdir (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern __pid_t tcgetpgrp (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) __attribute__ ((__nothrow__ , __leaf__));
extern char *getlogin (void);
extern int getlogin_r (char *__name, size_t __name_len) __attribute__ ((__nonnull__ (1)));
extern int setlogin (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));

extern char *optarg;
extern int optind;
extern int opterr;
extern int optopt;
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts)
       __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));



extern int gethostname (char *__name, size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int sethostname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int sethostid (long int __id) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int getdomainname (char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int setdomainname (const char *__name, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int vhangup (void) __attribute__ ((__nothrow__ , __leaf__));
extern int revoke (const char *__file) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int profil (unsigned short int *__sample_buffer, size_t __size,
     size_t __offset, unsigned int __scale)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int acct (const char *__name) __attribute__ ((__nothrow__ , __leaf__));
extern char *getusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void endusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern void setusershell (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daemon (int __nochdir, int __noclose) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int chroot (const char *__path) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *getpass (const char *__prompt) __attribute__ ((__nonnull__ (1)));
extern int fsync (int __fd);
extern int syncfs (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern long int gethostid (void);
extern void sync (void) __attribute__ ((__nothrow__ , __leaf__));
extern int getpagesize (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int getdtablesize (void) __attribute__ ((__nothrow__ , __leaf__));
extern int truncate (const char *__file, __off_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int truncate64 (const char *__file, __off64_t __length)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int ftruncate (int __fd, __off_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ftruncate64 (int __fd, __off64_t __length) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int brk (void *__addr) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void *sbrk (intptr_t __delta) __attribute__ ((__nothrow__ , __leaf__));
extern long int syscall (long int __sysno, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int lockf (int __fd, int __cmd, __off_t __len) ;
extern int lockf64 (int __fd, int __cmd, __off64_t __len) ;
ssize_t copy_file_range (int __infd, __off64_t *__pinoff,
    int __outfd, __off64_t *__poutoff,
    size_t __length, unsigned int __flags);
extern int fdatasync (int __fildes);
extern char *crypt (const char *__key, const char *__salt)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void encrypt (char *__glibc_block, int __edflag)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void swab (const void *__restrict __from, void *__restrict __to,
    ssize_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
int getentropy (void *__buffer, size_t __length) ;


typedef enum
{
  P_ALL,
  P_PID,
  P_PGID
} idtype_t;
typedef struct
  {
    int quot;
    int rem;
  } div_t;
typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;
__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
extern size_t __ctype_get_mb_cur_max (void) __attribute__ ((__nothrow__ , __leaf__)) ;
extern double atof (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern int atoi (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int atol (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
__extension__ extern long long int atoll (const char *__nptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern double strtod (const char *__restrict __nptr,
        char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern float strtof (const char *__restrict __nptr,
       char **__restrict __endptr) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long double strtold (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32 strtof32 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64 strtof64 (const char *__restrict __nptr,
     char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float128 strtof128 (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float32x strtof32x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern _Float64x strtof64x (const char *__restrict __nptr,
       char **__restrict __endptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int strtol (const char *__restrict __nptr,
   char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern unsigned long int strtoul (const char *__restrict __nptr,
      char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoq (const char *__restrict __nptr,
        char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtouq (const char *__restrict __nptr,
           char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern long long int strtoll (const char *__restrict __nptr,
         char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
__extension__
extern unsigned long long int strtoull (const char *__restrict __nptr,
     char **__restrict __endptr, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int strfromd (char *__dest, size_t __size, const char *__format,
       double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf (char *__dest, size_t __size, const char *__format,
       float __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfroml (char *__dest, size_t __size, const char *__format,
       long double __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32 (char *__dest, size_t __size, const char * __format,
         _Float32 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64 (char *__dest, size_t __size, const char * __format,
         _Float64 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf128 (char *__dest, size_t __size, const char * __format,
   _Float128 __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf32x (char *__dest, size_t __size, const char * __format,
   _Float32x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
extern int strfromf64x (char *__dest, size_t __size, const char * __format,
   _Float64x __f)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3)));
struct __locale_struct
{
  struct __locale_data *__locales[13];
  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
  const char *__names[13];
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
extern long int strtol_l (const char *__restrict __nptr,
     char **__restrict __endptr, int __base,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern unsigned long int strtoul_l (const char *__restrict __nptr,
        char **__restrict __endptr,
        int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern long long int strtoll_l (const char *__restrict __nptr,
    char **__restrict __endptr, int __base,
    locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
__extension__
extern unsigned long long int strtoull_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       int __base, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 4)));
extern double strtod_l (const char *__restrict __nptr,
   char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern float strtof_l (const char *__restrict __nptr,
         char **__restrict __endptr, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern long double strtold_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32 strtof32_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64 strtof64_l (const char *__restrict __nptr,
       char **__restrict __endptr,
       locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float128 strtof128_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float32x strtof32x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern _Float64x strtof64x_l (const char *__restrict __nptr,
         char **__restrict __endptr,
         locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 3)));
extern char *l64a (long int __n) __attribute__ ((__nothrow__ , __leaf__)) ;
extern long int a64l (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1))) ;
extern long int random (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srandom (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern char *initstate (unsigned int __seed, char *__statebuf,
   size_t __statelen) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *setstate (char *__statebuf) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };
extern int random_r (struct random_data *__restrict __buf,
       int32_t *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srandom_r (unsigned int __seed, struct random_data *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
   size_t __statelen,
   struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern int setstate_r (char *__restrict __statebuf,
         struct random_data *__restrict __buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int rand (void) __attribute__ ((__nothrow__ , __leaf__));
extern void srand (unsigned int __seed) __attribute__ ((__nothrow__ , __leaf__));
extern int rand_r (unsigned int *__seed) __attribute__ ((__nothrow__ , __leaf__));
extern double drand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern double erand48 (unsigned short int __xsubi[3]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int lrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int nrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern long int mrand48 (void) __attribute__ ((__nothrow__ , __leaf__));
extern long int jrand48 (unsigned short int __xsubi[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void srand48 (long int __seedval) __attribute__ ((__nothrow__ , __leaf__));
extern unsigned short int *seed48 (unsigned short int __seed16v[3])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void lcong48 (unsigned short int __param[7]) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    __extension__ unsigned long long int __a;
  };
extern int drand48_r (struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int erand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        double *__restrict __result) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int nrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int mrand48_r (struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int jrand48_r (unsigned short int __xsubi[3],
        struct drand48_data *__restrict __buffer,
        long int *__restrict __result)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int seed48_r (unsigned short int __seed16v[3],
       struct drand48_data *__buffer) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int lcong48_r (unsigned short int __param[7],
        struct drand48_data *__buffer)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *malloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern void *calloc (size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern void *realloc (void *__ptr, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void *reallocarray (void *__ptr, size_t __nmemb, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__warn_unused_result__));
extern void free (void *__ptr) __attribute__ ((__nothrow__ , __leaf__));

extern void *alloca (size_t __size) __attribute__ ((__nothrow__ , __leaf__));

extern void *valloc (size_t __size) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern void *aligned_alloc (size_t __alignment, size_t __size)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__alloc_size__ (2))) ;
extern void abort (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern int atexit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int at_quick_exit (void (*__func) (void)) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void quick_exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void _Exit (int __status) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern char *getenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *secure_getenv (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int putenv (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int setenv (const char *__name, const char *__value, int __replace)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int unsetenv (const char *__name) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int clearenv (void) __attribute__ ((__nothrow__ , __leaf__));
extern char *mktemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int mkstemp (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemp64 (char *__template) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps (char *__template, int __suffixlen) __attribute__ ((__nonnull__ (1))) ;
extern int mkstemps64 (char *__template, int __suffixlen)
     __attribute__ ((__nonnull__ (1))) ;
extern char *mkdtemp (char *__template) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemp64 (char *__template, int __flags) __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int mkostemps64 (char *__template, int __suffixlen, int __flags)
     __attribute__ ((__nonnull__ (1))) ;
extern int system (const char *__command) ;
extern char *canonicalize_file_name (const char *__name)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern char *realpath (const char *__restrict __name,
         char *__restrict __resolved) __attribute__ ((__nothrow__ , __leaf__)) ;
typedef int (*__compar_fn_t) (const void *, const void *);
typedef __compar_fn_t comparison_fn_t;
typedef int (*__compar_d_fn_t) (const void *, const void *, void *);
extern void *bsearch (const void *__key, const void *__base,
        size_t __nmemb, size_t __size, __compar_fn_t __compar)
     __attribute__ ((__nonnull__ (1, 2, 5))) ;
extern void qsort (void *__base, size_t __nmemb, size_t __size,
     __compar_fn_t __compar) __attribute__ ((__nonnull__ (1, 4)));
extern void qsort_r (void *__base, size_t __nmemb, size_t __size,
       __compar_d_fn_t __compar, void *__arg)
  __attribute__ ((__nonnull__ (1, 4)));
extern int abs (int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern long int labs (long int __x) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern long long int llabs (long long int __x)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern div_t div (int __numer, int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
__extension__ extern lldiv_t lldiv (long long int __numer,
        long long int __denom)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__)) ;
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *gcvt (double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern char *qecvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qfcvt (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4))) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3))) ;
extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
     int *__restrict __sign, char *__restrict __buf,
     size_t __len) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qecvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int qfcvt_r (long double __value, int __ndigit,
      int *__restrict __decpt, int *__restrict __sign,
      char *__restrict __buf, size_t __len)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (3, 4, 5)));
extern int mblen (const char *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int mbtowc (wchar_t *__restrict __pwc,
     const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern int wctomb (char *__s, wchar_t __wchar) __attribute__ ((__nothrow__ , __leaf__));
extern size_t mbstowcs (wchar_t *__restrict __pwcs,
   const char *__restrict __s, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern size_t wcstombs (char *__restrict __s,
   const wchar_t *__restrict __pwcs, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__));
extern int rpmatch (const char *__response) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1))) ;
extern int getsubopt (char **__restrict __optionp,
        char *const *__restrict __tokens,
        char **__restrict __valuep)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2, 3))) ;
extern void setkey (const char *__key) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int posix_openpt (int __oflag) ;
extern int grantpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern int unlockpt (int __fd) __attribute__ ((__nothrow__ , __leaf__));
extern char *ptsname (int __fd) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ptsname_r (int __fd, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int getpt (void);
extern int getloadavg (double __loadavg[], int __nelem)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


struct _IO_FILE;
typedef struct _IO_FILE __FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef struct
{
  int __count;
  union
  {
    unsigned int __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t; struct _IO_FILE;
typedef void _IO_lock_t;
struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;
  int _pos;
};
enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
struct _IO_FILE {
  int _flags;
  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;
  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;
  struct _IO_marker *_markers;
  struct _IO_FILE *_chain;
  int _fileno;
  int _flags2;
  __off_t _old_offset;
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];
  _IO_lock_t *_lock;
  __off64_t _offset;
  void *__pad1;
  void *__pad2;
  void *__pad3;
  void *__pad4;
  size_t __pad5;
  int _mode;
  char _unused2[15 * sizeof (int) - 4 * sizeof (void *) - sizeof (size_t)];
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);
typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
     size_t __n);
typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);
typedef int __io_close_fn (void *__cookie);
typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;
typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
        void *__cookie, _IO_cookie_io_functions_t __fns);
extern int __underflow (_IO_FILE *);
extern int __uflow (_IO_FILE *);
extern int __overflow (_IO_FILE *, int);
extern int _IO_getc (_IO_FILE *__fp);
extern int _IO_putc (int __c, _IO_FILE *__fp);
extern int _IO_feof (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ferror (_IO_FILE *__fp) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_peekc_locked (_IO_FILE *__fp);
extern void _IO_flockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern void _IO_funlockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_ftrylockfile (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
   __gnuc_va_list, int *__restrict);
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
    __gnuc_va_list);
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t);
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t);
extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int);
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int);
extern void _IO_free_backup_area (_IO_FILE *) __attribute__ ((__nothrow__ , __leaf__));
typedef __gnuc_va_list va_list;
typedef _G_fpos_t fpos_t;
typedef _G_fpos64_t fpos64_t;
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;
extern int remove (const char *__filename) __attribute__ ((__nothrow__ , __leaf__));
extern int rename (const char *__old, const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern int renameat (int __oldfd, const char *__old, int __newfd,
       const char *__new) __attribute__ ((__nothrow__ , __leaf__));
extern FILE *tmpfile (void) ;
extern FILE *tmpfile64 (void) ;
extern char *tmpnam (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tmpnam_r (char *__s) __attribute__ ((__nothrow__ , __leaf__)) ;
extern char *tempnam (const char *__dir, const char *__pfx)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) ;
extern int fclose (FILE *__stream);
extern int fflush (FILE *__stream);
extern int fflush_unlocked (FILE *__stream);
extern int fcloseall (void);
extern FILE *fopen (const char *__restrict __filename,
      const char *__restrict __modes) ;
extern FILE *freopen (const char *__restrict __filename,
        const char *__restrict __modes,
        FILE *__restrict __stream) ;
extern FILE *fopen64 (const char *__restrict __filename,
        const char *__restrict __modes) ;
extern FILE *freopen64 (const char *__restrict __filename,
   const char *__restrict __modes,
   FILE *__restrict __stream) ;
extern FILE *fdopen (int __fd, const char *__modes) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *fopencookie (void *__restrict __magic_cookie,
     const char *__restrict __modes,
     _IO_cookie_io_functions_t __io_funcs) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *fmemopen (void *__s, size_t __len, const char *__modes)
  __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *open_memstream (char **__bufloc, size_t *__sizeloc) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
      int __modes, size_t __n) __attribute__ ((__nothrow__ , __leaf__));
extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
         size_t __size) __attribute__ ((__nothrow__ , __leaf__));
extern void setlinebuf (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int fprintf (FILE *__restrict __stream,
      const char *__restrict __format, ...);
extern int printf (const char *__restrict __format, ...);
extern int sprintf (char *__restrict __s,
      const char *__restrict __format, ...) __attribute__ ((__nothrow__));
extern int vfprintf (FILE *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg);
extern int vprintf (const char *__restrict __format, __gnuc_va_list __arg);
extern int vsprintf (char *__restrict __s, const char *__restrict __format,
       __gnuc_va_list __arg) __attribute__ ((__nothrow__));
extern int snprintf (char *__restrict __s, size_t __maxlen,
       const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 4)));
extern int vsnprintf (char *__restrict __s, size_t __maxlen,
        const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 3, 0)));
extern int vasprintf (char **__restrict __ptr, const char *__restrict __f,
        __gnuc_va_list __arg)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0))) ;
extern int __asprintf (char **__restrict __ptr,
         const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int asprintf (char **__restrict __ptr,
       const char *__restrict __fmt, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3))) ;
extern int vdprintf (int __fd, const char *__restrict __fmt,
       __gnuc_va_list __arg)
     __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, const char *__restrict __fmt, ...)
     __attribute__ ((__format__ (__printf__, 2, 3)));
extern int fscanf (FILE *__restrict __stream,
     const char *__restrict __format, ...) ;
extern int scanf (const char *__restrict __format, ...) ;
extern int sscanf (const char *__restrict __s,
     const char *__restrict __format, ...) __attribute__ ((__nothrow__ , __leaf__));
extern int vfscanf (FILE *__restrict __s, const char *__restrict __format,
      __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 2, 0))) ;
extern int vscanf (const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__format__ (__scanf__, 1, 0))) ;
extern int vsscanf (const char *__restrict __s,
      const char *__restrict __format, __gnuc_va_list __arg)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__format__ (__scanf__, 2, 0)));
extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);
extern int getchar (void);
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
extern int fgetc_unlocked (FILE *__stream);
extern int fputc (int __c, FILE *__stream);
extern int putc (int __c, FILE *__stream);
extern int putchar (int __c);
extern int fputc_unlocked (int __c, FILE *__stream);
extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);
extern int getw (FILE *__stream);
extern int putw (int __w, FILE *__stream);
extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     ;
extern char *fgets_unlocked (char *__restrict __s, int __n,
        FILE *__restrict __stream) ;
extern __ssize_t __getdelim (char **__restrict __lineptr,
          size_t *__restrict __n, int __delimiter,
          FILE *__restrict __stream) ;
extern __ssize_t getdelim (char **__restrict __lineptr,
        size_t *__restrict __n, int __delimiter,
        FILE *__restrict __stream) ;
extern __ssize_t getline (char **__restrict __lineptr,
       size_t *__restrict __n,
       FILE *__restrict __stream) ;
extern int fputs (const char *__restrict __s, FILE *__restrict __stream);
extern int puts (const char *__s);
extern int ungetc (int __c, FILE *__stream);
extern size_t fread (void *__restrict __ptr, size_t __size,
       size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite (const void *__restrict __ptr, size_t __size,
        size_t __n, FILE *__restrict __s);
extern int fputs_unlocked (const char *__restrict __s,
      FILE *__restrict __stream);
extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
         size_t __n, FILE *__restrict __stream) ;
extern size_t fwrite_unlocked (const void *__restrict __ptr, size_t __size,
          size_t __n, FILE *__restrict __stream);
extern int fseek (FILE *__stream, long int __off, int __whence);
extern long int ftell (FILE *__stream) ;
extern void rewind (FILE *__stream);
extern int fseeko (FILE *__stream, __off_t __off, int __whence);
extern __off_t ftello (FILE *__stream) ;
extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos);
extern int fsetpos (FILE *__stream, const fpos_t *__pos);
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream) ;
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);
extern void clearerr (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void clearerr_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int feof_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int ferror_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void perror (const char *__s);
extern int sys_nerr;
extern const char *const sys_errlist[];
extern int _sys_nerr;
extern const char *const _sys_errlist[];
extern int fileno (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern int fileno_unlocked (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern FILE *popen (const char *__command, const char *__modes) ;
extern int pclose (FILE *__stream);
extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
extern char *cuserid (char *__s);
struct obstack;
extern int obstack_printf (struct obstack *__restrict __obstack,
      const char *__restrict __format, ...)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 3)));
extern int obstack_vprintf (struct obstack *__restrict __obstack,
       const char *__restrict __format,
       __gnuc_va_list __args)
     __attribute__ ((__nothrow__)) __attribute__ ((__format__ (__printf__, 2, 0)));
extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));


extern void *memcpy (void *__restrict __dest, const void *__restrict __src,
       size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmove (void *__dest, const void *__src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memccpy (void *__restrict __dest, const void *__restrict __src,
        int __c, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memset (void *__s, int __c, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *rawmemchr (const void *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern void *memrchr (const void *__s, int __c, size_t __n)
      __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strcat (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strncat (char *__restrict __dest, const char *__restrict __src,
        size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcoll (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strxfrm (char *__restrict __dest,
         const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern int strcoll_l (const char *__s1, const char *__s2, locale_t __l)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
    locale_t __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 4)));
extern char *strdup (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strndup (const char *__string, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__malloc__)) __attribute__ ((__nonnull__ (1)));
extern char *strchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strrchr (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strchrnul (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strcspn (const char *__s, const char *__reject)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strspn (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strpbrk (const char *__s, const char *__accept)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strstr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strtok (char *__restrict __s, const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2)));
extern char *__strtok_r (char *__restrict __s,
    const char *__restrict __delim,
    char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strtok_r (char *__restrict __s, const char *__restrict __delim,
         char **__restrict __save_ptr)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2, 3)));
extern char *strcasestr (const char *__haystack, const char *__needle)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *memmem (const void *__haystack, size_t __haystacklen,
       const void *__needle, size_t __needlelen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 3)));
extern void *__mempcpy (void *__restrict __dest,
   const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void *mempcpy (void *__restrict __dest,
        const void *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern size_t strlen (const char *__s)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern size_t strnlen (const char *__string, size_t __maxlen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *strerror (int __errnum) __attribute__ ((__nothrow__ , __leaf__));
extern char *strerror_r (int __errnum, char *__buf, size_t __buflen)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (2))) ;
extern char *strerror_l (int __errnum, locale_t __l) __attribute__ ((__nothrow__ , __leaf__));

extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bcopy (const void *__src, void *__dest, size_t __n)
  __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern void bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *index (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern char *rindex (const char *__s, int __c)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1)));
extern int ffs (int __i) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int ffsl (long int __l) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
__extension__ extern int ffsll (long long int __ll)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int strcasecmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strcasecmp_l (const char *__s1, const char *__s2, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 3)));
extern int strncasecmp_l (const char *__s1, const char *__s2,
     size_t __n, locale_t __loc)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2, 4)));

extern void explicit_bzero (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *strsep (char **__restrict __stringp,
       const char *__restrict __delim)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strsignal (int __sig) __attribute__ ((__nothrow__ , __leaf__));
extern char *__stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpcpy (char *__restrict __dest, const char *__restrict __src)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *__stpncpy (char *__restrict __dest,
   const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *stpncpy (char *__restrict __dest,
        const char *__restrict __src, size_t __n)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1, 2)));
extern int strverscmp (const char *__s1, const char *__s2)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__pure__)) __attribute__ ((__nonnull__ (1, 2)));
extern char *strfry (char *__string) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern void *memfrob (void *__s, size_t __n) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern char *basename (const char *__filename) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));


extern int *__errno_location (void) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern char *program_invocation_name;
extern char *program_invocation_short_name;
typedef int error_t;

struct timex
{
  unsigned int modes;
  __syscall_slong_t offset;
  __syscall_slong_t freq;
  __syscall_slong_t maxerror;
  __syscall_slong_t esterror;
  int status;
  __syscall_slong_t constant;
  __syscall_slong_t precision;
  __syscall_slong_t tolerance;
  struct timeval time;
  __syscall_slong_t tick;
  __syscall_slong_t ppsfreq;
  __syscall_slong_t jitter;
  int shift;
  __syscall_slong_t stabil;
  __syscall_slong_t jitcnt;
  __syscall_slong_t calcnt;
  __syscall_slong_t errcnt;
  __syscall_slong_t stbcnt;
  int tai;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32; int :32;
  int :32; int :32; int :32;
};

extern int clock_adjtime (__clockid_t __clock_id, struct timex *__utx) __attribute__ ((__nothrow__ , __leaf__));

struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
  long int tm_gmtoff;
  const char *tm_zone;
};
struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };
struct sigevent;

extern clock_t clock (void) __attribute__ ((__nothrow__ , __leaf__));
extern time_t time (time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern double difftime (time_t __time1, time_t __time0)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern time_t mktime (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime (char *__restrict __s, size_t __maxsize,
   const char *__restrict __format,
   const struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *strptime (const char *__restrict __s,
         const char *__restrict __fmt, struct tm *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern size_t strftime_l (char *__restrict __s, size_t __maxsize,
     const char *__restrict __format,
     const struct tm *__restrict __tp,
     locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern char *strptime_l (const char *__restrict __s,
    const char *__restrict __fmt, struct tm *__tp,
    locale_t __loc) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *gmtime_r (const time_t *__restrict __timer,
       struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern struct tm *localtime_r (const time_t *__restrict __timer,
          struct tm *__restrict __tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime (const struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime (const time_t *__timer) __attribute__ ((__nothrow__ , __leaf__));
extern char *asctime_r (const struct tm *__restrict __tp,
   char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *ctime_r (const time_t *__restrict __timer,
        char *__restrict __buf) __attribute__ ((__nothrow__ , __leaf__));
extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;
extern char *tzname[2];
extern void tzset (void) __attribute__ ((__nothrow__ , __leaf__));
extern int daylight;
extern long int timezone;
extern int stime (const time_t *__when) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timegm (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern time_t timelocal (struct tm *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int dysize (int __year) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__const__));
extern int nanosleep (const struct timespec *__requested_time,
        struct timespec *__remaining);
extern int clock_getres (clockid_t __clock_id, struct timespec *__res) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) __attribute__ ((__nothrow__ , __leaf__));
extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     __attribute__ ((__nothrow__ , __leaf__));
extern int clock_nanosleep (clockid_t __clock_id, int __flags,
       const struct timespec *__req,
       struct timespec *__rem);
extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_create (clockid_t __clock_id,
    struct sigevent *__restrict __evp,
    timer_t *__restrict __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_delete (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_settime (timer_t __timerid, int __flags,
     const struct itimerspec *__restrict __value,
     struct itimerspec *__restrict __ovalue) __attribute__ ((__nothrow__ , __leaf__));
extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     __attribute__ ((__nothrow__ , __leaf__));
extern int timer_getoverrun (timer_t __timerid) __attribute__ ((__nothrow__ , __leaf__));
extern int timespec_get (struct timespec *__ts, int __base)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int getdate_err;
extern struct tm *getdate (const char *__string);
extern int getdate_r (const char *__restrict __string,
        struct tm *__restrict __resbufp);


struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };
typedef struct timezone *__restrict __timezone_ptr_t;
extern int gettimeofday (struct timeval *__restrict __tv,
    __timezone_ptr_t __tz) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int settimeofday (const struct timeval *__tv,
    const struct timezone *__tz)
     __attribute__ ((__nothrow__ , __leaf__));
extern int adjtime (const struct timeval *__delta,
      struct timeval *__olddelta) __attribute__ ((__nothrow__ , __leaf__));
enum __itimer_which
  {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
  };
struct itimerval
  {
    struct timeval it_interval;
    struct timeval it_value;
  };
typedef enum __itimer_which __itimer_which_t;
extern int getitimer (__itimer_which_t __which,
        struct itimerval *__value) __attribute__ ((__nothrow__ , __leaf__));
extern int setitimer (__itimer_which_t __which,
        const struct itimerval *__restrict __new,
        struct itimerval *__restrict __old) __attribute__ ((__nothrow__ , __leaf__));
extern int utimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int lutimes (const char *__file, const struct timeval __tvp[2])
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__nonnull__ (1)));
extern int futimes (int __fd, const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));
extern int futimesat (int __fd, const char *__file,
        const struct timeval __tvp[2]) __attribute__ ((__nothrow__ , __leaf__));

extern _Bool debug_flag;
void die(void) __attribute__((__noreturn__));
void error_msg(const char *fmt, ...) __attribute__((__format__ (printf, 1, 2)));
void perror_msg(const char *fmt, ...) __attribute__((__format__ (printf, 1, 2)));
void perror_msg_and_die(const char *fmt, ...)
 __attribute__((__format__ (printf, 1, 2))) __attribute__((__noreturn__));
void error_msg_and_help(const char *fmt, ...)
 __attribute__((__format__ (printf, 1, 2))) __attribute__((__noreturn__));
void error_msg_and_die(const char *fmt, ...)
 __attribute__((__format__ (printf, 1, 2))) __attribute__((__noreturn__));
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned long __kernel_old_dev_t;
typedef long __kernel_long_t;
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_ino_t;
typedef unsigned int __kernel_mode_t;
typedef int __kernel_pid_t;
typedef int __kernel_ipc_pid_t;
typedef unsigned int __kernel_uid_t;
typedef unsigned int __kernel_gid_t;
typedef __kernel_long_t __kernel_suseconds_t;
typedef int __kernel_daddr_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef __kernel_ulong_t __kernel_size_t;
typedef __kernel_long_t __kernel_ssize_t;
typedef __kernel_long_t __kernel_ptrdiff_t;
typedef struct {
 int val[2];
} __kernel_fsid_t;
typedef __kernel_long_t __kernel_off_t;
typedef long long __kernel_loff_t;
typedef __kernel_long_t __kernel_time_t;
typedef __kernel_long_t __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef char * __kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef __kernel_long_t kernel_long_t;
typedef __kernel_ulong_t kernel_ulong_t;

extern void __assert_fail (const char *__assertion, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert_perror_fail (int __errnum, const char *__file,
      unsigned int __line, const char *__function)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
extern void __assert (const char *__assertion, const char *__file, int __line)
     __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));

static inline _Bool
is_filled(const char *ptr, char fill, size_t size)
{
 while (size--)
  if (*ptr++ != fill)
   return 0;
 return 1;
}
struct list_item {
 struct list_item *prev;
 struct list_item *next;
};
static inline void
list_init(struct list_item *l)
{
 l->prev = l;
 l->next = l;
}
static inline _Bool
list_is_empty(const struct list_item *l)
{
 return ((l->next == l) && (l->prev == l))
  || (!l->next && !l->prev);
}
static inline void
list_insert(struct list_item *head, struct list_item *item)
{
 item->next = head->next;
 item->prev = head;
 head->next->prev = item;
 head->next = item;
}
static inline void
list_append(struct list_item *head, struct list_item *item)
{
 item->next = head;
 item->prev = head->prev;
 head->prev->next = item;
 head->prev = item;
}
static inline _Bool
list_remove(struct list_item *item)
{
 if (!item->next || !item->prev || list_is_empty(item))
  return 0;
 item->prev->next = item->next;
 item->next->prev = item->prev;
 item->next = item->prev = item;
 return 1;
}
static inline struct list_item *
list_remove_tail(struct list_item *head)
{
 struct list_item *t = list_is_empty(head) ? ((void *)0) : head->prev;
 if (t)
  list_remove(t);
 return t;
}
static inline struct list_item *
list_remove_head(struct list_item *head)
{
 struct list_item *h = list_is_empty(head) ? ((void *)0) : head->next;
 if (h)
  list_remove(h);
 return h;
}
static inline _Bool
list_replace(struct list_item *old, struct list_item *new)
{
 if (!old->next || !old->prev || list_is_empty(old))
  return 0;
 new->next = old->next;
 new->prev = old->prev;
 old->prev->next = new;
 old->next->prev = new;
 old->next = old->prev = old;
 return 1;
}
typedef unsigned long mpers_ptr_t;
extern long long
string_to_uint_ex(const char *str, char **endptr,
    unsigned long long max_val, const char *accepted_ending);
static inline long long
string_to_uint_upto(const char *const str, const unsigned long long max_val)
{
 return string_to_uint_ex(str, ((void *)0), max_val, ((void *)0));
}
static inline int
string_to_uint(const char *str)
{
 return string_to_uint_upto(str, 0x7fffffff);
}
static inline long
string_to_ulong(const char *str)
{
 return string_to_uint_upto(str, 0x7fffffffffffffffL);
}
static inline kernel_long_t
string_to_kulong(const char *str)
{
 return string_to_uint_upto(str, ((kernel_ulong_t) -1ULL) >> 1);
}
static inline long long
string_to_ulonglong(const char *str)
{
 return string_to_uint_upto(str, 0x7fffffffffffffffLL);
}
typedef struct sysent {
 unsigned nargs;
 int sys_flags;
 int sen;
 int (*sys_func)();
 const char *sys_name;
} struct_sysent;
void *strace_malloc(size_t size) __attribute__((__malloc__)) __attribute__((__alloc_size__ (1)));
void *strace_calloc(size_t nmemb, size_t size)
 __attribute__((__malloc__)) __attribute__((__alloc_size__ (1, 2)));
__attribute__((__malloc__)) __attribute__((__alloc_size__ (1)))
static inline void *
xzalloc(size_t size)
{
 return strace_calloc(1, size);
}
void *xallocarray(size_t nmemb, size_t size)
 __attribute__((__malloc__)) __attribute__((__alloc_size__ (1, 2)));
void *xreallocarray(void *ptr, size_t nmemb, size_t size)
 __attribute__((__alloc_size__ (2, 3)));
void *xgrowarray(void *ptr, size_t *nmemb, size_t memb_size);
char *xstrdup(const char *str) __attribute__((__malloc__));
char *xstrndup(const char *str, size_t n) __attribute__((__malloc__));
void *xmemdup(const void *src, size_t size)
 __attribute__((__malloc__)) __attribute__((__alloc_size__ (2)));
void *xarraydup(const void *src, size_t nmemb, size_t memb_size)
 __attribute__((__malloc__)) __attribute__((__alloc_size__ (2, 3)));
char *xasprintf(const char *fmt, ...)
 __attribute__((__format__ (printf, 1, 2))) __attribute__((__malloc__));
extern void set_personality(unsigned int personality);
extern unsigned current_personality;
extern unsigned current_wordsize;
extern unsigned current_klongsize;
typedef struct ioctlent {
 const char *symbol;
 unsigned int code;
} struct_ioctlent;
struct inject_data {
 uint8_t flags;
 uint8_t signo;
 uint16_t rval_idx;
 uint16_t delay_idx;
 uint16_t poke_idx;
 uint16_t scno;
};
struct inject_opts {
 uint16_t first;
 uint16_t last;
 uint16_t step;
 struct inject_data data;
};
struct tcb {
 int flags;
 int pid;
 int qual_flg;
 unsigned int currpers;
 unsigned long u_error;
 kernel_ulong_t scno;
 kernel_ulong_t true_scno;
 kernel_ulong_t u_arg[6];
 kernel_long_t u_rval;
 int sys_func_rval;
 int curcol;
 FILE *outf;
 struct staged_output_data *staged_output_data;
 const char *auxstr;
 void *_priv_data;
 void (*_free_priv_data)(void *);
 const struct_sysent *s_ent;
 const struct_sysent *s_prev_ent;
 struct inject_opts *inject_vec[3];
 struct timespec stime;
 struct timespec ltime;
 struct timespec atime;
 struct timespec etime;
 struct timespec delay_expiration_time;
 unsigned int pid_ns;
 struct mmap_cache_t *mmap_cache;
 size_t wait_data_idx;
 struct tcb_wait_data *delayed_wait_data;
 struct list_item wait_list;
 struct vcpu_info *vcpu_info_list;
 void *unwind_ctx;
 struct unwind_queue_t *unwind_queue;
 char comm[16];
};
extern const struct_sysent stub_sysent;
enum xlat_type {
 XT_NORMAL,
 XT_SORTED,
 XT_INDEXED,
};
enum xlat_style {
 XLAT_STYLE_DEFAULT = 0,
 XLAT_STYLE_RAW = 1 << 0,
 XLAT_STYLE_ABBREV = 1 << 1,
 XLAT_STYLE_VERBOSE = XLAT_STYLE_RAW | XLAT_STYLE_ABBREV,
 XLAT_STYLE_FMT_X = 0 << 2,
 XLAT_STYLE_FMT_U = 1 << 2,
 XLAT_STYLE_FMT_D = 2 << 2,
};
struct xlat_data {
 uint64_t val;
 const char *str;
};
struct xlat {
 const struct xlat_data *data;
 size_t flags_strsz;
 uint32_t size;
 enum xlat_type type;
 uint64_t flags_mask;
};
extern const struct xlat addrfams[];
extern const struct xlat arp_hardware_types[];
extern const struct xlat at_flags[];
extern const struct xlat clocknames[];
extern const struct xlat dirent_types[];
extern const struct xlat ethernet_protocols[];
extern const struct xlat inet_protocols[];
extern const struct xlat evdev_abs[];
extern const struct xlat audit_arch[];
extern const struct xlat evdev_ev[];
extern const struct xlat iffflags[];
extern const struct xlat ip_type_of_services[];
extern const struct xlat ipc_private[];
extern const struct xlat msg_flags[];
extern const struct xlat netlink_protocols[];
extern const struct xlat nl_bridge_vlan_flags[];
extern const struct xlat nl_netfilter_msg_types[];
extern const struct xlat nl_route_types[];
extern const struct xlat open_access_modes[];
extern const struct xlat open_mode_flags[];
extern const struct xlat perf_type_id[];
extern const struct xlat pollflags[];
extern const struct xlat ptrace_cmds[];
extern const struct xlat resource_flags[];
extern const struct xlat route_nexthop_flags[];
extern const struct xlat routing_protocols[];
extern const struct xlat routing_scopes[];
extern const struct xlat routing_table_ids[];
extern const struct xlat routing_types[];
extern const struct xlat rwf_flags[];
extern const struct xlat seccomp_filter_flags[];
extern const struct xlat seccomp_ret_action[];
extern const struct xlat setns_types[];
extern const struct xlat sg_io_info[];
extern const struct xlat socketlayers[];
extern const struct xlat socktypes[];
extern const struct xlat tcp_state_flags[];
extern const struct xlat tcp_states[];
extern const struct xlat whence_codes[];
enum pid_type {
 PT_TID,
 PT_TGID,
 PT_PGID,
 PT_SID,
 PT_COUNT,
 PT_NONE = -1
};
enum sock_proto {
 SOCK_PROTO_UNKNOWN,
 SOCK_PROTO_UNIX,
 SOCK_PROTO_UNIX_STREAM,
 SOCK_PROTO_TCP,
 SOCK_PROTO_UDP,
 SOCK_PROTO_UDPLITE,
 SOCK_PROTO_DCCP,
 SOCK_PROTO_SCTP,
 SOCK_PROTO_L2TP_IP,
 SOCK_PROTO_PING,
 SOCK_PROTO_RAW,
 SOCK_PROTO_TCPv6,
 SOCK_PROTO_UDPv6,
 SOCK_PROTO_UDPLITEv6,
 SOCK_PROTO_DCCPv6,
 SOCK_PROTO_L2TP_IPv6,
 SOCK_PROTO_SCTPv6,
 SOCK_PROTO_PINGv6,
 SOCK_PROTO_RAWv6,
 SOCK_PROTO_NETLINK,
};
extern enum sock_proto get_proto_by_name(const char *);
extern int get_family_by_proto(enum sock_proto proto);
typedef enum {
 CFLAG_NONE = 0,
 CFLAG_ONLY_STATS,
 CFLAG_BOTH
} cflag_t;
extern cflag_t cflag;
extern _Bool Tflag;
extern int Tflag_scale;
extern int Tflag_width;
extern _Bool iflag;
extern _Bool count_wallclock;
struct path_set_item {
 const char *path;
};
extern struct path_set {
 struct path_set_item *paths_selected;
 size_t num_selected;
 size_t size;
} global_path_set;
enum xflag_opts {
 HEXSTR_NONE,
 HEXSTR_NON_ASCII,
 HEXSTR_ALL,
 HEXSTR_NON_ASCII_CHARS,
 NUM_HEXSTR_OPTS
};
extern unsigned xflag;
extern _Bool followfork;
extern _Bool output_separately;
extern _Bool stack_trace_enabled;
extern unsigned ptrace_setoptions;
extern unsigned max_strlen;
extern unsigned os_release;
extern int read_int_from_file(const char *, int *);
extern void set_sortby(const char *);
extern int set_overhead(const char *);
extern void set_count_summary_columns(const char *columns);
extern _Bool get_instruction_pointer(struct tcb *, kernel_ulong_t *);
extern _Bool get_stack_pointer(struct tcb *, kernel_ulong_t *);
extern void print_instruction_pointer(struct tcb *);
extern void print_syscall_number(struct tcb *);
extern void print_syscall_resume(struct tcb *tcp);
extern int syscall_entering_decode(struct tcb *);
extern int syscall_entering_trace(struct tcb *, unsigned int *);
extern void syscall_entering_finish(struct tcb *, int);
extern int syscall_exiting_decode(struct tcb *, struct timespec *);
extern int syscall_exiting_trace(struct tcb *, struct timespec *, int);
extern void syscall_exiting_finish(struct tcb *);
extern void count_syscall(struct tcb *, const struct timespec *);
extern void call_summary(FILE *);
extern void clear_regs(struct tcb *tcp);
extern int get_scno(struct tcb *);
extern kernel_ulong_t get_rt_sigframe_addr(struct tcb *);
extern const char *syscall_name_arch(kernel_ulong_t nr, unsigned int arch,
         const char **prefix);
extern kernel_long_t scno_by_name(const char *s, unsigned p,
      kernel_long_t start);
extern kernel_ulong_t shuffle_scno_pers(kernel_ulong_t scno, int pers);
static inline kernel_ulong_t
shuffle_scno(kernel_ulong_t scno)
{
 return shuffle_scno_pers(scno, current_personality);
}
extern void print_err(int64_t err, _Bool negated);
extern _Bool is_erestart(struct tcb *);
extern void temporarily_clear_syserror(struct tcb *);
extern void restore_cleared_syserror(struct tcb *);
extern void *get_tcb_priv_data(const struct tcb *);
extern int set_tcb_priv_data(struct tcb *, void *priv_data,
        void (*free_priv_data)(void *));
extern void free_tcb_priv_data(struct tcb *);
static inline unsigned long get_tcb_priv_ulong(const struct tcb *tcp)
{
 return (unsigned long) get_tcb_priv_data(tcp);
}
static inline int set_tcb_priv_ulong(struct tcb *tcp, unsigned long val)
{
 return set_tcb_priv_data(tcp, (void *) val, 0);
}
extern int
umoven(struct tcb *, kernel_ulong_t addr, unsigned int len, void *laddr);
extern unsigned int
upoken(struct tcb *, kernel_ulong_t addr, unsigned int len, void *laddr);
extern _Bool
tfetch_mem64(struct tcb *, uint64_t addr, unsigned int len, void *laddr);
static inline _Bool
tfetch_mem(struct tcb *tcp, const kernel_ulong_t addr,
    unsigned int len, void *laddr)
{
 return tfetch_mem64(tcp, addr, len, laddr);
}
extern _Bool
tfetch_mem64_ignore_syserror(struct tcb *, uint64_t addr,
        unsigned int len, void *laddr);
static inline _Bool
tfetch_mem_ignore_syserror(struct tcb *tcp, const kernel_ulong_t addr,
      unsigned int len, void *laddr)
{
 return tfetch_mem64_ignore_syserror(tcp, addr, len, laddr);
}
extern int
umoven_or_printaddr64(struct tcb *, uint64_t addr,
        unsigned int len, void *laddr);
static inline int
umoven_or_printaddr(struct tcb *tcp, const kernel_ulong_t addr,
      unsigned int len, void *laddr)
{
 return umoven_or_printaddr64(tcp, addr, len, laddr);
}
extern int
umoven_to_uint64_or_printaddr64(struct tcb *, uint64_t addr,
    unsigned int len, uint64_t *laddr);
static inline int
umoven_to_uint64_or_printaddr(struct tcb *tcp, const kernel_ulong_t addr,
         unsigned int len, uint64_t *laddr)
{
 return umoven_to_uint64_or_printaddr64(tcp, addr, len, laddr);
}
extern int
umoven_or_printaddr64_ignore_syserror(struct tcb *, uint64_t addr,
          unsigned int len, void *laddr);
static inline int
umoven_or_printaddr_ignore_syserror(struct tcb *tcp, const kernel_ulong_t addr,
        unsigned int len, void *laddr)
{
 return umoven_or_printaddr64_ignore_syserror(tcp, addr, len, laddr);
}
extern int
umovestr(struct tcb *, kernel_ulong_t addr, unsigned int len, char *laddr);
extern void invalidate_umove_cache(void);
extern int upeek(struct tcb *tcp, unsigned long, kernel_ulong_t *);
extern int upoke(struct tcb *tcp, unsigned long, kernel_ulong_t);
extern const char *signame(const int);
extern const char *sprintsigname(const int);
extern void pathtrace_select_set(const char *, struct path_set *);
extern _Bool pathtrace_match_set(struct tcb *, struct path_set *);
static inline void
pathtrace_select(const char *path)
{
 return pathtrace_select_set(path, &global_path_set);
}
static inline _Bool
pathtrace_match(struct tcb *tcp)
{
 return pathtrace_match_set(tcp, &global_path_set);
}
extern int get_proc_pid_fd_path(int proc_pid, int fd, char *buf,
    unsigned bufsize, _Bool *deleted);
extern int getfdpath_pid(pid_t pid, int fd, char *buf, unsigned bufsize,
    _Bool *deleted);
static inline int
getfdpath(struct tcb *tcp, int fd, char *buf, unsigned bufsize)
{
 return getfdpath_pid(tcp->pid, fd, buf, bufsize, ((void *)0));
}
extern unsigned long getfdinode(struct tcb *, int);
extern enum sock_proto getfdproto(struct tcb *, int);
extern const char *xlookup(const struct xlat *, const uint64_t);
extern const char *xlookup_le(const struct xlat *, uint64_t *);
struct dyxlat;
struct dyxlat *dyxlat_alloc(size_t nmemb);
void dyxlat_free(struct dyxlat *);
const struct xlat *dyxlat_get(const struct dyxlat *);
void dyxlat_add_pair(struct dyxlat *, uint64_t val, const char *str, size_t len);
const struct xlat *genl_families_xlat(struct tcb *tcp);
extern unsigned long get_pagesize(void);
extern int next_set_bit(const void *bit_array, unsigned cur_bit, unsigned size_bits);
static inline const char *
str_strip_prefix_len(const char *str, const char *prefix, size_t prefix_len)
{
 return strncmp(str, prefix, prefix_len) ? str : str + prefix_len;
}
_Static_assert((NUM_HEXSTR_OPTS - 1) <= ((0x3 << 8) >> 8),
       "xflag options do not fit into QUOTE_HEXSTR_MASK");
extern int string_quote(const char *, char *, unsigned int, unsigned int,
   const char *escape_chars);
extern int print_quoted_string_ex(const char *, unsigned int, unsigned int,
      const char *escape_chars);
extern int print_quoted_string(const char *, unsigned int, unsigned int);
extern int print_quoted_cstring(const char *, unsigned int);
extern unsigned int getllval(struct tcb *, unsigned long long *, unsigned int);
extern unsigned int print_arg_lld(struct tcb *, unsigned int);
extern unsigned int print_arg_llu(struct tcb *, unsigned int);
extern void printaddr64(uint64_t addr);
static inline void
printaddr(const kernel_ulong_t addr)
{
 printaddr64(addr);
}
extern enum xlat_style xlat_verbosity;
extern int printxvals_ex(uint64_t val, const char *dflt,
    enum xlat_style, const struct xlat *, ...)
 __attribute__((__sentinel__));
extern int sprintxval_ex(char *buf, size_t size, const struct xlat *,
    unsigned int val, const char *dflt, enum xlat_style);
static inline int
sprintxval(char *buf, size_t size, const struct xlat *xlat, unsigned int val,
    const char *dflt)
{
 return sprintxval_ex(buf, size, xlat, val, dflt, XLAT_STYLE_DEFAULT);
}
enum xlat_style_private_flag_bits {
 PAF_PRINT_INDICES_BIT = (2 + 2) + 1,
 PAF_ARRAY_TRUNCATED_BIT,
 PXF_DEFAULT_STR_BIT,
 SPFF_AUXSTR_MODE_BIT,
};
enum xlat_style_private_flags {
 PAF_PRINT_INDICES = (1U << (PAF_PRINT_INDICES_BIT)),
 PAF_ARRAY_TRUNCATED = (1U << (PAF_ARRAY_TRUNCATED_BIT)),
 PXF_DEFAULT_STR = (1U << (PXF_DEFAULT_STR_BIT)),
 SPFF_AUXSTR_MODE = (1U << (SPFF_AUXSTR_MODE_BIT)),
};
extern void print_xlat_ex(uint64_t val, const char *str, uint32_t style);
extern int printargs(struct tcb *);
extern int printargs_u(struct tcb *);
extern int printargs_d(struct tcb *);
extern int printflags_ex(uint64_t flags, const char *dflt,
    enum xlat_style, const struct xlat *, ...)
 __attribute__((__sentinel__));
extern const char *sprintflags_ex(const char *prefix, const struct xlat *,
      uint64_t flags, char sep, enum xlat_style);
static inline const char *
sprintflags(const char *prefix, const struct xlat *xlat, uint64_t flags)
{
 return sprintflags_ex(prefix, xlat, flags, '\0', XLAT_STYLE_DEFAULT);
}
extern const char *sprinttime(long long sec);
extern const char *sprinttime_nsec(long long sec, unsigned long long nsec);
extern const char *sprinttime_usec(long long sec, unsigned long long usec);
extern void print_mac_addr(const char *prefix,
      const uint8_t addr[], size_t size);
extern void print_hwaddr(const char *prefix,
    const uint8_t addr[], size_t size, uint32_t devtype);
extern void print_uuid(const unsigned char *uuid);
extern void print_symbolic_mode_t(unsigned int);
extern void print_numeric_umode_t(unsigned short);
extern void print_numeric_ll_umode_t(unsigned long long);
extern void print_dev_t(unsigned long long dev);
extern void print_kernel_version(unsigned long version);
extern void print_abnormal_hi(kernel_ulong_t);
extern void print_ioprio(unsigned int ioprio);
extern _Bool print_int_array_member(struct tcb *, void *elem_buf,
       size_t elem_size, void *data);
extern _Bool print_uint_array_member(struct tcb *, void *elem_buf,
        size_t elem_size, void *data);
extern _Bool print_xint_array_member(struct tcb *, void *elem_buf,
        size_t elem_size, void *data);
extern _Bool print_fd_array_member(struct tcb *, void *elem_buf,
      size_t elem_size, void *data);
typedef _Bool (*tfetch_mem_fn)(struct tcb *, kernel_ulong_t addr,
         unsigned int size, void *dest);
typedef _Bool (*print_fn)(struct tcb *, void *elem_buf,
    size_t elem_size, void *opaque_data);
typedef int (*print_obj_by_addr_fn)(struct tcb *, kernel_ulong_t);
typedef const char * (*sprint_obj_by_addr_fn)(struct tcb *, kernel_ulong_t);
typedef void (*print_obj_by_addr_size_fn)(struct tcb *,
       kernel_ulong_t addr,
       kernel_ulong_t size,
       void *opaque_data);
extern _Bool
print_array_ex(struct tcb *,
        kernel_ulong_t start_addr,
        size_t nmemb,
        void *elem_buf,
        size_t elem_size,
        tfetch_mem_fn tfetch_mem_func,
        print_fn print_func,
        void *opaque_data,
        unsigned int flags,
        const struct xlat *index_xlat,
        const char *index_dflt);
static inline _Bool
print_array(struct tcb *const tcp,
     const kernel_ulong_t start_addr,
     const size_t nmemb,
     void *const elem_buf,
     const size_t elem_size,
     tfetch_mem_fn tfetch_mem_func,
     print_fn print_func,
     void *const opaque_data)
{
 return print_array_ex(tcp, start_addr, nmemb, elem_buf, elem_size,
         tfetch_mem_func, print_func, opaque_data,
         0, ((void *)0), ((void *)0));
}
static inline _Bool
print_local_array_ex(struct tcb *tcp,
       const void *start_addr,
       const size_t nmemb,
       const size_t elem_size,
       print_fn print_func,
       void *const opaque_data,
       unsigned int flags,
       const struct xlat *index_xlat,
       const char *index_dflt)
{
 return print_array_ex(tcp, (uintptr_t) start_addr, nmemb,
         ((void *)0), elem_size, ((void *)0), print_func,
         opaque_data, flags, index_xlat, index_dflt);
}
extern kernel_ulong_t *
fetch_indirect_syscall_args(struct tcb *, kernel_ulong_t addr, unsigned int n_args);
extern void pidns_init(void);
extern int get_proc_pid(int pid);
extern int translate_pid(struct tcb *, int dest_id, enum pid_type type,
      int *proc_pid_ptr);
extern void
dumpiov_in_msghdr(struct tcb *, kernel_ulong_t addr, kernel_ulong_t data_size);
extern void
dumpiov_in_mmsghdr(struct tcb *, kernel_ulong_t addr);
extern void
dumpiov_upto(struct tcb *, int len, kernel_ulong_t addr, kernel_ulong_t data_size);
extern void
dumpstr(struct tcb *, kernel_ulong_t addr, kernel_ulong_t len);
extern int
printstr_ex(struct tcb *, kernel_ulong_t addr, kernel_ulong_t len,
     unsigned int user_style);
extern _Bool print_nonzero_bytes(struct tcb *const tcp,
    void (*prefix_fun)(void),
    const kernel_ulong_t start_addr,
    const unsigned int start_offs,
    const unsigned int total_len,
    const unsigned int style);
extern int
printpathn(struct tcb *, kernel_ulong_t addr, unsigned int n);
extern int
printpath(struct tcb *, kernel_ulong_t addr);
extern pid_t pidfd_get_pid(pid_t pid_of_fd, int fd);
extern void printfd_pid(struct tcb *tcp, pid_t pid, int fd);
static inline void
printfd(struct tcb *tcp, int fd)
{
 printfd_pid(tcp, tcp->pid, fd);
}
extern const char *pid_to_str(pid_t pid);
extern size_t proc_status_get_id_list(int proc_pid,
          int *id_buf, size_t id_buf_size,
          const char *str, size_t str_size);
extern void printfd_pid_tracee_ns(struct tcb *tcp, pid_t pid, int fd);
extern void printpid(struct tcb *, int pid, enum pid_type type);
extern void printpid_tgid_pgid(struct tcb *, int pid);
extern void print_sockaddr(struct tcb *, const void *sa, int len);
extern _Bool
print_inet_addr(int af, const void *addr, unsigned int len, const char *var_name);
extern _Bool
decode_inet_addr(struct tcb *, kernel_ulong_t addr,
   unsigned int len, int family, const char *var_name);
extern void print_ax25_addr(const void *addr);
extern void print_x25_addr(const void *addr);
extern const char *get_sockaddr_by_inode(struct tcb *, int fd, unsigned long inode);
extern void print_dirfd(struct tcb *, int);
extern int
decode_sockaddr(struct tcb *, kernel_ulong_t addr, int addrlen);
extern void printuid(const unsigned int);
extern void
print_sigset_addr_len(struct tcb *, kernel_ulong_t addr, kernel_ulong_t len);
extern void
print_sigset_addr(struct tcb *, kernel_ulong_t addr);
extern const char *sprintsigmask_n(const char *, const void *, unsigned int);
extern void printsignal(int);
extern void
tprint_iov_upto(struct tcb *, kernel_ulong_t len, kernel_ulong_t addr,
  kernel_ulong_t data_size, print_obj_by_addr_size_fn,
  void *opaque_data);
extern void
iov_decode_addr(struct tcb *, kernel_ulong_t addr, kernel_ulong_t size,
  void *opaque_data);
extern void
iov_decode_str(struct tcb *, kernel_ulong_t addr, kernel_ulong_t size,
        void *opaque_data);
extern void
decode_netlink(struct tcb *, int fd, kernel_ulong_t addr, kernel_ulong_t len);
extern void tprint_open_modes(unsigned int);
extern const char *sprint_open_modes(unsigned int);
extern void
decode_seccomp_fprog(struct tcb *, kernel_ulong_t addr);
extern void
print_seccomp_fprog(struct tcb *, kernel_ulong_t addr, unsigned short len);
extern void
decode_sock_fprog(struct tcb *, kernel_ulong_t addr);
extern void
print_sock_fprog(struct tcb *, kernel_ulong_t addr, unsigned short len);
struct strace_stat;
extern void print_struct_stat(struct tcb *, const struct strace_stat *const st);
struct strace_statfs;
struct strace_keyctl_kdf_params;
extern void
print_struct_statfs(struct tcb *, kernel_ulong_t addr);
extern void
print_struct_statfs64(struct tcb *, kernel_ulong_t addr, kernel_ulong_t size);
extern int
fetch_perf_event_attr(struct tcb *const tcp, const kernel_ulong_t addr);
extern void
print_perf_event_attr(struct tcb *const tcp, const kernel_ulong_t addr);
extern const char *get_ifname(const unsigned int ifindex);
extern void print_ifindex(unsigned int);
struct tcpvegas_info;
extern void print_tcpvegas_info(struct tcb *tcp,
    const struct tcpvegas_info *vegas,
    unsigned int len);
struct tcp_dctcp_info;
extern void print_tcp_dctcp_info(struct tcb *tcp,
     const struct tcp_dctcp_info *dctcp,
     unsigned int len);
struct tcp_bbr_info;
extern void print_tcp_bbr_info(struct tcb *tcp, const struct tcp_bbr_info *bbr,
          unsigned int len);
extern void print_bpf_filter_code(const uint16_t code, _Bool extended);
extern void print_affinitylist(struct tcb *const tcp, const kernel_ulong_t addr,
          const unsigned int len);
extern void qualify(const char *);
extern void qualify_trace(const char *);
extern void qualify_abbrev(const char *);
extern void qualify_verbose(const char *);
extern void qualify_raw(const char *);
extern void qualify_signals(const char *);
extern void qualify_status(const char *);
extern void qualify_quiet(const char *);
extern void qualify_decode_fd(const char *);
extern void qualify_decode_pid(const char *);
extern void qualify_read(const char *);
extern void qualify_write(const char *);
extern void qualify_fault(const char *);
extern void qualify_inject(const char *);
extern void qualify_kvm(const char *);
extern unsigned int qual_flags(const unsigned int);
extern int counter_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int dm_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int evdev_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int fs_0x94_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int fs_f_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int fs_x_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int gpio_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int inotify_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int kd_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int kvm_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int lirc_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int nbd_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int nsfs_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int ptp_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int random_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int seccomp_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int scsi_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int tee_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int term_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int ubi_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int uffdio_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int watchdog_ioctl(struct tcb *, unsigned int request, kernel_ulong_t arg);
extern int decode_sg_io_v4(struct tcb *, const kernel_ulong_t arg);
extern void print_evdev_ff_type(const kernel_ulong_t val);
struct nlmsghdr;
typedef _Bool (*netlink_decoder_t)(struct tcb *, const struct nlmsghdr *,
      kernel_ulong_t addr, unsigned int len);
extern _Bool decode_netlink_crypto(struct tcb *, const struct nlmsghdr *, kernel_ulong_t addr, unsigned int len);
extern _Bool decode_netlink_netfilter(struct tcb *, const struct nlmsghdr *, kernel_ulong_t addr, unsigned int len);
extern _Bool decode_netlink_route(struct tcb *, const struct nlmsghdr *, kernel_ulong_t addr, unsigned int len);
extern _Bool decode_netlink_selinux(struct tcb *, const struct nlmsghdr *, kernel_ulong_t addr, unsigned int len);
extern _Bool decode_netlink_sock_diag(struct tcb *, const struct nlmsghdr *, kernel_ulong_t addr, unsigned int len);
extern void
decode_netlink_kobject_uevent(struct tcb *, kernel_ulong_t addr,
         kernel_ulong_t len);
enum find_xlat_flag_bits {
 FXL_CASE_SENSITIVE_BIT,
};
enum find_xlat_flags {
 FXL_CASE_SENSITIVE = (1U << (FXL_CASE_SENSITIVE_BIT)),
};
extern const struct xlat_data *find_xlat_val_ex(const struct xlat_data *items,
      const char *s, size_t num_items,
      unsigned int flags);
extern uint64_t find_arg_val_(const char *arg, const struct xlat_data *strs,
         size_t strs_size, uint64_t default_val,
         uint64_t not_found);
extern int str2timescale_ex(const char *arg, int empty_dflt, int null_dflt,
       int *width);
extern int ts_nz(const struct timespec *);
extern int ts_cmp(const struct timespec *, const struct timespec *);
extern double ts_float(const struct timespec *);
extern void ts_add(struct timespec *, const struct timespec *, const struct timespec *);
extern void ts_sub(struct timespec *, const struct timespec *, const struct timespec *);
extern void ts_div(struct timespec *, const struct timespec *, uint64_t);
extern const struct timespec *ts_min(const struct timespec *, const struct timespec *);
extern const struct timespec *ts_max(const struct timespec *, const struct timespec *);
extern int parse_ts(const char *s, struct timespec *t);
extern void print_clock_t(uint64_t val);
extern void unwind_init(void);
extern void unwind_tcb_init(struct tcb *);
extern void unwind_tcb_fin(struct tcb *);
extern void unwind_tcb_print(struct tcb *);
extern void unwind_tcb_capture(struct tcb *);
extern void kvm_run_structure_decoder_init(void);
extern void kvm_vcpu_info_free(struct tcb *);
extern void maybe_load_task_comm(struct tcb *tcp);
extern void print_pid_comm(int pid);
static inline int
printstrn(struct tcb *tcp, kernel_ulong_t addr, kernel_ulong_t len)
{
 return printstr_ex(tcp, addr, len, 0);
}
static inline int
printstr(struct tcb *tcp, kernel_ulong_t addr)
{
 return printstr_ex(tcp, addr, -1, 0x01);
}
static inline int
printflags64(const struct xlat *x, uint64_t flags, const char *dflt)
{
 return printflags_ex(flags, dflt, XLAT_STYLE_DEFAULT, x, ((void *)0));
}
static inline int
printflags(const struct xlat *x, unsigned int flags, const char *dflt)
{
 return printflags64(x, flags, dflt);
}
static inline int
printxval64(const struct xlat *x, const uint64_t val, const char *dflt)
{
 return printxvals_ex((val), (dflt), XLAT_STYLE_DEFAULT, x, ((void *)0));
}
static inline int
printxval(const struct xlat *x, const unsigned int val, const char *dflt)
{
 return printxvals_ex((val), (dflt), XLAT_STYLE_DEFAULT, x, ((void *)0));
}
static inline int
printxval64_u(const struct xlat *x, const uint64_t val, const char *dflt)
{
 return printxvals_ex(val, dflt, XLAT_STYLE_FMT_U, x, ((void *)0));
}
static inline int
printxval_u(const struct xlat *x, const unsigned int val, const char *dflt)
{
 return printxvals_ex(val, dflt, XLAT_STYLE_FMT_U, x, ((void *)0));
}
static inline int
printxval64_d(const struct xlat *x, const int64_t val, const char *dflt)
{
 return printxvals_ex(val, dflt, XLAT_STYLE_FMT_D, x, ((void *)0));
}
static inline int
printxval_d(const struct xlat *x, const int val, const char *dflt)
{
 return printxvals_ex(val, dflt, XLAT_STYLE_FMT_D, x, ((void *)0));
}
static inline void
tprint_iov(struct tcb *tcp, kernel_ulong_t len, kernel_ulong_t addr,
    print_obj_by_addr_size_fn print_func)
{
 tprint_iov_upto(tcp, len, addr, -1, print_func, ((void *)0));
}
extern _Bool print_timespec32_data_size(const void *arg, size_t size);
extern _Bool print_timespec32_array_data_size(const void *arg,
          unsigned int nmemb,
          size_t size);
extern int print_timespec32(struct tcb *, kernel_ulong_t);
extern const char *sprint_timespec32(struct tcb *, kernel_ulong_t);
extern int print_timespec32_utime_pair(struct tcb *, kernel_ulong_t);
extern int print_itimerspec32(struct tcb *, kernel_ulong_t);
extern int print_timex32(struct tcb *, kernel_ulong_t);
extern _Bool print_timespec64_data_size(const void *arg, size_t size);
extern _Bool print_timespec64_array_data_size(const void *arg,
          unsigned int nmemb,
          size_t size);
extern int print_timespec64(struct tcb *, kernel_ulong_t);
extern const char *sprint_timespec64(struct tcb *, kernel_ulong_t);
extern int print_timespec64_utime_pair(struct tcb *, kernel_ulong_t);
extern int print_itimerspec64(struct tcb *, kernel_ulong_t);
extern _Bool print_timeval64_data_size(const void *arg, size_t size);
extern int print_timex64(struct tcb *, kernel_ulong_t);
enum user_desc_print_filter {
 USER_DESC_ENTERING = 1,
 USER_DESC_EXITING = 2,
 USER_DESC_BOTH = USER_DESC_ENTERING | USER_DESC_EXITING,
};
extern void print_user_desc(struct tcb *, kernel_ulong_t addr,
       enum user_desc_print_filter filter);
extern struct tcb *printing_tcp;
extern void printleader(struct tcb *);
extern void line_ended(void);
extern void tabto(void);
extern void tprintf(const char *fmt, ...) __attribute__((__format__ (printf, 1, 2)));
extern void tprints(const char *str);
extern void tprintf_comment(const char *fmt, ...) __attribute__((__format__ (printf, 1, 2)));
extern void tprints_comment(const char *str);
extern FILE *strace_open_memstream(struct tcb *tcp);
extern void strace_close_memstream(struct tcb *tcp, _Bool publish);
static inline void
printaddr_comment(const kernel_ulong_t addr)
{
 tprintf_comment("%#llx", (unsigned long long) addr);
}
extern _Bool printnum_short(struct tcb *, kernel_ulong_t addr, const char *fmt) __attribute__((__format__ (printf, 3, 0)));
extern _Bool printnum_int(struct tcb *, kernel_ulong_t addr, const char *fmt) __attribute__((__format__ (printf, 3, 0)));
extern _Bool printnum_int64(struct tcb *, kernel_ulong_t addr, const char *fmt) __attribute__((__format__ (printf, 3, 0)));
extern _Bool printnum_addr_int(struct tcb *, kernel_ulong_t addr);
extern _Bool printnum_addr_int64(struct tcb *, kernel_ulong_t addr);
extern _Bool
printnum_fd(struct tcb *, kernel_ulong_t addr);
extern _Bool
printnum_pid(struct tcb *const tcp, const kernel_ulong_t addr, enum pid_type type);
static inline _Bool
printnum_slong(struct tcb *tcp, kernel_ulong_t addr)
{
 return ((current_wordsize > sizeof(uint32_t)) ? (printnum_int64)(tcp, addr, ((current_wordsize > sizeof(uint32_t)) ? ("%" "l" "d") : ("%d"))) : (printnum_int)(tcp, addr, ((current_wordsize > sizeof(uint32_t)) ? ("%" "l" "d") : ("%d"))));
}
static inline _Bool
printnum_ulong(struct tcb *tcp, kernel_ulong_t addr)
{
 return ((current_wordsize > sizeof(uint32_t)) ? (printnum_int64)(tcp, addr, ((current_wordsize > sizeof(uint32_t)) ? ("%" "l" "u") : ("%u"))) : (printnum_int)(tcp, addr, ((current_wordsize > sizeof(uint32_t)) ? ("%" "l" "u") : ("%u"))));
}
static inline _Bool
printnum_ptr(struct tcb *tcp, kernel_ulong_t addr)
{
 return ((current_wordsize > sizeof(uint32_t)) ? (printnum_addr_int64)(tcp, addr) : (printnum_addr_int)(tcp, addr));
}
static inline _Bool
printnum_kptr(struct tcb *tcp, kernel_ulong_t addr)
{
 return ((current_klongsize > sizeof(uint32_t)) ? (printnum_addr_int64)(tcp, addr) : (printnum_addr_int)(tcp, addr));
}
extern _Bool printpair_int(struct tcb *, kernel_ulong_t addr, const char *fmt) __attribute__((__format__ (printf, 3, 0)));
extern _Bool printpair_int64(struct tcb *, kernel_ulong_t addr, const char *fmt) __attribute__((__format__ (printf, 3, 0)));
static inline kernel_long_t
truncate_klong_to_current_wordsize(const kernel_long_t v)
{
 if (current_wordsize < sizeof(v)) {
  return (int) v;
 } else
 {
  return v;
 }
}
static inline kernel_ulong_t
truncate_kulong_to_current_wordsize(const kernel_ulong_t v)
{
 if (current_wordsize < sizeof(v)) {
  return (unsigned int) v;
 } else
 {
  return v;
 }
}
static inline kernel_long_t
truncate_klong_to_current_klongsize(const kernel_long_t v)
{
 if (current_klongsize < sizeof(v)) {
  return (int) v;
 } else
 {
  return v;
 }
}
static inline kernel_ulong_t
truncate_kulong_to_current_klongsize(const kernel_ulong_t v)
{
 if (current_klongsize < sizeof(v)) {
  return (unsigned int) v;
 } else
 {
  return v;
 }
}
static inline unsigned int
popcount32(const uint32_t *a, unsigned int size)
{
 unsigned int count = 0;
 for (; size; ++a, --size) {
  uint32_t x = *a;
  count += __builtin_popcount(x);
 }
 return count;
}
extern const char *const errnoent[];
extern const char *const signalent[];
extern const unsigned int nerrnos;
extern const unsigned int nsignals;
extern const struct_sysent sysent0[];
extern const struct_ioctlent ioctlent0[];
extern const char *const personality_names[];
extern const struct_sysent *sysent;
extern const struct_ioctlent *ioctlent;
extern unsigned nsyscalls;
extern unsigned nioctlents;
extern const unsigned int nsyscall_vec[3];
extern const struct_sysent *const sysent_vec[3];
extern struct inject_opts *inject_vec[3];
struct audit_arch_t {
 unsigned int arch;
 unsigned int flag;
};
extern const struct audit_arch_t audit_arch_vec[3];
static inline _Bool
scno_in_range(kernel_ulong_t scno)
{
 return scno < nsyscalls;
}
static inline _Bool
scno_pers_in_range(kernel_ulong_t scno, unsigned int pers)
{
 return scno < nsyscall_vec[pers];
}
static inline _Bool
scno_is_valid(kernel_ulong_t scno)
{
 return scno_in_range(scno)
        && sysent[scno].sys_func
        && !(sysent[scno].sys_flags & 000002000);
}
static inline _Bool
scno_pers_is_valid(kernel_ulong_t scno, unsigned int pers)
{
 return scno_pers_in_range(scno, pers)
        && sysent_vec[pers][scno].sys_func
        && !(sysent_vec[pers][scno].sys_flags & 000002000);
}
static inline unsigned int
ilog2_64(uint64_t val)
{
 unsigned int ret = 0;
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (5))) - 1)) << (5); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (4))) - 1)) << (4); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (3))) - 1)) << (3); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (2))) - 1)) << (2); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (1))) - 1)) << (1); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (0))) - 1)) << (0); (val) >>= shift_; (ret) |= shift_; } while (0);
 return ret;
}
static inline unsigned int
ilog2_32(uint32_t val)
{
 unsigned int ret = 0;
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (4))) - 1)) << (4); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (3))) - 1)) << (3); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (2))) - 1)) << (2); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (1))) - 1)) << (1); (val) >>= shift_; (ret) |= shift_; } while (0);
 do { typeof(ret) shift_ = ((val) > ((((typeof(val)) 1) << (1 << (0))) - 1)) << (0); (val) >>= shift_; (ret) |= shift_; } while (0);
 return ret;
}
static inline void
tprint_struct_begin(void)
{
 tprints("{");
}
static inline void
tprint_struct_next(void)
{
 tprints(", ");
}
static inline void
tprint_struct_end(void)
{
 tprints("}");
}
static inline void
tprint_union_begin(void)
{
 tprints("{");
}
static inline void
tprint_union_next(void)
{
 tprints(", ");
}
static inline void
tprint_union_end(void)
{
 tprints("}");
}
static inline void
tprint_array_begin(void)
{
 tprints("[");
}
static inline void
tprint_array_next(void)
{
 tprints(", ");
}
static inline void
tprint_array_end(void)
{
 tprints("]");
}
static inline void
tprint_array_index_begin(void)
{
 tprints("[");
}
static inline void
tprint_array_index_end(void)
{
 tprints("] = ");
}
static inline void
tprint_arg_next(void)
{
 tprints(", ");
}
static inline void
tprint_arg_end(void)
{
 tprints(")");
}
static inline void
tprint_bitset_begin(void)
{
 tprints("[");
}
static inline void
tprint_bitset_next(void)
{
 tprints(" ");
}
static inline void
tprint_bitset_end(void)
{
 tprints("]");
}
static inline void
tprint_comment_begin(void)
{
 tprints(" /* ");
}
static inline void
tprint_comment_end(void)
{
 tprints(" */");
}
static inline void
tprint_indirect_begin(void)
{
 tprints("[");
}
static inline void
tprint_indirect_end(void)
{
 tprints("]");
}
static inline void
tprint_more_data_follows(void)
{
 tprints("...");
}
static inline void
tprint_value_changed(void)
{
 tprints(" => ");
}
static inline void
tprint_alternative_value(void)
{
 tprints(" or ");
}
static inline void
tprint_unavailable(void)
{
 tprints("???");
}
static inline void
tprint_shift(void)
{
 tprints("<<");
}
static inline void
tprint_or(void)
{
 tprints("|");
}
static inline void
tprints_field_name(const char *name)
{
 tprintf("%s=", name);
}
static inline void
tprints_arg_name(const char *name)
{
 tprintf("%s=", name);
}
static inline void
tprints_arg_begin(const char *name)
{
 tprintf("%s(", name);
}

enum __ptrace_request
{
  PTRACE_TRACEME = 0,
  PTRACE_PEEKTEXT = 1,
  PTRACE_PEEKDATA = 2,
  PTRACE_PEEKUSER = 3,
  PTRACE_POKETEXT = 4,
  PTRACE_POKEDATA = 5,
  PTRACE_POKEUSER = 6,
  PTRACE_CONT = 7,
  PTRACE_KILL = 8,
  PTRACE_SINGLESTEP = 9,
  PTRACE_GETREGS = 12,
  PTRACE_SETREGS = 13,
  PTRACE_GETFPREGS = 14,
  PTRACE_SETFPREGS = 15,
  PTRACE_ATTACH = 16,
  PTRACE_DETACH = 17,
  PTRACE_GETFPXREGS = 18,
  PTRACE_SETFPXREGS = 19,
  PTRACE_SYSCALL = 24,
  PTRACE_GET_THREAD_AREA = 25,
  PTRACE_SET_THREAD_AREA = 26,
  PTRACE_ARCH_PRCTL = 30,
  PTRACE_SYSEMU = 31,
  PTRACE_SYSEMU_SINGLESTEP = 32,
  PTRACE_SINGLEBLOCK = 33,
  PTRACE_SETOPTIONS = 0x4200,
  PTRACE_GETEVENTMSG = 0x4201,
  PTRACE_GETSIGINFO = 0x4202,
  PTRACE_SETSIGINFO = 0x4203,
  PTRACE_GETREGSET = 0x4204,
  PTRACE_SETREGSET = 0x4205,
  PTRACE_SEIZE = 0x4206,
  PTRACE_INTERRUPT = 0x4207,
  PTRACE_LISTEN = 0x4208,
  PTRACE_PEEKSIGINFO = 0x4209,
  PTRACE_GETSIGMASK = 0x420a,
  PTRACE_SETSIGMASK = 0x420b,
  PTRACE_SECCOMP_GET_FILTER = 0x420c,
  PTRACE_SECCOMP_GET_METADATA = 0x420d
};
enum __ptrace_setoptions
{
  PTRACE_O_TRACESYSGOOD = 0x00000001,
  PTRACE_O_TRACEFORK = 0x00000002,
  PTRACE_O_TRACEVFORK = 0x00000004,
  PTRACE_O_TRACECLONE = 0x00000008,
  PTRACE_O_TRACEEXEC = 0x00000010,
  PTRACE_O_TRACEVFORKDONE = 0x00000020,
  PTRACE_O_TRACEEXIT = 0x00000040,
  PTRACE_O_TRACESECCOMP = 0x00000080,
  PTRACE_O_EXITKILL = 0x00100000,
  PTRACE_O_SUSPEND_SECCOMP = 0x00200000,
  PTRACE_O_MASK = 0x003000ff
};
enum __ptrace_eventcodes
{
  PTRACE_EVENT_FORK = 1,
  PTRACE_EVENT_VFORK = 2,
  PTRACE_EVENT_CLONE = 3,
  PTRACE_EVENT_EXEC = 4,
  PTRACE_EVENT_VFORK_DONE = 5,
  PTRACE_EVENT_EXIT = 6,
  PTRACE_EVENT_SECCOMP = 7,
  PTRACE_EVENT_STOP = 128
};
struct __ptrace_peeksiginfo_args
{
  __uint64_t off;
  __uint32_t flags;
  __int32_t nr;
};
enum __ptrace_peeksiginfo_flags
{
  PTRACE_PEEKSIGINFO_SHARED = (1 << 0)
};
struct __ptrace_seccomp_metadata
{
  __uint64_t filter_off;
  __uint64_t flags;
};
extern long int ptrace (enum __ptrace_request __request, ...) __attribute__ ((__nothrow__ , __leaf__));

typedef __signed__ char __s8;
typedef unsigned char __u8;
typedef __signed__ short __s16;
typedef unsigned short __u16;
typedef __signed__ int __s32;
typedef unsigned int __u32;
__extension__ typedef __signed__ long long __s64;
__extension__ typedef unsigned long long __u64;
typedef struct {
 unsigned long fds_bits[1024 / (8 * sizeof(long))];
} __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int);
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
typedef unsigned __poll_t;
struct ptrace_peeksiginfo_args {
 __u64 off;
 __u32 flags;
 __s32 nr;
};
struct pt_regs {
 unsigned long r15;
 unsigned long r14;
 unsigned long r13;
 unsigned long r12;
 unsigned long rbp;
 unsigned long rbx;
 unsigned long r11;
 unsigned long r10;
 unsigned long r9;
 unsigned long r8;
 unsigned long rax;
 unsigned long rcx;
 unsigned long rdx;
 unsigned long rsi;
 unsigned long rdi;
 unsigned long orig_rax;
 unsigned long rip;
 unsigned long cs;
 unsigned long eflags;
 unsigned long rsp;
 unsigned long ss;
};
struct ptrace_syscall_info {
 uint8_t op;
 uint8_t pad[3];
 uint32_t arch;
 uint64_t instruction_pointer;
 uint64_t stack_pointer;
 union {
  struct {
   uint64_t nr;
   uint64_t args[6];
  } entry;
  struct {
   int64_t rval;
   uint8_t is_error;
  } exit;
  struct {
   uint64_t nr;
   uint64_t args[6];
   uint32_t ret_data;
  } seccomp;
 };
};
typedef struct ptrace_syscall_info struct_ptrace_syscall_info;
typedef struct {
 kernel_ulong_t r15;
 kernel_ulong_t r14;
 kernel_ulong_t r13;
 kernel_ulong_t r12;
 kernel_ulong_t rbp;
 kernel_ulong_t rbx;
 kernel_ulong_t r11;
 kernel_ulong_t r10;
 kernel_ulong_t r9;
 kernel_ulong_t r8;
 kernel_ulong_t rax;
 kernel_ulong_t rcx;
 kernel_ulong_t rdx;
 kernel_ulong_t rsi;
 kernel_ulong_t rdi;
 kernel_ulong_t orig_rax;
 kernel_ulong_t rip;
 kernel_ulong_t cs;
 kernel_ulong_t eflags;
 kernel_ulong_t rsp;
 kernel_ulong_t ss;
 kernel_ulong_t fs_base;
 kernel_ulong_t gs_base;
 kernel_ulong_t ds;
 kernel_ulong_t es;
 kernel_ulong_t fs;
 kernel_ulong_t gs;
} struct_prstatus_regset;
typedef struct {
 uint16_t cwd;
 uint16_t swd;
 uint16_t ftw;
 uint16_t fop;
 uint64_t rip;
 uint64_t rdp;
 uint32_t mxcsr;
 uint32_t mxcr_mask;
 uint32_t st_space[32];
 uint32_t xmm_space[64];
 uint32_t padding[24];
} struct_fpregset;
static void
arch_decode_prstatus_regset(struct tcb *const tcp,
       const kernel_ulong_t addr,
       const kernel_ulong_t size)
{
 struct_prstatus_regset regs;
 const size_t fetch_size = (((sizeof(regs)) < (size)) ? (sizeof(regs)) : (size));
 if (!size || size & 7) {
  printaddr(addr);
 } else if (!umoven_or_printaddr(tcp, addr, fetch_size, &regs)) {
  tprint_struct_begin();
  do { tprints_field_name("r15"); tprintf("%#llx", (sizeof((regs).r15) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r15) : sizeof((regs).r15) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r15) : sizeof((regs).r15) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r15) : sizeof((regs).r15) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r15) : (unsigned long long) ((regs).r15))); } while (0);
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r14)) {
   tprint_struct_next();
   do { tprints_field_name("r14"); tprintf("%#llx", (sizeof((regs).r14) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r14) : sizeof((regs).r14) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r14) : sizeof((regs).r14) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r14) : sizeof((regs).r14) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r14) : (unsigned long long) ((regs).r14))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r13)) {
   tprint_struct_next();
   do { tprints_field_name("r13"); tprintf("%#llx", (sizeof((regs).r13) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r13) : sizeof((regs).r13) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r13) : sizeof((regs).r13) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r13) : sizeof((regs).r13) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r13) : (unsigned long long) ((regs).r13))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r12)) {
   tprint_struct_next();
   do { tprints_field_name("r12"); tprintf("%#llx", (sizeof((regs).r12) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r12) : sizeof((regs).r12) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r12) : sizeof((regs).r12) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r12) : sizeof((regs).r12) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r12) : (unsigned long long) ((regs).r12))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rbp)) {
   tprint_struct_next();
   do { tprints_field_name("rbp"); tprintf("%#llx", (sizeof((regs).rbp) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rbp) : sizeof((regs).rbp) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rbp) : sizeof((regs).rbp) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rbp) : sizeof((regs).rbp) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rbp) : (unsigned long long) ((regs).rbp))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rbx)) {
   tprint_struct_next();
   do { tprints_field_name("rbx"); tprintf("%#llx", (sizeof((regs).rbx) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rbx) : sizeof((regs).rbx) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rbx) : sizeof((regs).rbx) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rbx) : sizeof((regs).rbx) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rbx) : (unsigned long long) ((regs).rbx))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r11)) {
   tprint_struct_next();
   do { tprints_field_name("r11"); tprintf("%#llx", (sizeof((regs).r11) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r11) : sizeof((regs).r11) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r11) : sizeof((regs).r11) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r11) : sizeof((regs).r11) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r11) : (unsigned long long) ((regs).r11))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r10)) {
   tprint_struct_next();
   do { tprints_field_name("r10"); tprintf("%#llx", (sizeof((regs).r10) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r10) : sizeof((regs).r10) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r10) : sizeof((regs).r10) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r10) : sizeof((regs).r10) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r10) : (unsigned long long) ((regs).r10))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r9)) {
   tprint_struct_next();
   do { tprints_field_name("r9"); tprintf("%#llx", (sizeof((regs).r9) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r9) : sizeof((regs).r9) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r9) : sizeof((regs).r9) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r9) : sizeof((regs).r9) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r9) : (unsigned long long) ((regs).r9))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, r8)) {
   tprint_struct_next();
   do { tprints_field_name("r8"); tprintf("%#llx", (sizeof((regs).r8) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).r8) : sizeof((regs).r8) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).r8) : sizeof((regs).r8) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).r8) : sizeof((regs).r8) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).r8) : (unsigned long long) ((regs).r8))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rax)) {
   tprint_struct_next();
   do { tprints_field_name("rax"); tprintf("%#llx", (sizeof((regs).rax) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rax) : sizeof((regs).rax) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rax) : sizeof((regs).rax) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rax) : sizeof((regs).rax) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rax) : (unsigned long long) ((regs).rax))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rcx)) {
   tprint_struct_next();
   do { tprints_field_name("rcx"); tprintf("%#llx", (sizeof((regs).rcx) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rcx) : sizeof((regs).rcx) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rcx) : sizeof((regs).rcx) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rcx) : sizeof((regs).rcx) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rcx) : (unsigned long long) ((regs).rcx))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rdx)) {
   tprint_struct_next();
   do { tprints_field_name("rdx"); tprintf("%#llx", (sizeof((regs).rdx) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rdx) : sizeof((regs).rdx) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rdx) : sizeof((regs).rdx) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rdx) : sizeof((regs).rdx) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rdx) : (unsigned long long) ((regs).rdx))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rsi)) {
   tprint_struct_next();
   do { tprints_field_name("rsi"); tprintf("%#llx", (sizeof((regs).rsi) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rsi) : sizeof((regs).rsi) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rsi) : sizeof((regs).rsi) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rsi) : sizeof((regs).rsi) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rsi) : (unsigned long long) ((regs).rsi))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rdi)) {
   tprint_struct_next();
   do { tprints_field_name("rdi"); tprintf("%#llx", (sizeof((regs).rdi) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rdi) : sizeof((regs).rdi) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rdi) : sizeof((regs).rdi) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rdi) : sizeof((regs).rdi) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rdi) : (unsigned long long) ((regs).rdi))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, orig_rax)) {
   tprint_struct_next();
   do { tprints_field_name("orig_rax"); tprintf("%#llx", (sizeof((regs).orig_rax) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).orig_rax) : sizeof((regs).orig_rax) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).orig_rax) : sizeof((regs).orig_rax) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).orig_rax) : sizeof((regs).orig_rax) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).orig_rax) : (unsigned long long) ((regs).orig_rax))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rip)) {
   tprint_struct_next();
   do { tprints_field_name("rip"); tprintf("%#llx", (sizeof((regs).rip) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rip) : sizeof((regs).rip) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rip) : sizeof((regs).rip) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rip) : sizeof((regs).rip) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rip) : (unsigned long long) ((regs).rip))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, cs)) {
   tprint_struct_next();
   do { tprints_field_name("cs"); tprintf("%#llx", (sizeof((regs).cs) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).cs) : sizeof((regs).cs) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).cs) : sizeof((regs).cs) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).cs) : sizeof((regs).cs) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).cs) : (unsigned long long) ((regs).cs))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, eflags)) {
   tprint_struct_next();
   do { tprints_field_name("eflags"); tprintf("%#llx", (sizeof((regs).eflags) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).eflags) : sizeof((regs).eflags) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).eflags) : sizeof((regs).eflags) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).eflags) : sizeof((regs).eflags) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).eflags) : (unsigned long long) ((regs).eflags))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, rsp)) {
   tprint_struct_next();
   do { tprints_field_name("rsp"); tprintf("%#llx", (sizeof((regs).rsp) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rsp) : sizeof((regs).rsp) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rsp) : sizeof((regs).rsp) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rsp) : sizeof((regs).rsp) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rsp) : (unsigned long long) ((regs).rsp))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, ss)) {
   tprint_struct_next();
   do { tprints_field_name("ss"); tprintf("%#llx", (sizeof((regs).ss) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).ss) : sizeof((regs).ss) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).ss) : sizeof((regs).ss) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).ss) : sizeof((regs).ss) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).ss) : (unsigned long long) ((regs).ss))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, fs_base)) {
   tprint_struct_next();
   do { tprints_field_name("fs_base"); tprintf("%#llx", (sizeof((regs).fs_base) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).fs_base) : sizeof((regs).fs_base) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).fs_base) : sizeof((regs).fs_base) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).fs_base) : sizeof((regs).fs_base) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).fs_base) : (unsigned long long) ((regs).fs_base))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, gs_base)) {
   tprint_struct_next();
   do { tprints_field_name("gs_base"); tprintf("%#llx", (sizeof((regs).gs_base) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).gs_base) : sizeof((regs).gs_base) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).gs_base) : sizeof((regs).gs_base) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).gs_base) : sizeof((regs).gs_base) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).gs_base) : (unsigned long long) ((regs).gs_base))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, ds)) {
   tprint_struct_next();
   do { tprints_field_name("ds"); tprintf("%#llx", (sizeof((regs).ds) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).ds) : sizeof((regs).ds) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).ds) : sizeof((regs).ds) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).ds) : sizeof((regs).ds) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).ds) : (unsigned long long) ((regs).ds))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, es)) {
   tprint_struct_next();
   do { tprints_field_name("es"); tprintf("%#llx", (sizeof((regs).es) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).es) : sizeof((regs).es) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).es) : sizeof((regs).es) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).es) : sizeof((regs).es) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).es) : (unsigned long long) ((regs).es))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, fs)) {
   tprint_struct_next();
   do { tprints_field_name("fs"); tprintf("%#llx", (sizeof((regs).fs) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).fs) : sizeof((regs).fs) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).fs) : sizeof((regs).fs) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).fs) : sizeof((regs).fs) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).fs) : (unsigned long long) ((regs).fs))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_prstatus_regset, gs)) {
   tprint_struct_next();
   do { tprints_field_name("gs"); tprintf("%#llx", (sizeof((regs).gs) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).gs) : sizeof((regs).gs) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).gs) : sizeof((regs).gs) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).gs) : sizeof((regs).gs) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).gs) : (unsigned long long) ((regs).gs))); } while (0);
  }
  if (size > sizeof(regs)) {
   tprint_struct_next();
   tprint_more_data_follows();
  }
  tprint_struct_end();
 }
}
static void
arch_decode_fpregset(struct tcb *const tcp,
       const kernel_ulong_t addr,
       const kernel_ulong_t size)
{
 struct_fpregset regs;
 const size_t fetch_size = (((sizeof(regs)) < (size)) ? (sizeof(regs)) : (size));
 if (!size || size & 7) {
  printaddr(addr);
 } else if (!umoven_or_printaddr(tcp, addr, fetch_size, &regs)) {
  tprint_struct_begin();
  do { tprints_field_name("cwd"); tprintf("%#llx", (sizeof((regs).cwd) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).cwd) : sizeof((regs).cwd) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).cwd) : sizeof((regs).cwd) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).cwd) : sizeof((regs).cwd) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).cwd) : (unsigned long long) ((regs).cwd))); } while (0);
  if (fetch_size > __builtin_offsetof (struct_fpregset, swd)) {
   tprint_struct_next();
   do { tprints_field_name("swd"); tprintf("%#llx", (sizeof((regs).swd) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).swd) : sizeof((regs).swd) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).swd) : sizeof((regs).swd) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).swd) : sizeof((regs).swd) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).swd) : (unsigned long long) ((regs).swd))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, ftw)) {
   tprint_struct_next();
   do { tprints_field_name("ftw"); tprintf("%#llx", (sizeof((regs).ftw) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).ftw) : sizeof((regs).ftw) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).ftw) : sizeof((regs).ftw) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).ftw) : sizeof((regs).ftw) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).ftw) : (unsigned long long) ((regs).ftw))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, fop)) {
   tprint_struct_next();
   do { tprints_field_name("fop"); tprintf("%#llx", (sizeof((regs).fop) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).fop) : sizeof((regs).fop) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).fop) : sizeof((regs).fop) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).fop) : sizeof((regs).fop) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).fop) : (unsigned long long) ((regs).fop))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, rip)) {
   tprint_struct_next();
   do { tprints_field_name("rip"); tprintf("%#llx", (sizeof((regs).rip) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rip) : sizeof((regs).rip) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rip) : sizeof((regs).rip) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rip) : sizeof((regs).rip) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rip) : (unsigned long long) ((regs).rip))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, rdp)) {
   tprint_struct_next();
   do { tprints_field_name("rdp"); tprintf("%#llx", (sizeof((regs).rdp) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).rdp) : sizeof((regs).rdp) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).rdp) : sizeof((regs).rdp) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).rdp) : sizeof((regs).rdp) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).rdp) : (unsigned long long) ((regs).rdp))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, mxcsr)) {
   tprint_struct_next();
   do { tprints_field_name("mxcsr"); tprintf("%#llx", (sizeof((regs).mxcsr) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).mxcsr) : sizeof((regs).mxcsr) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).mxcsr) : sizeof((regs).mxcsr) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).mxcsr) : sizeof((regs).mxcsr) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).mxcsr) : (unsigned long long) ((regs).mxcsr))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, mxcr_mask)) {
   tprint_struct_next();
   do { tprints_field_name("mxcr_mask"); tprintf("%#llx", (sizeof((regs).mxcr_mask) == sizeof(char) ? (unsigned long long) (unsigned char) ((regs).mxcr_mask) : sizeof((regs).mxcr_mask) == sizeof(short) ? (unsigned long long) (unsigned short) ((regs).mxcr_mask) : sizeof((regs).mxcr_mask) == sizeof(int) ? (unsigned long long) (unsigned int) ((regs).mxcr_mask) : sizeof((regs).mxcr_mask) == sizeof(long) ? (unsigned long long) (unsigned long) ((regs).mxcr_mask) : (unsigned long long) ((regs).mxcr_mask))); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, st_space)) {
   const size_t len = fetch_size -
    __builtin_offsetof (struct_fpregset, st_space);
   tprint_struct_next();
   do { tprints_field_name("st_space"); print_local_array_ex(((tcp)), ((regs).st_space), ((((((((len / 4))) > (0)) ? (((len / 4))) : (0))) < ((typeof((len / 4))) (sizeof((regs).st_space) / sizeof(((regs).st_space)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).st_space)), __typeof__(&((regs).st_space)[0])))]) * 0)))) ? ((((((len / 4))) > (0)) ? (((len / 4))) : (0))) : ((typeof((len / 4))) (sizeof((regs).st_space) / sizeof(((regs).st_space)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).st_space)), __typeof__(&((regs).st_space)[0])))]) * 0)))), sizeof(((regs).st_space)[0]), ((print_xint_array_member)), ((void *)0), 0, ((void *)0), ((void *)0)); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, xmm_space)) {
   const size_t len = fetch_size -
    __builtin_offsetof (struct_fpregset, xmm_space);
   tprint_struct_next();
   do { tprints_field_name("xmm_space"); print_local_array_ex(((tcp)), ((regs).xmm_space), ((((((((len / 4))) > (0)) ? (((len / 4))) : (0))) < ((typeof((len / 4))) (sizeof((regs).xmm_space) / sizeof(((regs).xmm_space)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).xmm_space)), __typeof__(&((regs).xmm_space)[0])))]) * 0)))) ? ((((((len / 4))) > (0)) ? (((len / 4))) : (0))) : ((typeof((len / 4))) (sizeof((regs).xmm_space) / sizeof(((regs).xmm_space)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).xmm_space)), __typeof__(&((regs).xmm_space)[0])))]) * 0)))), sizeof(((regs).xmm_space)[0]), ((print_xint_array_member)), ((void *)0), 0, ((void *)0), ((void *)0)); } while (0);
  }
  if (fetch_size > __builtin_offsetof (struct_fpregset, padding)) {
   const size_t len = fetch_size -
    __builtin_offsetof (struct_fpregset, padding);
   tprint_struct_next();
   do { tprints_field_name("padding"); print_local_array_ex(((tcp)), ((regs).padding), ((((((((len / 4))) > (0)) ? (((len / 4))) : (0))) < ((typeof((len / 4))) (sizeof((regs).padding) / sizeof(((regs).padding)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).padding)), __typeof__(&((regs).padding)[0])))]) * 0)))) ? ((((((len / 4))) > (0)) ? (((len / 4))) : (0))) : ((typeof((len / 4))) (sizeof((regs).padding) / sizeof(((regs).padding)[0]) + (sizeof(int[-1 + 2 * !!(!__builtin_types_compatible_p(__typeof__(((regs).padding)), __typeof__(&((regs).padding)[0])))]) * 0)))), sizeof(((regs).padding)[0]), ((print_xint_array_member)), ((void *)0), 0, ((void *)0), ((void *)0)); } while (0);
  }
  if (size > sizeof(regs)) {
   tprint_struct_next();
   tprint_more_data_follows();
  }
  tprint_struct_end();
 }
}
static void
arch_decode_pt_regs(struct tcb *const tcp, const kernel_ulong_t addr)
{
 arch_decode_prstatus_regset(tcp, addr,
   sizeof(struct_prstatus_regset)
  );
}
static void
arch_decode_pt_fpregs(struct tcb *const tcp, const kernel_ulong_t addr)
{
 arch_decode_fpregset(tcp, addr,
   sizeof(struct_fpregset)
  );
}
MPERS_PRINTER_DECL(void, decode_prstatus_regset, struct tcb *const tcp, const kernel_ulong_t addr, const kernel_ulong_t size)
{
 arch_decode_prstatus_regset(tcp, addr, size);
}
MPERS_PRINTER_DECL(void, decode_fpregset, struct tcb *const tcp, const kernel_ulong_t addr, const kernel_ulong_t size)
{
 arch_decode_fpregset(tcp, addr, size);
}
MPERS_PRINTER_DECL(void, decode_pt_regs, struct tcb *const tcp, const kernel_ulong_t addr)
{
 arch_decode_pt_regs(tcp, addr);
}
MPERS_PRINTER_DECL(void, decode_pt_fpregs, struct tcb *const tcp, const kernel_ulong_t addr)
{
 arch_decode_pt_fpregs(tcp, addr);
}
