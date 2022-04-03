# The `inc` Folder
This folder has the following structure.

    .
    ├── inc                         # config include folder
    │   └── config.h.in

## The `config.h.in` File
This is the input file that CMake converts into the header file `config.h`, which holds the project name and version information.  This file should not be edited willy nilly.  Lines should definitely not be deleted from this file.  Lines, if added, should be code reviewed, thoroughly.