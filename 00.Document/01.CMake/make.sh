#!/bin/bash 

CUR_DIR=`pwd`
DIR=""
CMAKE_PREFIX_PATH=""
CLEANUP=1

if [[ $# -lt 1 ]];then
    echo "Command Format:`basename $0` -d dir [-m cmake prefix path] [-c cleanup]"
    exit 1
fi

while getopts d:m:c: opt; do  
case $opt in   
	d)  
		DIR=$OPTARG
		;; 
        m)
                CMAKE_PREFIX_PATH=$OPTARG
                ;;
        c)
                CLEANUP=$OPTARG
                ;;
	*)  
		;;  
esac  
done  

if [ ! -d $DIR ]; then 
	echo "the direct is not exist!![Dir=$DIR]"
	exit 2
fi

cd $DIR

if [ ${CMAKE_PREFIX_PATH} == "" ]; then
  cmake .
else
  cmake . -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
fi

#Complie
make

# Clean
if [ ${CLEANUP} == "1" ]; then
  rm -f ./CMakeCache.txt
  rm -rf ./CMakeFiles/
  rm -f ./Makefile
  rm -f ./cmake_install.cmake
fi

cd $CUR_DIR
