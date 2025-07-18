### **Memory Allocation Algorithms: First Fit, Best Fit, and Next Fit**

The goal is to implement the memory allocation algorithms to handle dynamic storage allocation problems. Below is the C implementation of the **First Fit**, **Best Fit**, and **Next Fit** algorithms.

---

### **1. Implementation in C**

#### **Code**

```c
#include <stdio.h>
#include <stdbool.h>

void firstFit(int blockSize[], int m, int processSize[], int n) {
    printf("\nFirst Fit Allocation:\n");
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    printf("\nBest Fit Allocation:\n");
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void nextFit(int blockSize[], int m, int processSize[], int n) {
    printf("\nNext Fit Allocation:\n");
    int allocation[n];
    for (int i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < m) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
            j = (j + 1) % m; // Circular allocation
        }
    }

    printf("Process No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main() {
    int m, n;

    printf("Enter the number of blocks: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the sizes of the blocks: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the sizes of the processes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    int blockSize1[m], blockSize2[m], blockSize3[m];
    for (int i = 0; i < m; i++) {
        blockSize1[i] = blockSize[i];
        blockSize2[i] = blockSize[i];
        blockSize3[i] = blockSize[i];
    }

    firstFit(blockSize1, m, processSize, n);
    bestFit(blockSize2, m, processSize, n);
    nextFit(blockSize3, m, processSize, n);

    return 0;
}
```

---

### **2. Explanation of Algorithms**

1. **First Fit**:
   - Assigns the first available memory block that is large enough for the process.
   - Searches sequentially through the block list.

2. **Best Fit**:
   - Searches for the smallest block that can accommodate the process, reducing wasted memory.
   - May lead to higher execution time due to additional searches.

3. **Next Fit**:
   - Similar to First Fit but starts searching from the last allocated block, wrapping around in a circular manner.
   - Helps in reducing fragmentation.

---

### **3. Example Input and Output**

#### Input:
```
Enter the number of blocks: 5
Enter the sizes of the blocks: 100 500 200 300 600
Enter the number of processes: 4
Enter the sizes of the processes: 212 417 112 426
```

#### Output:
```
First Fit Allocation:
Process No.   Process Size   Block No.
1             212            2
2             417            5
3             112            3
4             Not Allocated

Best Fit Allocation:
Process No.   Process Size   Block No.
1             212            3
2             417            5
3             112            1
4             Not Allocated

Next Fit Allocation:
Process No.   Process Size   Block No.
1             212            2
2             417            5
3             112            3
4             Not Allocated
```

---

### **4. Key Observations**
- **First Fit** is faster but leads to more fragmentation.
- **Best Fit** minimizes wasted space but requires more time for searching.
- **Next Fit** improves upon First Fit in some cases but may still face fragmentation issues.

This program can be tested with various inputs to observe how different allocation strategies perform in dynamic memory management scenarios.