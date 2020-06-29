#include <catch.hpp>
#include <libdecimal/decimal.hpp>
#include <thread>

using namespace std::decimal;

TEST_CASE("decimal", "decimal") 
{
    SECTION("fe_dec_getround and fe_dec_setround")
    {
        REQUIRE(fe_dec_getround() == FE_DEC_TONEAREST);

        REQUIRE(fe_dec_setround(FE_DEC_DOWNWARD) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_DOWNWARD);

        REQUIRE(fe_dec_setround(FE_DEC_TONEAREST) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_TONEAREST);

        REQUIRE(fe_dec_setround(FE_DEC_TONEARESTFROMZERO) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_TONEARESTFROMZERO);

        REQUIRE(fe_dec_setround(FE_DEC_TOWARD_ZERO) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_TOWARD_ZERO);

        REQUIRE(fe_dec_setround(FE_DEC_UPWARD) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_UPWARD);

        REQUIRE(fe_dec_setround(5) != 0);

        // TODO - behaviour tests
    }

    SECTION("fe_dec_getround and fe_dec_setround thread locality")
    {
        REQUIRE(fe_dec_setround(FE_DEC_TONEAREST) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_TONEAREST);
        auto thread = std::thread([]() {
            REQUIRE(fe_dec_getround() == FE_DEC_TONEAREST);
            REQUIRE(fe_dec_setround(FE_DEC_DOWNWARD) == 0);
            REQUIRE(fe_dec_getround() == FE_DEC_DOWNWARD);
        });
        thread.join();
        REQUIRE(fe_dec_setround(FE_DEC_TONEAREST) == 0);
        REQUIRE(fe_dec_getround() == FE_DEC_TONEAREST);
    }

    SECTION("fe_dec_clearexcept")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == 0);
        decimal32 one(1.0);
        one /= 0;
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == FE_DEC_DIVBYZERO);
    }

    SECTION("fe_dec_raiseexcept")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_ALL_EXCEPT);

        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_DIVBYZERO) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == FE_DEC_DIVBYZERO);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_DIVBYZERO);

        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_INEXACT) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_INEXACT) == FE_DEC_INEXACT);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_INEXACT);

        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_INVALID) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_INVALID) == FE_DEC_INVALID);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_INVALID);

        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_OVERFLOW) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_OVERFLOW) == FE_DEC_OVERFLOW);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_OVERFLOW);

        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_UNDERFLOW) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_UNDERFLOW) == FE_DEC_UNDERFLOW);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_UNDERFLOW);
    }

    SECTION("fe_dec_getexceptflag and fe_dec_setexceptflag")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_setexceptflag(0, 0) != 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_OVERFLOW) == 0);
        const std::decimal::fexcept_t input = FE_DEC_OVERFLOW;
        REQUIRE(fe_dec_setexceptflag(&input, FE_DEC_OVERFLOW) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_OVERFLOW) == FE_DEC_OVERFLOW);
        std::decimal::fexcept_t output;
        REQUIRE(fe_dec_getexceptflag(&output, FE_DEC_OVERFLOW) == 0);
    }

    SECTION("fe_dec_getenv and fe_dec_setenv")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_getenv(0) != 0);
        REQUIRE(fe_dec_setenv(0) != 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == 0);
        std::decimal::fenv_t env;
        REQUIRE(fe_dec_getenv(&env) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_DIVBYZERO) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == FE_DEC_DIVBYZERO);
        REQUIRE(fe_dec_setenv(&env) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == 0);
    }

    SECTION("fe_dec_holdexcept and fe_dec_updateenv")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_holdexcept(0) != 0);
        
        decimal32 one(1.0);
        one /= 0;
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_DIVBYZERO);

        std::decimal::fenv_t env;
        REQUIRE(fe_dec_holdexcept(&env) == 0);

        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == 0);
        decimal32 two(1.0);
        two /= 0;
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == 0);

        REQUIRE(fe_dec_updateenv(0) != 0);
        REQUIRE(fe_dec_updateenv(&env) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_DIVBYZERO);
    }


    SECTION("constructors")
    {
       REQUIRE(decimal32() == 0);
    }

    SECTION("makers")
    {
        REQUIRE(make_decimal32(10ll, -1) == 1);
        REQUIRE(make_decimal32(100ll, -2) == 1);
        REQUIRE(make_decimal32(10ll, 0) == 10);
        REQUIRE(make_decimal32(10ll, 1) == 100);
        REQUIRE(make_decimal32(100ll, 2) == 10000);

        REQUIRE(make_decimal64(10ll, -1) == 1);
        REQUIRE(make_decimal64(100ll, -2) == 1);
        REQUIRE(make_decimal64(10ll, 0) == 10);
        REQUIRE(make_decimal64(10ll, 1) == 100);
        REQUIRE(make_decimal64(100ll, 2) == 10000);

        // REQUIRE(make_decimal128(10ll, -1) == 1);
        // REQUIRE(make_decimal128(100ll, -2) == 1);
        // REQUIRE(make_decimal128(10ll, 0) == 10);
        // REQUIRE(make_decimal128(10ll, 1) == 100);
        // REQUIRE(make_decimal128(100ll, 2) == 10000);
    }

    SECTION("convertion to integral type")
    {
        decimal32 a(5);
        decimal64 b(5);
        decimal128 c(5);

        REQUIRE(static_cast<long long>(a) == 5.0f);
        REQUIRE(static_cast<float>(a) == 5.0f);
        REQUIRE(static_cast<double>(a) == 5.0);
        //REQUIRE(static_cast<long double>(a) == 5.0l);

        REQUIRE(static_cast<long long>(b) == 5.0f);
        REQUIRE(static_cast<float>(b) == 5.0f);
        REQUIRE(static_cast<double>(b) == 5.0);
        //REQUIRE(static_cast<long double>(b) == 5.0l);

        // REQUIRE(static_cast<long long>(c) == 5.0f);
        // REQUIRE(static_cast<float>(c) == 5.0f);
        // REQUIRE(static_cast<double>(c) == 5.0);
        // REQUIRE(static_cast<long double>(c) == 5.0l);
    }

    SECTION("decimal to long double")
    {
        REQUIRE(decimal32_to_float(decimal32(5)) == 5.0f); 
        REQUIRE(decimal_to_float(decimal32(5)) == 5.0f); 

        REQUIRE(decimal64_to_float(decimal64(5)) == 5.0f); 
        REQUIRE(decimal_to_float(decimal64(5)) == 5.0f); 

        REQUIRE(decimal128_to_float(decimal128(5)) == 5.0f); 
        REQUIRE(decimal_to_float(decimal128(5)) == 5.0f);

        REQUIRE(decimal32_to_double(decimal32(5)) == 5.0); 
        REQUIRE(decimal_to_double(decimal32(5)) == 5.0); 

        REQUIRE(decimal64_to_double (decimal64(5)) == 5.0); 
        REQUIRE(decimal_to_double(decimal64(5)) == 5.0); 

        // REQUIRE(decimal128_to_double(decimal128(5)) == 5.0l); 
        // REQUIRE(decimal_to_double(decimal128(5)) == 5.0l);

        // REQUIRE(decimal32_to_long_double(decimal32(5)) == 5.0l);
        // REQUIRE(decimal_to_long_double(decimal32(5)) == 5.0l);
        
        // REQUIRE(decimal64_to_long_double(decimal64(5)) == 5.0l);
        // REQUIRE(decimal_to_long_double(decimal64(5)) == 5.0l);

        // REQUIRE(decimal128_to_long_double(decimal128(5)) == 5.0l);
        // REQUIRE(decimal_to_long_double(decimal128(5)) == 5.0l);
    }

    SECTION("unary arithmetic")
    {
        REQUIRE(+decimal32(1) == 1);
        REQUIRE(+decimal64(1) == 1);
        REQUIRE(+decimal128(1) == 1);

        REQUIRE(+decimal32(-1) == -1);
        REQUIRE(+decimal64(-1) == -1);
        REQUIRE(+decimal128(-1) == -1);

        REQUIRE(+decimal32(0) == 0);
        REQUIRE(+decimal64(0) == 0);
        REQUIRE(+decimal128(0) == 0);

        REQUIRE(-decimal32(1) == -1);
        REQUIRE(-decimal64(1) == -1);
        REQUIRE(-decimal128(1) == -1);

        REQUIRE(-decimal32(-1) == 1);
        REQUIRE(-decimal64(-1) == 1);
        REQUIRE(-decimal128(-1) == 1);

        REQUIRE(-decimal32(0) == 0);
        REQUIRE(-decimal64(0) == 0);
        REQUIRE(-decimal128(0) == 0);
    }

    SECTION("binary addition")
    {
        REQUIRE(decimal32(1) + decimal32(2) == decimal32(3));
        REQUIRE(decimal32(1) + decimal64(2) == decimal64(3));
        REQUIRE(decimal32(1) + decimal128(2) == decimal128(3));

        REQUIRE(decimal64(1) + decimal32(2) == decimal64(3));
        REQUIRE(decimal64(1) + decimal64(2) == decimal64(3));
        REQUIRE(decimal64(1) + decimal128(2) == decimal128(3));

        REQUIRE(decimal128(1) + decimal32(2) == decimal128(3));
        REQUIRE(decimal128(1) + decimal64(2) == decimal128(3));
        REQUIRE(decimal128(1) + decimal128(2) == decimal128(3));

        REQUIRE(decimal32(1) + 2 == decimal32(3));
        REQUIRE(decimal32(1) + 2u == decimal32(3));
        REQUIRE(decimal32(1) + 2l == decimal64(3));
        REQUIRE(decimal32(1) + 2lu == decimal64(3));
        REQUIRE(decimal32(1) + 2ll == decimal128(3));
        REQUIRE(decimal32(1) + 2llu == decimal128(3));
        REQUIRE(decimal32(1) + 2.0f == decimal32(3));
        REQUIRE(decimal32(1) + 2.0 == decimal64(3));
        // REQUIRE(decimal32(1) + 2.0l == decimal128(3));

        REQUIRE(1 + decimal32(2) == decimal32(3));
        REQUIRE(1u + decimal32(2) == decimal32(3));
        REQUIRE(1l + decimal32(2) == decimal64(3));
        REQUIRE(1lu + decimal32(2) == decimal64(3));
        REQUIRE(1ll + decimal32(2) == decimal128(3));
        REQUIRE(1llu + decimal32(2) == decimal128(3));
        REQUIRE(1.0f + decimal32(2) == decimal32(3));
        REQUIRE(1.0 + decimal32(2) == decimal64(3));
        // REQUIRE(1.0l + decimal32(2) == decimal128(3));

        REQUIRE(decimal64(1) + 2 == decimal64(3));
        REQUIRE(decimal64(1) + 2u == decimal64(3));
        REQUIRE(decimal64(1) + 2l == decimal64(3));
        REQUIRE(decimal64(1) + 2lu == decimal64(3));
        REQUIRE(decimal64(1) + 2ll == decimal128(3));
        REQUIRE(decimal64(1) + 2llu == decimal128(3));
        REQUIRE(decimal64(1) + 2.0f == decimal64(3));
        REQUIRE(decimal64(1) + 2.0 == decimal64(3));
        // REQUIRE(decimal64(1) + 2.0l == decimal128(3));

        REQUIRE(1 + decimal64(2) == decimal64(3));
        REQUIRE(1u + decimal64(2) == decimal64(3));
        REQUIRE(1l + decimal64(2) == decimal64(3));
        REQUIRE(1lu + decimal64(2) == decimal64(3));
        REQUIRE(1ll + decimal64(2) == decimal128(3));
        REQUIRE(1llu + decimal64(2) == decimal128(3));
        REQUIRE(1.0f + decimal64(2) == decimal64(3));
        REQUIRE(1.0 + decimal64(2) == decimal64(3));
        // REQUIRE(1.0l + decimal64(2) == decimal128(3));

        REQUIRE(decimal128(1) + 2 == decimal128(3));
        REQUIRE(decimal128(1) + 2u == decimal128(3));
        REQUIRE(decimal128(1) + 2l == decimal128(3));
        REQUIRE(decimal128(1) + 2lu == decimal128(3));
        REQUIRE(decimal128(1) + 2ll == decimal128(3));
        REQUIRE(decimal128(1) + 2llu == decimal128(3));
        REQUIRE(decimal128(1) + 2.0f == decimal128(3));
        REQUIRE(decimal128(1) + 2.0 == decimal128(3));
        // REQUIRE(decimal128(1) + 2.0l == decimal128(3));

        REQUIRE(1 + decimal128(2) == decimal128(3));
        REQUIRE(1u + decimal128(2) == decimal128(3));
        REQUIRE(1l + decimal128(2) == decimal128(3));
        REQUIRE(1lu + decimal128(2) == decimal128(3));
        REQUIRE(1ll + decimal128(2) == decimal128(3));
        REQUIRE(1llu + decimal128(2) == decimal128(3));
        REQUIRE(1.0f + decimal128(2) == decimal128(3));
        REQUIRE(1.0 + decimal128(2) == decimal128(3));
        // REQUIRE(1.0l + decimal128(2) == decimal128(3));
    }

    SECTION("binary subtraction")
    {
        REQUIRE(decimal32(3) - decimal32(2) == decimal32(1));
        REQUIRE(decimal32(3) - decimal64(2) == decimal32(1));
        REQUIRE(decimal32(3) - decimal128(2) == decimal32(1));

        REQUIRE(decimal64(3) - decimal32(2) == decimal64(1));
        REQUIRE(decimal64(3) - decimal64(2) == decimal64(1));
        REQUIRE(decimal64(3) - decimal128(2) == decimal64(1));
        
        REQUIRE(decimal128(3) - decimal32(2) == decimal128(1));
        REQUIRE(decimal128(3) - decimal64(2) == decimal128(1));
        REQUIRE(decimal128(3) - decimal128(2) == decimal128(1));

        REQUIRE(decimal32(3) - 2 == decimal32(1));
        REQUIRE(decimal32(3) - 2u == decimal32(1));
        REQUIRE(decimal32(3) - 2l == decimal64(1));
        REQUIRE(decimal32(3) - 2lu == decimal64(1));
        REQUIRE(decimal32(3) - 2ll == decimal128(1));
        REQUIRE(decimal32(3) - 2llu == decimal128(1));
        REQUIRE(decimal32(3) - 2.0f == decimal32(1));
        REQUIRE(decimal32(3) - 2.0 == decimal64(1));
        // REQUIRE(decimal32(3) - 2.0l == decimal128(1));

        REQUIRE(3 - decimal32(2) == decimal32(1));
        REQUIRE(3u - decimal32(2) == decimal32(1));
        REQUIRE(3l - decimal32(2) == decimal64(1));
        REQUIRE(3lu - decimal32(2) == decimal64(1));
        REQUIRE(3ll - decimal32(2) == decimal128(1));
        REQUIRE(3llu - decimal32(2) == decimal128(1));
        REQUIRE(3.0f - decimal32(2) == decimal32(1));
        REQUIRE(3.0 - decimal32(2) == decimal64(1));
        // REQUIRE(3.0l - decimal32(2) == decimal128(1));

        REQUIRE(decimal64(3) - 2 == decimal64(1));
        REQUIRE(decimal64(3) - 2u == decimal64(1));
        REQUIRE(decimal64(3) - 2l == decimal64(1));
        REQUIRE(decimal64(3) - 2lu == decimal64(1));
        REQUIRE(decimal64(3) - 2ll == decimal128(1));
        REQUIRE(decimal64(3) - 2llu == decimal128(1));
        REQUIRE(decimal64(3) - 2.0f == decimal64(1));
        REQUIRE(decimal64(3) - 2.0 == decimal64(1));
        // REQUIRE(decimal64(3) - 2.0l == decimal128(1));

        REQUIRE(3 - decimal64(2) == decimal64(1));
        REQUIRE(3u - decimal64(2) == decimal64(1));
        REQUIRE(3l - decimal64(2) == decimal64(1));
        REQUIRE(3lu - decimal64(2) == decimal64(1));
        REQUIRE(3ll - decimal64(2) == decimal128(1));
        REQUIRE(3llu - decimal64(2) == decimal128(1));
        REQUIRE(3.0f - decimal64(2) == decimal64(1));
        REQUIRE(3.0 - decimal64(2) == decimal64(1));
        // REQUIRE(3.0l - decimal64(2) == decimal128(1));

        REQUIRE(decimal128(3) - 2 == decimal128(1));
        REQUIRE(decimal128(3) - 2u == decimal128(1));
        REQUIRE(decimal128(3) - 2l == decimal128(1));
        REQUIRE(decimal128(3) - 2lu == decimal128(1));
        REQUIRE(decimal128(3) - 2ll == decimal128(1));
        REQUIRE(decimal128(3) - 2llu == decimal128(1));
        REQUIRE(decimal128(3) - 2.0f == decimal128(1));
        REQUIRE(decimal128(3) - 2.0 == decimal128(1));
        // REQUIRE(decimal128(3) - 2.0l == decimal128(1));

        REQUIRE(3 - decimal128(2) == decimal128(1));
        REQUIRE(3u - decimal128(2) == decimal128(1));
        REQUIRE(3l - decimal128(2) == decimal128(1));
        REQUIRE(3lu - decimal128(2) == decimal128(1));
        REQUIRE(3ll - decimal128(2) == decimal128(1));
        REQUIRE(3llu - decimal128(2) == decimal128(1));
        REQUIRE(3.0f - decimal128(2) == decimal128(1));
        REQUIRE(3.0 - decimal128(2) == decimal128(1));
        // REQUIRE(3.0l - decimal128(2) == decimal128(1));
    }

    SECTION("binary multiplication")
    {
        REQUIRE(decimal32(2) * decimal32(3) == decimal32(6));
        REQUIRE(decimal32(2) * decimal64(3) == decimal64(6));
        REQUIRE(decimal32(2) * decimal128(3) == decimal128(6));

        REQUIRE(decimal64(2) * decimal32(3) == decimal64(6));
        REQUIRE(decimal64(2) * decimal64(3) == decimal64(6));
        REQUIRE(decimal64(2) * decimal128(3) == decimal128(6));
        
        REQUIRE(decimal128(2) * decimal32(3) == decimal128(6));
        REQUIRE(decimal128(2) * decimal64(3) == decimal128(6));
        REQUIRE(decimal128(2) * decimal128(3) == decimal128(6));
    
        REQUIRE(decimal32(2) * 3 == decimal32(6));
        REQUIRE(decimal32(2) * 3u == decimal32(6));
        REQUIRE(decimal32(2) * 3l == decimal64(6));
        REQUIRE(decimal32(2) * 3lu == decimal64(6));
        REQUIRE(decimal32(2) * 3ll == decimal128(6));
        REQUIRE(decimal32(2) * 3llu == decimal128(6));
        REQUIRE(decimal32(2) * 3.0f == decimal32(6));
        REQUIRE(decimal32(2) * 3.0 == decimal64(6));
        // REQUIRE(decimal32(2) * 3.0l == decimal128(6));

        REQUIRE(2 * decimal32(3) == decimal32(6));
        REQUIRE(2u * decimal32(3) == decimal32(6));
        REQUIRE(2l * decimal32(3) == decimal64(6));
        REQUIRE(2lu * decimal32(3) == decimal64(6));
        REQUIRE(2ll * decimal32(3) == decimal128(6));
        REQUIRE(2llu * decimal32(3) == decimal128(6));
        REQUIRE(2.0f * decimal32(3) == decimal32(6));
        REQUIRE(2.0 * decimal32(3) == decimal64(6));
        // REQUIRE(2.0l * decimal32(3) == decimal128(6));

        REQUIRE(decimal64(2) * 3 == decimal64(6));
        REQUIRE(decimal64(2) * 3u == decimal64(6));
        REQUIRE(decimal64(2) * 3l == decimal64(6));
        REQUIRE(decimal64(2) * 3lu == decimal64(6));
        REQUIRE(decimal64(2) * 3ll == decimal128(6));
        REQUIRE(decimal64(2) * 3llu == decimal128(6));
        REQUIRE(decimal64(2) * 3.0f == decimal64(6));
        REQUIRE(decimal64(2) * 3.0 == decimal64(6));
        // REQUIRE(decimal64(2) * 3.0l == decimal128(6));

        REQUIRE(2 * decimal64(3) == decimal64(6));
        REQUIRE(2u * decimal64(3) == decimal64(6));
        REQUIRE(2l * decimal64(3) == decimal64(6));
        REQUIRE(2lu * decimal64(3) == decimal64(6));
        REQUIRE(2ll * decimal64(3) == decimal128(6));
        REQUIRE(2llu * decimal64(3) == decimal128(6));
        REQUIRE(2.0f * decimal64(3) == decimal64(6));
        REQUIRE(2.0 * decimal64(3) == decimal64(6));
        // REQUIRE(2.0l * decimal64(3) == decimal128(6));

        REQUIRE(decimal128(2) * 3 == decimal128(6));
        REQUIRE(decimal128(2) * 3u == decimal128(6));
        REQUIRE(decimal128(2) * 3l == decimal128(6));
        REQUIRE(decimal128(2) * 3lu == decimal128(6));
        REQUIRE(decimal128(2) * 3ll == decimal128(6));
        REQUIRE(decimal128(2) * 3llu == decimal128(6));
        REQUIRE(decimal128(2) * 3.0f == decimal128(6));
        REQUIRE(decimal128(2) * 3.0 == decimal128(6));
        // REQUIRE(decimal128(2) * 3.0l == decimal128(6));

        REQUIRE(2 * decimal128(3) == decimal128(6));
        REQUIRE(2u * decimal128(3) == decimal128(6));
        REQUIRE(2l * decimal128(3) == decimal128(6));
        REQUIRE(2lu * decimal128(3) == decimal128(6));
        REQUIRE(2ll * decimal128(3) == decimal128(6));
        REQUIRE(2llu * decimal128(3) == decimal128(6));
        REQUIRE(2.0f * decimal128(3) == decimal128(6));
        REQUIRE(2.0 * decimal128(3) == decimal128(6));
        // REQUIRE(2.0l * decimal128(3) == decimal128(6));
    }

    SECTION("binary division")
    {
        REQUIRE(decimal32(6) / decimal32(2) == decimal32(3));
        REQUIRE(decimal32(6) / decimal64(2) == decimal64(3));
        REQUIRE(decimal32(6) / decimal128(2) == decimal128(3));

        REQUIRE(decimal64(6) / decimal32(2) == decimal64(3));
        REQUIRE(decimal64(6) / decimal64(2) == decimal64(3));
        REQUIRE(decimal64(6) / decimal128(2) == decimal128(3));
        
        REQUIRE(decimal128(6) / decimal32(2) == decimal128(3));
        REQUIRE(decimal128(6) / decimal64(2) == decimal128(3));
        REQUIRE(decimal128(6) / decimal128(2) == decimal128(3));

        REQUIRE(decimal32(6) / 2 == decimal32(3));
        REQUIRE(decimal32(6) / 2u == decimal32(3));
        REQUIRE(decimal32(6) / 2l == decimal64(3));
        REQUIRE(decimal32(6) / 2lu == decimal64(3));
        REQUIRE(decimal32(6) / 2ll == decimal128(3));
        REQUIRE(decimal32(6) / 2llu == decimal128(3));
        REQUIRE(decimal32(6) / 2.0f == decimal32(3));
        REQUIRE(decimal32(6) / 2.0 == decimal64(3));
        // REQUIRE(decimal32(6) / 2.0l == decimal128(3));

        REQUIRE(6 / decimal32(2) == decimal32(3));
        REQUIRE(6u / decimal32(2) == decimal32(3));
        REQUIRE(6l / decimal32(2) == decimal64(3));
        REQUIRE(6lu / decimal32(2) == decimal64(3));
        REQUIRE(6ll / decimal32(2) == decimal128(3));
        REQUIRE(6llu / decimal32(2) == decimal128(3));
        REQUIRE(6.0f / decimal32(2) == decimal32(3));
        REQUIRE(6.0 / decimal32(2) == decimal64(3));
        // REQUIRE(6.0l / decimal32(2) == decimal128(3));

        REQUIRE(decimal64(6) / 2 == decimal64(3));
        REQUIRE(decimal64(6) / 2u == decimal64(3));
        REQUIRE(decimal64(6) / 2l == decimal64(3));
        REQUIRE(decimal64(6) / 2lu == decimal64(3));
        REQUIRE(decimal64(6) / 2ll == decimal128(3));
        REQUIRE(decimal64(6) / 2llu == decimal128(3));
        REQUIRE(decimal64(6) / 2.0f == decimal64(3));
        REQUIRE(decimal64(6) / 2.0 == decimal64(3));
        // REQUIRE(decimal64(6) / 2.0l == decimal128(3));

        REQUIRE(6 / decimal64(2) == decimal64(3));
        REQUIRE(6u / decimal64(2) == decimal64(3));
        REQUIRE(6l / decimal64(2) == decimal64(3));
        REQUIRE(6lu / decimal64(2) == decimal64(3));
        REQUIRE(6ll / decimal64(2) == decimal128(3));
        REQUIRE(6llu / decimal64(2) == decimal128(3));
        REQUIRE(6.0f / decimal64(2) == decimal64(3));
        REQUIRE(6.0 / decimal64(2) == decimal64(3));
        // REQUIRE(6.0l / decimal64(2) == decimal128(3));

        REQUIRE(decimal128(6) / 2 == decimal128(3));
        REQUIRE(decimal128(6) / 2u == decimal128(3));
        REQUIRE(decimal128(6) / 2l == decimal128(3));
        REQUIRE(decimal128(6) / 2lu == decimal128(3));
        REQUIRE(decimal128(6) / 2ll == decimal128(3));
        REQUIRE(decimal128(6) / 2llu == decimal128(3));
        REQUIRE(decimal128(6) / 2.0f == decimal128(3));
        REQUIRE(decimal128(6) / 2.0 == decimal128(3));
        // REQUIRE(decimal128(6) / 2.0l == decimal128(3));

        REQUIRE(6 / decimal128(2) == decimal128(3));
        REQUIRE(6u / decimal128(2) == decimal128(3));
        REQUIRE(6l / decimal128(2) == decimal128(3));
        REQUIRE(6lu / decimal128(2) == decimal128(3));
        REQUIRE(6ll / decimal128(2) == decimal128(3));
        REQUIRE(6llu / decimal128(2) == decimal128(3));
        REQUIRE(6.0f / decimal128(2) == decimal128(3));
        REQUIRE(6.0 / decimal128(2) == decimal128(3));
        // REQUIRE(6.0l / decimal128(2) == decimal128(3));
    }

    SECTION("binary equal")
    {
        REQUIRE(decimal32(0) == decimal32(0));
        REQUIRE(decimal32(0) == decimal64(0));
        REQUIRE(decimal32(0) == decimal128(0));

        REQUIRE(decimal64(0) == decimal32(0));
        REQUIRE(decimal64(0) == decimal64(0));
        REQUIRE(decimal64(0) == decimal128(0));
        
        REQUIRE(decimal128(0) == decimal32(0));
        REQUIRE(decimal128(0) == decimal64(0));
        REQUIRE(decimal128(0) == decimal128(0));

        REQUIRE(decimal32(0) == 0);
        REQUIRE(decimal32(0) == 0u);
        REQUIRE(decimal32(0) == 0l);
        REQUIRE(decimal32(0) == 0lu);
        REQUIRE(decimal32(0) == 0ll);
        REQUIRE(decimal32(0) == 0llu);
        REQUIRE(decimal32(0) == 0.0f);
        REQUIRE(decimal32(0) == 0.0);
        REQUIRE(decimal32(0) == 0.0l);

        REQUIRE(0 == decimal32(0));
        REQUIRE(0u == decimal32(0));
        REQUIRE(0l == decimal32(0));
        REQUIRE(0lu == decimal32(0));
        REQUIRE(0ll == decimal32(0));
        REQUIRE(0llu == decimal32(0));
        REQUIRE(0.0f == decimal32(0));
        REQUIRE(0.0 == decimal32(0));
        REQUIRE(0.0l == decimal32(0));

        REQUIRE(decimal64(0) == 0);
        REQUIRE(decimal64(0) == 0u);
        REQUIRE(decimal64(0) == 0l);
        REQUIRE(decimal64(0) == 0lu);
        REQUIRE(decimal64(0) == 0ll);
        REQUIRE(decimal64(0) == 0llu);
        REQUIRE(decimal64(0) == 0.0f);
        REQUIRE(decimal64(0) == 0.0);
        REQUIRE(decimal64(0) == 0.0l);

        REQUIRE(0 == decimal64(0));
        REQUIRE(0u == decimal64(0));
        REQUIRE(0l == decimal64(0));
        REQUIRE(0lu == decimal64(0));
        REQUIRE(0ll == decimal64(0));
        REQUIRE(0llu == decimal64(0));
        REQUIRE(0.0f == decimal64(0));
        REQUIRE(0.0 == decimal64(0));
        REQUIRE(0.0l == decimal64(0));

        REQUIRE(decimal128(0) == 0);
        REQUIRE(decimal128(0) == 0u);
        REQUIRE(decimal128(0) == 0l);
        REQUIRE(decimal128(0) == 0lu);
        REQUIRE(decimal128(0) == 0ll);
        REQUIRE(decimal128(0) == 0llu);
        REQUIRE(decimal128(0) == 0.0f);
        REQUIRE(decimal128(0) == 0.0);
        REQUIRE(decimal128(0) == 0.0l);

        REQUIRE(0 == decimal128(0));
        REQUIRE(0u == decimal128(0));
        REQUIRE(0l == decimal128(0));
        REQUIRE(0lu == decimal128(0));
        REQUIRE(0ll == decimal128(0));
        REQUIRE(0llu == decimal128(0));
        REQUIRE(0.0f == decimal128(0));
        REQUIRE(0.0 == decimal128(0));
        REQUIRE(0.0l == decimal128(0));
    }

    SECTION("binary not equal")
    {
        REQUIRE(decimal32(0) != decimal32(1));
        REQUIRE(decimal32(0) != decimal64(1));
        REQUIRE(decimal32(0) != decimal128(1));

        REQUIRE(decimal64(0) != decimal32(1));
        REQUIRE(decimal64(0) != decimal64(1));
        REQUIRE(decimal64(0) != decimal128(1));
        
        REQUIRE(decimal128(0) != decimal32(1));
        REQUIRE(decimal128(0) != decimal64(1));
        REQUIRE(decimal128(0) != decimal128(1));

        REQUIRE(decimal32(0) != 1);
        REQUIRE(decimal32(0) != 1u);
        REQUIRE(decimal32(0) != 1l);
        REQUIRE(decimal32(0) != 1lu);
        REQUIRE(decimal32(0) != 1ll);
        REQUIRE(decimal32(0) != 1llu);
        REQUIRE(decimal32(0) != 1.0f);
        REQUIRE(decimal32(0) != 1.0);
        // REQUIRE(decimal32(0) != 1.0l);

        REQUIRE(0 != decimal32(1));
        REQUIRE(0u != decimal32(1));
        REQUIRE(0l != decimal32(1));
        REQUIRE(0lu != decimal32(1));
        REQUIRE(0ll != decimal32(1));
        REQUIRE(0llu != decimal32(1));
        REQUIRE(0.0f != decimal32(1));
        REQUIRE(0.0 != decimal32(1));
        // REQUIRE(0.0l != decimal32(1));

        REQUIRE(decimal64(0) != 1);
        REQUIRE(decimal64(0) != 1u);
        REQUIRE(decimal64(0) != 1l);
        REQUIRE(decimal64(0) != 1lu);
        REQUIRE(decimal64(0) != 1ll);
        REQUIRE(decimal64(0) != 1llu);
        REQUIRE(decimal64(0) != 1.0f);
        REQUIRE(decimal64(0) != 1.0);
        // REQUIRE(decimal64(0) != 1.0l);

        REQUIRE(0 != decimal64(1));
        REQUIRE(0u != decimal64(1));
        REQUIRE(0l != decimal64(1));
        REQUIRE(0lu != decimal64(1));
        REQUIRE(0ll != decimal64(1));
        REQUIRE(0llu != decimal64(1));
        REQUIRE(0.0f != decimal64(1));
        REQUIRE(0.0 != decimal64(1));
        // REQUIRE(0.0l != decimal64(1));

        REQUIRE(decimal128(0) != 1);
        REQUIRE(decimal128(0) != 1u);
        REQUIRE(decimal128(0) != 1l);
        REQUIRE(decimal128(0) != 1lu);
        REQUIRE(decimal128(0) != 1ll);
        REQUIRE(decimal128(0) != 1llu);
        REQUIRE(decimal128(0) != 1.0f);
        REQUIRE(decimal128(0) != 1.0);
        // REQUIRE(decimal128(0) != 1.0l);

        REQUIRE(0 != decimal128(1));
        REQUIRE(0u != decimal128(1));
        REQUIRE(0l != decimal128(1));
        REQUIRE(0lu != decimal128(1));
        REQUIRE(0ll != decimal128(1));
        REQUIRE(0llu != decimal128(1));
        REQUIRE(0.0f != decimal128(1));
        REQUIRE(0.0 != decimal128(1));
        // REQUIRE(0.0l != decimal128(1));
    }

    SECTION("binary less")
    {
        REQUIRE(decimal32(0) < decimal32(1));
        REQUIRE(decimal32(0) < decimal64(1));
        REQUIRE(decimal32(0) < decimal128(1));

        REQUIRE(decimal64(0) < decimal32(1));
        REQUIRE(decimal64(0) < decimal64(1));
        REQUIRE(decimal64(0) < decimal128(1));
        
        REQUIRE(decimal128(0) < decimal32(1));
        REQUIRE(decimal128(0) < decimal64(1));
        REQUIRE(decimal128(0) < decimal128(1));

        REQUIRE(decimal32(0) < 1);
        REQUIRE(decimal32(0) < 1u);
        REQUIRE(decimal32(0) < 1l);
        REQUIRE(decimal32(0) < 1lu);
        REQUIRE(decimal32(0) < 1ll);
        REQUIRE(decimal32(0) < 1llu);
        REQUIRE(decimal32(0) < 1.0f);
        REQUIRE(decimal32(0) < 1.0);
        // REQUIRE(decimal32(0) < 1.0l);

        REQUIRE(0 < decimal32(1));
        REQUIRE(0u < decimal32(1));
        REQUIRE(0l < decimal32(1));
        REQUIRE(0lu < decimal32(1));
        REQUIRE(0ll < decimal32(1));
        REQUIRE(0llu < decimal32(1));
        REQUIRE(0.0f < decimal32(1));
        REQUIRE(0.0 < decimal32(1));
        // REQUIRE(0.0l < decimal32(1));

        REQUIRE(decimal64(0) < 1);
        REQUIRE(decimal64(0) < 1u);
        REQUIRE(decimal64(0) < 1l);
        REQUIRE(decimal64(0) < 1lu);
        REQUIRE(decimal64(0) < 1ll);
        REQUIRE(decimal64(0) < 1llu);
        REQUIRE(decimal64(0) < 1.0f);
        REQUIRE(decimal64(0) < 1.0);
        // REQUIRE(decimal64(0) < 1.0l);

        REQUIRE(0 < decimal64(1));
        REQUIRE(0u < decimal64(1));
        REQUIRE(0l < decimal64(1));
        REQUIRE(0lu < decimal64(1));
        REQUIRE(0ll < decimal64(1));
        REQUIRE(0llu < decimal64(1));
        REQUIRE(0.0f < decimal64(1));
        REQUIRE(0.0 < decimal64(1));
        // REQUIRE(0.0l < decimal64(1));

        REQUIRE(decimal128(0) < 1);
        REQUIRE(decimal128(0) < 1u);
        REQUIRE(decimal128(0) < 1l);
        REQUIRE(decimal128(0) < 1lu);
        REQUIRE(decimal128(0) < 1ll);
        REQUIRE(decimal128(0) < 1llu);
        REQUIRE(decimal128(0) < 1.0f);
        REQUIRE(decimal128(0) < 1.0);
        // REQUIRE(decimal128(0) < 1.0l);

        REQUIRE(0 < decimal128(1));
        REQUIRE(0u < decimal128(1));
        REQUIRE(0l < decimal128(1));
        REQUIRE(0lu < decimal128(1));
        REQUIRE(0ll < decimal128(1));
        REQUIRE(0llu < decimal128(1));
        REQUIRE(0.0f < decimal128(1));
        REQUIRE(0.0 < decimal128(1));
        // REQUIRE(0.0l < decimal128(1));
    }

    SECTION("binary less than or equal")
    {
        REQUIRE(decimal32(0) <= decimal32(1));
        REQUIRE(decimal32(0) <= decimal64(1));
        REQUIRE(decimal32(0) <= decimal128(1));

        REQUIRE(decimal64(0) <= decimal32(1));
        REQUIRE(decimal64(0) <= decimal64(1));
        REQUIRE(decimal64(0) <= decimal128(1));
        
        REQUIRE(decimal128(0) <= decimal32(1));
        REQUIRE(decimal128(0) <= decimal64(1));
        REQUIRE(decimal128(0) <= decimal128(1));

        REQUIRE(decimal32(0) <= 1);
        REQUIRE(decimal32(0) <= 1u);
        REQUIRE(decimal32(0) <= 1l);
        REQUIRE(decimal32(0) <= 1lu);
        REQUIRE(decimal32(0) <= 1ll);
        REQUIRE(decimal32(0) <= 1llu);
        REQUIRE(decimal32(0) <= 1.0f);
        REQUIRE(decimal32(0) <= 1.0);
        REQUIRE(decimal32(0) <= 1.0l);

        REQUIRE(0 <= decimal32(1));
        REQUIRE(0u <= decimal32(1));
        REQUIRE(0l <= decimal32(1));
        REQUIRE(0lu <= decimal32(1));
        REQUIRE(0ll <= decimal32(1));
        REQUIRE(0llu <= decimal32(1));
        REQUIRE(0.0f <= decimal32(1));
        REQUIRE(0.0 <= decimal32(1));
        REQUIRE(0.0l <= decimal32(1));

        REQUIRE(decimal64(0) <= 1);
        REQUIRE(decimal64(0) <= 1u);
        REQUIRE(decimal64(0) <= 1l);
        REQUIRE(decimal64(0) <= 1lu);
        REQUIRE(decimal64(0) <= 1ll);
        REQUIRE(decimal64(0) <= 1llu);
        REQUIRE(decimal64(0) <= 1.0f);
        REQUIRE(decimal64(0) <= 1.0);
        REQUIRE(decimal64(0) <= 1.0l);

        REQUIRE(0 <= decimal64(1));
        REQUIRE(0u <= decimal64(1));
        REQUIRE(0l <= decimal64(1));
        REQUIRE(0lu <= decimal64(1));
        REQUIRE(0ll <= decimal64(1));
        REQUIRE(0llu <= decimal64(1));
        REQUIRE(0.0f <= decimal64(1));
        REQUIRE(0.0 <= decimal64(1));
        REQUIRE(0.0l <= decimal64(1));

        REQUIRE(decimal128(0) <= 1);
        REQUIRE(decimal128(0) <= 1u);
        REQUIRE(decimal128(0) <= 1l);
        REQUIRE(decimal128(0) <= 1lu);
        REQUIRE(decimal128(0) <= 1ll);
        REQUIRE(decimal128(0) <= 1llu);
        REQUIRE(decimal128(0) <= 1.0f);
        REQUIRE(decimal128(0) <= 1.0);
        REQUIRE(decimal128(0) <= 1.0l);

        REQUIRE(0 <= decimal128(1));
        REQUIRE(0u <= decimal128(1));
        REQUIRE(0l <= decimal128(1));
        REQUIRE(0lu <= decimal128(1));
        REQUIRE(0ll <= decimal128(1));
        REQUIRE(0llu <= decimal128(1));
        REQUIRE(0.0f <= decimal128(1));
        REQUIRE(0.0 <= decimal128(1));
        REQUIRE(0.0l <= decimal128(1));
    }

    SECTION("binary greater")
    {
        REQUIRE(decimal32(1) > decimal32(0));
        REQUIRE(decimal32(1) > decimal64(0));
        REQUIRE(decimal32(1) > decimal128(0));

        REQUIRE(decimal64(1) > decimal32(0));
        REQUIRE(decimal64(1) > decimal64(0));
        REQUIRE(decimal64(1) > decimal128(0));
        
        REQUIRE(decimal128(1) > decimal32(0));
        REQUIRE(decimal128(1) > decimal64(0));
        REQUIRE(decimal128(1) > decimal128(0));

        REQUIRE(decimal32(1) > 0);
        REQUIRE(decimal32(1) > 0u);
        REQUIRE(decimal32(1) > 0l);
        REQUIRE(decimal32(1) > 0lu);
        REQUIRE(decimal32(1) > 0ll);
        REQUIRE(decimal32(1) > 0llu);
        REQUIRE(decimal32(1) > 0.0f);
        REQUIRE(decimal32(1) > 0.0);
        // REQUIRE(decimal32(1) > 0.0l);

        REQUIRE(1 > decimal32(0));
        REQUIRE(1u > decimal32(0));
        REQUIRE(1l > decimal32(0));
        REQUIRE(1lu > decimal32(0));
        REQUIRE(1ll > decimal32(0));
        REQUIRE(1llu > decimal32(0));
        REQUIRE(1.0f > decimal32(0));
        REQUIRE(1.0 > decimal32(0));
        // REQUIRE(1.0l > decimal32(0));

        REQUIRE(decimal64(1) > 0);
        REQUIRE(decimal64(1) > 0u);
        REQUIRE(decimal64(1) > 0l);
        REQUIRE(decimal64(1) > 0lu);
        REQUIRE(decimal64(1) > 0ll);
        REQUIRE(decimal64(1) > 0llu);
        REQUIRE(decimal64(1) > 0.0f);
        REQUIRE(decimal64(1) > 0.0);
        // REQUIRE(decimal64(1) > 0.0l);

        REQUIRE(1 > decimal64(0));
        REQUIRE(1u > decimal64(0));
        REQUIRE(1l > decimal64(0));
        REQUIRE(1lu > decimal64(0));
        REQUIRE(1ll > decimal64(0));
        REQUIRE(1llu > decimal64(0));
        REQUIRE(1.0f > decimal64(0));
        REQUIRE(1.0 > decimal64(0));
        // REQUIRE(1.0l > decimal64(0));

        REQUIRE(decimal128(1) > 0);
        REQUIRE(decimal128(1) > 0u);
        REQUIRE(decimal128(1) > 0l);
        REQUIRE(decimal128(1) > 0lu);
        REQUIRE(decimal128(1) > 0ll);
        REQUIRE(decimal128(1) > 0llu);
        REQUIRE(decimal128(1) > 0.0f);
        REQUIRE(decimal128(1) > 0.0);
        // REQUIRE(decimal128(1) > 0.0l);

        REQUIRE(1 > decimal128(0));
        REQUIRE(1u > decimal128(0));
        REQUIRE(1l > decimal128(0));
        REQUIRE(1lu > decimal128(0));
        REQUIRE(1ll > decimal128(0));
        REQUIRE(1llu > decimal128(0));
        REQUIRE(1.0f > decimal128(0));
        REQUIRE(1.0 > decimal128(0));
        // REQUIRE(1.0l > decimal128(0));
    }

    SECTION("binary greater than or equal")
    {
        REQUIRE(decimal32(1) >= decimal32(0));
        REQUIRE(decimal32(1) >= decimal64(0));
        REQUIRE(decimal32(1) >= decimal128(0));

        REQUIRE(decimal64(1) >= decimal32(0));
        REQUIRE(decimal64(1) >= decimal64(0));
        REQUIRE(decimal64(1) >= decimal128(0));
        
        REQUIRE(decimal128(1) >= decimal32(0));
        REQUIRE(decimal128(1) >= decimal64(0));
        REQUIRE(decimal128(1) >= decimal128(0));

        REQUIRE(decimal32(1) >= 0);
        REQUIRE(decimal32(1) >= 0u);
        REQUIRE(decimal32(1) >= 0l);
        REQUIRE(decimal32(1) >= 0lu);
        REQUIRE(decimal32(1) >= 0ll);
        REQUIRE(decimal32(1) >= 0llu);
        REQUIRE(decimal32(1) >= 0.0f);
        REQUIRE(decimal32(1) >= 0.0);
        REQUIRE(decimal32(1) >= 0.0l);

        REQUIRE(1 >= decimal32(0));
        REQUIRE(1u >= decimal32(0));
        REQUIRE(1l >= decimal32(0));
        REQUIRE(1lu >= decimal32(0));
        REQUIRE(1ll >= decimal32(0));
        REQUIRE(1llu >= decimal32(0));
        REQUIRE(1.0f >= decimal32(0));
        REQUIRE(1.0 >= decimal32(0));
        REQUIRE(1.0l >= decimal32(0));

        REQUIRE(decimal64(1) >= 0);
        REQUIRE(decimal64(1) >= 0u);
        REQUIRE(decimal64(1) >= 0l);
        REQUIRE(decimal64(1) >= 0lu);
        REQUIRE(decimal64(1) >= 0ll);
        REQUIRE(decimal64(1) >= 0llu);
        REQUIRE(decimal64(1) >= 0.0f);
        REQUIRE(decimal64(1) >= 0.0);
        REQUIRE(decimal64(1) >= 0.0l);

        REQUIRE(1 >= decimal64(0));
        REQUIRE(1u >= decimal64(0));
        REQUIRE(1l >= decimal64(0));
        REQUIRE(1lu >= decimal64(0));
        REQUIRE(1ll >= decimal64(0));
        REQUIRE(1llu >= decimal64(0));
        REQUIRE(1.0f >= decimal64(0));
        REQUIRE(1.0 >= decimal64(0));
        REQUIRE(1.0l >= decimal64(0));

        REQUIRE(decimal128(1) >= 0);
        REQUIRE(decimal128(1) >= 0u);
        REQUIRE(decimal128(1) >= 0l);
        REQUIRE(decimal128(1) >= 0lu);
        REQUIRE(decimal128(1) >= 0ll);
        REQUIRE(decimal128(1) >= 0llu);
        REQUIRE(decimal128(1) >= 0.0f);
        REQUIRE(decimal128(1) >= 0.0);
        REQUIRE(decimal128(1) >= 0.0l);

        REQUIRE(1 >= decimal128(0));
        REQUIRE(1u >= decimal128(0));
        REQUIRE(1l >= decimal128(0));
        REQUIRE(1lu >= decimal128(0));
        REQUIRE(1ll >= decimal128(0));
        REQUIRE(1llu >= decimal128(0));
        REQUIRE(1.0f >= decimal128(0));
        REQUIRE(1.0 >= decimal128(0));
        REQUIRE(1.0l >= decimal128(0));
    }

    SECTION("compound assignment addition")
    {
        REQUIRE((decimal32(1) += decimal32(2)) == decimal32(3));
        REQUIRE((decimal32(1) += decimal64(2)) == decimal32(3));
        REQUIRE((decimal32(1) += decimal128(2)) == decimal32(3));
        REQUIRE((decimal32(1) += 2) == decimal32(3));
        REQUIRE((decimal32(1) += 2u) == decimal32(3));
        REQUIRE((decimal32(1) += 2l) == decimal32(3));
        REQUIRE((decimal32(1) += 2lu) == decimal32(3));
        REQUIRE((decimal32(1) += 2ll) == decimal32(3));
        REQUIRE((decimal32(1) += 2llu) == decimal32(3));
        REQUIRE((decimal32(1) += 2.0f) == decimal32(3));
        REQUIRE((decimal32(1) += 2.0) == decimal32(3));
        //REQUIRE((decimal32(1) += 2.0l) == decimal32(3));

        REQUIRE((decimal64(1) += decimal32(2)) == decimal64(3));
        REQUIRE((decimal64(1) += decimal64(2)) == decimal64(3));
        REQUIRE((decimal64(1) += decimal128(2)) == decimal64(3));
        REQUIRE((decimal64(1) += 2) == decimal64(3));
        REQUIRE((decimal64(1) += 2u) == decimal64(3));
        REQUIRE((decimal64(1) += 2l) == decimal64(3));
        REQUIRE((decimal64(1) += 2lu) == decimal64(3));
        REQUIRE((decimal64(1) += 2ll) == decimal64(3));
        REQUIRE((decimal64(1) += 2llu) == decimal64(3));
        REQUIRE((decimal64(1) += 2.0f) == decimal64(3));
        REQUIRE((decimal64(1) += 2.0) == decimal64(3));
        //REQUIRE((decimal64(1) += 2.0l) == decimal64(3));

        REQUIRE((decimal128(1) += decimal32(2)) == decimal128(3));
        REQUIRE((decimal128(1) += decimal64(2)) == decimal128(3));
        REQUIRE((decimal128(1) += decimal128(2)) == decimal128(3));
        REQUIRE((decimal128(1) += 2) == decimal128(3));
        REQUIRE((decimal128(1) += 2u) == decimal128(3));
        REQUIRE((decimal128(1) += 2l) == decimal128(3));
        REQUIRE((decimal128(1) += 2lu) == decimal128(3));
        REQUIRE((decimal128(1) += 2ll) == decimal128(3));
        REQUIRE((decimal128(1) += 2llu) == decimal128(3));
        REQUIRE((decimal128(1) += 2.0f) == decimal128(3));
        REQUIRE((decimal128(1) += 2.0) == decimal128(3));
        //REQUIRE((decimal128(1) += 2.0l) == decimal128(3));
    }

    SECTION("compound assignment subtraction")
    {
        REQUIRE((decimal32(3) -= decimal32(2)) == decimal32(1));
        REQUIRE((decimal32(3) -= decimal64(2)) == decimal32(1));
        REQUIRE((decimal32(3) -= decimal128(2)) == decimal32(1));
        REQUIRE((decimal32(3) -= 2) == decimal32(1));
        REQUIRE((decimal32(3) -= 2u) == decimal32(1));
        REQUIRE((decimal32(3) -= 2l) == decimal32(1));
        REQUIRE((decimal32(3) -= 2lu) == decimal32(1));
        REQUIRE((decimal32(3) -= 2ll) == decimal32(1));
        REQUIRE((decimal32(3) -= 2llu) == decimal32(1));
        REQUIRE((decimal32(3) -= 2.0f) == decimal32(1));
        REQUIRE((decimal32(3) -= 2.0) == decimal32(1));
        //REQUIRE((decimal32(3) -= 2.0l) == decimal32(1));

        REQUIRE((decimal64(3) -= decimal32(2)) == decimal64(1));
        REQUIRE((decimal64(3) -= decimal64(2)) == decimal64(1));
        REQUIRE((decimal64(3) -= decimal128(2)) == decimal64(1));
        REQUIRE((decimal64(3) -= 2) == decimal64(1));
        REQUIRE((decimal64(3) -= 2u) == decimal64(1));
        REQUIRE((decimal64(3) -= 2l) == decimal64(1));
        REQUIRE((decimal64(3) -= 2lu) == decimal64(1));
        REQUIRE((decimal64(3) -= 2ll) == decimal64(1));
        REQUIRE((decimal64(3) -= 2llu) == decimal64(1));
        REQUIRE((decimal64(3) -= 2.0f) == decimal64(1));
        REQUIRE((decimal64(3) -= 2.0) == decimal64(1));
        //REQUIRE((decimal64(3) -= 2.0l) == decimal64(1));

        REQUIRE((decimal128(3) -= decimal32(2)) == decimal128(1));
        REQUIRE((decimal128(3) -= decimal64(2)) == decimal128(1));
        REQUIRE((decimal128(3) -= decimal128(2)) == decimal128(1));
        REQUIRE((decimal128(3) -= 2) == decimal128(1));
        REQUIRE((decimal128(3) -= 2u) == decimal128(1));
        REQUIRE((decimal128(3) -= 2l) == decimal128(1));
        REQUIRE((decimal128(3) -= 2lu) == decimal128(1));
        REQUIRE((decimal128(3) -= 2ll) == decimal128(1));
        REQUIRE((decimal128(3) -= 2llu) == decimal128(1));
        REQUIRE((decimal128(3) -= 2.0f) == decimal128(1));
        REQUIRE((decimal128(3) -= 2.0) == decimal128(1));
        //REQUIRE((decimal128(3) -= 2.0l) == decimal128(1));
    }

    SECTION("compound assignment multiplication")
    {
        REQUIRE((decimal32(2) *= decimal32(3)) == decimal32(6));
        REQUIRE((decimal32(2) *= decimal64(3)) == decimal32(6));
        REQUIRE((decimal32(2) *= decimal128(3)) == decimal32(6));
        REQUIRE((decimal32(2) *= 3) == decimal32(6));
        REQUIRE((decimal32(2) *= 3u) == decimal32(6));
        REQUIRE((decimal32(2) *= 3l) == decimal32(6));
        REQUIRE((decimal32(2) *= 3lu) == decimal32(6));
        REQUIRE((decimal32(2) *= 3ll) == decimal32(6));
        REQUIRE((decimal32(2) *= 3llu) == decimal32(6));
        REQUIRE((decimal32(2) *= 3.0f) == decimal32(6));
        REQUIRE((decimal32(2) *= 3.0) == decimal32(6));
        // REQUIRE((decimal32(2) *= 3.0l) == decimal32(6));

        REQUIRE((decimal64(2) *= decimal32(3)) == decimal64(6));
        REQUIRE((decimal64(2) *= decimal64(3)) == decimal64(6));
        REQUIRE((decimal64(2) *= decimal128(3)) == decimal64(6));
        REQUIRE((decimal64(2) *= 3) == decimal64(6));
        REQUIRE((decimal64(2) *= 3u) == decimal64(6));
        REQUIRE((decimal64(2) *= 3l) == decimal64(6));
        REQUIRE((decimal64(2) *= 3lu) == decimal64(6));
        REQUIRE((decimal64(2) *= 3ll) == decimal64(6));
        REQUIRE((decimal64(2) *= 3llu) == decimal64(6));
        REQUIRE((decimal64(2) *= 3.0f) == decimal64(6));
        REQUIRE((decimal64(2) *= 3.0) == decimal64(6));
        // REQUIRE((decimal64(2) *= 3.0l) == decimal64(6));

        REQUIRE((decimal128(2) *= decimal32(3)) == decimal128(6));
        REQUIRE((decimal128(2) *= decimal64(3)) == decimal128(6));
        REQUIRE((decimal128(2) *= decimal128(3)) == decimal128(6));
        REQUIRE((decimal128(2) *= 3) == decimal128(6));
        REQUIRE((decimal128(2) *= 3u) == decimal128(6));
        REQUIRE((decimal128(2) *= 3l) == decimal128(6));
        REQUIRE((decimal128(2) *= 3lu) == decimal128(6));
        REQUIRE((decimal128(2) *= 3ll) == decimal128(6));
        REQUIRE((decimal128(2) *= 3llu) == decimal128(6));
        REQUIRE((decimal128(2) *= 3.0f) == decimal128(6));
        REQUIRE((decimal128(2) *= 3.0) == decimal128(6));
        // REQUIRE((decimal128(2) *= 3.0l) == decimal128(6));
}

    SECTION("compound assignment division")
    {
        REQUIRE((decimal32(6) /= decimal32(2)) == decimal32(3));
        REQUIRE((decimal32(6) /= decimal64(2)) == decimal32(3));
        REQUIRE((decimal32(6) /= decimal128(2)) == decimal32(3));
        REQUIRE((decimal32(6) /= 2) == decimal32(3));
        REQUIRE((decimal32(6) /= 2u) == decimal32(3));
        REQUIRE((decimal32(6) /= 2l) == decimal32(3));
        REQUIRE((decimal32(6) /= 2lu) == decimal32(3));
        REQUIRE((decimal32(6) /= 2ll) == decimal32(3));
        REQUIRE((decimal32(6) /= 2llu) == decimal32(3));
        REQUIRE((decimal32(6) /= 2.0f) == decimal32(3));
        REQUIRE((decimal32(6) /= 2.0) == decimal32(3));
        // REQUIRE((decimal32(6) /= 2.0l) == decimal32(3));

        REQUIRE((decimal64(6) /= decimal32(2)) == decimal64(3));
        REQUIRE((decimal64(6) /= decimal64(2)) == decimal64(3));
        REQUIRE((decimal64(6) /= decimal128(2)) == decimal64(3));
        REQUIRE((decimal64(6) /= 2) == decimal64(3));
        REQUIRE((decimal64(6) /= 2u) == decimal64(3));
        REQUIRE((decimal64(6) /= 2l) == decimal64(3));
        REQUIRE((decimal64(6) /= 2lu) == decimal64(3));
        REQUIRE((decimal64(6) /= 2ll) == decimal64(3));
        REQUIRE((decimal64(6) /= 2llu) == decimal64(3));
        REQUIRE((decimal64(6) /= 2.0f) == decimal64(3));
        REQUIRE((decimal64(6) /= 2.0) == decimal64(3));
        // REQUIRE((decimal64(6) /= 2.0l) == decimal64(3));

        REQUIRE((decimal128(6) /= decimal32(2)) == decimal128(3));
        REQUIRE((decimal128(6) /= decimal64(2)) == decimal128(3));
        REQUIRE((decimal128(6) /= decimal128(2)) == decimal128(3));
        REQUIRE((decimal128(6) /= 2) == decimal128(3));
        REQUIRE((decimal128(6) /= 2u) == decimal128(3));
        REQUIRE((decimal128(6) /= 2l) == decimal128(3));
        REQUIRE((decimal128(6) /= 2lu) == decimal128(3));
        REQUIRE((decimal128(6) /= 2ll) == decimal128(3));
        REQUIRE((decimal128(6) /= 2llu) == decimal128(3));
        REQUIRE((decimal128(6) /= 2.0f) == decimal128(3));
        REQUIRE((decimal128(6) /= 2.0) == decimal128(3));
        // REQUIRE((decimal128(6) /= 2.0l) == decimal128(3));
    }

    SECTION("increment and decrement operators")
    {
        REQUIRE(++decimal32(1) == decimal32(2));
        REQUIRE(++decimal64(1) == decimal64(2));
        REQUIRE(++decimal128(1) == decimal128(2));

        REQUIRE(--decimal32(3) == decimal32(2));
        REQUIRE(--decimal64(3) == decimal64(2));
        REQUIRE(--decimal128(3) == decimal128(2));

        auto a32 = decimal32(1);
        auto b32 = a32++;
        REQUIRE(a32 == decimal32(2));
        REQUIRE(b32 == decimal32(1));

        a32 = decimal32(2);
        b32 = a32--;
        REQUIRE(a32 == decimal32(1));
        REQUIRE(b32 == decimal32(2));

        auto a64 = decimal64(1);
        auto b64 = a64++;
        REQUIRE(a64 == decimal64(2));
        REQUIRE(b64 == decimal64(1));

        a64 = decimal64(2);
        b64 = a64--;
        REQUIRE(a64 == decimal64(1));
        REQUIRE(b64 == decimal64(2));

        auto a128 = decimal128(1);
        auto b128 = a128++;
        REQUIRE(a128 == decimal128(2));
        REQUIRE(b128 == decimal128(1));

        a128 = decimal128(2);
        b128 = a128--;
        REQUIRE(a128 == decimal128(1));
        REQUIRE(b128 == decimal128(2));
    }
}