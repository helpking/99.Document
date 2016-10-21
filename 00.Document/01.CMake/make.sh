#!/bin/bash 

# カレントディレクトリー
CUR_DIR=`pwd`
# 該当ディレクトリー
WORK_DIR=""
# CMake
CMAKE_PREFIX_PATH=""
# クリアフラグ（コンパイル後で、ソース、かつ、バイナリーターゲットファイル以外、全部削除）
CLEANUP=0
# テストフラグ（コンパイル後で、ソース以外、全部削除）
IS_TEST=0
# ターゲットバイナリーディレクトリー
TARGET_BIN_DIR="./bin"
#CMakeディレクトリー
CMAKE_DIR=""
#CMakelistsファイル
CUR_CMAKE_LISTS_FILE_NAME="CMakeLists.txt"
CMAKE_LISTS_FILE="${CMAKE_DIR}/${CUR_CMAKE_LISTS_FILE_NAME}"
CUR_CMAKE_LISTS_FILE_PATH="./${CUR_CMAKE_LISTS_FILE}"

if [[ $# -lt 1 ]];then
    echo "Command Format:`basename $0` -d dir [-m cmake prefix path] [-c cleanup] [-t test flag]"
    exit 1
fi

while getopts d:m:ct opt; do  
case $opt in   
	d)  
		WORK_DIR=$OPTARG
        CMAKE_DIR="${WORK_DIR}/cmake"
        CMAKE_LISTS_FILE="${CMAKE_DIR}/${CUR_CMAKE_LISTS_FILE_NAME}" 
        CUR_CMAKE_LISTS_FILE_PATH="${WORK_DIR}/${CUR_CMAKE_LISTS_FILE_NAME}"
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

if [ ! -d "${WORK_DIR}" ]; then 
	echo "the direct is not exist!![Dir=$WORK_DIR]"
	exit 2
fi

if [ ! -d "${CMAKE_DIR}" ]; then 
	echo "the direct is not exist!![Dir=$CMAKE_DIR]"
	exit 2
fi

if [ ! -f "${CMAKE_LISTS_FILE}" ]; then 
	echo "the file is not exist!![file=$CMAKE_LISTS_FILE]"
	exit 3
fi
#
cp -fp ${CMAKE_LISTS_FILE} ${CUR_CMAKE_LISTS_FILE_PATH}

cd ${WORK_DIR}
if [ ! -d "${TARGET_BIN_DIR}" ]; then 
  mkdir ${TARGET_BIN_DIR}
fi

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
  rm -rf ${TARGET_BIN_DIR}
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

# CMakelistsファイルを削除する
if [ -f "${CUR_CMAKE_LISTS_FILE_PATH}" ]; then 
  rm -f ${CUR_CMAKE_LISTS_FILE_PATH}
fi