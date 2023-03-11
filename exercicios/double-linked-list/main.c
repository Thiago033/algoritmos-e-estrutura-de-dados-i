#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
} node;

// void CountOfNodes( node *head ) {
//     int count = 0;

//     if ( head == NULL ) {
//         printf("Linked list is empty.\n");
//         return;
//     }

//     node *ptr = NULL;
//     ptr = head;

//     while (ptr != NULL) {
//         count++;
//         ptr = ptr->link;
//     }

//     printf("Nodes in the list: %d\n", count);
// }

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

// void ReverseList ( node **head ) {

//     node *prev = NULL, *next = NULL;

//     while ( *head != NULL ) {
//         next = (*head)->link;
//         (*head)->link = prev;
//         prev = *head;
//         *head = next;
//     }

//     *head = prev;
// }

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
// void DeleteAtEnd( node *head ) {
//     if ( head == NULL ) {
//         printf("Linked list is empty.");
//     } else if ( head->link == NULL ){
//         free(head);
//         head = NULL;
//     } else {
//         node *ptr = head;

//         while ( ptr->link->link != NULL) {
//             ptr = ptr->link;
//         }

//         free( ptr->link );
//         ptr->link = NULL;
//     }
// }

// void DeleteAtBeg( node **head ) {
//     if ( *head == NULL ) {
//         printf("Linked list is empty.");
//     } else {
//         node *ptr = *head;

//         *head = (*head)->link;

//         free( ptr );
//         ptr = NULL;
//     }
// }

// void DeleteAtPos( node **head, int pos ) {
//     node *current = *head;
//     node *previous = *head;

//     if ( *head == NULL ) {
//         printf("Linked list is empty.");
//     } else if ( pos == 1 ) {
//         *head = current->link;
//         free( current );
//         current = NULL;
//     } else {
//         while ( pos != 1 ) {
//             previous = current;
//             current = current->link;
//             pos--;
//         }

//         previous->link = current->link;
//         free( current );
//         current = NULL;
//     }
// }

// void DeleteAllList( node **head ) {
//     if ( *head == NULL ) {
//         printf("Linked list is empty.\n");
//         return;
//     }

//     node *ptr = *head;

//     while ( ptr != NULL ) {
//         ptr = ptr->link;
//         free( *head );
//         *head = ptr;
//     }
// }


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

    // DeleteAtEnd(head);

    // DeleteAtBeg(&head);
    
    // DeleteAtPos(&head, 2);

    // 1 3 4

    // ReverseList(&head);

    // 4 3 1

    // CountOfNodes( head );
    PrintListData( head );

    // DeleteAllList( &head );

    return 0;
}
