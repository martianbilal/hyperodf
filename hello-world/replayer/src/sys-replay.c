#include "sys-replay.h"
#include "read-structs.h"


int CURR_IOCTLS_INDEX = 0;

ioctl_args **ioctls = NULL;

void *replay_kvm_run;

FILE *infile;
char INFILE_NAME[] = "/root/kvm-samples/dumps/kvm.structs";


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

void init_env(void){
    snprintf(proj_root,128,"/root/kvm-samples/hello-world");
    snprintf(log_directory, 128, "%s/replayer/logs", proj_root);
    snprintf(raw_logs, 128, "%s/final.log", log_directory);
    snprintf(csv_logs, 128, "%s/final.csv", log_directory);

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
    printf("[ioctl entry]\t");
    printf("%p,", args->fd);
    printf("%p,", args->ioctl_id);
    printf("%p,", args->ioctl_struct);
    printf("%p\n", args->result);
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

int replay_read_csv(char *in_file){
    int ret = 0;
    char buffer[MAX_BUFFER];
    const char delim[2] = ",";
    char *token;
    void* cache_buf[4];
    int index = 0;

    printf("%s\n", in_file);
    FILE *in_stream = fopen(in_file, "r");

    assert(in_stream);

    #ifdef DBG_FILE_READING
    printf("\n");
    #endif
    while(fgets(buffer, MAX_BUFFER, in_stream)){
        if(strlen(buffer)<=1) continue;
        #ifdef DBG_FILE_READING
        printf("[%d] [ioctl entry]\t [size = %ld]\t", index, strlen(buffer));
        printf("%s", buffer);
        #endif
        index = index + 1;

        token = strtok(buffer, delim);
        int counter = 0;
        while(token){
            switch (counter)
            {
            case 0:
                cache_buf[0] = (void *)atol(token);
                break;
            case 1:
                cache_buf[1] = (void *)atol(token);
                break;
            case 2:
                cache_buf[2] = (void *)atol(token);
                break;
            case 3:
                cache_buf[3] = (void *)atol(token);
                break;
            }
            counter = counter + 1;
            token = strtok(NULL, delim);
        }
        replay_extend_ioctls(cache_buf[0], cache_buf[1], 
                        cache_buf[2], cache_buf[3]);
        
    }
    // [TODO] [START]Shortcircuiting the system for testing the proper parsing of 
    // verbose strace ouptut 
    dbg_pr("\t++exiting for testing++");
    exit(0);

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
    char strace_cmd[128];

    // snprintf(strace_cmd, 128, "strace --raw=all -e trace=ioctl -p %d -o %s",
    //         pid, out_file);
    dbg_pr("strace file\t:\t%s", out_file);
    snprintf(strace_cmd, 128, "/root/kvm-samples/htrace/src/strace  --abbrev=none -p %d -o %s",
            pid, out_file);

    ret = fork();

    if(ret == 0){
        /* Child process */
        // execve("/usr/bin/strace", );
        printf("\n[replayer] pid\t:\t%d\n", getpid());
        // printf("[replayer]\tCalling strace child process\n");
        system(strace_cmd);
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
    dbg_pr("ret::\tneed_struct:\t%d",ret);
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

    // for reading random ioctl structs from the dump
    void *ioctl_struct;
    int ioctl_struct_size;

    int max_tries = 10;
    int tries = 0;

    int vcpu_mmap_size;

    need_struct = ioctl_need_struct((unsigned long)(arg->ioctl_id));
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

    if((unsigned long)(arg->ioctl_id) == KVM_SET_USER_MEMORY_REGION){
        dbg_pr("memory set");
        memreg = (struct kvm_userspace_memory_region*)(arg->ioctl_struct);
        dbg_pr("&memreg : %p", arg->ioctl_struct);
        dbg_pr("memreg.userspace_addr : %p", memreg->userspace_addr);
        dbg_pr("memreg.guest_phys_addr : %p", memreg->guest_phys_addr);
        dbg_pr("memreg.memsize : %p", memreg->memory_size);
    }

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

int replay_ioctl_rewind(){
    int ret = 0;

    FOREACH_IOCTL(replay_run_ioctl);

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


    ret = replay_get_parent_fds();

    for(int i = 0; i < max_fds; i++){
        if(!parent_fds[i]){
            return -1;
        }
    }
    
    ret = replay_close_parent_fds();
    ret = replay_reopen_kvm_device();
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

#ifdef STANDALONE_BUILD
int main() {
    dbg_pr("*********STANDALONE BUILD*********");
    replayer_main();

    replay_get_parent_fds();
    dbg_pr("*********STANDALONE BUILD*********");
    // dbg_pr("create : %p", KVM_CREATE_VM);
}
#endif