#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"



int * insertionSort(int *numsGlobal, int size){
    
    int *local = copyArray(numsGlobal, size);
    
    for(int i = 0; i < size-1; i++){
        if(*(local+i+1) < *(local+i)){
            int temp = *(local+i);
            *(local+i) = *(local+i+1);
            *(local+i+1) = temp;

            int j = i;
            //continue reading from here
            while(*(local+j) < *(local+j-1) && j > 0){
                int temp = *(local+j-1);
                *(local+j-1) = *(local+j);
                *(local+j) = temp;
                j -= 1;
            } 
            
        }
    }

    
/*
    for(int i = 0; i < size; i++){
        printf("%d ", *(local+i));
    }
    printf("\n");

*/
    return local;
}
