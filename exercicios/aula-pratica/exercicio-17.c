/*
17. Fac¸a um programa que leia numeros do teclado e os armazene em um vetor alocado ´
dinamicamente. O usuario ir ´ a digitar uma sequ ´ encia de n ˆ umeros, sem limite de quan- ´
tidade. Os numeros ser ´ ao digitados um a um e, sendo que caso ele deseje encerrar a ˜
entrada de dados, ele ira digitar o numero ZERO. Os dados devem ser armazenados na ´
memoria deste modo ´
    • Inicie com um vetor de tamanho 10 alocado dinamicamente;
    • Apos, caso o vetor alocado esteja cheio, aloque um novo vetor do tamanho do vetor ´
    anterior adicionado espac¸o para mais 10 valores (tamanho N+10, onde N inicia com
    10);
    • Copie os valores ja digitados da ´ area inicial para esta ´ area maior e libere a mem ´ oria ´
    da area inicial; ´
    • Repita este procedimento de expandir dinamicamente com mais 10 valores o vetor
    alocado cada vez que o mesmo estiver cheio. Assim o vetor ira ser ’expandido’ de ´
    10 em 10 valores.

Ao final, exiba o vetor lido. Nao use a func¸ ˜ ao REALLOC.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    int number, index = 0, count = 0;
    int *array = malloc ( 10 * sizeof(int) );

    do {
        printf("Enter a number\n");
        scanf("%d", &number);

        if ( number == 0 ) break;

        array[index++] = number;
        count++;

        if (count == 10) {
            count = 0;

            int *tempArray = calloc ( (10 + index), sizeof(int) );

            memcpy( tempArray, array, index * sizeof(int) );
            array = tempArray;
            
        }
    } while ( 1 );
    
    for ( int i = 0; i < index; i++ ) {
        printf("%d ", array[i]);
    }

    free(array);

    return 0;
}
