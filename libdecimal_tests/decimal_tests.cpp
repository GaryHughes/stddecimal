#include <catch.hpp>
#include <libdecimal/decimal.hpp>

using namespace std::decimal;

TEST_CASE("decimal", "decimal") 
{
    SECTION("constructors")
    {
       REQUIRE(decimal32() == 0);
    
      
    
    }

    SECTION("makers")
    {
        // decimal32 make_decimal32(long long coeff, int exponent); 
        // decimal32 make_decimal32(unsigned long long coeff, int exponent);
    }

    SECTION("unary arithmetic")
    {
        REQUIRE(+decimal32(1) == 1);
        REQUIRE(+decimal64(1) == 1);
        // REQUIRE(+decimal128(1) == 1);

        REQUIRE(+decimal32(-1) == -1);
        REQUIRE(+decimal64(-1) == -1);
        // REQUIRE(+decimal128(-1) == -1);

        REQUIRE(+decimal32(0) == 0);
        REQUIRE(+decimal64(0) == 0);
        // REQUIRE(+decimal128(0) == 0);

        REQUIRE(-decimal32(1) == -1);
        REQUIRE(-decimal64(1) == -1);
        // REQUIRE(-decimal128(1) == -1);

        REQUIRE(-decimal32(-1) == 1);
        REQUIRE(-decimal64(-1) == 1);
        // REQUIRE(-decimal128(-1) == 1);

        REQUIRE(-decimal32(0) == 0);
        REQUIRE(-decimal64(0) == 0);
        // REQUIRE(-decimal128(0) == 0);
    }

    SECTION("binary addition")
    {
        decimal32(0) + decimal32(0);
        decimal32(0) + decimal64(0);
        decimal32(0) + decimal128(0);

        decimal64(0) + decimal32(0);
        decimal64(0) + decimal64(0);
        decimal64(0) + decimal128(0);

        decimal128(0) + decimal32(0);
        decimal128(0) + decimal64(0);
        decimal128(0) + decimal128(0);

        decimal32(0) + 0;
        decimal32(0) + 0u;
        decimal32(0) + 0l;
        decimal32(0) + 0lu;
        decimal32(0) + 0ll;
        decimal32(0) + 0llu;

        0 + decimal32(0);
        0u + decimal32(0);
        0l + decimal32(0);
        0lu + decimal32(0);
        0ll + decimal32(0);
        0llu + decimal32(0);

        decimal64(0) + 0;
        decimal64(0) + 0u;
        decimal64(0) + 0l;
        decimal64(0) + 0lu;
        decimal64(0) + 0ll;
        decimal64(0) + 0llu;

        0 + decimal64(0);
        0u + decimal64(0);
        0l + decimal64(0);
        0lu + decimal64(0);
        0ll + decimal64(0);
        0llu + decimal64(0);

        decimal128(0) + 0;
        decimal128(0) + 0u;
        decimal128(0) + 0l;
        decimal128(0) + 0lu;
        decimal128(0) + 0ll;
        decimal128(0) + 0llu;

        0 + decimal128(0);
        0u + decimal128(0);
        0l + decimal128(0);
        0lu + decimal128(0);
        0ll + decimal128(0);
        0llu + decimal128(0);
    }

    SECTION("binary subtraction")
    {
        decimal32(0) - decimal32(0);
        decimal32(0) - decimal64(0);
        decimal32(0) - decimal128(0);

        decimal64(0) - decimal32(0);
        decimal64(0) - decimal64(0);
        decimal64(0) - decimal128(0);
        
        decimal128(0) - decimal32(0);
        decimal128(0) - decimal64(0);
        decimal128(0) - decimal128(0);

        decimal32(0) - 0;
        decimal32(0) - 0u;
        decimal32(0) - 0l;
        decimal32(0) - 0lu;
        decimal32(0) - 0ll;
        decimal32(0) - 0llu;

        0 - decimal32(0);
        0u - decimal32(0);
        0l - decimal32(0);
        0lu - decimal32(0);
        0ll - decimal32(0);
        0llu - decimal32(0);

        decimal64(0) - 0;
        decimal64(0) - 0u;
        decimal64(0) - 0l;
        decimal64(0) - 0lu;
        decimal64(0) - 0ll;
        decimal64(0) - 0llu;

        0 - decimal64(0);
        0u - decimal64(0);
        0l - decimal64(0);
        0lu - decimal64(0);
        0ll - decimal64(0);
        0llu - decimal64(0);

        decimal128(0) - 0;
        decimal128(0) - 0u;
        decimal128(0) - 0l;
        decimal128(0) - 0lu;
        decimal128(0) - 0ll;
        decimal128(0) - 0llu;

        0 - decimal128(0);
        0u - decimal128(0);
        0l - decimal128(0);
        0lu - decimal128(0);
        0ll - decimal128(0);
        0llu - decimal128(0);
    }

    SECTION("binary multiplication")
    {
        decimal32(0) * decimal32(0);
        decimal32(0) * decimal64(0);
        decimal32(0) * decimal128(0);

        decimal64(0) * decimal32(0);
        decimal64(0) * decimal64(0);
        decimal64(0) * decimal128(0);
        
        decimal128(0) * decimal32(0);
        decimal128(0) * decimal64(0);
        decimal128(0) * decimal128(0);
    
        decimal32(0) * 0;
        decimal32(0) * 0u;
        decimal32(0) * 0l;
        decimal32(0) * 0lu;
        decimal32(0) * 0ll;
        decimal32(0) * 0llu;

        0 * decimal32(0);
        0u * decimal32(0);
        0l * decimal32(0);
        0lu * decimal32(0);
        0ll * decimal32(0);
        0llu * decimal32(0);

        decimal64(0) * 0;
        decimal64(0) * 0u;
        decimal64(0) * 0l;
        decimal64(0) * 0lu;
        decimal64(0) * 0ll;
        decimal64(0) * 0llu;

        0 * decimal64(0);
        0u * decimal64(0);
        0l * decimal64(0);
        0lu * decimal64(0);
        0ll * decimal64(0);
        0llu * decimal64(0);

        decimal128(0) * 0;
        decimal128(0) * 0u;
        decimal128(0) * 0l;
        decimal128(0) * 0lu;
        decimal128(0) * 0ll;
        decimal128(0) * 0llu;

        0 * decimal128(0);
        0u * decimal128(0);
        0l * decimal128(0);
        0lu * decimal128(0);
        0ll * decimal128(0);
        0llu * decimal128(0);
    
    }

    SECTION("binary division")
    {
        decimal32(0) / decimal32(0);
        decimal32(0) / decimal64(0);
        decimal32(0) / decimal128(0);

        decimal64(0) / decimal32(0);
        decimal64(0) / decimal64(0);
        decimal64(0) / decimal128(0);
        
        decimal128(0) / decimal32(0);
        decimal128(0) / decimal64(0);
        decimal128(0) / decimal128(0);

        decimal32(0) / 0;
        decimal32(0) / 0u;
        decimal32(0) / 0l;
        decimal32(0) / 0lu;
        decimal32(0) / 0ll;
        decimal32(0) / 0llu;

        0 / decimal32(0);
        0u / decimal32(0);
        0l / decimal32(0);
        0lu / decimal32(0);
        0ll / decimal32(0);
        0llu / decimal32(0);

        decimal64(0) / 0;
        decimal64(0) / 0u;
        decimal64(0) / 0l;
        decimal64(0) / 0lu;
        decimal64(0) / 0ll;
        decimal64(0) / 0llu;

        0 / decimal64(0);
        0u / decimal64(0);
        0l / decimal64(0);
        0lu / decimal64(0);
        0ll / decimal64(0);
        0llu / decimal64(0);

        decimal128(0) / 0;
        decimal128(0) / 0u;
        decimal128(0) / 0l;
        decimal128(0) / 0lu;
        decimal128(0) / 0ll;
        decimal128(0) / 0llu;

        0 / decimal128(0);
        0u / decimal128(0);
        0l / decimal128(0);
        0lu / decimal128(0);
        0ll / decimal128(0);
        0llu / decimal128(0);
    }

    SECTION("binary equal")
    {
        REQUIRE(decimal32(0) == decimal32(0));
        REQUIRE(decimal32(0) == decimal64(0));
        // REQUIRE(decimal32(0) == decimal128(0));

        REQUIRE(decimal64(0) == decimal32(0));
        REQUIRE(decimal64(0) == decimal64(0));
        // REQUIRE(decimal64(0) == decimal128(0));
        
        // REQUIRE(decimal128(0) == decimal32(0));
        // REQUIRE(decimal128(0) == decimal64(0));
        // REQUIRE(decimal128(0) == decimal128(0));

        REQUIRE(decimal32(0) == 0);
        REQUIRE(decimal32(0) == 0u);
        REQUIRE(decimal32(0) == 0l);
        REQUIRE(decimal32(0) == 0lu);
        REQUIRE(decimal32(0) == 0ll);
        REQUIRE(decimal32(0) == 0llu);

        REQUIRE(0 == decimal32(0));
        REQUIRE(0u == decimal32(0));
        REQUIRE(0l == decimal32(0));
        REQUIRE(0lu == decimal32(0));
        REQUIRE(0ll == decimal32(0));
        REQUIRE(0llu == decimal32(0));

        REQUIRE(decimal64(0) == 0);
        REQUIRE(decimal64(0) == 0u);
        REQUIRE(decimal64(0) == 0l);
        REQUIRE(decimal64(0) == 0lu);
        REQUIRE(decimal64(0) == 0ll);
        REQUIRE(decimal64(0) == 0llu);

        REQUIRE(0 == decimal64(0));
        REQUIRE(0u == decimal64(0));
        REQUIRE(0l == decimal64(0));
        REQUIRE(0lu == decimal64(0));
        REQUIRE(0ll == decimal64(0));
        REQUIRE(0llu == decimal64(0));

        // REQUIRE(decimal128(0) == 0);
        // REQUIRE(decimal128(0) == 0u);
        // REQUIRE(decimal128(0) == 0l);
        // REQUIRE(decimal128(0) == 0lu);
        // REQUIRE(decimal128(0) == 0ll);
        // REQUIRE(decimal128(0) == 0llu);

        // REQUIRE(0 == decimal128(0));
        // REQUIRE(0u == decimal128(0));
        // REQUIRE(0l == decimal128(0));
        // REQUIRE(0lu == decimal128(0));
        // REQUIRE(0ll == decimal128(0));
        // REQUIRE(0llu == decimal128(0));
    }

    SECTION("binary not equal")
    {
        REQUIRE(decimal32(0) != decimal32(1));
        REQUIRE(decimal32(0) != decimal64(1));
        // REQUIRE(decimal32(0) != decimal128(1));

        REQUIRE(decimal64(0) != decimal32(1));
        REQUIRE(decimal64(0) != decimal64(1));
        // REQUIRE(decimal64(0) != decimal128(1));
        
        // REQUIRE(decimal128(0) != decimal32(1));
        // REQUIRE(decimal128(0) != decimal64(1));
        // REQUIRE(decimal128(0) != decimal128(1));

        REQUIRE(decimal32(0) != 1);
        REQUIRE(decimal32(0) != 1u);
        REQUIRE(decimal32(0) != 1l);
        REQUIRE(decimal32(0) != 1lu);
        // REQUIRE(decimal32(0) != 1ll);
        // REQUIRE(decimal32(0) != 1llu);

        REQUIRE(0 != decimal32(1));
        REQUIRE(0u != decimal32(1));
        REQUIRE(0l != decimal32(1));
        REQUIRE(0lu != decimal32(1));
        // REQUIRE(0ll != decimal32(1));
        // REQUIRE(0llu != decimal32(1));

        REQUIRE(decimal64(0) != 1);
        REQUIRE(decimal64(0) != 1u);
        REQUIRE(decimal64(0) != 1l);
        REQUIRE(decimal64(0) != 1lu);
        // REQUIRE(decimal64(0) != 1ll);
        // REQUIRE(decimal64(0) != 1llu);

        REQUIRE(0 != decimal64(1));
        REQUIRE(0u != decimal64(1));
        REQUIRE(0l != decimal64(1));
        REQUIRE(0lu != decimal64(1));
        // REQUIRE(0ll != decimal64(1));
        // REQUIRE(0llu != decimal64(1));

        // REQUIRE(decimal128(0) != 1);
        // REQUIRE(decimal128(0) != 1u);
        // REQUIRE(decimal128(0) != 1l);
        // REQUIRE(decimal128(0) != 1lu);
        // REQUIRE(decimal128(0) != 1ll);
        // REQUIRE(decimal128(0) != 1llu);

        // REQUIRE(0 != decimal128(1));
        // REQUIRE(0u != decimal128(1));
        // REQUIRE(0l != decimal128(1));
        // REQUIRE(0lu != decimal128(1));
        // REQUIRE(0ll != decimal128(1));
        // REQUIRE(0llu != decimal128(1));
    }

    SECTION("binary less")
    {
        REQUIRE(decimal32(0) < decimal32(1));
        REQUIRE(decimal32(0) < decimal64(1));
        // REQUIRE(decimal32(0) < decimal128(1));

        REQUIRE(decimal64(0) < decimal32(1));
        REQUIRE(decimal64(0) < decimal64(1));
        // REQUIRE(decimal64(0) < decimal128(1));
        
        // REQUIRE(decimal128(0) < decimal32(1));
        // REQUIRE(decimal128(0) < decimal64(1));
        // REQUIRE(decimal128(0) < decimal128(1));

        REQUIRE(decimal32(0) < 1);
        REQUIRE(decimal32(0) < 1u);
        REQUIRE(decimal32(0) < 1l);
        REQUIRE(decimal32(0) < 1lu);
        // REQUIRE(decimal32(0) < 1ll);
        // REQUIRE(decimal32(0) < 1llu);

        REQUIRE(0 < decimal32(1));
        REQUIRE(0u < decimal32(1));
        REQUIRE(0l < decimal32(1));
        REQUIRE(0lu < decimal32(1));
        // REQUIRE(0ll < decimal32(1));
        // REQUIRE(0llu < decimal32(1));

        REQUIRE(decimal64(0) < 1);
        REQUIRE(decimal64(0) < 1u);
        REQUIRE(decimal64(0) < 1l);
        REQUIRE(decimal64(0) < 1lu);
        // REQUIRE(decimal64(0) < 1ll);
        // REQUIRE(decimal64(0) < 1llu);

        REQUIRE(0 < decimal64(1));
        REQUIRE(0u < decimal64(1));
        REQUIRE(0l < decimal64(1));
        REQUIRE(0lu < decimal64(1));
        // REQUIRE(0ll < decimal64(1));
        // REQUIRE(0llu < decimal64(1));

        // REQUIRE(decimal128(0) < 1);
        // REQUIRE(decimal128(0) < 1u);
        // REQUIRE(decimal128(0) < 1l);
        // REQUIRE(decimal128(0) < 1lu);
        // REQUIRE(decimal128(0) < 1ll);
        // REQUIRE(decimal128(0) < 1llu);

        // REQUIRE(0 < decimal128(1));
        // REQUIRE(0u < decimal128(1));
        // REQUIRE(0l < decimal128(1));
        // REQUIRE(0lu < decimal128(1));
        // REQUIRE(0ll < decimal128(1));
        // REQUIRE(0llu < decimal128(1));
    }

    SECTION("binary less than or equal")
    {
        REQUIRE(decimal32(0) <= decimal32(1));
        REQUIRE(decimal32(0) <= decimal64(1));
        // REQUIRE(decimal32(0) <= decimal128(1));

        REQUIRE(decimal64(0) <= decimal32(1));
        REQUIRE(decimal64(0) <= decimal64(1));
        // REQUIRE(decimal64(0) <= decimal128(1));
        
        // REQUIRE(decimal128(0) <= decimal32(1));
        // REQUIRE(decimal128(0) <= decimal64(1));
        // REQUIRE(decimal128(0) <= decimal128(1));

        REQUIRE(decimal32(0) <= 1);
        REQUIRE(decimal32(0) <= 1u);
        REQUIRE(decimal32(0) <= 1l);
        REQUIRE(decimal32(0) <= 1lu);
        // REQUIRE(decimal32(0) <= 1ll);
        // REQUIRE(decimal32(0) <= 1llu);

        REQUIRE(0 <= decimal32(1));
        REQUIRE(0u <= decimal32(1));
        REQUIRE(0l <= decimal32(1));
        REQUIRE(0lu <= decimal32(1));
        // REQUIRE(0ll <= decimal32(1));
        // REQUIRE(0llu <= decimal32(1));

        REQUIRE(decimal64(0) <= 1);
        REQUIRE(decimal64(0) <= 1u);
        REQUIRE(decimal64(0) <= 1l);
        REQUIRE(decimal64(0) <= 1lu);
        // REQUIRE(decimal64(0) <= 1ll);
        // REQUIRE(decimal64(0) <= 1llu);

        REQUIRE(0 <= decimal64(1));
        REQUIRE(0u <= decimal64(1));
        REQUIRE(0l <= decimal64(1));
        REQUIRE(0lu <= decimal64(1));
        // REQUIRE(0ll <= decimal64(1));
        // REQUIRE(0llu <= decimal64(1));

        // REQUIRE(decimal128(0) <= 1);
        // REQUIRE(decimal128(0) <= 1u);
        // REQUIRE(decimal128(0) <= 1l);
        // REQUIRE(decimal128(0) <= 1lu);
        // REQUIRE(decimal128(0) <= 1ll);
        // REQUIRE(decimal128(0) <= 1llu);

        // REQUIRE(0 <= decimal128(1));
        // REQUIRE(0u <= decimal128(1));
        // REQUIRE(0l <= decimal128(1));
        // REQUIRE(0lu <= decimal128(1));
        // REQUIRE(0ll <= decimal128(1));
        // REQUIRE(0llu <= decimal128(1));
    }

    SECTION("binary greater")
    {
        REQUIRE(decimal32(1) > decimal32(0));
        REQUIRE(decimal32(1) > decimal64(0));
        // REQUIRE(decimal32(1) > decimal128(0));

        REQUIRE(decimal64(1) > decimal32(0));
        REQUIRE(decimal64(1) > decimal64(0));
        // REQUIRE(decimal64(1) > decimal128(0));
        
        // REQUIRE(decimal128(1) > decimal32(0));
        // REQUIRE(decimal128(1) > decimal64(0));
        // REQUIRE(decimal128(1) > decimal128(0));

        REQUIRE(decimal32(1) > 0);
        REQUIRE(decimal32(1) > 0u);
        REQUIRE(decimal32(1) > 0l);
        REQUIRE(decimal32(1) > 0lu);
        REQUIRE(decimal32(1) > 0ll);
        REQUIRE(decimal32(1) > 0llu);

        REQUIRE(1 > decimal32(0));
        REQUIRE(1u > decimal32(0));
        REQUIRE(1l > decimal32(0));
        REQUIRE(1lu > decimal32(0));
        // REQUIRE(1ll > decimal32(0));
        // REQUIRE(1llu > decimal32(0));

        REQUIRE(decimal64(1) > 0);
        REQUIRE(decimal64(1) > 0u);
        REQUIRE(decimal64(1) > 0l);
        REQUIRE(decimal64(1) > 0lu);
        REQUIRE(decimal64(1) > 0ll);
        REQUIRE(decimal64(1) > 0llu);

        REQUIRE(1 > decimal64(0));
        REQUIRE(1u > decimal64(0));
        REQUIRE(1l > decimal64(0));
        REQUIRE(1lu > decimal64(0));
        // REQUIRE(1ll > decimal64(0));
        // REQUIRE(1llu > decimal64(0));

        // REQUIRE(decimal128(1) > 0);
        // REQUIRE(decimal128(1) > 0u);
        // REQUIRE(decimal128(1) > 0l);
        // REQUIRE(decimal128(1) > 0lu);
        // REQUIRE(decimal128(1) > 0ll);
        // REQUIRE(decimal128(1) > 0llu);

        // REQUIRE(1 > decimal128(0));
        // REQUIRE(1u > decimal128(0));
        // REQUIRE(1l > decimal128(0));
        // REQUIRE(1lu > decimal128(0));
        // REQUIRE(1ll > decimal128(0));
        // REQUIRE(1llu > decimal128(0));
    }

    SECTION("binary greater than or equal")
    {
        REQUIRE(decimal32(1) >= decimal32(0));
        REQUIRE(decimal32(1) >= decimal64(0));
        // REQUIRE(decimal32(1) >= decimal128(0));

        REQUIRE(decimal64(1) >= decimal32(0));
        REQUIRE(decimal64(1) >= decimal64(0));
        // REQUIRE(decimal64(1) >= decimal128(0));
        
        // REQUIRE(decimal128(1) >= decimal32(0));
        // REQUIRE(decimal128(1) >= decimal64(0));
        // REQUIRE(decimal128(1) >= decimal128(0));

        REQUIRE(decimal32(1) >= 0);
        REQUIRE(decimal32(1) >= 0u);
        REQUIRE(decimal32(1) >= 0l);
        REQUIRE(decimal32(1) >= 0lu);
        REQUIRE(decimal32(1) >= 0ll);
        REQUIRE(decimal32(1) >= 0llu);

        REQUIRE(1 >= decimal32(0));
        REQUIRE(1u >= decimal32(0));
        REQUIRE(1l >= decimal32(0));
        REQUIRE(1lu >= decimal32(0));
        // REQUIRE(1ll >= decimal32(0));
        // REQUIRE(1llu >= decimal32(0));

        REQUIRE(decimal64(1) >= 0);
        REQUIRE(decimal64(1) >= 0u);
        REQUIRE(decimal64(1) >= 0l);
        REQUIRE(decimal64(1) >= 0lu);
        REQUIRE(decimal64(1) >= 0ll);
        REQUIRE(decimal64(1) >= 0llu);

        REQUIRE(1 >= decimal64(0));
        REQUIRE(1u >= decimal64(0));
        REQUIRE(1l >= decimal64(0));
        REQUIRE(1lu >= decimal64(0));
        // REQUIRE(1ll >= decimal64(0));
        // REQUIRE(1llu >= decimal64(0));

        // REQUIRE(decimal128(1) >= 0);
        // REQUIRE(decimal128(1) >= 0u);
        // REQUIRE(decimal128(1) >= 0l);
        // REQUIRE(decimal128(1) >= 0lu);
        // REQUIRE(decimal128(1) >= 0ll);
        // REQUIRE(decimal128(1) >= 0llu);

        // REQUIRE(1 >= decimal128(0));
        // REQUIRE(1u >= decimal128(0));
        // REQUIRE(1l >= decimal128(0));
        // REQUIRE(1lu >= decimal128(0));
        // REQUIRE(1ll >= decimal128(0));
        // REQUIRE(1llu >= decimal128(0));
    }

    SECTION("compound assignment addition")
    {
        decimal32(0) += decimal32(0);
        decimal32(0) += decimal64(0);
        decimal32(0) += decimal128(0);
        decimal32(0) += 0;
        decimal32(0) += 0u;
        decimal32(0) += 0l;
        decimal32(0) += 0lu;
        decimal32(0) += 0ll;
        decimal32(0) += 0llu;
        decimal32(0) += 0.0f;
        decimal32(0) += 0.0;
        decimal32(0) += 0.0l;

        decimal64(0) += decimal32(0);
        decimal64(0) += decimal64(0);
        decimal64(0) += decimal128(0);
        decimal64(0) += 0;
        decimal64(0) += 0u;
        decimal64(0) += 0l;
        decimal64(0) += 0lu;
        decimal64(0) += 0ll;
        decimal64(0) += 0llu;
        decimal64(0) += 0.0f;
        decimal64(0) += 0.0;
        decimal64(0) += 0.0l;

        decimal128(0) += decimal32(0);
        decimal128(0) += decimal64(0);
        decimal128(0) += decimal128(0);
        decimal128(0) += 0;
        decimal128(0) += 0u;
        decimal128(0) += 0l;
        decimal128(0) += 0lu;
        decimal128(0) += 0ll;
        decimal128(0) += 0llu;
        decimal128(0) += 0.0f;
        decimal128(0) += 0.0;
        decimal128(0) += 0.0l;
    }

    SECTION("compound assignment subtraction")
    {
        decimal32(0) -= decimal32(0);
        decimal32(0) -= decimal64(0);
        decimal32(0) -= decimal128(0);
        decimal32(0) -= 0;
        decimal32(0) -= 0u;
        decimal32(0) -= 0l;
        decimal32(0) -= 0lu;
        decimal32(0) -= 0ll;
        decimal32(0) -= 0llu;
        decimal32(0) -= 0.0f;
        decimal32(0) -= 0.0;
        decimal32(0) -= 0.0l;

        decimal64(0) -= decimal32(0);
        decimal64(0) -= decimal64(0);
        decimal64(0) -= decimal128(0);
        decimal64(0) -= 0;
        decimal64(0) -= 0u;
        decimal64(0) -= 0l;
        decimal64(0) -= 0lu;
        decimal64(0) -= 0ll;
        decimal64(0) -= 0llu;
        decimal64(0) -= 0.0f;
        decimal64(0) -= 0.0;
        decimal64(0) -= 0.0l;

        decimal128(0) -= decimal32(0);
        decimal128(0) -= decimal64(0);
        decimal128(0) -= decimal128(0);
        decimal128(0) -= 0;
        decimal128(0) -= 0u;
        decimal128(0) -= 0l;
        decimal128(0) -= 0lu;
        decimal128(0) -= 0ll;
        decimal128(0) -= 0llu;
        decimal128(0) -= 0.0f;
        decimal128(0) -= 0.0;
        decimal128(0) -= 0.0l;
    }

    SECTION("compound assignment multiplication")
    {
        decimal32(0) *= decimal32(0);
        decimal32(0) *= decimal64(0);
        decimal32(0) *= decimal128(0);
        decimal32(0) *= 0;
        decimal32(0) *= 0u;
        decimal32(0) *= 0l;
        decimal32(0) *= 0lu;
        decimal32(0) *= 0ll;
        decimal32(0) *= 0llu;
        decimal32(0) *= 0.0f;
        decimal32(0) *= 0.0;
        decimal32(0) *= 0.0l;

        decimal64(0) *= decimal32(0);
        decimal64(0) *= decimal64(0);
        decimal64(0) *= decimal128(0);
        decimal64(0) *= 0;
        decimal64(0) *= 0u;
        decimal64(0) *= 0l;
        decimal64(0) *= 0lu;
        decimal64(0) *= 0ll;
        decimal64(0) *= 0llu;
        decimal64(0) *= 0.0f;
        decimal64(0) *= 0.0;
        decimal64(0) *= 0.0l;

        decimal128(0) *= decimal32(0);
        decimal128(0) *= decimal64(0);
        decimal128(0) *= decimal128(0);
        decimal128(0) *= 0;
        decimal128(0) *= 0u;
        decimal128(0) *= 0l;
        decimal128(0) *= 0lu;
        decimal128(0) *= 0ll;
        decimal128(0) *= 0llu;
        decimal128(0) *= 0.0f;
        decimal128(0) *= 0.0;
        decimal128(0) *= 0.0l;
}

    SECTION("compound assignment division")
    {
        decimal32(0) /= decimal32(0);
        decimal32(0) /= decimal64(0);
        decimal32(0) /= decimal128(0);
        decimal32(0) /= 0;
        decimal32(0) /= 0u;
        decimal32(0) /= 0l;
        decimal32(0) /= 0lu;
        decimal32(0) /= 0ll;
        decimal32(0) /= 0llu;
        decimal32(0) /= 0.0f;
        decimal32(0) /= 0.0;
        decimal32(0) /= 0.0l;

        decimal64(0) /= decimal32(0);
        decimal64(0) /= decimal64(0);
        decimal64(0) /= decimal128(0);
        decimal64(0) /= 0;
        decimal64(0) /= 0u;
        decimal64(0) /= 0l;
        decimal64(0) /= 0lu;
        decimal64(0) /= 0ll;
        decimal64(0) /= 0llu;
        decimal64(0) /= 0.0f;
        decimal64(0) /= 0.0;
        decimal64(0) /= 0.0l;

        decimal128(0) /= decimal32(0);
        decimal128(0) /= decimal64(0);
        decimal128(0) /= decimal128(0);
        decimal128(0) /= 0;
        decimal128(0) /= 0u;
        decimal128(0) /= 0l;
        decimal128(0) /= 0lu;
        decimal128(0) /= 0ll;
        decimal128(0) /= 0llu;
        decimal128(0) /= 0.0f;
        decimal128(0) /= 0.0;
        decimal128(0) /= 0.0l;
    }
}