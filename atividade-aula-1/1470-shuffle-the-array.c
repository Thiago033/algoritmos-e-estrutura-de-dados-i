/*
 Note: The returned array must be malloced, assume caller calls free().
*/

#include <stdio.h>
#include <stdlib.h>

/*
=======================================================================================
Shuffle

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
=======================================================================================
*/
int* Shuffle( int* nums, int numsSize, int n, int* returnSize ) {
    int i = 0;
    int left = 0;
    int right = n;

    int* shuffled = (int*) malloc( sizeof(int) * numsSize );

    while ( i < numsSize ) {
        shuffled[i] = nums[left++];
        shuffled[i+1] = nums[right++];
        i+=2;
    }

    *returnSize = numsSize;

    return shuffled;
}

int main( int argc, char const *argv[] ) {

    // -----------------------
    //int nums[] = {2,5,1,3,4,7}; // Expected Output: [2,3,5,4,1,7]
    //int nums[] = {1,2,3,4,4,3,2,1}; // Expected Output: [1,4,2,3,3,2,4,1]
    int nums[] = {1,1,2,2}; // Expected Output: [1,2,1,2]
    // -----------------------

    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int n = numsSize / 2;
    int returnSize;

    int* shuffledArray = Shuffle( nums, numsSize, n, &returnSize );

    for ( int i = 0; i < numsSize; i++ ) {
        printf("%d ", shuffledArray[i]);
    }

    free( shuffledArray );

    return 0;
}