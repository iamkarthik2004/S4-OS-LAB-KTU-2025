/*
03-03-2025
MONDAY

EXPERIMENT NO: 8
INTER PROCESS COMMUNICATION USING SHARED MEMORY
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[])
{
 int shmid;
 key_t key;
 char *segptr;
 char buff[]="hello how are you?";
 
 //Generate a uniqure key for shared memory
 key = ftok(".",'s');
 
 //Try to create a new shared memory segment or get the ID of an existing one
 if((shmid = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
 {
   if((shmid = shmget(key, SEGSIZE, 0))==-1)
   {
     perror("shmget");
     exit(1);
    }
  }
  else
  {
  printf("Creating a new shared memory segment\n");
  printf("SHMID:%d\n", shmid);
  }
  
  system("ipcs -m");
  
  //Attach the shared memory segment to the address space of the calling process
  if((segptr = (char *)shmat(shmid, 0, 0))==(char *)-1)
  {
    perror("shmat");
    exit(1);
  }
  
  //Write data to the shared memory segment
  printf("Writing data to shared memory...\n");
  strcpy(segptr, buff);
  printf("DONE\n");
  
  //Read data from the shared memory segment
  printf("Reading data from shared memory...\n");
  printf("DATA:%s\n", segptr);
  printf("DONE\n");
  
  //Detach the shared memory segment from the address space of the calling process
  if(shmdt(segptr)==-1)
  {
    perror("shmdt");
    exit(1);
  }
  
  //Remove the shared memory segment
  printf("Removing shared memory segment...\n");
  if(shmctl(shmid, IPC_RMID, 0)==-1)
    printf("Can't Remove Shared memory Segment...\n");
  else
    printf("Removed Successfully\n");
    
  return 0;
 
}
  
  
  

    
    
    
    
    
    
    
