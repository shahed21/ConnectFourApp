/**
 * @file types.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief Holds the typedefs for different data types
 * @version 0.1
 * @date 2022-03-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef TYPES_H
#define TYPES_H

#include "env.h"

#if (_OS==(WINDOWS))
typedef unsigned long long u64;
typedef long long i64;

typedef unsigned int u32;
typedef int i32;

typedef unsigned short u16;
typedef short i16;

typedef unsigned char u8;
typedef char i8;


#elif ((_OS==(UNIX))||(_OS==(LINUX))||(_OS==(OSX)))
typedef unsigned long u64;
typedef long i64;

typedef unsigned int u32;
typedef int i32;

typedef unsigned short u16;
typedef short i16;

typedef unsigned char u8;
typedef char i8;


#endif //(_OS)
#endif //TYPES_H