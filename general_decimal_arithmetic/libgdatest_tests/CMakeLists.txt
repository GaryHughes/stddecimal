add_executable(libgdatest_tests
    test_line_tests.cpp
)

target_link_libraries(libgdatest_tests
    gdatest
    ${DECIMAL_EXTRA_LIBRARIES}
    Catch2::Catch2WithMain
)

catch_discover_tests(libgdatest_tests)
