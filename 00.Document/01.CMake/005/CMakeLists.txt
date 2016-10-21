cmake_minimum_required (VERSION 2.6)

project(prog6)


find_package(GLUT)
find_package(OpenGL)

set(CMAKE_CXX_FLAGS "-g -Wall")
# bin
set(BIN_DIR "./bin")
# target
set(EXE_TARGET "${BIN_DIR}/target")
# src
set(SRC_DIR "./src")

add_executable(${EXE_TARGET} prog6.cc)
target_link_libraries(${EXE_TARGET} ${GLUT_LIBRARY} ${OPENGL_LIBRARY} m)

