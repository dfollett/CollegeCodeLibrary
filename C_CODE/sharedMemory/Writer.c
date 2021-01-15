/*
* This is the writer program. It uses input from the terminal
* to create a memory location name, key, and data to be entered
* into a data array.
*
* @author  Dustin Follett
* @since   10-26-19
*/

#include <stdio.h>
#include <stdlib.h>
#include<stdio.h>
#include<signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/msg.h>

/* Defines the maximum value of shared memory segment. */
#define MAX 1024

/*Initalizes the handle_sigint function.*/
void handle_sigint(int);

/*Variables accessable by all functions.*/
key_t key;
int shmid;
char *data;

/*main handles most things like setting up naming and writing to
  a shared memory location.*/
int main(){

    /*Asks for what to name the memory location.*/
    printf("%d  shmwriter:  Enter a shm loc: ", getpid());
    scanf("%s",data);

    /* Makes the not so unique key. */
    key = ftok("/home", 'R');
    printf("\n\n");

    /* Connects to the shared memory segment. */
    shmid = shmget(key, 1024, 0644 | IPC_CREAT);

    /* Attaches to the memory segment to get a pointer to it. */
    data = (char*) shmat(shmid, (void*)0,0);

    printf("%d  Set up memory seg, id: %d\n", getpid(), shmid);

    /*Calls a signal handler to allow conrtoll of what happens
    after a signal is caught.*/
    signal(SIGINT, handle_sigint);

    /* Modifies the segment based on the command line. In Infinite loop. */
    while('A' == 'A'){
      fgets(data, MAX, stdin);
      printf("%d  shmwriter:  Enter some data: ", getpid());

      /*Clears buffer after each input.*/
      fflush(stdin);
    }

}

/*handle_sigint function that clears data then exits program.*/
void handle_sigint(int sig){
  *data = -1;

  printf("\n%d  shmwriter:  SIGINT signal caught. \n\n", getpid());

  printf("%d  Cleaning up segid %d\n\n", getpid(), shmid);

  exit(1);
}
