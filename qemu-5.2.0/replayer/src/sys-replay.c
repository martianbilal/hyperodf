#include "read-structs.h"
#include "sys-replay.h"
#include "replay-debug.h"


int CURR_IOCTLS_INDEX = 0;  //ioctl index
int CURR_SYSCALL_INDEX = 0;     //generic syscall index

ioctl_args **ioctls = NULL;
sys_call_args **syscalls = NULL;
int *syscall_types = NULL;

// use for checking the type of the syscall before making 
// the extend ioctl call 
char *syscalls_supported[max_syscall_supported] = {
    "ioctl",
    "open",
    "close",
    "fstat",
    "arch_prctl"
};

void *replay_kvm_run;

FILE *infile;

// HyperODF [Bilal] CHANGE Here 
char INFILE_NAME[] = "/root/kvm-samples/qemu-5.2.0/dumps/kvm.structs";


// KVM ioctls that require a struct
unsigned int ioctl_req_struct[max_struct_req] = {
    KVM_GET_REGS, 
    KVM_SET_REGS, 
    KVM_GET_SREGS,
    KVM_SET_SREGS,    
    KVM_SET_USER_MEMORY_REGION
};



// corresponding structures
unsigned int ioctl_struct_sizes[max_struct_req] = {
    sizeof(struct kvm_regs), 
    sizeof(struct kvm_regs), 
    sizeof(struct kvm_sregs),
    sizeof(struct kvm_sregs),    
    sizeof(struct kvm_userspace_memory_region)
};



// a list of all the ioctls 
unsigned int ioctl_ids[max_ioctls_supported] = {
    KVM_GET_API_VERSION,
    KVM_CREATE_VM,
    KVM_CHECK_EXTENSION,
    KVM_GET_VCPU_MMAP_SIZE,
    KVM_CREATE_VCPU,
    KVM_SET_TSS_ADDR,
    KVM_SET_USER_MEMORY_REGION,
    KVM_RUN,
    KVM_GET_REGS,
    KVM_SET_REGS,
    KVM_GET_SREGS,
    KVM_SET_SREGS
};

char *ioctl_strings[max_ioctls_supported] = {
    "KVM_GET_API_VERSION",
    "KVM_CREATE_VM",
    "KVM_CHECK_EXTENSION",
    "KVM_GET_VCPU_MMAP_SIZE",
    "KVM_CREATE_VCPU",
    "KVM_SET_TSS_ADDR",
    "KVM_SET_USER_MEMORY_REGION",
    "KVM_RUN",
    "KVM_GET_REGS",
    "KVM_SET_REGS",
    "KVM_GET_SREGS",
    "KVM_SET_SREGS"
};




char proj_root[128];
char log_directory[128];
char raw_logs[128];
char csv_logs[128];

unsigned long parent_fds[max_fds];
unsigned long child_fds[max_fds];

void init_ioctls(void){
    
    ioctls = malloc(sizeof(ioctl_args*) * max_ioctls);
    assert(ioctls);

    CURR_IOCTLS_INDEX = 0;
    return;
}

void init_syscalls(void){
    syscalls = malloc(sizeof(sys_call_args) * max_syscalls);
    return;
}

void init_env(void){

    // [Bilal] CHANGE here
    snprintf(proj_root,128,"/root/kvm-samples/qemu-5.2.0");
    snprintf(log_directory, 128, "%s/replayer/logs", proj_root);
    snprintf(raw_logs, 128, "%s/qemu.log", log_directory);
    snprintf(csv_logs, 128, "%s/qemu.csv", log_directory);

    for(int i = 0; i < max_fds; i++){
        parent_fds[i] = 0;
        child_fds[i] = 0;
    }

    replay_kvm_run = NULL;

    return;
}

int init_files(){
    int ret = 0;    

    
    infile = fopen(INFILE_NAME, "r");
    #ifdef DBG_FILE_READING
    dbg_pr("Open file: %s", INFILE_NAME);
    dbg_pr("File ptr: %p", infile);
    #endif


    return ret; 
}

