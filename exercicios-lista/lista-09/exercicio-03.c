/*
Exercício 3
    Faça um programa para calcular a área e o perímetro de um hexágono. O programa deve implementar uma função chamada calc_hexa que calcula a área e o perímetro de um hexágono regular de lado L. O program deve solicitar ao usuário o lado do polígono, calcular e imprimir a área e o perímetro do polígono. O programa termina quando for digitado um valor negativo qualquer para o lado. A função deve obedecer o seguinte protótipo:

    void calc_hexa(float l, floar *area, float *perimetro);
*/

#include <stdio.h>
#include <math.h>

void calc_hexa(float l, float *area, float *perimetro);

int main() {
    float l, area, perimetro;

    printf("Digite o tamanho de L:\n");
    scanf("%f", &l);

    calc_hexa(l, &area, &perimetro);

    printf("Area do hexagono:\n");
    printf("%.2f\n", area);
    printf("Perimetro do hexagono:\n");
    printf("%.2f", perimetro);
}

/*
==============================
calc_hexa

calcula a area e o perimetro de um hexagono

==============================
*/
void calc_hexa(float l, float *area, float *perimetro) {

    *area = ( 3 * pow(l,2) * sqrt(3) ) / 2;
    *perimetro = 6  * l;
}