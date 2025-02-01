/* 
24-01-2025
Experiment No: 3
System Callss of Linux Operating Systems
(B)
second.c*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *args[]={"./EXEC",NULL};
	execvp(args[0],args);
	return 0;
}
