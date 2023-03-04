#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judgeCircle( char* moves ) {
/*
======================================
    MOVES: "U" - up / "D" - down / "R" - right / "L" - left

    up    = ver = +1
    down  = ver = -1

    right = hor = +1
    left  = hor = -1
======================================
*/

    int hor = 0, ver = 0;

    for ( int i = 0; i < strlen( moves ); i++ ) {
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
    
    // hor & ver == 0: origin
    if ( hor == 0 && ver == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

int main( int argc, char const *argv[] ) {
    char moves[50];

    printf("Enter the string of moves: ");
    scanf("%s", moves);

    printf(judgeCircle( moves ) ? "True" : "False");
    
    return 0;
}