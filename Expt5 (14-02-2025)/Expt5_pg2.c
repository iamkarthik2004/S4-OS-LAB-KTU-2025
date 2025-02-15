/*
14-02-2025
FRIDAY

EXPERIMENT NO: 5
MEMORY ALLOCATION METHODS
(A) BEST FIT

*/

#include <stdio.h>
int main() 
{
	int nb, np, i, j;


	printf("Enter the number of memory blocks: ");
	scanf("%d", &nb);
	
	int blockSize[nb], allocation[nb];
	for (i = 0; i < nb; i++) {
	printf("Enter size of block %d: ", i + 1);
	scanf("%d", &blockSize[i]);
	allocation[i] = -1;
}


	printf("Enter the number of processes: ");
	scanf("%d", &np);

	int processSize[np];
	for (i = 0; i < np; i++) 
	{
		printf("Enter size of process %d: ", i + 1);
		scanf("%d", &processSize[i]);
	}
	
	//BEST FIT
	 for (j = 0; j < nb; j++) {
            if (blockSize[j] >= processSize[i] && allocation[j] == -1) {
                int diff = blockSize[j] - processSize[i];
                if (diff < minDiff) {
                    minDiff = diff;
                    bestIdx = j;
                }
            }
        }


        if (bestIdx != -1) {
            allocation[bestIdx] = i;
        }
    }



	printf("\nProcess No.\tProcess Size\tBlock No.\n");
	for (i = 0; i < np; i++) 
	{
		printf("%d\t\t%d\t\t", i + 1, processSize[i]);
		int allocated = 0;
		for (j = 0; j < nb; j++) 
		{
			if (allocation[j] == i) 
			{
				printf("%d\n", j + 1);
				allocated = 1;
				break;
			}
		}
		if (!allocated) 
		{
			printf("Not Allocated\n");
		}
	}

return 0;
}
