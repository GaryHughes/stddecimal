#ifndef stddecimal_libdecimal_decimal_hpp
#define stddecimal_libdecimal_decimal_hpp

#include <ios>
#include <exception>
#include <string>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_conf.h>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_functions.h>

namespace std::decimal
{

// 3.5 Additions to <cfenv> and <fenv.h>

constexpr int FE_DEC_TONEAREST = BID_ROUNDING_TO_NEAREST;
constexpr int FE_DEC_DOWNWARD = BID_ROUNDING_DOWN;
constexpr int FE_DEC_UPWARD = BID_ROUNDING_UP;
constexpr int FE_DEC_TOWARD_ZERO = BID_ROUNDING_TO_ZERO;
constexpr int FE_DEC_TONEARESTFROMZERO = BID_ROUNDING_TIES_AWAY;

// There is no mention of changes to exception state in the standard so I am assuming that the floating point and decimal operations 
// would share a single exception state. This implementation doesn't really want to affect the compiler runtime state so we need to 
// supply our own. We need to redefine the exception constants because their values are implementation defined, add _DEC_ to the names 
// as well as placing them in the std::decimal namespace to avoid any clashes or confusion.
using fexcept_t = int;

constexpr fexcept_t FE_DEC_DIVBYZERO = BID_ZERO_DIVIDE_EXCEPTION;
constexpr fexcept_t FE_DEC_INEXACT = BID_INEXACT_EXCEPTION;
constexpr fexcept_t FE_DEC_INVALID = BID_INVALID_EXCEPTION;
constexpr fexcept_t FE_DEC_OVERFLOW = BID_OVERFLOW_EXCEPTION;
constexpr fexcept_t FE_DEC_UNDERFLOW = BID_UNDERFLOW_EXCEPTION;
constexpr fexcept_t FE_DEC_ALL_EXCEPT = FE_DEC_DIVBYZERO | 
                                        FE_DEC_INEXACT | 
                                        FE_DEC_INVALID | 
                                        FE_DEC_OVERFLOW | 
                                        FE_DEC_UNDERFLOW;

// NB: Environment state is per thread.
struct fenv_t
{
    int round;
    unsigned int flags;
    bool hold;
    unsigned int exceptions;
};

// Rename the global floating point environment functions by adding _dec_ to the names so there is no ambiguity and they
// match the decimal specific fe_dec_getround and fe_dec_setround.

// Clears the specified floating-point status flags
// 0​ if all indicated exceptions were successfully cleared or if excepts is zero. Returns a non-zero value on error.
int fe_dec_clearexcept(int except);

// Raises the specified floating-point exceptions 
// ​0​ if all listed exceptions were raised, non-zero value otherwise.
int fe_dec_raiseexcept(int except);

// Copies the state of the specified floating-point status flags from or to the floating-point environment
// ​0​ on success, non-zero otherwise.
int fe_dec_setexceptflag(const fexcept_t *pflag, int except);
int fe_dec_getexceptflag(fexcept_t *pflag, int except);

// Determines which of the specified floating-point status flags are set
// Returns: Bitwise OR of the floating-point exception macros that are both included in excepts and correspond to floating-point exceptions currently set.
int fe_dec_testexcept(int except);

// Attempts to store the status of the floating-point environment in the object pointed to by envp.
// ​0​ on success, non-zero otherwise.
int fe_dec_getenv(fenv_t *penv);

// Attempts to establish the floating-point environment from the object pointed to by envp. 
// ​0​ on success, non-zero otherwise.
int fe_dec_setenv(const fenv_t *penv);

// Saves the environment, clears all status flags and ignores all future errors
// ​0​ on success, non-zero otherwise.
int fe_dec_holdexcept(fenv_t *penv);

// restores the floating-point environment and raises the previously raise exceptions 
// 0​ on success, non-zero otherwise.
int fe_dec_updateenv(const fenv_t *penv);

// These are additions for decimal. Unlike the exception flags they don't overlap with the regular floating point counterparts.

// Gets the current rounding direction for decimal floating-point operations.
int fe_dec_getround();

// Establishes round as the rounding direction for decimal floating-point operations. If round is not equal to the value of a DFP 
// rounding direction macro, the rounding direction is not changed.
// Returns: a zero value if and only if the argument is equal to one of the rounding direction macros
int fe_dec_setround(int round);


// Extensions

class exception : public std::exception
{
public:

