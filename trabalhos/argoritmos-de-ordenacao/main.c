#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

void swap( int *xp, int *yp ) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/*
==================
Merge Sort
==================
*/
int merge(int array[], int low, int mid, int high) {

    int *temp, p1, p2, size, i, j, k;
    int end1 = 0, end2 = 0;

    size = high - low + 1;

    p1 = low;
    p2 = mid + 1;

    temp = (int *) malloc(size * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < size; i++) {
            if (!end1 && !end2) {
                
                if (array[p1] < array[p2]) {
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
                
                if (p1 > mid) end1 = 1;
                if (p2 > high) end2 = 1;
            } else {
                if(!end1){
                    temp[i] = array[p1++];
                } else {
                    temp[i] = array[p2++];
                }
            }
        }

        for (j = 0, k = low; j < size; j++, k++) {
            array[k] = temp[j];
        }
    }
    
    free(temp);
}

void mergeSort(int *array, int low, int high) {

    if (low < high) {

        int mid = floor((low + high) / 2);

        mergeSort(array, low , mid);
        mergeSort(array, mid+1, high);
        
        merge(array, low, mid, high);
    }
}

/*
==================
Quick Sort
==================
*/
int partition(int array[], int low, int high) {
    int left, right, pivot, aux;

    left = low;
    right = high;

    pivot = array[low];

    while (left < right) {

        while (array[left] <= pivot) {
            left++;
        }

        while (array[right] > pivot) {
            right--;
        }

        if (left < right) {
            aux = array[left];
            array[left] = array[right];
            array[right] = aux;
        }
    }

    array[low] = array[right];
    array[right] = pivot;

    return right;
}

void quickSort(int *array, int low, int high) {

    if (low < high) {
        int pivot = partition(array, low, high);

        quickSort(array, low , pivot - 1);
        quickSort(array, pivot + 1, high);
    }
}

/*
==================
Selection Sort
==================
*/
void selectionSort( int *array, int size ) {
    int i, j, min_idx;

    for ( i = 0; i < size-1; i++ ) {
        min_idx = i;

        for (j = i+1; j < size; j++) {
            if (array[j] < array[min_idx]) {
                min_idx = j;
            }
        }
        
        swap(&array[min_idx], &array[i]);
    }
}

/*
==================
Insertion Sort
==================
*/
void insertionSort( int *array, int size ) {
    int i, j, key;

    for ( i = 1; i < size; i++ ) {
        key = array[i];
        j = i - 1;

        while ( j >= 0 && array[j] > key ) {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int isSorted(int* array, int size){
    int i;

    for(i = 0; i < size-1; i++){

        if(array[i] > array[i+1]) return 0;
    }

    return 1;
}

int main () {
    int size, option;

    time_t randomSeed = time(NULL);

    struct timespec begin, end; 

    printf("Type the size of the array: \n");
    scanf("%d", &size);

    int* array = (int  *) malloc(sizeof(int) * size);

    //define the random number generator
    srand(randomSeed);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    printf ("==========================\n");
    printf("Select the sort method:    \n");
    printf("1) Insertion Sort          \n");
    printf("2) Selection Sort          \n");
    printf("3) Quick Sort              \n");
    printf("4) Merge Sort              \n");
    printf("5) Quit                    \n");
    printf ("==========================\n");
    scanf("%d", &option);

    // ==============
    // TIMER START
    // ==============
    clock_gettime(CLOCK_REALTIME, &begin);

    switch (option) {
    case 1:
        insertionSort(array, size);
        break;
    
    case 2:
        selectionSort(array, size);
        break;
    
    case 3:
        quickSort(array, 0, size-1);
        break;

    case 4:
        mergeSort(array, 0, size-1);
        break;
    
    case 5:
        printf("Quit.\n\n");
        break;
    
    default:
        printf("Invalid option!\n");
        break;
    }

    // ==============
    // TIMER END
    // ==============
    clock_gettime(CLOCK_REALTIME, &end);

    //measuring time
    long seconds = end.tv_sec - begin.tv_sec;
    long nanoseconds = end.tv_nsec - begin.tv_nsec;
    double elapsed = seconds + nanoseconds*1e-9;

    printf("============================================\n");

    isSorted(array, size) ? printf("Array is sorted!\n") : printf("Error!\nArray isn't sorted!\n");

    printf("Time measured: %f seconds.\n", elapsed);

    printf("============================================\n");
    
    free(array);

   return 0;
}