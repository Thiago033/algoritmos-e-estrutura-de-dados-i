/*
Exercicio 15
    Crie uma func¸ao que receba como par ˜ ametro um array e o imprima. N ˆ ao utilize ˜ ´ındices
    para percorrer o array, apenas aritmetica de ponteiros.
*/

void imprimirArray(char *string);

#include <stdio.h>
#include <string.h>

int main() {

    char frase1[30];

    printf("Digite uma string: \n");
    fgets(frase1, 30, stdin);

    imprimirArray(frase1);

    return 0;
}

void imprimirArray(char *string) {

    for (int i = 0; i < strlen(string); i++) {
        printf("%c", *(string+i));
    }

   
}