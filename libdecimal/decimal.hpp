#include <iosfwd>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_conf.h>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_functions.h>

namespace std::decimal
{

class decimal32;
class decimal64;
class decimal128;

// - if one or both of the parameters of the overloaded operator is decimal128, then the return type is decimal128,
// - otherwise, if one or both of the parameters is decimal64, then the return type is decimal64,
// - otherwise, the return type is decimal32.

template<typename T> struct value_traits;
template<> struct value_traits<decimal32> { static constexpr int width() { return 4 * 8; }  };
template<> struct value_traits<decimal64> { static constexpr int width() { return 8 * 8; }  };
template<> struct value_traits<decimal128> { static constexpr int width() { return 16 * 8; }  };
template<> struct value_traits<int> { static constexpr int width() { return sizeof(int) * 8; }  };
template<> struct value_traits<unsigned int> { static constexpr int width() { return sizeof(unsigned int) * 8; }  };
template<> struct value_traits<long> { static constexpr int width() { return sizeof(long) * 8; }  };
template<> struct value_traits<unsigned long> { static constexpr int width() { return sizeof(unsigned long) * 8; }  };
template<> struct value_traits<long long> { static constexpr int width() { return sizeof(long long) * 8; }  };
template<> struct value_traits<unsigned long long> { static constexpr int width() { return sizeof(unsigned long long) * 8; }  };


template<typename TargetType, typename SourceType>
TargetType resize(SourceType value);
template<> BID_UINT32 resize(BID_UINT32 value);
template<> BID_UINT32 resize(BID_UINT64 value);
template<> BID_UINT32 resize(BID_UINT128 value);
template<> BID_UINT32 resize(int value);
// template<> BID_UINT32 resize(unsigned int value); same as BID_UINT32
template<> BID_UINT32 resize(long value);
template<> BID_UINT32 resize(unsigned long value);
template<> BID_UINT32 resize(long long value);
// template<> BID_UINT32 resize(unsigned long long value); same as BID_UINT64




class decimal32 
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
    
    // 3.2.2.5 increment and decrement operators: 
    decimal32& operator++();
    decimal32 operator++(int);
    decimal32& operator--();
    decimal32 operator--(int);
    
    // 3.2.2.6 compound assignment: 
    decimal32& operator+=(decimal32 rhs);
    decimal32& operator+=(decimal64 rhs);
    decimal32& operator+=(decimal128 rhs);
    decimal32& operator+=(int z);
    decimal32& operator+=(unsigned int z);
    decimal32& operator+=(long z);
    decimal32& operator+=(unsigned long z); 
    decimal32& operator+=(long long z); 
    decimal32& operator+=(unsigned long long z);
    decimal32& operator+=(float z);
    decimal32& operator+=(double z);
    decimal32& operator+=(long double z);
    
    decimal32& operator-=(decimal32 rhs);
    decimal32& operator-=(decimal64 rhs);
    decimal32& operator-=(decimal128 rhs);
    decimal32& operator-=(int z);
    decimal32& operator-=(unsigned int z);
    decimal32& operator-=(long z);
    decimal32& operator-=(unsigned long z); 
    decimal32& operator-=(long long z); 
    decimal32& operator-=(unsigned long long z);
    decimal32& operator-=(float z);
    decimal32& operator-=(double z);
    decimal32& operator-=(long double z);
    
    decimal32& operator*=(decimal32 rhs);
    decimal32& operator*=(decimal64 rhs);
    decimal32& operator*=(decimal128 rhs);
    decimal32& operator*=(int z);
    decimal32& operator*=(unsigned int z);
    decimal32& operator*=(long z);
    decimal32& operator*=(unsigned long z); 
    decimal32& operator*=(long long z); 
    decimal32& operator*=(unsigned long long z);
    decimal32& operator*=(float z);
    decimal32& operator*=(double z);
    decimal32& operator*=(long double z);

    decimal32& operator/=(decimal32 rhs);
    decimal32& operator/=(decimal64 rhs);
    decimal32& operator/=(decimal128 rhs);
    decimal32& operator/=(int z);
    decimal32& operator/=(unsigned int z);
    decimal32& operator/=(long z);
    decimal32& operator/=(unsigned long z); 
    decimal32& operator/=(long long z); 
    decimal32& operator/=(unsigned long long z);
    decimal32& operator/=(float z);
    decimal32& operator/=(double z);
    decimal32& operator/=(long double z);

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;

    friend decimal64;
    friend decimal128;

};

