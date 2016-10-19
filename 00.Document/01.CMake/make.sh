#!/bin/bash 

CMD=$0
DIR=""

if [[ $# -lt 1 ]];then
    echo "Command Format:`basename $0` [-d dir]"
    exit 1
fi

while getopts d: opt; do  
case $opt in   
	d)  
		DIR=$OPTARG
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

cmake .

#Complie
make

# Clean
rm -f ./CMakeCache.txt
rm -rf ./CMakeFiles/
rm -f ./Makefile
rm -f ./cmake_install.cmake

cd $CMD
