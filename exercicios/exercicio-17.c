#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num, index = 0, auxIndex = 0;

    int *array = malloc(sizeof(int) * 2);

    while ( num != 0 ) {
        printf("Enter a integer greater than 0, or enter '0' to quit.\n");
        scanf("%d", &num);

        if (!num) break;

        array[index++] = num;
        auxIndex++;

        if ( auxIndex == 2 ) {
            int *tempArray = malloc( sizeof(int) * (index + 2) );
            memcpy(tempArray, array, index * sizeof(int));
            array = tempArray;

            auxIndex = 0;

        }
    }

    printf("\n");

    for ( int i = 0; i < index; i++ ) {
        printf("%d  ", array[i]);
    }

    free(array);
}