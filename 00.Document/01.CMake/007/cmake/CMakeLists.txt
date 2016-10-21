cmake_minimum_required (VERSION 2.8.11)

#project(main)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

# bin
set(BIN_DIR "./bin")
# target
set(EXE_TARGET "${BIN_DIR}/main")
# src
set(SRC_DIR "./src")

add_executable(${BIN_DIR}/main ${SRC_DIR}/hello.cc)
#target_link_libraries(main hello)

