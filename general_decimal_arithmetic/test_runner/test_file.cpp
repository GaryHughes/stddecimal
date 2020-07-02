#include "test_file.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "test_context.hpp"


test_file::test_file(const std::string& filename, test_results& results)
:   m_is(filename),
    m_results(results)
{
    if (!m_is) {
        throw std::runtime_error("Unable to open test file '" + filename + "'");
    }
}

void test_file::process()
{
    // Lines with no characters, or only space characters. These lines are treated as commentary and are ignored.
    const std::regex empty_line_regex("^\\s*");
    // If the first two characters of a token are two hyphens (--) the token indicates the start of a comment. The two-hyphen 
    // sequence and any characters that follow it, up to the end of the line on which the sequence occurs, are ignored
    const std::regex comment_regex("^\\s*--.*");
    // keyword: value
    const std::regex directive_regex("^([^:]+):(.+)");
    // id operation operand1 operand2 operand3 -> result conditions
    const std::regex test_regex("^\\s*(\\S+)\\s+(\\S+)\\s+(.+\\s+){1,3}->\\s+(\\S+)\\s*(.*)");
    
    test_context context;

    while (m_is) 
    {
        std::string line;
    
        if (!std::getline(m_is, line)) {
            break;
        }

        if (std::regex_match(line, empty_line_regex)) {
            continue;
        }

        boost::algorithm::trim(line);

        if (std::regex_match(line, comment_regex)) {
            continue;
        }

        std::smatch match;

        if (std::regex_match(line, match, directive_regex)) {
            if (context.apply_directive(match[1].str(), match[2].str())) {
                std::cerr << context << std::endl;
            }
            continue;
        }

        if (std::regex_match(line, match, test_regex)) {
            test test;
            test.id = match[1].str();
            test.operation = match[2].str();
            boost::algorithm::to_lower(test.operation);
            auto operand_string{match[3].str()};
            boost::trim(operand_string);
            boost::split(test.operands, operand_string, boost::is_any_of("\t "), boost::token_compress_on);
            test.expected_result = match[4];
            auto condition_string{match[5].str()};
            boost::trim(condition_string);
            boost::split(test.conditions, condition_string, boost::is_any_of("\t "), boost::token_compress_on);
            try {
                m_results.record(process_test(test));
            }
            catch (std::exception& ex) {
                m_results.record(result::fail);
            }
            continue;
        }


        throw std::runtime_error("Unrecognised line [" + line + "]");
    }
}

result test_file::process_test(const test& test)
{
    if (test.operation == "add") {
        return result::fail;
    }
    
    std::cerr << "skipping: " << test.id << '\n';

    return result::skip;
}




