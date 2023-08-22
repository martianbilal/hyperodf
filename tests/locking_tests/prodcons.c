#include <stdio.h>
#include <pthread.h>

#define NUM_CONSUMERS 1

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int data_ready = 0;

void* producer(void* arg) {
    pthread_mutex_lock(&mutex);
    data_ready = 1;  // Produce data
    pthread_cond_broadcast(&cond);  // Signal that data is ready to all waiting threads
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* consumer(void* arg) {
    int id = *((int*)arg);
    pthread_mutex_lock(&mutex);
    while (!data_ready) {
        pthread_cond_wait(&cond, &mutex);
    }
    printf("Consumer %d consumed data\n", id);  // Consume data
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    pthread_t prod, cons[NUM_CONSUMERS];
    int ids[NUM_CONSUMERS];

    for (int i = 0; i < NUM_CONSUMERS; i++) {
        ids[i] = i + 1;
        pthread_create(&cons[i], NULL, consumer, &ids[i]);
    }

    pthread_create(&prod, NULL, producer, NULL);

    pthread_join(prod, NULL);
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        pthread_join(cons[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);

    return 0;
}
