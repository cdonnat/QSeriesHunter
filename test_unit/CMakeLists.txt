INCLUDE_DIRECTORIES(
    ../src
    ../src/network
    ../src/series
    ../src/gui
)

SET(QT_USE_QTNETWORK TRUE)
SET(QT_USE_QTTEST TRUE)

INCLUDE(${QT_USE_FILE})

ADD_DEFINITIONS(${QT_DEFINITIONS})

FILE(GLOB STUBS "stub_*.*")
FILE(GLOB SOURCES "tst_*.cpp")
FILE(GLOB HEADERS "tst_*.h")

FILE(GLOB INPUT_RC "input/*.*")

SET(SOURCES_RC tests.qrc)

SOURCE_GROUP(Stubs FILES ${STUBS})
SOURCE_GROUP(Test_Unit FILES ${SOURCES} ${HEADERS})
SOURCE_GROUP(Input FILES ${INPUT_RC})


QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

ADD_EXECUTABLE(test_qserieshunter
                main.cpp
                ${HEADERS}
                ${SOURCES}
                ${STUBS}
                ${HEADERS_MOC}
                ${SOURCES_RC_SRC})

TARGET_LINK_LIBRARIES(test_qserieshunter ${QT_LIBRARIES} src)
