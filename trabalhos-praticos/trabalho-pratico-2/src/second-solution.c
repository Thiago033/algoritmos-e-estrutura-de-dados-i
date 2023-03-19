/*
===================================
    solução com complexidade em:
        tempo  O(n)
        espaço O(1)
===================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;


/*
=================================================
ClearLinkedList

    Clear all nodes in the list
=================================================
*/
void ClearLinkedList( struct ListNode** head ) {
    ListNode *ptr = *head;
    ListNode *next;

    while ( ptr != NULL ) {
        next = ptr->next;
        free(ptr);
        ptr = next;
    }

    *head = NULL;
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
    ListNode *slow = head;
    ListNode *fast= head;

    // If list contains only one element, return true.
    if( head->next == NULL)  return true;

    // Find middle of linked list
    while ( fast->next && fast->next->next ) {              
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the linked list on the middle node
    // Middle node
    ListNode *ptr = slow->next;

    ListNode *prev = NULL;
    ListNode *next = NULL;

    while ( ptr != NULL ) {                                
        next = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = next;
    }
    // list before reverse: 1 2 | 2 1
    // list after reverse:  1 2 | 1 2

    // Update pointer after reversing the list.
    slow->next = prev;

    // Middle node
    ptr = slow->next;

    // head 1 2 
    // ptr  2 1

    while ( ptr ) {   
        if ( head->val != ptr->val ) {
            return false;
        }

        head = head->next;
        ptr = ptr->next;
    }

    return true;
}

int main(int argc, char const *argv[]) {
    
    // ------------------------
    ListNode *head = malloc(sizeof(ListNode));
    head->val = 1;
    head->next = NULL;
    // ------------------------

    // ------------------------
    ListNode *test = malloc(sizeof(ListNode));
    test->val = 2;
    test->next = NULL;

    // Update pointer
    head->next = test;
    // ------------------------

    // ------------------------
    ListNode *test2 = malloc(sizeof(ListNode));
    test2->val = 2;
    test2->next = NULL;

    // Update pointer
    test->next = test2;
    // ------------------------

    // ------------------------
    ListNode *test3 = malloc(sizeof(ListNode));
    test3->val = 1;
    test3->next = NULL;

    // Update pointer
    test2->next = test3;
    // ------------------------

    // List = [1, 2, 2, 1]

    if ( isPalindrome( head ) ) {
        printf("This number IS a palindrome.");
    } else {
        printf("This number is NOT a palindrome.");
    }

    ClearLinkedList(&head);

    return 0;
}
