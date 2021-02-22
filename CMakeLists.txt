cmake_minimum_required(VERSION 3.10.0)

project(stddecimal)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -checks=-*,clang-analyzer-*,bugprone-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-modernize-use-trailing-return-type,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers;
    -warnings-as-errors=*;)

# Don't embed build tree paths
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "")

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/thirdparty/catch2/include
    # TODO - IntelRDFPMathLib20U2
    ${CMAKE_SOURCE_DIR}/..
)

link_directories(
    ${CMAKE_SOURCE_DIR}/../IntelRDFPMathLib20U2/LIBRARY
)

enable_testing()
include(CTest)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/thirdparty/catch2/contrib")
include(Catch)

add_subdirectory(libdecimal)
add_subdirectory(libdecimal_tests)
add_subdirectory(general_decimal_arithmetic)