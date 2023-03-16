/*
Exercicio 13: 
    Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes ˜
    definidas pelo usuario e a leia. Em seguida, implemente uma func¸ ´ ao que receba um ˜
    valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz.
*/

#include <stdio.h>
#include <stdlib.h>

int check( int checkNumber, int **matriz, int rows, int columns ) {
    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < columns; j++ ) {
            if ( checkNumber == matriz[i][j] ) {
                return 1;
            }
        } 
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    
    int **matriz;
    int rows, columns;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &columns);

    matriz = (int **) malloc( rows * sizeof(int *) );

    for (int i = 0; i < rows; i++) {
        matriz[i] = (int *) malloc( columns * sizeof(int) );

        for (int j = 0; j < columns; j++) {
            printf("");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    int checkNumber, checkReturn, option;

    do {
        printf("Check a number:\n[0] quit.\n");
        scanf("%d", &checkNumber);

        checkReturn = check( checkNumber, matriz, rows, columns );

        printf(checkReturn == 1 ? "True" : "False");
    } while ( option != 0 );

    free(matriz);

    return 0;
}