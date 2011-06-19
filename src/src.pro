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
    torrentfinderresult.h \
    serie.h \
    torrentfindercontroller.h \
    seriescontroller.h \
    seriesmodel.h \
    mainwindow.h \
    serieswidget.h \
    scheduler.h \
    ilogger.h \
    log.h \
    loggerwidget.h \
    downloader.h \
    iseriedownloader.h \
    seriedownloader.h \
    iseriescontroller.h \
    editseriedialog.h \
    ieditseriedialog.h \
    editserie.h \
    imessagebox.h \
    messagebox.h
SOURCES += \  
    isohunt.cpp \
    networkaccess.cpp \
    torrentfinderresult.cpp \
    serie.cpp \
    torrentfindercontroller.cpp \
    seriescontroller.cpp \
    seriesmodel.cpp \
    mainwindow.cpp \
    serieswidget.cpp \
    scheduler.cpp \
    loggerwidget.cpp \
    downloader.cpp \
    seriedownloader.cpp \
    editseriedialog.cpp \
    editserie.cpp \
    messagebox.cpp
