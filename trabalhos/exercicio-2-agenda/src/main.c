#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global
char *names;
int letters = 0;

/*
=======================================================================================
AddName

Adds a new name to the string "names"
=======================================================================================
*/
void AddName() {
    int i = 0;
    char newName[30];

    system("cls");

    fflush(stdin);
    printf("Enter a name to add to the list: ");
    scanf("%s", newName);

   
    strcat(newName, "/"); // Separate each name by a slash(/)
    
    
    names = (char*) realloc( names, sizeof(newName) + 2 ); // Reallocate space to a new name

    if ( names == NULL ) {
        printf("Memory Allocation Error!\n");
        exit (1);
    }

    for ( letters; letters <= (strlen( names )); letters++ ) {
        names[letters] = newName[i];
        i++;
    }

    letters--;

    system("cls");
    printf("Name added to list.\n");
}

/*
=======================================================================================
RemoveName

Removes a specific name from the string "names"
=======================================================================================
*/
void RemoveName(){
    int index;
    char nameToDelete[30];

    printf("Enter a name to delete: ");
    scanf("%s", nameToDelete);

    char *name = strstr(names, nameToDelete); // Finds the pointer to the name to be deleted in the string "names"
    
    if ( !name ) {
        printf("This name doesn't exist on the list!\n");
    } else {
        index = strlen( names ) - strlen( name );

        if (index != 0 && names[index - 1] == '/') {
            index--;
            name--;
        }

        for ( int i = 0; i <= strlen( nameToDelete ); i++ ) {
            for ( int j = 0; j < strlen( name ); j++ ) {
                names[index + j] = names[index + j + 1];
            }

            letters--;
        }

        names = (char *)realloc(names, (strlen( names )) + 2);

        system("cls");
        printf("Name Deleted\n");
    }
}

/*
=======================================================================================
PrintNames

Prints on terminal all names on the string "names"
=======================================================================================
*/
void PrintNames() {
    system("cls");

    //printf("%s\n", names);

    // Duplicate the string names
    char *string = strdup( names );

    // get the first token
    char *name = strtok( string, "/" );

    // walk through other tokens
    while( name != NULL ) {
        printf("%s\n", name);

        // get next token
        name = strtok( NULL, "/" );
    }
}

int main() {
    int option = 0;

    names = (char*) malloc( sizeof(char) ); 

    if ( names == NULL ) {
        printf("Memory Allocation Error!\n");
        exit(1);
    }

    do {
        printf("1) Add Name\n");
        printf("2) Remove Name\n");
        printf("3) Print Names\n");
        printf("0) Quit\n");
        scanf("%d", &option);

        switch ( option ) {
            case 1:
                AddName();
                break;
            case 2:
                RemoveName();
                break;
            case 3:
                PrintNames();
                break;
            case 0:
                printf("Quit...");
                break;
            default:
                system("cls");
                printf("Invalid Option!\n");
                break;
        }
    } while ( option != 0 );
    
    free(names);
}