void replay_init(){
    
    // init_files();
    init_syscalls();
    init_ioctls();
    init_env();

}


void replay_print_parent_fds(){
    dbg_pr("[Parent]\tKVM:\t%d", parent_fds[0]);
    dbg_pr("[Parent]\tKVM VM:\t%d", parent_fds[1]);
    dbg_pr("[Parent]\tKVM VCPU:\t%d", parent_fds[2]);
    return;
}

void replay_print_child_fds(){
    dbg_pr("[Child]\t\tKVM:\t%d", child_fds[0]);
    dbg_pr("[Child]\t\tKVM VM:\t%d", child_fds[1]);
    dbg_pr("[Child]\t\tKVM VCPU:\t%d", child_fds[2]);
    return;
}

void replay_generate_csv_logs(char* raw_logs, char* csv_logs){
    char generate_cmd[256];

    snprintf(generate_cmd, 256, "%s/replayer/ioctl_parse.py %s %s", proj_root, raw_logs, csv_logs);

    system(generate_cmd);
    return;
}

void replay_destroy(void){
    for(int i = 0; i<CURR_IOCTLS_INDEX; i++){
        #ifdef DBG_FREE
        printf("\nfreeing ioctls[%d] : %p\n", i, ioctls[i]);
        #endif
        //free ioctl args
        free(ioctls[i]);
    }
    #ifdef DBG_FREE
    printf("freeing ioctls : %p\n", ioctls);
    #endif
    free(ioctls);

    #ifdef DBG_FILE_READING
    printf("File ptr closing : %p", infile);
    #endif
    // fclose(infile);
}

/// @brief pretty prints an ioctl_args struct -> given DBG_PRINT_STRUCT is defined
/// @param a 
void replay_print_ioctl_args(void *a){
    ioctl_args *args = a;

    #ifdef DBG_PRINT_STRUCT
    printf("\n\n IOCTL_ARGS ==> ");
    printf("\nfd :  %p", args->fd);
    printf("\nioctl_id :  %p", args->ioctl_id);
    printf("\nioctl_stuct :  %p", args->ioctl_struct);
    printf("\nioctl_result :  %p\n", args->result);
    #endif

    #ifdef DBG_PRINT_IOCTL_TAB
    #ifdef CONVERTED_IDS
    printf("[ioctl entry]\t");
    printf("%p,", args->fd);
    printf("%p,", args->ioctl_id);
    printf("%p,", args->ioctl_struct);
    printf("%p\n", args->result);
    #endif
    #ifndef CONVERTED_IDS
    printf("[ioctl entry]\t");
    printf("%p,", args->fd);
    printf("%p,", args->ioctl_id);
    printf("%p,", args->ioctl_struct);
    printf("%p\n", args->result);
    #endif 
    #endif


    return;
}

void replay_print_ioctl_list(void){
    printf("\n\tPRINT IOCTL LIST\t\n");
    FOREACH_IOCTL(replay_print_ioctl_args);
    printf("\tEND IOCTL LIST\t\n");
}

/// @brief 
/// @param fd 
/// @param ioctl_id 
/// @param ioctl_struct 
void replay_extend_ioctls(void *fd, void *ioctl_id, void *ioctl_struct, void *result){
    ioctl_args *new_ioctl = (ioctl_args*)malloc(sizeof(ioctl_args)); 

    assert(new_ioctl != NULL);

    new_ioctl->fd = fd;
    new_ioctl->ioctl_id = ioctl_id;
    new_ioctl->ioctl_struct = ioctl_struct;
    new_ioctl->result = result;

    ioctls[CURR_IOCTLS_INDEX] = new_ioctl;
    CURR_IOCTLS_INDEX = CURR_IOCTLS_INDEX + 1;

    return;
}


