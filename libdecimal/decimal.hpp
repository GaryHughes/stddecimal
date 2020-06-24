#include <iosfwd>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_conf.h>
#include <IntelRDFPMathLib20U2/LIBRARY/src/bid_functions.h>

namespace std::decimal
{

class decimal32;
class decimal64;
class decimal128;


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
    // TODO - integral types
    
    decimal32& operator-=(decimal32 rhs);
    decimal32& operator-=(decimal64 rhs);
    decimal32& operator-=(decimal128 rhs);
    // TODO - integral types
    
    decimal32& operator*=(decimal32 rhs);
    decimal32& operator*=(decimal64 rhs);
    decimal32& operator*=(decimal128 rhs);
    // TODO - integral types
    
    decimal32& operator/=(decimal32 rhs);
    decimal32& operator/=(decimal64 rhs);
    decimal32& operator/=(decimal128 rhs);
    // TODO - integral types

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
    // TODO - integral types

    decimal64& operator-=(decimal32 rhs);
    decimal64& operator-=(decimal64 rhs);
    decimal64& operator-=(decimal128 rhs);
    // TODO - integral types

    decimal64& operator*=(decimal32 rhs); 
    decimal64& operator*=(decimal64 rhs); 
    decimal64& operator*=(decimal128 rhs);
    // TODO - integral types
    
    decimal64& operator/=(decimal32 rhs);
    decimal64& operator/=(decimal64 rhs);
    decimal64& operator/=(decimal128 rhs);
    // TODO - integral types

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
    // TODO - integral types

    decimal128& operator-=(decimal32 rhs);
    decimal128& operator-=(decimal64 rhs);
    decimal128& operator-=(decimal128 rhs);
    // TODO - integral types

    decimal128& operator*=(decimal32 rhs); 
    decimal128& operator*=(decimal64 rhs); 
    decimal128& operator*=(decimal128 rhs);
    // TODO - integral types
    
    decimal128& operator/=(decimal32 rhs);
    decimal128& operator/=(decimal64 rhs);
    decimal128& operator/=(decimal128 rhs);
    // TODO - integral types

    explicit decimal128(value_type value)
    :   m_value(value)
    {
    }

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



// - if one or both of the parameters of the overloaded operator is decimal128, then the return type is decimal128,
// - otherwise, if one or both of the parameters is decimal64, then the return type is decimal64,
// - otherwise, the return type is decimal32.

template<typename T> struct value_traits;
template<> struct value_traits<decimal32> { static constexpr int width() { return sizeof(decimal32::value_type) * 8; }  };
template<> struct value_traits<decimal64> { static constexpr int width() { return sizeof(decimal64::value_type) * 8; }  };
template<> struct value_traits<decimal128> { static constexpr int width() { return sizeof(decimal128::value_type) * 8; }  };
template<> struct value_traits<int> { static constexpr int width() { return sizeof(int) * 8; }  };
template<> struct value_traits<unsigned int> { static constexpr int width() { return sizeof(unsigned int) * 8; }  };
template<> struct value_traits<long> { static constexpr int width() { return sizeof(long) * 8; }  };
template<> struct value_traits<unsigned long> { static constexpr int width() { return sizeof(unsigned long) * 8; }  };
template<> struct value_traits<long long> { static constexpr int width() { return sizeof(long long) * 8; }  };
template<> struct value_traits<unsigned long long> { static constexpr int width() { return sizeof(unsigned long long) * 8; }  };

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

    static result_type add(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid32_add(lhs, rhs, round_mode, &flags)); 
    }

    static result_type sub(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid32_sub(lhs, rhs, round_mode, &flags)); 
    }

    static result_type mul(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid32_mul(lhs, rhs, round_mode, &flags)); 
    }

    static result_type div(BID_UINT32 lhs, BID_UINT32 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid32_div(lhs, rhs, round_mode, &flags)); 
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
	
    static result_type add(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid64_add(lhs, rhs, round_mode, &flags)); 
    }

    static result_type sub(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid64_sub(lhs, rhs, round_mode, &flags)); 
    }

    static result_type mul(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid64_mul(lhs, rhs, round_mode, &flags)); 
    }

    static result_type div(BID_UINT64 lhs, BID_UINT64 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid64_div(lhs, rhs, round_mode, &flags)); 
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

    static result_type add(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid128_add(lhs, rhs, round_mode, &flags)); 
    }

    static result_type sub(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid128_sub(lhs, rhs, round_mode, &flags)); 
    }

    static result_type mul(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid128_mul(lhs, rhs, round_mode, &flags)); 
    }

    static result_type div(BID_UINT128 lhs, BID_UINT128 rhs) {
        _IDEC_flags flags = 0;
        return result_type(bid128_div(lhs, rhs, round_mode, &flags)); 
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
    return traits::add(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator-(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>; 
    return traits::sub(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator*(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::mul(traits::promote(lhs), traits::promote(rhs)); 
}

template<typename LHS, typename RHS>
typename operator_traits<value_traits<LHS>::width(), value_traits<RHS>::width()>::result_type operator/(LHS lhs, RHS rhs)
{ 
    using traits = operator_traits<value_traits<decltype(lhs)>::width(), value_traits<decltype(rhs)>::width()>;
    return traits::div(traits::promote(lhs), traits::promote(rhs)); 
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




bool operator<=(decimal32 lhs, decimal32 rhs); 
bool operator<=(decimal64 lhs, decimal32 rhs); 
bool operator<=(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator<=(decimal32 lhs, decimal64 rhs); 
bool operator<=(decimal64 lhs, decimal64 rhs); 
bool operator<=(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator<=(decimal32 lhs, decimal128 rhs);
bool operator<=(decimal64 lhs, decimal128 rhs);
bool operator<=(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

bool operator>(decimal32 lhs, decimal32 rhs); 
bool operator>(decimal64 lhs, decimal32 rhs); 
bool operator>(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator>(decimal32 lhs, decimal64 rhs); 
bool operator>(decimal64 lhs, decimal64 rhs); 
bool operator>(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator>(decimal32 lhs, decimal128 rhs);
bool operator>(decimal64 lhs, decimal128 rhs);
bool operator>(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

bool operator>=(decimal32 lhs, decimal32 rhs); 
bool operator>=(decimal64 lhs, decimal32 rhs); 
bool operator>=(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator>=(decimal32 lhs, decimal64 rhs); 
bool operator>=(decimal64 lhs, decimal64 rhs); 
bool operator>=(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator>=(decimal32 lhs, decimal128 rhs);
bool operator>=(decimal64 lhs, decimal128 rhs);
bool operator>=(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 


// 3.2.10 Formatted input:
template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal32 & d) { return is; }

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal64 & d) { return is; }

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal128 & d) { return is; }

// 3.2.11 Formatted output:
template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal32 d) { return os; }

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal64 d) { return os; };

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal128 d) { return os; }

} // namespace std::decimal