#include <stdio.h>
#include <string.h>

void bubsorter(int stor[], int size, char order){
	int i, j, t;
	if(order == 'A'){
		for (i = 0; i < size; i++){
			for (j = 2; j < size-i; j++){
				if (stor[j] > stor[j+1]){
					t = stor[j];
					stor[j] = stor[j+1];
					stor[j+1] = t;
				}
			}
		}
	for (int i = 2; i < size; i++) {
		printf("%d\n",stor[i]);
	}
	}
	if (order == 'D'){
		for (i = 2; i < size; i++){
			for (j = i; j < size; j++){
				if (stor[i] < stor[j]){
					t = stor[i];
					stor[i] = stor[j];
					stor[j] = t;
				}
			}
		}
	for (int i = 2; i < size; i++) {
		printf("%d\n",stor[i]);
	}
	}
}
