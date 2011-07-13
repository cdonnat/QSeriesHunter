INCLUDE_DIRECTORIES(
  ../src/gui
)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})

ADD_EXECUTABLE(${PROJECT_NAME} MACOSX_BUNDLE WIN32 main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${QT_LIBRARIES} src)

set(APPS ${QSeriesHunter_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.app)
set(DIRS ${QT_LIBRARY_DIR} ${LIBRARY_OUTPUT_PATH} /usr/local/lib)   # directories to search for prerequisites
INSTALL(CODE "
   include(BundleUtilities)
   fixup_bundle(\"${APPS}\"   \"\"   \"${DIRS}\")
   " COMPONENT Runtime)  

INSTALL(TARGETS ${PROJECT_NAME} 
    BUNDLE DESTINATION . COMPONENT Runtime
    RUNTIME DESTINATION bin COMPONENT Runtime) 

SET(APP_ICON "${CMAKE_CURRENT_SOURCE_DIR}/Resources/QSeriesHunter.icns")
SET(MACOSX_BUNDLE_ICON_FILE ${APP_ICON})
SET_SOURCE_FILES_PROPERTIES(${MACOSX_BUNDLE_ICON_FILE} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "1")

# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_BINARY_DRAGNDROP ON)
include(CPack)