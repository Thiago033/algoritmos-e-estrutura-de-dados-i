/*
* Note: The returned array must be malloced, assume caller calls free().
*/

/*
=======================================================================================
Shuffle

Given the array nums consisting of 2n elements in the form [x1,x2,...,xn,y1,y2,...,yn].
Return the array in the form [x1,y1,x2,y2,...,xn,yn].
=======================================================================================
*/
int* Shuffle( int* nums, int numsSize, int n, int* returnSize ) {
    int i=0; 
    int l=0;
    int r=n;

    int* shuffled = (int*) malloc(sizeof(int) * numsSize);

    while ( i < n*2 ) {
        shuffled[i] = nums[l++];
        shuffled[i+1] = nums[r++];

        i+=2;
    }

    *returnSize = numsSize;

    return shuffled;
}
