#include <stdio.h>
#include <stdlib.h>

void swap( int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort( int *array, int size ) {

    int i, j, minIndex;

    for ( int i = 0; i < size-1; i++ ) {
        minIndex = i;

        for ( int j = i+1; j < size; j++ ) {
            if ( array[j] > array[minIndex] ) {
                minIndex = j;
            }
        }

        swap( &array[minIndex], &array[i] );      
    }
}
                                                // int* returnSize
int* maxSubsequence( int* nums, int numsSize, int k ) {
    int *returnArray = (int *)malloc(sizeof(int) * k);

    for (int i = 0; i < k; i++) {
        returnArray[i] = nums[i];
    }

    return returnArray;
}

int main() {
    int array[4] = {-1, -2, 3, 4};
    int size = 4;
    
    // Sort in decrescent order
    selectionSort(array, size);

    // number of elements of subsequence
    int k = 3;

    int *returnArray = (int *)malloc(sizeof(int) * k);
    returnArray = maxSubsequence( array, size, k );

    // print max subsequence
    for ( int j = 0; j < k; j++ ) {
        printf("%d, ", returnArray[j]);
    }

    free(returnArray);
}