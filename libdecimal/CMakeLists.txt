add_library(decimal
    decimal.hpp decimal.cpp
    decimal_cmath.hpp decimal_cmath.cpp
)

target_link_libraries(decimal
    bid
)