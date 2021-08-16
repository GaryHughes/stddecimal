#include "test_line.hpp"
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>

namespace gda
{

const boost::regex comment_regex("^\\s*--.*");
// keyword: value
const boost::regex directive_regex("^([^:]+):(.+)");
// add060 add '10000e+9'  '70000' -> '1.00000E+13' Inexact Rounded
const boost::regex test_regex("^\\s*(\\S+)\\s+(\\S+)\\s+(\\.+\\s+){1,3}->\\s+(\\.+)\\s*(.*)");

test_line::test_line(std::string line)
{
    boost::algorithm::trim_all(line);
    
    if (line.empty())
    {
        m_type = line_type::blank;
        return; 
    }

    if (boost::regex_match(line, comment_regex)) {
        m_type = line_type::comment;
        return;
    }

    boost::smatch match;

    if (boost::regex_match(line, match, directive_regex)) {
        m_type = line_type::directive;
        m_keyword = match[1].str();
        boost::algorithm::trim_all(m_keyword);
        m_value = match[2].str();
        boost::algorithm::trim_all(m_value);
        return;
    }

    std::string arrow = "->";
    auto arrow_pos = line.find(arrow);

    if (arrow_pos == std::string::npos) {
        throw std::runtime_error("failed to find -> on line: " + line);
    }

    auto left = line.substr(0, arrow_pos);
    auto right = line.substr(arrow_pos + arrow.length());

    std::vector<std::string> tokens;
    tokenise(left, tokens);

    if (tokens.size() < 3 || tokens.size() > 5) {
        throw std::runtime_error("there can only be between 3 and 5 tokens on the left of the arrow: " + line);
    }

    m_id = tokens[0];
    m_operation = tokens[1];
    m_operands.push_back(tokens[2]);
    if (tokens.size() > 3) {
        m_operands.push_back(tokens[3]);
        if (tokens.size() > 4) {
            m_operands.push_back(tokens[4]);
        }
    }

    tokens.clear();
    tokenise(right, tokens);

    if (tokens.size() < 1) {
        throw std::runtime_error("there must be atleast 1 token on the right of the arrow: " + line);
    }

    m_expected_result = tokens[0];
    m_expected_conditions = parse_conditions(std::vector<std::string>(++tokens.begin(), tokens.end()));

    m_type = line_type::test;
}

void test_line::tokenise(const std::string text, std::vector<std::string>& tokens)
{
    std::string token;
    const char not_space = 'a';
    char previous = not_space;
    bool quoted_token = false;

    for (char c : text) {
        
        if ((std::isspace(c) && !std::isspace(previous)) || (c == '\'' && previous != '\'')) {
            if (!token.empty()) {
                tokens.push_back(token);
                token = "";
                previous = not_space;
            }
            continue;
        }

        if (!std::isspace(c)) {
            if (token.empty() && c == '\'') {
                quoted_token = true;
            }
            else {
                token += c;
            }        
        }

        previous = c;
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }
}

std::decimal::fexcept_t test_line::parse_conditions(const std::vector<std::string>& conditions)
{
    std::decimal::fexcept_t res = 0;
    for (const auto& text : conditions) {
        std::string condition = text;
        boost::algorithm::to_lower(condition);
            // clamped                 NA
        if (condition == "conversion_syntax")           {   res |= std::decimal::FE_DEC_INVALID;    }
        else if (condition == "division_by_zero") 	    {   res |= std::decimal::FE_DEC_DIVBYZERO;  }
        else if (condition == "division_impossible")    {   res |= std::decimal::FE_DEC_INVALID;    }
        else if (condition == "division_undefined")     {   res |= std::decimal::FE_DEC_INVALID;    }
        else if (condition == "inexact")	            {   res |= std::decimal::FE_DEC_INEXACT;    }
        else if (condition == "insufficient_storage")   {   res |= std::decimal::FE_DEC_INVALID;    }
        else if (condition == "invalid_context")        {   res |= std::decimal::FE_DEC_INVALID;    }
        else if (condition == "invalid_operation")      {   res |= std::decimal::FE_DEC_INVALID;    }
            // lost_digits	            (no equivalent)
        else if (condition == "overflow")               {   res |= std::decimal::FE_DEC_OVERFLOW;   } 
        // TODO dectest says IEEE has no equivalent, we get inexact so use that for now and investigate later
        else if (condition == "rounded")                {   res |= std::decimal::FE_DEC_INEXACT;    } 
            // subnormal	        	(no equivalent)
        else if (condition == "underflow")              {   res |= std::decimal::FE_DEC_UNDERFLOW;  }
    }
    return res;
}

test_line::line_type test_line::type() const
{
    return m_type;
}

bool test_line::is_blank() const
{
    return type() == line_type::blank;
}

bool test_line::is_comment() const
{
    return type() == line_type::comment;
}

bool test_line::is_directive() const
{
    return type() == line_type::directive;
}

bool test_line::is_test() const
{
    return type() == line_type::test;
}

const std::string& test_line::keyword() const
{
    return m_keyword;
}

const std::string& test_line::value() const
{
    return m_value;
}

const std::string& test_line::id() const
{
    return m_id;
}

const std::string& test_line::operation() const
{
    return m_operation;
}

const std::vector<std::string>& test_line::operands() const
{
    return m_operands;
}

const std::string& test_line::expected_result() const
{
    return m_expected_result;
}

std::decimal::fexcept_t test_line::expected_conditions() const
{
    return m_expected_conditions;
}

} // namespace gda