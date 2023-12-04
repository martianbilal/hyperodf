#include "util/hodf-util.h"
#include "qemu/event_notifier.h"
#include "qemu/thread.h"
#include "qemu/typedefs.h"
#include "util/forkall-coop.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>

// debug flag for hodf
// #define DBG_HODF
//#define USE_EPT

#ifdef DBG_HODF
#define DEBUG_PRINT(fmt, args...) printf( "[%d|%s():%d] " fmt, \
    getpid(), __func__,  __LINE__, ##args)
#else
#define DEBUG_PRINT(fmt, args...) /* do nothing */
#endif

#define USE_FILE

// random number
static int H_MAX_CPUS = 20;
static int monitor_client_fd = 0;

#ifdef USE_FILE
// static const char *hodf_eval_file = "evals/hodf.csv";
#endif

//======================Global Vars============================
hodf_metadata *metadata_array;

EventNotifier mon_create_event;
int parent_child_pipe[2];

hodf_event *hodf_events = NULL;
int hodf_events_size =0;

GMainLoop *h_iothread_main_loop;
int h_qmp_fd = 0;

QemuCondList *qemu_cond_list = NULL;


//==============================================================

void hodf_add_event(const char *eventDesc) {
    struct timeval tv;
    gettimeofday(&tv, NULL); // Get the current time

    double time = tv.tv_sec + tv.tv_usec / 1000000.0;

    // Resize the hodf_events array
    hodf_event *newHodfEvents = realloc(hodf_events, (hodf_events_size + 1) * sizeof(hodf_event));
    if (newHodfEvents == NULL) {
        perror("Failed to allocate memory for hodf_events");
        exit(EXIT_FAILURE);
    }
    hodf_events = newHodfEvents;

    // Add the new event
    hodf_events[hodf_events_size].time = time;
    hodf_events[hodf_events_size].pid = getpid();
    strncpy(hodf_events[hodf_events_size].event, eventDesc, MAX_EVENT_LEN);
    hodf_events[hodf_events_size].event[MAX_EVENT_LEN - 1] = '\0'; // Ensure null-termination

    // Increment the size
    hodf_events_size++;
}
// Function to print all events
void hodf_print_events(void) {
    const char *hodf_eval_file = forkall_check_child() ? "evals/hodf_child.csv": "evals/hodf_parent.csv";
    
    #ifdef USE_FILE
    FILE *hodf_fd = fopen(hodf_eval_file, "w");
    #endif
    
    // Print the header
    #ifndef USE_FILE
    printf("Pid, Time, Event\n");
    #else
    fprintf(hodf_fd, "Pid,Time,Event\n");
    // fprintf(hodf_fd, "Pid,Time,Event,delta(ms)\n");
    #endif
    double prev_time = 0;
    for (int i = 0; i < hodf_events_size; i++) {
        double delta = hodf_events[i].time - prev_time;
        if(i == 0) delta = 0;
        #ifndef USE_FILE
        printf("Pid: %d, Time: %.2f, Event: %s, Duration: %.2f\n", hodf_events[i].pid, hodf_events[i].time, hodf_events[i].event, delta * 1000);
        #else
        // fprintf(hodf_fd, "%d,%.6f,%s,%.6f\n", hodf_events[i].pid, hodf_events[i].time, hodf_events[i].event, delta * 1000);
        fprintf(hodf_fd, "%d,%.6f,%s\n", hodf_events[i].pid, hodf_events[i].time, hodf_events[i].event);
        #endif
        prev_time = hodf_events[i].time;
    }

    #ifdef USE_FILE
    fclose(hodf_fd);
    #endif
}

QemuCondList* h_qemu_cond_list_new(void) {
    QemuCondList *qcl = g_malloc(sizeof(QemuCondList));
    qcl->list = NULL;
    return qcl;
}

void h_qemu_cond_list_add(QemuCondList *qcl, QemuCond *cond) {
    printf("cond: %p\n", cond);
    h_print_pthread_cond(cond->cond);
    qcl->list = g_list_append(qcl->list, cond);
}

void h_qemu_cond_list_iterate(QemuCondList *qcl, void (*func)(QemuCond *)) {
    GList *l;
    for (l = qcl->list; l != NULL; l = l->next) {
        func(l->data);
    }
}

