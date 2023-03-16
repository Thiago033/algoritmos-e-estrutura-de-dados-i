/*
    Tres amigos jogaram na loteria. Caso eles ganhem, o pr ˆ emio deve ser repartido pro- ˆ
    porcionalmente ao valor que cada deu para a realizac¸ao da aposta. Fac¸a um programa ˜
    que leia quanto cada apostador investiu, o valor do premio, e imprima quanto cada um ˆ
    ganharia do premio com base no valor investido.
*/

#include <stdio.h>

int main()
{
    //Codigo com vetores

    float jogador[3], premioJogador[3], totalApostas = 0, premio;

    printf("Digite o valor do premio: \n");
    scanf("%f", &premio);

    for (int i = 0; i < 3; i++) {
        printf("Valor apostado pelo jogador %d:\n", i+1);
        scanf("%f", &jogador[i]);

        totalApostas += jogador[i];
    }

    for (int i = 0; i < 3; i++) {
        premioJogador[i] = premio * (jogador[i]/totalApostas);
        printf("Valor ganho pelo jogador %d: %.2f\n", i+1, premioJogador[i]);
    }
    
    //Codigo sem vetores

    // float premio, jogador1, jogador2, jogador3, premioJogador1, premioJogador2, premioJogador3, totalApostas = 0;

    // printf("Digite o valor do premio: \n");
    // scanf("%f", &premio);

    // printf("Valor apostado pelo jogador 1: \n");
    // scanf("%f", &jogador1);

    // printf("Valor apostado pelo jogador 2: \n");
    // scanf("%f", &jogador2);

    // printf("Valor apostado pelo jogador 3: \n");
    // scanf("%f", &jogador3);

    // totalApostas = jogador1 + jogador2 + jogador3;

    // premioJogador1 = premio * (jogador1/totalApostas);
    // premioJogador2 = premio * (jogador2/totalApostas);
    // premioJogador3 = premio * (jogador3/totalApostas);

    // printf("Valor ganho pelo jogador 1: %.2f\n", premioJogador1);
    // printf("Valor ganho pelo jogador 2: %.2f\n", premioJogador2);
    // printf("Valor ganho pelo jogador 3: %.2f\n", premioJogador3);

    return 0;
}