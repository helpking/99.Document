#-------------------------------------------------
#
# Project created by QtCreator 2016-11-30T20:52:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 006
TEMPLATE = app


SOURCES += src/memory_check.cpp \
           main.cpp \
           mainwindow.cpp \
           src/language/languagePackage.cpp \


HEADERS  += include/memory_check.h \
            mainwindow.h \
            include/common_types.h \
            include/common.h \
            include/ui/ui_types.h \
            include/language/languagePackage.h \
            include/language/languagePackage_types.h \
            include/language/languagePackage_text.h

FORMS    += mainwindow.ui
