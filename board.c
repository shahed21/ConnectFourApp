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
#include "types.h"
#include "board.h"
#include "matchmask.h"

#include <stdio.h>
#include <stdbool.h>
/*********************Private Function Declarations***********************/
/**
 * @brief private function to count the set bits in a uint64
 * 
 * @param n 
 * @return int number of 1s in the 64 bit integer
 */
int count_set_bits(uint64 n);

/**
 * @brief Get the Column mask
 * 
 * @param columnChosen 
 * @return uint64 returns 1s where the column is
 */
uint64 getColumn(short columnChosen);

/**
 * @brief Get the Row mask
 * 
 * @param rowChosen 
 * @return uint64 returns 1s where the row is
 */
uint64 getRow(short rowChosen);


/*********************Private Functions Definitions***********************/
int count_set_bits(uint64 n) {
  int size, count = 0;
  
  size = sizeof(uint64) * 8;
  
  while(size--) {
    count += (int)(n & 0x01);
    n = n >> 1;
  }

  return count;
}

uint64 getColumn(short columnChosen) {
    uint64 mask = 1<<columnChosen, columnMask = 0;
    
    for (short i=0; i<MAX_ROWS; i++) {
        columnMask = columnMask | (mask<<(i*MAX_COLS));
    }
    return columnMask;
}

uint64 getRow(short rowChosen) {
    uint64 rowMask = (((uint64)0x7f)<<(rowChosen*MAX_COLS));
    return rowMask;
}

/*********************Public Functions Definitions************************/
bool board_checkBoardValidity(
    uint64 xBoard,
    uint64 oBoard
) {
    #if (DEBUG>(8))
        printf("%016x\n\r", xBoard&oBoard);
    #endif /*(DEBUG>(3))*/
    return ((xBoard&oBoard)==0);
}

bool board_checkBoardFull(
    uint64 xBoard,
    uint64 oBoard
) {
    uint64 xorVal = ((uint64)0x1ffffffffffff)^(xBoard|oBoard);

    #if (DEBUG>6)
    printf ("%llx%s", xorVal, _NEWLINE);
    #endif //(DEBUG>6)
    
    if (xorVal==0) {
        return true;
    }
    return false;
}

bool board_displayBoard(
    uint64 xBoard,
    uint64 oBoard
) {
    uint64 unitmask = 1;
    uint64 mask;
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
                
                #if (DEBUG>(8))
                    printf("%016x - %i%s", mask, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                #endif /*DEBUG>5*/

                if (mask!=(uint64)0) {
                    if ((xBoard&mask)==mask){
                        #if (DEBUG>(5))
                        printf("%d%s", sizeof(uint64),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), (xBoard),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), (xBoard&mask),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), mask,_NEWLINE);
                        printf("%d,%d,%d%s", i, j, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                        #endif /*DEBUG>5*/
                        tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j]='x';
                    }
                    if ((oBoard&mask)==mask) {
                        #if (DEBUG>(5))
                        printf("%d - %llx%s",(mask!=0), mask, _NEWLINE);
                        printf("%d,%d,%d%s", i, j, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                        #endif /*DEBUG>5*/
                        tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j]='o';
                    }
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
    uint64 board
) {
    for (short i = 0; i<VICTORY_MASK_LENGTH; i++) {
        if ((board&victoryMasks[i])==victoryMasks[i]) {
            return true;
        }
    }
    return false;
}

bool board_validColumnForEntry(
    uint64 xBoard,
    uint64 oBoard,
    short columnChosen
) {
    uint64 board = xBoard|oBoard;
    uint64 columnMask = getColumn(columnChosen);

    #if (DEBUG>3)
    printf("columnMask = %016x", columnMask);
    #elif (DEBUG>5)
    board_displayBoard(columnMask, 0);
    #endif /*DEBUG*/

    return ((board&columnMask)!=columnMask);
}

void board_placeToken(
    uint64 *xBoard,
    uint64 *oBoard,
    short columnChosen,
    short whoPlays
) {
    uint64 board = (*xBoard)|(*oBoard);
    uint64 columnMask = getColumn(columnChosen);
    short rows = count_set_bits(board&columnMask);
    uint64 rowMask =  getRow(rows);

    #if (DEBUG>5)
    printf("%s%s", _NEWLINE, _NEWLINE);
    printf("xBoard = %llx%s", *xBoard, _NEWLINE);
    printf("oBoard = %llx%s", *oBoard, _NEWLINE);
    printf("xBoardp = %x%s", xBoard, _NEWLINE);
    printf("oBoardp = %x%s", oBoard, _NEWLINE);
    printf("column = %llx%s", columnMask, _NEWLINE);
    printf("rowMsk = %llx%s", rowMask, _NEWLINE);
    printf("posMsk = %llx", rowMask&columnMask);
    printf("%s%s", _NEWLINE, _NEWLINE);
    #endif /*(DEBUG>5)*/
    
    if (whoPlays) {
        *xBoard |= ((uint64)columnMask)&((uint64)rowMask);
    } else {
        *oBoard |= ((uint64)columnMask)&((uint64)rowMask);
    }

    #if (DEBUG>5)
    printf("%s%s", _NEWLINE, _NEWLINE);
    printf("xBoard = %llx%s", *xBoard, _NEWLINE);
    printf("oBoard = %llx%s", *oBoard, _NEWLINE);
    printf("xBoardp = %x%s", xBoard, _NEWLINE);
    printf("oBoardp = %x%s", oBoard, _NEWLINE);
    printf("column = %llx%s", columnMask, _NEWLINE);
    printf("rowMsk = %llx%s", rowMask, _NEWLINE);
    printf("posMsk = %llx", rowMask&columnMask);
    printf("%s%s", _NEWLINE, _NEWLINE);
    #endif /*(DEBUG>5)*/

}