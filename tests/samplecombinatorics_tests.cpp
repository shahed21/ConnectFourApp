/**
 * @file samplecombinatorics_tests.cpp
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This file provides tests for the samplecombinatorics library
 * @version 1.0.0
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <samplecombinatorics.h>
#include <gtest/gtest.h>
#include <config.h>

TEST(samplecombinatorics_tests_add, addTestNE)
{
    int a=10;
    int b=20;
    ASSERT_NE(6, samplecombinatorics_add(a,b));
}

TEST(samplecombinatorics_tests_add, addTestEQ)
{
    int a=10;
    int b=20;
    ASSERT_EQ(30, samplecombinatorics_add(a,b));
}


TEST(samplecombinatorics_tests_version, nameTest)
{
    ASSERT_STREQ(PROJECT_NAME, samplecombinatoricsversion_getLibraryName());
}

TEST(samplecombinatorics_tests_version, verTest)
{
    ASSERT_STREQ(PROJECT_VER, samplecombinatoricsversion_getLibraryVersion());
}

TEST(samplecombinatorics_tests_version, verMajorTest)
{
    ASSERT_STREQ(PROJECT_VER_MAJOR, samplecombinatoricsversion_getLibraryVersionMajor());
}

TEST(samplecombinatorics_tests_version, verMinorTest)
{
    ASSERT_STREQ(PROJECT_VER_MINOR, samplecombinatoricsversion_getLibraryVersionMinor());
}

TEST(samplecombinatorics_tests_version, verPatchTest)
{
    ASSERT_STREQ(PROJECT_VER_PATCH, samplecombinatoricsversion_getLibraryVersionPatch());
}
