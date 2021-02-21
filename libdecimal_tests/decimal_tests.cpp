#include <catch.hpp>
#include <libdecimal/decimal.hpp>
#include <thread>

using namespace std::decimal;

TEST_CASE("floating point environment", "decimal") 
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
        REQUIRE(fe_dec_setexceptflag(nullptr, 0) != 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_OVERFLOW) == 0);
        const std::decimal::fexcept_t input = FE_DEC_OVERFLOW;
        REQUIRE(fe_dec_setexceptflag(&input, FE_DEC_OVERFLOW) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_OVERFLOW) == FE_DEC_OVERFLOW);
        std::decimal::fexcept_t output = 0;
        REQUIRE(fe_dec_getexceptflag(&output, FE_DEC_OVERFLOW) == 0);
    }

    SECTION("fe_dec_getenv and fe_dec_setenv")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_getenv(nullptr) != 0);
        REQUIRE(fe_dec_setenv(nullptr) != 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == 0);
        std::decimal::fenv_t env {};
        REQUIRE(fe_dec_getenv(&env) == 0);
        REQUIRE(fe_dec_raiseexcept(FE_DEC_DIVBYZERO) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == FE_DEC_DIVBYZERO);
        REQUIRE(fe_dec_setenv(&env) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_DIVBYZERO) == 0);
    }

    SECTION("fe_dec_holdexcept and fe_dec_updateenv")
    {
        REQUIRE(fe_dec_clearexcept(FE_DEC_ALL_EXCEPT) == 0);
        REQUIRE(fe_dec_holdexcept(nullptr) != 0);
        
        decimal32 one(1.0);
        one /= 0;
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_DIVBYZERO);

        std::decimal::fenv_t env {};
        REQUIRE(fe_dec_holdexcept(&env) == 0);

        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == 0);
        decimal32 two(1.0);
        two /= 0;
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == 0);

        REQUIRE(fe_dec_updateenv(nullptr) != 0);
        REQUIRE(fe_dec_updateenv(&env) == 0);
        REQUIRE(fe_dec_testexcept(FE_DEC_ALL_EXCEPT) == FE_DEC_DIVBYZERO);
    }

}


class decimal_Fixture
{
public:

    decimal_Fixture()
    {
        set_exceptions(FE_DEC_ALL_EXCEPT);
    }
};

TEST_CASE_METHOD(decimal_Fixture, "exceptions")
{
    REQUIRE_THROWS_MATCHES(decimal32(1) / 0, std::decimal::exception, Catch::Message("divide by zero"));
    REQUIRE_THROWS_MATCHES(decimal32(1) / 3, std::decimal::exception, Catch::Message("inexact"));
    REQUIRE_THROWS_MATCHES(make_decimal32(1LL,999999999) + make_decimal32(9LL, 99999999), std::decimal::exception, Catch::Message("overflow, inexact"));
    REQUIRE_THROWS_MATCHES(make_decimal32(1LL,-999999999) + make_decimal32(1LL, -99999999), std::decimal::exception, Catch::Message("underflow, inexact"));
    // TODO
    // REQUIRE_THROWS_MATCHES(sqrt(decimal32(-1)), std::decimal::exception, Catch::Message("invalid"));
}

TEST_CASE_METHOD(decimal_Fixture, "constructors")
{
    REQUIRE(decimal32() == 0);
}

TEST_CASE_METHOD(decimal_Fixture, "makers")
{

    REQUIRE(make_decimal32(10LL, -1) == 1);
    REQUIRE(make_decimal32(100LL, -2) == 1);
    REQUIRE(make_decimal32(10LL, 0) == 10);
    REQUIRE(make_decimal32(10LL, 1) == 100);
    REQUIRE(make_decimal32(100LL, 2) == 10000);

    REQUIRE(make_decimal64(10LL, -1) == 1);
    REQUIRE(make_decimal64(100LL, -2) == 1);
    REQUIRE(make_decimal64(10LL, 0) == 10);
    REQUIRE(make_decimal64(10LL, 1) == 100);
    REQUIRE(make_decimal64(100LL, 2) == 10000);

    REQUIRE(make_decimal128(10LL, -1) == 1);
    REQUIRE(make_decimal128(100LL, -2) == 1);
    REQUIRE(make_decimal128(10LL, 0) == 10);
    REQUIRE(make_decimal128(10LL, 1) == 100);
    REQUIRE(make_decimal128(100LL, 2) == 10000);
}

TEST_CASE_METHOD(decimal_Fixture, "convertion to integral type")
{
    decimal32 a(5);
    decimal64 b(5);
    decimal128 c(5);

    REQUIRE(static_cast<long long>(a) == 5.0F);
    REQUIRE(static_cast<float>(a) == 5.0F);
    REQUIRE(static_cast<double>(a) == 5.0);
    REQUIRE(static_cast<long double>(a) == 5.0L);

    REQUIRE(static_cast<long long>(b) == 5.0F);
    REQUIRE(static_cast<float>(b) == 5.0F);
    REQUIRE(static_cast<double>(b) == 5.0);
    REQUIRE(static_cast<long double>(b) == 5.0L);

    REQUIRE(static_cast<long long>(c) == 5.0F);
    REQUIRE(static_cast<float>(c) == 5.0F);
    REQUIRE(static_cast<double>(c) == 5.0);
    REQUIRE(static_cast<long double>(c) == 5.0L);
}

TEST_CASE_METHOD(decimal_Fixture, "decimal to long double")
{
    REQUIRE(decimal32_to_float(decimal32(5)) == 5.0F); 
    REQUIRE(decimal_to_float(decimal32(5)) == 5.0F); 

    REQUIRE(decimal64_to_float(decimal64(5)) == 5.0F); 
    REQUIRE(decimal_to_float(decimal64(5)) == 5.0F); 

    REQUIRE(decimal128_to_float(decimal128(5)) == 5.0F); 
    REQUIRE(decimal_to_float(decimal128(5)) == 5.0F);

    REQUIRE(decimal32_to_double(decimal32(5)) == 5.0); 
    REQUIRE(decimal_to_double(decimal32(5)) == 5.0); 

    REQUIRE(decimal64_to_double (decimal64(5)) == 5.0); 
    REQUIRE(decimal_to_double(decimal64(5)) == 5.0); 

    REQUIRE(decimal128_to_double(decimal128(5)) == 5.0L); 
    REQUIRE(decimal_to_double(decimal128(5)) == 5.0L);

    REQUIRE(decimal32_to_long_double(decimal32(5)) == 5.0L);
    REQUIRE(decimal_to_long_double(decimal32(5)) == 5.0L);
    
    REQUIRE(decimal64_to_long_double(decimal64(5)) == 5.0L);
    REQUIRE(decimal_to_long_double(decimal64(5)) == 5.0L);

    REQUIRE(decimal128_to_long_double(decimal128(5)) == 5.0L);
    REQUIRE(decimal_to_long_double(decimal128(5)) == 5.0L);
}

