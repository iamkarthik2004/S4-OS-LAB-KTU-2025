#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char *args[]={"./EXEC",NULL};
	execvp(args[0],args);
	return 0;
}