/// @brief Adds a parsed syscall to syscalls list
/// @param id 
/// @param args_list 
void replay_extend_syscall(int id, int n_args, void *args_list[]){
    sys_call_args *new_syscall = (sys_call_args*)malloc(sizeof(sys_call_args)); 
    dbg_pr("%s called with : id: %d, n_args: %d, args_list: %p", __func__, id, n_args, args_list);

    assert(new_syscall != NULL);
    // ->fd = fd;
    // new_ioctl->ioctl_id = ioctl_id;
    // new_ioctl->ioctl_struct = ioctl_struct;
    // new_ioctl->result = result;
    new_syscall->id = id;

    for(int i = 0; i < n_args; i++){
        new_syscall->args_list[i] = args_list[i];
    }
    dbg_pr("NOW for newsyscall: id: %d, n_args: %d, args_list: %p", new_syscall->id, n_args, new_syscall->args_list);
    dbg_pr("NOW for newsyscall: args[0]: %s, agrgs[1]: %s, args[2]: %d", new_syscall->args_list[0], new_syscall->args_list[1], new_syscall->args_list[2]);

    syscalls[CURR_SYSCALL_INDEX] = new_syscall;
    CURR_SYSCALL_INDEX = CURR_SYSCALL_INDEX + 1;

    return;
}

// was created for testing
// void replay_extend_syscall(int id, int n_args, void **args_list){
//     dbg_pr("%s called with : id: %d, n_args: %d", id, n_args);
//     dbg_pr("this function is called!");
//     return;
// }



int replay_dump_single_ioctl(void *a, FILE *dump){
    ioctl_args *args = (ioctl_args*)a;
    int ret = 0;

    #ifdef DBG_DUMP
    printf("Writing to file | ioctl.id %p\n", args->ioctl_id);
    #endif
    
    ret = fwrite(args, sizeof(ioctl_args), 1, dump);
    assert(ret != 0);

    return 0;
}

int replay_dump_ioctls(char* out_file){
    int ret = 0;
    FILE *dump;

    dump = fopen(out_file, "w");
    assert(dump != NULL);

    FOREACH_IOCTLS_INDEX{
        replay_dump_single_ioctl(ioctls[i], dump);
    }
    fclose(dump);

    return ret;
}


unsigned int replay_get_ioctl_id(char *ioctl_name){
    int ioctl_id = 0;

    FOREACH_KVM_IOCTL_INDEX{
        check_ioctl(ioctl_name, ioctl_strings[i], ioctl_ids[i], ioctl_id, ret_ioctl);
    }


    // check_ioctl(ioctl_name, "KVM_GET_API_VERSION", KVM_GET_API_VERSION, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_CREATE_VM", KVM_CREATE_VM, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_CHECK_EXTENSION", KVM_CHECK_EXTENSION, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_GET_VCPU_MMAP_SIZE", KVM_GET_VCPU_MMAP_SIZE, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_CREATE_VCPU", KVM_CREATE_VCPU, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_SET_TSS_ADDR", KVM_SET_TSS_ADDR, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_SET_USER_MEMORY_REGION", KVM_SET_USER_MEMORY_REGION, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_RUN", KVM_RUN, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_GET_REGS", KVM_GET_REGS, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_SET_REGS", KVM_SET_REGS, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_GET_SREGS", KVM_GET_SREGS, ioctl_id, ret_ioctl);
    // check_ioctl(ioctl_name, "KVM_SET_SREGS", KVM_SET_SREGS, ioctl_id, ret_ioctl);

ret_ioctl:
    return ioctl_id;
}

int replay_update_ioctls(){
    unsigned int id = 0;
    FOREACH_IOCTLS_INDEX{
        id = replay_get_ioctl_id((char *)(ioctls[i]->ioctl_id));
        ioctls[i]->ioctl_id = (void *)id;
    }
}

