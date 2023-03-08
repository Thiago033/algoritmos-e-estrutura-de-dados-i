/*
34 - Faca um programa que encontre o conjunto de 5 dıgitos consecutivos na sequencia abaixo que gere o maior produto:

Ex:
    string = "1 2 3 4 5 6 7 8 9 9"
    Maior sequencia de 5 numeros seria: "6 7 8 9 9"
    
    string = "1 2 3 4 5 6 7 8 9 9 9 9 9"
    Maior sequencia possivel de 5 numeros: "9 9 9 9 9"
*/

#include <stdio.h>


int main() {
    //String a ser analizada
    char string[] = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843125406987471585238630507156932909632952274430435578586156078912949495459501737958331952853208805511668966489504452445231617318564030987111217223831136222989342338030813533627661428280644448664523874930358907296290491560440772907138105158593079608667017242712188399879790879227492190169972088809377665727333001053367881220235421809751254540594752243525849077116705560136048395864467063244172215539753697817977846174064955149290862569321978468622482839722413756999995749026140797296865241453510047482166370484403199890008895243450658541227588666881164271747992444292823086346567481391912316282458617866458359124566529476545682848912883142607690042";

    //Vetor para armazenar os 5 numeros da maior sequencia
    char sequencia[5];

    int n1, n2, n3, n4, n5;

    int tamanhoString = sizeof(string);

    int maiorSequencia = 0, produtoSequencia, j, i;

    for (i = 0; i < (tamanhoString-5); i++) {

        n1 = string[i]-48;
        n2 = string[i+1]-48;
        n3 = string[i+2]-48;
        n4 = string[i+3]-48;
        n5 = string[i+4]-48;

        /*
            O indice do character do numero na tabela ascii menos "48" retorna o numero em decimal

            Ex:
                indice do numero "1" na tabela ascii = 49
                49 - 48 = 1 (numero em decimal)

                indice do numero "9" na tabela ascii = 57
                57 - 48 = 9 (numero em decimal)
        */

        produtoSequencia = n1*n2*n3*n4*n5;

        if (maiorSequencia < produtoSequencia) {
            maiorSequencia = produtoSequencia;

            //Armazena os numeros da maior sequencia encontrada
            for (j = 0; j < 5; j++){
                sequencia[j] = string[i+j];
            }
        }
    }
    
    //Printa os numeros da maior sequencia
    for (i = 0; i < 5; i++) {
        printf("%c ", sequencia[i]);
    }

    //Valor do produto da maior sequencia encontrada
    printf("\n%d", maiorSequencia);
    
    return 0;
}
