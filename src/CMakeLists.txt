find_package (Qt4 REQUIRED)

SET(QT_USE_QTNETWORK TRUE)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(network
                    series
                    gui
                    ${CMAKE_CURRENT_SOURCE_DIR})

SET(SOURCES_RC resources/QSeriesHunter.qrc)

SET(NETWORK_SRC
    network/defaultexternalapprunner.cpp
    network/downloader.cpp
    network/isohunt.cpp
    network/networkaccess.cpp
    network/torrentfindercontroller.cpp
    network/torrentfinderresult.cpp)

SET(SERIES_SRC
    series/mementocontroller.cpp
    series/scheduler.cpp
    series/serie.cpp
    series/seriescontroller.cpp
    series/seriesmemento.cpp)

SET(GUI_SRC
    gui/editserie.cpp
    gui/editseriedialog.cpp
    gui/loggerwidget.cpp
    gui/mainwindow.cpp
    gui/messagebox.cpp
    gui/seriesmodel.cpp
    gui/serieswidget.cpp)

SET(HEADERS
    downloader.h
    idefaultexternalapprunner.h
    inetworkaccess.h
    isohunt.h
    itorrentfinder.h
    defaultexternalapprunner.h
    networkaccess.h )

SOURCE_GROUP(headers ${MOC_HEADERS})

SET(MOC_HEADERS gui/mainwindow.h gui/serieswidget.h)
    
QT4_WRAP_CPP(HEADERS_MOC ${MOC_HEADERS})
QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )

ADD_LIBRARY(src SHARED
                ${NETWORK_SRC}
                ${SERIES_SRC}
                ${GUI_SRC}
                ${HEADERS_MOC}
                ${SOURCES_RC_SRC})
TARGET_LINK_LIBRARIES(src ${QT_LIBRARIES} qjson)

