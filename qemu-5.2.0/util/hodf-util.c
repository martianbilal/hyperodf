#include "util/hodf-util.h"
#include "qemu/thread.h"

// debug flag for hodf
// #define DBG_HODF

#ifdef DBG_HODF
#define DEBUG_PRINT(fmt, args...) printf( "[%d|%s():%d] " fmt, \
    getpid(), __func__,  __LINE__, ##args)
#else
#define DEBUG_PRINT(fmt, args...) /* do nothing */
#endif



// random number
static int H_MAX_CPUS = 20;
hodf_metadata *metadata_array;


void h_initialize(void){
    DEBUG_PRINT("Starting initializing");
    
    metadata_array = malloc(sizeof(hodf_metadata) * H_MAX_CPUS);
    
    for(int i = 0; i < H_MAX_CPUS; i++){
        metadata_array[i].threadid = 0;
    }
    DEBUG_PRINT("Initialization done");
}

void h_save_metadata(QemuCond *halt_cond, pthread_t threadid, int cpu_index){
    memcpy(&metadata_array[cpu_index].halt_cond, halt_cond, sizeof(QemuCond));
    metadata_array[cpu_index].threadid = threadid;
    return;
}

void h_cpu_kick(void){
    DEBUG_PRINT("Kicking all threads\n");
    for(int i = 0; i < H_MAX_CPUS; i++){
        if(metadata_array[i].threadid != 0){
            // still not setting the thread_kicked flag
            // qemu_mutex_lock(qemu_global_mutex);
            qemu_cond_broadcast(&metadata_array[i].halt_cond);
            // from main-loop.h #define SIG_IPI SIGUSR1
            // pthread_kill(metadata_array[i].threadid, SIGUSR1);
            break;
        }
    }
    return;
}

void h_hello(void){
    printf("Hello\n");
}