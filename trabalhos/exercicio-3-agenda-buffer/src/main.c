#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer = NULL;

int main(int argc, char const *argv[]) {
    
    pBuffer = (void*)(malloc( sizeof(int) ));
    
    if ( pBuffer == NULL ) {
        printf("Memory Allocation Error!\n");
        exit (1);
    }

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
                //AddPerson()
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