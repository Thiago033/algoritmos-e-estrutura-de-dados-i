/*
Exercício 2
    Escreva um programa que declare uma matriz 10x10 de inteiros. Você criar uma função void (procedimento) para inicializar a matriz com zeros usando um ponteiro para a matriz. Faça outra função void para preencher depois a matriz com os números de 99 a 0, também usando ponteiro para matriz como parâmetro. Por fim, o programa deve imprimir a matriz.
*/

#include <stdio.h>
#include <string.h>

void inicializaMatriz(int *mat);
void imprimirMatriz(int *mat);

int main() {

    int matriz[10][10];

    inicializaMatriz(matriz[0]);
    imprimirMatriz(matriz[0]);

    return 0;
}

/*
==============================
inicializaMatriz

Inicializar uma matriz com todos elementos = 0

==============================
*/
void inicializaMatriz(int *mat) {
    int i;
    for(i=0; i < 100; i++) {
        *mat=0;
        mat++;
    }
}

/*
==============================
imprimirMatriz

Imprime a matriz

==============================
*/
void imprimirMatriz(int *mat) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d | ", *mat);
            mat++;
        }
        printf("\n");
    }
}