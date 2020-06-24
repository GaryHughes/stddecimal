add_library(decimal
    decimal.hpp decimal.cpp
)

target_link_libraries(decimal
    bid
)