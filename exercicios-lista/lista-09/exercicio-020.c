/*
Exercicio 20:

Implemente uma func¸ao que receba como parametro um array de numeros reais de
tamanho N e retorne quantos numeros negativos ha nesse array. Essa funcao deve
obedecer ao prototipo:

int negativos(float *vet, int N);
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int negativos(float *vet, int N);

int main() {
    float *vetor, num;
    int N;

    printf("Quantos numeros no vetor? \n");
    scanf("%d", &N);

    vetor = malloc(sizeof(float) * N);

    for (int i = 0; i < N; i++) {
        printf("Digite o %d numero para o vetor: \n", i+1);

        scanf("%f", &vetor[i]);
        // vetor[i] = num;
    }

    int numeroDeNegativos = negativos(vetor, N);

    printf("Numero de valores negativos no vetor: %d", numeroDeNegativos); 

    return 0;
}

/*
============================================================
maxDoVetor

retorna quantos numeros negativos ha no vetor.
============================================================
*/
int negativos(float *vet, int N) {
    int numeroDeNegativos = 0;

    for (int i = 0; i < N; i++) {
        if (vet[i] < 0) {
            numeroDeNegativos++;
        }
    }
    
    return numeroDeNegativos;
}