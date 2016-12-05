#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T20:52:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ./bin/006
TEMPLATE = app

# .O文件输出路径(当前编译目录下)
OBJECTS_DIR = ./Output/

# 指定源文件中包含文件的搜索路径
#INCLUDEPATH += 具体文件路径

# 宏定义
DEFINES += QT_DEBUG

# Sources
SOURCES += src/memory_check.cpp \
           main.cpp \
           mainwindow.cpp \
           src/SystemLib/language/languagePackage.cpp \
           src/SystemLib/log/log.cpp \
           src/SystemLib/datetime/datetime.cpp

# Headers
HEADERS  += include/memory_check.h \
            mainwindow.h \
            include/common_macro.h \
            include/common_types.h \
            include/common.h \
            include/ui/ui_types.h \
            include/SystemLib/language/languagePackage.h \
            include/SystemLib/language/languagePackage_text.h \
            include/SystemLib/language/languagePackage_types.h \
            include/SystemLib/log/log.h \
            include/SystemLib/log/log_types.h \
            include/SystemLib/datetime/datetime.h \
            include/SystemLib/datetime/datetime_types.h

# UI
FORMS    += mainwindow.ui

RESOURCES += \
    resource.qrc