class decimal64 
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
    
    // 3.2.3.5 increment and decrement operators: 
    decimal64& operator++();
    decimal64 operator++(int);
    decimal64& operator--();
    decimal64 operator--(int);
    
    // 3.2.3.6 compound assignment: 
    decimal64& operator+=(decimal32 rhs);
    decimal64& operator+=(decimal64 rhs);
    decimal64& operator+=(decimal128 rhs);
    decimal64& operator+=(int z);
    decimal64& operator+=(unsigned int z);
    decimal64& operator+=(long z);
    decimal64& operator+=(unsigned long z); 
    decimal64& operator+=(long long z); 
    decimal64& operator+=(unsigned long long z);
    decimal64& operator+=(float z);
    decimal64& operator+=(double z);
    decimal64& operator+=(long double z);

    decimal64& operator-=(decimal32 rhs);
    decimal64& operator-=(decimal64 rhs);
    decimal64& operator-=(decimal128 rhs);
    decimal64& operator-=(int z);
    decimal64& operator-=(unsigned int z);
    decimal64& operator-=(long z);
    decimal64& operator-=(unsigned long z); 
    decimal64& operator-=(long long z); 
    decimal64& operator-=(unsigned long long z);
    decimal64& operator-=(float z);
    decimal64& operator-=(double z);
    decimal64& operator-=(long double z);

    decimal64& operator*=(decimal32 rhs); 
    decimal64& operator*=(decimal64 rhs); 
    decimal64& operator*=(decimal128 rhs);
    decimal64& operator*=(int z);
    decimal64& operator*=(unsigned int z);
    decimal64& operator*=(long z);
    decimal64& operator*=(unsigned long z); 
    decimal64& operator*=(long long z); 
    decimal64& operator*=(unsigned long long z);
    decimal64& operator*=(float z);
    decimal64& operator*=(double z);
    decimal64& operator*=(long double z);
    
    decimal64& operator/=(decimal32 rhs);
    decimal64& operator/=(decimal64 rhs);
    decimal64& operator/=(decimal128 rhs);
    decimal64& operator/=(int z);
    decimal64& operator/=(unsigned int z);
    decimal64& operator/=(long z);
    decimal64& operator/=(unsigned long z); 
    decimal64& operator/=(long long z); 
    decimal64& operator/=(unsigned long long z);
    decimal64& operator/=(float z);
    decimal64& operator/=(double z);
    decimal64& operator/=(long double z);

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;

    friend decimal32;
    friend decimal128;

};

class decimal128 
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
    
    // 3.2.4.5 increment and decrement operators: 
    decimal128& operator++();
    decimal128 operator++(int);
    decimal128& operator--();
    decimal128 operator--(int);

    // 3.2.4.6 compound assignment:
    decimal128& operator+=(decimal32 rhs);
    decimal128& operator+=(decimal64 rhs);
    decimal128& operator+=(decimal128 rhs);
    decimal128& operator+=(int z);
    decimal128& operator+=(unsigned int z);
    decimal128& operator+=(long z);
    decimal128& operator+=(unsigned long z); 
    decimal128& operator+=(long long z); 
    decimal128& operator+=(unsigned long long z);
    decimal128& operator+=(float z);
    decimal128& operator+=(double z);
    decimal128& operator+=(long double z);

    decimal128& operator-=(decimal32 rhs);
    decimal128& operator-=(decimal64 rhs);
    decimal128& operator-=(decimal128 rhs);
    decimal128& operator-=(int z);
    decimal128& operator-=(unsigned int z);
    decimal128& operator-=(long z);
    decimal128& operator-=(unsigned long z); 
    decimal128& operator-=(long long z); 
    decimal128& operator-=(unsigned long long z);
    decimal128& operator-=(float z);
    decimal128& operator-=(double z);
    decimal128& operator-=(long double z);

    decimal128& operator*=(decimal32 rhs); 
    decimal128& operator*=(decimal64 rhs); 
    decimal128& operator*=(decimal128 rhs);
    decimal128& operator*=(int z);
    decimal128& operator*=(unsigned int z);
    decimal128& operator*=(long z);
    decimal128& operator*=(unsigned long z); 
    decimal128& operator*=(long long z); 
    decimal128& operator*=(unsigned long long z);
    decimal128& operator*=(float z);
    decimal128& operator*=(double z);
    decimal128& operator*=(long double z);
    
    decimal128& operator/=(decimal32 rhs);
    decimal128& operator/=(decimal64 rhs);
    decimal128& operator/=(decimal128 rhs);
    decimal128& operator/=(int z);
    decimal128& operator/=(unsigned int z);
    decimal128& operator/=(long z);
    decimal128& operator/=(unsigned long z); 
    decimal128& operator/=(long long z); 
    decimal128& operator/=(unsigned long long z);
    decimal128& operator/=(float z);
    decimal128& operator/=(double z);
    decimal128& operator/=(long double z);

    void value(value_type value) { m_value = value; }
    const value_type value() const { return m_value; }

