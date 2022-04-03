/**
 * @file cfboard_tests.cpp
 * @author Shahed Rahim (shahed21@gmail.com)
 * @brief This file provides tests for the cfboard library
 * @version 1.0.0
 * @date 2022-04-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <cfboard.h>
#include <gtest/gtest.h>
#include <config.h>


TEST(cfboard_tests_version, nameTest)
{
    ASSERT_STREQ(PROJECT_NAME, cfboardversion_getLibraryName());
}

TEST(cfboard_tests_version, verTest)
{
    ASSERT_STREQ(PROJECT_VER, cfboardversion_getLibraryVersion());
}

TEST(cfboard_tests_version, verMajorTest)
{
    ASSERT_STREQ(PROJECT_VER_MAJOR, cfboardversion_getLibraryVersionMajor());
}

TEST(cfboard_tests_version, verMinorTest)
{
    ASSERT_STREQ(PROJECT_VER_MINOR, cfboardversion_getLibraryVersionMinor());
}

TEST(cfboard_tests_version, verPatchTest)
{
    ASSERT_STREQ(PROJECT_VER_PATCH, cfboardversion_getLibraryVersionPatch());
}
