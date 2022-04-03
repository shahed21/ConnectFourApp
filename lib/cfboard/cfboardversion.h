/**
 * @file cfboardversion.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief this is a header for the cfboardversion.cpp file
 * @version 1.0.0
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef CFBOARDVERSION_H
#define CFBOARDVERSION_H

#include <config.h>

/**
 * @brief function declaration for cfboardversion_getLibraryName function
 * 
 * @return char* return the name of the library compiled in library memory
 */
const char* cfboardversion_getLibraryName();

/**
 * @brief function declaration for cfboardversion_getLibraryVersion function
 * 
 * @return char* return the version number of the library as a string
 */
const char* cfboardversion_getLibraryVersion();

/**
 * @brief function declaration for cfboardversion_getLibraryVersionMajor function
 * 
 * @return char* return the version major number of the library as a string
 */
const char* cfboardversion_getLibraryVersionMajor();

/**
 * @brief function declaration for cfboardversion_getLibraryVersionMinor function
 * 
 * @return char* return the version minor number of the library as a string
 */
const char* cfboardversion_getLibraryVersionMinor();

/**
 * @brief function declaration for cfboardversion_getLibraryVersionPatch function
 * 
 * @return char* return the version patch number of the library as a string
 */
const char* cfboardversion_getLibraryVersionPatch();


#endif //CFBOARDVERSION_H