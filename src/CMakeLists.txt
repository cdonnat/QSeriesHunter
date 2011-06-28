find_package (Qt4 REQUIRED)

SET(QT_USE_QTNETWORK TRUE)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(SOURCES_RC QSeriesHunter.qrc)

SET(SOURCES 
	isohunt.cpp 
    networkaccess.cpp 
    torrentfinderresult.cpp 
    serie.cpp 
    torrentfindercontroller.cpp 
    seriescontroller.cpp 
    seriesmodel.cpp 
    mainwindow.cpp 
    serieswidget.cpp 
    scheduler.cpp 
    loggerwidget.cpp 
    downloader.cpp 
    seriedownloader.cpp 
    editseriedialog.cpp 
    editserie.cpp 
    messagebox.cpp
    seriesmemento.cpp 
    mementocontroller.cpp)
    
SET(HEADERS 
	isohunt.h 
    itorrentfinder.h 
    inetworkaccess.h 
    networkaccess.h 
    torrentfinderresult.h 
    serie.h 
    torrentfindercontroller.h 
    seriescontroller.h 
    seriesmodel.h 
    mainwindow.h 
    serieswidget.h 
    scheduler.h 
    ilogger.h 
    log.h 
    loggerwidget.h 
    downloader.h 
    iseriedownloader.h 
    seriedownloader.h 
    iseriescontroller.h 
    editseriedialog.h 
    ieditseriedialog.h 
    editserie.h 
    imessagebox.h 
    messagebox.h 
    seriesmemento.h 
    mementocontroller.h)
    
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})
QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )

ADD_LIBRARY(src SHARED ${SOURCES} ${HEADERS_MOC} ${SOURCES_RC_SRC})
TARGET_LINK_LIBRARIES(src ${QT_LIBRARIES} qjson)

