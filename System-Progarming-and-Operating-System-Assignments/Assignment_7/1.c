// Page Replacement Algorithms Implementation

#include <stdio.h>
#include <limits.h>

void fifo(int pages[], int n, int capacity) {
    printf("\nFIFO Page Replacement:\n");
    int frames[capacity];
    int pageFaults = 0, next = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    printf("Pages in memory:\n");
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[next] = pages[i];
            next = (next + 1) % capacity;
            pageFaults++;
        }

        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void lru(int pages[], int n, int capacity) {
    printf("\nLRU Page Replacement:\n");
    int frames[capacity], age[capacity];
    int pageFaults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    printf("Pages in memory:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, lruIndex = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                age[j] = i; // Update age
                break;
            }
        }

        if (!found) {
            if (i >= capacity) {
                int minAge = INT_MAX;
                for (int j = 0; j < capacity; j++) {
                    if (age[j] < minAge) {
                        minAge = age[j];
                        lruIndex = j;
                    }
                }
            } else {
                lruIndex = i;
            }

            frames[lruIndex] = pages[i];
            age[lruIndex] = i;
            pageFaults++;
        }

        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

void optimal(int pages[], int n, int capacity) {
    printf("\nOptimal Page Replacement:\n");
    int frames[capacity];
    int pageFaults = 0;
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    printf("Pages in memory:\n");
    for (int i = 0; i < n; i++) {
        int found = 0, farthest = -1, replaceIndex = -1;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            for (int j = 0; j < capacity; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }

                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) break;
                }

                if (k == n) {
                    replaceIndex = j;
                    break;
                } else if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
            }

            frames[replaceIndex] = pages[i];
            pageFaults++;
        }

        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) printf("%d ", frames[j]);
            else printf("- ");
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int n, capacity;

    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    fifo(pages, n, capacity);
    lru(pages, n, capacity);
    optimal(pages, n, capacity);

    return 0;
}
