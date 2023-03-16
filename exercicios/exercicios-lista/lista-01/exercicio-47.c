/*
    Leia um numero inteiro de 4 digitos (de 1000 a 9999) e imprima 1 digito por linha
*/

#include <stdio.h>

int main()
{
    
    int number;
    int m, c, d, u;

    printf("Digite um inteiro de 4 digitos: ");
    scanf("%d", &number);

    m = number / 1000;
    printf("%d\n", m);

    c = (number%1000) / 100;
    printf("%d\n", c);

    d = (number%100)/10;
    printf("%d\n", d);

    u = number%10;
    printf("%d\n", u);

    return 0;
}