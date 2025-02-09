/* 
27-01-2025
Experiment No: 4
Scheduling Algorithm
(C) Priority Scheduling*/

#include <stdio.h>
int main()
{
	int n;
	float avgwt=0, avgtat=0;
	int tatTot=0, wtTot=0;
	
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	
	int bt[n], wt[n], tat[n], pid[n], priority[n];
	printf("Enter the Burst Time and Priority for each Processes: \n");
	for(int i=0; i<n; i++)
	{
		pid[i]=i+1;
		printf("Burst time of P%d: ", pid[i]);
		scanf("%d", &bt[i]);
		printf("Priority of P%d: ", pid[i]);
		scanf("%d", &priority[i]);
	}
	
	//Bubble Sorting
	for(int i=0; i<n-1; i++)
	{
	    for(int j=i+1; j<n; j++)
	    {
		if(priority[i]>priority[j])
		{
			
			
			//Swap Burst Time
			int temp = bt[i];
			bt[i] = bt[j];
			bt[j] = temp;
			
			//Swap PID
			temp = pid[i];
			pid[i] = pid[j];
			pid[j] = temp;
			
			//Swap Priority
			temp = priority[i];
			priority[i] = priority[j];
			priority[j] = temp;
		}
	    }
	}
	
	//Waiting Time
	wt[0] = 0;
	for(int i=1; i<n; i++)
	{
	    wt[i] = wt[i-1] + bt[i-1];
	}
	
	//Turn Around Time
	for(int i=0; i<n; i++)
	{
	    tat[i] = bt[i] + wt[i];
	}
	
	printf("\n");
	
	
	//Process Details
	printf("PROCESS ID\tBurst Time\tPriority\tWaiting Time\tTurn Around Time\n");
	for(int i=0; i<n; i++)
	{
	    printf("P%d:  ", pid[i]);
            printf("\t\t%d", bt[i]);
            printf("\t\t%d", priority[i]);
            printf("\t\t%d", wt[i]);
            printf("\t\t%d", tat[i]);
            printf("\n");
	}
	
	// Total Turnaround and Waiting Time Calcu
	for (int i = 0; i < n; i++) 
	{
            tatTot += tat[i];
            wtTot += wt[i];
        }
        
        avgwt = (float)wtTot / n;
        avgtat = (float)tatTot / n;
        
        printf("\n");
        
        printf("Average Turnaround Time: %.2f\n", avgtat);
        printf("Average Waiting Time: %.2f\n", avgwt);
        
        //Gantt Chart
        printf("\nGantt Chart:\n");
        
        
        // Print process pid
        for (int i = 0; i < n; i++) 
        {
            printf("   P%d   ", pid[i]);
        }
        
        printf("\n");
        
        // Print time sequence
        printf("0");
        for (int i = 0; i < n; i++) 
        {
            printf("      %d", tat[i]);
        }
        
        printf("\n");
	
	return 0;
	

}