int replay_read_csv(char *in_file){
    int ret = 0;
    char buffer[MAX_BUFFER];
    const char delim[2] = ",";
    char *token;
    void* cache_buf[4];
    int index = 0;


    // for syscalls 
    int id = 0;
    int n_args = 0;
    void **args_list = malloc(sizeof(void *) * max_syscall_args);
    assert(args_list);

    int num_syscalls = 0;
    int syscall_size = 0;

    replay_print_backtrace();

    printf("%s\n", in_file);
    FILE *in_stream = fopen(in_file, "r");

    assert(in_stream);

    #ifdef DBG_FILE_READING
    printf("\n");
    #endif

    // code for getting the num of syscall 
    fgets(buffer, MAX_BUFFER, in_stream);
    token = strtok(buffer, delim);
    int counter = 0;
    syscall_size = atol(token);
    syscall_types = malloc(sizeof(int) * syscall_size);
    counter = 0;
    while(token){
        token = strtok(NULL, delim); 

        // add the token to the syscall array
        syscall_types[counter] = atol(token);

        counter = counter + 1;
        if(counter == syscall_size ){
            //end the loop
            break;
        }
    }
    // code for getting the list of syscall ids 


    while(fgets(buffer, MAX_BUFFER, in_stream)){
        if(strlen(buffer)<=1) continue;
        #ifdef DBG_FILE_READING
        printf("[%d] [ioctl entry]\t [size = %ld]\t", index, strlen(buffer));
        printf("%s", buffer);
        #endif
        dbg_pr("in %s:%d", __func__, __LINE__);
        
        id  = syscall_types[index];

        token = strtok(buffer, delim);
        int counter = 0;
        while(token){
            if(id == 0){
                // ioctl    
                switch (counter)
                {
                case 0:
                    cache_buf[0] = (void *)atol(token);
                    break;
                case 1:
                    cache_buf[1] = (void *)strdup(token);
                    break;
                case 2:
                    cache_buf[2] = (void *)atol(token);
                    break;
                case 3:
                    cache_buf[3] = (void *)atol(token);
                    break;
                }
            } else {
                // any other syscall
                if(id == 1){
                    // open syscall 
                    switch (counter)
                    {
                    case 0:
                        args_list[0] = (void *)strdup(token);
                        break;
                    case 1:
                        args_list[1] = (void *)strdup(token);
                        break;
                    case 2:
                        dbg_pr("adding args_list : %d ", atol(token));
                        args_list[2] = (void *)atol(token);
                        dbg_pr("args_list[2] = %d", args_list[2]);
                        break;
                    }
                }

                n_args = n_args + 1;
                
            }
            counter = counter + 1;
            token = strtok(NULL, delim);
        }

        if(syscall_types[index] == 0){
            // ioctl
            replay_extend_ioctls(cache_buf[0], cache_buf[1], 
                        cache_buf[2], cache_buf[3]);
        } else if (syscall_types[index] == 1){
            // open
            dbg_pr("Calling extend_syscall from %s:%d", __func__, __LINE__);
            dbg_pr("id : %d", id);
            dbg_pr("n_args : %d", n_args);
            dbg_pr("args_list : %p", args_list);
            dbg_pr("0 : %s", args_list[0]);
            dbg_pr("1 : %s", args_list[1]);
            dbg_pr("2 : %d", args_list[2]);
            replay_extend_syscall(id, n_args, args_list);
        }
        
        
        index = index + 1;
    }
    // [TODO] [START]Shortcircuiting the system for testing the proper parsing of 
    // verbose strace ouptut 
    // dbg_pr("\t++exiting for testing++");
    // dbg_pr("KVM_GET_REGS : %p", KVM_GET_REGS);
    // dbg_pr("KVM_GET_REGS - DESTRINGIF¥: %p", replay_get_ioctl_id("KVM_GET_REGS"));
    replay_update_ioctls();
    replay_print_ioctl_list();
    // exit(0);

    // [TODO] [END]Befor this point 
    
    assert(ret == 0);
    return ret;
}

void hello_test(){
    printf("[Replayer] Hello :)\n");
    printf("[Replayer] %p\n", ioctls);
}

