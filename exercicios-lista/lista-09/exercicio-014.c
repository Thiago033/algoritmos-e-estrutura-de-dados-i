/*
Exercicio 14
    Crie uma func¸ao que receba dois par ˜ ametros: um array e um valor do mesmo tipo do ˆ
    array. A func¸ao dever ˜ a preencher os elementos de array com esse valor. N ´ ao utilize ˜
    ´ındices para percorrer o array, apenas aritmetica de ponteiros.
*/

void preencherArray(char *string1, char *caracter);

#include <stdio.h>
#include <string.h>

int main() {

    char frase1[30], caracter;

    printf("Digite um caracter: \n");
    scanf("%c", &caracter);

    preencherArray(frase1, &caracter);

    return 0;
}

void preencherArray(char *string1, char *caracter) {

    printf("%c", *caracter);

    for (int i = 0; i < 30; i++) {
        *(string1+i) = *caracter;
    }

    printf("%s", string1);
}