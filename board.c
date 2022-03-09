/**
 * @file board.c
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This file handles the board functions
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "env.h"
#include "board.h"

#include <stdio.h>

short board_checkBoardValidity(
    unsigned long long xBoard,
    unsigned long long oBoard
) {
    #if (DEBUG>(3))
        printf("%016x\n\r", xBoard&oBoard);
    #endif /*(DEBUG>(3))*/
    return ((xBoard&oBoard)!=0);
}

void board_displayBoard(
    unsigned long long xBoard,
    unsigned long long oBoard
) {
    unsigned long long unitmask = 1;
    unsigned long long mask;
    short i,j;
    char tokens[MAX_ROWS*(MAX_COLS+2)];
    //char boardString[BOARD_DISPLAY_BUFFER];

    if (board_checkBoardValidity(xBoard, oBoard)) {
        printf ("There was an error with the board. It couldn't be displayed.\n");
    } else {
        for (i=0; i<MAX_ROWS; i++) {
            for (j=0; j<MAX_COLS; j++) {
                #if (_OS==(WINDOWS))
                tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j] = '_';
                mask = unitmask<<(i*MAX_ROWS+j);
                
                #if (DEBUG>(5))
                    printf("%016x - %i\n\r", mask, (MAX_ROWS-1-i)*(MAX_COLS+2)+j);
                #endif /*DEBUG>5*/

                if ((xBoard&mask)==mask){
                    tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j]='x';
                }
                if ((oBoard&mask)==mask) {
                    tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j]='o';
                }
                #else
                printf("%i\n", (MAX_ROWS-1-i)*(MAX_COLS)+j);
                tokens[(MAX_ROWS-1-i)*(MAX_COLS+1)+j] = '_';
                mask = unitmask<<(i*MAX_ROWS+j);
                if (xBoard&mask==mask){
                    tokens[(MAX_ROWS-1-i)*(MAX_COLS+1)+j]='x';
                }
                if (oBoard&mask == mask) {
                    tokens[(MAX_ROWS-1-i)*(MAX_COLS+1)+j]='o';
                }
                #endif /*_OS*/
            }

            #if (_OS==(WINDOWS))
            tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j] = '\r';
            tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j+1] = '\n';
            #elif ((_OS==(UNIX))||(_OS==(LINUX))||(_OS==(OSX)))
            tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j] = '\n';
            #elif (_OS==(OLD_MAC))
            tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j] = '\r';
            #endif /*_OS*/
        }
        printf("%s", tokens);
        printf("1234567%s",_NEWLINE);
    }
}