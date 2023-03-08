/*
    Exercicio 21:
        
    Escreva um programa que declare um array de inteiros e um ponteiro para inteiros. Associe o ponteiro ao array. Agora, some mais um (+1) a cada posic¸ao do array usando o ponteiro (use *).
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10}, num;
    
    int *pVetor = vetor;

    for (int i = 0; i < 10; i++) {
        *(pVetor + i) = *(pVetor+i) + 1;
    }

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(pVetor+i));
    }

    return 0;
}