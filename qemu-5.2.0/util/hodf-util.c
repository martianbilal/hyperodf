#include "util/hodf-util.h"
#include "qemu/event_notifier.h"
#include "qemu/thread.h"
#include "qemu/typedefs.h"

// debug flag for hodf
// #define DBG_HODF

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
static const char *hodf_eval_file = "evals/hodf.csv";
#endif

//======================Global Vars============================
hodf_metadata *metadata_array;

EventNotifier mon_create_event;
int parent_child_pipe[2];

hodf_event *hodf_events = NULL;
int hodf_events_size =0;

GMainLoop *h_iothread_main_loop;
int h_qmp_fd = 0;


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
    #ifdef USE_FILE
    FILE *hodf_fd = fopen(hodf_eval_file, "w");
    #endif
    for (int i = 0; i < hodf_events_size; i++) {
        #ifndef USE_FILE
        printf("Pid: %d, Time: %.2f, Event: %s\n", hodf_events[i].pid, hodf_events[i].time, hodf_events[i].event);
        #else
        fprintf(hodf_fd, "%d,Pid: %d, Time: %.2f, Event: %s\n", hodf_events_size, hodf_events[i].pid, hodf_events[i].time, hodf_events[i].event);
        #endif
    }

    #ifdef USE_FILE
    fclose(hodf_fd);
    #endif
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
