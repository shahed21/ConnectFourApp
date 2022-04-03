/**
 * @file samplecombinatoricsversion.h
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief this is a sample header for the samplecombinatoricsversion.cpp file
 * @version 1.0.0
 * @date 2022-03-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef SAMPLECOMBINATORICSVERSION_H
#define SAMPLECOMBINATORICSVERSION_H

#include <config.h>

/**
 * @brief function declaration for samplecombinatoricsversion_getLibraryName function
 * 
 * @return char* return the name of the library compiled in library memory
 */
const char* samplecombinatoricsversion_getLibraryName();

/**
 * @brief function declaration for samplecombinatoricsversion_getLibraryVersion function
 * 
 * @return char* return the version number of the library as a string
 */
const char* samplecombinatoricsversion_getLibraryVersion();

/**
 * @brief function declaration for samplecombinatoricsversion_getLibraryVersionMajor function
 * 
 * @return char* return the version major number of the library as a string
 */
const char* samplecombinatoricsversion_getLibraryVersionMajor();

/**
 * @brief function declaration for samplecombinatoricsversion_getLibraryVersionMinor function
 * 
 * @return char* return the version minor number of the library as a string
 */
const char* samplecombinatoricsversion_getLibraryVersionMinor();

/**
 * @brief function declaration for samplecombinatoricsversion_getLibraryVersionPatch function
 * 
 * @return char* return the version patch number of the library as a string
 */
const char* samplecombinatoricsversion_getLibraryVersionPatch();


#endif //SAMPLECOMBINATORICSVERSION_H