#include <stdio.h>

// Function to implement LRU Page Replacement
void lruPageReplacement(int pages[], int n, int capacity) {
    int frames[capacity], index[capacity], pageFaults = 0, pageHits = 0;

    // Initialize frames and index arrays
    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;  // Empty frames
        index[i] = -1;   // Index of the page in frames
    }

    printf("\nLRU Page Replacement:\n");
    printf("----------------------------\n");

    // Iterate through the page reference string
    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // Check if the page is already in one of the frames
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                found = 1;    // Page found in frames
                index[j] = i; // Update the last accessed time (index)
                pageHits++;    // Increment page hits
                break;
            }
        }

        // If the page is not found (page fault)
        if (!found) {
            if (i < capacity) {
                // If there's space, simply place the page in an empty frame
                frames[i] = page;
                index[i] = i;
            } else {
                // If no space, replace the least recently used (LRU) page
                int minIndex = 0;
                for (int j = 1; j < capacity; j++) {
                    if (index[j] < index[minIndex]) {
                        minIndex = j;
                    }
                }

                frames[minIndex] = page;  // Replace the LRU page
                index[minIndex] = i;      // Update the last accessed time
            }
            pageFaults++;  // Increment page faults
        }

        // Display the current state of frames
        printf("Page %d -> [", page);
        for (int j = 0; j < capacity; j++) {
            if (frames[j] != -1) {
                printf(" %d ", frames[j]);
            } else {
                printf(" - ");
            }
        }
        printf("] %s\n", found ? "Hit" : "Miss");
    }

    // Calculate and display hit and miss ratios
    float hitRatio = (float) pageHits / n;
    float missRatio = (float) pageFaults / n;

    printf("\nTotal Page Faults: %d\n", pageFaults);
    printf("Total Page Hits: %d\n", pageHits);
    printf("Hit Ratio: %.2f\n", hitRatio);
    printf("Miss Ratio: %.2f\n", missRatio);
}

int main() {
    int n, capacity;

    // Input the number of pages and page reference string
    printf("Enter the number of pages: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &capacity);

    // Call the LRU page replacement function
    lruPageReplacement(pages, n, capacity);

    return 0;
}

