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


int checkPalindrome( stack *firstStack, stack *secondStack, int stackSize ) {
	//if stack size is odd, AND, if the stack2 is NOT empty, removes the first element.
	if ( stackSize % 2 != 0 ) POP(firstStack);

	//compare each element of the two stacks
	for (int i = 0; i < stackSize / 2; i++) {
		if (POP(firstStack) != POP(secondStack))  return 0;
	}

	return 1;
}

int main(int argc, char const *argv[]) {
	stack *firstStack;
	firstStack = RESET();

	char character;

	do {
		printf("Type a letter to add to the stack or type 'X' to exit\n");
		scanf("%c", &character);
		fflush(stdin);

		//character = tolower(character);

		if ( character == 'x' || character == 'X' ) {
			printf("Exit...\n");
		} else {
			PUSH( firstStack, character );
		}
	} while ( character != 'x' && character != 'X' );

	stack *secondStack;
	secondStack = RESET();

	int stackSize = firstStack->top;

	if ( !IsEmpty( firstStack )) {
		for (int i = 0; i < (stackSize / 2); i++) {
			PUSH( secondStack, POP(firstStack));
		}

		if ( checkPalindrome( firstStack, secondStack, stackSize ) ) {
			printf("The word IS a palindrome.");
		} else {
			printf("The word is NOT a palindrome.");
		}
	} else {
		printf("Stack Is Empty");
		return 0;
	}

	CLEAR(firstStack);
	CLEAR(secondStack);

	return 0;
}
