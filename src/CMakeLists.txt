SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTXML TRUE)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

if (WIN32)
INCLUDE_DIRECTORIES(network
                    series
                    gui
                    ${CMAKE_CURRENT_SOURCE_DIR}
                    "C:/Program Files/qjson/include")
else (WIN32)
INCLUDE_DIRECTORIES(network
                    series
                    gui
                    ${CMAKE_CURRENT_SOURCE_DIR}
					/usr/local/include)
endif (WIN32)

MESSAGE (STATUS ${CMAKE_CURRENT_BINARY_DIR})
CONFIGURE_FILE (${CMAKE_CURRENT_SOURCE_DIR}/config.h.cmake ${CMAKE_CURRENT_SOURCE_DIR}/config.h)

SET(SOURCES_RC resources/src.qrc)

FILE(GLOB NETWORK_SRC "network/*.*")
FILE(GLOB SERIES_SRC "series/*.*")
FILE(GLOB GUI_SRC "gui/*.*")

SET(MOC_HEADERS gui/mainwindow.h gui/serieswidget.h gui/loggerwidget.h)
    
QT4_WRAP_CPP(HEADERS_MOC ${MOC_HEADERS})
QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )

SOURCE_GROUP(Network FILES ${NETWORK_SRC})
SOURCE_GROUP(Series FILES ${SERIES_SRC})
SOURCE_GROUP(Gui FILES ${GUI_SRC})

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