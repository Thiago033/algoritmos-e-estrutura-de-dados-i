/*
A importancia de R$ 780.000,00 sera dividida entre tres ganhadores de um concurso.
    Sendo que da quantia total:
        • O primeiro ganhador recebera 46%;
        • O segundo recebera 32%;
        • O terceiro recebera o restante;
Calcule e imprima a quantia ganha por cada um dos ganhadores
*/

#include <stdio.h>

#define PREMIO 780000

int main()
{
    
    int primeiro, segundo, terceiro;

    primeiro = 0.46 * PREMIO;
    segundo = 0.32 * PREMIO;
    terceiro = 0.22 * PREMIO;
    int premioTotal = primeiro + segundo + terceiro;
    printf("Premiacao total: %d\n", premioTotal);

    printf("Primeiro colocado recebe: %d\n", primeiro);
    printf("Segundo colocado recebe: %d\n", segundo);
    printf("Terceiro colocado recebe: %d\n", terceiro);

    return 0;
}