#include "decimal_cmath.hpp"

namespace std
{

bool isinf(decimal::decimal32 value)
{
    return bid32_isInf(value.value());
}

bool isinf(decimal::decimal64 value)
{
    return bid64_isInf(value.value());
}

bool isinf(decimal::decimal128 value)
{
    return bid128_isInf(value.value());
}

bool isnan(decimal::decimal32 value)
{
    return bid32_isNaN(value.value());
}

bool isnan(decimal::decimal64 value)
{
    return bid64_isNaN(value.value());
}

bool isnan(decimal::decimal128 value)
{
    return bid128_isNaN(value.value());
}

}

