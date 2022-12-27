#include <stdio.h>
#include <stdlib.h>



int * randArray(int size){

    int *nums = (int*)malloc(size*sizeof(int));
    
    for(int i = 0; i < size; i++){
        *(nums+i) = rand() % size;
    }

    return nums;

}


void printArray(int *nums, int size, char name[30]){
    
    printf("%s", name);

    for(int i = 0; i < size; i++){
        printf("%d ", *(nums+i));
    }
    printf("\n");
}

int * copyArray(int *nums, int size){

    int *new = (int*)malloc(size*sizeof(int));
    
    for(int i = 0; i < size; i++){
        *(new+i) = *(nums+i);
    }

    return new;

}


