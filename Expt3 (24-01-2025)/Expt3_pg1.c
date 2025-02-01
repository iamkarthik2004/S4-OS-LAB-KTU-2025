/* 
24-01-2025
Experiment No: 3
System Callss of Linux Operating Systems
(A)*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

//child pid = -1 (process creation unsuccessful)
//child pid = 0 (process creation successful)

int main()
{
	pid_t childpid=fork();
	if(childpid==-1)
	{
		printf("Child Creation unsuccessful\n");
	}
	else if(childpid==0)
	{
		printf("Child Creation Successful\n");
		printf("PID %d\n",getpid());
		printf("Parent PID %d\n",getppid());
	}
	else
	{
		printf("Parent Process\n");
		printf("PID %d\n",getpid());
		printf("Child PID %d\n",childpid);
		wait(NULL);
		printf("Child Finished\n");
		exit(0);
	}

	return 0;
	
}

