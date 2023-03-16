/*
    Exercicio 22:
        
    Crie uma func¸ao para somar dois arrays. Esta func¸ ˜ ao deve receber dois arrays e retornar ˜
    a soma em um terceiro array. Caso o tamanho do primeiro e segundo array seja diferente
    entao a func¸ ˜ ao retornar ˜ a ZERO (0). Caso a func¸ ´ ao seja conclu ˜ ´ıda com sucesso a mesma
    deve retornar o valor UM (1). Utilize aritmetica de ponteiros para manipulac¸ ´ ao do array
*/

#include <stdio.h>

// int somarVetores(int *vet1, int *vet2, int *somaVetores);

int main() {
    int *vetor1, *vetor2;
    // int *somaVetores;


    for (int i = 0; i < 10; i++) {
        printf("Digite o %d numero para o vetor 1: \n", i+1);
        scanf("%d", &vetor1[i]);
    }

    for (int j = 0; j < 10; j++) {
        printf("Digite o %d numero para o vetor 2: \n", j+1);
        scanf("%d", &vetor2[j]);
    }
    

    // int retorno = somarVetores(vetor1, vaitomanocu, somaVetores);

    // if (retorno == 0) {
    //     printf("Vetores de tamanhos diferentes!");
    // } else {
    //     for (int i = 0; i < 10; i++){
    //         printf("%d", somaVetores[i]);
    //     }  
    // }
    
    return 0;
}

// int somarVetores(int *vet1, int *vet2, int *somaVetores){
//     for (int i = 0; i < 10; i++){
//         *(somaVetores+i) = *(vet1+i) = *(vet2+i);
//     }

//     return 1;
// }