private:

    value_type m_value;

    friend decimal32;
    friend decimal64;

};


// 3.2.5 initialization from coefficient and exponent: 
decimal32 make_decimal32(long long coeff, int exponent); 
decimal32 make_decimal32(unsigned long long coeff, int exponent);
decimal64 make_decimal64(long long coeff, int exponent);
decimal64 make_decimal64(unsigned long long coeff, int exponent);
decimal128 make_decimal128(long long coeff, int exponent); 
decimal128 make_decimal128(unsigned long long coeff, int exponent);

// 3.2.6 conversion to generic floating-point type: 
long double decimal32_to_long_double(decimal32 d); 
long double decimal64_to_long_double(decimal64 d); 
long double decimal128_to_long_double(decimal128 d); 
long double decimal_to_long_double(decimal32 d); 
long double decimal_to_long_double(decimal64 d); 
long double decimal_to_long_double(decimal128 d);

// 3.2.7 unary arithmetic operators: 
decimal32 operator+(decimal32 rhs); 
decimal64 operator+(decimal64 rhs); 
decimal128 operator+(decimal128 rhs); 
decimal32 operator-(decimal32 rhs); 
decimal64 operator-(decimal64 rhs); 
decimal128 operator-(decimal128 rhs);



const _IDEC_round round_mode = BID_ROUNDING_TO_NEAREST;

template<int lhs, int rhs> struct operator_traits;

struct operator_32bit {

    using result_type = decimal32;

    static BID_UINT32 promote(decimal32 d)  { return d.value(); }

    static BID_UINT32 promote(int d) { 
        _IDEC_flags flags = 0;
        return bid32_from_int32(d, round_mode, &flags); 
    }	

    static BID_UINT32 promote(unsigned int d) { 
        _IDEC_flags flags = 0;
        return bid32_from_uint32(d, round_mode, &flags); 
    }

    static BID_UINT32 promote(long d) {
        _IDEC_flags flags = 0;
        return bid32_from_int64(d, round_mode, &flags); 
    }	

    static BID_UINT32 promote(unsigned long d) {
        _IDEC_flags flags = 0;
        return bid32_from_uint64(d, round_mode, &flags); 
    }

    static BID_UINT32 promote(long long d) { 
        return 0; // TODO 
    }	

    static BID_UINT32 promote(unsigned long long d) { 
        return 0; // TODO
    }

    static void add(BID_UINT32& lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid32_add(lhs, rhs, round_mode, &flags); 
    }

    static void sub(BID_UINT32& lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid32_sub(lhs, rhs, round_mode, &flags); 
    }

    static void mul(BID_UINT32& lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid32_mul(lhs, rhs, round_mode, &flags); 
    }

    static void div(BID_UINT32& lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid32_div(lhs, rhs, round_mode, &flags); 
    }

    static bool equal(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_equal(lhs, rhs, &flags); 
    }

    static bool not_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_not_equal(lhs, rhs, &flags); 
    }

    static bool less(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_less(lhs, rhs, &flags); 
    }

    static bool less_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_less_equal(lhs, rhs, &flags); 
    }

    static bool greater(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_greater(lhs, rhs, &flags); 
    }

    static bool greater_equal(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return bid32_quiet_greater_equal(lhs, rhs, &flags); 
    }
};

struct operator_64bit {

    using result_type = decimal64;

    static BID_UINT64 promote(decimal64 d)  { return d.value(); }

    static BID_UINT64 promote(decimal32 d)  { 
        _IDEC_flags flags = 0;
        return bid32_to_bid64(d.value(), &flags);
    }

    static BID_UINT64 promote(int d) { 
        return bid64_from_int32(d); 
    }	

    static BID_UINT64 promote(unsigned int d) { 
        return bid64_from_uint32(d); 
    }

    static BID_UINT64 promote(long d) {
        _IDEC_flags flags = 0;
        return bid64_from_int64(d, round_mode, &flags); 
    }	

    static BID_UINT64 promote(unsigned long d) {
        _IDEC_flags flags = 0; 
        return bid64_from_uint64(d, round_mode, &flags); 
    }	

    static BID_UINT64 promote(long long d) { 
        return 0; // TODO 
    }	

    static BID_UINT64 promote(unsigned long long d) { 
        return 0; // TODO
    }

    static void add(BID_UINT64& lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid64_add(lhs, rhs, round_mode, &flags); 
    }

