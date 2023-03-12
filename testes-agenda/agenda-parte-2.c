#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main buffer
void *pBuffer = NULL;

char *start = NULL;
char *last = NULL;

/*
========================
    pBuffer Variables
========================
*/
// Control variables
int *option = NULL, *personCounter = NULL, *i = NULL, *teste = NULL;

// Person variables
char *tempName  = NULL;
int *tempAge = NULL, *tempPhone = NULL;

// 6 int variables
// 1 char size 10+1


char* NewPerson( ) { 
    void *pBufferPessoas = NULL;

    pBufferPessoas = (void*)(malloc(TAMANHOBASE));
    if ( pBufferPessoas == NULL ) {
        printf("Error Memory Allocation");
        exit (1);
    }

    printf("Enter the name: \n");
    fflush(stdin);
    gets(tempName);

    printf("Enter the age: \n");
    fflush(stdin);
    scanf("%d", tempAge);

    printf("Enter the phone number: \n");
    fflush(stdin);
    scanf("%s", tempPhone);


    strcpy((char *)(pBufferPessoas), tempName);
    *(int *)(pBufferPessoas + TAMANHONOME) = *tempAge;
    *(int *)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE) = *tempPhone;

    *(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = NULL; //next
    *(char **)(pBufferPessoas + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = NULL; //previous

    return pBufferPessoas;
}

void Insert(char **head, char *newp){
    char **tracer = head;

    //*tracer != NULL (Existe mais elementos na fila, next != Null)
    //strcmp < 1 Enquanto não achar um elemento maior que o newp não sai do while
    while ( *tracer != NULL && strcmp( *tracer, (char *)(newp) ) < 1 ) {     
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE); //Vai para o próximo da fila
    }

    *(char **)(newp + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE) = *tracer;  //Atualiza o next do newp
    *tracer = newp; //Atualiza o next do que vem antes do newp 

    UpdatePrevious(head);
}

//Atualiza o previous de todos elementos da fila encadeada
void UpdatePrevious(char **tracer){ 
    char *tracerPrevious = *tracer;

    while (*tracer != NULL) {
        tracerPrevious = *tracer; //Memoriza o endereço anterior 
        tracer = (char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE);  //Vai para o próximo endereço da lista

        if ( *tracer != NULL ) { //Certifica-se que existe um endereço válido
            *(char **)(*tracer + TAMANHONOME + TAMANHOIDADE + TAMANHOTELEFONE + sizeof(char **)) = (char *)(tracerPrevious);
        }
    }

    //Atualiza o ponteiro last como o último elemento da lista
    last = (char *)(tracerPrevious);
}

int main( int argc, char const *argv[] ) {

    pBuffer = (void *)(malloc( (sizeof(int) * 6) + (sizeof(char) * 10 + 1) ));

    if ( pBuffer == NULL ) {
        printf("Error memory allocation");
        exit (1);
    }

    // Variables Address
    option        = (int *) (pBuffer);
    personCounter = (int *) (pBuffer + sizeof(int));
    i             = (int *) (pBuffer + (sizeof(int) * 2));
    teste         = (int *) (pBuffer + (sizeof(int) * 3));
    tempName      = (char *)(pBuffer + (sizeof(int) * 4));
    tempAge     = (int *) (pBuffer + (sizeof(int) * 4) + (sizeof(char) * 10 + 1));
    tempPhone  = (int *)(pBuffer + (sizeof(int) * 5) + (sizeof(char) * 10 + 1));

    /*
    ================================================================================================
    Buffer Variables Order:

    option | personCounter |   i   | teste |   tempName   | tempAge | tempPhone |
      int  |       int     |  int  |  int  |   char [10]  |    int  |    int    |

    ================================================================================================
    */

    *option = 0;
    *personCounter = 0;

    do {
        printf("1) Add Person\n");
        printf("2) Remove Person\n");
        printf("3) Print List\n");
        printf("4) Search Person\n");
        printf("0) Sair\n");
        scanf("%d", option);

        switch (*option) {
        case 1:
            NewPerson();
            printf("add person");
            break;

        case 2:
            //RemovePerson( personCounter );
            printf("remove person");
            break;

        case 3:
            //PrintList( personCounter );
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

    return 0;
}
