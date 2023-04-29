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

    int * sol = (int*)malloc( sizeof(int) * k );

    for ( int i = 0; i < k ; i++ ) {
        sol[i] = nums[pairs[i].index];
    }

    free( pairs );

    return sol;
}

int main() {
    int returnSize;

    int array[4] = {-1,-2,3,4};
    int size = 4;

    // number of elements in the subsequence
    int k = 3;

    //int *returnArray = (int *)malloc(sizeof(int) * k);
    int *returnArray = maxSubsequence( array, size, k, &returnSize );

    // print max subsequence
    for ( int j = 0; j < k; j++ ) {
        printf("%d, ", returnArray[j]);
    }

    free(returnArray);
}