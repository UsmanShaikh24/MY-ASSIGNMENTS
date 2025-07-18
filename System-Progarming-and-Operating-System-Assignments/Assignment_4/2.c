// SJF (Shortest Job First) - Non-preemptive

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
