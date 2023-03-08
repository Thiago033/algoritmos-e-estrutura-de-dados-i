/*
Exercicio 19:
    Escreva uma func¸ao que aceita como par ˜ ametro um array de inteiros com N valores, e ˆ
    determina o maior elemento do array e o numero de vezes que este elemento ocorreu ´
    no array. Por exemplo, para um array com os seguintes elementos: 5, 2, 15, 3, 7, 15,
    8, 6, 15, a func¸ao deve retorna para o programa que a chamou o valor 15 e o n ˜ umero 3 ´
    (indicando que o numero 15 ocorreu 3 vezes). A func¸ ´ ao deve ser do tipo ˜ void.
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void maiorValorDoVetor(int *vet);

int main() {
    int *vetor, num;

    // vetor = malloc(sizeof(float) * 10);

    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero para o vetor: \n", i+1);

        scanf("%d", &num);
        vetor[i] = num;
    }

    maiorValorDoVetor(vetor);

    return 0;
}

void maiorValorDoVetor(int *vet) {
    int maiorValor = vet[0];
    int numero = 0;

    for (int i = 0; i < 10; i++) {

        if (maiorValor == vet[i]) {
            numero++;
        }
        
        if (maiorValor < vet[i]) {
            maiorValor = vet[i];
        }
    }
    
    printf("Maior valor: \n");
    printf("%d\n", maiorValor);
    printf("Vezes que o valor aparece no vetor: \n");
    printf("%d", numero);
}