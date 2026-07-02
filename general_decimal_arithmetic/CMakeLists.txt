set(BOOST_VERSION_REQUIRED 1.90)

find_package(Boost ${BOOST_VERSION_REQUIRED} EXACT
    COMPONENTS
    program_options
    regex
    REQUIRED
)

add_subdirectory(libgdatest)
add_subdirectory(libgdatest_tests)
add_subdirectory(test_runner)
