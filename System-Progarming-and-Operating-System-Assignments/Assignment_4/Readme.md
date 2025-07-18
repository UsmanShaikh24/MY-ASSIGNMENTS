### **CPU Scheduling Algorithms**

CPU scheduling is a critical aspect of an operating system, determining how processes are assigned to the CPU for execution. Below is the implementation of various CPU scheduling algorithms in C, followed by suggestions for data structure variations, comparisons, and problem execution for various inputs.

---

### **1. Implement Scheduling Algorithms**

#### **FCFS (First-Come, First-Served)**

```c
#include <stdio.h>

void fcfs(int processes[], int n, int bt[], int wt[], int tat[]) {
    // Waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

void display(int processes[], int n, int bt[], int wt[], int tat[]) {
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {21, 3, 6, 2};
    int wt[n], tat[n];

    fcfs(processes, n, burst_time, wt, tat);
    display(processes, n, burst_time, wt, tat);

    return 0;
}
```

---

#### **SJF (Shortest Job First) - Non-preemptive**

```c
#include <stdio.h>

void sjf(int processes[], int n, int bt[], int wt[], int tat[]) {
    int temp, pos;

    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        pos = i;
        for (int j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos]) {
                pos = j;
            }
        }

        // Swap burst times
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        // Swap process IDs
        temp = processes[i];
        processes[i] = processes[pos];
        processes[pos] = temp;
    }

    // Calculate waiting time
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }
}

int main() {
    int processes[] = {1, 2, 3, 4};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {6, 8, 7, 3};
    int wt[n], tat[n];

    sjf(processes, n, burst_time, wt, tat);
    display(processes, n, burst_time, wt, tat);

    return 0;
}
```

---

#### **Round Robin Scheduling**

```c
#include <stdio.h>

void roundRobin(int processes[], int n, int bt[], int quantum) {
    int wt[n], tat[n], remaining_bt[n], time = 0;
    for (int i = 0; i < n; i++) {
        remaining_bt[i] = bt[i];
    }

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_bt[i] > 0) {
                done = 0;
                if (remaining_bt[i] > quantum) {
                    time += quantum;
                    remaining_bt[i] -= quantum;
                } else {
                    time += remaining_bt[i];
                    wt[i] = time - bt[i];
                    remaining_bt[i] = 0;
                }
            }
        }
        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    display(processes, n, bt, wt, tat);
}

int main() {
    int processes[] = {1, 2, 3};
    int n = sizeof(processes) / sizeof(processes[0]);
    int burst_time[] = {10, 5, 8};
    int quantum = 2;

    roundRobin(processes, n, burst_time, quantum);

    return 0;
}
```

---

### **2. Implement Using Different Data Structures**

Instead of using arrays, you can use other data structures like linked lists, heaps, or queues. For example:
- **Linked List**: Can store processes dynamically when processes arrive at different times.
- **Priority Queue**: Useful for priority-based scheduling algorithms.
- **Circular Queue**: Ideal for Round Robin scheduling.

---

### **3. Comparative Statement of Scheduling Algorithms**

| Algorithm      | Advantages                                   | Disadvantages                          | Best Use Case                       |
|----------------|---------------------------------------------|----------------------------------------|-------------------------------------|
| FCFS           | Simple to implement                        | High waiting time for long processes   | Batch systems                       |
| SJF            | Minimizes average waiting time             | May cause starvation                   | Systems with known burst times      |
| Round Robin    | Fair to all processes                      | Higher average turnaround time         | Time-sharing systems                |
| Priority       | Processes with higher priority get CPU     | Can lead to starvation for low priority| Systems with prioritized tasks      |

---

### **4. Execute Problem Statements for Various Inputs**

#### Example Inputs:
1. **FCFS Input**: Processes = `{P1, P2, P3}`, Burst Times = `{10, 5, 8}`
2. **SJF Input**: Processes = `{P1, P2, P3}`, Burst Times = `{6, 8, 7}`
3. **Round Robin Input**: Processes = `{P1, P2, P3}`, Burst Times = `{24, 3, 3}`, Quantum = `4`

By running the programs, you'll observe:
- FCFS leads to high waiting time for processes arriving late.
- SJF minimizes average waiting time but can starve longer processes.
- Round Robin ensures fair CPU allocation at the cost of higher turnaround times.

