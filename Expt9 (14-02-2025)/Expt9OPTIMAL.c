#include <stdio.h>

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], pageFaults = 0, pageHits = 0;

    for (int i = 0; i < capacity; i++)
        frames[i] = -1;

    printf("\nOptimal Page Replacement:\n");
    printf("----------------------------\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;
                pageHits++;
                break;
            }
        }
        if (!found) {
            if (i < capacity) {
                frames[i] = page;
            } else {
                int farthest = -1, replaceIndex = -1;

                for (int j = 0; j < capacity; j++) {
                    int k;
                    for (k = i + 1; k < n; k++) {
                        if (frames[j] == pages[k])
                            break;
                    }
                    if (k > farthest) {
                        farthest = k;
                        replaceIndex = j;
                    }
                }
                frames[replaceIndex] = page;
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
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    optimalPageReplacement(pages, n, capacity);

    return 0;
}
