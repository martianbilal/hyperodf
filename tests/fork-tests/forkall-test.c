#include "forkall-coop.h"
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Slave thread function
void *slave_function(void *arg) {
    int *id_ptr = (int *)arg;
    int id = *id_ptr;
    ski_forkall_thread_add_self_tid();


    while (1) {
        int did_fork, is_child;
        ski_forkall_slave(&did_fork, &is_child);

        if (did_fork) {
            if (is_child) {
                printf("Child: Slave Thread %d is duplicated in child process\n", id);
            } else {
                printf("Parent: Slave Thread %d continues in parent process\n", id);
            }
            break;
        } else {
            // Simulate some work
            printf("Slave Thread %d is working\n", id);
            sleep(1);
        }
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 1, id2 = 2;

    // Initialize the ski_forkall system
    ski_forkall_initialize();

    // Create and register slave threads
    ski_forkall_pthread_create(&thread1, NULL, slave_function, &id1);
    // ski_forkall_pthread_create(&thread2, NULL, slave_function, &id2);

    // Simulate some work in the main thread
    sleep(2);

    // Signal the condition variable, allowing the first slave thread to proceed
    

    // Main thread (master) initiates forkall
    pid_t child_pid = ski_forkall_master();

    if (child_pid > 0) {
        // This block will be executed in the parent process
        printf("Parent: Master Thread created child process with pid %d\n", child_pid);
    } else {
        // This block will be executed in the child process
        printf("Child: Master Thread is running in child process\n");
    }

    // Simulate continuing work in both parent and child processes
    sleep(5);

    return 0;
}