    static void sub(BID_UINT64& lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid64_sub(lhs, rhs, round_mode, &flags); 
    }

    static void mul(BID_UINT64& lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid64_mul(lhs, rhs, round_mode, &flags); 
    }

    static void div(BID_UINT64& lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid64_div(lhs, rhs, round_mode, &flags); 
    }

    static bool equal(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_equal(lhs, rhs, &flags); 
    }

    static bool not_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_not_equal(lhs, rhs, &flags); 
    }

    static bool less(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_less(lhs, rhs, &flags); 
    }

    static bool less_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_less_equal(lhs, rhs, &flags); 
    }

    static bool greater(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_greater(lhs, rhs, &flags); 
    }

    static bool greater_equal(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return bid64_quiet_greater_equal(lhs, rhs, &flags); 
    }
};

struct operator_128bit {

    using result_type = decimal128;

    static BID_UINT128 promote(decimal128 d) { return d.value(); }

    static BID_UINT128 promote(decimal64 d)  { 
        _IDEC_flags flags = 0;
        return bid64_to_bid128(d.value(), &flags);
    }

    static BID_UINT128 promote(decimal32 d)  { 
        _IDEC_flags flags = 0;
        return bid32_to_bid128(d.value(), &flags);
    }

    static BID_UINT128 promote(int d) { 
        return bid128_from_int32(d); 
    }	

    static BID_UINT128 promote(unsigned int d) { 
        return bid128_from_uint32(d); 
    }	

    static BID_UINT128 promote(long d) { 
        return bid128_from_int64(d); 
    }	

    static BID_UINT128 promote(unsigned long d) { 
        return bid128_from_uint64(d); 
    }	

    static BID_UINT128 promote(long long d) { 
        return { 0, 0 }; // TODO 
    }	

    static BID_UINT128 promote(unsigned long long d) { 
        return { 0, 0 }; // TODO
    }

    static void add(BID_UINT128& lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid128_add(lhs, rhs, round_mode, &flags); 
    }

    static void sub(BID_UINT128& lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid128_sub(lhs, rhs, round_mode, &flags); 
    }

    static void mul(BID_UINT128& lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid128_mul(lhs, rhs, round_mode, &flags); 
    }

    static void div(BID_UINT128& lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        lhs = bid128_div(lhs, rhs, round_mode, &flags); 
    }

    static bool equal(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_equal(lhs, rhs, &flags); 
    }

    static bool not_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_not_equal(lhs, rhs, &flags); 
    }

    static bool less(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_less(lhs, rhs, &flags); 
    }

    static bool less_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_less_equal(lhs, rhs, &flags); 
    }

    static bool greater(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_greater(lhs, rhs, &flags); 
    }

    static bool greater_equal(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return bid128_quiet_greater_equal(lhs, rhs, &flags); 
    }
};

template<> struct operator_traits<32,  32>  : public operator_32bit {}; 
template<> struct operator_traits<32,  64>  : public operator_64bit {};
template<> struct operator_traits<64,  32>  : public operator_64bit {};
template<> struct operator_traits<64,  64>  : public operator_64bit {};
template<> struct operator_traits<32,  128> : public operator_128bit {};
template<> struct operator_traits<64,  128> : public operator_128bit {};
template<> struct operator_traits<128, 32>  : public operator_128bit {};
template<> struct operator_traits<128, 64>  : public operator_128bit {};
template<> struct operator_traits<128, 128> : public operator_128bit {}; 



// 3.2.8 binary arithmetic operators:

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator+(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::promote(lhs);
    traits::add(promoted_lhs, traits::promote(rhs)); 
    typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type result;
    result.value(promoted_lhs);
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator-(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::promote(lhs);
    traits::sub(promoted_lhs, traits::promote(rhs)); 
    typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type result;
    result.value(promoted_lhs);
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator*(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::promote(lhs);
    traits::mul(promoted_lhs, traits::promote(rhs)); 
    typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type result;
    result.value(promoted_lhs);
    return result;
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator/(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    auto promoted_lhs = traits::promote(lhs);
    traits::div(promoted_lhs, traits::promote(rhs)); 
    typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type result;
    result.value(promoted_lhs);
    return result;
}

// 3.2.9 comparison operators:

template<typename LHS, typename RHS>
bool operator==(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::equal(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
bool operator!=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::not_equal(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
bool operator<(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::less(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
bool operator<=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::less_equal(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
bool operator>(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::greater(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
bool operator>=(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::greater_equal(traits::promote(lhs), traits::promote(rhs)); 
}

// 3.2.10 Formatted input:
template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal32 & d) { return is; }

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal64 & d) { return is; }

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal128 & d) { return is; }

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