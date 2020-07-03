#ifndef stddecimal_libdecimal_decimal_cmath_hpp
#define stddecimal_libdecimal_decimal_cmath_hpp

#include "decimal.hpp"

namespace std
{

// signbit
// fpclassify
// isfinite

bool isinf(decimal::decimal32 value);
bool isinf(decimal::decimal64 value);
bool isinf(decimal::decimal128 value);

bool isnan(decimal::decimal32 value);
bool isnan(decimal::decimal64 value);
bool isnan(decimal::decimal128 value);

// isnormal
// isgreater
// isgreaterequal
// isless
// islessequal
// islessgreater
// isunordered

namespace decimal {

// 3.6.4 samequantum functions:
// bool samequantum (decimal32 x, decimal32 y); 
// bool samequantumd32 (decimal32 x, decimal32 y);

// bool samequantum (decimal64 x, decimal64 y); 
// bool samequantumd64 (decimal64 x, decimal64 y);

// bool samequantum (decimal128 x, decimal128 y); 
// bool samequantumd128 (decimal128 x, decimal128 y);

// // 3.6.5 quantize functions:
decimal32 quantize (decimal32 x, decimal32 y); 
decimal32 quantized32 (decimal32 x, decimal32 y);

decimal64 quantize (decimal64 x, decimal64 y); 
decimal64 quantized64 (decimal64 x, decimal64 y);

decimal128 quantize (decimal128 x, decimal128 y); 
decimal128 quantized128 (decimal128 x, decimal128 y);

// // 3.6.6 elementary functions:
// // trigonometric functions: 
// decimal32 acosd32 (decimal32 x); 
// decimal64 acosd64 (decimal64 x); 
// decimal128 acosd128 (decimal128 x);

// decimal32 asind32 (decimal32 x); 
// decimal64 asind64 (decimal64 x); 
// decimal128 asind128 (decimal128 x);

// decimal32 atand32 (decimal32 x); 
// decimal64 atand64 (decimal64 x); 
// decimal128 atand128 (decimal128 x);

// decimal32 atan2d32 (decimal32 x, decimal32 y); 
// decimal64 atan2d64 (decimal64 x, decimal64 y); 
// decimal128 atan2d128 (decimal128 x, decimal128 y);

// decimal32 cosd32 (decimal32 x); 
// decimal64 cosd64 (decimal64 x); 
// decimal128 cosd128 (decimal128 x);

// decimal32 sind32 (decimal32 x); 
// decimal64 sind64 (decimal64 x); 
// decimal128 sind128 (decimal128 x);

// decimal32 tand32 (decimal32 x); 
// decimal64 tand64 (decimal64 x); 
// decimal128 tand128 (decimal128 x);

// // hyperbolic functions:
// decimal32 acoshd32 (decimal32 x); 
// decimal64 acoshd64 (decimal64 x); 
// decimal128 acoshd128 (decimal128 x);
// decimal32 asinhd32 (decimal32 x);
// decimal64 asinhd64 (decimal64 x); 
// decimal128 asinhd128 (decimal128 x);
// decimal32 atanhd32 (decimal32 x); 
// decimal64 atanhd64 (decimal64 x); 
// decimal128 atanhd128 (decimal128 x);
// decimal32 coshd32 (decimal32 x); 
// decimal64 coshd64 (decimal64 x); 
// decimal128 coshd128 (decimal128 x);
// decimal32 sinhd32 (decimal32 x); 
// decimal64 sinhd64 (decimal64 x); 
// decimal128 sinhd128 (decimal128 x);
// decimal32 tanhd32 (decimal32 x); 
// decimal64 tanhd64 (decimal64 x); 
// decimal128 tanhd128 (decimal128 x);

// // exponential and logarithmic functions: decimal32 expd32 (decimal32 x); decimal64 expd64 (decimal64 x); decimal128 expd128 (decimal128 x);
// decimal32 exp2d32 (decimal32 x); 
// decimal64 exp2d64 (decimal64 x); 
// decimal128 exp2d128 (decimal128 x);
// decimal32 expm1d32 (decimal32 x); 
// decimal64 expm1d64 (decimal64 x); 
// decimal128 expm1d128 (decimal128 x);
// decimal32 frexpd32 (decimal32 value, int * exp); 
// decimal64 frexpd64 (decimal64 value, int * exp); 
// decimal128 frexpd128 (decimal128 value, int * exp);
// int ilogbd32 (decimal32 x); 
// int ilogbd64 (decimal64 x); 
// int ilogbd128 (decimal128 x);
// decimal32 ldexpd32 (decimal32 x, int exp); 
// decimal64 ldexpd64 (decimal64 x, int exp); 
// decimal128 ldexpd128 (decimal128 x, int exp);
// decimal32 logd32 (decimal32 x); 
// decimal64 logd64 (decimal64 x); 
// decimal128 logd128 (decimal128 x);

decimal32 log10d32(decimal32 x); 
decimal64 log10d64(decimal64 x); 
decimal128 log10d128(decimal128 x);

// decimal32 log1pd32 (decimal32 x); 
// decimal64 log1pd64 (decimal64 x); 
// decimal128 log1pd128 (decimal128 x);
// decimal32 log2d32 (decimal32 x);

// decimal64 log2d64 (decimal64 x); 
// decimal128 log2d128 (decimal128 x);
// decimal32 logbd32 (decimal32 x); 
// decimal64 logbd64 (decimal64 x); 
// decimal128 logbd128 (decimal128 x);
// decimal32 modfd32 (decimal32 value, decimal32 * iptr); 
// decimal64 modfd64 (decimal64 value, decimal64 * iptr); 
// decimal32 modfd128 (decimal128 value, decimal128 * iptr);
// decimal32 scalbnd32 (decimal32 x, int n); 
// decimal64 scalbnd64 (decimal64 x, int n); 
// decimal128 scalbnd128 (decimal128 x, int n);
// decimal32 scalblnd32 (decimal32 x, long int n); 
// decimal64 scalblnd64 (decimal64 x, long int n); 
// decimal128 scalblnd128 (decimal128 x, long int n);

// // power and absolute-value functions: decimal32 cbrtd32 (decimal32 x); decimal64 cbrtd64 (decimal64 x); decimal128 cbrtd128 (decimal128 x);
// decimal32 fabsd32 (decimal32 x); 
// decimal64 fabsd64 (decimal64 x); 
// decimal128 fabsd128 (decimal128 x);
// decimal32 hypotd32 (decimal32 x, decimal32 y); 
// decimal64 hypotd64 (decimal64 x, decimal64 y); 
// decimal128 hypotd128 (decimal128 x, decimal128 y);

decimal32 powd32(decimal32 x, decimal32 y); 
decimal64 powd64(decimal64 x, decimal64 y); 
decimal128 powd128(decimal128 x, decimal128 y);

decimal32 sqrtd32(decimal32 x); 
decimal64 sqrtd64(decimal64 x); 
decimal128 sqrtd128(decimal128 x);

// error and gamma functions: decimal32 erfd32 (decimal32 x); decimal64 erfd64 (decimal64 x); decimal128 erfd128 (decimal128 x);
// decimal32 erfcd32 (decimal32 x); 
// decimal64 erfcd64 (decimal64 x); 
// decimal128 erfcd128 (decimal128 x);
// decimal32 lgammad32 (decimal32 x); 
// decimal64 lgammad64 (decimal64 x); 
// decimal128 lgammad128 (decimal128 x);
// decimal32 tgammad32 (decimal32 x); 
// decimal64 tgammad64 (decimal64 x); 
// decimal128 tgammad128 (decimal128 x);

// // nearest integer functions: decimal32 ceild32 (decimal32 x); decimal64 ceild64 (decimal64 x); decimal128 ceild128 (decimal128 x);
// decimal32 floord32 (decimal32 x); 
// decimal64 floord64 (decimal64 x); 
// decimal128 floord128 (decimal128 x);
// decimal32 nearbyintd32 (decimal32 x); 
// decimal64 nearbyintd64 (decimal64 x); 
// decimal128 nearbyintd128 (decimal128 x);
// decimal32 rintd32 (decimal32 x); 
// decimal64 rintd64 (decimal64 x); 
// decimal128 rintd128 (decimal128 x);
// long int lrintd32 (decimal32 x); 
// long int lrintd64 (decimal64 x); 
// long int lrintd128 (decimal128 x);
// long long int llrintd32 (decimal32 x); 
// long long int llrintd64 (decimal64 x); 
// long long int llrintd128 (decimal128 x);
// decimal32 roundd32 (decimal32 x); 
// decimal64 roundd64 (decimal64 x); 
// decimal128 roundd128 (decimal128 x);
// long int lroundd32 (decimal32 x); 
// long int lroundd64 (decimal64 x); 
// long int lroundd128 (decimal128 x);
// long long int llroundd32 (decimal32 x); 
// long long int llroundd64 (decimal64 x); 
// long long int llroundd128 (decimal128 x);
// decimal32 truncd32 (decimal32 x); 
// decimal64 truncd64 (decimal64 x); 
// decimal128 truncd128 (decimal128 x);

// // remainder functions:
// decimal32 fmodd32 (decimal32 x, decimal32 y); 
// decimal64 fmodd64 (decimal64 x, decimal64 y); 
// decimal128 fmodd128 (decimal128 x, decimal128 y);
// decimal32 remainderd32 (decimal32 x, decimal32 y); 
// decimal64 remainderd64 (decimal64 x, decimal64 y); 
// decimal128 remainderd128 (decimal128 x, decimal128 y);
// decimal32 remquod32 (decimal32 x, decimal32 y, int * quo); 
// decimal64 remquod64 (decimal64 x, decimal64 y, int * quo); 
// decimal128 remquod128 (decimal128 x, decimal128 y, int * quo);

// // manipulation functions:
// decimal32 copysignd32 (decimal32 x, decimal32 y); 
// decimal64 copysignd64 (decimal64 x, decimal64 y);
// decimal128 copysignd128 (decimal128 x, decimal128 y);

// decimal32 nand32 (const char * tagp); 
// decimal64 nand64 (const char * tagp); 
// decimal128 nand128 (const char * tagp);

// decimal32 nextafterd32 (decimal32 x, decimal32 y); 
// decimal64 nextafterd64 (decimal64 x, decimal64 y); 
// decimal128 nextafterd128 (decimal128 x, decimal128 y);

// decimal32 nexttowardd32 (decimal32 x, decimal32 y); 
// decimal64 nexttowardd64 (decimal64 x, decimal64 y); 
// decimal128 nexttowardd128 (decimal128 x, decimal128 y);

// // maximum, minimum, and positive difference functions: 
// decimal32 fdimd32 (decimal32 x, decimal32 y); 
// decimal64 fdimd64 (decimal64 x, decimal64 y); 
// decimal128 fdimd128 (decimal128 x, decimal128 y);
// decimal32 fmaxd32 (decimal32 x, decimal32 y); 
// decimal64 fmaxd64 (decimal64 x, decimal64 y); 
// decimal128 fmaxd128 (decimal128 x, decimal128 y);
// decimal32 fmind32 (decimal32 x, decimal32 y); 
// decimal64 fmind64 (decimal64 x, decimal64 y); 
// decimal128 fmind128 (decimal128 x, decimal128 y);

// floating multiply-add:
decimal32 fmad32(decimal32 x, decimal32 y, decimal32 z); 
decimal64 fmad64(decimal64 x, decimal64 y, decimal64 z); 
decimal128 fmad128(decimal128 x, decimal128 y, decimal128 z);

// 3.6.6.1 abs function overloads 
decimal32 abs(decimal32 d); 
decimal64 abs(decimal64 d); 
decimal128 abs(decimal128 d);

}

}

#endif