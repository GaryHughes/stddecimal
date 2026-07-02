cmake_minimum_required(VERSION 3.17.0)

project(stddecimal)

set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
    -checks=-*,clang-analyzer-*,bugprone-*,concurrency-*,cppcoreguidelines-*,misc-*,modernize-*,performance-*,portability-*,readability-*,-modernize-use-trailing-return-type,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers;
    -warnings-as-errors=*;
    -line-filter=[{"name":"catch.hpp"}])

# Don't embed build tree paths
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "")

find_package(Catch2 3 REQUIRED)

enable_testing()
include(CTest)
include(Catch)

add_subdirectory(libdecimal)
add_subdirectory(libdecimal_tests)
add_subdirectory(general_decimal_arithmetic)