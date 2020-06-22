#include <iosfwd>

namespace std::decimal
{

class decimal32;
class decimal64;
class decimal128;

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

// 3.2.8 binary arithmetic operators:
decimal32 operator+(decimal32 lhs, decimal32 rhs); 
decimal64 operator+(decimal64 lhs, decimal32 rhs); 
decimal128 operator+(decimal128 lhs, decimal32 rhs);
// TODO - lhs can be integral types 

decimal64 operator+(decimal32 lhs, decimal64 rhs); 
decimal64 operator+(decimal64 lhs, decimal64 rhs); 
decimal128 operator+(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

decimal128 operator+(decimal32 lhs, decimal128 rhs);
decimal128 operator+(decimal64 lhs, decimal128 rhs);
decimal128 operator+(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

decimal32 operator-(decimal32 lhs, decimal32 rhs); 
decimal64 operator-(decimal64 lhs, decimal32 rhs); 
decimal128 operator-(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

decimal64 operator-(decimal32 lhs, decimal64 rhs); 
decimal64 operator-(decimal64 lhs, decimal64 rhs); 
decimal128 operator-(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

decimal128 operator-(decimal32 lhs, decimal128 rhs);
decimal128 operator-(decimal64 lhs, decimal128 rhs);
decimal128 operator-(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

decimal32 operator*(decimal32 lhs, decimal32 rhs); 
decimal64 operator*(decimal64 lhs, decimal32 rhs);
decimal128 operator*(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types

decimal64 operator*(decimal32 lhs, decimal64 rhs);
decimal64 operator*(decimal64 lhs, decimal64 rhs);
decimal128 operator*(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

decimal128 operator*(decimal32 lhs, decimal128 rhs);
decimal128 operator*(decimal64 lhs, decimal128 rhs);
decimal128 operator*(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

decimal32 operator/(decimal32 lhs, decimal32 rhs); 
decimal64 operator/(decimal64 lhs, decimal32 rhs); 
decimal128 operator/(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

decimal64 operator/(decimal32 lhs, decimal64 rhs); 
decimal64 operator/(decimal64 lhs, decimal64 rhs); 
decimal128 operator/(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

decimal128 operator/(decimal32 lhs, decimal128 rhs);
decimal128 operator/(decimal64 lhs, decimal128 rhs);
decimal128 operator/(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 


// 3.2.9 comparison operators:
bool operator==(decimal32 lhs, decimal32 rhs); 
bool operator==(decimal64 lhs, decimal32 rhs); 
bool operator==(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator==(decimal32 lhs, decimal64 rhs); 
bool operator==(decimal64 lhs, decimal64 rhs); 
bool operator==(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator==(decimal32 lhs, decimal128 rhs);
bool operator==(decimal64 lhs, decimal128 rhs);
bool operator==(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

bool operator!=(decimal32 lhs, decimal32 rhs); 
bool operator!=(decimal64 lhs, decimal32 rhs); 
bool operator!=(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator!=(decimal32 lhs, decimal64 rhs); 
bool operator!=(decimal64 lhs, decimal64 rhs); 
bool operator!=(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator!=(decimal32 lhs, decimal128 rhs);
bool operator!=(decimal64 lhs, decimal128 rhs);
bool operator!=(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

bool operator<(decimal32 lhs, decimal32 rhs); 
bool operator<(decimal64 lhs, decimal32 rhs); 
bool operator<(decimal128 lhs, decimal32 rhs); 
// TODO - lhs can be integral types 

bool operator<(decimal32 lhs, decimal64 rhs); 
bool operator<(decimal64 lhs, decimal64 rhs); 
bool operator<(decimal128 lhs, decimal64 rhs); 
// TODO - lhs can be integral types 

bool operator<(decimal32 lhs, decimal128 rhs);
bool operator<(decimal64 lhs, decimal128 rhs);
bool operator<(decimal128 lhs, decimal128 rhs);
// TODO - lhs can be integral types 

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
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal32 & d);

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal64 & d);

template <class charT, class traits>
std::basic_istream<charT, traits>& operator>>(std::basic_istream<charT, traits> & is, decimal128 & d);

// 3.2.11 Formatted output:
template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal32 d);

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal64 d);

template <class charT, class traits>
std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits> & os, decimal128 d);

class decimal32 
{
public:
    // 3.2.2.1 construct/copy/destroy: 
    decimal32() = default;
    
    // 3.2.2.2 conversion from floating-point type: 
    explicit decimal32(decimal64 d64);
    explicit decimal32(decimal128 d128);
    explicit decimal32(float r);
    explicit decimal32(double r); explicit decimal32(long double r);

    // 3.2.2.3 conversion from integral type: 
    decimal32(int z);
    decimal32(unsigned int z);
    decimal32(long z);
    decimal32(unsigned long z); 
    decimal32(long long z); 
    decimal32(unsigned long long z);
    
    // 3.2.2.4 conversion to integral type: 
    operator long long() const;
    
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
};

class decimal64 
{
public:

    // 3.2.3.1 construct/copy/destroy: 
    decimal64() = default;
    
    // 3.2.3.2 conversion from floating-point type: 
    explicit decimal64(decimal32 d32);
    explicit decimal64(decimal128 d128); 
    explicit decimal64(float r); 
    explicit decimal64(double r); 
    explicit decimal64(long double r);
    
    // 3.2.3.3 conversion from integral type: 
    decimal64(int z);
    decimal64(unsigned int z);
    decimal64(long z);
    decimal64(unsigned long z); 
    decimal64(long long z); 
    decimal64(unsigned long long z);
    
    // 3.2.3.4 conversion to integral type: 
    operator long long() const;
    
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
};

class decimal128 
{
public:

    // 3.2.4.1 construct/copy/destroy: 
    decimal128() = default;
    
    // 3.2.4.2 conversion from floating-point type: 
    decimal128(decimal32 d32);
    decimal128(decimal64 d64); 
    explicit decimal128(float r);
    explicit decimal128(double r); 
    explicit decimal128(long double r);
    
    // 3.2.4.3 conversion from integral type: 
    decimal128(int z);
    decimal128(unsigned int z); 
    decimal128(long z);
    decimal128(unsigned long z); 
    decimal128(long long z); 
    decimal128(unsigned long long z);
    
    // 3.2.4.4 conversion to integral type: 
    operator long long() const;
    
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
};

} // namespace std::decimal