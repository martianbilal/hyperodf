#include "sys-replay.h"

#define DBG_PRINT_STRUCT

#define FOREACH_IOCTLS_INDEX                        \
      for (int i = 0; i < CURR_IOCTLS_INDEX; i++)   \


#define FOREACH_IOCTL(function) FOREACH_IOCTLS_INDEX{(function)(ioctls[i]);}

      

int CURR_IOCTLS_INDEX = 0;


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
    printf("\nioctl_stuct :  %p\n", args->ioctl_struct);
    #endif

    return;
}

void replay_print_ioctl_list(void){
    FOREACH_IOCTL(replay_print_ioctl_args);
}

/// @brief 
/// @param fd 
/// @param ioctl_id 
/// @param ioctl_struct 
void replay_extend_ioctls(void* fd, void* ioctl_id, void* ioctl_struct){
    ioctl_args *new_ioctl = (ioctl_args*)malloc(sizeof(ioctl_args)); 

    assert(new_ioctl != NULL);

    new_ioctl->fd = fd;
    new_ioctl->ioctl_id = ioctl_id;
    new_ioctl->ioctl_struct = ioctl_struct;

    ioctls[CURR_IOCTLS_INDEX] = new_ioctl;
    CURR_IOCTLS_INDEX++;

    return;
}


int replay_dump_ioctls(char* out_file){
    int ret = 0;
    
    return ret;
}

int main(){
    printf("\n********************   ******  ********************\n");
    printf("\n********************   REPLAY  ********************\n");
    printf("\n********************   ******  ********************\n");

    init_ioctls();
    

    replay_extend_ioctls((void *)0x1, (void *)0x1, (void *)0x1);
    replay_extend_ioctls((void *)0x1, (void *)0x24, (void *)0x1);

    replay_dump_ioctls("dump.ioctls");

    // replay_print_ioctl_args(ioctls[0]);
    // replay_print_ioctl_args(ioctls[1]);
    replay_print_ioctl_list();

    destroy();

    printf("\n\n\n");
    printf("\n********************   ******  ********************\n");

    return 0;
        
}