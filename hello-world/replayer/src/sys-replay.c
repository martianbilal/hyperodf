#include "sys-replay.h"

#define DBG_PRINT_IOCTL_TAB
// #define DBG_PRINT_STRUCT
// uncomment to debug freeing routines
// #define DBG_FREE
// uncomment to debug struct printing routines 
// #define DBG_PRINT_STRUCT
// uncomment to debug dumping routines
// #define DBG_DUMP 
// uncomment to print strings read from file
#define DBG_FILE_READING

// uncomment this to use debug printing
#define DBG_PRINT 1

#define STANDALONE_BUILD

#define dbg_pr_verbose(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "%s:%d:%s(): [replayer]\t" fmt, __FILE__, \
                                __LINE__, __func__, ##__VA_ARGS__); } while (0)

#define dbg_pr(fmt, ...) \
        do { if(DBG_PRINT) fprintf(stderr, "[replayer]\t" fmt "\n", ##__VA_ARGS__); } while (0)



#define FOREACH_IOCTLS_INDEX                        \
      for (int i = 0; i < CURR_IOCTLS_INDEX; i++)   \


#define FOREACH_IOCTL(function) FOREACH_IOCTLS_INDEX{(function)(ioctls[i]);}

      
#define MAX_BUFFER 100 //used for reading lines from the file



int CURR_IOCTLS_INDEX = 0;

ioctl_args **ioctls = NULL;

char proj_root[128];
char log_directory[128];
char raw_logs[128];
char csv_logs[128];

unsigned long parent_fds[3];

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

    return;
}

void replay_init(){
    init_ioctls();
    init_env();

}


void replay_generate_csv_logs(char* raw_logs, char* csv_logs){
    char generate_cmd[256];

    snprintf(generate_cmd, 256, "%s/replayer/ioctl_parse.py %s %s", proj_root, raw_logs, csv_logs);

    system(generate_cmd);
    return;
}

void destroy(void){
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

    snprintf(strace_cmd, 128, "strace --raw=all -e trace=ioctl -p %d -o %s",
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

    ret = system("killall strace");

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

int replay_ioctl_rewind(){
    int ret = 0;
    return ret;
}

int replay_close_parent_fds(){
    int ret = 0;
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
    int parent_kvm_fd = 0;
    int parent_kvm_vm_fd = 0;
    int parent_kvm_vcpu_fd = 0;


    ret = replay_get_parent_fds(&parent_kvm_fd, &parent_kvm_vm_fd, &parent_kvm_vcpu_fd);
    
    if(!(parent_kvm_fd && parent_kvm_vm_fd && parent_kvm_vcpu_fd)){
        return -1;
    }
    
    ret = replay_close_parent_fds();
    ret = replay_ioctl_rewind();
    ret = replay_verify_results();
 

    return ret;
}


int replayer_main(){
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