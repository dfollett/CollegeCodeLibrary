****************************************************************
//Dustin Follett 				Bubble Sorter Program
//11/12/2018
//
//This is a porgram that will implement bubble sort to organize 
//an inputed list of positive and negative numbers according to 
//what is specified. Either an A or a D. this program includes a
//function called bubsort that sorts the given integers.Also it
//includes a make file that allows you to compile the program 
//then run it using ./bubsort A 1 2 3 as an example.
****************************************************************


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <bubSort.h>

int main(int argc, char *argv[]){

	int storage[32];
	int size = argc;

	if(argc <= 1){
		fprintf(stderr,"usage 1: %s zero arguments entered type an A or D then a list of positive and or negative integers to be sorted.\n", argv[1]);
		exit(1);
	}

	char order = *argv[1];

	if(order != 'A' && order != 'D'){
		fprintf(stderr,"usage 2: %s please specify the order with either an A (ascending) or a D (descending).\n",argv[1]);
	}

	if(size == 2 && order == 'A' ){
		fprintf(stderr,"usage 3: %s zero integer arguments entered.\n", argv[1]);
		exit(1);
	}
	if(size == 2 && order == 'D' ){
		fprintf(stderr,"usage 3: %s zero integer arguments entered.\n", argv[1]);
		exit(1);
	}
	if (argc >= 34){
		fprintf(stderr,"usage 4: %s arguments size exceeds 32 integers.\n", argv[1]);
		exit(1);
	}

	else{
		for (int i = 0; i < argc; i++) {
			storage[i] = atoi(argv[i]);
		}

// this is a call to bubsort with 3 parameters. the list to be                         // modifyed the size of that list and the order desired.
		bubsorter(storage, size, order);
	
	}
}







