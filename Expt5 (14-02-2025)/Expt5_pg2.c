/*
14-02-2025
FRIDAY

EXPERIMENT NO: 5
MEMORY ALLOCATION METHODS
(A) BEST FIT

*/

#include <stdio.h>

int main() {
    int nb, np, i, j;

    // Input number of memory blocks
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    
    int blockSize[nb], allocation[nb];

    // Input block sizes and initialize allocation array
    for (i = 0; i < nb; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
        allocation[i] = -1; // Initialize all blocks as unallocated
    }

    // Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &np);
    
    int processSize[np];

    // Input process sizes
    for (i = 0; i < np; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &processSize[i]);
    }

    // Best Fit Allocation
    for (i = 0; i < np; i++) {
        int bestIndex = -1;
        
        for (j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i] && allocation[j] == -1) {
                if (bestIndex == -1 || blockSize[j] < blockSize[bestIndex]) {
                    bestIndex = j; // Select the best (smallest fitting) block
                }
            }
        }

        // Allocate process if a suitable block is found
        if (bestIndex != -1) {
            allocation[bestIndex] = i;
        }
    }

    // Display allocation details
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < np; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        int allocated = 0;
        
        for (j = 0; j < nb; j++) {
            if (allocation[j] == i) {
                printf("B%d\n", j + 1);
                allocated = 1;
                break;
            }
        }
        
        if (!allocated) {
            printf("Not Allocated\n");
        }
    }

    return 0;
}
