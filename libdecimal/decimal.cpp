#include "decimal.hpp"
#include <limits>

namespace std::decimal
{

const fenv_t default_environment { FE_DEC_TONEAREST, 0, false, 0 };
thread_local fenv_t environment = default_environment; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)
thread_local unsigned int hold_flags; // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

const size_t bytes_in_32_bit_decimal = 4;
const size_t bytes_in_64_bit_decimal = 8;
const size_t bytes_in_128_bit_decimal = 16;

unsigned int* environment_flags()
{
    if (environment.hold) {
        return &hold_flags;
    }

    return &environment.flags;
}

int fe_dec_clearexcept(int except)
{
    environment.flags &= ~except;
    return 0;
}

int fe_dec_raiseexcept(int except)
{
    if (!environment.hold) {
        environment.flags |= except;
    }
    return 0;
}

int fe_dec_getexceptflag(fexcept_t *pflag, int except)
{
    if (pflag == nullptr) {
        return 1;
    }

    *pflag = fexcept_t(environment.flags & except);
    
    return 0;
}

int fe_dec_setexceptflag(const fexcept_t *pflag, int except)
{
    if (pflag == nullptr) {
        return 1;
    }

    if (!environment.hold) {
        environment.flags |= (*pflag & except);
    }

    return 0;
}

int fe_dec_testexcept(int except)
{
    return int(environment.flags & except);
}

int fe_dec_getenv(fenv_t *penv)
{
    if (penv == nullptr) {
        return 1;
    }

    *penv = environment;

    return 0;
}

int fe_dec_setenv(const fenv_t *penv)
{
    if (penv == nullptr) {
        return 1;
    }

    environment = *penv;

    return 0;
}

int fe_dec_holdexcept(fenv_t *penv)
{
    if (fe_dec_getenv(penv) != 0) {
        return 1;
    }

    fe_dec_clearexcept(FE_DEC_ALL_EXCEPT);

    environment.hold = true;

    return 0;
}

int fe_dec_updateenv(const fenv_t *penv)
{
    fexcept_t saved_flags = 0;

    if (fe_dec_getexceptflag(&saved_flags, FE_DEC_ALL_EXCEPT) != 0) {
        return 1;
    }

    if (fe_dec_setenv(penv) != 0) {
        return 1;
    }

    return fe_dec_raiseexcept(saved_flags);
}

int fe_dec_getround()
{
    return environment.round;
}

int fe_dec_setround(int round)
{
    switch (round)
    {
        case FE_DEC_DOWNWARD:
        case FE_DEC_TONEAREST:
        case FE_DEC_TONEARESTFROMZERO:
        case FE_DEC_TOWARD_ZERO:
        case FE_DEC_UPWARD:
            environment.round = round;
            return 0;
    };

	return 1;
}


exception::exception(fexcept_t flags)
:   m_flags(flags)
{
    if ((m_flags & FE_DEC_DIVBYZERO) != 0) {
        m_what += "divide by zero";
    } 

    if ((m_flags & FE_DEC_OVERFLOW) != 0) {
        if (!m_what.empty()) { m_what += ", "; }
        m_what += "overflow";
    }

    if ((m_flags & FE_DEC_UNDERFLOW) != 0) {
        if (!m_what.empty()) { m_what += ", "; }
        m_what += "underflow";
    } 

    if ((m_flags & FE_DEC_INEXACT) != 0) {
        if (!m_what.empty()) { m_what += ", "; }
        m_what += "inexact";
    } 

    if ((m_flags & FE_DEC_INVALID) != 0) {
        if (!m_what.empty()) { m_what += ", "; }
        m_what += "invalid";
    } 
}

void set_exceptions(int except) noexcept
{
    environment.exceptions |= except;
    fe_dec_clearexcept(except);
}

void clear_exceptions(int except) noexcept
{
    environment.exceptions &= ~except;
}

int get_exceptions() noexcept
{
    return int(environment.exceptions);
}

void check_exceptions()
{
    int raised_exceptions = int(environment.flags & environment.exceptions);

    if (raised_exceptions != 0) {
        fe_dec_clearexcept(raised_exceptions);
        throw std::decimal::exception(raised_exceptions);
    }
}

// 32 ------------------------------------------------

void operator_32bit::add(BID_UINT32& lhs, BID_UINT32 rhs) {
    lhs = bid32_add(lhs, rhs, environment.round, environment_flags()); 
}

void operator_32bit::sub(BID_UINT32& lhs, BID_UINT32 rhs) {
    lhs = bid32_sub(lhs, rhs, environment.round, environment_flags()); 
}

