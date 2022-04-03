# The `lib` Folder
This folder holds the submodules / libraries that are dependencies in the project.  The `lib` folder has the following structure.

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

## The `CMakeLists.txt` File
The code below shows how subdirectories are added for each additional submodule.

    if(ENABLE_SAMPLE_BUILD)
        if(ENABLE_SAMPLE_ADDER_BUILD)
            add_subdirectory(sampleadder)
        endif()
        if(ENABLE_SAMPLE_COMBINATORICS_BUILD)
            add_subdirectory(samplecombinatorics)
        endif()
    endif()

Each submodule/library should have its own subdirectory.

If the submodule/library is a sample submodule/library, then its `add_subdirectory` command should be bounded in the `if(ENABLE_SAMPLE_BUILD)` loop.

Whether the submodule is a sample library or not, it should have its own build option, and its `add_subdirectory` command should be bounded by its enable build option if loop.  For example, check out the `if(ENABLE_SAMPLE_ADDER_BUILD)` and the `if(ENABLE_SAMPLE_COMBINATORICS_BUILD)` loops.