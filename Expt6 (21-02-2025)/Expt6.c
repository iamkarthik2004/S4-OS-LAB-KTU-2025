/*
21-02-2025
FRIDAY

EXPERIMENT NO: 6

k - Size
*/

#include <stdio.h>
#include <stdlib.h>
int mutex=1,full=0,x=0, empty;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer produce item %d", x);
	++mutex;
}

void consumer()
{
	--mutex;
	--full;
	++empty;
	printf("\nConsumer consumers item %d", x);
	x--;
	++mutex;
}

int main(){
	
	int n, i, k;
	printf("Enter the Size of the Buffer: ");
	scanf("%d", &k);
	empty=k;
	printf("\nSelect 1 for Producer");
	printf("\nSelect 2 for Consumer");
	printf("\nSelect 3 for Exit");
	
	for(int i=1; i>0; i++)
	{
		printf("\nEnter Your Choice: ");
		scanf("%d", &n);
		switch(n)
			{
				case 1: 
				if((mutex==1)&&(empty!=0))
				{
					producer();
				}
				else
				{
					printf("Buffer is full");
				}
				break;
				
				case 2: 
				if((mutex==1)&&(full!=0))
				{
					consumer();
				}
				else
				{
					printf("Buffer is empty");
				}
				break;
				
				case 3:
				printf("Exiting...\n");
				exit(0);
				break;
			 }
			
				
	}
	 


	return 0;
}
