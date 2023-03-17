/*
===================================
    solução com complexidade em:
        tempo  O(n)
        espaço O(n)
===================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

int nodeCounter = 0;

/*
======================================
IsEmpty

	check if the list is empty

    return true if the list is empty,
    return false if not.
======================================
*/
int IsEmpty( ListNode *head) {
    if ( head == NULL ) {
        return 1;
    } else {
        return 0;
    }
}

/*
===================================================
Push

	Adds an element to the first node of the list.
===================================================
*/
void Push( ListNode **head, int data) {
    // Creates the new node
    ListNode *newNode = malloc(sizeof(ListNode));
    newNode->val = data;
    newNode->next = NULL;

    newNode->next = *head;
	*head = newNode;

    nodeCounter++;
}

/*
===============================================
Pop

	Removes the first element from the list.
===============================================
*/
int Pop( ListNode **head ) {
    int data;
    ListNode *ptr;

    if (IsEmpty(*head)) {
		printf("List is empty!");
		exit(1);
	}

    ptr = *head;

	data = ptr->val;
	*head = ptr->next;

	free(ptr);
	ptr = NULL;

    nodeCounter--;

    return data;
}

/*
=================================================
isPalindrome

	compares each element of the two lists.

	return true if the number is a palindrome,
    return false if not.
=================================================
*/
bool isPalindrome(struct ListNode* head) {
    // Create the 2nd list with half of elements of primary list
    ListNode *secondList = NULL;

    for ( int i = 0; i < (nodeCounter / 2); i++ ) {
        Push( &secondList, Pop( &head) );
    }

    // If number of nodes in the list is odd, Pop one element
    if ( nodeCounter % 2 != 0) {
        Pop( &head );
    }
    
    for ( int i = 0; i < (nodeCounter/2); i++ ) {
        if ( Pop( &head ) != Pop( &secondList ) ) {   
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[]) {
    ListNode *head = NULL;

    Push( &head, 1);
    Push( &head, 2);
    Push( &head, 2);
    Push( &head, 1);

    if ( isPalindrome( head ) ) {
        printf("This number IS a palindrome.");
    } else {
        printf("This number is NOT a palindrome.");
    }

    return 0;
}
