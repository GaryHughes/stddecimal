add_library(decimal
    decimal.hpp decimal.cpp
    decimal_cmath.hpp decimal_cmath.cpp
    decimal_numeric_limits.hpp
)

target_include_directories(decimal PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/libdecimal
    # TODO - IntelRDFPMathLib20U2
    ${CMAKE_SOURCE_DIR}/..
)

target_link_directories(decimal PUBLIC
    ${CMAKE_SOURCE_DIR}/../IntelRDFPMathLib20U2/LIBRARY
)

target_link_libraries(decimal PUBLIC
    bid
)