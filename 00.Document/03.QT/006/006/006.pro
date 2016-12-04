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
           src/SystemLib/language/languagePackage.cpp \
           src/SystemLib/log/log.cpp \
           src/SystemLib/datetime/datetime.cpp


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

FORMS    += mainwindow.ui