    exception(fexcept_t flags);
    constexpr fexcept_t flags() const { return m_flags; }
    const char* what() const noexcept override { return m_what.c_str(); }

private:

    fexcept_t m_flags;
    std::string m_what;

};

// Throw a C++ exception whenever an exception in the except mask is raised. This will prevent the specified
// exceptions from being set in the environment flags, other exceptions will be unnaffected.
// This also clears these exceptions from the environment flags if they are set.
// Any operation involving the decimal types may require multiple calls to the underlying Intel library, the
// exception state will only be checked at the end of the sequence of operations so the exception flags may
// have multiple exception flags set. This allows all the exceptions to be communicated to the caller but 
// there is no ordering information available which is atleast consistent with the fe_dec* api.
void set_exceptions(int except) noexcept;
// Disable C++ exceptions for the exceptions in the except mask.
void clear_exceptions(int except) noexcept;
// Return the current exception mask.
int get_exceptions() noexcept;
// If any exceptions have been raised in the environment flags then throw a C++ std::decimal::exception.
// This is primarily for internal use but can be called explicitly if it is not desirable to use set_exceptions in
// some circumstances. 
void check_exceptions();


class decimal32;
class decimal64;
class decimal128;

// - if one or both of the parameters of the overloaded operator is decimal128, then the return type is decimal128,
// - otherwise, if one or both of the parameters is decimal64, then the return type is decimal64,
// - otherwise, the return type is decimal32.

template<typename T> struct value_traits;
template<> struct value_traits<decimal32> { static constexpr int width() { return sizeof(BID_UINT32) * 8; }  };
template<> struct value_traits<decimal64> { static constexpr int width() { return sizeof(BID_UINT64) * 8; }  };
template<> struct value_traits<decimal128> { static constexpr int width() { return sizeof(BID_UINT128) * 8; }  };
template<> struct value_traits<BID_UINT128> { static constexpr int width() { return sizeof(BID_UINT128) * 8; }  };
template<> struct value_traits<int> { static constexpr int width() { static_assert(sizeof(int) == 4); return sizeof(int) * 8; }  };
template<> struct value_traits<unsigned int> { static constexpr int width() { static_assert(sizeof(int) == 4); return sizeof(unsigned int) * 8; }  };
template<> struct value_traits<long> { static constexpr int width() { static_assert(sizeof(long) == 8); return sizeof(long) * 8; }  };
template<> struct value_traits<unsigned long> { static constexpr int width() { static_assert(sizeof(unsigned long) == 8); return sizeof(unsigned long) * 8; }  };
template<> struct value_traits<long long> { static constexpr int width() { static_assert(sizeof(long long) == 8); return sizeof(long long) * 8; }  };
template<> struct value_traits<unsigned long long> { static constexpr int width() { static_assert(sizeof(unsigned long long) == 8); return sizeof(unsigned long long) * 8; }  };
template<> struct value_traits<float> { static constexpr int width() { static_assert(sizeof(float) == 4); return sizeof(float) * 8; }  };
template<> struct value_traits<double> { static constexpr int width() { static_assert(sizeof(double) == 8); return sizeof(double) * 8; }  };
template<> struct value_traits<long double> { static constexpr int width() { static_assert(sizeof(long double) == 16); return sizeof(long double) * 8; }  };

struct operator_32bit {

    using binary_result_type = decimal32;

