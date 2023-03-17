/*
===================
check palindrome
linked-list stack
===================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct stack {
	int *array;
	int base;
	int top;
} stack;

int IsEmpty( stack *stack ) {
	if ( stack->top == stack->base ) {
		return 1;
	} else {
		return 0;
	}
	
}

stack *RESET() {
	stack *stack = malloc( sizeof(stack) );

	stack->array = NULL;
	stack->base = 0;
	stack->top = 0;

	return stack;
}

void CLEAR( stack *stack ) {
    free( stack->array );
    free( stack );
}

void PUSH( stack *stack, int data ) {

	stack->array = (int *)(realloc( stack->array, sizeof(int) * (stack->top + 1) ));

	if ( stack->array == NULL ) {
		printf("Error Memory Allocation");
	} else {
		stack->array[stack->top] = data;
		stack->top++;
		stack->base = 0;
	}
}

int POP( stack *stack ) {
	int data;

	if ( IsEmpty( stack ) ) {
		printf("Stack Is Empty");
		exit(1);
	} else {
		data = stack->array[stack->top - 1];
		stack->top--;
		stack->array = (int *)(realloc( stack->array, sizeof(int) * (stack->top) ));
	}

	return data;
}


// Return 1 if expression has balanced Brackets
int CallPoints( char** exp ) {
    int value1;
    int value2;
    int ans = 0;

    stack *stack;
    stack = RESET();

    int i = 0;
    while( i < 5 ) {

        if (exp[i][0] == 'C') {
            POP( stack );

        } else if ( exp[i][0] == 'D' ) {
            value1 = POP( stack );
            PUSH( stack , value1 );
            PUSH( stack, value1*2 );

        } else if ( exp[i][0] == '+' ) {
            value2 = POP( stack );
            value1 = POP( stack );
            PUSH( stack, value1 );
            PUSH( stack, value2 );
            PUSH( stack, (value1 + value2) );
        } else {
            char c[2];
            c[0] = exp[i][0];
            c[1] = '\0';

            int value = atoi( c );
            PUSH( stack, value );
        }

        i++;
    }

    for (int i = 0; i < 3; i++) {
        ans +=  POP( stack );
    }
    

    return ans;
}


int main(int argc, char const *argv[]) {
	char *ops[] = {"5","2","C","D","+"};

    // printf("Enter a string of \n");
    // gets(ops);

    // Function call
    printf("Points: %d", CallPoints( ops ));

	return 0;
}