TEST_CASE_METHOD(decimal_Fixture, "unary arithmetic")
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

TEST_CASE_METHOD(decimal_Fixture, "binary addition")
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
    REQUIRE(decimal32(1) + 2U == decimal32(3));
    REQUIRE(decimal32(1) + 2L == decimal64(3));
    REQUIRE(decimal32(1) + 2LU == decimal64(3));
    REQUIRE(decimal32(1) + 2LL == decimal128(3));
    REQUIRE(decimal32(1) + 2LLU == decimal128(3));
    REQUIRE(decimal32(1) + 2.0F == decimal32(3));
    REQUIRE(decimal32(1) + 2.0 == decimal64(3));
    REQUIRE(decimal32(1) + 2.0L == decimal128(3));

    REQUIRE(1 + decimal32(2) == decimal32(3));
    REQUIRE(1U + decimal32(2) == decimal32(3));
    REQUIRE(1L + decimal32(2) == decimal64(3));
    REQUIRE(1LU + decimal32(2) == decimal64(3));
    REQUIRE(1LL + decimal32(2) == decimal128(3));
    REQUIRE(1LLU + decimal32(2) == decimal128(3));
    REQUIRE(1.0F + decimal32(2) == decimal32(3));
    REQUIRE(1.0 + decimal32(2) == decimal64(3));
    REQUIRE(1.0L + decimal32(2) == decimal128(3));

    REQUIRE(decimal64(1) + 2 == decimal64(3));
    REQUIRE(decimal64(1) + 2U == decimal64(3));
    REQUIRE(decimal64(1) + 2L == decimal64(3));
    REQUIRE(decimal64(1) + 2LU == decimal64(3));
    REQUIRE(decimal64(1) + 2LL == decimal128(3));
    REQUIRE(decimal64(1) + 2LLU == decimal128(3));
    REQUIRE(decimal64(1) + 2.0F == decimal64(3));
    REQUIRE(decimal64(1) + 2.0 == decimal64(3));
    REQUIRE(decimal64(1) + 2.0L == decimal128(3));

    REQUIRE(1 + decimal64(2) == decimal64(3));
    REQUIRE(1U + decimal64(2) == decimal64(3));
    REQUIRE(1L + decimal64(2) == decimal64(3));
    REQUIRE(1LU + decimal64(2) == decimal64(3));
    REQUIRE(1LL + decimal64(2) == decimal128(3));
    REQUIRE(1LLU + decimal64(2) == decimal128(3));
    REQUIRE(1.0F + decimal64(2) == decimal64(3));
    REQUIRE(1.0 + decimal64(2) == decimal64(3));
    REQUIRE(1.0L + decimal64(2) == decimal128(3));

    REQUIRE(decimal128(1) + 2 == decimal128(3));
    REQUIRE(decimal128(1) + 2U == decimal128(3));
    REQUIRE(decimal128(1) + 2L == decimal128(3));
    REQUIRE(decimal128(1) + 2LU == decimal128(3));
    REQUIRE(decimal128(1) + 2LL == decimal128(3));
    REQUIRE(decimal128(1) + 2LLU == decimal128(3));
    REQUIRE(decimal128(1) + 2.0F == decimal128(3));
    REQUIRE(decimal128(1) + 2.0 == decimal128(3));
    REQUIRE(decimal128(1) + 2.0L == decimal128(3));

    REQUIRE(1 + decimal128(2) == decimal128(3));
    REQUIRE(1U + decimal128(2) == decimal128(3));
    REQUIRE(1L + decimal128(2) == decimal128(3));
    REQUIRE(1LU + decimal128(2) == decimal128(3));
    REQUIRE(1LL + decimal128(2) == decimal128(3));
    REQUIRE(1LLU + decimal128(2) == decimal128(3));
    REQUIRE(1.0F + decimal128(2) == decimal128(3));
    REQUIRE(1.0 + decimal128(2) == decimal128(3));
    REQUIRE(1.0L + decimal128(2) == decimal128(3));
}

TEST_CASE_METHOD(decimal_Fixture, "binary subtraction")
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
    REQUIRE(decimal32(3) - 2U == decimal32(1));
    REQUIRE(decimal32(3) - 2L == decimal64(1));
    REQUIRE(decimal32(3) - 2LU == decimal64(1));
    REQUIRE(decimal32(3) - 2LL == decimal128(1));
    REQUIRE(decimal32(3) - 2LLU == decimal128(1));
    REQUIRE(decimal32(3) - 2.0F == decimal32(1));
    REQUIRE(decimal32(3) - 2.0 == decimal64(1));
    REQUIRE(decimal32(3) - 2.0L == decimal128(1));

    REQUIRE(3 - decimal32(2) == decimal32(1));
    REQUIRE(3U - decimal32(2) == decimal32(1));
    REQUIRE(3L - decimal32(2) == decimal64(1));
    REQUIRE(3LU - decimal32(2) == decimal64(1));
    REQUIRE(3LL - decimal32(2) == decimal128(1));
    REQUIRE(3LLU - decimal32(2) == decimal128(1));
    REQUIRE(3.0F - decimal32(2) == decimal32(1));
    REQUIRE(3.0 - decimal32(2) == decimal64(1));
    REQUIRE(3.0L - decimal32(2) == decimal128(1));

    REQUIRE(decimal64(3) - 2 == decimal64(1));
    REQUIRE(decimal64(3) - 2U == decimal64(1));
    REQUIRE(decimal64(3) - 2L == decimal64(1));
    REQUIRE(decimal64(3) - 2LU == decimal64(1));
    REQUIRE(decimal64(3) - 2LL == decimal128(1));
    REQUIRE(decimal64(3) - 2LLU == decimal128(1));
    REQUIRE(decimal64(3) - 2.0F == decimal64(1));
    REQUIRE(decimal64(3) - 2.0 == decimal64(1));
    REQUIRE(decimal64(3) - 2.0L == decimal128(1));

    REQUIRE(3 - decimal64(2) == decimal64(1));
    REQUIRE(3U - decimal64(2) == decimal64(1));
    REQUIRE(3L - decimal64(2) == decimal64(1));
    REQUIRE(3LU - decimal64(2) == decimal64(1));
    REQUIRE(3LL - decimal64(2) == decimal128(1));
    REQUIRE(3LLU - decimal64(2) == decimal128(1));
    REQUIRE(3.0F - decimal64(2) == decimal64(1));
    REQUIRE(3.0 - decimal64(2) == decimal64(1));
    REQUIRE(3.0L - decimal64(2) == decimal128(1));

    REQUIRE(decimal128(3) - 2 == decimal128(1));
    REQUIRE(decimal128(3) - 2U == decimal128(1));
    REQUIRE(decimal128(3) - 2L == decimal128(1));
    REQUIRE(decimal128(3) - 2LU == decimal128(1));
    REQUIRE(decimal128(3) - 2LL == decimal128(1));
    REQUIRE(decimal128(3) - 2LLU == decimal128(1));
    REQUIRE(decimal128(3) - 2.0F == decimal128(1));
    REQUIRE(decimal128(3) - 2.0 == decimal128(1));
    REQUIRE(decimal128(3) - 2.0L == decimal128(1));

    REQUIRE(3 - decimal128(2) == decimal128(1));
    REQUIRE(3U - decimal128(2) == decimal128(1));
    REQUIRE(3L - decimal128(2) == decimal128(1));
    REQUIRE(3LU - decimal128(2) == decimal128(1));
    REQUIRE(3LL - decimal128(2) == decimal128(1));
    REQUIRE(3LLU - decimal128(2) == decimal128(1));
    REQUIRE(3.0F - decimal128(2) == decimal128(1));
    REQUIRE(3.0 - decimal128(2) == decimal128(1));
    REQUIRE(3.0L - decimal128(2) == decimal128(1));
}

