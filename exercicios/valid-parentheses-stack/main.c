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
	char *array;
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

void PUSH( stack *stack, char characterDigitada ) {

	stack->array = (char *)(realloc( stack->array, sizeof(char) * (stack->top + 1) + sizeof(char)) );

	if ( stack->array == NULL ) {
		printf("Error Memory Allocation");
	} else {
		stack->array[stack->top] = characterDigitada;
		stack->top++;
		stack->base = 0;
		stack->array[stack->top] = '\0';
	}
}

char POP( stack *stack ) {
	char data;

	if ( IsEmpty( stack ) ) {
		printf("Stack Is Empty");
		exit(1);
	} else {
		data = stack->array[stack->top - 1];
		stack->array[stack->top - 1] = '\0';
		stack->top--;
		stack->array = (char *)(realloc(stack->array, sizeof(char) * (stack->top + 1) + sizeof(char)));
	}

	return data;
}

// Returns 1 if character1 and character2 are matching left
// and right Brackets
bool IsMatchingPair( char character1, char character2 ) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}

// Return 1 if expression has balanced Brackets
bool AreBracketsBalanced( char exp[] ) {
    int i = 0;
 
    stack *stack;
    stack = RESET();
 
    while ( exp[i] ) {
        // If the exp[i] is a starting bracket then push it
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') PUSH( stack, exp[i] );
 
        // If exp[i] is an ending bracket then pop from stack and 
        //check if the popped bracket is a matching pair
        if ( exp[i] == '}' || exp[i] == ')' || exp[i] == ']' ) {
            // If we see an ending bracket without a pair then return false
            if ( stack == NULL ) {
                return 0;

            // Pop the top element from stack, if it is not a pair bracket of character then there is a mismatch.
            // his happens for expressions like {(})
            } else if ( !IsMatchingPair(POP( stack ), exp[i]) ) {
                return 0;
            }
        }

        i++;
    }
 
    // If there is something left in expression then there
    // is a starting bracket without a closing
    // bracket
    if ( IsEmpty( stack ) ) {
        return 1; // balanced
    } else {
        return 0; // not balanced
    }
}


int main(int argc, char const *argv[]) {
	char parenthesesArray[10000];

    printf("Enter a string of paranthesis\n");
    gets(parenthesesArray);

    // Function call
    if ( AreBracketsBalanced( parenthesesArray ) )
        printf("Balanced \n");
    else
        printf("Not Balanced \n");
    return 0;

	return 0;
}
