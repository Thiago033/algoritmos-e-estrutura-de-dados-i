#include <stdio.h>
#include <stdlib.h>

/*
=======================================================================================
Shuffle

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
=======================================================================================
*/
int* Shuffle( int* nums, int numsSize, int n, int* returnSize) {
    int i = 0;
    int l = 0;
    int r = numsSize / 2;

    int* shuffled = (int*) malloc(sizeof(int) * numsSize);

    while ( i < numsSize ) {
        shuffled[i] = nums[l++];
        shuffled[i+1] = nums[r++];
        i+=2;
    }

    *returnSize = numsSize;

    return shuffled;
}

int main(int argc, char const *argv[]) {

    // ----------------
    // tests

    int nums[] = {2,5,1,3,4,7};
    //int nums[] = {1,2,3,4,4,3,2,1};
    //int nums[] = {1,1,2,2};

    // ----------------

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int n = numsSize / 2;
    int returnSize;

    int* shuffledArray = Shuffle( nums, numsSize, n, &returnSize );

    for ( int i = 0; i < numsSize; i++ ) {
        printf("%d ", shuffledArray[i]);
    }

    free(shuffledArray);

    return 0;
}