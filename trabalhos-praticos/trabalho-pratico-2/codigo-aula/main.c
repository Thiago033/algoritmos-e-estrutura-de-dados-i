#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

int nodeCounter = 0;

int isEmpty( ListNode *head) {
    if ( head->next == NULL ) {
        return 1;
    } else {
        return 0;
    }
}

// add element to the end of the list
void Push( ListNode **head, int data) {
    // Creates the new node
    ListNode *temp = malloc(sizeof(ListNode));
    temp->val = data;
    temp->next = NULL;

    ListNode *ptr = *head;

    // If is the first element
    if ( nodeCounter == 0 ) {
        (*head) = temp;
        nodeCounter++;
        return;
    }

    // Go to the end of the list
    while ( ptr->next != NULL) {
        ptr = ptr->next;
    }

    // Update pointer
    ptr->next = temp;

    nodeCounter++;
}

// remove element from the end of the list
int Pop( ListNode **head ) {
    int data;
    ListNode *ptr = *head;
    ListNode *previous;

    while ( ptr->next != NULL){
        previous = ptr;
        ptr = ptr->next;
    }

    data = ptr->val;

    free(ptr);

    previous->next = NULL;

    return data;
}

void PrintList( ListNode *head)  {
    ListNode *ptr = head;

    while ( ptr != NULL ) {
        printf("%d", ptr->val);
        ptr = ptr->next;
    }
}

bool isPalindrome(struct ListNode* head) {
    //TEST
    int counter2 = nodeCounter;

    ListNode *secondList = malloc(sizeof(ListNode));

    // pass half of the elements to another list
    nodeCounter = 0;
    for ( int i = 0; i < (counter2/2); i++ ) {
        Push( &secondList, Pop( &head) );
    }

    // If number of nodes in the list is odd
    // Pop one element
    if ( counter2 % 2 != 0) {
        Pop( &head );
    }
    
    for ( int i = 0; i < (counter2/2); i++ ) {
        if ( Pop( &head ) != Pop( &secondList ) ) {   
            return false;
        } else {
            return true;
        }
        
    }
}

int main(int argc, char const *argv[]) {
    ListNode *head = malloc(sizeof(ListNode));
    head->val = 1;
    head->next = NULL;

    ListNode *test = malloc(sizeof(ListNode));
    test->val = 2;
    test->next = NULL;

    // Update pointer
    head->next = test;

    ListNode *test2 = malloc(sizeof(ListNode));
    test2->val = 1;
    test2->next = NULL;

    // Update pointer
    test->next = test2;


    PrintList( head );

    //Push( &head, 1);
    //Push( &head, 2);
    //Push( &head, 2);
    //Push( &head, 1);


    //test only
    nodeCounter = 3;

    if ( isPalindrome( head ) ) {
        printf("true");
    } else {
        printf("false");
    }

    return 0;
}
