#!/bin/bash
# This script configures folders for the project

full_path=$(realpath $0)

shell_path=$(dirname $full_path)

dir_path=$(dirname $shell_path)

#Set this to the root directory
ROOTDIR=$dir_path
#Set this to the source directory
SOURCEDIR=$dir_path/src/
#Set this to the build directory
BUILDDIR=$dir_path/build/
