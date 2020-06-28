#include "decimal.hpp"

namespace std::decimal
{

const _IDEC_round round_mode = BID_ROUNDING_TO_NEAREST;


// 32 ------------------------------------------------

void operator_32bit::add(BID_UINT32& lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid32_add(lhs, rhs, round_mode, &flags); 
}

void operator_32bit::sub(BID_UINT32& lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid32_sub(lhs, rhs, round_mode, &flags); 
}

void operator_32bit::mul(BID_UINT32& lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid32_mul(lhs, rhs, round_mode, &flags); 
}

void operator_32bit::div(BID_UINT32& lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid32_div(lhs, rhs, round_mode, &flags); 
}

bool operator_32bit::equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_equal(lhs, rhs, &flags); 
}

bool operator_32bit::not_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_not_equal(lhs, rhs, &flags); 
}

bool operator_32bit::less(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_less(lhs, rhs, &flags); 
}

bool operator_32bit::less_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_less_equal(lhs, rhs, &flags); 
}

bool operator_32bit::greater(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_greater(lhs, rhs, &flags); 
}

bool operator_32bit::greater_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    _IDEC_flags flags = 0;
    return bid32_quiet_greater_equal(lhs, rhs, &flags); 
}

BID_UINT32 operator_32bit::resize(decimal32 value) {
    return value.value();
}

BID_UINT32 operator_32bit::resize(decimal64 value) {
    _IDEC_flags flags = 0;
    return bid64_to_bid32(value.value(), round_mode, &flags);
}

BID_UINT32 operator_32bit::resize(decimal128 value) {
    _IDEC_flags flags = 0;
    return bid128_to_bid32(value.value(), round_mode, &flags);
}