TEST_CASE_METHOD(decimal_Fixture, "binary multiplication")
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
    REQUIRE(decimal32(2) * 3U == decimal32(6));
    REQUIRE(decimal32(2) * 3L == decimal64(6));
    REQUIRE(decimal32(2) * 3LU == decimal64(6));
    REQUIRE(decimal32(2) * 3LL == decimal128(6));
    REQUIRE(decimal32(2) * 3LLU == decimal128(6));
    REQUIRE(decimal32(2) * 3.0F == decimal32(6));
    REQUIRE(decimal32(2) * 3.0 == decimal64(6));
    REQUIRE(decimal32(2) * 3.0L == decimal128(6));

    REQUIRE(2 * decimal32(3) == decimal32(6));
    REQUIRE(2U * decimal32(3) == decimal32(6));
    REQUIRE(2L * decimal32(3) == decimal64(6));
    REQUIRE(2LU * decimal32(3) == decimal64(6));
    REQUIRE(2LL * decimal32(3) == decimal128(6));
    REQUIRE(2LLU * decimal32(3) == decimal128(6));
    REQUIRE(2.0F * decimal32(3) == decimal32(6));
    REQUIRE(2.0 * decimal32(3) == decimal64(6));
    REQUIRE(2.0L * decimal32(3) == decimal128(6));

    REQUIRE(decimal64(2) * 3 == decimal64(6));
    REQUIRE(decimal64(2) * 3U == decimal64(6));
    REQUIRE(decimal64(2) * 3L == decimal64(6));
    REQUIRE(decimal64(2) * 3LU == decimal64(6));
    REQUIRE(decimal64(2) * 3LL == decimal128(6));
    REQUIRE(decimal64(2) * 3LLU == decimal128(6));
    REQUIRE(decimal64(2) * 3.0F == decimal64(6));
    REQUIRE(decimal64(2) * 3.0 == decimal64(6));
    REQUIRE(decimal64(2) * 3.0L == decimal128(6));

    REQUIRE(2 * decimal64(3) == decimal64(6));
    REQUIRE(2U * decimal64(3) == decimal64(6));
    REQUIRE(2L * decimal64(3) == decimal64(6));
    REQUIRE(2LU * decimal64(3) == decimal64(6));
    REQUIRE(2LL * decimal64(3) == decimal128(6));
    REQUIRE(2LLU * decimal64(3) == decimal128(6));
    REQUIRE(2.0F * decimal64(3) == decimal64(6));
    REQUIRE(2.0 * decimal64(3) == decimal64(6));
    REQUIRE(2.0L * decimal64(3) == decimal128(6));

    REQUIRE(decimal128(2) * 3 == decimal128(6));
    REQUIRE(decimal128(2) * 3U == decimal128(6));
    REQUIRE(decimal128(2) * 3L == decimal128(6));
    REQUIRE(decimal128(2) * 3LU == decimal128(6));
    REQUIRE(decimal128(2) * 3LL == decimal128(6));
    REQUIRE(decimal128(2) * 3LLU == decimal128(6));
    REQUIRE(decimal128(2) * 3.0F == decimal128(6));
    REQUIRE(decimal128(2) * 3.0 == decimal128(6));
    REQUIRE(decimal128(2) * 3.0L == decimal128(6));

    REQUIRE(2 * decimal128(3) == decimal128(6));
    REQUIRE(2U * decimal128(3) == decimal128(6));
    REQUIRE(2L * decimal128(3) == decimal128(6));
    REQUIRE(2LU * decimal128(3) == decimal128(6));
    REQUIRE(2LL * decimal128(3) == decimal128(6));
    REQUIRE(2LLU * decimal128(3) == decimal128(6));
    REQUIRE(2.0F * decimal128(3) == decimal128(6));
    REQUIRE(2.0 * decimal128(3) == decimal128(6));
    REQUIRE(2.0L * decimal128(3) == decimal128(6));
}

