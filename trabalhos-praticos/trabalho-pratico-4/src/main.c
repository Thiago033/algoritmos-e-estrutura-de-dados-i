#include <stdio.h>
#include <stdlib.h>

struct pair{
    int index;
    int value;
};

void swap( int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/*
================================================================
selectionSortValue

    Sort the array in decrescent order, using value as parameter
================================================================
*/
void selectionSortValue( struct pair *array, int size ) {
    int i, j, minIndex;

    for ( int i = 0; i < size-1; i++ ) {
        minIndex = i;

        for ( int j = i+1; j < size; j++ ) {
            if ( array[j].value > array[minIndex].value ) {
                minIndex = j;
            }
        }

        swap( &array[minIndex].value, &array[i].value );
        swap( &array[minIndex].index, &array[i].index );
    }
}

/*
================================================================
selectionSortIndex

    Sort the array in crescent order, using index as parameter
================================================================
*/
void selectionSortIndex( struct pair *array, int size ) {
    int i, j, minIndex;

    for ( int i = 0; i < size-1; i++ ) {
        minIndex = i;

        for ( int j = i+1; j < size; j++ ) {
            if ( array[j].index < array[minIndex].index ) {
                minIndex = j;
            }
        }

        swap( &array[minIndex].value, &array[i].value );
        swap( &array[minIndex].index, &array[i].index );
    }
}

int* maxSubsequence( int* nums, int numsSize, int k, int* returnSize ) {
    *returnSize = k;

    if ( k == numsSize ) return nums;

    struct pair * pairs = malloc( sizeof(struct pair) * numsSize );

    for ( int i = 0; i < numsSize; i++ ) {
        pairs[i].index = i;
        pairs[i].value = nums[i];
    }

    selectionSortValue( pairs, numsSize );
    selectionSortIndex (pairs, k );

    int * returnArray = (int*)malloc( sizeof(int) * k );

    for ( int i = 0; i < k ; i++ ) {
        returnArray[i] = nums[pairs[i].index];
    }

    free( pairs );

    return returnArray;
}

int main() {
    int returnSize;

    int array[10] = {63,-74,61,-17,-55,-59,-10,2,-60,-65};
    int size = 10;

    // number of elements in the subsequence
    int k = 9;

    int *returnArray = maxSubsequence( array, size, k, &returnSize );

    // print max subsequence
    for ( int j = 0; j < k; j++ ) {
        printf("%d, ", returnArray[j]);
    }

    free(returnArray);
}