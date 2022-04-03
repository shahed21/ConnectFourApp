# CMake Bare Bones
This project is a bare bones project to start a new C project in CMake.

## File and Folder Organization Structure
The following folder structure is available for your use.

    .
    ├── lib                         # Library files
    │   ├── sampleadder             # Placeholder library source code folder
    │   │   ├── sampleadder.cpp
    │   │   ├── sampleadder.h
    │   │   ├── sampleadderversion.cpp
    │   │   ├── sampleadderversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt
    │   ├── samplecombinatorics     # Another placeholder library source code folder
    │   │   ├── samplecombinatorics.cpp
    │   │   ├── samplecombinatorics.h
    │   │   ├── samplecombinatoricsversion.cpp
    │   │   ├── samplecombinatoricsversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt
    │   ├── readme.md
    │   └── CMakeLists.txt
    ├── scripts                     # Tools and shell scripts
    │   ├── include.sh
    │   ├── install.sh
    │   ├── configure.sh
    │   ├── build.sh
    │   ├── readme.md
    │   └── execute.sh
    ├── tests                       # Automated tests
    │   ├── sampleadder_tests.cpp
    │   ├── samplecombinatorics_tests.cpp
    │   ├── readme.md
    │   └── CMakeLists.txt
    ├── inc                         # config include folder
    │   ├── readme.md
    │   └── config.h.in
    ├── .gitignore
    ├── CMakeLists.txt
    ├── TODO.txt
    └── readme.md

The following top level folder structure is generated after code is compiled.

    .
    ├── build                       # Compiled files
    ├── lib                         # Library files
    ├── scripts                     # Tools and utilities
    ├── inc                         # Config include folder
    ├── tests                       # Automated tests
    ├── .gitignore
    ├── CMakeLists.txt
    └── readme.md

## Commands
### Configure CMake
The following command, run in the `scripts/` folder, can be used to configure CMake for the entire project.

    ./configure.sh

### Build Code
The following command, run in the `scripts/` folder, can be used to build executable for the entire project.

    ./build.sh

### Execute Code
The following command, run in the `scripts/` folder, can be used to execute the executable for the project.

    ./execute.sh

### Run Tests
The following command, run in the `scripts/` folder, can be used to run tests to validate the project.

    ./runtests.sh

### Install Build
The following command, run in the `scripts/` folder, can be used to install the project built executable and libraries to system accessible folders.  One needs system administrator access to run this command successfully.

    ./install.sh


## What to change for your project
The following items have to be changed to port this for a new project, or an existing one.

### Project Name and Version Number
The project name needs to be renamed.  It has to be done in the `./CMakeLists.txt` file. `SampleExeWithLib` should be replaced with the new project / project executable name.  This is also where the version number is to be updated.  This version number gets hardcoded into the library memory for better library version control.

    project(SampleExeWithLib 
        VERSION 0.1.0
        LANGUAGES C CXX
    )

