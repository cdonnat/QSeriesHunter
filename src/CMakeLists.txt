SET(QT_USE_QTNETWORK TRUE)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

INCLUDE_DIRECTORIES(network
                    series
                    gui
                    ${CMAKE_CURRENT_SOURCE_DIR})

SET(SOURCES_RC resources/QSeriesHunter.qrc)

FILE(GLOB NETWORK_SRC "network/*.*")
FILE(GLOB SERIES_SRC "series/*.*")
FILE(GLOB GUI_SRC "gui/*.*")

SET(MOC_HEADERS gui/mainwindow.h gui/serieswidget.h)
    
QT4_WRAP_CPP(HEADERS_MOC ${MOC_HEADERS})
QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )

ADD_LIBRARY(src
            SHARED
            ${NETWORK_SRC}
            ${SERIES_SRC}
            ${GUI_SRC}
            ${HEADERS_MOC}
            ${SOURCES_RC_SRC})

TARGET_LINK_LIBRARIES(src ${QT_LIBRARIES} qjson)

#INSTALL(TARGETS src 
#        BUNDLE DESTINATION . COMPONENT Runtime
#        LIBRARY DESTINATION lib COMPONENT Runtime)