/**
 * @file samplecombinatoricsversion.cpp
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This file provides the function defintions that hardcode the version information for the library
 * @version 1.0.0
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "samplecombinatoricsversion.h"
const char* samplecombinatoricsversion_getLibraryName() {
    return PROJECT_NAME;
}

const char* samplecombinatoricsversion_getLibraryVersion() {
    return PROJECT_VER;
}

const char* samplecombinatoricsversion_getLibraryVersionMajor() {
    return PROJECT_VER_MAJOR;
}

const char* samplecombinatoricsversion_getLibraryVersionMinor() {
    return PROJECT_VER_MINOR;
}

const char* samplecombinatoricsversion_getLibraryVersionPatch() {
    return PROJECT_VER_PATCH;
}

