#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"


void putTogether(int *nums, int left, int middle, int right){
	int sizeLeft = middle - left + 1;
	int *tempLeft = (int*)malloc(sizeLeft*sizeof(int));

	int sizeRight = right - middle;
	int *tempRight = (int*)malloc(sizeRight*sizeof(int));
	
	for(int i = 0; i < sizeLeft; i++){
		*(tempLeft+i) = *(nums+left+i);
	}

	for(int i = 0; i < sizeRight; i++){
		*(tempRight+i) = *(nums+middle+1+i);
	}

	int i, j, k;

	for(i = 0, j = 0, k = left; k <= right; k++){
		if((i < sizeLeft) && (j >= sizeRight || *(tempLeft+i) <= *(tempRight+j))){
			*(nums + k) = *(tempLeft+i);
			i++;
		}
		else{
			*(nums + k) = *(tempRight+j);
			j++;
		}
	}
}

void splittingRecursion(int *nums, int left, int right){
	

	if(left < right){
		int middle = left + (right - left)/2;
		splittingRecursion(nums, left, middle);
		splittingRecursion(nums, middle + 1, right);


		putTogether(nums, left, middle, right);

	}
 }

int *mergeSort(int *numsGlobal, int size){
	int *nums = copyArray(numsGlobal, size);
	splittingRecursion(nums, 0, size-1);
	//change back to size-1
	

	return nums;
}



/* Test Case

int main(){
	
	int *nums = randArray(10);
	printArray(nums, 10, "Random: ");

	int *new = mergeSort(nums, 10);
	printArray(new, 10, "New: ");

	return 0;
}
*/