! include( ../common.pri ) {
    error( "Could not find the common.pri file!" )
}
INCLUDEPATH += ../src
TEMPLATE = app
QT      += testlib network
CONFIG  += console
CONFIG  -= app_bundle
TARGET  = ../exe/test_unit
LIBS += -L../exe -lsrc

HEADERS += \
    tst_isohunt.h \
    stub_networkaccess.h \
    tst_torrentdownloader.h \
    tst_networkaccess.h \
    tst_serie.h
SOURCES += \
           main.cpp \
    tst_isohunt.cpp \
    stub_networkaccess.cpp \
    tst_torrentdownloader.cpp \
    tst_networkaccess.cpp \
    tst_serie.cpp

OTHER_FILES += \
    input/json_input.txt
