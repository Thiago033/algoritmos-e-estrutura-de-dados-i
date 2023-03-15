#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4

int stack_arr[MAX];
int top = -1;

void IsFull() {
    if ( top == MAX - 1 ) {
        return 1;
    } else {
        return 0;
    }
}

void IsEmpty() {
    if ( top == -1 ) {
        return 1;
    } else {
        return 0;
    }
}

void Push( int data ) {
    if ( IsFull() ) {
        printf("Stack Overflow!");
        return;
    }

    top++;
    stack_arr[top] = data;
}

int Pop() {
    int value;

    if ( IsEmpty() ) {
        printf("Stack Is Empty!");
        exit(1);
    }

    value = stack_arr[top];
    top--;
    return value;
}



int main( int argc, char const *argv[] ) {
    
    int data;

    push( 1 );

    data = pop();


    return 0;
}