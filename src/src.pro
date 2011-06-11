! include( ../common.pri ) {
    error( "Could not find the common.pri file!" )
}
TEMPLATE = lib
QT      += network

INCLUDEPATH += /usr/local/include
LIBS    += -lqjson

HEADERS += \
    isohunt.h \
    itorrentfinder.h \
    inetworkaccess.h \
    networkaccess.h \
    torrentdownloader.h \
    torrentfinderresult.h \
    serie.h \
    torrentfindercontroller.h \
    seriescontroller.h \
    seriesmodel.h
SOURCES += \  
    isohunt.cpp \
    networkaccess.cpp \
    torrentdownloader.cpp \
    torrentfinderresult.cpp \
    serie.cpp \
    torrentfindercontroller.cpp \
    seriescontroller.cpp \
    seriesmodel.cpp
