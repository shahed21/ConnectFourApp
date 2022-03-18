/**
 * @file main.c
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This is the main file for the connect four application
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdbool.h>

#include "board.h"
#include "gametheory.h"
#include "types.h"

#define WHO_STARTS (HUMAN_PLAYS)

/**
 * @brief returns the column number chosen by player or computer
 * 
 * @param xBoard this is the token map of x
 * @param oBoard this is the token map of o
 * @param whoPlays 1->human, 0-> computer
 * @return short column number 0 to 6 chosen by player or computer
 */
short main_getTokenColumn(uint64 xBoard, uint64 oBoard, short whoPlays) {
    short columnChosen=0;
    bool validColumn = false;
    
    if (whoPlays) { //Human Plays
        printf("It's your turn to play.%s", _NEWLINE);

        while ((columnChosen<1)||(columnChosen>7)||(!validColumn)) {
            printf("Please enter a column number from 1 to 7 to place your token x.%s", _NEWLINE);
            scanf("%hd", &columnChosen); //has to be 1-7

            validColumn = board_validColumnForEntry(xBoard,oBoard, (columnChosen-1)); //1-7 is decremented to 0-6
            if (!validColumn) {
                printf("You entered a column that is not valid for entry.  Try another.%s", _NEWLINE);
            }
        }

        printf("You chose column %d to place your token x.%s", columnChosen, _NEWLINE);
    } else { //AI pLays
        printf("It's my turn to play.%s", _NEWLINE);
        while ((columnChosen<1)||(columnChosen>7)||(!validColumn)) {
            columnChosen = gametheory_chooseColumn(xBoard, oBoard, columnChosen);
            //columnChosen++;  //TODO this is where AI goes
            validColumn = board_validColumnForEntry(xBoard,oBoard, (columnChosen-1)); //1-7 is decremented to 0-6
        }
    }
    return columnChosen-1;
}

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int main(int argc, char **argv) {
    uint64 xBoard=0, oBoard=0;
    bool victoryMatched = false;
    bool boardFull = false;
    short whoPlays = WHO_STARTS;
    short columnChosen = 0;
    char victoryString[2][16] = {
        "You won.",
        "I won."
    };

    printf("Let's play a game of Connect Four. You play with 'x', I play with 'o'.\n");

    //xBoard=0x0000000004081020;
    //oBoard=0x0000000004040404;
    if (board_displayBoard(xBoard, oBoard)){
        while ((!victoryMatched)&&(!boardFull)) {
            victoryMatched = board_checkVictoryMatch((whoPlays)?(oBoard):(xBoard));
            if (victoryMatched) {
                printf("%s%s", victoryString[whoPlays], _NEWLINE);
            } else {
                boardFull = board_checkBoardFull(xBoard, oBoard);
                if (boardFull) {
                    printf("Board is full, nobody won.  Thank you for playing.%s", _NEWLINE);
                } else {
                    columnChosen = main_getTokenColumn(xBoard, oBoard, whoPlays);
                    board_placeToken(&xBoard,&oBoard,columnChosen,whoPlays);
                    board_displayBoard(xBoard, oBoard);
                }
            }
            whoPlays=!whoPlays;
        }
    }
    printf("Goodbye!%s", _NEWLINE);
    return 0;
}