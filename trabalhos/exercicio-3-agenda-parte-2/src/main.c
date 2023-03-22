#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMESIZE    sizeof(char) * 10 + 1
#define AGESIZE     sizeof(int)
#define PHONESIZE   sizeof(int)
#define NEXT        NAMESIZE + AGESIZE + PHONESIZE
#define PREVIOUS    NAMESIZE + AGESIZE + PHONESIZE + sizeof(char *)
#define PERSONSIZE  NAMESIZE + AGESIZE + PHONESIZE + sizeof(char *) + sizeof(char *)

// Main buffer
void *pBuffer = NULL;


// List Pointers
//  List Start
char *head = NULL;
//  list End
char *last = NULL;

// pBuffer Variables
int *option = NULL, *personCounter = NULL, *i = NULL;
char *tempName  = NULL;
int *tempAge = NULL, *tempPhone = NULL;


/*
====================================
NewPerson

    Return a new person
====================================
*/
void* NewPerson() { 
    void *newPerson = NULL;

    newPerson = (void*)(malloc( PERSONSIZE ));

    if ( newPerson == NULL ) {
        printf("Error memory allocation");
        exit (1);
    }

    printf("Enter the name: \n");
    fflush(stdin);
    gets( tempName );

    printf("Enter the age: \n");
    fflush(stdin);
    scanf("%d", tempAge);

    printf("Enter the phone number: \n");
    fflush(stdin);
    scanf("%d", tempPhone);

    // Person Data
    strcpy( (char *)(newPerson), tempName );
    *(int *)(newPerson + NAMESIZE) = *tempAge;
    *(int *)(newPerson + NAMESIZE + AGESIZE) = *tempPhone;

    // Next Pointer
    *(char **)(newPerson + NEXT)     = NULL;
    // Previous Poiter
    *(char **)(newPerson + PREVIOUS) = NULL;

    return newPerson;
}

/*
====================================
AddPerson

    Add a new person in the list,
    sorted in alphabetic order
====================================
*/
void AddPerson( char **head ) {
    char **ptr = head;

    void *newPerson = NewPerson();

    while ( (*ptr != NULL) && strcmp( *ptr, newPerson ) < 1 ) {
        // Jump to the next person
        ptr = (char **)(*ptr + NAMESIZE + AGESIZE + PHONESIZE);
    }

    /*
    =====================
    Update Pointers    
    =====================
    */

    // Update the "next" pointer of newPerson;
    *(char **)(newPerson + NAMESIZE + AGESIZE + PHONESIZE) = *ptr;

    // Update the "next" pointer of ptr (element before newPerson);
    *ptr = newPerson;

    char *ptrPrevious = *head;

    while ( *head != NULL ) {
        ptrPrevious = *head;

        // Jump to the next person
        head = (char **)(*head + NAMESIZE + AGESIZE + PHONESIZE);

        if ( *head != NULL ) {
            // Update "previous pointer of newPerson"
            *(char **)(*head + NAMESIZE + AGESIZE + PHONESIZE + sizeof(char **)) = ptrPrevious;
        }
    }

    last = ptrPrevious;
    *personCounter = *personCounter + 1;
}

// void RemovePerson() {

// }

void PrintList( char **head ) {
    if ( (*head) == NULL ) {
        printf("List is empty.\n");
    }

    for ( *i = 0; *i < *personCounter; *i = *i + 1 ) {
        printf("Person Number: %d\n", *i + 1);
        printf("Name: %s\n",          (char *)(*head));
        printf("Age: %d\n",           *(int *)(*head + NAMESIZE));
        printf("Phone Number: %d\n",  *(int *)(*head + NAMESIZE + AGESIZE));
        printf("--------------------------------\n\n");

        head = (char **)(*head + NAMESIZE + AGESIZE + PHONESIZE);
    }
}

// void SearchPerson() {

// }

int main( int argc, char const *argv[] ) {
    // Main Buffer
    pBuffer = (void *)(malloc( (sizeof(int) * 5) + (sizeof(char) * 10 + 1) ));

    if ( pBuffer == NULL ) {
        printf("Error memory allocation");
        exit (1);
    }

    // pBuffer Variables Addresses
    i             = (int *) (pBuffer);

    option        = (int *) (pBuffer + sizeof(int));
    *option = 0;

    personCounter = (int *) (pBuffer + (sizeof(int) * 2));
    *personCounter = 0;

    tempName      = (char *)(pBuffer + (sizeof(int) * 3));
    tempAge       = (int *) (pBuffer + (sizeof(int) * 3) + (sizeof(char) * 10 + 1));
    tempPhone     = (int *) (pBuffer + (sizeof(int) * 4) + (sizeof(char) * 10 + 1));

    do {
        printf("1) Add Person\n");
        printf("2) Remove Person\n");
        printf("3) Print List\n");
        printf("4) Search Person\n");
        printf("0) Quit\n");
        scanf("%d", option);

        switch ( *option ) {
        case 1:
            AddPerson( &head );
            break;

        case 2:
            //RemovePerson(  );
            break;

        case 3:
            PrintList( &head );
            break;

        case 4:
            //SearchPerson( );
            break;

        case 0:
            system("cls");
            printf("Quit...");
            break;
        
        default:
            system("cls");
            printf("Invalid Option!\n");
            break;
        }
    } while ( option != 0 );

    return 0;
}
