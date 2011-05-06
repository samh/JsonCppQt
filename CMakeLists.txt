# Probably could use an earlier version, but I'm not testing that now
cmake_minimum_required(VERSION 2.8)
project(jsoncpp-qt)

# Look for extra CMake modules in a subdirectory of this project
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/" ${CMAKE_MODULE_PATH})

# Up the compiler warnings
set(EXTRA_WARNINGS off CACHE BOOL "Enable extra compiler warnings (-Wall)")
if(EXTRA_WARNINGS)
    include(EnableWarnings)
endif(EXTRA_WARNINGS)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated")

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

# Library includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/library)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(library)
add_subdirectory(progs)
