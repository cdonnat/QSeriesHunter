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

FILE(GLOB STUBS "stub_*.cpp")
FILE(GLOB SOURCES "tst_*.cpp")
FILE(GLOB HEADERS "tst_*.h")

SET(SOURCES_RC tests.qrc)

QT4_ADD_RESOURCES(SOURCES_RC_SRC ${SOURCES_RC} )
QT4_WRAP_CPP(HEADERS_MOC ${HEADERS})

ADD_EXECUTABLE(test_qserieshunter
                main.cpp
                ${SOURCES}
                ${STUBS}
                ${HEADERS_MOC}
                ${SOURCES_RC_SRC})

TARGET_LINK_LIBRARIES(test_qserieshunter ${QT_LIBRARIES} src)
