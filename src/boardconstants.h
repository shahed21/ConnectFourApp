/**
 * @file boardconstants.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This is the header file for boardconstants.c
 * @version 0.1
 * @date 2022-03-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef BOARDCONSTANTS_H
#define BOARDCONSTANTS_H

#include "types.h"

#define BOARDCONSTANTS_VICTORYMASKLENGTH (88)
#define BOARDCONSTANTS_MAXROWS (7)
#define BOARDCONSTANTS_MAXCOLS (7)

extern u64 boardConstants_victoryMasks[BOARDCONSTANTS_VICTORYMASKLENGTH];
extern u64 boardConstants_rowMasks[BOARDCONSTANTS_MAXROWS];
extern u64 boardConstants_rowCols[BOARDCONSTANTS_MAXCOLS];

#endif /*BOARDCONSTANTS_H*/