### Git Init
Old Git has to be removed. Git has to be reinitialized with new Project Name.  `./.git/config` file is shown below.  The url should be updated to point to the new project remote repository.

    [core]
        repositoryformatversion = 0
        filemode = true
        bare = false
        logallrefupdates = true
    [remote "origin"]
        url = git@github.com:shahed21/CMakeBB.git
        fetch = +refs/heads/*:refs/remotes/origin/*
    [branch "master"]
        remote = origin
        merge = refs/heads/master


### Libraries
The `sampleadder` library and the `samplecombinatorics` library show how libraries are organized in this project.  If this form is maintained new projects can be written as libraries and used in executables and tests.  All one has to do to adapt this is to add a new library and turn off the options to build the sample libraries.  This is covered in more detail in the next section titled `How to Add New Libraries`.

### Tests
Whenever a new library is added, it should accompany corresponding self tests written in the `./tests` folder.  The files `./tests/sampleadder_tests.cpp` and `./tests/samplecombinatorics_tests.cpp` provide good examples on how to proceed writing more such tests.

### CMakeLists.txt FIles
And finally these cmake configuration files are definitely going to need some modifications to allow for any change.  More on this is covered in `How to Add New Libraries`.

## How to Add New Libraries
In this section we are going to cover the step by step approach to adding a new library to this CMake framework.  We are going to cover how we added `samplecombinatorics` library to the project which already had `sampleadder` library in it.

### CMake Option Flags
We can start by creating option flags for the new library we are about to create.  Some examples of this can be seen in `./CMakeLists.txt` as shown below.

    option(ENABLE_SAMPLE_BUILD "Sample Libraries Enabled." ON)
    option(ENABLE_SAMPLE_ADDER_BUILD "Sample Adder Libraries Enabled." ON)

The first one is to turn on and off all Sample Libraries that are in the framework.  The second one is to enable `sampleadder` library.  We add the option to enable `samplecombinatorics` to the project in the next line of code.

    option(ENABLE_SAMPLE_COMBINATORICS_BUILD "Sample Combinatorics Libraries Enabled." ON)

### Changes to the script `./scripts/configure.sh`

They can be turned ON or OFF from the shell script `./scripts/configure.sh` as shown below.

    cmake -S $ROOTDIR -B $BUILDDIR -DENABLE_SAMPLE_BUILD=ON -DENABLE_SAMPLE_ADDER_BUILD=ON

This can be modified to add the switch we just created as shown below.

    cmake -S $ROOTDIR -B $BUILDDIR -DENABLE_SAMPLE_BUILD=ON -DENABLE_SAMPLE_ADDER_BUILD=ON -DENABLE_SAMPLE_COMBINATORICS_BUILD=ON

Here, all three options are enabled, which will build both the sample libraries.

### Include and Link Paths
Then we use the options we just created to configure the paths for the library we are about to create.  This is done in `./CMakeLists.txt` as shown below.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            list(APPEND SAMPLE_INC_DIRS lib/sampleadder/)
            list(APPEND SAMPLE_LINK_DIRS lib/sampleadder/)
            list(APPEND SAMPLE_LINK_LIBS sampleadder)
            list(APPEND TEST_EXECUTABLES tests/sampleadder_tests.cpp)
        endif()
    endif()

Since `samplecombinatorics` library is also a sample library we can put this in the `ENABLE_SAMPLE_BUILD` if loop, as shown below.

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

It is important to understand the different lists that are being used here. `SAMPLE_INC_DIRS` is where the library `.h` files are kept.  These should be `PUBLIC`.  `SAMPLE_LINK_DIRS` is where the library code is kept.  These are `PRIVATE` to the library.  `SAMPLE_LINK_LIBS` are libraries that are linked to executable target after compilation is done.  `TEST_EXECUTABLES` are the files that have the google test code to test the library.

When making a new library, it might be prudent to keep this code block for the new library outside the `ENABLE_SAMPLE_BUILD` if loop.

### Changes to the `lib` Folder
The `lib` folder used to look like the following.

    .
    ├── lib                         # Library files
    │   ├── sampleadder             # Placeholder library source code folder
    │   │   ├── sampleadder.cpp
    │   │   ├── sampleadder.h
    │   │   ├── sampleadderversion.cpp
    │   │   ├── sampleadderversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt
    │   ├── readme.md
    │   └── CMakeLists.txt

But to add `samplecombinatorics` library we have to add the following files to the structure.

    .
    ├── lib                         # Library files
    │   ├── sampleadder             # Placeholder library source code folder
    │   │   ├── sampleadder.cpp
    │   │   ├── sampleadder.h
    │   │   ├── sampleadderversion.cpp
    │   │   ├── sampleadderversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt
    │   ├── samplecombinatorics     # Another placeholder library source code folder
    │   │   ├── samplecombinatorics.cpp
    │   │   ├── samplecombinatorics.h
    │   │   ├── samplecombinatoricsversion.cpp
    │   │   ├── samplecombinatoricsversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt
    │   ├── readme.md
    │   └── CMakeLists.txt

The `./lib/CMakeLists.txt` had the following code for `sampleadder` folder to be added.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            add_subdirectory(sampleadder)
        endif()
    endif()

To add the `samplecombinatorics` subdirectory, the following code was added inside the `ENABLE_SAMPLE_BUILD` if loop.

    if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
        add_subdirectory(samplecombinatorics)
    endif()

The `./lib/CMakeLists.txt` code looks like the following.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            add_subdirectory(sampleadder)
        endif()
        if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
            add_subdirectory(samplecombinatorics)
        endif()
    endif()

For libraries that are not samples, they are better off being kept outside the `ENABLE_SAMPLE_BUILD` if loop.

### Create the subdirectory `./lib/samplecombinatorics/`

Create the subdirectory `./lib/samplecombinatorics/` for the library `samplecombinatorics`.  Create `./lib/samplecombinatorics/CMakeLists.txt` file with the following code.  Again, if the new library isn't a smaple library, then remove the `ENABLE_SAMPLE_BUILD` if loop.

    cmake_minimum_required(VERSION 3.16.3)

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
            add_library(samplecombinatorics samplecombinatorics.cpp)
            target_include_directories(samplecombinatorics
                PUBLIC "${PROJECT_BINARY_DIR}/inc/"
            )
        endif()
    endif()

Put the `samplecombinatorics` library source and header files in `./lib/samplecombinatorics/` subdirectory.

### Tests
The `tests` folder already had the tests for `sampleadder` in the file `sampleadder_tests.cpp`.  We have to create the tests for the `samplecombinatorics` in the file called `./tests/samplecombinatorics_tests.cpp`.

## Installation
Installation of released software allows the executables, libraries and header files to be accessible system wide on the computer by the user.  In this section below we explain how CMake is used to install this project and its dependencies onto the system.

### CMake Options
Three CMake options were added for installation purposes.  They are listed and explained below.

    option(ENABLE_SAMPLE_ADDER_INSTALL "Sample Adder Library Install Enabled." ON)
    option(ENABLE_SAMPLE_COMBINATORICS_INSTALL "Sample Combinatorics Library Install Enabled." ON)
    option(ENABLE_PROJECT_INSTALL "Project Install Enabled." ON)

The first two are used for installing the libraries.  The last one is used to install project executables.  These are defined in `./CMakeLists.txt`.

### Library Install Commands
We are just going to show `sampleadder` installation changes, as `samplecombinatorics` has very similar changes.  The `./lib/sampleadder/CMakeLists.txt` before the update looked like this.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            add_library(sampleadder sampleadder.cpp sampleadderversion.cpp)
            target_include_directories(sampleadder
                PUBLIC "${PROJECT_BINARY_DIR}/inc/"
            )
        endif()
    endif()


After the installation changes for `sampleadder` library, the `./lib/sampleadder/CMakeLists.txt` file looks as follows.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            add_library(sampleadder sampleadder.cpp sampleadderversion.cpp)
            target_include_directories(sampleadder
                PUBLIC "${PROJECT_BINARY_DIR}/inc/"
            )
            if(ENABLE_SAMPLE_ADDER_INSTALL)
                install(TARGETS sampleadder
                    DESTINATION lib)
                install(FILES sampleadder.h sampleadderversion.h
                    DESTINATION include)
            endif()
        endif()
    endif()

The change is in the code snippet that was added as below.

            if(ENABLE_SAMPLE_ADDER_INSTALL)
                install(TARGETS sampleadder
                    DESTINATION lib)
                install(FILES sampleadder.h sampleadderversion.h
                    DESTINATION include)
            endif()

The first `install` command prepares cmake to copy the library files to the system `lib` folder.  The second `install` command prepares cmake to copy the library header include files to the system `include` folder.

As mentioned earlier, similar changes can be seen for `samplecombinatorics` library.

### Runtime Executable Install Commands
In the `./CMakeLists.txt`, after the `target_link_libraries` command, the following code was added for installation purposes.

    if(ENABLE_PROJECT_INSTALL)
        install(TARGETS ${PROJECT_NAME}
            DESTINATION bin)
        install(FILES "${PROJECT_BINARY_DIR}/inc/config.h"
            DESTINATION include)

    endif()

This code is activated only when the `ENABLE_PROJECT_INSTALL` option is turned on.  The first `install` command prepares cmake to copy the executable with the project name to the system `bin` folder.  The second `install` command prepares cmake to copy the `config.h` file to the system `include` folder.

### Script Change in `./scripts/configure.sh`
The script had the following CMake command.

    cmake -S $ROOTDIR -B $BUILDDIR -DENABLE_SAMPLE_BUILD=ON -DENABLE_SAMPLE_ADDER_BUILD=ON -DENABLE_SAMPLE_COMBINATORICS_BUILD=ON

It got updated to turn the install options `ON` as follows.

    cmake -S $ROOTDIR -B $BUILDDIR -DENABLE_SAMPLE_BUILD=ON -DENABLE_SAMPLE_ADDER_BUILD=ON -DENABLE_SAMPLE_COMBINATORICS_BUILD=ON -DENABLE_SAMPLE_ADDER_INSTALL=ON -DENABLE_SAMPLE_COMBINATORICS_INSTALL=ON -DENABLE_PROJECT_INSTALL=ON

### Final Installation with `./scripts/install.sh`
The `./scripts/build.sh` command only builds the project.  But, once the build process is complete, it leaves `cmake_install.cmake` folders where installation code was found.  These files are activated by `cmake -P` command.  This command is added in a new file called `./scripts/install.sh`, which is shown below.

    #!/bin/bash
    # This script installs the project

    source include.sh

    cd $BUILDDIR/
    sudo cmake -P cmake_install.cmake
    cd $ROOTDIR/

The `sudo` is needed as this command accesses folders which require root permissions.  So, only a system administrator can run this command.