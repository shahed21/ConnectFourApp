/**
 * @file sampleadderversion.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief this is a sample header for the sampleadderversion.cpp file
 * @version 1.0.0
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SAMPLEADDERVERSION_H
#define SAMPLEADDERVERSION_H

#include <config.h>

/**
 * @brief function declaration for sampleadderversion_getLibraryName function
 * 
 * @return char* return the name of the library compiled in library memory
 */
const char* sampleadderversion_getLibraryName();

/**
 * @brief function declaration for sampleadderversion_getLibraryVersion function
 * 
 * @return char* return the version number of the library as a string
 */
const char* sampleadderversion_getLibraryVersion();

/**
 * @brief function declaration for sampleadderversion_getLibraryVersionMajor function
 * 
 * @return char* return the version major number of the library as a string
 */
const char* sampleadderversion_getLibraryVersionMajor();

/**
 * @brief function declaration for sampleadderversion_getLibraryVersionMinor function
 * 
 * @return char* return the version minor number of the library as a string
 */
const char* sampleadderversion_getLibraryVersionMinor();

/**
 * @brief function declaration for sampleadderversion_getLibraryVersionPatch function
 * 
 * @return char* return the version patch number of the library as a string
 */
const char* sampleadderversion_getLibraryVersionPatch();


#endif //SAMPLEADDERVERSION_H