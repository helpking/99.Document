cmake_minimum_required (VERSION 2.8.11)

#project(hello)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

# bin
set(BIN_DIR "./bin")
# target
set(EXE_TARGET "${BIN_DIR}/hello")
# src
set(SRC_DIR "./src")

message(status|fatal_error, ${SRC_DIR})

# ヘッダーファイルのディレクトリー
include_directories(${HELLO_SOURCE_DIR}/src)

# リンクファイル用のディレクトリー（サーチー用）
link_directories(${HELLO_BINARY_DIR}/bin) 

# サブディレクトリー
add_subdirectory(${HELLO_SOURCE_DIR}/src)

# コンパイル用のマクロ追加
add_definitions(-DDEBUG)

# ライブラリの追加&生成（hello.cc -> libHello.a）
add_library(Hello hello.cc)

find_package(Qt5Widgets)

# メッセージ出力
message(status|fatal_error, “find_package”)

add_executable(${EXE_TARGET} ${SRC_DIR}/hello.cc)
#target_link_libraries(hello Qt5::Widgets)

