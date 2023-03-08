/*
Exercicio 24:

Escreva uma funcao que receba um array de inteiros V e os enderecos de duas variaveis
inteiras, min e max, e armazene nessas variaveis o valor mınimo e maximo do array.
Escreva tambem uma funcao main que use essa funcao.

*/

#include <stdio.h>
#include <math.h>

int minEMaxDoVetor(int vet[], int *min, int *max);

int main() {

    int vetor[10] = {0,1,2,3,4,5,6,7,8,9};
    int min, max;

    min, max = minEMaxDoVetor(vetor, &min, &max);

    printf("Minimo: %d", min);
    printf("Maximo: %d", max);
}

/*
============================================================
minEMaxDoVetor

recebe um vetor e retorna o valor minimo e maximo encontrados
dentro desse vetor.
============================================================
*/
int minEMaxDoVetor(int vet[], int *min, int *max) {
    *min = vet[0];
    *max = vet[0];

    for (int i = 0; i < 10; i++) {

        if (vet[i] < *min) {
            *min = vet[i];
        }

        if (vet[i] > *max) {
            *max = vet[i];
        }
    }
    
    return *min, *max;
}