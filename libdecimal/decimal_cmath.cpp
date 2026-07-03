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
    static BID_UINT32 quantize(BID_UINT32 x, BID_UINT32 y, int round, unsigned int& flags) { return bid32_quantize(x, y, round, &flags); }
    static BID_UINT32 exp(BID_UINT32 x, int round, unsigned int& flags) { return bid32_exp(x, round, &flags); }
    static BID_UINT32 log(BID_UINT32 x, int round, unsigned int& flags) { return bid32_log(x, round, &flags); }
    static BID_UINT32 log10(BID_UINT32 x, int round, unsigned int& flags) { return bid32_log10(x, round, &flags); }
    static BID_UINT32 pow(BID_UINT32 x, BID_UINT32 y, int round, unsigned int& flags) { return bid32_pow(x, y, round, &flags); }
    static BID_UINT32 sqrt(BID_UINT32 x, int round, unsigned int& flags) { return bid32_sqrt(x, round, &flags); }
    static BID_UINT32 rem(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_rem(x, y, &flags); }
    static BID_UINT32 maxnum(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_maxnum(x, y, &flags); }
    static BID_UINT32 minnum(BID_UINT32 x, BID_UINT32 y, unsigned int& flags) { return bid32_minnum(x, y, &flags); }
    static BID_UINT32 fma(BID_UINT32 x, BID_UINT32 y, BID_UINT32 z, int round, unsigned int& flags) { return bid32_fma(x, y, z, round, &flags); }
    static BID_UINT32 abs(BID_UINT32 x) { return bid32_abs(x); }
};

template<> struct cmath_traits<decimal64>
{
    static bool is_inf(BID_UINT64 x) { return bid64_isInf(x); }
    static bool is_nan(BID_UINT64 x) { return bid64_isNaN(x); }
    static bool same_quantum(BID_UINT64 x, BID_UINT64 y) { return bid64_sameQuantum(x, y); }
    static BID_UINT64 quantize(BID_UINT64 x, BID_UINT64 y, int round, unsigned int& flags) { return bid64_quantize(x, y, round, &flags); }
    static BID_UINT64 exp(BID_UINT64 x, int round, unsigned int& flags) { return bid64_exp(x, round, &flags); }
    static BID_UINT64 log(BID_UINT64 x, int round, unsigned int& flags) { return bid64_log(x, round, &flags); }
    static BID_UINT64 log10(BID_UINT64 x, int round, unsigned int& flags) { return bid64_log10(x, round, &flags); }
    static BID_UINT64 pow(BID_UINT64 x, BID_UINT64 y, int round, unsigned int& flags) { return bid64_pow(x, y, round, &flags); }
    static BID_UINT64 sqrt(BID_UINT64 x, int round, unsigned int& flags) { return bid64_sqrt(x, round, &flags); }
    static BID_UINT64 rem(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_rem(x, y, &flags); }
    static BID_UINT64 maxnum(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_maxnum(x, y, &flags); }
    static BID_UINT64 minnum(BID_UINT64 x, BID_UINT64 y, unsigned int& flags) { return bid64_minnum(x, y, &flags); }
    static BID_UINT64 fma(BID_UINT64 x, BID_UINT64 y, BID_UINT64 z, int round, unsigned int& flags) { return bid64_fma(x, y, z, round, &flags); }
    static BID_UINT64 abs(BID_UINT64 x) { return bid64_abs(x); }
};

template<> struct cmath_traits<decimal128>
{
    static bool is_inf(BID_UINT128 x) { return bid128_isInf(x); }
    static bool is_nan(BID_UINT128 x) { return bid128_isNaN(x); }
    static bool same_quantum(BID_UINT128 x, BID_UINT128 y) { return bid128_sameQuantum(x, y); }
    static BID_UINT128 quantize(BID_UINT128 x, BID_UINT128 y, int round, unsigned int& flags) { return bid128_quantize(x, y, round, &flags); }
    static BID_UINT128 exp(BID_UINT128 x, int round, unsigned int& flags) { return bid128_exp(x, round, &flags); }
    static BID_UINT128 log(BID_UINT128 x, int round, unsigned int& flags) { return bid128_log(x, round, &flags); }
    static BID_UINT128 log10(BID_UINT128 x, int round, unsigned int& flags) { return bid128_log10(x, round, &flags); }
    static BID_UINT128 pow(BID_UINT128 x, BID_UINT128 y, int round, unsigned int& flags) { return bid128_pow(x, y, round, &flags); }
    static BID_UINT128 sqrt(BID_UINT128 x, int round, unsigned int& flags) { return bid128_sqrt(x, round, &flags); }
    static BID_UINT128 rem(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_rem(x, y, &flags); }
    static BID_UINT128 maxnum(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_maxnum(x, y, &flags); }
    static BID_UINT128 minnum(BID_UINT128 x, BID_UINT128 y, unsigned int& flags) { return bid128_minnum(x, y, &flags); }
    static BID_UINT128 fma(BID_UINT128 x, BID_UINT128 y, BID_UINT128 z, int round, unsigned int& flags) { return bid128_fma(x, y, z, round, &flags); }
    static BID_UINT128 abs(BID_UINT128 x) { return bid128_abs(x); }
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

decimal32 fmaxd32(decimal32 x, decimal32 y) { return fmax_impl(x, y); }
decimal64 fmaxd64(decimal64 x, decimal64 y) { return fmax_impl(x, y); }
decimal128 fmaxd128(decimal128 x, decimal128 y) { return fmax_impl(x, y); }

decimal32 fmind32(decimal32 x, decimal32 y) { return fmin_impl(x, y); }
decimal64 fmind64(decimal64 x, decimal64 y) { return fmin_impl(x, y); }
decimal128 fmind128(decimal128 x, decimal128 y) { return fmin_impl(x, y); }

decimal32 fmad32(decimal32 x, decimal32 y, decimal32 z) { return fma_impl(x, y, z); }
decimal64 fmad64(decimal64 x, decimal64 y, decimal64 z) { return fma_impl(x, y, z); }
decimal128 fmad128(decimal128 x, decimal128 y, decimal128 z) { return fma_impl(x, y, z); }

template<decimal_value_type T>
T abs(T d)
{
    T result;
    result.value(cmath_traits<T>::abs(d.value()));
    return result;
}

template bool samequantum<decimal32>(decimal32, decimal32);
template bool samequantum<decimal64>(decimal64, decimal64);
template bool samequantum<decimal128>(decimal128, decimal128);

template decimal32 quantize<decimal32>(decimal32, decimal32);
template decimal64 quantize<decimal64>(decimal64, decimal64);
template decimal128 quantize<decimal128>(decimal128, decimal128);

template decimal32 abs<decimal32>(decimal32);
template decimal64 abs<decimal64>(decimal64);
template decimal128 abs<decimal128>(decimal128);

} // namespace decimal

} // namespace std