    static void add(BID_UINT32& lhs, BID_UINT32 rhs);
    static void sub(BID_UINT32& lhs, BID_UINT32 rhs);
    static void mul(BID_UINT32& lhs, BID_UINT32 rhs);
    static void div(BID_UINT32& lhs, BID_UINT32 rhs);
    static bool equal(BID_UINT32 lhs, BID_UINT32 rhs);
    static bool not_equal(BID_UINT32 lhs, BID_UINT32 rhs);
    static bool less(BID_UINT32 lhs, BID_UINT32 rhs);
    static bool less_equal(BID_UINT32 lhs, BID_UINT32 rhs);
    static bool greater(BID_UINT32 lhs, BID_UINT32 rhs);
    static bool greater_equal(BID_UINT32 lhs, BID_UINT32 rhs);
    static BID_UINT32 resize(decimal32 value);
    static BID_UINT32 resize(decimal64 value);
    static BID_UINT32 resize(decimal128 value);
    static BID_UINT32 resize(int value);
    static BID_UINT32 resize(unsigned int value);
    static BID_UINT32 resize(long value);
    static BID_UINT32 resize(unsigned long value);
    static BID_UINT32 resize(long long value);
    static BID_UINT32 resize(unsigned long long value);
    static BID_UINT32 resize(float value);
    static BID_UINT32 resize(double value);
    static BID_UINT32 resize(long double value);
};

struct operator_64bit {

    using binary_result_type = decimal64;

    static void add(BID_UINT64& lhs, BID_UINT64 rhs);
    static void sub(BID_UINT64& lhs, BID_UINT64 rhs);
    static void mul(BID_UINT64& lhs, BID_UINT64 rhs);
    static void div(BID_UINT64& lhs, BID_UINT64 rhs);
    static bool equal(BID_UINT64 lhs, BID_UINT64 rhs);
    static bool not_equal(BID_UINT64 lhs, BID_UINT64 rhs);
    static bool less(BID_UINT64 lhs, BID_UINT64 rhs);
    static bool less_equal(BID_UINT64 lhs, BID_UINT64 rhs);
    static bool greater(BID_UINT64 lhs, BID_UINT64 rhs);
    static bool greater_equal(BID_UINT64 lhs, BID_UINT64 rhs);
    static BID_UINT64 resize(decimal32 value);
    static BID_UINT64 resize(decimal64 value);
    static BID_UINT64 resize(decimal128 value);
    static BID_UINT64 resize(int value);
    static BID_UINT64 resize(unsigned int value);
    static BID_UINT64 resize(long value);
    static BID_UINT64 resize(unsigned long value);
    static BID_UINT64 resize(long long value);
    static BID_UINT64 resize(unsigned long long value);
    static BID_UINT64 resize(float value);
    static BID_UINT64 resize(double value);
    static BID_UINT64 resize(long double value);
};

struct operator_128bit {

    using binary_result_type = decimal128;

    static void add(BID_UINT128& lhs, BID_UINT128 rhs);
    static void sub(BID_UINT128& lhs, BID_UINT128 rhs);
    static void mul(BID_UINT128& lhs, BID_UINT128 rhs);
    static void div(BID_UINT128& lhs, BID_UINT128 rhs);
    static bool equal(BID_UINT128 lhs, BID_UINT128 rhs);
    static bool not_equal(BID_UINT128 lhs, BID_UINT128 rhs);
    static bool less(BID_UINT128 lhs, BID_UINT128 rhs);
    static bool less_equal(BID_UINT128 lhs, BID_UINT128 rhs);
    static bool greater(BID_UINT128 lhs, BID_UINT128 rhs);
    static bool greater_equal(BID_UINT128 lhs, BID_UINT128 rhs);
    static BID_UINT128 resize(decimal32 value);
    static BID_UINT128 resize(decimal64 value);
    static BID_UINT128 resize(decimal128 value);
    static BID_UINT128 resize(int value);
    static BID_UINT128 resize(unsigned int value);
    static BID_UINT128 resize(long value);
    static BID_UINT128 resize(unsigned long value);
    static BID_UINT128 resize(long long value);
    static BID_UINT128 resize(unsigned long long value);
    static BID_UINT128 resize(float value);
    static BID_UINT128 resize(double value);
    static BID_UINT128 resize(long double value);
};

template<int lhs, int rhs> struct operator_traits;
template<> struct operator_traits<32,  32>  : public operator_32bit {}; 
template<> struct operator_traits<32,  64>  : public operator_64bit {};
template<> struct operator_traits<64,  32>  : public operator_64bit {};
template<> struct operator_traits<64,  64>  : public operator_64bit {};
template<> struct operator_traits<32,  128> : public operator_128bit {};
template<> struct operator_traits<64,  128> : public operator_128bit {};
template<> struct operator_traits<128, 32>  : public operator_128bit {};
template<> struct operator_traits<128, 64>  : public operator_128bit {};
template<> struct operator_traits<128, 128> : public operator_128bit {};


struct compound_result_traits_32
{
    static BID_UINT32 resize(BID_UINT32 value);
    static BID_UINT32 resize(BID_UINT64 value);
    static BID_UINT32 resize(BID_UINT128 value);
};

struct compound_result_traits_64
{
    static BID_UINT64 resize(BID_UINT32 value);
    static BID_UINT64 resize(BID_UINT64 value);
    static BID_UINT64 resize(BID_UINT128 value);
};

struct compound_result_traits_128
{
    static BID_UINT128 resize(BID_UINT32 value);
    static BID_UINT128 resize(BID_UINT64 value);
    static BID_UINT128 resize(BID_UINT128 value);
};

template<int result> struct compound_result_traits;
template<> struct compound_result_traits<4> : public compound_result_traits_32 {};
template<> struct compound_result_traits<8> : public compound_result_traits_64 {};
template<> struct compound_result_traits<16> : public compound_result_traits_128 {};

class decimal32 final
{
public:

    using value_type = BID_UINT32;

    // 3.2.2.1 construct/copy/destroy: 
    decimal32();
    
    // 3.2.2.2 conversion from floating-point type: 
    explicit decimal32(decimal64 d64);
    explicit decimal32(decimal128 d128);
    explicit decimal32(float r);
    explicit decimal32(double r);
    explicit decimal32(long double r);

    // 3.2.2.3 conversion from integral type: 
    explicit decimal32(int z);
    explicit decimal32(unsigned int z);
    explicit decimal32(long z);
    explicit decimal32(unsigned long z); 
    explicit decimal32(long long z); 
    explicit decimal32(unsigned long long z);
    
    // 3.2.2.4 conversion to integral type: 
    explicit operator long long() const;
    explicit operator float() const;
    explicit operator double() const;
    explicit operator long double() const;
        
    // 3.2.2.5 increment and decrement operators: 
    decimal32& operator++();
    decimal32 operator++(int);
    decimal32& operator--();
    decimal32 operator--(int);
    
    // 3.2.2.6 compound assignment: 
    template<typename RHS>
    decimal32& operator+=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::add(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }
   
    template<typename RHS>
    decimal32& operator-=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::sub(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal32& operator*=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::mul(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal32& operator/=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::div(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;
   
};

class decimal64 final
{
public:

    using value_type = BID_UINT64;

    // 3.2.3.1 construct/copy/destroy: 
    decimal64();
    
    // 3.2.3.2 conversion from floating-point type: 
    explicit decimal64(decimal32 d32);
    explicit decimal64(decimal128 d128); 
    explicit decimal64(float r); 
    explicit decimal64(double r); 
    explicit decimal64(long double r);
    
    // 3.2.3.3 conversion from integral type: 
    explicit decimal64(int z);
    explicit decimal64(unsigned int z);
    explicit decimal64(long z);
    explicit decimal64(unsigned long z); 
    explicit decimal64(long long z); 
    explicit decimal64(unsigned long long z);
    
    // 3.2.3.4 conversion to integral type: 
    explicit operator long long() const;
    explicit operator float() const;
    explicit operator double() const;
    explicit operator long double() const;
    
    // 3.2.3.5 increment and decrement operators: 
    decimal64& operator++();
    decimal64 operator++(int);
    decimal64& operator--();
    decimal64 operator--(int);
    
    // 3.2.3.6 compound assignment: 
    template<typename RHS>
    decimal64& operator+=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::add(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }
   
    template<typename RHS>
    decimal64& operator-=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::sub(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal64& operator*=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::mul(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal64& operator/=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::div(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;

};

class decimal128 final
{
public:

    using value_type = BID_UINT128;

    // 3.2.4.1 construct/copy/destroy: 
    decimal128();
    
    // 3.2.4.2 conversion from floating-point type: 
    explicit decimal128(decimal32 d32);
    explicit decimal128(decimal64 d64);
    explicit decimal128(float r);
    explicit decimal128(double r); 
    explicit decimal128(long double r);
    
    // 3.2.4.3 conversion from integral type: 
    explicit decimal128(int z);
    explicit decimal128(unsigned int z); 
    explicit decimal128(long z);
    explicit decimal128(unsigned long z); 
    explicit decimal128(long long z); 
    explicit decimal128(unsigned long long z);
    
    // 3.2.4.4 conversion to integral type: 
    explicit operator long long() const;
    explicit operator float() const;
    explicit operator double() const;
    explicit operator long double() const;
    
    // 3.2.4.5 increment and decrement operators: 
    decimal128& operator++();
    decimal128 operator++(int);
    decimal128& operator--();
    decimal128 operator--(int);

    // 3.2.4.6 compound assignment:
    template<typename RHS>
    decimal128& operator+=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::add(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }
   
    template<typename RHS>
    decimal128& operator-=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::sub(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal128& operator*=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::mul(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    template<typename RHS>
    decimal128& operator/=(RHS rhs)
    {
        using traits = operator_traits<value_traits<value_type>::width(), value_traits<decltype(rhs)>::width()>;
        auto result = traits::resize(*this);
        traits::div(result, traits::resize(rhs));
        using value_traits = compound_result_traits<sizeof(m_value)>;
        value(value_traits::resize(result));
        check_exceptions();
        return *this;    
    }

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;

};

// 3.2.5 initialization from coefficient and exponent: 
//
// Returns an object of the appropriate decimal floating-point type with the value coeff x 10^exponent
// rounded as in IEEE-754, if necessary. If an overflow condition occurs, then the value of the macro 
// ERANGE is stored in errno. In cases where the desired coefficient is greater than ULLONG_MAX or less 
// than LLONG_MIN, it will be preferable to initialize an object of decimal floating-point type by 
// extracting its value from a string literal using one of the strtod functions or iostreams.
decimal32 make_decimal32(long long coeff, int exponent); 
decimal32 make_decimal32(unsigned long long coeff, int exponent);
decimal64 make_decimal64(long long coeff, int exponent);
decimal64 make_decimal64(unsigned long long coeff, int exponent);
decimal128 make_decimal128(long long coeff, int exponent); 
decimal128 make_decimal128(unsigned long long coeff, int exponent);

// 3.2.6 conversion to generic floating-point type:
//
// If std::numeric_limits<float>::is_iec559 == true, returns the result of the conversion of d to float, 
// performed as in IEEE 754-2008. Otherwise, the returned value is implementation-defined.
float decimal32_to_float(decimal32 d); 
float decimal64_to_float(decimal64 d); 
float decimal128_to_float(decimal128 d); 
float decimal_to_float(decimal32 d); 
float decimal_to_float(decimal64 d); 
float decimal_to_float(decimal128 d);
// If std::numeric_limits<double>::is_iec559 == true, returns the result of the conversion of d double, 
// performed as in IEEE 754-2008. Otherwise, the returned value is implementation-defined
double decimal32_to_double (decimal32 d); 
double decimal64_to_double (decimal64 d); 
double decimal128_to_double(decimal128 d); 
double decimal_to_double(decimal32 d); 
double decimal_to_double(decimal64 d); 
double decimal_to_double(decimal128 d);
// If std::numeric_limits<long double>::is_iec559 == true, returns the result of the conversion of d 
// to long double, performed as in IEEE754-2008. Otherwise, the returned value is implementation-defined
long double decimal32_to_long_double(decimal32 d); 
long double decimal64_to_long_double(decimal64 d); 
long double decimal128_to_long_double(decimal128 d); 
long double decimal_to_long_double(decimal32 d); 
long double decimal_to_long_double(decimal64 d); 
long double decimal_to_long_double(decimal128 d);

// 3.2.7 unary arithmetic operators:
//
// Adds lhs to 0, as in IEEE 754-2008, and returns the result.
decimal32 operator+(decimal32 lhs);
decimal64 operator+(decimal64 lhs);
decimal128 operator+(decimal128 lhs);
// Returns the result of inverting the sign of lhs.
decimal32 operator-(decimal32 lhs);
decimal64 operator-(decimal64 lhs);
decimal128 operator-(decimal128 lhs);

// 3.2.8 binary arithmetic operators:
template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::binary_result_type operator+(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::resize(lhs);
    traits::add(promoted_lhs, traits::resize(rhs)); 
    typename traits::binary_result_type result;
    result.value(promoted_lhs);
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::binary_result_type operator-(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::resize(lhs);
    traits::sub(promoted_lhs, traits::resize(rhs)); 
    typename traits::binary_result_type result;
    result.value(promoted_lhs);
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::binary_result_type operator*(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::resize(lhs);
    traits::mul(promoted_lhs, traits::resize(rhs)); 
    typename traits::binary_result_type result;
    result.value(promoted_lhs);
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::binary_result_type operator/(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::resize(lhs);
    traits::div(promoted_lhs, traits::resize(rhs)); 
    typename traits::binary_result_type result;
    result.value(promoted_lhs);
    check_exceptions();
    return result;
}

// 3.2.9 comparison operators:

template<typename LHS, typename RHS>
bool operator==(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::equal(traits::resize(lhs), traits::resize(rhs));
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
bool operator!=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::not_equal(traits::resize(lhs), traits::resize(rhs)); 
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
bool operator<(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::less(traits::resize(lhs), traits::resize(rhs)); 
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
bool operator<=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::less_equal(traits::resize(lhs), traits::resize(rhs)); 
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
bool operator>(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::greater(traits::resize(lhs), traits::resize(rhs)); 
    check_exceptions();
    return result;
}

template<typename LHS, typename RHS>
bool operator>=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto result = traits::greater_equal(traits::resize(lhs), traits::resize(rhs)); 
    check_exceptions();
    return result;
}

// 3.2.10 Formatted input:
template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal32 & d) 
{
    // TODO
    std::string buffer;
    if (!(is >> buffer)) {
        return is;
    }
    
    fenv_t fpenv;
    
    if (fe_dec_getenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }
  
    auto value = bid32_from_string(const_cast<char*>(buffer.c_str()), fe_dec_getround(), &fpenv.flags);
  
    if (fe_dec_setenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }

    d.value(value);

    return is; 
}

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal64 & d) 
{
    // TODO 
    std::string buffer;
    if (!(is >> buffer)) {
        return is;
    }
    
    fenv_t fpenv;
    
    if (fe_dec_getenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }
  
    auto value = bid64_from_string(const_cast<char*>(buffer.c_str()), fe_dec_getround(), &fpenv.flags);
  
    if (fe_dec_setenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }

    d.value(value);

    return is; 
}

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal128 & d) 
{
    // TODO 
    std::string buffer;
    if (!(is >> buffer)) {
        return is;
    }
    
    fenv_t fpenv;
    
    if (fe_dec_getenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }
  
    auto value = bid128_from_string(const_cast<char*>(buffer.c_str()), fe_dec_getround(), &fpenv.flags);
  
    if (fe_dec_setenv(&fpenv)) {
        is.setstate(std::ios::failbit);
    }

    d.value(value);

    return is;  
}

// 3.2.11 Formatted output:
template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal32 d) 
{ 
    // TODO
    char buffer[256];
    _IDEC_flags flags = 0;
    bid32_to_string(buffer, d.value(), &flags);
    os << buffer;
    return os; 
}

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal64 d) 
{ 
    // TODO
    char buffer[256];
    _IDEC_flags flags = 0;
    bid64_to_string(buffer, d.value(), &flags);
    os << buffer;
    return os; 
};

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal128 d) 
{ 
    // TODO
    char buffer[256];
    _IDEC_flags flags = 0;
    bid128_to_string(buffer, d.value(), &flags);
    os << buffer;
    return os; 
}

} // namespace std::decimal

#endif