# Probably could use an earlier version, but I'm not testing that now
cmake_minimum_required(VERSION 2.8)
project(jsoncpp-qt)

# Look for extra CMake modules in the ACS directory
set(CMAKE_MODULE_PATH "$ENV{ACSDIR}/cmake/modules/" ${CMAKE_MODULE_PATH})

# Look for extra CMake modules in a subdirectory of this project
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/" ${CMAKE_MODULE_PATH})

# Up the compiler warnings
set(EXTRA_WARNINGS off CACHE BOOL "Enable extra compiler warnings (-Wall)")
if(EXTRA_WARNINGS)
    include(EnableWarnings)
endif(EXTRA_WARNINGS)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-deprecated")

# Generate doxygen documentation with "make doc"
#include(UseDoxygen)

# The macro below forces the build directory to be different from source directory
include(MacroEnsureOutOfSourceBuild)
macro_ensure_out_of_source_build("${PROJECT_NAME} requires an out of source build. Please see 'README.txt'.")

find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

# Find ACS libraries and headers
#find_package(ACSPRISM REQUIRED)
#include_directories(${ACSPRISM_INCLUDE_DIRS})

# Library includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/library)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(library)
add_subdirectory(progs)
