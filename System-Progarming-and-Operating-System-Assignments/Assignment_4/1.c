// CPU Scheduling Algorithms
// CPU scheduling is a critical aspect of an operating system, determining how processes are assigned to the CPU for execution. Below is the implementation of various CPU scheduling algorithms in C, followed by suggestions for data structure variations, comparisons, and problem execution for various inputs.


// FCFS (First-Come, First-Served)



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
