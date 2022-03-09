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
#include "board.h"

int main(int argc, char **argv) {
    printf("Let's play a game of Connect Four\n");

    unsigned long long xBoard=0, oBoard=0;
    //xBoard=0x0000000004081020;
    //oBoard=0x0000000004040404;
    board_displayBoard(xBoard, oBoard);
}