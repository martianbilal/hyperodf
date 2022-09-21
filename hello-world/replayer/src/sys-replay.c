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


#define FOREACH_IOCTLS_INDEX                        \
      for (int i = 0; i < CURR_IOCTLS_INDEX; i++)   \


#define FOREACH_IOCTL(function) FOREACH_IOCTLS_INDEX{(function)(ioctls[i]);}

      
#define MAX_BUFFER 100 //used for reading lines from the file



int CURR_IOCTLS_INDEX = 0;
ioctl_args **ioctls = NULL;


void init_ioctls(void){
    
    ioctls = malloc(sizeof(ioctl_args*) * max_ioctls);
    assert(ioctls);

    CURR_IOCTLS_INDEX = 0;

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

    #ifdef DBG_DUMP
    printf("Writing to file | ioctl.id %p\n", args->ioctl_id);
    #endif
    
    fwrite(args, sizeof(ioctl_args), 1, dump);
    assert(fwrite!=0);

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

    snprintf(strace_cmd, 128, "strace -fe trace=ioctl -p %d -o %s",
            pid, out_file);
    ret = system(strace_cmd);

    assert(!ret);

    return ret;
}

int replay_detach_strace(){
    int ret = 0;

    ret = system("killall strace");

    assert(!ret);

    return ret;
}



int replayer_main(){
    char *in_file = "/root/kvm-samples/hello-world/\
replayer/logs/simple.csv";


    printf("\n********************   ******  ********************\n");
    printf("\n********************   REPLAY  ********************\n");
    printf("\n********************   ******  ********************\n");

    init_ioctls();
    
    // TODO : BUG : does not work if you extend before reading file
    // replay_extend_ioctls((void *)0x1, (void *)0x1, (void *)0x1, (void *)0x0);
    // replay_extend_ioctls((void *)0x1, (void *)0x24, (void *)0x1, (void *)0x23);

    // replay_dump_ioctls("dump.ioctls");

    // replay_print_ioctl_args(ioctls[0]);
    // replay_print_ioctl_args(ioctls[1]);
    // replay_print_ioctl_list();


    replay_read_csv(in_file);
    // replay_extend_ioctls((void *)0x1, (void *)0x24, (void *)0x1, (void *)0x23);
    replay_print_ioctl_list();
    destroy();

    printf("\n");
    printf("\n********************   ******  ********************\n");
    printf("\n\n\n");

    return 0;
        
}