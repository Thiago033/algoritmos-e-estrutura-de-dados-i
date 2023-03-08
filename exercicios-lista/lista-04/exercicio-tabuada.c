//Imprime uma matriz com a tabuada do 0 ao 9

#include <stdio.h>

#define LIN 10
#define COL 10

int main() {
    int i;
    int j;
    int mat[LIN][COL];

    for (i = 0; i < LIN; i++) {
        for (j = 0; j < COL; j++) {
            mat[i][j] = i*j;
        }
    }

    //Printa os indices na parte de cima da tebela
    printf("%6d", 0);
    for (i = 1; i < COL; i++) {
        printf("%3d", i);
    }
    printf("\n");

    //Printa uma linha horizontal
    printf("    ");
    for (i = 0; i < 3*COL; i++) {
        printf("-");
    }
    printf("\n");

    //Printa a tabela, seus indices a esquerda, e uma linha vertical
    for (int i = 0; i < LIN; i++) {
        printf("%d |", i);
        for (int j = 0; j < COL; j++) {
            printf("%3d", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}