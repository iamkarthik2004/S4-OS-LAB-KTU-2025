/*
EXPERIMENT NO: 9
PAGE REPLACEMENT ALGORITHM
14 - 03 - 2025
FRIDAY
(B) LRU PAGE REPLACEMENT
*/

#include <stdio.h>

void lruPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], index[capacity], pageFaults = 0, pageHits = 0;
    

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        index[i] = -1;
    }
    
    printf("--------------------------");
    printf("\nLRU Page Replacement\n");
    printf("--------------------------\n");


    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                index[j] = i;
                pageHits++;
                break;
            }
        }
        

        if (!found) {
            if (i < capacity) {
                frames[i] = page;
                index[i] = i;
            } else {
                int minIndex = 0;
                for (int j = 1; j < capacity; j++) {
                    if (index[j] < index[minIndex]) {
                        minIndex = j;
                    }
                }
                frames[minIndex] = page;
                index[minIndex] = i;
            }
            pageFaults++;
        }

        printf("Page %d -> [", page);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1)
                printf(" %d ", frames[j]);
            else
                printf(" - ");
        }
        printf("] %s\n", found ? "Hit " : "Miss ");
    }

    float hitRatio = (float) pageHits / n;
    float missRatio = (float) pageFaults / n;

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Hit Ratio: %.2f\n", hitRatio);
    printf("Miss Ratio: %.2f\n", missRatio);
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

    lruPageReplacement(pages, n, capacity);

    return 0;
}

