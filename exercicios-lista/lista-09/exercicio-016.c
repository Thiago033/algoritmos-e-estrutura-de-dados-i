/*
Exercicio 16:

Considere a seguinte declarac¸ao: int A, *B, **C, ***D; Escreva um programa que leia a
variavel a e calcule e exiba o dobro, o triplo e o quadruplo desse valor utilizando apenas
os ponteiros B, C e D. O ponteiro B deve ser usada para calcular o dobro, C o triplo e D
o quadruplo. 

*/

#include <stdio.h>

int main() {

    int A, *B, **C, ***D;

    A = 2;
    B = &A;
    C = &B;
    D = &C;

    printf("Dobro de A: %d\n", (*B * 2));
	printf("Triplo de A: %d\n", (**C * 3));
	printf("Quadruplo de A: %d", (***D * 4)); 
}