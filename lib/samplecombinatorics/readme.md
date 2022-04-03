# Sample Submodule `samplecombinatorics`
This is a submodule library written in C++, which demonstrates a simple adder function.  The point of this submodule is to show how a library is to be written and incorporated into the CMake platform for ease of use.

## Folder Structure
The following shows the folder structure of this subdirectory.

    ├── lib                         # Library files
    │   ├── samplecombinatorics             # Placeholder library source code folder
    │   │   ├── samplecombinatorics.cpp
    │   │   ├── samplecombinatorics.h
    │   │   ├── samplecombinatoricsversion.cpp
    │   │   ├── samplecombinatoricsversion.h
    │   │   ├── readme.md
    │   │   └── CMakeLists.txt

## Files
### `samplecombinatorics.cpp` and `samplecombinatorics.h` files
These are the library files that do what the submodule is supposed to do.  So, in this case there is only a adder function in here.  These two files represent the entire functional portion of the library.  It could theoritically be any number of files here.  But 2 is the bare minimum, as we need a header file for the API declarations and a C file for the function definitions.

### `samplecombinatoricsversion.cpp` and `samplecombinatoricsversion.h` files
These are the version header `samplecombinatoricsversion.h` and version C++ `samplecombinatoricsversion.cpp` files.  The header file imports the version information from the project config.h file.  It is hardcoded into the library memory in the C++ file.  So, once built the version numbers are permanent for the build, barring bitwise tampering of library files.  Any submodule should provide access to the five functions in these files, and these functions should be tested for in the test suite.

### `CMakeLists.txt` file
This file tells CMake how to what files are needed to build the library.  It also tells CMake how to install the built library on the system.  It also shows where the include directories are.  This file needs to be carefully edited when creating a new submobule.