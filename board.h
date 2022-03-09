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

/**
 * @brief checks the validity of the board token positions. If there is an error the function returns a nonzero number.
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 * @return short returns zero if there is no errors detected in the parameters
 */
short board_checkBoardValidity(
    unsigned long long xBoard,
    unsigned long long oBoard);

/**
 * @brief displays the 7x7 board on screen given x token positions and o token positions
 * 
 * @param xBoard a 64 bit integer holding the x token positions of the board
 * @param oBoard a 64 bit integer holding the o token positions of the board
 */
void board_displayBoard(
    unsigned long long xBoard,
    unsigned long long oBoard);

#endif /*BOARD_H*/