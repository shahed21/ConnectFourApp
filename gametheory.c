/**
 * @file gametheory.c
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This is where the computer game theory decision is made
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "types.h"
#include "board.h"
#include "matchmask.h"
#include "gametheory.h"

#include <stdio.h>
#include <stdbool.h>


/*********************Private Function Declarations***********************/
/**
 * @brief this function picks the instant victory
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @param whoPlays 1->human, 0-> computer
 * @return short returns the column number 1-7 for victory, or 0 if there is not instant victory
 */
short chooseInstantVictory(
    uint64 xBoard,
    uint64 oBoard,
    short whoPlays);

/**
 * @brief this function avoid instant loss, by showing which columns to avoid
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @param whoPlays 1->human, 0-> computer
 * @param acceptableColumnMask is a pointer to a acceptableColumnMask; that is read in, and written back to.
 * A 0 bit implies using that column means loss on next turn. A 1 bit implies safe turn next using the column.
 */
void avoidInstantLoss(
    uint64 xBoard,
    uint64 oBoard,
    short whoPlays,
    short *acceptableColumnMask);

/*********************Private Functions Definitions***********************/
short chooseInstantVictory(
    uint64 xBoard,
    uint64 oBoard,
    short whoPlays
) {
    for (short columnChosen=0; columnChosen<MAX_COLS; columnChosen++) {
        uint64 xBoardTemp = xBoard;
        uint64 oBoardTemp = oBoard;

        board_placeToken(&xBoardTemp,&oBoardTemp,columnChosen,whoPlays);
        if (board_checkVictoryMatch((whoPlays)?(oBoardTemp):(xBoardTemp))) {
            return columnChosen+1;
        }
    }
    return 0;
}

void avoidInstantLoss(
    uint64 xBoard,
    uint64 oBoard,
    short whoPlays,
    short *acceptableColumnMask
) {
    for (short columnChosen=0; columnChosen<MAX_COLS; columnChosen++) {
        uint64 xBoardTemp = xBoard;
        uint64 oBoardTemp = oBoard;
        bool validColumn = board_validColumnForEntry(xBoardTemp,oBoardTemp, columnChosen);
        if (!validColumn) {
            *acceptableColumnMask = (~((short)1<<columnChosen))&(*acceptableColumnMask); //remove columns already full
        } else {
            board_placeToken(&xBoardTemp,&oBoardTemp,columnChosen,whoPlays);
            short columnFound = chooseInstantVictory(xBoard, oBoard, whoPlays);
            if (columnFound) {
                *acceptableColumnMask = (~((short)1<<columnChosen))&(*acceptableColumnMask); //remove columns with Instant Losses
            }
        }
    }
}

/*********************Public Functions Definitions************************/
short gametheory_chooseColumn(
    uint64 xBoard,
    uint64 oBoard,
    short columnChosen,
    short whoPlays
) {
    short acceptableColumnsMask = 0x007f;
    short columnFound = chooseInstantVictory(xBoard, oBoard, whoPlays);
    if (columnFound) {
        return columnFound;  //Instant Victory
    }
    avoidInstantLoss(xBoard, oBoard, whoPlays, &acceptableColumnsMask);
    #if ((DEBUG)>=(NEW_DEBUG))
    printf("acceptableColumnsMask = %d%s", avoidInstantLoss, _NEWLINE);
    #endif /*((DEBUG)>=(NEW_DEBUG))*/
    for (columnChosen=0; columnChosen<MAX_COLS; columnChosen++) {
        if (acceptableColumnsMask&((short)0x1<<columnChosen)) {
            return columnChosen + 1;
        }
    }
    return columnChosen + 1;
}