void operator_32bit::mul(BID_UINT32& lhs, BID_UINT32 rhs) {
    lhs = bid32_mul(lhs, rhs, environment.round, environment_flags()); 
}

void operator_32bit::div(BID_UINT32& lhs, BID_UINT32 rhs) {
    lhs = bid32_div(lhs, rhs, environment.round, environment_flags()); 
}

bool operator_32bit::equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_equal(lhs, rhs, environment_flags()); 
}

bool operator_32bit::not_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_not_equal(lhs, rhs, environment_flags()); 
}

bool operator_32bit::less(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_less(lhs, rhs, environment_flags()); 
}

bool operator_32bit::less_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_less_equal(lhs, rhs, environment_flags()); 
}

bool operator_32bit::greater(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_greater(lhs, rhs, environment_flags()); 
}

bool operator_32bit::greater_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
    return bid32_quiet_greater_equal(lhs, rhs, environment_flags()); 
}

BID_UINT32 operator_32bit::resize(decimal32 value) {
    return value.value();
}

BID_UINT32 operator_32bit::resize(decimal64 value) {
    return bid64_to_bid32(value.value(), environment.round, environment_flags());
}

BID_UINT32 operator_32bit::resize(decimal128 value) {
    return bid128_to_bid32(value.value(), environment.round, environment_flags());
}

