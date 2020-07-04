#ifndef stddecimal_libdecimal_decimal_numeric_limits_hpp
#define stddecimal_libdecimal_decimal_numeric_limits_hpp

namespace std::decimal
{

class decimal32;
class decimal64;
class decimal128;

// Redefine this inside the decimal namespace so it doesn't clash with the standard library.
template<typename T> class numeric_limits;

template<> class numeric_limits<decimal::decimal32> {
public:
    // static const bool is_specialized = true;
    // static decimal::decimal32 min() throw() { return DEC32_MIN; }
    // static decimal::decimal32 max() throw() { return DEC32_MAX; }
    static constexpr int digits = 7; 
    // static const int digits10 = digits; 
    // static const int max_digits10 = digits;
    // static const bool is_signed = true; 
    // static const bool is_integer = false; 
    // static const bool is_exact = false;
    // static const int radix = 10;
    // static decimal::decimal32 epsilon() throw()  { return DEC32_EPSILON; }
    // static decimal::decimal32 round_error() throw();
    static constexpr int min_exponent = -94;   
    // static const int min_exponent10 = min_exponent;
    static constexpr int max_exponent = 97;
    // static const int max_exponent10 = max_exponent;
    // static const bool has_infinity = true;
    // static const bool has_quiet_NaN = true;
    // static const bool has_signaling_NaN = true;
    // static const float_denorm_style has_denorm = = true;
    // static decimal::decimal32 infinity()
    // static decimal::decimal32 quiet_NaN()
    // static decimal::decimal32 signaling_NaN() throw();
    // static decimal::decimal32 denorm_min()    throw() { return DEC32_DEN; }
    // static const bool is_iec559
    // static const bool is_bounded
    // static const bool is_modulo
    // static const bool traps
    // static const bool tinyness_before
    // static const float_round_style round_style = round_indeterminate;
};


template<> class numeric_limits<decimal::decimal64> {
public:
    // static const bool is_specialized = true;
    // static decimal::decimal64 min() throw() { return DEC64_MIN; }
    //     denorm_present;
    // static const bool has_denorm_loss
    // = false; = true; = false; = true; = true;
    // throw();
    // throw();
    // 27
    // ISO/IEC DTR 24733
    // WG21 N2849
    // static decimal::decimal64 max() throw()
    //     { return DEC64_MAX; }
    static constexpr int digits = 16;
    // static const int digits10 = digits;
    // static const int max_digits10 = digits;
    // static const bool is_signed = true;
    // static const bool is_integer = false;
    // static const bool is_exact = false;
    // static const int radix = 10;
    // static decimal::decimal64 epsilon() throw() { return DEC64_EPSILON; }
    // static decimal::decimal64 round_error() throw() { return ...; }
    static constexpr int min_exponent = -382;
    // static const int min_exponent10 = min_exponent;
    static constexpr int max_exponent = 385;
    // static const int max_exponent10 = max_exponent;
    // static const bool has_infinity = true;
    // static const bool has_quiet_NaN = true;
    // static const bool has_signaling_NaN = true;
    // static const float_denorm_style has_denorm = denorm_present;
    // static const bool has_denorm_loss
    // static decimal::decimal64 infinity() { return ...; }
    // static decimal::decimal64 quiet_NaN() { return ...; }
    // static decimal::decimal64 signaling_NaN() throw() { return ...; }
    // static decimal::decimal64 denorm_min()    throw()
    //     { return DEC64_DEN; }
    // static const bool is_iec559
    // static const bool is_bounded
    // static const bool is_modulo
    // static const bool traps
    // static const bool tinyness_before
    // = false; = true; = false; = true; = true;
    // static const float_round_style round_style = round_indeterminate;
};



template<> class numeric_limits<decimal::decimal128> {
public:
    // static const bool is_specialized = true;
    // static decimal::decimal128 min() throw() { return DEC128_MIN; }
    // static decimal::decimal128 max() throw() { return DEC128_MAX; }
    static constexpr int digits = 34;
    // static const int digits10
    // static const int max_digits10 = digits;
    // static const bool is_signed = true; 
    // static const bool is_integer = false; 
    // static const bool is_exact = false;
    // static const int radix = 10;
    // static decimal::decimal128 epsilon() { return DEC128_EPSILON; }
    // static decimal::decimal128 round_error() throw() { return ...; }
    static constexpr int min_exponent = -6142;
    // static const int min_exponent10 = min_exponent;
    static constexpr int max_exponent = 6145;
    // static const int max_exponent10 = max_exponent;
    // static const bool has_infinity = true;
    // static const bool has_quiet_NaN = true;
    // static const bool has_signaling_NaN = true;
    // static const float_denorm_style has_denorm = denorm_present;
    // static const bool has_denorm_loss = true; 
    // static decimal::decimal128 infinity() throw() { return ...; }
    // static decimal::decimal128 quiet_NaN() throw() { return ...; }
    // static decimal::decimal128 signaling_NaN() throw() { return ...; }
    // static decimal::decimal128 denorm_min() throw() { return DEC128_DEN; }
    // static const bool is_iec559 = false;
    // static const bool is_bounded = true;
    // static const bool is_modulo = false;
    // static const bool traps = true;
    // static const bool tinyness_before = true;
    // static const float_round_style round_style = round_indeterminate;
};

}

#endif