TEST_CASE_METHOD(decimal_Fixture, "binary division")
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
    REQUIRE(decimal32(6) / 2U == decimal32(3));
    REQUIRE(decimal32(6) / 2L == decimal64(3));
    REQUIRE(decimal32(6) / 2LU == decimal64(3));
    REQUIRE(decimal32(6) / 2LL == decimal128(3));
    REQUIRE(decimal32(6) / 2LLU == decimal128(3));
    REQUIRE(decimal32(6) / 2.0F == decimal32(3));
    REQUIRE(decimal32(6) / 2.0 == decimal64(3));
    REQUIRE(decimal32(6) / 2.0L == decimal128(3));

    REQUIRE(6 / decimal32(2) == decimal32(3));
    REQUIRE(6U / decimal32(2) == decimal32(3));
    REQUIRE(6L / decimal32(2) == decimal64(3));
    REQUIRE(6LU / decimal32(2) == decimal64(3));
    REQUIRE(6LL / decimal32(2) == decimal128(3));
    REQUIRE(6LLU / decimal32(2) == decimal128(3));
    REQUIRE(6.0F / decimal32(2) == decimal32(3));
    REQUIRE(6.0 / decimal32(2) == decimal64(3));
    REQUIRE(6.0L / decimal32(2) == decimal128(3));

    REQUIRE(decimal64(6) / 2 == decimal64(3));
    REQUIRE(decimal64(6) / 2U == decimal64(3));
    REQUIRE(decimal64(6) / 2L == decimal64(3));
    REQUIRE(decimal64(6) / 2LU == decimal64(3));
    REQUIRE(decimal64(6) / 2LL == decimal128(3));
    REQUIRE(decimal64(6) / 2LLU == decimal128(3));
    REQUIRE(decimal64(6) / 2.0F == decimal64(3));
    REQUIRE(decimal64(6) / 2.0 == decimal64(3));
    REQUIRE(decimal64(6) / 2.0L == decimal128(3));

    REQUIRE(6 / decimal64(2) == decimal64(3));
    REQUIRE(6U / decimal64(2) == decimal64(3));
    REQUIRE(6L / decimal64(2) == decimal64(3));
    REQUIRE(6LU / decimal64(2) == decimal64(3));
    REQUIRE(6LL / decimal64(2) == decimal128(3));
    REQUIRE(6LLU / decimal64(2) == decimal128(3));
    REQUIRE(6.0F / decimal64(2) == decimal64(3));
    REQUIRE(6.0 / decimal64(2) == decimal64(3));
    REQUIRE(6.0L / decimal64(2) == decimal128(3));

    REQUIRE(decimal128(6) / 2 == decimal128(3));
    REQUIRE(decimal128(6) / 2U == decimal128(3));
    REQUIRE(decimal128(6) / 2L == decimal128(3));
    REQUIRE(decimal128(6) / 2LU == decimal128(3));
    REQUIRE(decimal128(6) / 2LL == decimal128(3));
    REQUIRE(decimal128(6) / 2LLU == decimal128(3));
    REQUIRE(decimal128(6) / 2.0F == decimal128(3));
    REQUIRE(decimal128(6) / 2.0 == decimal128(3));
    REQUIRE(decimal128(6) / 2.0L == decimal128(3));

    REQUIRE(6 / decimal128(2) == decimal128(3));
    REQUIRE(6U / decimal128(2) == decimal128(3));
    REQUIRE(6L / decimal128(2) == decimal128(3));
    REQUIRE(6LU / decimal128(2) == decimal128(3));
    REQUIRE(6LL / decimal128(2) == decimal128(3));
    REQUIRE(6LLU / decimal128(2) == decimal128(3));
    REQUIRE(6.0F / decimal128(2) == decimal128(3));
    REQUIRE(6.0 / decimal128(2) == decimal128(3));
    REQUIRE(6.0L / decimal128(2) == decimal128(3));
}

TEST_CASE_METHOD(decimal_Fixture, "binary equal")
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
    REQUIRE(decimal32(0) == 0U);
    REQUIRE(decimal32(0) == 0L);
    REQUIRE(decimal32(0) == 0LU);
    REQUIRE(decimal32(0) == 0LL);
    REQUIRE(decimal32(0) == 0LLU);
    REQUIRE(decimal32(0) == 0.0F);
    REQUIRE(decimal32(0) == 0.0);
    REQUIRE(decimal32(0) == 0.0L);

    REQUIRE(0 == decimal32(0));
    REQUIRE(0U == decimal32(0));
    REQUIRE(0L == decimal32(0));
    REQUIRE(0LU == decimal32(0));
    REQUIRE(0LL == decimal32(0));
    REQUIRE(0LLU == decimal32(0));
    REQUIRE(0.0F == decimal32(0));
    REQUIRE(0.0 == decimal32(0));
    REQUIRE(0.0L == decimal32(0));

    REQUIRE(decimal64(0) == 0);
    REQUIRE(decimal64(0) == 0U);
    REQUIRE(decimal64(0) == 0L);
    REQUIRE(decimal64(0) == 0LU);
    REQUIRE(decimal64(0) == 0LL);
    REQUIRE(decimal64(0) == 0LLU);
    REQUIRE(decimal64(0) == 0.0F);
    REQUIRE(decimal64(0) == 0.0);
    REQUIRE(decimal64(0) == 0.0L);

    REQUIRE(0 == decimal64(0));
    REQUIRE(0U == decimal64(0));
    REQUIRE(0L == decimal64(0));
    REQUIRE(0LU == decimal64(0));
    REQUIRE(0LL == decimal64(0));
    REQUIRE(0LLU == decimal64(0));
    REQUIRE(0.0F == decimal64(0));
    REQUIRE(0.0 == decimal64(0));
    REQUIRE(0.0L == decimal64(0));

    REQUIRE(decimal128(0) == 0);
    REQUIRE(decimal128(0) == 0U);
    REQUIRE(decimal128(0) == 0L);
    REQUIRE(decimal128(0) == 0LU);
    REQUIRE(decimal128(0) == 0LL);
    REQUIRE(decimal128(0) == 0LLU);
    REQUIRE(decimal128(0) == 0.0F);
    REQUIRE(decimal128(0) == 0.0);
    REQUIRE(decimal128(0) == 0.0L);

    REQUIRE(0 == decimal128(0));
    REQUIRE(0U == decimal128(0));
    REQUIRE(0L == decimal128(0));
    REQUIRE(0LU == decimal128(0));
    REQUIRE(0LL == decimal128(0));
    REQUIRE(0LLU == decimal128(0));
    REQUIRE(0.0F == decimal128(0));
    REQUIRE(0.0 == decimal128(0));
    REQUIRE(0.0L == decimal128(0));
}

