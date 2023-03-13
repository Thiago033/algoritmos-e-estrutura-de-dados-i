#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

void CountOfNodes( node *head ) {
    int count = 0;

    if ( head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    printf("Nodes in the list: %d\n", count);
}

void PrintListData( node *head ) {
    if ( head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = NULL;
    ptr = head;

    while (ptr != NULL) {
        printf("Node data: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

void ReverseList ( node **head ) {

    node *ptr = *head;
    node *ptr2 = ptr->next;

    ptr->next = NULL;
    ptr->prev = ptr2;

    while ( ptr2 != NULL ) {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr;
        ptr = ptr2;
        ptr2 = ptr2->prev;
    }

    *head = ptr;
}

/*
=================
    PUSHs
=================
*/
void InsertAtEnd( node *head, int data ) {
    node *ptr, *newNode;
    ptr = head;

    //Creates the new node
    //Can be a separate function
    newNode = (node *) malloc( sizeof(node) );
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    //Go to the end of the list
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->prev = ptr;
}

void InsertAtBeg( node **head, int data ) {
    //Creates the new node
    //Can be a separate function
    node *newNode = (node *) malloc( sizeof(node) );
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    newNode->next = *head;
    (*head)->prev = newNode;

    *head = newNode;
}

void InsertAtPos( node *head, int data, int pos ) {
    node *ptr = head, *ptr2 = NULL;

    //Creates the new node
    //Can be a separate function
    node *newNode = (node *) malloc( sizeof(node) );
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    pos--;
    while ( pos != 1 ) {
        ptr = ptr->next;
        pos--;
    }

    if ( ptr->next == NULL) {
        ptr->next = newNode;
        newNode->prev = ptr;
    } else {
        ptr2 = ptr->next;
        ptr->next = newNode;
        ptr2->prev = newNode;
        newNode->next = ptr2;
        newNode->prev = ptr2;
    }
}

// /*
// =================
//     POPs
// =================
// */
void DeleteAtEnd( node *head ) {
    if ( head == NULL ) {
        printf("Linked list is empty.");
    }

    node *ptr = head;

    while ( ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->prev->next = NULL;
    free( ptr );
}

void DeleteAtBeg( node **head ) {
    if ( *head == NULL ) {
        printf("Linked list is empty.");
    } else {
        node *ptr = *head;

        *head = (*head)->next;

        free( ptr );
        ptr = NULL;
        (*head)->prev = NULL;
    }
}

void DeleteAtPos( node **head, int pos ) {
    node *current = *head;
    node *previous = NULL;

    if ( *head == NULL ) {
        printf("Linked list is empty.");
    } else if ( pos == 1 ) {
        *head = current->next;

        free( current );
        current = NULL;
        (*head)->prev = NULL;
    } else {
        while ( pos > 1 ) {
            current = current->next;
            pos--;
        }

        if (current->next == NULL) {
            current->prev->next = NULL;
            free( current ); 

        } else {
            previous = current->prev;
            previous->next = current->next;
            current->next->prev = previous;

            free( current );
            current = NULL;
        }
    }
}

void DeleteAllList( node **head ) {
    if ( *head == NULL ) {
        printf("Linked list is empty.\n");
        return;
    }

    node *ptr = *head;

    while ( ptr != NULL ) {
        ptr = ptr->next;
        free( *head );
        *head = ptr;
    }
}


int main() {
    
    node *head = (node *) malloc( sizeof(node) );
    
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;

    InsertAtEnd( head, 2);
    InsertAtEnd( head, 3);
    InsertAtEnd( head, 4);

    InsertAtBeg(&head, 10);

    InsertAtPos( head, 11, 6);


    // 10 1 2 3 4 11

    DeleteAtEnd(head);

    // 10 1 2 3 4

    DeleteAtBeg(&head);

    // 1 2 3 4

    DeleteAtPos(&head, 2);

    // 1 3 4

    ReverseList(&head);

    // 4 3 1

    CountOfNodes( head );
    PrintListData( head );

    DeleteAllList( &head );

    return 0;
}
