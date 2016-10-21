#!/bin/bash 

CUR_DIR=`pwd`
DIR=""
CMAKE_PREFIX_PATH=""
CLEANUP=0
IS_TEST=0

if [[ $# -lt 1 ]];then
    echo "Command Format:`basename $0` -d dir [-m cmake prefix path] [-c cleanup] [-t test flag]"
    exit 1
fi

while getopts d:m:ct opt; do  
case $opt in   
	d)  
		DIR=$OPTARG
		;; 
    m)
        CMAKE_PREFIX_PATH=$OPTARG
        ;;
    c)
        CLEANUP=1
        ;;
    t)
        IS_TEST=1
        ;;
	*)  
		;;  
esac  
done  

if [ ! -d "$DIR" ]; then 
	echo "the direct is not exist!![Dir=$DIR]"
	exit 2
fi

cd $DIR

if [ -f "./make.sh" ]; then
  sh ./make.sh
else
  if [ -z "${CMAKE_PREFIX_PATH}" ]; then
    cmake .
  else
    cmake . -DCMAKE_PREFIX_PATH=${CMAKE_PREFIX_PATH}
  fi
fi

#Complie
make

# Clean
if [ "${IS_TEST}" == "1" ]; then
  rm -rf ./bin/
  rm -f ./CMakeCache.txt
  rm -rf ./CMakeFiles/
  rm -f ./Makefile
  rm -f ./cmake_install.cmake
else
  if [ "${CLEANUP}" == "1" ]; then
    rm -f ./CMakeCache.txt
    rm -rf ./CMakeFiles/
    rm -f ./Makefile
    rm -f ./cmake_install.cmake
  fi
fi

cd $CUR_DIR