TEST_CASE_METHOD(decimal_Fixture, "binary not equal")
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
    REQUIRE(decimal32(0) != 1U);
    REQUIRE(decimal32(0) != 1L);
    REQUIRE(decimal32(0) != 1LU);
    REQUIRE(decimal32(0) != 1LL);
    REQUIRE(decimal32(0) != 1LLU);
    REQUIRE(decimal32(0) != 1.0F);
    REQUIRE(decimal32(0) != 1.0);
    REQUIRE(decimal32(0) != 1.0L);

    REQUIRE(0 != decimal32(1));
    REQUIRE(0U != decimal32(1));
    REQUIRE(0L != decimal32(1));
    REQUIRE(0LU != decimal32(1));
    REQUIRE(0LL != decimal32(1));
    REQUIRE(0LLU != decimal32(1));
    REQUIRE(0.0F != decimal32(1));
    REQUIRE(0.0 != decimal32(1));
    REQUIRE(0.0L != decimal32(1));

    REQUIRE(decimal64(0) != 1);
    REQUIRE(decimal64(0) != 1U);
    REQUIRE(decimal64(0) != 1L);
    REQUIRE(decimal64(0) != 1LU);
    REQUIRE(decimal64(0) != 1LL);
    REQUIRE(decimal64(0) != 1LLU);
    REQUIRE(decimal64(0) != 1.0F);
    REQUIRE(decimal64(0) != 1.0);
    REQUIRE(decimal64(0) != 1.0L);

    REQUIRE(0 != decimal64(1));
    REQUIRE(0U != decimal64(1));
    REQUIRE(0L != decimal64(1));
    REQUIRE(0LU != decimal64(1));
    REQUIRE(0LL != decimal64(1));
    REQUIRE(0LLU != decimal64(1));
    REQUIRE(0.0F != decimal64(1));
    REQUIRE(0.0 != decimal64(1));
    REQUIRE(0.0L != decimal64(1));

    REQUIRE(decimal128(0) != 1);
    REQUIRE(decimal128(0) != 1U);
    REQUIRE(decimal128(0) != 1L);
    REQUIRE(decimal128(0) != 1LU);
    REQUIRE(decimal128(0) != 1LL);
    REQUIRE(decimal128(0) != 1LLU);
    REQUIRE(decimal128(0) != 1.0F);
    REQUIRE(decimal128(0) != 1.0);
    REQUIRE(decimal128(0) != 1.0L);

    REQUIRE(0 != decimal128(1));
    REQUIRE(0U != decimal128(1));
    REQUIRE(0L != decimal128(1));
    REQUIRE(0LU != decimal128(1));
    REQUIRE(0LL != decimal128(1));
    REQUIRE(0LLU != decimal128(1));
    REQUIRE(0.0F != decimal128(1));
    REQUIRE(0.0 != decimal128(1));
    REQUIRE(0.0L != decimal128(1));
}

TEST_CASE_METHOD(decimal_Fixture, "binary less")
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
    REQUIRE(decimal32(0) < 1U);
    REQUIRE(decimal32(0) < 1L);
    REQUIRE(decimal32(0) < 1LU);
    REQUIRE(decimal32(0) < 1LL);
    REQUIRE(decimal32(0) < 1LLU);
    REQUIRE(decimal32(0) < 1.0F);
    REQUIRE(decimal32(0) < 1.0);
    REQUIRE(decimal32(0) < 1.0L);

    REQUIRE(0 < decimal32(1));
    REQUIRE(0U < decimal32(1));
    REQUIRE(0L < decimal32(1));
    REQUIRE(0LU < decimal32(1));
    REQUIRE(0LL < decimal32(1));
    REQUIRE(0LLU < decimal32(1));
    REQUIRE(0.0F < decimal32(1));
    REQUIRE(0.0 < decimal32(1));
    REQUIRE(0.0L < decimal32(1));

    REQUIRE(decimal64(0) < 1);
    REQUIRE(decimal64(0) < 1U);
    REQUIRE(decimal64(0) < 1L);
    REQUIRE(decimal64(0) < 1LU);
    REQUIRE(decimal64(0) < 1LL);
    REQUIRE(decimal64(0) < 1LLU);
    REQUIRE(decimal64(0) < 1.0F);
    REQUIRE(decimal64(0) < 1.0);
    REQUIRE(decimal64(0) < 1.0L);

    REQUIRE(0 < decimal64(1));
    REQUIRE(0U < decimal64(1));
    REQUIRE(0L < decimal64(1));
    REQUIRE(0LU < decimal64(1));
    REQUIRE(0LL < decimal64(1));
    REQUIRE(0LLU < decimal64(1));
    REQUIRE(0.0F < decimal64(1));
    REQUIRE(0.0 < decimal64(1));
    REQUIRE(0.0L < decimal64(1));

    REQUIRE(decimal128(0) < 1);
    REQUIRE(decimal128(0) < 1U);
    REQUIRE(decimal128(0) < 1L);
    REQUIRE(decimal128(0) < 1LU);
    REQUIRE(decimal128(0) < 1LL);
    REQUIRE(decimal128(0) < 1LLU);
    REQUIRE(decimal128(0) < 1.0F);
    REQUIRE(decimal128(0) < 1.0);
    REQUIRE(decimal128(0) < 1.0L);

    REQUIRE(0 < decimal128(1));
    REQUIRE(0U < decimal128(1));
    REQUIRE(0L < decimal128(1));
    REQUIRE(0LU < decimal128(1));
    REQUIRE(0LL < decimal128(1));
    REQUIRE(0LLU < decimal128(1));
    REQUIRE(0.0F < decimal128(1));
    REQUIRE(0.0 < decimal128(1));
    REQUIRE(0.0L < decimal128(1));
}

