/*
Exercicio 23:

Escreva uma funcao que retorna o maior valor de um array de tamanho N. Escreva um
programa que leia N valores inteiros, imprima o array com k elementos por linha, e o
maior elemento. O valor de k tambem deve ser fornecido pelo usuario. 

*/

#include <stdio.h>
#include <math.h>

int maxDoVetor(int *vet, int tamanho);

int main() {

    int N, num, i = 0;
    int *vetor;

    printf("Quantos numeros no vetor? \n");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("Digite o %d numero para o vetor: \n", i+1);

        scanf("%d", &num);
        vetor[i] = num;
    }

    int k;
    printf("Quantos elementos por linha? ");
    scanf("%d", &k);

    for (int j = 0; j < N; j++) {

        printf("%d ", vetor[j]);

        if(!((j + 1) % k)){
            printf("\n");
        }  
    }
    
    int maiorValor = maxDoVetor(vetor, N);

    printf("\nMaior valor do vetor: %d", maiorValor); 

    

    return 0;
}

/*
============================================================
maxDoVetor

recebe um vetor e retorna o maximo encontrado
dentro desse vetor.
============================================================
*/
int maxDoVetor(int *vet, int tamanho) {
    int maiorElemento = vet[0];

    for (int i = 0; i < tamanho; i++) {
        if (maiorElemento <= vet[i]) {
            maiorElemento = vet[i];
        }
    }
    
    return maiorElemento;
}