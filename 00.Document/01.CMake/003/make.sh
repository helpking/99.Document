#!/bin/bash 
cmake .

#Complie
make

# Clean
rm -f ./CMakeCache.txt
rm -rf ./CMakeFiles/
rm -f ./Makefile
rm -f ./cmake_install.cmake

