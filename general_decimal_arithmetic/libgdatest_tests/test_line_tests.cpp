#include <catch.hpp>
#include <libgdatest/test_line.hpp>

TEST_CASE("test line", "gdatest") 
{
    SECTION("test blank line")
    {
        gda::test_line line("");
        REQUIRE(line.type() == gda::test_line::line_type::blank);
        REQUIRE(line.is_blank());
    }

    SECTION("test whitespace line")
    {
        gda::test_line line("    ");
        REQUIRE(line.type() == gda::test_line::line_type::blank);
        REQUIRE(line.is_blank());
    }

    SECTION("test comment")
    {
        gda::test_line line("-- this is a comment");
        REQUIRE(line.type() == gda::test_line::line_type::comment);
        REQUIRE(line.is_comment());
    }

    SECTION("test comment with leading whitespace")
    {
        gda::test_line line("  -- this is a comment with leading whitespace");
        REQUIRE(line.type() == gda::test_line::line_type::comment);
        REQUIRE(line.is_comment());
    }

    SECTION("test directive")
    {
        gda::test_line line("precision:   9");
        REQUIRE(line.type() == gda::test_line::line_type::directive);
        REQUIRE(line.is_directive());
        REQUIRE(line.keyword() == "precision");
        REQUIRE(line.value() == "9");
    }

    SECTION("test test with 2 simple operands and no conditions")
    {
        gda::test_line line("add001 add 1       1       ->  2");
        REQUIRE(line.type() ==  gda::test_line::line_type::test);
        REQUIRE(line.is_test());
        REQUIRE(line.id() == "add001");
        REQUIRE(line.operation() == "add");
        REQUIRE(line.operands().size() == 2);
        REQUIRE(line.operands()[0] == "1");
        REQUIRE(line.operands()[1] == "1");
        REQUIRE(line.expected_result() == "2");
        REQUIRE(line.expected_conditions() == 0);
    }

    SECTION("test with no operands") 
    {
        REQUIRE_THROWS(gda::test_line("add001 add -> 2"));
    }

    SECTION("test with too many operands") 
    {
        REQUIRE_THROWS(gda::test_line("add001 add 1 2 3 4 -> 2"));
    }

    SECTION("test with quoted operands")
    {
        gda::test_line line("add003 add '5.75'  '3.3'   ->  9.05");
        REQUIRE(line.type() ==  gda::test_line::line_type::test);
        REQUIRE(line.is_test());
        REQUIRE(line.id() == "add003");
        REQUIRE(line.operation() == "add");
        REQUIRE(line.operands().size() == 2);
        REQUIRE(line.operands()[0] == "5.75");
        REQUIRE(line.operands()[1] == "3.3");
        REQUIRE(line.expected_result() == "9.05");
        REQUIRE(line.expected_conditions() == 0);
    }

    SECTION("test with quoted operands and quoted result")
    {
        gda::test_line line("add010 add '1.23456789'  '1.00000011' -> '2.23456800'");
        REQUIRE(line.type() ==  gda::test_line::line_type::test);
        REQUIRE(line.is_test());
        REQUIRE(line.id() == "add010");
        REQUIRE(line.operation() == "add");
        REQUIRE(line.operands().size() == 2);
        REQUIRE(line.operands()[0] == "1.23456789");
        REQUIRE(line.operands()[1] == "1.00000011");
        REQUIRE(line.expected_result() == "2.23456800");
        REQUIRE(line.expected_conditions() == 0);
    }

    SECTION("test with expected conditions")
    {
        gda::test_line line("add011 add '0.4444444444'  '0.5555555555' -> '1.00000000' Inexact Lost_digits Rounded");
        REQUIRE(line.type() ==  gda::test_line::line_type::test);
        REQUIRE(line.is_test());
        REQUIRE(line.id() == "add011");
        REQUIRE(line.operation() == "add");
        REQUIRE(line.operands().size() == 2);
        REQUIRE(line.operands()[0] == "0.4444444444");
        REQUIRE(line.operands()[1] == "0.5555555555");
        REQUIRE(line.expected_result() == "1.00000000");
        REQUIRE(line.expected_conditions() == std::decimal::FE_DEC_INEXACT);
    }
}

