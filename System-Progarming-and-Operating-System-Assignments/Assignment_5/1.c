// Banker’s Algorithm Implementation
// C Code for Deadlock Avoidance

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
