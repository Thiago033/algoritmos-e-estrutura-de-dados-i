#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
void *pBuffer = NULL;

                        // 10 char + '/0'                      
int personSize = ((sizeof(char) * 10) + 1) + sizeof(int) + sizeof(int);

int nameSize = ((sizeof(char) * 10) + 1);
int ageSize  = ((sizeof(char) * 10) + 1) + sizeof(int);

int personCounter = 0;
 
void AddPerson( char *name, int *age, int *phoneNumber ) {
    char tempName[10];
    int tempAge, tempPhone;

    printf("Enter the name: ");
    fflush(stdin);
    gets(tempName);
    strcpy(name,tempName);

    printf("Enter the age: ");
    fflush(stdin);
    scanf("%d", &tempAge);
    *age = tempAge;

    printf("Enter the phone number: ");
    fflush(stdin);
    scanf("%d", &tempPhone);
    *phoneNumber = tempPhone;
}

void PrintList( int personCounter ) {
    system("cls");
    for ( int i = 0; i < personCounter; i++ ) {
        printf("User %d\n", i+1);
        printf("Name: %s\n"          , (char*) (pBuffer            + (personSize * i)));
        printf("Age: %d\n"           , *(int*) (pBuffer + nameSize + (personSize * i)));
        printf("Phone Number: %d\n\n", *(int*) (pBuffer + ageSize  + (personSize * i)));
    }
}

void SearchPerson(int personCounter){
    char tempName[10];
    
    system("cls");
    printf("Enter a name to search: ");
    scanf("%s", tempName);

    for ( int i = 0; i <= personCounter; i++ ) {
        if ( strcmp( tempName, (pBuffer + (personSize * i))) == 0 ) {
            printf("Name: %s\n"          , (char*) (pBuffer            + (personSize * i)));
            printf("Age: %d\n"           , *(int*) (pBuffer + nameSize + (personSize * i)));
            printf("Phone Number: %d\n\n", *(int*) (pBuffer + ageSize  + (personSize * i)));

            return;
        }
    }

    printf("Name not founded!\n");
}

void RemovePerson ( int personCounter ) {
    char tempName[10];

    printf("Digite o nome que quer excluir: ");
    fflush(stdin);
    gets(tempName);

    for( int i = 0; i < personCounter; i++ ) {

        if ( strcmp( (char *) (pBuffer + personSize * i), tempName ) == 0 ) {

            printf("Name: %s\n"          , (char*) (pBuffer            + (personSize * i)));
            printf("Age: %d\n"           , *(int*) (pBuffer + nameSize + (personSize * i)));
            printf("Phone Number: %d\n\n", *(int*) (pBuffer + ageSize  + (personSize * i)));

            for ( int j = i; j < personCounter; j++ ) {

                strcpy( 
                    (char*)pBuffer + personSize * j,
                    (char*)pBuffer + personSize * (j + 1)
                );

                *(int*)(pBuffer + nameSize + (personSize * j)) = *(int*)(pBuffer + nameSize + (personSize) * (j + 1));

                *(int*)(pBuffer + ageSize + (personSize * j)) = *(int*)(pBuffer + ageSize + (personSize) * (j + 1));
            }

            personCounter = personCounter - 1;
            pBuffer = realloc(pBuffer, personSize * personCounter);

            return;
        }
    }

    printf("Name not founded.");
}

int main(int argc, char const *argv[]) {
    
    pBuffer = (void*)(malloc( personSize ));
    
    if ( pBuffer == NULL ) {
        printf("Memory Allocation Error!\n");
        exit (1);
    }

    // Person
    char *name = NULL;
    int *age = NULL, *phoneNumber = NULL;

    name        = pBuffer;
    age         = pBuffer + nameSize;
    phoneNumber = pBuffer + ageSize;

    int option;

    do {
        printf("1) Add Person\n");
        printf("2) Remove Person\n");
        printf("3) Print List\n");
        printf("4) Search Person\n");
        printf("0) Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                if ( personCounter != 0 ) {

                    pBuffer = (void*) realloc( pBuffer, (personSize * (personCounter+1)) );

                    if ( !pBuffer ){
                        printf("Memory Allocation Error!\n");
                        exit (1);
                    }

                    name        = pBuffer +            personSize * personCounter;
                    age         = pBuffer + nameSize + personSize * personCounter;
                    phoneNumber = pBuffer + ageSize  + personSize * personCounter;
                }

                AddPerson( name, age, phoneNumber );

                personCounter++;
                break;

            case 2:
                RemovePerson( personCounter );
                break;

            case 3:
                PrintList( personCounter );
                break;

            case 4:
                SearchPerson( personCounter );
                break;

            case 0:
                system("cls");
                printf("Quit...");
                free( pBuffer );
                break;
            
            default:
                system("cls");
                printf("Invalid Option!\n");
                break;
            }
    } while ( option != 0 );
}