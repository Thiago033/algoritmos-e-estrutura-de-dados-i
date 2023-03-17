/*
===================
check palindrome
stack
===================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
	char data;
	struct stack *link;
};

int stackSize = 0;

/*
===============================
isEmpty

	check if the stack is empty
===============================
*/
int isEmpty(struct stack *top) {
	if (top == NULL) {
		return 1;
	} else {
		return 0;
	}
}

/*
============================================
push

	adds an element to the top of the Stack.
============================================
*/
void push(struct stack **top, char data) {
	struct stack *newNode;
	newNode = malloc(sizeof(newNode));

	newNode->data = data;
	newNode->link = NULL;

	newNode->link = *top;
	*top = newNode;
}

/*
===============================================
pop

	removes the topmost element from the stack.
===============================================
*/
char pop(struct stack **top) {
	struct stack *temp;
	char data;

	if (isEmpty(*top)) {
		printf("Stack is empty!");
		exit(1);
	}

	temp = *top;

	data = temp->data;
	*top = temp->link;

	free(temp);
	temp = NULL;

	return data;
}

/*
============================================
checkPalindrome

	compares each element of the two stacks, 
	to check if the word is a palindrome
============================================
*/
int checkPalindrome(struct stack *top, struct stack *secondStackTop) {
	
	//if stack size is odd, removes the first element.
	if (stackSize % 2 != 0) pop(&top);
	
	//compare each element of the two stacks
	for (int i = 0; i < (stackSize / 2); i++) {
		if (pop(&top) != pop(&secondStackTop)) return 0;
	}

	return 1;
}

int main(int argc, char const *argv[]) {
	
	//Create the principal stack
	struct stack *top = NULL;

	char character;

	//Menu
	do {
		printf("Type a letter to add to the stack or type 'X' to exit\n");
		scanf("%c", &character);
		fflush(stdin);

		if (character == 'x' || character == 'X') {
			printf("\nx\n");
		} else {
			push(&top, character);
			stackSize++;
		}
	} while (character != 'x' && character != 'X');

	//create the 2nd stack with half of elements of primary stack
	struct stack *secondStackTop = NULL;

	//if the stack is NOT empty, create the 2nd stack
	if (!isEmpty(top)) {
		for (int i = 0; i < (stackSize / 2); i++) {
			push(&secondStackTop, pop(&top));
		}

		if (checkPalindrome(top, secondStackTop)) {
			printf("The word IS a palindrome.");
		} else {
			printf("The word is NOT a palindrome.");
		}
	} else {
		printf("Stack is empty!");
	}

	free(top);
	free(secondStackTop);

	return 0;
}