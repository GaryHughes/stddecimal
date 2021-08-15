add_executable(libgdatest_tests
    main.cpp
    test_line_tests.cpp
)

target_link_libraries(libgdatest_tests
    gdatest 
    ${DECIMAL_EXTRA_LIBRARIES}
)

catch_discover_tests(libgdatest_tests)
