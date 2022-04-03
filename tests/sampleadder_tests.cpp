/**
 * @file sampleadder_tests.cpp
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This file provides tests for the sampleadder library
 * @version 1.0.0
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <sampleadder.h>
#include <gtest/gtest.h>
#include <config.h>

TEST(sampleadder_tests_add, addTestNE)
{
    int a=10;
    int b=20;
    ASSERT_NE(6, sampleadder_add(a,b));
}

TEST(sampleadder_tests_add, addTestEQ)
{
    int a=10;
    int b=20;
    ASSERT_EQ(30, sampleadder_add(a,b));
}


TEST(sampleadder_tests_version, nameTest)
{
    ASSERT_STREQ(PROJECT_NAME, sampleadderversion_getLibraryName());
}

TEST(sampleadder_tests_version, verTest)
{
    ASSERT_STREQ(PROJECT_VER, sampleadderversion_getLibraryVersion());
}

TEST(sampleadder_tests_version, verMajorTest)
{
    ASSERT_STREQ(PROJECT_VER_MAJOR, sampleadderversion_getLibraryVersionMajor());
}

TEST(sampleadder_tests_version, verMinorTest)
{
    ASSERT_STREQ(PROJECT_VER_MINOR, sampleadderversion_getLibraryVersionMinor());
}

TEST(sampleadder_tests_version, verPatchTest)
{
    ASSERT_STREQ(PROJECT_VER_PATCH, sampleadderversion_getLibraryVersionPatch());
}
