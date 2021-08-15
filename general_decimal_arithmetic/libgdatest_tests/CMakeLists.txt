add_executable(libgdatest_tests
    main.cpp
    test_line_tests.cpp
)

include_directories(
    "${CMAKE_SOURCE_DIR}/general_decimal_arithmetic"
)


target_link_libraries(libgdatest_tests
    gdatest 
    ${DECIMAL_EXTRA_LIBRARIES}
)

catch_discover_tests(libgdatest_tests)