TEST_CASE_METHOD(decimal_Fixture, "binary less than or equal")
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
    REQUIRE(decimal32(0) <= 1U);
    REQUIRE(decimal32(0) <= 1L);
    REQUIRE(decimal32(0) <= 1LU);
    REQUIRE(decimal32(0) <= 1LL);
    REQUIRE(decimal32(0) <= 1LLU);
    REQUIRE(decimal32(0) <= 1.0F);
    REQUIRE(decimal32(0) <= 1.0);
    REQUIRE(decimal32(0) <= 1.0L);

    REQUIRE(0 <= decimal32(1));
    REQUIRE(0U <= decimal32(1));
    REQUIRE(0L <= decimal32(1));
    REQUIRE(0LU <= decimal32(1));
    REQUIRE(0LL <= decimal32(1));
    REQUIRE(0LLU <= decimal32(1));
    REQUIRE(0.0F <= decimal32(1));
    REQUIRE(0.0 <= decimal32(1));
    REQUIRE(0.0L <= decimal32(1));

    REQUIRE(decimal64(0) <= 1);
    REQUIRE(decimal64(0) <= 1U);
    REQUIRE(decimal64(0) <= 1L);
    REQUIRE(decimal64(0) <= 1LU);
    REQUIRE(decimal64(0) <= 1LL);
    REQUIRE(decimal64(0) <= 1LLU);
    REQUIRE(decimal64(0) <= 1.0F);
    REQUIRE(decimal64(0) <= 1.0);
    REQUIRE(decimal64(0) <= 1.0L);

    REQUIRE(0 <= decimal64(1));
    REQUIRE(0U <= decimal64(1));
    REQUIRE(0L <= decimal64(1));
    REQUIRE(0LU <= decimal64(1));
    REQUIRE(0LL <= decimal64(1));
    REQUIRE(0LLU <= decimal64(1));
    REQUIRE(0.0F <= decimal64(1));
    REQUIRE(0.0 <= decimal64(1));
    REQUIRE(0.0L <= decimal64(1));

    REQUIRE(decimal128(0) <= 1);
    REQUIRE(decimal128(0) <= 1U);
    REQUIRE(decimal128(0) <= 1L);
    REQUIRE(decimal128(0) <= 1LU);
    REQUIRE(decimal128(0) <= 1LL);
    REQUIRE(decimal128(0) <= 1LLU);
    REQUIRE(decimal128(0) <= 1.0F);
    REQUIRE(decimal128(0) <= 1.0);
    REQUIRE(decimal128(0) <= 1.0L);

    REQUIRE(0 <= decimal128(1));
    REQUIRE(0U <= decimal128(1));
    REQUIRE(0L <= decimal128(1));
    REQUIRE(0LU <= decimal128(1));
    REQUIRE(0LL <= decimal128(1));
    REQUIRE(0LLU <= decimal128(1));
    REQUIRE(0.0F <= decimal128(1));
    REQUIRE(0.0 <= decimal128(1));
    REQUIRE(0.0L <= decimal128(1));
}

TEST_CASE_METHOD(decimal_Fixture, "binary greater")
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
    REQUIRE(decimal32(1) > 0U);
    REQUIRE(decimal32(1) > 0L);
    REQUIRE(decimal32(1) > 0LU);
    REQUIRE(decimal32(1) > 0LL);
    REQUIRE(decimal32(1) > 0LLU);
    REQUIRE(decimal32(1) > 0.0F);
    REQUIRE(decimal32(1) > 0.0);
    REQUIRE(decimal32(1) > 0.0L);

    REQUIRE(1 > decimal32(0));
    REQUIRE(1U > decimal32(0));
    REQUIRE(1L > decimal32(0));
    REQUIRE(1LU > decimal32(0));
    REQUIRE(1LL > decimal32(0));
    REQUIRE(1LLU > decimal32(0));
    REQUIRE(1.0F > decimal32(0));
    REQUIRE(1.0 > decimal32(0));
    REQUIRE(1.0L > decimal32(0));

    REQUIRE(decimal64(1) > 0);
    REQUIRE(decimal64(1) > 0U);
    REQUIRE(decimal64(1) > 0L);
    REQUIRE(decimal64(1) > 0LU);
    REQUIRE(decimal64(1) > 0LL);
    REQUIRE(decimal64(1) > 0LLU);
    REQUIRE(decimal64(1) > 0.0F);
    REQUIRE(decimal64(1) > 0.0);
    REQUIRE(decimal64(1) > 0.0L);

    REQUIRE(1 > decimal64(0));
    REQUIRE(1U > decimal64(0));
    REQUIRE(1L > decimal64(0));
    REQUIRE(1LU > decimal64(0));
    REQUIRE(1LL > decimal64(0));
    REQUIRE(1LLU > decimal64(0));
    REQUIRE(1.0F > decimal64(0));
    REQUIRE(1.0 > decimal64(0));
    REQUIRE(1.0L > decimal64(0));

    REQUIRE(decimal128(1) > 0);
    REQUIRE(decimal128(1) > 0U);
    REQUIRE(decimal128(1) > 0L);
    REQUIRE(decimal128(1) > 0LU);
    REQUIRE(decimal128(1) > 0LL);
    REQUIRE(decimal128(1) > 0LLU);
    REQUIRE(decimal128(1) > 0.0F);
    REQUIRE(decimal128(1) > 0.0);
    REQUIRE(decimal128(1) > 0.0L);

    REQUIRE(1 > decimal128(0));
    REQUIRE(1U > decimal128(0));
    REQUIRE(1L > decimal128(0));
    REQUIRE(1LU > decimal128(0));
    REQUIRE(1LL > decimal128(0));
    REQUIRE(1LLU > decimal128(0));
    REQUIRE(1.0F > decimal128(0));
    REQUIRE(1.0 > decimal128(0));
    REQUIRE(1.0L > decimal128(0));
}

TEST_CASE_METHOD(decimal_Fixture, "binary greater than or equal")
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
    REQUIRE(decimal32(1) >= 0U);
    REQUIRE(decimal32(1) >= 0L);
    REQUIRE(decimal32(1) >= 0LU);
    REQUIRE(decimal32(1) >= 0LL);
    REQUIRE(decimal32(1) >= 0LLU);
    REQUIRE(decimal32(1) >= 0.0F);
    REQUIRE(decimal32(1) >= 0.0);
    REQUIRE(decimal32(1) >= 0.0L);

    REQUIRE(1 >= decimal32(0));
    REQUIRE(1U >= decimal32(0));
    REQUIRE(1L >= decimal32(0));
    REQUIRE(1LU >= decimal32(0));
    REQUIRE(1LL >= decimal32(0));
    REQUIRE(1LLU >= decimal32(0));
    REQUIRE(1.0F >= decimal32(0));
    REQUIRE(1.0 >= decimal32(0));
    REQUIRE(1.0L >= decimal32(0));

    REQUIRE(decimal64(1) >= 0);
    REQUIRE(decimal64(1) >= 0U);
    REQUIRE(decimal64(1) >= 0L);
    REQUIRE(decimal64(1) >= 0LU);
    REQUIRE(decimal64(1) >= 0LL);
    REQUIRE(decimal64(1) >= 0LLU);
    REQUIRE(decimal64(1) >= 0.0F);
    REQUIRE(decimal64(1) >= 0.0);
    REQUIRE(decimal64(1) >= 0.0L);

    REQUIRE(1 >= decimal64(0));
    REQUIRE(1U >= decimal64(0));
    REQUIRE(1L >= decimal64(0));
    REQUIRE(1LU >= decimal64(0));
    REQUIRE(1LL >= decimal64(0));
    REQUIRE(1LLU >= decimal64(0));
    REQUIRE(1.0F >= decimal64(0));
    REQUIRE(1.0 >= decimal64(0));
    REQUIRE(1.0L >= decimal64(0));

    REQUIRE(decimal128(1) >= 0);
    REQUIRE(decimal128(1) >= 0U);
    REQUIRE(decimal128(1) >= 0L);
    REQUIRE(decimal128(1) >= 0LU);
    REQUIRE(decimal128(1) >= 0LL);
    REQUIRE(decimal128(1) >= 0LLU);
    REQUIRE(decimal128(1) >= 0.0F);
    REQUIRE(decimal128(1) >= 0.0);
    REQUIRE(decimal128(1) >= 0.0L);

    REQUIRE(1 >= decimal128(0));
    REQUIRE(1U >= decimal128(0));
    REQUIRE(1L >= decimal128(0));
    REQUIRE(1LU >= decimal128(0));
    REQUIRE(1LL >= decimal128(0));
    REQUIRE(1LLU >= decimal128(0));
    REQUIRE(1.0F >= decimal128(0));
    REQUIRE(1.0 >= decimal128(0));
    REQUIRE(1.0L >= decimal128(0));
}

