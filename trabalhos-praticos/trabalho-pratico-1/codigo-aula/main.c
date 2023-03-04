/*
=============================
Codigo feito em aula: 3/3/23
=============================
*/

#include <stdio.h>
#include <string.h>

/*

MOVES: U up/ D down/ R right/ L left
up = 1
down = -1
right = 1
left = -1

*/

int judgeCircle(char* moves) {

    // 0 = origem"
    // contadores: horizontal e vertical
    // no final do loop, se os contadores forem == 0, terminou na origem.
    int hor = 0, ver = 0;

    for (int i = 0; i < strlen(moves); i++) {
        switch (moves[i]) {
            case 'U':
                ver++;
                break;
                
            case 'D':
                ver--;
                break;
            
            case 'R':
                hor++;
                break;

            case 'L':
                hor--;
                break;
            
            default:
                break;
        }
    }
    
    if (hor == 0 && ver == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char const *argv[]) {
    // Read moves
    char *moves;
    scanf("%s", moves);

    if (judgeCircle("ULURDD")) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
    
    return 0;
}