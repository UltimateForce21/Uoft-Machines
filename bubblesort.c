#include <stdio.h>
#include "algorithms.h"

int * bubbleSort(int *numsGlobal, int size){
    
    int *nums = copyArray(numsGlobal, size);

    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if (*(nums + j) > *(nums+i)){
                int temp = *(nums+i);
                *(nums+i) = *(nums+j);
                *(nums+j) = temp;
            }
        }
    }

    return nums;
}
