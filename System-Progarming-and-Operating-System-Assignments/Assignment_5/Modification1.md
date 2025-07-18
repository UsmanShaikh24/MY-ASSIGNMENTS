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
