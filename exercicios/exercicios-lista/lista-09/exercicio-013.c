/*
Exercicio 13 
    Elabore uma func¸ao que receba duas strings como par ˜ ametros e verifique se a segunda ˆ
    string ocorre dentro da primeira. Use aritmetica de ponteiros para acessar os caracteres ´
    das strings.
*/

int verificaStrings(char *string1, char *string2);

#include <stdio.h>
#include <string.h>

int main() {

    char frase1[30], frase2[30];

    fgets(frase1,30, stdin);
    fgets(frase2,30, stdin);

    int retorno = verificaStrings(frase1, frase2);

    if(retorno == 1) {
        printf("A segunda string ESTA contida na primeira string\n");
    }  else {
        printf("A segunda string NAO ESTA contida na primeira string\n");
    }

    return 0;
}

int verificaStrings(char *string1, char *string2) {
    int i, j, retorno = 0;

    for(i = 0, j = 0; (*(string1 + i)) != '\0'; i++){

        while( (*(string1 + i)) == (*(string2 + j)) ){
            i++;
            j++;

            if( (*(string2 + j)) == '\n' || (*(string2 + j)) == '\0') {
                return 1;
            } else if( (*(string1 + i)) != (*(string2 + j)) ) {
                retorno = 0;
            }   
        }
    }

    return retorno;
}