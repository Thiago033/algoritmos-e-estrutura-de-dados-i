/*
Escreva um algoritmo, usando uma stack, que inverte as letras de cada palavra de um
texto terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o
texto:

ESTE EXERCICIO E MUITO FACIL
A saida deve ser:
ETSE OICICREXE E OTIUM LICAF
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct node{
    char caracter;
    struct node *next;
}Node;

Node* push(Node *stack, char valor) {
    Node *new = malloc(sizeof(Node));

    if(new){
        new->caracter = valor;
        new->next = stack;
        return new;
    }
    else
        printf("Error!!!\n");
    return NULL;
}

Node* pop(Node **stack){
    Node *remove = NULL;

    if(*stack){
        remove = *stack;
        *stack = remove->next;
    }
    else
        printf("\nStack is empty!\n");
    return remove;
}

void invertString(char data[]){
    int i = 0;
    Node *remove, *stack = NULL;

    while(data[i] != '\0'){
        if(data[i] != ' ')
            stack = push(stack, data[i]);
        else {
            while(stack){
                remove = pop(&stack);
                printf("%c", remove->caracter);
                free(remove);
            }
            printf(" ");
        }
        i++;
    }
    while(stack){
        remove = pop(&stack);
        printf("%c", remove->caracter);
        free(remove);
    }
    printf("\n");
}

int main(){
    char text[50] = {"ABCDE"};

    invertString(text);
}