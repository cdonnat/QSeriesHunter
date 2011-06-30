find_package (Qt4 REQUIRED)

SET(QT_USE_QTNETWORK TRUE)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(network
                    ${CMAKE_CURRENT_SOURCE_DIR})

SET(SOURCES_RC resources/QSeriesHunter.qrc)

SET(NETWORK_SRC
    network/defaultexternalapprunner.cpp
    network/downloader.cpp
    network/isohunt.cpp
    network/networkaccess.cpp
    network/torrentfinderresult.cpp)

SET(SOURCES
    serie.cpp 
    torrentfindercontroller.cpp 
    seriescontroller.cpp 
    seriesmodel.cpp 
    mainwindow.cpp 
    serieswidget.cpp 
    scheduler.cpp 
    loggerwidget.cpp 
    editseriedialog.cpp 
    editserie.cpp 
    messagebox.cpp
    seriesmemento.cpp 
    mementocontroller.cpp)

SET(HEADERS
    downloader.h
    idefaultexternalapprunner.h
    inetworkaccess.h
    isohunt.h
    itorrentfinder.h
    defaultexternalapprunner.h
    networkaccess.h )

SOURCE_GROUP(headers ${MOC_HEADERS})

SET(MOC_HEADERS
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
    iseriescontroller.h
    editseriedialog.h 
    ieditseriedialog.h 
    editserie.h 
    imessagebox.h 
    messagebox.h 
    seriesmemento.h 
    mementocontroller.h)
    
QT4_WRAP_CPP(HEADERS_MOC ${MOC_HEADERS})
QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )

ADD_LIBRARY(src SHARED
                ${SOURCES}
                ${NETWORK_SRC}
                ${HEADERS_MOC}
                ${SOURCES_RC_SRC})
TARGET_LINK_LIBRARIES(src ${QT_LIBRARIES} qjson)

