find_package (Qt4 REQUIRED)

INCLUDE_DIRECTORIES(
    ../src
    ../src/network
    ../src/series
    ../src/gui
)

SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTTEST TRUE)
SET(QT_DONT_USE_QTGUI TRUE)

INCLUDE(${QT_USE_FILE})

ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(STUBS
    stub_defaultapprunner.cpp
    stub_logger.cpp
    stub_networkaccess.cpp
    stub_torrentfinder.cpp
    stub_editseriedialog.cpp
    stub_messagebox.cpp)

SET(SOURCES
    tst_isohunt.cpp
    tst_networkaccess.cpp 
    tst_serie.cpp 
    tst_torrentfindercontroller.cpp 
    tst_seriescontroller.cpp 
    tst_seriesmodel.cpp 
    main.cpp
    tst_scheduler.cpp
    tst_downloader.cpp 
    tst_editserie.cpp 
    tst_mementocontroller.cpp)
    
SET(HEADERS 
    tst_isohunt.h
    tst_networkaccess.h
    tst_torrentfindercontroller.h
    tst_seriescontroller.h 
    tst_seriesmodel.h
    tst_scheduler.h
    tst_downloader.h
    tst_editserie.h
    tst_mementocontroller.h
    tst_serie.h)
    
SET(SOURCES_RC tests.qrc)

QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

ADD_EXECUTABLE(test_qserieshunter ${SOURCES} ${STUBS} ${HEADERS_MOC} ${SOURCES_RC_SRC})
TARGET_LINK_LIBRARIES(test_qserieshunter ${QT_LIBRARIES} src)