int replay_attach_strace(int pid, char* out_file){
    int ret = 0;
    char strace_cmd[256];
    // snprintf(strace_cmd, 128, "strace --raw=all -e trace=ioctl -p %d -o %s",
    //         pid, out_file);
    dbg_pr("strace test file\t:\t%s", out_file);
    snprintf(strace_cmd, 256, "/root/kvm-samples/htrace/src/strace -e trace=ioctl  --abbrev=none -p %d -o %s",
            pid, out_file);

    ret = fork();

    if(ret < 0){
        // fork failed 
        dbg_pr("Failed to fork");
        exit(-1);
    }

    if(ret == 0){
        /* Child process */
        // execve("/usr/bin/strace", );
        dbg_pr("Started child for starting fork");
        printf("\n[replayer] pid\t:\t%d\n", getpid());
        // printf("[replayer]\tCalling strace child process\n");
        ret = system(strace_cmd);
        dbg_pr("return value from system strace : %d", ret);
        exit(0);
        // printf("[replayer] pid\t:\t%d\t--\treturned\n", getpid());

    } else {
        // while(wait(NULL) > 0);
        sleep(2);
        printf("\n[replayer] Parent pid\t:\t%d\n", getpid());
        // wait(NULL);
        return ret;
    }


    assert(!ret);

    return ret;
}

int replay_detach_strace(){
    int ret = 0;

    dbg_pr("------------------\tdetaching from strace\t-------------");
    ret = system("killall strace");
    init_files();

    // assert(!ret);

    return ret;
}

int replay_get_parent_fd(void *a){
    ioctl_args* arg = (ioctl_args*)a;
    int ret = 0;

    // dbg_pr("id:  %p", (arg->ioctl_id));
    // replay_print_ioctl_args(arg);

    switch ((unsigned long)(arg->ioctl_id))
    {
    case KVM_CREATE_VM:
        /* code */
        parent_fds[0] = (unsigned long)arg->fd;
        parent_fds[1] = (unsigned long)arg->result;
        ret = 0;
        break;

    case KVM_CREATE_VCPU:
        /* code */
        parent_fds[2] = (unsigned long)arg->result;
        ret = 0;
        break;
    
    default:
        ret = -1;
        break;
    }

    return ret; 
}

int replay_get_parent_fds(){
    int ret = 0;
    FOREACH_IOCTL(replay_get_parent_fd);
    dbg_pr("kvm_fd : %lu", parent_fds[0]);
    dbg_pr("vm_fd : %lu", parent_fds[1]);
    dbg_pr("vcpu_fd : %lu", parent_fds[2]);

    return ret;
}


/**
 * @brief Checks if the given ioctl needs 
 * struct or not 
 * 
 * @return -1 if ioctl does not need struct, 
 * index of the ioctl in the check array otherwise
*/
static int ioctl_need_struct(unsigned int ioctl){
    int ret = -1;
    for(int i = 0; i < max_struct_req; i++){
        if(ioctl == ioctl_req_struct[i]){
            ret = i;
            break;
        }
    }
    // dbg_pr("ret::\tneed_struct:\t%d",ret);
    return ret;
}
/**
 * @brief run an ioctl given an ioctl_arg
 * 
 * @return -1 on failure, ioctl result on success
 * */
