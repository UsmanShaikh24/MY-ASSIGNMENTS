### **Banker’s Algorithm for Deadlock Avoidance**

The Banker's Algorithm is used to avoid deadlocks by ensuring that the system operates in a safe state. Here's the implementation of the algorithm in C, covering the objectives and additional modifications.

---

### **1. Banker’s Algorithm Implementation**

#### **C Code for Deadlock Avoidance**

```c
#include <stdio.h>
#include <stdbool.h>

void calculateNeed(int need[][10], int max[][10], int allot[][10], int P, int R) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - allot[i][j];
        }
    }
}

bool isSafe(int processes[], int avail[], int max[][10], int allot[][10], int P, int R) {
    int need[10][10];
    calculateNeed(need, max, allot, P, R);

    bool finish[10] = {0};
    int safeSeq[10], work[10];
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0;
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                int j;
                for (j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        break;
                    }
                }
                if (j == R) {
                    for (int k = 0; k < R; k++) {
                        work[k] += allot[p][k];
                    }
                    safeSeq[count++] = p;
                    finish[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            printf("System is in an unsafe state.\n");
            return false;
        }
    }

    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
    return true;
}

int main() {
    int P = 5; // Number of processes
    int R = 3; // Number of resources

    int processes[] = {0, 1, 2, 3, 4};

    // Available resources
    int avail[] = {3, 3, 2};

    // Maximum demand of each process
    int max[][10] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Resources allocated to each process
    int allot[][10] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    isSafe(processes, avail, max, allot, P, R);

    return 0;
}
```

---

### **2. Additional Modifications**

#### **Modification 1: Calculate Available Matrix**

If the available matrix is not provided, it can be calculated as:
\[
\text{Available[i]} = \text{Total[i]} - \sum \text{Allotted[i]}
\]

Add this code snippet to calculate the `avail[]` array dynamically:

```c
void calculateAvailable(int avail[], int total[], int allot[][10], int P, int R) {
    for (int i = 0; i < R; i++) {
        avail[i] = total[i];
        for (int j = 0; j < P; j++) {
            avail[i] -= allot[j][i];
        }
    }
}
```

Modify the `main()` function to include:

```c
int total[] = {10, 5, 7}; // Total resources in the system
calculateAvailable(avail, total, allot, P, R);
```

---

#### **Modification 2: Handle Additional Requests**

Add a function to handle an additional request from a process after the first safe sequence:

```c
bool requestResources(int process, int request[], int avail[], int max[][10], int allot[][10], int need[][10], int R) {
    for (int i = 0; i < R; i++) {
        if (request[i] > need[process][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return false;
        }
        if (request[i] > avail[i]) {
            printf("Error: Resources are not available.\n");
            return false;
        }
    }

    for (int i = 0; i < R; i++) {
        avail[i] -= request[i];
        allot[process][i] += request[i];
        need[process][i] -= request[i];
    }

    printf("Resources allocated successfully.\n");
    return true;
}
```

Modify the `main()` function to test additional requests:

```c
int request[] = {1, 0, 2}; // Example request for Process 1
if (requestResources(1, request, avail, max, allot, need, R)) {
    isSafe(processes, avail, max, allot, P, R);
}
```

---

### **3. Comparative Testing**

Test the program with various inputs:
1. **Normal Operation**: Execute with given inputs.
2. **Unsafe State**: Alter the `avail[]` or `max[][]` matrix to test unsafe scenarios.
3. **Additional Requests**: Test new requests to validate the system's deadlock avoidance.

This ensures you understand both safe and unsafe states and how the Banker's Algorithm works.