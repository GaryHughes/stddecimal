#include "decimal_cmath.hpp"

namespace std::decimal
{

namespace
{

template<typename T> struct cmath_traits;

template<> struct cmath_traits<decimal32>
{
    static bool is_inf(BID_UINT32 x) { return bid32_isInf(x); }
    static bool is_nan(BID_UINT32 x) { return bid32_isNaN(x); }
    static bool same_quantum(BID_UINT32 x, BID_UINT32 y) { return bid32_sameQuantum(x, y); }
    static bool total_order(BID_UINT32 x, BID_UINT32 y) { return bid32_totalOrder(x, y); }
    static bool total_order_mag(BID_UINT32 x, BID_UINT32 y) { return bid32_totalOrderMag(x, y); }
    static BID_UINT32 quantize(BID_UINT32 x, BID_UINT32 y, int round, unsigned int& flags) { return bid32_quantize(x, y, round, &flags); }
    static BID_UINT32 exp(BID_UINT32 x, int round, unsigned int& flags) { return bid32_exp(x, round, &flags); }
    static BID_UINT32 log(BID_UINT32 x, int round, unsigned int& flags) { return bid32_log(x, round, &flags); }
    static BID_UINT32 log10(BID_UINT32 x, int round, unsigned int& flags) { return bid32_log10(x, round, &flags); }
    static BID_UINT32 pow(BID_UINT32 x, BID_UINT32 y, int round, unsigned int& flags) { return bid32_pow(x, y, round, &flags); }
    static BID_UINT32 sqrt(BID_UINT32 x, int round, unsigned int& flags) { return bid32_sqrt(x, round, &flags); }
    static BID_UINT32 rem(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_rem(x, y, &flags); }
    static BID_UINT32 fmod(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_fmod(x, y, &flags); }
    static BID_UINT32 maxnum(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_maxnum(x, y, &flags); }
    static BID_UINT32 minnum(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_minnum(x, y, &flags); }
    static BID_UINT32 fma(BID_UINT32 x, BID_UINT32 y, BID_UINT32 z, int round, unsigned int& flags) { return bid32_fma(x, y, z, round, &flags); }
    static BID_UINT32 abs(BID_UINT32 x) { return bid32_abs(x); }
    static BID_UINT32 to_integral(BID_UINT32 x, int round, unsigned int& flags)
    {
        switch (round) {
            case FE_DEC_DOWNWARD: return bid32_round_integral_negative(x, &flags);
            case FE_DEC_UPWARD: return bid32_round_integral_positive(x, &flags);
            case FE_DEC_TOWARD_ZERO: return bid32_round_integral_zero(x, &flags);
            case FE_DEC_TONEARESTFROMZERO: return bid32_round_integral_nearest_away(x, &flags);
            default: return bid32_round_integral_nearest_even(x, &flags);
        }
    }
    static BID_UINT32 to_integral_exact(BID_UINT32 x, int round, unsigned int& flags) { return bid32_round_integral_exact(x, round, &flags); }
    static BID_UINT32 copy(BID_UINT32 x) { return bid32_copy(x); }
    static BID_UINT32 negate(BID_UINT32 x) { return bid32_negate(x); }
    static BID_UINT32 copy_sign(BID_UINT32 x, BID_UINT32 y) { return bid32_copySign(x, y); }
    static int class_of(BID_UINT32 x) { return bid32_class(x); }
    static BID_UINT32 maxnum_mag(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_maxnum_mag(x, y, &flags); }
    static BID_UINT32 minnum_mag(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_minnum_mag(x, y, &flags); }
    static BID_UINT32 nextup(BID_UINT32 x, unsigned int& flags) { return bid32_nextup(x, &flags); }
    static BID_UINT32 nextdown(BID_UINT32 x, unsigned int& flags) { return bid32_nextdown(x, &flags); }
    static BID_UINT32 nextafter(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_nextafter(x, y, &flags); }
    static BID_UINT32 logb(BID_UINT32 x, unsigned int& flags) { return bid32_logb(x, &flags); }
    static BID_UINT32 scalbln(BID_UINT32 x, long int n, int round, unsigned int& flags) { return bid32_scalbln(x, n, round, &flags); }
};

template<> struct cmath_traits<decimal64>
{
    static bool is_inf(BID_UINT64 x) { return bid64_isInf(x); }
    static bool is_nan(BID_UINT64 x) { return bid64_isNaN(x); }
    static bool same_quantum(BID_UINT64 x, BID_UINT64 y) { return bid64_sameQuantum(x, y); }
    static bool total_order(BID_UINT64 x, BID_UINT64 y) { return bid64_totalOrder(x, y); }
    static bool total_order_mag(BID_UINT64 x, BID_UINT64 y) { return bid64_totalOrderMag(x, y); }
    static BID_UINT64 quantize(BID_UINT64 x, BID_UINT64 y, int round, unsigned int& flags) { return bid64_quantize(x, y, round, &flags); }
    static BID_UINT64 exp(BID_UINT64 x, int round, unsigned int& flags) { return bid64_exp(x, round, &flags); }
    static BID_UINT64 log(BID_UINT64 x, int round, unsigned int& flags) { return bid64_log(x, round, &flags); }
    static BID_UINT64 log10(BID_UINT64 x, int round, unsigned int& flags) { return bid64_log10(x, round, &flags); }
    static BID_UINT64 pow(BID_UINT64 x, BID_UINT64 y, int round, unsigned int& flags) { return bid64_pow(x, y, round, &flags); }
    static BID_UINT64 sqrt(BID_UINT64 x, int round, unsigned int& flags) { return bid64_sqrt(x, round, &flags); }
    static BID_UINT64 rem(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_rem(x, y, &flags); }
    static BID_UINT64 fmod(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_fmod(x, y, &flags); }
    static BID_UINT64 maxnum(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_maxnum(x, y, &flags); }
    static BID_UINT64 minnum(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_minnum(x, y, &flags); }
    static BID_UINT64 fma(BID_UINT64 x, BID_UINT64 y, BID_UINT64 z, int round, unsigned int& flags) { return bid64_fma(x, y, z, round, &flags); }
    static BID_UINT64 abs(BID_UINT64 x) { return bid64_abs(x); }
    static BID_UINT64 to_integral(BID_UINT64 x, int round, unsigned int& flags)
    {
        switch (round) {
            case FE_DEC_DOWNWARD: return bid64_round_integral_negative(x, &flags);
            case FE_DEC_UPWARD: return bid64_round_integral_positive(x, &flags);
            case FE_DEC_TOWARD_ZERO: return bid64_round_integral_zero(x, &flags);
            case FE_DEC_TONEARESTFROMZERO: return bid64_round_integral_nearest_away(x, &flags);
            default: return bid64_round_integral_nearest_even(x, &flags);
        }
    }
    static BID_UINT64 to_integral_exact(BID_UINT64 x, int round, unsigned int& flags) { return bid64_round_integral_exact(x, round, &flags); }
    static BID_UINT64 copy(BID_UINT64 x) { return bid64_copy(x); }
    static BID_UINT64 negate(BID_UINT64 x) { return bid64_negate(x); }
    static BID_UINT64 copy_sign(BID_UINT64 x, BID_UINT64 y) { return bid64_copySign(x, y); }
    static int class_of(BID_UINT64 x) { return bid64_class(x); }
    static BID_UINT64 maxnum_mag(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_maxnum_mag(x, y, &flags); }
    static BID_UINT64 minnum_mag(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_minnum_mag(x, y, &flags); }
    static BID_UINT64 nextup(BID_UINT64 x, unsigned int& flags) { return bid64_nextup(x, &flags); }
    static BID_UINT64 nextdown(BID_UINT64 x, unsigned int& flags) { return bid64_nextdown(x, &flags); }
    static BID_UINT64 nextafter(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_nextafter(x, y, &flags); }
    static BID_UINT64 logb(BID_UINT64 x, unsigned int& flags) { return bid64_logb(x, &flags); }
    static BID_UINT64 scalbln(BID_UINT64 x, long int n, int round, unsigned int& flags) { return bid64_scalbln(x, n, round, &flags); }
};

template<> struct cmath_traits<decimal128>
{
    static bool is_inf(BID_UINT128 x) { return bid128_isInf(x); }
    static bool is_nan(BID_UINT128 x) { return bid128_isNaN(x); }
    static bool same_quantum(BID_UINT128 x, BID_UINT128 y) { return bid128_sameQuantum(x, y); }
    static bool total_order(BID_UINT128 x, BID_UINT128 y) { return bid128_totalOrder(x, y); }
    static bool total_order_mag(BID_UINT128 x, BID_UINT128 y) { return bid128_totalOrderMag(x, y); }
    static BID_UINT128 quantize(BID_UINT128 x, BID_UINT128 y, int round, unsigned int& flags) { return bid128_quantize(x, y, round, &flags); }
    static BID_UINT128 exp(BID_UINT128 x, int round, unsigned int& flags) { return bid128_exp(x, round, &flags); }
    static BID_UINT128 log(BID_UINT128 x, int round, unsigned int& flags) { return bid128_log(x, round, &flags); }
    static BID_UINT128 log10(BID_UINT128 x, int round, unsigned int& flags) { return bid128_log10(x, round, &flags); }
    static BID_UINT128 pow(BID_UINT128 x, BID_UINT128 y, int round, unsigned int& flags) { return bid128_pow(x, y, round, &flags); }
    static BID_UINT128 sqrt(BID_UINT128 x, int round, unsigned int& flags) { return bid128_sqrt(x, round, &flags); }
    static BID_UINT128 rem(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_rem(x, y, &flags); }
    static BID_UINT128 fmod(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_fmod(x, y, &flags); }
    static BID_UINT128 maxnum(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_maxnum(x, y, &flags); }
    static BID_UINT128 minnum(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_minnum(x, y, &flags); }
    static BID_UINT128 fma(BID_UINT128 x, BID_UINT128 y, BID_UINT128 z, int round, unsigned int& flags) { return bid128_fma(x, y, z, round, &flags); }
    static BID_UINT128 abs(BID_UINT128 x) { return bid128_abs(x); }
    static BID_UINT128 to_integral(BID_UINT128 x, int round, unsigned int& flags)
    {
        switch (round) {
            case FE_DEC_DOWNWARD: return bid128_round_integral_negative(x, &flags);
            case FE_DEC_UPWARD: return bid128_round_integral_positive(x, &flags);
            case FE_DEC_TOWARD_ZERO: return bid128_round_integral_zero(x, &flags);
            case FE_DEC_TONEARESTFROMZERO: return bid128_round_integral_nearest_away(x, &flags);
            default: return bid128_round_integral_nearest_even(x, &flags);
        }
    }
    static BID_UINT128 to_integral_exact(BID_UINT128 x, int round, unsigned int& flags) { return bid128_round_integral_exact(x, round, &flags); }
    static BID_UINT128 copy(BID_UINT128 x) { return bid128_copy(x); }
    static BID_UINT128 negate(BID_UINT128 x) { return bid128_negate(x); }
    static BID_UINT128 copy_sign(BID_UINT128 x, BID_UINT128 y) { return bid128_copySign(x, y); }
    static int class_of(BID_UINT128 x) { return bid128_class(x); }
    static BID_UINT128 maxnum_mag(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_maxnum_mag(x, y, &flags); }
    static BID_UINT128 minnum_mag(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_minnum_mag(x, y, &flags); }
    static BID_UINT128 nextup(BID_UINT128 x, unsigned int& flags) { return bid128_nextup(x, &flags); }
    static BID_UINT128 nextdown(BID_UINT128 x, unsigned int& flags) { return bid128_nextdown(x, &flags); }
    static BID_UINT128 nextafter(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_nextafter(x, y, &flags); }
    static BID_UINT128 logb(BID_UINT128 x, unsigned int& flags) { return bid128_logb(x, &flags); }
    static BID_UINT128 scalbln(BID_UINT128 x, long int n, int round, unsigned int& flags) { return bid128_scalbln(x, n, round, &flags); }
};

template<decimal_value_type T>
T exp_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::exp(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T log_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::log(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T log10_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::log10(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T pow_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::pow(x.value(), y.value(), env.round, env.flags));
    // The vendored Intel library's pow can spuriously raise Overflow for a result that actually
    // underflows toward zero - e.g. pow(10, -333333333) returns +0E-101 (correctly recognising
    // the true result is far too small to represent) but still sets Overflow rather than
    // Underflow, seemingly because the internal x^|y| sub-computation for the reciprocal
    // genuinely overflows and that flag leaks through unconverted. A real overflow always
    // produces +/-Infinity, so Overflow alongside a finite result is never legitimate here.
    if ((env.flags & FE_DEC_OVERFLOW) && !isinf(result)) {
        env.flags &= ~static_cast<unsigned int>(FE_DEC_OVERFLOW);
        env.flags |= FE_DEC_UNDERFLOW;
    }
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T sqrt_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::sqrt(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T remainder_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::rem(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fmod_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::fmod(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fmax_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::maxnum(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fmin_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::minnum(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fma_impl(T x, T y, T z)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::fma(x.value(), y.value(), z.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fmaxmag_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::maxnum_mag(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T fminmag_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::minnum_mag(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T nextup_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::nextup(x.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T nextdown_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::nextdown(x.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T nextafter_impl(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::nextafter(x.value(), y.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T logb_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::logb(x.value(), env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T scalbln_impl(T x, long int n)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::scalbln(x.value(), n, env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T to_integral_exact_impl(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::to_integral_exact(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

const char* class_name(int class_index)
{
    static constexpr const char* names[] = {
        "sNaN", "NaN", "-Infinity", "-Normal", "-Subnormal", "-Zero", "+Zero", "+Subnormal", "+Normal", "+Infinity"
    };
    return names[class_index];
}

} // anonymous namespace

} // namespace std::decimal

namespace std
{

template<decimal_value_type T>
bool isinf(T value)
{
    return decimal::cmath_traits<T>::is_inf(value.value());
}

template<decimal_value_type T>
bool isnan(T value)
{
    return decimal::cmath_traits<T>::is_nan(value.value());
}

template bool isinf<decimal::decimal32>(decimal::decimal32);
template bool isinf<decimal::decimal64>(decimal::decimal64);
template bool isinf<decimal::decimal128>(decimal::decimal128);

template bool isnan<decimal::decimal32>(decimal::decimal32);
template bool isnan<decimal::decimal64>(decimal::decimal64);
template bool isnan<decimal::decimal128>(decimal::decimal128);

namespace decimal
{

template<decimal_value_type T>
bool samequantum(T x, T y)
{
    return cmath_traits<T>::same_quantum(x.value(), y.value());
}

bool samequantumd32(decimal32 x, decimal32 y) { return samequantum(x, y); }
bool samequantumd64(decimal64 x, decimal64 y) { return samequantum(x, y); }
bool samequantumd128(decimal128 x, decimal128 y) { return samequantum(x, y); }

template<decimal_value_type T>
bool total_order(T x, T y)
{
    return cmath_traits<T>::total_order(x.value(), y.value());
}

template<decimal_value_type T>
bool total_order_mag(T x, T y)
{
    return cmath_traits<T>::total_order_mag(x.value(), y.value());
}

template<decimal_value_type T>
T quantize(T x, T y)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::quantize(x.value(), y.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

decimal32 quantized32(decimal32 x, decimal32 y) { return quantize(x, y); }
decimal64 quantized64(decimal64 x, decimal64 y) { return quantize(x, y); }
decimal128 quantized128(decimal128 x, decimal128 y) { return quantize(x, y); }

decimal32 expd32(decimal32 x) { return exp_impl(x); }
decimal64 expd64(decimal64 x) { return exp_impl(x); }
decimal128 expd128(decimal128 x) { return exp_impl(x); }

decimal32 logd32(decimal32 x) { return log_impl(x); }
decimal64 logd64(decimal64 x) { return log_impl(x); }
decimal128 logd128(decimal128 x) { return log_impl(x); }

decimal32 log10d32(decimal32 x) { return log10_impl(x); }
decimal64 log10d64(decimal64 x) { return log10_impl(x); }
decimal128 log10d128(decimal128 x) { return log10_impl(x); }

decimal32 powd32(decimal32 x, decimal32 y) { return pow_impl(x, y); }
decimal64 powd64(decimal64 x, decimal64 y) { return pow_impl(x, y); }
decimal128 powd128(decimal128 x, decimal128 y) { return pow_impl(x, y); }

decimal32 sqrtd32(decimal32 x) { return sqrt_impl(x); }
decimal64 sqrtd64(decimal64 x) { return sqrt_impl(x); }
decimal128 sqrtd128(decimal128 x) { return sqrt_impl(x); }

decimal32 remainderd32(decimal32 x, decimal32 y) { return remainder_impl(x, y); }
decimal64 remainderd64(decimal64 x, decimal64 y) { return remainder_impl(x, y); }
decimal128 remainderd128(decimal128 x, decimal128 y) { return remainder_impl(x, y); }

decimal32 fmodd32(decimal32 x, decimal32 y) { return fmod_impl(x, y); }
decimal64 fmodd64(decimal64 x, decimal64 y) { return fmod_impl(x, y); }
decimal128 fmodd128(decimal128 x, decimal128 y) { return fmod_impl(x, y); }

decimal32 fmaxd32(decimal32 x, decimal32 y) { return fmax_impl(x, y); }
decimal64 fmaxd64(decimal64 x, decimal64 y) { return fmax_impl(x, y); }
decimal128 fmaxd128(decimal128 x, decimal128 y) { return fmax_impl(x, y); }

decimal32 fmind32(decimal32 x, decimal32 y) { return fmin_impl(x, y); }
decimal64 fmind64(decimal64 x, decimal64 y) { return fmin_impl(x, y); }
decimal128 fmind128(decimal128 x, decimal128 y) { return fmin_impl(x, y); }

decimal32 fmad32(decimal32 x, decimal32 y, decimal32 z) { return fma_impl(x, y, z); }
decimal64 fmad64(decimal64 x, decimal64 y, decimal64 z) { return fma_impl(x, y, z); }
decimal128 fmad128(decimal128 x, decimal128 y, decimal128 z) { return fma_impl(x, y, z); }

decimal32 fmaxmagd32(decimal32 x, decimal32 y) { return fmaxmag_impl(x, y); }
decimal64 fmaxmagd64(decimal64 x, decimal64 y) { return fmaxmag_impl(x, y); }
decimal128 fmaxmagd128(decimal128 x, decimal128 y) { return fmaxmag_impl(x, y); }

decimal32 fminmagd32(decimal32 x, decimal32 y) { return fminmag_impl(x, y); }
decimal64 fminmagd64(decimal64 x, decimal64 y) { return fminmag_impl(x, y); }
decimal128 fminmagd128(decimal128 x, decimal128 y) { return fminmag_impl(x, y); }

decimal32 nextupd32(decimal32 x) { return nextup_impl(x); }
decimal64 nextupd64(decimal64 x) { return nextup_impl(x); }
decimal128 nextupd128(decimal128 x) { return nextup_impl(x); }

decimal32 nextdownd32(decimal32 x) { return nextdown_impl(x); }
decimal64 nextdownd64(decimal64 x) { return nextdown_impl(x); }
decimal128 nextdownd128(decimal128 x) { return nextdown_impl(x); }

decimal32 nextafterd32(decimal32 x, decimal32 y) { return nextafter_impl(x, y); }
decimal64 nextafterd64(decimal64 x, decimal64 y) { return nextafter_impl(x, y); }
decimal128 nextafterd128(decimal128 x, decimal128 y) { return nextafter_impl(x, y); }

decimal32 logbd32(decimal32 x) { return logb_impl(x); }
decimal64 logbd64(decimal64 x) { return logb_impl(x); }
decimal128 logbd128(decimal128 x) { return logb_impl(x); }

decimal32 scalblnd32(decimal32 x, long int n) { return scalbln_impl(x, n); }
decimal64 scalblnd64(decimal64 x, long int n) { return scalbln_impl(x, n); }
decimal128 scalblnd128(decimal128 x, long int n) { return scalbln_impl(x, n); }

decimal32 copyd32(decimal32 x) { decimal32 result; result.value(cmath_traits<decimal32>::copy(x.value())); return result; }
decimal64 copyd64(decimal64 x) { decimal64 result; result.value(cmath_traits<decimal64>::copy(x.value())); return result; }
decimal128 copyd128(decimal128 x) { decimal128 result; result.value(cmath_traits<decimal128>::copy(x.value())); return result; }

decimal32 negated32(decimal32 x) { decimal32 result; result.value(cmath_traits<decimal32>::negate(x.value())); return result; }
decimal64 negated64(decimal64 x) { decimal64 result; result.value(cmath_traits<decimal64>::negate(x.value())); return result; }
decimal128 negated128(decimal128 x) { decimal128 result; result.value(cmath_traits<decimal128>::negate(x.value())); return result; }

decimal32 copysignd32(decimal32 x, decimal32 y) { decimal32 result; result.value(cmath_traits<decimal32>::copy_sign(x.value(), y.value())); return result; }
decimal64 copysignd64(decimal64 x, decimal64 y) { decimal64 result; result.value(cmath_traits<decimal64>::copy_sign(x.value(), y.value())); return result; }
decimal128 copysignd128(decimal128 x, decimal128 y) { decimal128 result; result.value(cmath_traits<decimal128>::copy_sign(x.value(), y.value())); return result; }

std::string classd32(decimal32 x) { return class_name(cmath_traits<decimal32>::class_of(x.value())); }
std::string classd64(decimal64 x) { return class_name(cmath_traits<decimal64>::class_of(x.value())); }
std::string classd128(decimal128 x) { return class_name(cmath_traits<decimal128>::class_of(x.value())); }

template<decimal_value_type T>
T abs(T d)
{
    T result;
    result.value(cmath_traits<T>::abs(d.value()));
    return result;
}

template<decimal_value_type T>
T to_integral(T x)
{
    fenv_t env {};
    fe_dec_getenv(&env);
    T result;
    result.value(cmath_traits<T>::to_integral(x.value(), env.round, env.flags));
    fe_dec_setenv(&env);
    return result;
}

template<decimal_value_type T>
T to_integral_exact(T x)
{
    return to_integral_exact_impl(x);
}

template bool samequantum<decimal32>(decimal32, decimal32);
template bool samequantum<decimal64>(decimal64, decimal64);
template bool samequantum<decimal128>(decimal128, decimal128);

template bool total_order<decimal32>(decimal32, decimal32);
template bool total_order<decimal64>(decimal64, decimal64);
template bool total_order<decimal128>(decimal128, decimal128);

template bool total_order_mag<decimal32>(decimal32, decimal32);
template bool total_order_mag<decimal64>(decimal64, decimal64);
template bool total_order_mag<decimal128>(decimal128, decimal128);

template decimal32 quantize<decimal32>(decimal32, decimal32);
template decimal64 quantize<decimal64>(decimal64, decimal64);
template decimal128 quantize<decimal128>(decimal128, decimal128);

template decimal32 abs<decimal32>(decimal32);
template decimal64 abs<decimal64>(decimal64);
template decimal128 abs<decimal128>(decimal128);

template decimal32 to_integral<decimal32>(decimal32);
template decimal64 to_integral<decimal64>(decimal64);
template decimal128 to_integral<decimal128>(decimal128);

template decimal32 to_integral_exact<decimal32>(decimal32);
template decimal64 to_integral_exact<decimal64>(decimal64);
template decimal128 to_integral_exact<decimal128>(decimal128);

} // namespace decimal

} // namespace std
