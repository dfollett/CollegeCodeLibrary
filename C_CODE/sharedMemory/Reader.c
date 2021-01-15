/*
* This is the Reader program. It uses input from the terminal
* to create a memory location name and key. Then it reads from
* shared memory about every 10 seconds.
*
* @author  Dustin Follett
* @since   10-26-19
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/msg.h>

/* Defines the maximum value of shared memory segment. */
#define MAX 1024

/*Initalizes the handle_sigusr1 function.*/
void handle_sigusr1(int);

/*Variables accessable by all functions.*/
key_t key;
int shmid;
char *data;

/*main handles most things like setting up naming and reading from
 a shared memory location.*/
int main(){

    /*Asks for what to name the memory location.*/
    printf("%d  shmReader:  Enter a shm loc: ", getpid());
    scanf("%s",data);
    printf("\n\n");

    /* Makes not so unique key. */
    key = ftok("/home", 'R');

    /* Connects to the shared memory segment. */
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);

    /* Attaches to the memory segment to get a pointer to it. */
    data = (char*) shmat(shmid, (void*)0,0);

    /*Calls a signal handler to allow conrtoll of what happens
    after a signal is caught.*/
    signal(SIGUSR1, handle_sigusr1);

    /* Prints the segment in infinite loop. */
    while('A' == 'A'){

      /*Checks if own pid is passe in if so exit.*/
      if(atoi(data) == getpid()){
        printf("%d was told to exit. Goodbye!\n", getpid());
        exit(1);
      }

      /*Checks if the writer has exited. */
      if(*data == -1){
        /*Passes numerical value to see how to handle signal.*/
        handle_sigusr1(atoi(data));
      }

      printf("%d  shmReader:  shared memory currently contains: %s\n", getpid(), data);

      /*sleeps so it dosent print at light speed.*/
			usleep(10000000);

      /*Clears buffer after each input.*/
      fflush(stdin);
    }
}

/*handle_sigusr1 function that exits program if needed.*/
void handle_sigusr1(int sig){
  printf("%d  shmwriter:  SIGUSR1 signal caught. ", getpid());

  /*checks if no value is passed in.*/
  if (sig == 0){
    /*Executes a full exit of program.*/
    puts("Exiting.\n\n");
    printf("%d Goodbye! Thanks for sharing.\n", getpid());
    exit(1);
  }
  else{}

}
