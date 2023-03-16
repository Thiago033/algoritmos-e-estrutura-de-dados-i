/*
Exercício 1
    Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres) e armazeá-la num vetor. Imprimir a frase lida trocando as vogais, isto é, trocar 'a' pelo 'u', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'. Usar uma função void (procedimento) para realizar a troca e uma função para realizar a impressão da frase trocada. A função deve ter como parâmetro um ponteiro char referente ao vetor. Dica: Use a função gets() da biblioteca string.h para realizar a leitura da frase. use o switch para realizar as trocas. Só considere as letras minúsculas.
*/

#include <stdio.h>
#include <string.h>

void troca(char *frase);
void imprimeFrase(char *frase);

int main() {

    char frase[20];
    
    printf("Digite uma frase: ");
    gets(frase);
    
    troca(frase);
    imprimeFrase(frase);

    return 0;
}

/*
====================================================================================
troca

troca as vogais de uma frase.
Ex: 'a' pelo 'i', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'.

====================================================================================
*/
void troca(char *vet) {

    int tam = strlen(vet);

    for (int i = 0; i < tam; i++) {
        switch (*vet)
        {
        case 'a':
            *vet = 'i';
            break;
        case 'e':
            *vet='o';
            break;
        case 'i':
            *vet='u';
            break;
        case 'o':
            *vet='a';
            break;
        case 'u':
            *vet='e';
            break;
        }

        vet++;
    }
}

void imprimeFrase(char *vet) {
    char *ptr;
    ptr = vet;

    printf("\n\n");

    for (int i = 0; i < strlen(vet); i++) {
        printf("%c", *ptr);
        ptr++;
    }
}