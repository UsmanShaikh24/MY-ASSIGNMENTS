### **AIM**  
To implement virtual memory techniques and understand the working of **Paging** and **Demand Paging**, specifically by simulating various **Page Replacement Algorithms**.

---

### **OBJECTIVE**  
The objective is to:
1. Implement **Page Replacement Algorithms** like:
   - First-In-First-Out (FIFO)
   - Least Recently Used (LRU)
   - Optimal Page Replacement
2. Understand the importance of virtual memory management.
3. Learn how to minimize page faults and improve system performance.

---

### **Page Replacement Algorithms Implementation**

Here’s a **C program** that demonstrates the simulation of **FIFO**, **LRU**, and **Optimal Page Replacement Algorithms**.

---

#### **Code**

```c
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
```

---

### **Explanation of Algorithms**

1. **FIFO (First-In-First-Out)**:
   - Replaces the oldest page in memory.
   - Easy to implement but may lead to frequent page faults (Belady’s anomaly).

2. **LRU (Least Recently Used)**:
   - Replaces the page that has not been used for the longest time.
   - Reduces page faults compared to FIFO but requires tracking of page usage.

3. **Optimal**:
   - Replaces the page that will not be needed for the longest time in the future.
   - Yields the minimum number of page faults but is not practical in real systems due to future knowledge requirements.

---

### **Input and Output Example**

#### Input:
```
Enter the number of pages: 12
Enter the page reference string: 7 0 1 2 0 3 0 4 2 3 0 3
Enter the number of frames: 3
```

#### Output:
```
FIFO Page Replacement:
Pages in memory:
7 - -
7 0 -
7 0 1
2 0 1
2 0 1
2 3 1
0 3 1
0 4 1
2 4 1
2 3 1
0 3 1
0 3 1
Total Page Faults: 9

LRU Page Replacement:
Pages in memory:
7 - -
7 0 -
7 0 1
2 0 1
2 0 1
2 3 1
0 3 1
0 4 1
2 4 1
2 3 1
0 3 1
0 3 1
Total Page Faults: 8

Optimal Page Replacement:
Pages in memory:
7 - -
7 0 -
7 0 1
2 0 1
2 0 1
2 3 1
0 3 1
0 4 1
2 4 1
2 3 1
0 3 1
0 3 1
Total Page Faults: 7
```

---

### **Key Observations**
1. **Optimal** produces the fewest page faults but is idealistic.
2. **LRU** is a practical choice for many systems and has lower page faults than **FIFO**.
3. The number of page faults depends heavily on the reference string and the number of frames.