void h_print_pthread_cond(pthread_cond_t cond) {
    // if (cond == NULL) {
    //     printf("Condition variable is NULL.\n");
    //     return;
    // }

    // Print the raw bytes of the pthread_cond_t structure
    unsigned char *cond_bytes = (unsigned char *)&cond;
    size_t size = sizeof(pthread_cond_t);
    printf("pthread_cond_t at address %p, size %zu bytes:\n", (void *)&cond, size);
    
    for (size_t i = 0; i < size; ++i) {
        printf("%02x ", cond_bytes[i]);
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");

}

static void h_qemu_cond_patch(QemuCond *condptr){
    // QemuCond **condptr2 = *condptr;
    QemuCond *cond = condptr;
    int err = 0;
    
    hodf_add_event("Patching cond");
    printf("Patching cond [%d]\n", getpid());
    // clear the cond variable
    // memset(cond, 0, sizeof(QemuCond));
    err = pthread_cond_init(&cond->cond, NULL);

    // printf("Cond: %p\n", (void *)(*cond));
    h_print_pthread_cond(cond->cond);
    

    if(err != 0){
        printf("Error initializing cond: %d\n", err);
        return;
    }
    printf("Done patched cond\n");
    return;
}

void h_qemu_cond_list_patch(QemuCondList *qcl) {
    hodf_add_event("patching cond list");
    h_qemu_cond_list_iterate(qcl, h_qemu_cond_patch);
}

static void h_eval_initialize(const char *filename){
    // open a CSV file to write the data
    h_eval_fd = fopen(filename, "w");
    if(h_eval_fd == NULL){
        DEBUG_PRINT("Error opening file\n");
        return;
    }
    // write the header 
    fprintf(h_eval_fd, "pid,name,time\n");
    return;
}

int h_eval_reopen_fd(const char *filename){
    h_eval_fd = fopen(filename, "w");
    if(h_eval_fd == NULL){
        DEBUG_PRINT("Error opening file\n");
        return -1;
    }

    return 0;
}

// sorta hacky way to get the number of times the fd is registered
static int times_registered_fd = 0;

void h_initialize(void){
    const char *filename = "evals/eval.csv";
    
    #ifdef USE_FILE
    // FILE *hodf_fd = fopen(hodf_eval_file, "w");
    // if(hodf_fd == NULL){
    //     DEBUG_PRINT("Error opening file\n");
    //     return;
    // }
    // fclose(hodf_fd);
    #endif

    qemu_cond_list = h_qemu_cond_list_new();

    DEBUG_PRINT("Starting initializing");
    metadata_array = malloc(sizeof(hodf_metadata) * H_MAX_CPUS);
    pipe(parent_child_pipe);
    
    for(int i = 0; i < H_MAX_CPUS; i++){
        metadata_array[i].threadid = 0;
    }
    DEBUG_PRINT("Initialization done");

    int ret = event_notifier_init(&mon_create_event, 0);
    if(ret < 0){
        DEBUG_PRINT("Error initializing event notifier\n");
    }

    // h_eval_initialize(filename);
}

void h_save_metadata(QemuCond *halt_cond, pthread_t threadid, int cpu_index){
    memcpy(&metadata_array[cpu_index].halt_cond, halt_cond, sizeof(QemuCond));
    metadata_array[cpu_index].threadid = threadid;
    return;
}

void h_save_iothread_loop(GMainLoop *main_loop){
    h_iothread_main_loop = main_loop;
    return;
}

void h_intrpt_iothread_loop(void){
    // DEBUG_PRINT("Interrupting iothread loop\n");
    printf("Interrupting iothread loop\n");
    if(h_iothread_main_loop != NULL)
        g_main_loop_quit(h_iothread_main_loop);
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

void h_signal_child_done(void){
    DEBUG_PRINT("Signaling child done\n");
    write(parent_child_pipe[1], "done", sizeof("done"));
    DEBUG_PRINT("Signalled child done\n");
    return;
}

void h_wait_for_load_snapshot(void){
    char buffer[100];
    DEBUG_PRINT("Waiting for load snapshot in child\n");
    // compare the buffer with "done"
    while(strcmp(buffer, "done") != 0){
        read(parent_child_pipe[0], buffer, sizeof(buffer));
    }
    DEBUG_PRINT("Load snapshot done\n");
    return;
}

void h_hello(void){
    printf("Hello\n");
}

// make sure to call this function only with 
// hmp or qmp monitor
void h_set_qmp_server_fd(int fd){
    if(fd > h_qmp_fd)h_qmp_fd = fd;
    return;
}

int h_get_qmp_server_fd(void){
    return h_qmp_fd;
}


void h_register_monitor_fd(int fd){
    if(times_registered_fd >= 1){
        DEBUG_PRINT("Already registered monitor fd\n");
        return;
    }
    times_registered_fd++;
    DEBUG_PRINT("Registering monitor fd: %d\n", fd);
    monitor_client_fd = fd;
    return;
}

int h_get_monitor_fd(void){
    return monitor_client_fd;
}

int h_eval_record_time(const char *name){
    // get the current time
    struct timeval tv;
    gettimeofday(&tv, NULL); // Get the current time

    double time_in_sec = tv.tv_sec + tv.tv_usec / 1000000.0;
    int pid = getpid();

    fprintf(h_eval_fd, "%d,%s,%.6f\n", pid ? pid: 0, name, time_in_sec);
    fflush(h_eval_fd);

    return 0;
}

void h_set_parent_vcpu_fd(int fd){
    parent_vcpu_fd = fd;
    return;
}

void h_set_parent_mem_size(uint64_t mem_size){
    parent_mem_size = mem_size;
    return;
}

void h_set_child_vcpu_fd(int fd){
    child_vcpu_fd = fd;
    return;
}

void h_set_kvm_fd(int fd){
    kvm_fd = fd;
    return;
}

int h_enable_ept_sharing(void){
    int ret = 0;
    
    #ifdef USE_EPT
    struct odf_info o_info;
    o_info.parent_vcpu_fd = parent_vcpu_fd;
    o_info.child_vcpu_fd = child_vcpu_fd;
    o_info.mem_size = 0x200000;
    // o_info.mem_size = parent_mem_size;
    DEBUG_PRINT("Enabling ept sharing\n");
    hodf_add_event("Enabling EPT sharing");

    ret = ioctl(kvm_fd, KVM_EPT_ODF, &o_info);
    if(ret < 0){
        DEBUG_PRINT("Error enabling ept sharing\n");
        
        // create a string with the error
        char error[100];
        sprintf(error, "EPT shared: ERROR %d", ret);

        hodf_add_event(error);
        return ret;
    }
    
    hodf_add_event("EPT shared: DONE");
    DEBUG_PRINT("Enabled EPT sharing\n");
    #endif

    return ret;
}