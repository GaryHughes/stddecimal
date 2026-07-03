add_library(gdatest
    test_line.hpp test_line.cpp
    test_file.hpp
    test_context.hpp test_context.cpp
    test_results.hpp
)

target_include_directories(gdatest PUBLIC
    ${Boost_INCLUDE_DIRS}
    "${CMAKE_SOURCE_DIR}/general_decimal_arithmetic"
    "${CMAKE_SOURCE_DIR}/general_decimal_arithmetic/libgdatest"
)

target_link_libraries(gdatest PUBLIC
    decimal
    Boost::regex
)
