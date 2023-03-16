/*  
    Exercicio 09:
    
    Faça um programa que leia uma quantidade qualquer de numeros armazenando-os na memoria e pare a leitura quando o usuário entrar um número negativo. Em seguida, imprima o vetor lido. Use a função realloc. 
*/

#include<stdio.h>
#include<stdlib.h>

int main() {
    int *numeros, i=0;
    numeros = (int*) malloc(sizeof(int));

    printf("\nDigite um numero: \n");
    scanf("%d", &numeros[0]);

    while (numeros[i] >= 0) {
        i++;
        numeros = (int*) realloc(numeros, sizeof(int) * (i+1));
        printf("Digite um numero: \n");
        scanf("%d", &numeros[i]);
    }

    printf("Numeros digitados:\n");

    for (int j=0; j<i; j++) {
        printf("%d \n", numeros[j]);

        // ou

        // printf("%d \n", *numeros);
        // numeros++;
    }

    free(numeros);
}