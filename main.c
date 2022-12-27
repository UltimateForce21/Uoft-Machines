#include <stdio.h>
#include <stdlib.h>
#include "algorithms.h"
#include "time.h"





/*
Main Program will provide a randomly generated list run the sorting algorithms
    a) print out the list of random nums


Sorting algorithms will sort
    a) print out the sorted list
    b) print out time to sort


Create a function to check whether the sorted lists are really sorted
    a) return sorted or not sorted
    b) if all the elements are still in the list
*/


/*
Tasks
0. Set up git
1. Redesign sorts to fit new system
2. Add merge sort
3. Create a timer function 
4. Add other complex sorts
5. Create checker function (done)
6. Create a copy function so that the original list of random integers is not altered
*/

void checker(int *sortedArray, int size, char name[30]){
    int sorted = 1;  
    for(int i = 0; i < size-1; i++){
        if(*(sortedArray+i) > *(sortedArray+i+1)){
            sorted = 0;
        }
    }
    if(sorted == 1){
        printf("%sIs Sorted\n", name);
    }
    else{
        printf("%sNot Sorted\n", name);
    }
    
    
    //************I cant check the size of the array, the following is just dividing a pointer type size by int type size
    
    /*
    int listsize = sizeof(sortedArray)/sizeof(int);
    printf("Not size of list: %d\n", listsize);
    
    */
}

int main(){
    int testSize = 100000;
    printf("Test Size = %d\n", testSize);
    int *nums = randArray(testSize);
    int *randlist = nums;
    //printArray(nums, testSize, "Random List: ");
    //checker(nums, testSize, "Random List: ");
    
    //Insertion Sort
    clock_t tInsertion;
    tInsertion = clock();    
    char insertion[] = "Insertion Sort: "; 
    int *insertionsorted = insertionSort(nums, testSize);
    //printArray(insertionsorted, testSize, insertion);    
    tInsertion = clock() - tInsertion;
    double cInsertion = ((double)tInsertion)/CLOCKS_PER_SEC;
    printf("Insertion Time: %f seconds\n", cInsertion);
    checker(insertionsorted, testSize, insertion);
    printf("\n\n");


    //Selection Sort
    clock_t tSelection;
    tSelection = clock(); 
    char selection[] = "Selection Sort: "; 
    int *selectionsorted = selectionSort(nums, testSize);
    //printArray(selectionsorted, testSize, selection);
    tSelection = clock() - tSelection;
    double cSelection = ((double)tSelection)/CLOCKS_PER_SEC;
    printf("Selection Time: %f seconds\n", cSelection);
    checker(selectionsorted, testSize, selection);
    printf("\n\n");


    //Bubble Sort
    clock_t tBubble;
    tBubble = clock(); 
    char bubble[] = "Bubble Sort: "; 
    int *bubblesorted = bubbleSort(nums, testSize);
    //printArray(bubblesorted, testSize, bubble);
    tBubble = clock() - tBubble;
    double cBubble = ((double)tBubble)/CLOCKS_PER_SEC;
    printf("Bubble Time: %f seconds\n", cBubble);
    checker(bubblesorted, testSize, bubble);

    //Merge Sort
    clock_t tMerge;
    tMerge = clock(); 
    char merge[] = "Merge Sort: "; 
    int *mergesorted = mergeSort(nums, testSize);
    //printArray(mergesorted, testSize, merge);
    tMerge = clock() - tMerge;
    double cMerge = ((double)cMerge)/CLOCKS_PER_SEC;
    printf("Merge Time: %f seconds\n", cMerge);
    checker(mergesorted, testSize, merge);


    

    //printArray(randlist, testSize, "Random List: ");

    return 0;
}