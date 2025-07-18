### **AIM**  
To implement the Reader-Writer or Producer-Consumer problem using **mutex** and **semaphore**.

---

### **OBJECTIVE**
1. Understand and implement **thread synchronization** using mutexes and semaphores.
2. Gain hands-on experience with **POSIX threads (pthreads)**.
3. Explore thread creation, execution, and synchronization.
4. Prevent race conditions by implementing critical section behavior.
5. Learn the differences between mutex and semaphore for ensuring thread safety.

---

### **Implementation: Reader-Writer Problem Using Mutex and Semaphore**

Below is a C program for the **Reader-Writer problem** that ensures:
1. **Multiple Readers** can read simultaneously.
2. **Only one Writer** can write at a time.
3. **No Reader** can read while a Writer is writing.

---

#### **Code for Reader-Writer Problem**

```c
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
```

---

### **Explanation**

1. **Shared Variables**:
   - `shared_data`: Represents the shared resource (e.g., database, file, etc.).
   - `reader_count`: Tracks the number of active readers.

2. **Semaphores and Mutex**:
   - `sem_t wrt`: Ensures only one writer accesses the shared resource at a time.
   - `pthread_mutex_t mutex`: Synchronizes reader count updates to avoid race conditions.

3. **Readers**:
   - Multiple readers can access the shared resource simultaneously.
   - The first reader locks the writer to prevent writing while reading.
   - The last reader unlocks the writer.

4. **Writers**:
   - Only one writer can access the shared resource at a time.
   - Writing is blocked if any reader is reading.

5. **Thread Creation**:
   - Reader and writer threads are created using `pthread_create`.

6. **Thread Synchronization**:
   - Readers and writers are synchronized using semaphores and mutex locks to prevent race conditions.

---

### **Output**

#### Example Execution:

```
Writer 1: Writing shared data = 1
Reader 1: Reading shared data = 1
Reader 2: Reading shared data = 1
Writer 2: Writing shared data = 2
Reader 3: Reading shared data = 2
Reader 4: Reading shared data = 2
Reader 5: Reading shared data = 2
Writer 3: Writing shared data = 3
```

---

### **Key Learnings**
1. **Semaphores** are ideal for managing exclusive access to shared resources.
2. **Mutex locks** are used to protect critical sections and shared variables.
3. Proper synchronization prevents **deadlocks** and **race conditions**.
