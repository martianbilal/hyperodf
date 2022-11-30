




#include <stdio.h>
#include <linux/kvm.h>
#include <assert.h>
#include <linux/prctl.h>
#include <linux/memfd.h>
#include <signal.h>
#include <linux/seccomp.h>  /* Definition of SECCOMP_* constants */
#include <linux/filter.h>   /* Definition of struct sock_fprog */
#include <linux/audit.h>    /* Definition of AUDIT_* constants */
// #include <linux/signal.h>   /* Definition of SIG* constants */
#include <sys/ptrace.h>     /* Definition of PTRACE_* constants */
#include <sys/syscall.h>    /* Definition of SYS_* constants */
#include <unistd.h>
// #include <asm/types.h>
// #include <sys/socket.h>
#include <linux/netlink.h>
#include <asm/prctl.h>        /* Definition of ARCH_* constants */
// #include <fcntl.h>
#include <asm/fcntl.h>
#include <sys/mman.h>
#include <sys/eventfd.h>
#include <linux/memfd.h>

#include <linux/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sys/time.h>
#include <sys/resource.h>



/* https://students.mimuw.edu.pl/SO/Linux/Kod/include/linux/socket.h.html */
#define SOL_TCP 6
// #define SOL_IP 0

#define IPV 0


/* https://elixir.bootlin.com/linux/latest/source/include/uapi/linux/memfd.h#L10 */
#define MFD_HUGETLB		0x0004U

/* https://elixir.bootlin.com/linux/v4.9/source/include/uapi/asm-generic/signal-defs.h#L7 */
#define SIG_BLOCK          0
#define SIG_UNBLOCK        1
#define SIG_SETMASK        2

#define MACRO_NR 61

#define STRINGIFY(x) #x

char *macro_strings[MACRO_NR] = {"MFD_CLOEXEC", "SEEK_END", "SIGHUP", "IPPROTO_TCP", "SECCOMP_SET_MODE_FILTER", "O_NONBLOCK", "MFD_ALLOW_SEALING", "O_WRONLY", "SEEK_SET", "F_GETFD", "SOCK_STREAM", "PR_MCE_KILL_EARLY", "ARCH_SET_FS", "SIGTERM", "F_OFD_SETLK", "AF_NETLINK", "SIG_BLOCK", "O_RDONLY", "SIGQUIT", "PR_SET_TIMERSLACK", "SIGCONT", "F_SETFD", "O_CLOEXEC", "SIG_UNBLOCK", "SIG_SETMASK", "SO_OOBINLINE", "FD_CLOEXEC", "SIGCHLD", "O_DIRECTORY", "O_CREAT", "IPPROTO_IP", "SIGUSR1", "O_LARGEFILE", "NETLINK_ROUTE", "F_SETFL", "O_RDWR", "RLIMIT_STACK", "MFD_HUGETLB", "AF_INET", "SOL_SOCKET", "SOL_TCP", "SOCK_NONBLOCK", "SOCK_DGRAM", "F_SETLK", "SO_REUSEADDR", "SOCK_CLOEXEC", "SIGPIPE", "SEEK_CUR", "TCP_NODELAY", "AF_UNIX", "IPV", "EFD_NONBLOCK", "SOCK_RAW", "F_GETFL", "PR_MCE_KILL_SET", "SIGINT", "PR_MCE_KILL", "F_OFD_GETLK", "SECCOMP_FILTER_FLAG_TSYNC", "EFD_CLOEXEC", "SOL_IPV6"};
int macro_ids[MACRO_NR] = {MFD_CLOEXEC, SEEK_END, SIGHUP, IPPROTO_TCP, SECCOMP_SET_MODE_FILTER, O_NONBLOCK, MFD_ALLOW_SEALING, O_WRONLY, SEEK_SET, F_GETFD, SOCK_STREAM, PR_MCE_KILL_EARLY, ARCH_SET_FS, SIGTERM, F_OFD_SETLK, AF_NETLINK, SIG_BLOCK, O_RDONLY, SIGQUIT, PR_SET_TIMERSLACK, SIGCONT, F_SETFD, O_CLOEXEC, SIG_UNBLOCK, SIG_SETMASK, SO_OOBINLINE, FD_CLOEXEC, SIGCHLD, O_DIRECTORY, O_CREAT, IPPROTO_IP, SIGUSR1, O_LARGEFILE, NETLINK_ROUTE, F_SETFL, O_RDWR, RLIMIT_STACK, MFD_HUGETLB, AF_INET, SOL_SOCKET, SOL_TCP, SOCK_NONBLOCK, SOCK_DGRAM, F_SETLK, SO_REUSEADDR, SOCK_CLOEXEC, SIGPIPE, SEEK_CUR, TCP_NODELAY, AF_UNIX, IPV, EFD_NONBLOCK, SOCK_RAW, F_GETFL, PR_MCE_KILL_SET, SIGINT, PR_MCE_KILL, F_OFD_GETLK, SECCOMP_FILTER_FLAG_TSYNC, EFD_CLOEXEC, SOL_IPV6};


int main(int argc, char *argv[]) {

    FILE *fptr;

    if(argc <= 1 || argc >= 3) {
        printf("./print-macro-ids filename\n");
        return 1; 
    }

    fptr = fopen(argv[1], "w");
    assert(fptr);
    

    fprintf(fptr, "{\n");
    for(int i = 0; i < MACRO_NR; i++){
        // fprintf(fptr, "%s,%p\n", kvm_ids_strings[i], kvm_ids[i]);
        fprintf(fptr, "\t\'%s\' : %d,\n", macro_strings[i], macro_ids[i]);
    }
    fprintf(fptr, "}\n");

    fclose(fptr);
    
    return 0;
}