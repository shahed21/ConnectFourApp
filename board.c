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
#include "matchmask.h"

#include <stdio.h>
#include <stdbool.h>
/*********************Private Function Declarations**********************/
/**
 * @brief private function to count the set bits in a uint64
 * 
 * @param n 
 * @return int number of 1s in the 64 bit integer
 */
int count_set_bits(unsigned long long n);

/**
 * @brief Get the Column mask
 * 
 * @param columnChosen 
 * @return unsigned long long returns 1s where the column is
 */
unsigned long long getColumn(short columnChosen);

/**
 * @brief Get the Row mask
 * 
 * @param rowChosen 
 * @return unsigned long long returns 1s where the row is
 */
unsigned long long getRow(short rowChosen);


/*********************Private Functions Definitions***********************/
int count_set_bits(unsigned long long n) {
  int size, count = 0;
  
  size = sizeof(unsigned long long) * 8;
  
  while(size--) {
    count += (int)(n & 0x01);
    n = n >> 1;
  }

  return count;
}

unsigned long long getColumn(short columnChosen) {
    unsigned long long mask = 1<<columnChosen, columnMask = 0;
    
    for (short i=0; i<MAX_ROWS; i++) {
        columnMask = columnMask | (mask<<(i*MAX_COLS));
    }
    return columnMask;
}

unsigned long long getRow(short rowChosen) {
    unsigned long long rowMask = (0x7f)<<(rowChosen*MAX_COLS);
    return rowMask;
}

/*********************Public Functions Definitions************************/
bool board_checkBoardValidity(
    unsigned long long xBoard,
    unsigned long long oBoard
) {
    #if (DEBUG>(3))
        printf("%016x\n\r", xBoard&oBoard);
    #endif /*(DEBUG>(3))*/
    return ((xBoard&oBoard)==0);
}

bool board_displayBoard(
    unsigned long long xBoard,
    unsigned long long oBoard
) {
    unsigned long long unitmask = 1;
    unsigned long long mask;
    short i,j;
    char tokens[MAX_ROWS*(MAX_COLS+2)];
    //char boardString[BOARD_DISPLAY_BUFFER];

    if (!board_checkBoardValidity(xBoard, oBoard)) {
        printf ("There was an error with the board. It couldn't be displayed.\n");
        return false;
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
        return true;
    }
}

bool board_checkVictoryMatch(
    unsigned long long board
) {
    for (short i = 0; i<VICTORY_MASK_LENGTH; i++) {
        if ((board&victoryMasks[i])==victoryMasks[i]) {
            return true;
        }
    }
    return false;
}

bool board_validColumnForEntry(
    unsigned long long xBoard,
    unsigned long long oBoard,
    short columnChosen
) {
    unsigned long long board = xBoard|oBoard;
    unsigned long long columnMask = getColumn(columnChosen);

    #if (DEBUG>3)
    printf("columnMask = %016x", columnMask);
    #elif (DEBUG>5)
    board_displayBoard(columnMask, 0);
    #endif /*DEBUG*/

    return ((board&columnMask)!=columnMask);
}

void board_placeToken(
    unsigned long long *xBoard,
    unsigned long long *oBoard,
    short columnChosen,
    short whoPlays
) {
    unsigned long long board = (*xBoard)|(*oBoard);
    unsigned long long columnMask = getColumn(columnChosen);
    short rows = count_set_bits(board&columnMask);
    unsigned long long rowMask =  getRow(rows);
    
    if (whoPlays) {
        *xBoard |= columnMask&rowMask;
    } else {
        *oBoard |= columnMask&rowMask;
    }
}