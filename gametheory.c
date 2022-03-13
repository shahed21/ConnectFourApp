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

/*********************Private Function Declarations***********************/
/**
 * @brief this function picks the instant victory
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @return short returns the column number 1-7 for victory, or 0 if there is not instant victory
 */
short chooseInstantVictory(
    uint64 xBoard,
    uint64 oBoard);


/*********************Private Functions Definitions***********************/
short chooseInstantVictory(
    uint64 xBoard,
    uint64 oBoard
) {
    for (short columnChosen=0; columnChosen<MAX_COLS; columnChosen++) {
        uint64 xBoardTemp = xBoard;
        uint64 oBoardTemp = oBoard;

        board_placeToken(&xBoardTemp,&oBoardTemp,columnChosen,COMPUTER_PLAYS);
        if (board_checkVictoryMatch(oBoardTemp)) {
            return columnChosen+1;
        }
    }
    return 0;
}

/*********************Public Functions Definitions************************/
short gametheory_chooseColumn(
    uint64 xBoard,
    uint64 oBoard,
    short columnChosen
) {
    short columnFound = chooseInstantVictory(xBoard, oBoard);
    if (columnFound) {
        return columnFound;  //Instant Victory
    }
    return columnChosen + 1;
}


#include <stdio.h>
#include <stdbool.h>
