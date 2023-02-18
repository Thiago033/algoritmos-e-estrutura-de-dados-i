#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
void *pBuffer = NULL;

                    // 10 char + '/0'                      
int personSize = ((sizeof(char) * 10) + 1) + sizeof(int) + sizeof(int);

int nameSize = ((sizeof(char) * 10) + 1);
int ageSize  = ((sizeof(char) * 10) + 1) + sizeof(int);


void AddPerson () {
    printf("teste");
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

    int option, personCounter = 0;

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

                AddPerson();

                personCounter++;
                break;

            case 2:
                //RemovePerson();
                break;

            case 3:
                //PrintList();
                break;

            case 4:
                //SearchPerson();
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