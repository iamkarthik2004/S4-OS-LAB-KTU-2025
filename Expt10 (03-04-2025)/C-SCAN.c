#include <stdio.h>
#include <stdlib.h>

int main() {
    int RQ[100], i, j, n, TotalHeadMoment = 0, initial, size, move, index, temp;

    // Input: Number of disk requests
    printf("Enter the number of requests: ");
    scanf("%d", &n);

    // Input: Disk request queue
    printf("Enter the request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);

    // Input: Initial head position
    printf("Enter the initial head position: ");
    scanf("%d", &initial);

    // Input: Total disk size
    printf("Enter the total disk size: ");
    scanf("%d", &size);

    // Input: Direction of movement (0 for left, 1 for right)
    printf("Enter the direction (0 for left, 1 for right): ");
    scanf("%d", &move);

    // Sorting the request queue in ascending order
    for(i = 0; i < n; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(RQ[j] > RQ[j + 1]) {
                temp = RQ[j];
                RQ[j] = RQ[j + 1];
                RQ[j + 1] = temp;
            }
        }
    }

    // Finding the index of the first request greater than the initial head position
    for(i = 0; i < n; i++) {
        if(initial < RQ[i]) {
            index = i;
            break;
        }
    }

    if(move == 1) { // Moving towards higher track numbers (right direction)
        for(i = index; i < n; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Moving to the end of the disk
        TotalHeadMoment += abs(size - RQ[i - 1] - 1);
        // Jumping to the start (circular)
        TotalHeadMoment += abs(size - 1 - 0);
        initial = 0;

        // Servicing the remaining requests
        for(i = 0; i < index; i++) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    } else { // Moving towards lower track numbers (left direction)
        for(i = index - 1; i >= 0; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
        // Moving to track 0
        TotalHeadMoment += abs(RQ[i + 1] - 0);
        // Jumping to the highest track
        TotalHeadMoment += abs(size - 1 - 0);
        initial = size - 1;

        // Servicing the remaining requests
        for(i = n - 1; i >= index; i--) {
            TotalHeadMoment += abs(RQ[i] - initial);
            initial = RQ[i];
        }
    }

    // Output the total head movement
    printf("Total head movement is %d\n", TotalHeadMoment);
    
    return 0;
}