#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
void *pBuffer = NULL;

                      // 10 char + '/0'                      
int personSize = ((sizeof(char) * 10) + 1) + sizeof(int) + sizeof(int);

int nameSize   = sizeof(int);
int ageSize    = sizeof(int) + ((sizeof(char) * 10) + 1);
int phoneSize = sizeof(int) + ((sizeof(char) * 10) + 1) + sizeof(int);

void AddPerson( int *personCounter, char *name, int *age, int *phoneNumber ) {
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

void PrintList( int *personCounter ) {
    system("cls");
    for ( int i = 0; i < (*personCounter); i++ ) {
        printf("User %d\n", i+1);
        // printf("Name: %s\n"          , (char*) (pBuffer + sizeof(int)                                           + (personSize * i)));
        // printf("Age: %d\n"           , *(int*) (pBuffer + sizeof(int) + ((sizeof(char) * 10) + 1)               + (personSize * i)));
        // printf("Phone Number: %d\n\n", *(int*) (pBuffer + sizeof(int) + ((sizeof(char) * 10) + 1) + sizeof(int) + (personSize * i)));

        printf("Name: %s\n"          , (char*) (pBuffer + nameSize   + (personSize * i)));
        printf("Age: %d\n"           , *(int*) (pBuffer + ageSize    + (personSize * i)));
        printf("Phone Number: %d\n\n", *(int*) (pBuffer + phoneSize + (personSize * i)));
    }
}

int main(int argc, char const *argv[]) {
    
    pBuffer = (void*)(malloc( personSize + sizeof(int) ));
    
    if ( pBuffer == NULL ) {
        printf("Memory Allocation Error!\n");
        exit (1);
    }

    //Definindo endereço incial para os ponteiros
    int *personCounter = NULL;
    personCounter = pBuffer;
    *personCounter = 0;

    // Person
    char *name = NULL;
    int *age = NULL, *phoneNumber = NULL;


    //CHANGE FOR nameSize, ageSize, phoneSize
    name        = pBuffer + sizeof(int);
    age         = pBuffer + sizeof(int) + ((sizeof(char) * 10) + 1);
    phoneNumber = pBuffer + sizeof(int) + ((sizeof(char) * 10) + 1) + sizeof(int);

    int option;

    do {
        printf("1) Add Person\n");
        printf("2) Remove Person\n");
        printf("3) Print List\n");
        printf("4) Search Person\n");
        printf("0) Sair\n");
        scanf("%d", &option);

        switch (option) {
            //Add Person
            case 1:
                *personCounter = *personCounter + 1;

                if ( *personCounter != 1 ) {

                    pBuffer = (void*)(realloc( pBuffer, personSize * (*personCounter) + sizeof(int)) );

                    if ( !pBuffer ){
                        printf("Memory Allocation Error!\n");
                        exit (1);
                    }

                    name        = pBuffer + sizeof(int) + personSize * (*personCounter-1);
                    age         = pBuffer + sizeof(int) + personSize * (*personCounter-1) + ((sizeof(char) * 10) + 1);  
                    phoneNumber = pBuffer + sizeof(int) + personSize * (*personCounter-1) + ((sizeof(char) * 10) + 1) + sizeof(int);
                }

                AddPerson( pBuffer, name, age, phoneNumber );
                break;

            case 2:
                //RemovePerson( personCounter );
                break;

            case 3:
                PrintList( personCounter );
                break;

            case 4:
                //SearchPerson( personCounter );
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