find_package (Qt4 REQUIRED)

INCLUDE_DIRECTORIES(
  ../src
)

SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTTEST TRUE)
SET(QT_DONT_USE_QTGUI TRUE)

INCLUDE(${QT_USE_FILE})

ADD_DEFINITIONS(${QT_DEFINITIONS})

SET(SOURCES 
	tst_isohunt.cpp 
    stub_networkaccess.cpp 
    tst_networkaccess.cpp 
    tst_serie.cpp 
    tst_torrentfindercontroller.cpp 
    stub_torrentfinder.cpp 
    tst_seriescontroller.cpp 
    tst_seriesmodel.cpp 
    main.cpp 
    stub_logger.cpp 
    tst_scheduler.cpp 
    stub_seriedownloader.cpp 
    tst_downloader.cpp 
    tst_editserie.cpp 
    stub_editseriedialog.cpp 
    stub_messagebox.cpp 
    tst_mementocontroller.cpp)
    
SET(HEADERS 
	tst_isohunt.h 
    stub_networkaccess.h 
    tst_networkaccess.h 
    tst_serie.h 
    tst_torrentfindercontroller.h 
    stub_torrentfinder.h 
    tst_seriescontroller.h 
    tst_seriesmodel.h 
    stub_logger.h 
    tst_scheduler.h 
    stub_seriedownloader.h 
    tst_downloader.h 
    shared.h 
    tst_editserie.h 
    stub_editseriedialog.h 
    stub_messagebox.h 
    tst_mementocontroller.h)
    
SET(SOURCES_RC tests.qrc)

QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

ADD_EXECUTABLE(test_qserieshunter ${SOURCES} ${HEADERS_MOC} ${SOURCES_RC_SRC})
TARGET_LINK_LIBRARIES(test_qserieshunter ${QT_LIBRARIES} src)