TEST_CASE_METHOD(decimal_Fixture, "compound assignment addition")
{
    REQUIRE((decimal32(1) += decimal32(2)) == decimal32(3));
    REQUIRE((decimal32(1) += decimal64(2)) == decimal32(3));
    REQUIRE((decimal32(1) += decimal128(2)) == decimal32(3));
    REQUIRE((decimal32(1) += 2) == decimal32(3));
    REQUIRE((decimal32(1) += 2U) == decimal32(3));
    REQUIRE((decimal32(1) += 2L) == decimal32(3));
    REQUIRE((decimal32(1) += 2LU) == decimal32(3));
    REQUIRE((decimal32(1) += 2LL) == decimal32(3));
    REQUIRE((decimal32(1) += 2LLU) == decimal32(3));
    REQUIRE((decimal32(1) += 2.0F) == decimal32(3));
    REQUIRE((decimal32(1) += 2.0) == decimal32(3));
    REQUIRE((decimal32(1) += 2.0L) == decimal32(3));

    REQUIRE((decimal64(1) += decimal32(2)) == decimal64(3));
    REQUIRE((decimal64(1) += decimal64(2)) == decimal64(3));
    REQUIRE((decimal64(1) += decimal128(2)) == decimal64(3));
    REQUIRE((decimal64(1) += 2) == decimal64(3));
    REQUIRE((decimal64(1) += 2U) == decimal64(3));
    REQUIRE((decimal64(1) += 2L) == decimal64(3));
    REQUIRE((decimal64(1) += 2LU) == decimal64(3));
    REQUIRE((decimal64(1) += 2LL) == decimal64(3));
    REQUIRE((decimal64(1) += 2LLU) == decimal64(3));
    REQUIRE((decimal64(1) += 2.0F) == decimal64(3));
    REQUIRE((decimal64(1) += 2.0) == decimal64(3));
    REQUIRE((decimal64(1) += 2.0L) == decimal64(3));

    REQUIRE((decimal128(1) += decimal32(2)) == decimal128(3));
    REQUIRE((decimal128(1) += decimal64(2)) == decimal128(3));
    REQUIRE((decimal128(1) += decimal128(2)) == decimal128(3));
    REQUIRE((decimal128(1) += 2) == decimal128(3));
    REQUIRE((decimal128(1) += 2U) == decimal128(3));
    REQUIRE((decimal128(1) += 2L) == decimal128(3));
    REQUIRE((decimal128(1) += 2LU) == decimal128(3));
    REQUIRE((decimal128(1) += 2LL) == decimal128(3));
    REQUIRE((decimal128(1) += 2LLU) == decimal128(3));
    REQUIRE((decimal128(1) += 2.0F) == decimal128(3));
    REQUIRE((decimal128(1) += 2.0) == decimal128(3));
    REQUIRE((decimal128(1) += 2.0L) == decimal128(3));
}

TEST_CASE_METHOD(decimal_Fixture, "compound assignment subtraction")
{
    REQUIRE((decimal32(3) -= decimal32(2)) == decimal32(1));
    REQUIRE((decimal32(3) -= decimal64(2)) == decimal32(1));
    REQUIRE((decimal32(3) -= decimal128(2)) == decimal32(1));
    REQUIRE((decimal32(3) -= 2) == decimal32(1));
    REQUIRE((decimal32(3) -= 2U) == decimal32(1));
    REQUIRE((decimal32(3) -= 2L) == decimal32(1));
    REQUIRE((decimal32(3) -= 2LU) == decimal32(1));
    REQUIRE((decimal32(3) -= 2LL) == decimal32(1));
    REQUIRE((decimal32(3) -= 2LLU) == decimal32(1));
    REQUIRE((decimal32(3) -= 2.0F) == decimal32(1));
    REQUIRE((decimal32(3) -= 2.0) == decimal32(1));
    REQUIRE((decimal32(3) -= 2.0L) == decimal32(1));

    REQUIRE((decimal64(3) -= decimal32(2)) == decimal64(1));
    REQUIRE((decimal64(3) -= decimal64(2)) == decimal64(1));
    REQUIRE((decimal64(3) -= decimal128(2)) == decimal64(1));
    REQUIRE((decimal64(3) -= 2) == decimal64(1));
    REQUIRE((decimal64(3) -= 2U) == decimal64(1));
    REQUIRE((decimal64(3) -= 2L) == decimal64(1));
    REQUIRE((decimal64(3) -= 2LU) == decimal64(1));
    REQUIRE((decimal64(3) -= 2LL) == decimal64(1));
    REQUIRE((decimal64(3) -= 2LLU) == decimal64(1));
    REQUIRE((decimal64(3) -= 2.0F) == decimal64(1));
    REQUIRE((decimal64(3) -= 2.0) == decimal64(1));
    REQUIRE((decimal64(3) -= 2.0L) == decimal64(1));

    REQUIRE((decimal128(3) -= decimal32(2)) == decimal128(1));
    REQUIRE((decimal128(3) -= decimal64(2)) == decimal128(1));
    REQUIRE((decimal128(3) -= decimal128(2)) == decimal128(1));
    REQUIRE((decimal128(3) -= 2) == decimal128(1));
    REQUIRE((decimal128(3) -= 2U) == decimal128(1));
    REQUIRE((decimal128(3) -= 2L) == decimal128(1));
    REQUIRE((decimal128(3) -= 2LU) == decimal128(1));
    REQUIRE((decimal128(3) -= 2LL) == decimal128(1));
    REQUIRE((decimal128(3) -= 2LLU) == decimal128(1));
    REQUIRE((decimal128(3) -= 2.0F) == decimal128(1));
    REQUIRE((decimal128(3) -= 2.0) == decimal128(1));
    REQUIRE((decimal128(3) -= 2.0L) == decimal128(1));
}

