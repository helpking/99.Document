#!/bin/bash 

CUR_DIR=`pwd`
WORK_DIR=""
CMAKE_PREFIX_PATH=""
CLEANUP=0
IS_TEST=0
BIN_DIR="./bin"

if [[ $# -lt 1 ]];then
    echo "Command Format:`basename $0` -d dir [-m cmake prefix path] [-c cleanup] [-t test flag]"
    exit 1
fi

while getopts d:m:ct opt; do  
case $opt in   
	d)  
		WORK_DIR=$OPTARG
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

if [ ! -d "$WORK_DIR" ]; then 
	echo "the direct is not exist!![Dir=$WORK_DIR]"
	exit 2
fi

cd ${WORK_DIR}
mkdir ${BIN_DIR}

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
  rm -rf ${BIN_DIR}
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
