add_executable(libdecimal_tests
    main.cpp
    decimal_tests.cpp
)

target_link_libraries(libdecimal_tests
    decimal
)

catch_discover_tests(libdecimal_tests)
