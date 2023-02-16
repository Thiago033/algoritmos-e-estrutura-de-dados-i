#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int num, index = 0, auxIndex = 0;

    int *array = malloc(sizeof(int) * 10);

    while ( num != 0 ) {
        printf("Enter '0' to quit.");
        scanf("%d", &num);

        array[index++] = num;
        auxIndex++;

        if ( auxIndex == 10 ) {
            int *tempArray = malloc( sizeof(int) * (index + 10) );
            
            memcpy(tempArray, array, index * sizeof(int));
            free(array);

            array = tempArray;

            auxIndex = 0;

            free(tempArray);
        }
    }

    printf("\n");

    for ( int i = 0; i < index; i++ ) {
        printf("%d  ", array[i]);
    }

    free(array);
}