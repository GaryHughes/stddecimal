#ifndef stddecimal_libdecimal_decimal_cmath_hpp
#define stddecimal_libdecimal_decimal_cmath_hpp

#include "decimal.hpp"

namespace std
{

// signbit
// fpclassify
// isfinite

bool isinf(decimal::decimal32 value);
bool isinf(decimal::decimal64 value);
bool isinf(decimal::decimal128 value);

bool isnan(decimal::decimal32 value);
bool isnan(decimal::decimal64 value);
bool isnan(decimal::decimal128 value);

// isnormal
// isgreater
// isgreaterequal
// isless
// islessequal
// islessgreater
// isunordered

}

#endif