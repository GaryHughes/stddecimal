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
const boost::regex test_regex("^\\s*(\\S+)\\s+(\\S+)\\s+(\\.+\\s+){1,3}->\\s+(\\S+)\\s*(.*)");

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

    if (boost::regex_match(line, match, test_regex)) {
    
        m_type = line_type::test;
        m_id = match[1].str();
    
        m_operation = match[2].str();
        boost::algorithm::to_lower(m_operation);

        auto operand_string{match[3].str()};
        boost::trim(operand_string);
        boost::split(m_operands, operand_string, boost::is_any_of("\t "), boost::token_compress_on);
        for (auto& operand : m_operands) {
            boost::erase_all(operand, "'");
        }
        
        m_expected_result = match[4];
        boost::erase_all(m_expected_result, "'");
    
        auto expected_conditions_string = match[5].str();
        boost::trim(expected_conditions_string);
        boost::algorithm::to_lower(expected_conditions_string);
        m_expected_conditions = parse_conditions(expected_conditions_string);
        return;
    }

    throw std::runtime_error("unrecognised line: " + line);
}

std::decimal::fexcept_t test_line::parse_conditions(const std::string& condition_string)
{
    std::vector<std::string> conditions;
    boost::split(conditions, condition_string, boost::is_any_of("\t "), boost::token_compress_on);
    std::decimal::fexcept_t res = 0;
    for (const auto& condition : conditions) {

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