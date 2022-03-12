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


/*********************Private Functions Definitions***********************/

/*********************Public Functions Definitions************************/
short gametheory_chooseColumn(
    uint64 xBoard,
    uint64 oBoard,
    short columnChosen
) {
    return columnChosen + 1;
}


#include <stdio.h>
#include <stdbool.h>
