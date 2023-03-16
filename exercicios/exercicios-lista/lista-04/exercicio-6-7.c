/*

Juntando os exercicios 6 e 7 em um soh.

6. Faca um programa que receba do usuario um vetor com 10 posicoes. Em seguida devera ser impresso o maior e o menor elemento do vetor.

7. Escreva um programa que leia 10 numeros inteiros e os armazene em um vetor. Imprima o vetor, o maior elemento e a posic¸ao que ele se encontra. 
*/

#include <stdio.h>

int main() {
    int vet[10], maiorElemento, menorElemento, indiceMaiorElemento, indiceMenorElemento;

    for (int i = 0; i < 10; i++) {
        printf("Digite um numero inteiro: \n");
        scanf("%d", &vet[i]);
    }
    
    //Inicia os valores das variaveis com o primeiro elemento do vetor.
    maiorElemento = vet[0];
    menorElemento = vet[0];
    indiceMaiorElemento = vet[0];
    indiceMenorElemento = vet[0];

    for (int i = 0; i < 10; i++) {
        
        if (maiorElemento < vet[i]) {
            maiorElemento = vet[i];
            indiceMaiorElemento = i;
        }

        if (menorElemento > vet[i]) {
            menorElemento = vet[i];
            indiceMenorElemento = i;
        }
    }

    printf("Maior elemento do vetor: %d\n", maiorElemento);
    printf("Indice do maior elemento: %d\n", indiceMaiorElemento);

    printf("Menor elemento do vetor: %d\n", menorElemento);
    printf("Indice do menor elemento: %d\n", indiceMenorElemento);
    return 0;
}
