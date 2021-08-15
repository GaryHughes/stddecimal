add_library(gdatest
    test_file.hpp
    test_context.hpp test_context.cpp
    test_results.hpp
)

include_directories(
    "/usr/local/include"
    "${CMAKE_SOURCE_DIR}/libdecimal"
)


