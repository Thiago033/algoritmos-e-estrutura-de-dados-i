/*
13. Escreva um programa que aloque dinamicamente uma matriz (de inteiros) de dimensoes ˜
definidas pelo usuario e a leia. Em seguida, implemente uma func¸ ´ ao que receba um ˜
valor, retorne 1 caso o valor esteja na matriz ou retorne 0 caso nao esteja na matriz. 
*/

#include <stdio.h>
#include <stdlib.h>

int Check( int checkNumber, int **matriz, int rows, int columns ) {

    for ( int i = 0; i < rows; i++ ) {
        for ( int j = 0; j < columns; j++ ) {
            if (matriz[i][j] == checkNumber) return 1;
        }
    }

    return 0;
}

int main(int argc, char const *argv[]) {
    int **matriz; 
    int rows, columns;

    printf("Rows: ");
    scanf("%d", &rows);
    printf("Columns: ");
    scanf("%d", &columns);

    matriz = malloc( rows * sizeof(int) );

    printf("Enter matriz: \n");
    for ( int i = 0; i < rows; i++ ) {
        
        matriz[i] = malloc( columns * sizeof(int) );

        for ( int j = 0; j < columns; j++ ) {
            scanf("%d", &matriz[i][j]);
        }
        
    }

    int checkNumber;

    do {
        printf("Check number: ");
        scanf("%d", &checkNumber);
        printf(Check( checkNumber, matriz, rows, columns ) ? "YES\n" : "NO\n");
    } while ( checkNumber != 0);
    
    free(matriz);
    
    return 0;
}
