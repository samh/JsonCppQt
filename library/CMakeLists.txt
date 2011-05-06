find_package(Qt4 REQUIRED)
include(${QT_USE_FILE})

set(SOURCES jsoncpp.cpp jsoncpp-qt.cpp)

add_library(jsoncpp-qt ${SOURCES})