TEST_CASE_METHOD(decimal_Fixture, "compound assignment multiplication")
{
    REQUIRE((decimal32(2) *= decimal32(3)) == decimal32(6));
    REQUIRE((decimal32(2) *= decimal64(3)) == decimal32(6));
    REQUIRE((decimal32(2) *= decimal128(3)) == decimal32(6));
    REQUIRE((decimal32(2) *= 3) == decimal32(6));
    REQUIRE((decimal32(2) *= 3U) == decimal32(6));
    REQUIRE((decimal32(2) *= 3L) == decimal32(6));
    REQUIRE((decimal32(2) *= 3LU) == decimal32(6));
    REQUIRE((decimal32(2) *= 3LL) == decimal32(6));
    REQUIRE((decimal32(2) *= 3LLU) == decimal32(6));
    REQUIRE((decimal32(2) *= 3.0F) == decimal32(6));
    REQUIRE((decimal32(2) *= 3.0) == decimal32(6));
    REQUIRE((decimal32(2) *= 3.0L) == decimal32(6));

    REQUIRE((decimal64(2) *= decimal32(3)) == decimal64(6));
    REQUIRE((decimal64(2) *= decimal64(3)) == decimal64(6));
    REQUIRE((decimal64(2) *= decimal128(3)) == decimal64(6));
    REQUIRE((decimal64(2) *= 3) == decimal64(6));
    REQUIRE((decimal64(2) *= 3U) == decimal64(6));
    REQUIRE((decimal64(2) *= 3L) == decimal64(6));
    REQUIRE((decimal64(2) *= 3LU) == decimal64(6));
    REQUIRE((decimal64(2) *= 3LL) == decimal64(6));
    REQUIRE((decimal64(2) *= 3LLU) == decimal64(6));
    REQUIRE((decimal64(2) *= 3.0F) == decimal64(6));
    REQUIRE((decimal64(2) *= 3.0) == decimal64(6));
    REQUIRE((decimal64(2) *= 3.0L) == decimal64(6));

    REQUIRE((decimal128(2) *= decimal32(3)) == decimal128(6));
    REQUIRE((decimal128(2) *= decimal64(3)) == decimal128(6));
    REQUIRE((decimal128(2) *= decimal128(3)) == decimal128(6));
    REQUIRE((decimal128(2) *= 3) == decimal128(6));
    REQUIRE((decimal128(2) *= 3U) == decimal128(6));
    REQUIRE((decimal128(2) *= 3L) == decimal128(6));
    REQUIRE((decimal128(2) *= 3LU) == decimal128(6));
    REQUIRE((decimal128(2) *= 3LL) == decimal128(6));
    REQUIRE((decimal128(2) *= 3LLU) == decimal128(6));
    REQUIRE((decimal128(2) *= 3.0F) == decimal128(6));
    REQUIRE((decimal128(2) *= 3.0) == decimal128(6));
    REQUIRE((decimal128(2) *= 3.0L) == decimal128(6));
}

TEST_CASE_METHOD(decimal_Fixture, "compound assignment division")
{
    REQUIRE((decimal32(6) /= decimal32(2)) == decimal32(3));
    REQUIRE((decimal32(6) /= decimal64(2)) == decimal32(3));
    REQUIRE((decimal32(6) /= decimal128(2)) == decimal32(3));
    REQUIRE((decimal32(6) /= 2) == decimal32(3));
    REQUIRE((decimal32(6) /= 2U) == decimal32(3));
    REQUIRE((decimal32(6) /= 2L) == decimal32(3));
    REQUIRE((decimal32(6) /= 2LU) == decimal32(3));
    REQUIRE((decimal32(6) /= 2LL) == decimal32(3));
    REQUIRE((decimal32(6) /= 2LLU) == decimal32(3));
    REQUIRE((decimal32(6) /= 2.0F) == decimal32(3));
    REQUIRE((decimal32(6) /= 2.0) == decimal32(3));
    REQUIRE((decimal32(6) /= 2.0L) == decimal32(3));

    REQUIRE((decimal64(6) /= decimal32(2)) == decimal64(3));
    REQUIRE((decimal64(6) /= decimal64(2)) == decimal64(3));
    REQUIRE((decimal64(6) /= decimal128(2)) == decimal64(3));
    REQUIRE((decimal64(6) /= 2) == decimal64(3));
    REQUIRE((decimal64(6) /= 2U) == decimal64(3));
    REQUIRE((decimal64(6) /= 2L) == decimal64(3));
    REQUIRE((decimal64(6) /= 2LU) == decimal64(3));
    REQUIRE((decimal64(6) /= 2LL) == decimal64(3));
    REQUIRE((decimal64(6) /= 2LLU) == decimal64(3));
    REQUIRE((decimal64(6) /= 2.0F) == decimal64(3));
    REQUIRE((decimal64(6) /= 2.0) == decimal64(3));
    REQUIRE((decimal64(6) /= 2.0L) == decimal64(3));

    REQUIRE((decimal128(6) /= decimal32(2)) == decimal128(3));
    REQUIRE((decimal128(6) /= decimal64(2)) == decimal128(3));
    REQUIRE((decimal128(6) /= decimal128(2)) == decimal128(3));
    REQUIRE((decimal128(6) /= 2) == decimal128(3));
    REQUIRE((decimal128(6) /= 2U) == decimal128(3));
    REQUIRE((decimal128(6) /= 2L) == decimal128(3));
    REQUIRE((decimal128(6) /= 2LU) == decimal128(3));
    REQUIRE((decimal128(6) /= 2LL) == decimal128(3));
    REQUIRE((decimal128(6) /= 2LLU) == decimal128(3));
    REQUIRE((decimal128(6) /= 2.0F) == decimal128(3));
    REQUIRE((decimal128(6) /= 2.0) == decimal128(3));
    REQUIRE((decimal128(6) /= 2.0L) == decimal128(3));
}

TEST_CASE_METHOD(decimal_Fixture, "increment and decrement operators")
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
