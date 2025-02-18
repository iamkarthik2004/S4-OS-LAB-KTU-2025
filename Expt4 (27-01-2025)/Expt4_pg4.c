/* 
21-01-2025
Experiment No: 4
Scheduling Algorithm
(D) Round Robin*/

#include<stdio.h>
void roundRobin(int processes[],int n,int BT[],int quantum){
	int rem_bt[n],wt[n],tat[n];
	for(int i=0;i<n;i++){
		rem_bt[i]=BT[i];
	}
	int t=0;
	printf("\nGantt Chart\n");
	printf("0");
	while(1){
		int done=1;
		for(int i=0;i<n;i++){
			if (rem_bt[i] > 0) {
				done=0;
				if(rem_bt[i]>quantum){
					t+=quantum;
					rem_bt[i]-=quantum;
					printf("| P%d | %d",processes[i],t);
				}
				else{
					t+=rem_bt[i];
					wt[i]=t-BT[i];
					rem_bt[i]=0;
					printf(" | P%d | %d",processes[i],t);
					}
				}
			}
		
	if(done==1)
		break;
	}
	printf("\n");
	for(int i=0;i<n;i++){
		tat[i]=BT[i]+wt[i];
	}
	 printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	 for (int i = 0; i < n; i++)
        printf("P%d\t%d\t\t%d\t\t%d\n", processes[i], BT[i], wt[i], tat[i]);

    float total_wt = 0, total_tat = 0;
	 for(int i=0;i<n;i++){
	 	total_wt+=wt[i];
	 	total_tat+=tat[i];
	 }
	 printf("\n Average Waiting time: %.2f",total_wt/n);
	 printf("\n Average Turnaround time: %.2f",total_tat/n);
	
}
int main(){
	int n,quantum;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	int processes[n],BT[n];
	printf("Enter the burst time of each process: \n");
	for(int i=0;i<n;i++){
		processes[i]=i+1;
		printf("P%d: ",i+1);
		scanf("%d",&BT[i]);
		
	}
	printf("Enter the time quantum: ");
	scanf("%d",&quantum);
	roundRobin(processes,n,BT,quantum);
	return 0;
}
