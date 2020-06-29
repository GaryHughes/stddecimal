add_executable(libdecimal_tests
    main.cpp
    decimal_tests.cpp
)

if(UNIX AND NOT APPLE)
    set(DECIMAL_EXTRA_LIBRARIES pthread)
endif()

target_link_libraries(libdecimal_tests
    decimal
    ${DECIMAL_EXTRA_LIBRARIES}
)

catch_discover_tests(libdecimal_tests)
