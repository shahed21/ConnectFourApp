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
#include "env.h"

#define COMPUTER_PLAYS (0)
#define HUMAN_PLAYS (1)
#define WHO_STARTS (HUMAN_PLAYS)

/**
 * @brief gets a column number from the AI
 * 
 * @param xBoard this is the token map of x
 * @param oBoard this is the token map of o
 * @return short column number 1 to 7 chosen by computer
 */
short main_letAIPlay(unsigned long long xBoard, unsigned long long oBoard) {
    short columnChosen=0;
    printf("It's my turn to play.%s", _NEWLINE);
    columnChosen= 1;  //TODO this is where AI goes
    return columnChosen-1;
}


/**
 * @brief Reads a column number from console, makes sure it is valid and returns it as a short
 * 
 * @param xBoard this is the token map of x
 * @param oBoard this is the token map of o
 * @return short column number 1 to 7 chosen by human
 */
short main_letHumanPlay(unsigned long long xBoard, unsigned long long oBoard) {
    short columnChosen=0;
    bool validColumn = false;
    
    printf("It's your turn to play.%s", _NEWLINE);

    while ((columnChosen<1)||(columnChosen>7)||(!validColumn)) {
        printf("Please enter a column number from 1 to 7 to place your token x.%s", _NEWLINE);
        scanf("%d", &columnChosen); //has to be 1-7

        validColumn = board_validColumnForEntry(xBoard,oBoard, (columnChosen-1)); //1-7 is decremented to 0-6
        if (!validColumn) {
            printf("You entered a column that is not valid for entry.  Try another.%s", _NEWLINE);
        }
    }

    printf("You chose column %d to place your token x.%s", columnChosen, _NEWLINE);

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
    unsigned long long xBoard=0, oBoard=0;
    bool victoryMatched = false;
    short whoPlays = WHO_STARTS;
    short columnChosen = 0;

    printf("Let's play a game of Connect Four. You play with 'x', I play with 'o'.\n");

    //xBoard=0x0000000004081020;
    //oBoard=0x0000000004040404;
    if (board_displayBoard(xBoard, oBoard)){
        while (!victoryMatched) {
            if (whoPlays==(HUMAN_PLAYS)) {
                victoryMatched = board_checkVictoryMatch(oBoard);
                if (victoryMatched) {
                    printf("I won.%s", _NEWLINE);
                } else {
                    columnChosen = main_letHumanPlay(xBoard, oBoard);
                    board_placeToken(&xBoard,&oBoard,columnChosen,whoPlays);
                    board_displayBoard(xBoard, oBoard);
                }
            } else {
                victoryMatched = board_checkVictoryMatch(xBoard);
                if (victoryMatched) {
                    printf("You won.%s", _NEWLINE);
                } else {
                    columnChosen = main_letAIPlay(xBoard, oBoard);
                    board_placeToken(&xBoard,&oBoard,columnChosen,whoPlays);
                    board_displayBoard(xBoard, oBoard);
                }
            }
            whoPlays=!whoPlays;
        }
    }
    printf("Goodbye!%s", _NEWLINE);
}