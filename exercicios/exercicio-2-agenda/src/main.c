#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global
char *names;
int letters = 0;

void AddName() {
    int i = 0;
    char newName[20];

    system("cls");

    fflush(stdin);
    printf("Enter a name to add to the list: ");
    scanf("%s", newName);

   
    strcat(newName, "-"); // Separate each name by slash(/)
    
    
    names = (char*) realloc( names, sizeof(newName) * sizeof(char) + 2 ); // Reallocate space to a new name

    if ( names == NULL ) {
        printf("Memory Allocation Error!\n");
        exit (1);
    }

    for (letters; letters <= (strlen( names )); letters++) {
        names[letters] = newName[i];
        i++;
    }

    letters--;

    system("cls");
    printf("Name added to list.\n");
}

void PrintNames() {
    system("cls");

    // Duplicate the string names
    char *string = strdup(names);

    // get the first token
    char *name = strtok( string, "-" );

    // walk through other tokens
    while( name != NULL ) {
        printf("%s\n", name);

        // get next token
        name = strtok( NULL, "-" );
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
                //RemoveName();
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