BID_UINT32 operator_32bit::resize(int value) {
    return bid32_from_int32(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(unsigned int value) {
    return bid32_from_uint32(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(long value) {
    return bid32_from_int64(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(unsigned long value) {
    return bid32_from_uint64(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(long long value) {
    return bid32_from_int64(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(unsigned long long value) {
    return bid64_to_bid32(value, environment.round, environment_flags());    
}

BID_UINT32 operator_32bit::resize(float value) {
    return binary32_to_bid32(value, environment.round, environment_flags());
}

BID_UINT32 operator_32bit::resize(double value) {
    return binary64_to_bid32(value, environment.round, environment_flags());
}

BID_UINT32 operator_32bit::resize(long double value) {
    return binary80_to_bid32(value, environment.round, environment_flags());
}

// 64 ------------------------------------------------

void operator_64bit::add(BID_UINT64& lhs, BID_UINT64 rhs) {
    lhs = bid64_add(lhs, rhs, environment.round, environment_flags());
    check_exceptions(); 
}

void operator_64bit::sub(BID_UINT64& lhs, BID_UINT64 rhs) {
    lhs = bid64_sub(lhs, rhs, environment.round, environment_flags());
    check_exceptions();
}

void operator_64bit::mul(BID_UINT64& lhs, BID_UINT64 rhs) {
    lhs = bid64_mul(lhs, rhs, environment.round, environment_flags());
    check_exceptions();
}

void operator_64bit::div(BID_UINT64& lhs, BID_UINT64 rhs) {
    lhs = bid64_div(lhs, rhs, environment.round, environment_flags());
    check_exceptions();
}

bool operator_64bit::equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_equal(lhs, rhs, environment_flags());
}

bool operator_64bit::not_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_not_equal(lhs, rhs, environment_flags()); 
}

bool operator_64bit::less(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_less(lhs, rhs, environment_flags()); 
}

bool operator_64bit::less_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_less_equal(lhs, rhs, environment_flags()); 
}

bool operator_64bit::greater(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_greater(lhs, rhs, environment_flags()); 
}

bool operator_64bit::greater_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
    return bid64_quiet_greater_equal(lhs, rhs, environment_flags()); 
}

BID_UINT64 operator_64bit::resize(decimal32 value) {
    return bid32_to_bid64(value.value(), environment_flags());
}

BID_UINT64 operator_64bit::resize(decimal64 value) {
    return value.value();
}

BID_UINT64 operator_64bit::resize(decimal128 value) {
    return bid128_to_bid64(value.value(), environment.round, environment_flags());
}

BID_UINT64 operator_64bit::resize(int value) {
    return bid64_from_int32(value);
}

BID_UINT64 operator_64bit::resize(unsigned int value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(long value) {
    
    return bid64_from_int64(value, environment.round, environment_flags());
}

BID_UINT64 operator_64bit::resize(unsigned long value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(long long value) {
    return bid64_from_int64(value, environment.round, environment_flags());
}

BID_UINT64 operator_64bit::resize(unsigned long long value) {
    return bid64_from_uint32(value);
}

BID_UINT64 operator_64bit::resize(float value) {
    return binary32_to_bid64(value, environment.round, environment_flags());
}

BID_UINT64 operator_64bit::resize(double value) {
    return binary64_to_bid64(value, environment.round, environment_flags());
}

BID_UINT64 operator_64bit::resize(long double value) {
    return binary80_to_bid64(value, environment.round, environment_flags());
}

// 128 -----------------------------------------------

void operator_128bit::add(BID_UINT128& lhs, BID_UINT128 rhs) {
    lhs = bid128_add(lhs, rhs, environment.round, environment_flags()); 
}

void operator_128bit::sub(BID_UINT128& lhs, BID_UINT128 rhs) {
    lhs = bid128_sub(lhs, rhs, environment.round, environment_flags()); 
}

void operator_128bit::mul(BID_UINT128& lhs, BID_UINT128 rhs) {
    lhs = bid128_mul(lhs, rhs, environment.round, environment_flags()); 
}

void operator_128bit::div(BID_UINT128& lhs, BID_UINT128 rhs) {
    lhs = bid128_div(lhs, rhs, environment.round, environment_flags()); 
}

bool operator_128bit::equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_equal(lhs, rhs, environment_flags()); 
}

bool operator_128bit::not_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_not_equal(lhs, rhs, environment_flags()); 
}

bool operator_128bit::less(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_less(lhs, rhs, environment_flags()); 
}

bool operator_128bit::less_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_less_equal(lhs, rhs, environment_flags()); 
}

bool operator_128bit::greater(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_greater(lhs, rhs, environment_flags()); 
}

bool operator_128bit::greater_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
    return bid128_quiet_greater_equal(lhs, rhs, environment_flags()); 
}

BID_UINT128 operator_128bit::resize(decimal32 value) {
    return bid32_to_bid128(value.value(), environment_flags());
}

BID_UINT128 operator_128bit::resize(decimal64 value) {
    return bid64_to_bid128(value.value(), environment_flags());
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
    return binary32_to_bid128(value, environment.round, environment_flags());
}

BID_UINT128 operator_128bit::resize(double value) {
    return binary64_to_bid128(value, environment.round, environment_flags());
}

BID_UINT128 operator_128bit::resize(long double value) {
    return binary80_to_bid128(value, environment.round, environment_flags());
}

// ---------------------------------------------------------

BID_UINT32 compound_result_traits_32::resize(BID_UINT32 value) {
    return value;
}

BID_UINT32 compound_result_traits_32::resize(BID_UINT64 value) {
    return bid64_to_bid32(value, environment.round, environment_flags());
}

BID_UINT32 compound_result_traits_32::resize(BID_UINT128 value) {
    return bid128_to_bid32(value, environment.round, environment_flags());
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT32 value) {
    return bid32_to_bid64(value, environment_flags());
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT64 value) {
    return value;
}

BID_UINT64 compound_result_traits_64::resize(BID_UINT128 value) {
    return bid128_to_bid64(value, environment.round, environment_flags());
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT32 value) {
    return bid32_to_bid128(value, environment_flags());
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT64 value) {
    return bid64_to_bid128(value, environment_flags());
}

BID_UINT128 compound_result_traits_128::resize(BID_UINT128 value) {
    return value;
}

// ---------------------------------------------------------

template<typename DecimalType, typename InputType>
DecimalType make_decimal(InputType coeff, int exponent)
{
    DecimalType multiplier;
    DecimalType power{1};
    DecimalType value{coeff};

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

    auto result = value * power;

    check_exceptions();

    return result;
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
    auto result = bid32_to_binary32(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
}
 

float decimal64_to_float (decimal64 d)
{
    auto result = bid64_to_binary32(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
}

float decimal128_to_float(decimal128 d)
{
    auto result = bid128_to_binary32(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
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
    auto result = bid32_to_binary64(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
}

double decimal64_to_double (decimal64 d)
{
    auto result = bid64_to_binary64(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
}

double decimal128_to_double(decimal128 d)
{
    auto result = bid128_to_binary64(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
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
    auto result = bid32_to_binary80(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
}

long double decimal64_to_long_double(decimal64 d)
{
    auto result = bid64_to_binary80(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
} 

long double decimal128_to_long_double(decimal128 d)
{
    auto result = bid128_to_binary80(d.value(), environment.round, environment_flags());
    check_exceptions();
    return result;
} 

long double decimal_to_long_double(decimal32 d)
{
    return decimal32_to_long_double(d);
}

long double decimal_to_long_double(decimal64 d)
{
    return decimal64_to_long_double(d);
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

decimal32::decimal32(decimal64 d64)
:   m_value(bid64_to_bid32(d64.value(), environment.round, environment_flags()))
{
    check_exceptions();
}

decimal32::decimal32(decimal128 d128)
:   m_value(bid128_to_bid32(d128.value(), environment.round, environment_flags()))
{
    check_exceptions();
}

decimal32::decimal32(float r)
:   m_value(binary32_to_bid32(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(double r)
:   m_value(binary64_to_bid32(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(long double r)
:   m_value(binary80_to_bid32(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_128_bit_decimal);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    static_assert(std::numeric_limits<long double>::digits10 == 18); // 80 bit Intel extended precision
    check_exceptions();
}

decimal32::decimal32(int r)
:   m_value(bid32_from_int32(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(unsigned int r)
:   m_value(bid32_from_uint32(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(long r)
:   m_value(bid32_from_int64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(unsigned long r)
:   m_value(bid32_from_uint64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(long long r)
:   m_value(bid32_from_int64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal32::decimal32(unsigned long long r)
:   m_value(bid32_from_uint64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal32::operator long long() const
{
    auto result = bid32_to_int64_floor(m_value, environment_flags());
    check_exceptions();
    return result;
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
:   m_value(bid64_from_int64(0, environment.round, environment_flags()))
{
    check_exceptions();
}
    
decimal64::decimal64(decimal32 d32)
:   m_value(bid32_to_bid64(d32.value(), environment_flags()))
{
    check_exceptions();
}

decimal64::decimal64(decimal128 d128)
:   m_value(bid128_to_bid64(d128.value(), environment.round, environment_flags()))
{
    check_exceptions();
} 

decimal64::decimal64(float r)
:   m_value(binary32_to_bid64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
} 

decimal64::decimal64(double r)
:   m_value(binary64_to_bid64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
} 

decimal64::decimal64(long double r)
:   m_value(binary80_to_bid64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_128_bit_decimal);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    static_assert(std::numeric_limits<long double>::digits10 == 18); // 80 bit Intel extended precision
    check_exceptions();
}
    
decimal64::decimal64(int r)
:   m_value(bid64_from_int32(r))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal64::decimal64(unsigned int r)
:   m_value(bid64_from_uint32(r))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal64::decimal64(long r)
:   m_value(bid64_from_int64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal64::decimal64(unsigned long r)
:   m_value(bid64_from_uint64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
} 

decimal64::decimal64(long long r)
:   m_value(bid64_from_int64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
} 

decimal64::decimal64(unsigned long long r)
:   m_value(bid64_from_uint64(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}
    
decimal64::operator long long() const
{
    auto result = bid64_to_int64_floor(m_value, environment_flags());
    check_exceptions();
    return result;
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
    check_exceptions();
}
    
decimal128::decimal128(decimal32 d32)
:   m_value(bid32_to_bid128(d32.value(), environment_flags()))
{
    check_exceptions();
}

decimal128::decimal128(decimal64 d64)
:   m_value(bid64_to_bid128(d64.value(), environment_flags()))
{
    check_exceptions();
} 

decimal128::decimal128(float r)
:   m_value(binary32_to_bid128(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal128::decimal128(double r)
:   m_value(binary64_to_bid128(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
} 

decimal128::decimal128(long double r)
:   m_value(binary80_to_bid128(r, environment.round, environment_flags()))
{
    static_assert(sizeof(r) == bytes_in_128_bit_decimal);
    // NOLINTNEXTLINE(cppcoreguidelines-avoid-magic-numbers,readability-magic-numbers)
    static_assert(std::numeric_limits<long double>::digits10 == 18); // 80 bit Intel extended precision
    check_exceptions();
}

decimal128::decimal128(int r)
:   m_value(bid128_from_int32(r))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
}

decimal128::decimal128(unsigned int r)
:   m_value(bid128_from_uint32(r))
{
    static_assert(sizeof(r) == bytes_in_32_bit_decimal);
    check_exceptions();
} 

decimal128::decimal128(long r)
:   m_value(bid128_from_int64(r))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal128::decimal128(unsigned long r)
:   m_value(bid128_from_uint64(r))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal128::decimal128(long long r)
:   m_value(bid128_from_int64(r))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal128::decimal128(unsigned long long r)
:   m_value(bid128_from_uint64(r))
{
    static_assert(sizeof(r) == bytes_in_64_bit_decimal);
    check_exceptions();
}

decimal128::operator long long() const
{
    auto result = bid128_to_int64_floor(m_value, environment_flags());
    check_exceptions();
    return result;
}

decimal128::operator float() const
{
    return decimal_to_float(*this);
}

decimal128::operator double() const
{
    return decimal_to_double(*this);
}

decimal128::operator long double() const
{
    return decimal_to_long_double(*this);
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
