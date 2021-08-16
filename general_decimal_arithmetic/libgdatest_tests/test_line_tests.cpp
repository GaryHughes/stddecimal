#include <catch.hpp>
#include <libgdatest/test_line.hpp>

TEST_CASE("test line", "gdatest") 
{
    SECTION("test blank line")
    {
        gda::test_line line("");
        REQUIRE(line.type() == gda::test_line::line_type::blank);
    }

    SECTION("test whitespace line")
    {
        gda::test_line line("    ");
        REQUIRE(line.type() == gda::test_line::line_type::blank);
    }

    SECTION("test comment")
    {
        gda::test_line line("-- this is a comment");
        REQUIRE(line.type() == gda::test_line::line_type::comment);
    }

    SECTION("test comment with leading whitespace")
    {
        gda::test_line line("  -- this is a comment with leading whitespace");
        REQUIRE(line.type() == gda::test_line::line_type::comment);
    }

    SECTION("test directive")
    {
        gda::test_line line("precision:   9");
        REQUIRE(line.type() == gda::test_line::line_type::directive);
        REQUIRE(line.keyword() == "precision");
        REQUIRE(line.value() == "9");
    }


}

