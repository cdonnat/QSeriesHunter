INCLUDE_DIRECTORIES(
  ../src/gui
)

INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
  
ADD_EXECUTABLE(${PROJECT_NAME} MACOSX_BUNDLE WIN32 main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${QT_LIBRARIES} src)

INSTALL(TARGETS ${PROJECT_NAME} 
    BUNDLE DESTINATION . COMPONENT Runtime
    RUNTIME DESTINATION bin COMPONENT Runtime)

set(APPS ${QSeriesHunter_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}/${PROJECT_NAME}.app)
set(DIRS ${QT_LIBRARY_DIR} ${LIBRARY_OUTPUT_PATH} /usr/local/lib)   # directories to search for prerequisites
INSTALL(CODE "
   include(BundleUtilities)
   fixup_bundle(\"${APPS}\"   \"\"   \"${DIRS}\")
   " COMPONENT Runtime)  

# To Create a package, one can run "cpack -G DragNDrop CPackConfig.cmake" on Mac OS X
# where CPackConfig.cmake is created by including CPack
# And then there's ways to customize this as well
set(CPACK_BINARY_DRAGNDROP ON)
include(CPack)