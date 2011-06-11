! include( ../common.pri ) {
    error( "Could not find the common.pri file!" )
}
INCLUDEPATH += ../src
TEMPLATE = app
QT      += gui
CONFIG  -= app_bundle
TARGET  = ../exe/main

LIBS += -L../exe -lsrc

SOURCES += main.cpp
