#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_line_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_line_hpp

#include <string>
#include <vector>
#include <decimal.hpp>

namespace gda
{

class test_line
{
public:

    enum class line_type {
        // Lines with no characters, or only space characters. These lines are treated as commentary and are ignored.
        blank,
        // If the first two characters of a token are two hyphens (--) the token indicates the start of a comment. The two-hyphen 
        // sequence and any characters that follow it, up to the end of the line on which the sequence occurs, are ignored
        comment,
        // keyword: value
        directive,
        // id operation operand1 operand2 operand3 -> result conditions
        // operand2 and 3 are optional
        test
    };

    test_line(std::string line);

    line_type type() const;
    bool is_blank() const;
    bool is_comment() const;
    bool is_directive() const;
    bool is_test() const;

    // type() == directive
    const std::string& keyword() const;
    const std::string& value() const;

    // type() == test
    const std::string& id() const;
    const std::string& operation() const;
    const std::vector<std::string>& operands() const;
    const std::string& expected_result() const;
    std::decimal::fexcept_t expected_conditions() const;

private:

    std::decimal::fexcept_t parse_conditions(const std::vector<std::string>& conditions);
    void tokenise(const std::string text, std::vector<std::string>& tokens);

    line_type m_type;

    // type() == directive
    std::string m_keyword;
    std::string m_value;

    // type() == test
    std::string m_id;
    std::string m_operation;
    std::vector<std::string> m_operands;
    std::string m_expected_result;
    std::decimal::fexcept_t m_expected_conditions = 0;

};

} // namespace gda

#endif