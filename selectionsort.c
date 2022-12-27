#include <stdio.h>
#include "algorithms.h"

int * selectionSort(int *numsGlobal, int size){
    
    int *nums = copyArray(numsGlobal, size);

    for(int i = 0; i < size; i++){
        
        int min = *(nums+i);
        int index = i;
        
        for(int j = i; j < size; j++){
            
            if(*(nums+j) < min){
                min = *(nums+j);
                index = j;
            }
        }
        
        //printf("This is for iteration i = %d and the min: %d, index: %d\n", i, min, index);
        
        
        int temp = *(nums+i);
        *(nums+i) = min;
        *(nums+index) = temp;

    }
    

    return nums;
}