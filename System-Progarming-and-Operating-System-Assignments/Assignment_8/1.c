// Code for Reader-Writer Problem

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

sem_t wrt;          // Semaphore for writer access
pthread_mutex_t mutex; // Mutex to synchronize readers
int shared_data = 0;   // Shared resource
int reader_count = 0;  // Number of readers accessing the shared resource

void *reader(void *arg) {
    int reader_id = *((int *)arg);

    // Reader entry section
    pthread_mutex_lock(&mutex);
    reader_count++;
    if (reader_count == 1) {
        sem_wait(&wrt); // First reader locks the writer
    }
    pthread_mutex_unlock(&mutex);

    // Critical section for reading
    printf("Reader %d: Reading shared data = %d\n", reader_id, shared_data);
    sleep(1);

    // Reader exit section
    pthread_mutex_lock(&mutex);
    reader_count--;
    if (reader_count == 0) {
        sem_post(&wrt); // Last reader unlocks the writer
    }
    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *writer(void *arg) {
    int writer_id = *((int *)arg);

    // Writer entry section
    sem_wait(&wrt);

    // Critical section for writing
    shared_data += 1;
    printf("Writer %d: Writing shared data = %d\n", writer_id, shared_data);
    sleep(1);

    // Writer exit section
    sem_post(&wrt);

    return NULL;
}

int main() {
    pthread_t readers[5], writers[3];
    int reader_ids[5], writer_ids[3];

    // Initialize mutex and semaphore
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt, 0, 1);

    // Create reader threads
    for (int i = 0; i < 5; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    // Create writer threads
    for (int i = 0; i < 3; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    // Wait for all threads to complete
    for (int i = 0; i < 5; i++) {
        pthread_join(readers[i], NULL);
    }
    for (int i = 0; i < 3; i++) {
        pthread_join(writers[i], NULL);
    }

    // Destroy mutex and semaphore
    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