int replay_run_ioctl(void *a){
    unsigned long ret = 0;
    ioctl_args *arg = a;
    struct kvm_userspace_memory_region *memreg;
    int need_struct = -1;
    struct kvm_regs *regs_test;
    struct kvm_userspace_memory_region *memreg_test;

    // for reading random ioctl structs from the dump
    void *ioctl_struct;
    int ioctl_struct_size;

    int max_tries = 10;
    int tries = 0;

    int vcpu_mmap_size;

    need_struct = ioctl_need_struct((unsigned long)(arg->ioctl_id));
    if(need_struct != -1)
        dbg_pr("need_struct\t:\t%d", need_struct);
    
    if(need_struct != -1){
        //get struct
        // [TODO] get the actual type of the struct 

        // thing we want to do is 
        /**
         * void *struct = malloc(sizeof(corresponding struct));
         * read(struct);
         * 
         * for finding the corresponding struct 
         * arrayofstructtype[need_struct]
         * 
        */
        ioctl_struct_size = ioctl_struct_sizes[need_struct];
        ioctl_struct = malloc(ioctl_struct_size);   

        dbg_pr("%s\t||\treplay read struct being called ", __func__);
        replay_read_struct(ioctl_struct, ioctl_struct_size, infile);

        #ifdef DBG_LOAD_STRUCT
        if(need_struct == 0 || need_struct == 1){
            regs_test = (struct kvm_reg *)ioctl_struct;
            dbg_pr();
            dbg_pr("REGS==>RAX\t:\t%lu", regs_test->rax);
        }
        if(need_struct == 4){
            memreg = (struct kvm_userspace_memory_region *)ioctl_struct;
            dbg_pr("&memreg : %p", &memreg);
            dbg_pr("memreg.userspace_addr : %p", memreg->userspace_addr);
            dbg_pr("memreg.guest_phys_addr : %p", memreg->guest_phys_addr);
            dbg_pr("memreg.memsize : %d", memreg->memory_size);
        }
        #endif

        do{
            ret = ioctl((int)(arg->fd), (unsigned long)(arg->ioctl_id), ioctl_struct);
            tries = tries + 1;
        }while(ret != (unsigned long)(arg->result) && tries < max_tries);
    } else {
        do{
            ret = ioctl((int)(arg->fd), (unsigned long)(arg->ioctl_id), arg->ioctl_struct);
            tries = tries + 1;
        }while(ret != (unsigned long)(arg->result) && tries < max_tries);
    }

    
    
    if(ret != (unsigned long)(arg->result)) ret = -1;

    // if((unsigned long)(arg->ioctl_id) == KVM_SET_USER_MEMORY_REGION){
    //     dbg_pr("memory set");
    //     memreg = (struct kvm_userspace_memory_region*)(arg->ioctl_struct);
    //     dbg_pr("&memreg : %p", arg->ioctl_struct);
    //     dbg_pr("memreg.userspace_addr : %p", memreg->userspace_addr);
    //     dbg_pr("memreg.guest_phys_addr : %p", memreg->guest_phys_addr);
    //     dbg_pr("memreg.memsize : %p", memreg->memory_size);
    // }

    if((unsigned long)(arg->ioctl_id) == KVM_CREATE_VCPU){
        vcpu_mmap_size = ioctl(parent_fds[0], KVM_GET_VCPU_MMAP_SIZE, 0);
            if (vcpu_mmap_size <= 0) {
            perror("KVM_GET_VCPU_MMAP_SIZE");
                    exit(1);
        }

        replay_kvm_run = mmap(NULL, vcpu_mmap_size, PROT_READ | PROT_WRITE,
                    MAP_PRIVATE, parent_fds[2], 0);
        dbg_pr("[module]\t%p",replay_kvm_run);
    }

    return ret;
}

int replay_run_syscall(void *a, int id){
    int ret = 0;
    sys_call_args *args = (sys_call_args *)a;
    // handling the syscall 
    if(args->id == 1){
        // open
        // ret = open("/dev/kvm", O_RDWR);
        dbg_pr("args list 0 for open --- : ----  %s", args->args_list[0] );
        dbg_pr("args list 1 for open --- : ----  %s", args->args_list[1] );
        // ret = open((char *)(args->args_list[0]), O_RDWR);
        
        if(!(strcmp(args->args_list[1], "O_RDWR")))
            ret = open((char *)(args->args_list[0]), O_RDWR);
        else
            ret = open((char *)(args->args_list[0]), args->args_list[1]);

        child_fds[0] = ret;
        dbg_pr("child kvm fd : %d", child_fds[0]);
        dbg_pr("parent kvm fd : %d", parent_fds[0]);
        assert(child_fds[0] == parent_fds[0]);
        assert(ret == args->args_list[2]);
    }
    return ret;


    return ret;
}

/**
 * 
 * flag => is 0 if ioctl, ioctl id otherwise 
 * 
*/
int __replay_run_syscall(void *a, int flag){
    int ret = 0;
    if(!flag){
        // ioctl
        replay_run_ioctl(a);
    } else {
        //other syscall
        replay_run_syscall(a, flag);
    
    }
    return;
}


