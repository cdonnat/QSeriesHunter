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
    tst_networkaccess.h \
    tst_serie.h \
    tst_torrentfindercontroller.h \
    stub_torrentfinder.h \
    tst_seriescontroller.h \
    tst_seriesmodel.h \
    stub_logger.h \
    tst_scheduler.h \
    stub_seriedownloader.h \
    tst_downloader.h \
    shared.h
SOURCES += \
    tst_isohunt.cpp \
    stub_networkaccess.cpp \
    tst_networkaccess.cpp \
    tst_serie.cpp \
    tst_torrentfindercontroller.cpp \
    stub_torrentfinder.cpp \
    tst_seriescontroller.cpp \
    tst_seriesmodel.cpp \
    main.cpp \
    stub_logger.cpp \
    tst_scheduler.cpp \
    stub_seriedownloader.cpp \
    tst_downloader.cpp

OTHER_FILES += \
    input/json_input.txt
