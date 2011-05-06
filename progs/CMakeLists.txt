set(COMMON_LIBS
    jsoncpp-qt
    ${QT_LIBRARIES}
    )

add_executable(test1 test1)
target_link_libraries(test1
    ${COMMON_LIBS}
    )

add_executable(test1-qt test1-qt)
target_link_libraries(test1-qt
    ${COMMON_LIBS}
    )
