cmake_minimum_required(VERSION 3.21.0)

project(stddecimal)

# Checks and WarningsAsErrors are configured in .clang-tidy; -line-filter has no
# equivalent there so it stays here.
set(CMAKE_CXX_CLANG_TIDY
    clang-tidy;
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

# CTest's own "test" target intentionally has no dependency on the test binaries - build and
# test are deliberately decoupled in CMake. "check" is a convenience target that builds what
# ctest needs first, so a single build system invocation reliably builds then tests in order.
add_custom_target(check
    COMMAND ${CMAKE_CTEST_COMMAND} --force-new-ctest-process
    DEPENDS test_runner libdecimal_tests libgdatest_tests
)