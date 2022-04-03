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
 * @brief private function to count the set bits in a u64
 * 
 * @param n 
 * @return i32 number of 1s in the 64 bit integer
 */
i32 count_set_bits(u64 n);

/**
 * @brief Get the Column mask
 * 
 * @param columnChosen 
 * @return u64 returns 1s where the column is
 */
u64 getColumn(i16 columnChosen);

/**
 * @brief Get the Row mask
 * 
 * @param rowChosen 
 * @return u64 returns 1s where the row is
 */
u64 getRow(i16 rowChosen);


/*********************Private Functions Definitions***********************/
i32 count_set_bits(u64 n) {
  i32 size, count = 0;
  
  size = sizeof(u64) * 8;
  
  while(size--) {
    count += (i32)(n & 0x01);
    n = n >> 1;
  }

  return count;
}

//TODO: Change this function into a u64 array macro
u64 getColumn(i16 columnChosen) {
    u64 mask = 1<<columnChosen, columnMask = 0;
    
    for (i16 i=0; i<MAX_ROWS; i++) {
        columnMask = columnMask | (mask<<(i*MAX_COLS));
    }
    return columnMask;
}

//TODO: Change this function into a u64 array macro
u64 getRow(i16 rowChosen) {
    u64 rowMask = (((u64)0x7f)<<(rowChosen*MAX_COLS));
    return rowMask;
}

/*********************Public Functions Definitions************************/
bool board_checkBoardValidity(
    u64 xBoard,
    u64 oBoard
) {
    #if (DEBUG>=(OLD_DEBUG))
        printf("%016x\n\r", xBoard&oBoard);
    #endif /*(DEBUG>=(OLD_DEBUG))*/
    return ((xBoard&oBoard)==0);
}

bool board_checkBoardFull(
    u64 xBoard,
    u64 oBoard
) {
    u64 xorVal = ((u64)0x1ffffffffffff)^(xBoard|oBoard);

    #if (DEBUG>=(OLD_DEBUG))
    printf ("%llx%s", xorVal, _NEWLINE);
    #endif //(DEBUG>=(OLD_DEBUG))
    
    if (xorVal==0) {
        return true;
    }
    return false;
}

bool board_displayBoard(
    u64 xBoard,
    u64 oBoard
) {
    u64 unitmask = 1;
    u64 mask;
    i16 i,j;
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
                
                #if (DEBUG>=(OLD_DEBUG))
                    printf("%016x - %i%s", mask, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                #endif /*(DEBUG>=(OLD_DEBUG))*/

                if (mask!=(u64)0) {
                    if ((xBoard&mask)==mask){
                        #if (DEBUG>=(OLD_DEBUG))
                        printf("%d%s", sizeof(u64),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), (xBoard),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), (xBoard&mask),_NEWLINE);
                        printf("%d - %llx%s",(mask!=0), mask,_NEWLINE);
                        printf("%d,%d,%d%s", i, j, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                        #endif /*(DEBUG>=(OLD_DEBUG))*/
                        tokens[(MAX_ROWS-1-i)*(MAX_COLS+2)+j]='x';
                    }
                    if ((oBoard&mask)==mask) {
                        #if (DEBUG>=(OLD_DEBUG))
                        printf("%d - %llx%s",(mask!=0), mask, _NEWLINE);
                        printf("%d,%d,%d%s", i, j, (MAX_ROWS-1-i)*(MAX_COLS+2)+j, _NEWLINE);
                        #endif /*(DEBUG>=(OLD_DEBUG))*/
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
    u64 board
) {
    for (i16 i = 0; i<VICTORY_MASK_LENGTH; i++) {
        if ((board&victoryMasks[i])==victoryMasks[i]) {
            return true;
        }
    }
    return false;
}

bool board_validColumnForEntry(
    u64 xBoard,
    u64 oBoard,
    i16 columnChosen
) {
    u64 board = xBoard|oBoard;
    u64 columnMask = getColumn(columnChosen);

    #if (DEBUG>=(OLD_DEBUG))
    printf("columnMask = %016x", columnMask);
    board_displayBoard(columnMask, 0);
    #endif /*(DEBUG>=(OLD_DEBUG))*/

    return ((board&columnMask)!=columnMask);
}

void board_placeToken(
    u64 *xBoard,
    u64 *oBoard,
    i16 columnChosen,
    i16 whoPlays
) {
    u64 board = (*xBoard)|(*oBoard);
    u64 columnMask = getColumn(columnChosen);
    i16 rows = count_set_bits(board&columnMask);
    u64 rowMask =  getRow(rows);

    #if (DEBUG>=(OLD_DEBUG))
    printf("%s%s", _NEWLINE, _NEWLINE);
    printf("xBoard = %llx%s", *xBoard, _NEWLINE);
    printf("oBoard = %llx%s", *oBoard, _NEWLINE);
    printf("xBoardp = %x%s", xBoard, _NEWLINE);
    printf("oBoardp = %x%s", oBoard, _NEWLINE);
    printf("column = %llx%s", columnMask, _NEWLINE);
    printf("rowMsk = %llx%s", rowMask, _NEWLINE);
    printf("posMsk = %llx", rowMask&columnMask);
    printf("%s%s", _NEWLINE, _NEWLINE);
    #endif /*(DEBUG>=(OLD_DEBUG))*/
    
    if (whoPlays) {
        *xBoard |= ((u64)columnMask)&((u64)rowMask);
    } else {
        *oBoard |= ((u64)columnMask)&((u64)rowMask);
    }

    #if (DEBUG>=(OLD_DEBUG))
    printf("%s%s", _NEWLINE, _NEWLINE);
    printf("xBoard = %llx%s", *xBoard, _NEWLINE);
    printf("oBoard = %llx%s", *oBoard, _NEWLINE);
    printf("xBoardp = %x%s", xBoard, _NEWLINE);
    printf("oBoardp = %x%s", oBoard, _NEWLINE);
    printf("column = %llx%s", columnMask, _NEWLINE);
    printf("rowMsk = %llx%s", rowMask, _NEWLINE);
    printf("posMsk = %llx", rowMask&columnMask);
    printf("%s%s", _NEWLINE, _NEWLINE);
    #endif /*(DEBUG>=(OLD_DEBUG))*/

}