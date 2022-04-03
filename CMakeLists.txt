cmake_minimum_required(VERSION 3.16.3)
project(SampleExeWithLib 
    VERSION 1.0.0
    LANGUAGES C CXX
)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

configure_file(
    inc/config.h.in 
    inc/config.h
)


include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.11.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

# CMake options
## Sample Library CMake options
option(ENABLE_SAMPLE_BUILD "Sample Libraries Enabled." ON)
option(ENABLE_SAMPLE_ADDER_BUILD "Sample Adder Library Build Enabled." ON)
option(ENABLE_SAMPLE_ADDER_INSTALL "Sample Adder Library Install Enabled." ON)
option(ENABLE_SAMPLE_COMBINATORICS_BUILD "Sample Combinatorics Library Build Enabled." ON)
option(ENABLE_SAMPLE_COMBINATORICS_INSTALL "Sample Combinatorics Library Install Enabled." ON)

## Project Cmake Options 
option(ENABLE_PROJECT_INSTALL "Project Install Enabled." ON)


if(ENABLE_SAMPLE_BUILD)
    if(ENABLE_SAMPLE_ADDER_BUILD)
        list(APPEND SAMPLE_INC_DIRS lib/sampleadder/)
        list(APPEND SAMPLE_LINK_DIRS lib/sampleadder/)
        list(APPEND SAMPLE_LINK_LIBS sampleadder)
        list(APPEND TEST_EXECUTABLES tests/sampleadder_tests.cpp)
    endif()
    if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
        list(APPEND SAMPLE_INC_DIRS lib/samplecombinatorics/)
        list(APPEND SAMPLE_LINK_DIRS lib/samplecombinatorics/)
        list(APPEND SAMPLE_LINK_LIBS samplecombinatorics)
        list(APPEND TEST_EXECUTABLES tests/samplecombinatorics_tests.cpp)
    endif()
endif()

if(TEST_EXECUTABLES)
    add_executable(${PROJECT_NAME}
        ${TEST_EXECUTABLES}
    )

    add_subdirectory(lib)

    target_include_directories(${PROJECT_NAME} 
        PUBLIC "${PROJECT_BINARY_DIR}/inc/"
        ${SAMPLE_INC_DIRS}
    )

    target_link_directories(${PROJECT_NAME} 
    #    PRIVATE lib/sampleadder
        PRIVATE ${SAMPLE_LINK_DIRS}
    )

    target_link_libraries(${PROJECT_NAME}
    #    sampleadder
        ${SAMPLE_LINK_LIBS}
        gtest_main
    )

    if(ENABLE_PROJECT_INSTALL)
        install(TARGETS ${PROJECT_NAME}
            DESTINATION bin)
        install(FILES "${PROJECT_BINARY_DIR}/inc/config.h"
            DESTINATION include)

    endif()

    include(GoogleTest)
    gtest_discover_tests(${PROJECT_NAME})
else()
    message("No tests found.  Test executable was not built.")
endif()