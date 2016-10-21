#!/bin/bash 

# 生成ディレクトリー
CREATE_DIR=""
# カレントディレクトリー
CUR_DIR="."
# サンプルのテンプレートディレクトリー
SAMPLE_TEMP_DIR="${CUR_DIR}/sample"

if [[ $# -lt 1 ]];then
  echo "Command Format:`basename $0` -c create dir"
  exit 1
fi

while getopts c: opt; do  
case $opt in   
  c)  
    CREATE_DIR=$OPTARG
    CREATE_DIR="${CUR_DIR}/${CREATE_DIR}"
    ;; 
  *)  
    ;;  
esac  
done 

if [ ! -d "${CREATE_DIR}" ]; then 
  mkdir ${CREATE_DIR}
else
  rm -rf ${CREATE_DIR}/*
fi

# Copy
cp -rfp ${SAMPLE_TEMP_DIR}/* ${CREATE_DIR}