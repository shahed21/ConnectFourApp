# The `tests` Folder
This folder holds all the tests for the modules in the project.  Ideally the tests should be written even before the submodule functions are written.

## Anatomy of a `TEST`

### Includes needed to test
Following are the includes in `sampleadder_test.cpp`.

    #include <sampleadder.h>
    #include <gtest/gtest.h>
    #include <config.h>

The first include is for the submodule being test.  The second include is for the google testing platform, which gives us the framework for testing.  The third include is the config file that holds version number to chack against.

### `TEST` function call
A `TEST` function call is shown below.

    TEST(sampleadder_tests_add, addTestNE)
    {
        int a=10;
        int b=20;
        ASSERT_NE(6, sampleadder_add(a,b));
    }

The first argument of the functino is the name of the test suite.  The second argument is the name of the test within the test suite. One test suite can have multiple tests grouped within it.

The `ASSERT` function used here is an `ASSERT_NE` which checks for inequality.  Test passes only if the two arguments are unequal.