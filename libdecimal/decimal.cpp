#include "decimal.hpp"

namespace std::decimal
{

_IDEC_flags flags = 0;

template<typename DecimalType, typename CoefficientType>
DecimalType make_decimal(CoefficientType coeff, int exponent)
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
    // TODO
    return 0;
}

long double decimal_to_long_double(decimal64 d)
{
    // TODO
    return 0;
}

long double decimal_to_long_double(decimal128 d)
{
    // TODO
    return 0;
}

decimal32 operator+(decimal32 rhs)
{
    // TODO
    return rhs;
}

decimal64 operator+(decimal64 rhs)
{
    // TODO
    return rhs;
}

decimal128 operator+(decimal128 rhs)
{
    // TODO
    return rhs;
}

decimal32 operator-(decimal32 rhs)
{
    // TODO
    return rhs;
}

decimal64 operator-(decimal64 rhs)
{
    // TODO
    return rhs;
}

decimal128 operator-(decimal128 rhs)
{
    // TODO
    return rhs;
}

// decimal32 ------------------------------------------------------------------

decimal32::decimal32()
:   m_value(bid32_from_int32(0, round_mode, &flags))
{
}

decimal32::decimal32(decimal64 d64)
:   m_value(bid64_to_bid32(d64.m_value, round_mode, &flags))
{
}

decimal32::decimal32(decimal128 d128)
:   m_value(bid128_to_bid32(d128.m_value, round_mode, &flags))
{
}

decimal32::decimal32(float r)
:   m_value(binary32_to_bid32(r, round_mode, &flags))
{
}

decimal32::decimal32(double r)
:   m_value(binary64_to_bid32(r, round_mode, &flags))
{
}

decimal32::decimal32(long double r)
// : m_value(binary128_to_bid32(r, round_mode, &flags))
{
}

decimal32::decimal32(int z)
:   m_value(bid32_from_int32(z, round_mode, &flags))
{
}

decimal32::decimal32(unsigned int z)
:   m_value(bid32_from_uint32(z, round_mode, &flags))
{
}

decimal32::decimal32(long z)
:   m_value(bid32_from_int64(z, round_mode, &flags))
{
}

decimal32::decimal32(unsigned long z)
:   m_value(bid32_from_uint64(z, round_mode, &flags))
{
}

decimal32::decimal32(long long z)
{
    // TODO
}

decimal32::decimal32(unsigned long long z)
{
    // TODO
}

decimal32::operator long long() const
{
    // TODO - is this the appropriate conversion?
    return bid32_to_int32_floor(m_value, &flags);
}

decimal32& decimal32::operator++()
{
    // TODO
    return *this;
}

decimal32 decimal32::operator++(int)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator--()
{
    // TODO
    return *this;
}

decimal32 decimal32::operator--(int)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(unsigned int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(unsigned long z) 
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator+=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(unsigned int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(unsigned long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator-=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(unsigned int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(unsigned long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator*=(unsigned long long z)
{
    // TODO
    return *this;
}


decimal32& decimal32::operator/=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(unsigned int z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(unsigned long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(long long z)
{
    // TODO
    return *this;
}

decimal32& decimal32::operator/=(unsigned long long z)
{
    // TODO
    return *this;
}

// decimal64 ------------------------------------------------------------------

decimal64::decimal64()
:   m_value(bid64_from_int64(0, round_mode, &flags))
{
}
    
decimal64::decimal64(decimal32 d32)
:   m_value(bid32_to_bid64(d32.m_value, &flags))
{
}

decimal64::decimal64(decimal128 d128)
:   m_value(bid128_to_bid64(d128.m_value, round_mode, &flags))
{
} 

decimal64::decimal64(float r)
:   m_value(binary32_to_bid64(r, round_mode, &flags))
{
} 

decimal64::decimal64(double r)
:   m_value(binary64_to_bid64(r, round_mode, &flags))
{
} 

decimal64::decimal64(long double r)
{
    // TODO
}
    
decimal64::decimal64(int z)
:   m_value(bid64_from_int32(z)) // TDOO - why are these different?
{
}

decimal64::decimal64(unsigned int z)
:   m_value(bid64_from_uint32(z)) // TDOO - why are these different?
{
}

decimal64::decimal64(long z)
:   m_value(bid64_from_int64(z, round_mode, &flags))
{
}

decimal64::decimal64(unsigned long z)
:   m_value(bid64_from_uint64(z, round_mode, &flags))
{
} 

decimal64::decimal64(long long z)
{
    // TODO
} 

decimal64::decimal64(unsigned long long z)
{
    // TODO
}
    
decimal64::operator long long() const
{
    // TODO - is this the appropriate conversion?
    return bid32_to_int64_floor(m_value, 0);
}

decimal64& decimal64::operator++()
{
    // TODO
    return *this;
}

decimal64 decimal64::operator++(int)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator--()
{
    // TODO
    return *this;
}

decimal64 decimal64::operator--(int)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(unsigned int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(unsigned long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator+=(unsigned long long z)
{
    // TODO
    return *this;
}


decimal64& decimal64::operator-=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(unsigned int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(unsigned long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator-=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(unsigned int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(unsigned long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator*=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(unsigned int z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(unsigned long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(long long z)
{
    // TODO
    return *this;
}

decimal64& decimal64::operator/=(unsigned long long z)
{
    // TODO
    return *this;
}

// decimal128 -----------------------------------------------------------------

decimal128::decimal128()
{
    // TODO
}
    
decimal128::decimal128(decimal32 d32)
{
    // TODO
}

decimal128::decimal128(decimal64 d64)
{
    // TODO
} 

decimal128::decimal128(float r)
{
    // TODO
}

decimal128::decimal128(double r)
{
    // TODO
} 

decimal128::decimal128(long double r)
{
    // TODO
}

decimal128::decimal128(int z)
{
    // TODO
}

decimal128::decimal128(unsigned int z)
{
    // TODO
} 

decimal128::decimal128(long z)
{
    // TODO
}

decimal128::decimal128(unsigned long z)
{
    // TODO
}

decimal128::decimal128(long long z)
{
    // TODO
}

decimal128::decimal128(unsigned long long z)
{
    // TODO
}

decimal128::operator long long() const
{
    // TODO
    return 0;
}

decimal128& decimal128::operator++()
{
    // TODO
    return *this;
}

decimal128 decimal128::operator++(int)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator--()
{
    // TODO
    return *this;
}

decimal128 decimal128::operator--(int)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(unsigned int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(unsigned long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator+=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(unsigned int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(unsigned long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator-=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(unsigned int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(unsigned long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator*=(unsigned long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(decimal32 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(decimal64 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(decimal128 rhs)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(unsigned int z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(unsigned long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(long long z)
{
    // TODO
    return *this;
}

decimal128& decimal128::operator/=(unsigned long long z)
{
    // TODO
    return *this;
}

}