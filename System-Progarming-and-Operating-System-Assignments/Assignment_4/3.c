// Round Robin Scheduling

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
