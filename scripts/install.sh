#!/bin/bash
# This script installs the project

source include.sh

cd $BUILDDIR/
sudo cmake -P cmake_install.cmake
cd $ROOTDIR/