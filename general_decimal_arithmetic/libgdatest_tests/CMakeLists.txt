add_executable(libgdatest_tests
    test_line_tests.cpp
)

include_directories(
    "${CMAKE_SOURCE_DIR}/libdecimal"
    "${CMAKE_SOURCE_DIR}/general_decimal_arithmetic"
)

if(APPLE)

    set(BOOST_LIBS
        libboost_program_options-mt.dylib
        libboost_regex-mt.dylib
    )

else()

    set(BOOST_LIBS
        libboost_program_options.so
        libboost_regex.so
    )
        
endif()

target_link_libraries(libgdatest_tests
    gdatest 
    ${DECIMAL_EXTRA_LIBRARIES}
    ${BOOST_LIBS}
    Catch2::Catch2WithMain
)

catch_discover_tests(libgdatest_tests)
