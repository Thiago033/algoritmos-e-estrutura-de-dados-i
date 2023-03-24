#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define NAMESIZE    sizeof(char) * 10 + 1
#define AGESIZE     sizeof(int)
#define PHONESIZE   sizeof(int)

#define NEXT        NAMESIZE + AGESIZE + PHONESIZE
#define PREVIOUS    NAMESIZE + AGESIZE + PHONESIZE + sizeof(char *)

#define PERSONSIZE  NAMESIZE + AGESIZE + PHONESIZE + sizeof(char *) + sizeof(char *)

// Persons List Head
char *head = NULL;

/*
List structure
    | name | age | phone | next | previous |

    |"nameA" "ageA" "phoneA" 2000 NULL| <-> |"nameB" "ageB" "phoneB" 3000 1000| <-> |"nameC" "ageC" "phoneC" NULL 2000|
                    1000                                    2000                                    3000
*/


// Main buffer
void *pBuffer = NULL;

// pBuffer Variables
int *option = NULL, *personCounter = NULL, *i = NULL;
char *tempName  = NULL;
int *tempAge = NULL, *tempPhone = NULL;

/*
==========================================
isEmpty

    Check if the list is empty

    return TRUE if is empty
    return FALSE otherwise
==========================================
*/
bool isEmpty( char **head ) {
    if ( *head == NULL ) {
        return true;
    } else {
        return false;
    }
}

/*
==========================================
NewPerson

    Return a pointer to a new person data
==========================================
*/
void* NewPerson() { 
    void *newPerson = NULL;

    newPerson = (void*)(malloc( PERSONSIZE ));

    if ( newPerson == NULL ) {
        printf("Error memory allocation");
        exit (1);
    }
    system("cls");

    printf("Enter the name: \n");
    fflush(stdin);
    gets( tempName );

    printf("Enter the age: \n");
    fflush(stdin);
    scanf("%d", tempAge);

    printf("Enter the phone number: \n");
    fflush(stdin);
    scanf("%d", tempPhone);


    // Copy Person Data
    strcpy( (char *)(newPerson), tempName );
    *(int *)(newPerson + NAMESIZE) = *tempAge;
    *(int *)(newPerson + NAMESIZE + AGESIZE) = *tempPhone;

    // Update "Next" Pointer
    *(char **)(newPerson + NEXT)     = NULL;
    // Update "Previous" Poiter
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

    // Creates a new person
    void *newPerson = NewPerson();

    while ( (*ptr != NULL) && strcmp( *ptr, newPerson ) < 1 ) {
        // Jump to the next person
        ptr = (char **)(*ptr + NEXT);
    }

    // Update the "next" pointer of newPerson;
    *(char **)(newPerson + NEXT) = *ptr;

    // Update the "next" pointer of ptr;
    *ptr = newPerson;

    char *ptrPrevious = *head;

    while ( *head != NULL ) {
        ptrPrevious = *head;

        // Jump to the next person
        head = (char **)(*head + NEXT);

        if ( *head != NULL ) {
            // Update "previous" pointer of newPerson
            *(char **)(*head + PREVIOUS) = ptrPrevious;
        }
    }

    *personCounter = *personCounter + 1;
}

void RemovePerson( char **head ) {
    char *ptr = NULL;
    
    if ( isEmpty( head ) ) {
        system("cls");
        printf("List is empty.\n\n");
        return;
    } else {
        // Remove person on the head of the list
        ptr = *head; 

        // Jump to the next person
        *head =  *(char **)(*head + NEXT); 

        free(ptr);

        system("cls");
        printf ("Person Removed.\n\n");

        // If list is not empty after remove a person
        if ( !isEmpty( head ) ) {
            // Update "previous" pointer
            *(char **)(*head + PREVIOUS) = NULL;
        }

        *personCounter = *personCounter - 1;
    }
}

void PrintList( char **head ) {
    if ( isEmpty( head ) ) {
        system("cls");
        printf("List is empty.\n\n");
        return;
    }

    system("cls");

    printf("Person Counter: %d\n", *(int *)(personCounter));
    printf("First name on the list: %s\n", (char *)(*head));
    printf("Last name on the list: %s\n\n",(char *)(last));


    for ( *i = 0; *i < *personCounter; *i = *i + 1 ) {
        printf("Person Number: %d\n", *i + 1);
        printf("Name: %s\n",          (char *)(*head));
        printf("Age: %d\n",           *(int *)(*head + NAMESIZE));
        printf("Phone Number: %d\n",  *(int *)(*head + NAMESIZE + AGESIZE));
        printf("--------------------------------\n\n");

        head = (char **)(*head + NEXT);
    }
}

void SearchPerson( char **head ) {
    if ( isEmpty( head ) ) {
        system("cls");
        printf("List is empty.\n\n");
        return;
    }

    system("cls");

    printf("Enter the name to search: \n");
    fflush(stdin);
    gets( tempName );

    while ( *head != NULL ) {
        if ( strcmp( *head, tempName ) == 0 ) {
        // If name founded, print and return
            system("cls");
            printf("Name: %s\n",          (char *)(*head));
            printf("Age: %d\n",           *(int *)(*head + NAMESIZE));
            printf("Phone Number: %d\n",  *(int *)(*head + NAMESIZE + AGESIZE));

            return;
        } else {
            // Jump to the next person
            head = (char **)(*head + NEXT);
        }
    }

    system("cls");
    printf("Name not founded!\n");
}

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

    /*
        List Structure
        |  i  | option | personCounter | tempName   | tempAge | tempPhone |
        | int |   int  |      int      | char[10]+1 |    int  |    int    |
    */


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
            RemovePerson( &head );
            break;

        case 3:
            PrintList( &head );
            break;

        case 4:
            SearchPerson( &head );
            break;

        case 0:
            system("cls");
            printf("Quit...");
            free( pBuffer );
            free( head );
            exit(1);
            break;
        
        default:
            system("cls");
            printf("Invalid Option!\n");
            break;
        }
    } while ( option != 0 );

    return 0;
}