BID_UINT32 operator_32bit::resize(int value) {
    _IDEC_flags flags = 0;
    return bid32_from_int32(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(unsigned int value) {
    _IDEC_flags flags = 0;
    return bid32_from_uint32(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(long value) {
    _IDEC_flags flags = 0;
    return bid32_from_int64(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(unsigned long value) {
    _IDEC_flags flags = 0;
    return bid32_from_uint64(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(long long value) {
    _IDEC_flags flags = 0;
    return bid32_from_int64(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(unsigned long long value) {
    _IDEC_flags flags = 0;
    return bid64_to_bid32(value, round_mode, &flags);    
}

BID_UINT32 operator_32bit::resize(float value) {
    _IDEC_flags flags = 0;
    return binary32_to_bid32(value, round_mode, &flags);
}

// 64 ------------------------------------------------

void operator_64bit::add(BID_UINT64& lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid64_add(lhs, rhs, round_mode, &flags); 
}

void operator_64bit::sub(BID_UINT64& lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid64_sub(lhs, rhs, round_mode, &flags); 
}

void operator_64bit::mul(BID_UINT64& lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid64_mul(lhs, rhs, round_mode, &flags); 
}

void operator_64bit::div(BID_UINT64& lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid64_div(lhs, rhs, round_mode, &flags); 
}

bool operator_64bit::equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_equal(lhs, rhs, &flags); 
}

bool operator_64bit::not_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_not_equal(lhs, rhs, &flags); 
}

bool operator_64bit::less(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_less(lhs, rhs, &flags); 
}

bool operator_64bit::less_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_less_equal(lhs, rhs, &flags); 
}

bool operator_64bit::greater(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_greater(lhs, rhs, &flags); 
}

bool operator_64bit::greater_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    _IDEC_flags flags = 0;
    return bid64_quiet_greater_equal(lhs, rhs, &flags); 
}

BID_UINT64 operator_64bit::resize(decimal32 value) {
    _IDEC_flags flags = 0;
    return bid32_to_bid64(value.value(), &flags);
}

BID_UINT64 operator_64bit::resize(decimal64 value) {
    return value.value();
}

BID_UINT64 operator_64bit::resize(decimal128 value) {
    _IDEC_flags flags = 0;
    return bid128_to_bid64(value.value(), round_mode, &flags);
}

BID_UINT64 operator_64bit::resize(int value) {
    return bid64_from_int32(value);
}

BID_UINT64 operator_64bit::resize(unsigned int value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(long value) {
    return bid64_from_int32(value);
}

BID_UINT64 operator_64bit::resize(unsigned long value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(long long value) {
    return bid64_from_int32(value);
}

BID_UINT64 operator_64bit::resize(unsigned long long value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(float value) {
    _IDEC_flags flags = 0;
    return binary32_to_bid64(value, round_mode, &flags);
}

BID_UINT64 operator_64bit::resize(double value) {
    _IDEC_flags flags = 0;
    return binary64_to_bid64(value, round_mode, &flags);
}

// 128 -----------------------------------------------

void operator_128bit::add(BID_UINT128& lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid128_add(lhs, rhs, round_mode, &flags); 
}

void operator_128bit::sub(BID_UINT128& lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid128_sub(lhs, rhs, round_mode, &flags); 
}

void operator_128bit::mul(BID_UINT128& lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid128_mul(lhs, rhs, round_mode, &flags); 
}

void operator_128bit::div(BID_UINT128& lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    lhs = bid128_div(lhs, rhs, round_mode, &flags); 
}

bool operator_128bit::equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_equal(lhs, rhs, &flags); 
}

bool operator_128bit::not_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_not_equal(lhs, rhs, &flags); 
}

bool operator_128bit::less(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_less(lhs, rhs, &flags); 
}

bool operator_128bit::less_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_less_equal(lhs, rhs, &flags); 
}

bool operator_128bit::greater(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_greater(lhs, rhs, &flags); 
}

bool operator_128bit::greater_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    _IDEC_flags flags = 0;
    return bid128_quiet_greater_equal(lhs, rhs, &flags); 
}

BID_UINT128 operator_128bit::resize(decimal32 value) {
    _IDEC_flags flags = 0;
    return bid32_to_bid128(value.value(), &flags);
}

BID_UINT128 operator_128bit::resize(decimal64 value) {
    _IDEC_flags flags = 0;
    return bid64_to_bid128(value.value(), &flags);
}

BID_UINT128 operator_128bit::resize(decimal128 value) {
    return value.value();
}

BID_UINT128 operator_128bit::resize(int value) {
    return bid128_from_int32(value);
}

BID_UINT128 operator_128bit::resize(unsigned int value) {
    return bid128_from_uint32(value);
}

BID_UINT128 operator_128bit::resize(long value) {
    return bid128_from_int64(value);
}

BID_UINT128 operator_128bit::resize(unsigned long value) {
    return bid128_from_uint64(value);
}

BID_UINT128 operator_128bit::resize(long long value) {
    return bid128_from_int64(value);
}

BID_UINT128 operator_128bit::resize(unsigned long long value) {
    return bid128_from_uint64(value);
}

BID_UINT128 operator_128bit::resize(float value) {
    _IDEC_flags flags = 0;
    return binary32_to_bid128(value, round_mode, &flags);
}

BID_UINT128 operator_128bit::resize(double value) {
    _IDEC_flags flags = 0;
    return binary64_to_bid128(value, round_mode, &flags);
}

BID_UINT128 operator_128bit::resize(long double value) {
    //return bid128_from_binary128(value);
    return BID_UINT128();
}

// ---------------------------------------------------------

BID_UINT32 compound_result_traits_32::resize(BID_UINT32 value) {
    return value;
}

BID_UINT32 compound_result_traits_32::resize(BID_UINT64 value) {
    _IDEC_flags flags = 0;
    return bid64_to_bid32(value, round_mode, &flags);
}

BID_UINT32 compound_result_traits_32::resize(BID_UINT128 value) {
    _IDEC_flags flags = 0;
    return bid128_to_bid32(value, round_mode, &flags);
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT32 value) {
    _IDEC_flags flags = 0;
    return bid32_to_bid64(value, &flags);
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT64 value) {
    return value;
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT128 value) {
    _IDEC_flags flags = 0;
    return bid128_to_bid64(value, round_mode, &flags);
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT32 value) {
    _IDEC_flags flags = 0;
    return bid32_to_bid128(value, &flags);
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT64 value) {
    _IDEC_flags flags = 0;
    return bid64_to_bid128(value, &flags);
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT128 value) {
    return value;
}

// ---------------------------------------------------------

_IDEC_flags flags = 0;

template<typename DecimalType>
DecimalType make_decimal(long long coeff, int exponent)
{
    DecimalType multiplier;
    DecimalType power{1};
    DecimalType result{coeff};

    if (exponent < 0) {
        multiplier = DecimalType{1} / DecimalType{10};
		exponent = -exponent;                                        
    }
    else {
        multiplier = DecimalType{10};
    }

    for (int i = 0; i < exponent; ++i) {
        power *= multiplier;
    }

    return result * power;
}


decimal32 make_decimal32(long long coeff, int exponent)
{
    return make_decimal<decimal32>(coeff, exponent);    
} 

decimal32 make_decimal32(unsigned long long coeff, int exponent)
{
    return make_decimal<decimal32>(coeff, exponent);    
}

decimal64 make_decimal64(long long coeff, int exponent)
{
    return make_decimal<decimal64>(coeff, exponent);    
}

decimal64 make_decimal64(unsigned long long coeff, int exponent)
{
    return make_decimal<decimal64>(coeff, exponent);    
}

decimal128 make_decimal128(long long coeff, int exponent)
{
    return make_decimal<decimal128>(coeff, exponent);    
}

decimal128 make_decimal128(unsigned long long coeff, int exponent)
{
    return make_decimal<decimal128>(coeff, exponent);    
}

// 3.2.6 conversion to generic floating-point type:

float decimal32_to_float (decimal32 d)
{
    _IDEC_flags flags = 0;
    return bid32_to_binary32(d.value(), round_mode, &flags);
} 

float decimal64_to_float (decimal64 d)
{
    _IDEC_flags flags = 0;
    return bid64_to_binary32(d.value(), round_mode, &flags);
}

float decimal128_to_float(decimal128 d)
{
    _IDEC_flags flags = 0;
    return bid128_to_binary32(d.value(), round_mode, &flags);
}

float decimal_to_float(decimal32 d)
{
    return decimal32_to_float(d);
}

float decimal_to_float(decimal64 d)
{
    return decimal64_to_float(d);
}

float decimal_to_float(decimal128 d)
{
    return decimal128_to_float(d);
}

double decimal32_to_double (decimal32 d)
{
    _IDEC_flags flags = 0;
    return bid32_to_binary64(d.value(), round_mode, &flags);
}

double decimal64_to_double (decimal64 d)
{
    _IDEC_flags flags = 0;
    return bid64_to_binary64(d.value(), round_mode, &flags);
}

double decimal128_to_double(decimal128 d)
{
    // TODO
    return 0;
}

double decimal_to_double(decimal32 d)
{
    return decimal32_to_double(d);
}

double decimal_to_double(decimal64 d)
{
    return decimal64_to_double(d);
}

double decimal_to_double(decimal128 d)
{
    return decimal128_to_double(d);
}

long double decimal32_to_long_double(decimal32 d)
{
    // TODO
    return 0;
}

long double decimal64_to_long_double(decimal64 d)
{
    // TODO
    return 0;
} 

long double decimal128_to_long_double(decimal128 d)
{
    // TODO
    return 0;
} 

long double decimal_to_long_double(decimal32 d)
{
    return decimal32_to_long_double(d);
}

long double decimal_to_long_double(decimal64 d)
{
    return decimal64_to_double(d);
}

long double decimal_to_long_double(decimal128 d)
{
    return decimal128_to_long_double(d);
}

// 3.2.7 unary arithmetic operators: 

decimal32 operator+(decimal32 lhs)
{
    decimal32 result;
    result.value(lhs.value());
    return result;
}

decimal64 operator+(decimal64 lhs)
{
    decimal64 result;
    result.value(lhs.value());
    return result;
}

decimal128 operator+(decimal128 lhs)
{
    decimal128 result;
    result.value(lhs.value());
    return result;
}

decimal32 operator-(decimal32 lhs)
{
    decimal32 result;
    result.value(bid32_negate(lhs.value()));
    return result;
}

decimal64 operator-(decimal64 lhs)
{
    decimal64 result;
    result.value(bid64_negate(lhs.value()));
    return result;
}

decimal128 operator-(decimal128 lhs)
{
    decimal128 result;
    result.value(bid128_negate(lhs.value()));
    return result;
}

// decimal32 ------------------------------------------------------------------

decimal32::decimal32()
:   m_value(bid32_from_int32(0, round_mode, &flags))
{
}

decimal32::decimal32(decimal64 d64)
:   m_value(bid64_to_bid32(d64.value(), round_mode, &flags))
{
}

decimal32::decimal32(decimal128 d128)
:   m_value(bid128_to_bid32(d128.value(), round_mode, &flags))
{
}

decimal32::decimal32(float r)
:   m_value(binary32_to_bid32(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 4);
}

decimal32::decimal32(double r)
:   m_value(binary64_to_bid32(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal32::decimal32(long double r)
// : m_value(binary128_to_bid32(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 16);
}

decimal32::decimal32(int r)
:   m_value(bid32_from_int32(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 4);
}

decimal32::decimal32(unsigned int r)
:   m_value(bid32_from_uint32(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 4);
}

decimal32::decimal32(long r)
:   m_value(bid32_from_int64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal32::decimal32(unsigned long r)
:   m_value(bid32_from_uint64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal32::decimal32(long long r)
:   m_value(bid32_from_int64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal32::decimal32(unsigned long long r)
:   m_value(bid32_from_uint64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal32::operator long long() const
{
    // TODO - is this the appropriate conversion?
    return bid32_to_int32_floor(m_value, &flags);
}

decimal32::operator float() const
{
    return decimal_to_float(*this);
}

decimal32::operator double() const
{
    return decimal_to_double(*this);
}

decimal32::operator long double() const
{
    return decimal_to_long_double(*this);
}

decimal32& decimal32::operator++()
{
    *this += 1;
    return *this;
}

decimal32 decimal32::operator++(int)
{
    auto result = *this;
    *this += 1;
    return result;
}

decimal32& decimal32::operator--()
{
    *this -= 1;
    return *this;
}

decimal32 decimal32::operator--(int)
{
    auto result = *this;
    *this -= 1;    
    return result;
}

// decimal64 ------------------------------------------------------------------

decimal64::decimal64()
:   m_value(bid64_from_int64(0, round_mode, &flags))
{
}
    
decimal64::decimal64(decimal32 d32)
:   m_value(bid32_to_bid64(d32.value(), &flags))
{
}

decimal64::decimal64(decimal128 d128)
:   m_value(bid128_to_bid64(d128.value(), round_mode, &flags))
{
} 

decimal64::decimal64(float r)
:   m_value(binary32_to_bid64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 4);
} 

decimal64::decimal64(double r)
:   m_value(binary64_to_bid64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
} 

decimal64::decimal64(long double r)
{
    // TODO
    static_assert(sizeof(r) == 16);
}
    
decimal64::decimal64(int r)
:   m_value(bid64_from_int32(r))
{
    static_assert(sizeof(r) == 4);
}

decimal64::decimal64(unsigned int r)
:   m_value(bid64_from_uint32(r))
{
    static_assert(sizeof(r) == 4);
}

decimal64::decimal64(long r)
:   m_value(bid64_from_int64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}

decimal64::decimal64(unsigned long r)
:   m_value(bid64_from_uint64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
} 

decimal64::decimal64(long long r)
:   m_value(bid64_from_int64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
} 

decimal64::decimal64(unsigned long long r)
:   m_value(bid64_from_uint64(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
}
    
decimal64::operator long long() const
{
    return bid64_to_int64_floor(m_value, &flags);
}

decimal64::operator float() const
{
    return decimal_to_float(*this);
}

decimal64::operator double() const
{
    return decimal_to_double(*this);
}

decimal64::operator long double() const
{
    return decimal_to_long_double(*this);
}

decimal64& decimal64::operator++()
{
    *this += 1;
    return *this;
}

decimal64 decimal64::operator++(int)
{
    auto result = *this;
    *this += 1;
    return result;
}

decimal64& decimal64::operator--()
{
    *this -= 1;
    return *this;
}

decimal64 decimal64::operator--(int)
{
    auto result = *this;
    *this -= 1;
    return result;
}

// decimal128 -----------------------------------------------------------------

decimal128::decimal128()
:   m_value(bid128_from_int32(0))
{
}
    
decimal128::decimal128(decimal32 d32)
:   m_value(bid32_to_bid128(d32.value(), &flags))
{
}

decimal128::decimal128(decimal64 d64)
:   m_value(bid64_to_bid128(d64.value(), &flags))
{
} 

decimal128::decimal128(float r)
:   m_value(binary32_to_bid128(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 4);
}

decimal128::decimal128(double r)
:   m_value(binary64_to_bid128(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 8);
} 

decimal128::decimal128(long double r)
//:   m_value(binary128_to_bid128(r, round_mode, &flags))
{
    static_assert(sizeof(r) == 16);
}

decimal128::decimal128(int r)
:   m_value(bid128_from_int32(r))
{
    static_assert(sizeof(r) == 4);
}

decimal128::decimal128(unsigned int r)
:   m_value(bid128_from_uint32(r))
{
    static_assert(sizeof(r) == 4);
} 

decimal128::decimal128(long r)
:   m_value(bid128_from_int64(r))
{
    static_assert(sizeof(r) == 8);
}

decimal128::decimal128(unsigned long r)
:   m_value(bid128_from_uint64(r))
{
    static_assert(sizeof(r) == 8);
}

decimal128::decimal128(long long r)
{
    // TODO
    static_assert(sizeof(r) == 8);
}

decimal128::decimal128(unsigned long long r)
{
    // TODO
    static_assert(sizeof(r) == 8);
}

decimal128::operator long long() const
{
    // TODO
    return 0;
}

decimal128::operator float() const
{
    return 0;
}

decimal128::operator double() const
{
    return 0;
}

decimal128::operator long double() const
{
    return 0;
}

decimal128& decimal128::operator++()
{
    *this += 1;
    return *this;
}

decimal128 decimal128::operator++(int)
{
    auto result = *this;
    *this += 1;
    return result;
}

decimal128& decimal128::operator--()
{
    *this -= 1;
    return *this;
}

decimal128 decimal128::operator--(int)
{
    auto result = *this;
    *this -= 1;
    return result;
}

}