/**
 * @file gametheory.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief It is the header file for gametheory.c
 * @version 0.1
 * @date 2022-03-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef GAMETHEORY_H
#define GAMETHEORY_H
#include "types.h"

/**
 * @brief This function is where the computer decided which column to play next
 * 
 * @param xBoard this is the token map of x
 * @param oBoard this is the token map of o
 * @param columnChosen 
 * @return short column number 0 to 6 chosen by computer
 */
short gametheory_chooseColumn(
    u64 xBoard,
    u64 oBoard,
    short columnChosen);
/*********************Public Functions Declarations************************/
#endif //GAMETHEORY_H