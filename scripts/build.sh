#!/bin/bash
# This script builds the project

source include.sh

cd $BUILDDIR/
make
cd $ROOTDIR/