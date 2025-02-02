/* 
27-01-2025
Experiment No: 4
Scheduling Algorithm
(A) SJF - Shortest Job First*/

#include <stdio.h>

int main() {
    int n;
    float avgwt = 0, avgtat = 0;
    int tatTot = 0, wtTot = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], pid[n];

    // Burst Time Input
    printf("Enter the Burst Time of each process:\n");
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;  // Assigning process IDs (P1, P2, P3, ...)
        printf("P%d: ", pid[i]);
        scanf("%d", &bt[i]);
    }

    // Sorting processes based on Burst Time (SJF Scheduling)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (bt[i] > bt[j]) {
                // Swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // Swap process IDs
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Waiting Time Calculation
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround Time Calculation
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    printf("\n");

    // Process Details
    printf("PROCESS ID\tBurst Time\tWaiting Time\tTurnAround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d:  ", pid[i]);
        printf("\t\t\t%d", bt[i]);
        printf("\t\t\t\t%d", wt[i]);
        printf("\t\t\t\t%d", tat[i]);
        printf("\n");
    }
    
    // Total Turnaround and Waiting Time Calculation
    for (int i = 0; i < n; i++) {
        tatTot += tat[i];
        wtTot += wt[i];
    }

    avgwt = (float)wtTot / n;
    avgtat = (float)tatTot / n;

    printf("\n");

    printf("Average Turnaround Time: %.2f\n", avgtat);
    printf("Average Waiting Time: %.2f\n", avgwt);

    //Gantt Chart Representation
    printf("\nGantt Chart:\n");

    // Print process labels
    for (int i = 0; i < n; i++) {
        printf("   P%d   ", pid[i]);
    }
    printf("\n");

    // Print time sequence
    printf("0");
    for (int i = 0; i < n; i++) {
        printf("      %d", tat[i]);
    }
    printf("\n");

    return 0;
}
