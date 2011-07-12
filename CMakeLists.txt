set(PROJECT_NAME QSeriesHunter)

project (${PROJECT_NAME})

cmake_minimum_required(VERSION 2.6)

# set warning level
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wno-unused -Wno-uninitialized")


set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
             "Debug" "Release" "Coverage")
set(CMAKE_CXX_FLAGS_COVERAGE "${CMAKE_CXX_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_COVERAGE "${CMAKE_C_FLAGS_DEBUG} -fprofile-arcs -ftest-coverage")
set(CMAKE_EXE_LINKER_FLAGS_COVERAGE "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")

set(EXECUTABLE_OUTPUT_PATH ${QSeriesHunter_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
set(LIBRARY_OUTPUT_PATH ${QSeriesHunter_BINARY_DIR}/lib/${CMAKE_BUILD_TYPE})

find_package (Qt4 REQUIRED)

add_subdirectory (src)
add_subdirectory (test_unit)
add_subdirectory (main)