void foreach_entry(int (*func)(void *a, int i)){
    int ioctl_i = 0;
    int syscall_i = 0;

    __FOREACH_SYSCALL_INDEX{
        if(!syscall_types[i]){
            //ioctl
            func(ioctls[ioctl_i], syscall_types[i]);
            ioctl_i = ioctl_i + 1;

        } else {
            // other syscall
            func(syscalls[syscall_i], syscall_types[i]);
            syscall_i = syscall_i + 1;
        }
    }

    dbg_pr("At end of foreach_entry --- ");
    dbg_pr("syscall__i\t:\t%d ", syscall_i);
    dbg_pr("ioctl_i\t:\t%d ", ioctl_i);
    return;
}

int replay_ioctl_rewind(){
    int ret = 0;

    // [TODO] this loop only runs for each ioctl 
    // needs something which runs in a hybrid way
    // for ioctls and rest of the syscalls

    foreach_entry(__replay_run_syscall);
    dbg_pr("sizeof ioctl_args : %d", sizeof(ioctl_args));
    dbg_pr("sizeof syscall_args : %d", sizeof(sys_call_args));


    // FOREACH_IOCTL(replay_run_ioctl);

    return ret;
}

int replay_close_parent_fds(){
    int ret = 0;

    for(int i = 0; i < max_fds; i++){
        close(parent_fds[i]);
    }

    return ret;
}

int replay_reopen_kvm_device(){
    int ret = 0; 
    
    // open kvm device
    ret = open("/dev/kvm", O_RDWR);
	if (ret < 0) {
		perror("open /dev/kvm");
		exit(1);
	}
    child_fds[0] = ret;
    assert(child_fds[0] == parent_fds[0]);


    return ret; 
}

int replay_verify_results(){
    int ret = 0;
    return ret;
}


/// @brief entry function for child related replayer routines
/// @return 0 on success, -1 on failure
int replay_child(){
    int ret = 0;
    dbg_pr("Calling %s\n", __func__);

    ret = replay_get_parent_fds();

    for(int i = 0; i < max_fds; i++){
        if(!parent_fds[i]){
            return -1;
        }
    }
    
    ret = replay_close_parent_fds();
    // ret = replay_reopen_kvm_device();
    ret = replay_ioctl_rewind();
    ret = replay_verify_results();
 

    return ret;
}


int replay_main(){
    char *in_file = csv_logs;


    printf("\n********************   ******  ********************\n");
    printf("\n********************   REPLAY  ********************\n");
    printf("\n********************   ******  ********************\n");

    // init_ioctls();
    replay_init();
    
    // TODO : BUG : does not work if you extend before reading file
    // replay_extend_ioctls((void *)0x1, (void *)0x1, (void *)0x1, (void *)0x0);
    // replay_extend_ioctls((void *)0x1, (void *)0x24, (void *)0x1, (void *)0x23);

    // replay_dump_ioctls("dump.ioctls");

    // replay_print_ioctl_args(ioctls[0]);
    // replay_print_ioctl_args(ioctls[1]);
    // replay_print_ioctl_list();
    replay_generate_csv_logs(raw_logs, csv_logs);

    replay_read_csv(in_file);
    // replay_extend_ioctls((void *)0x1, (void *)0x24, (void *)0x1, (void *)0x23);
    replay_print_ioctl_list();

    printf("\n");
    printf("\n********************   ******  ********************\n");
    printf("\n\n\n");

    return 0;
        
}


// testing if the module compiled with QEMUs
void replay_hello(){
    printf("[Replayer] HELLO ****working\n");
    return;
}

#ifdef STANDALONE_BUILD
int main() {
    dbg_pr("*********STANDALONE BUILD*********");
    replayer_main();

    replay_get_parent_fds();
    dbg_pr("*********STANDALONE BUILD*********");
    // dbg_pr("create : %p", KVM_CREATE_VM);
}
#endif