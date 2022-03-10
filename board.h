/**
 * @file board.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This is the header file for the board.c file
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BOARD_H
#define BOARD_H


#define MAX_ROWS 7
#define MAX_COLS 7

//#define BOARD_DISPLAY_BUFFER 256

#include <stdbool.h>

/**
 * @brief checks the validity of the board token positions. If there is an error the function returns a false.
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @return bool returns true if there is no errors detected in the parameters
 */
bool board_checkBoardValidity(
    unsigned long long xBoard,
    unsigned long long oBoard);

/**
 * @brief displays the 7x7 board on screen given x token positions and o token positions.
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @return bool returns true is there were no issues displaying the board, false if there was an error
 */
bool board_displayBoard(
    unsigned long long xBoard,
    unsigned long long oBoard);

/**
 * @brief checks if there is a victory match on the board
 * 
 * @param board this is the board of one token only
 * @return true if there is a victory match
 * @return false if there is no victory match
 */
bool board_checkVictoryMatch(
    unsigned long long board);

/**
 * @brief 
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @param columnChosen a number between 0 to 6
 * @return true if number is valid
 * @return false if number is invalid
 */
bool board_validColumnForEntry(
    unsigned long long xBoard,
    unsigned long long oBoard,
    short columnChosen);

/**
 * @brief places a token on top of the columnChosen
 * 
 * @param xBoard a 64 bit integer ptr holding the x token positions of the board
 * @param oBoard a 64 bit integer ptr holding the o token positions of the board
 * @param columnChosen a number between 0 to 6
 * @param whoPlays 1 for x; 0 for o
 */

void board_placeToken(
    unsigned long long *xBoard,
    unsigned long long *oBoard,
    short columnChosen,
    short whoPlays);
#endif /*BOARD_H*/