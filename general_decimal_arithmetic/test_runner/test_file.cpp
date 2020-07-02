#include "test_file.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/split.hpp>
#include "test_context.hpp"

void test_file::process(const std::string& filename)
{
    std::ifstream is(filename);

    if (!is) {
        throw std::runtime_error("Unable to open test file '" + filename + "'");
    }

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

    while (is) 
    {
        std::string line;
    
        if (!std::getline(is, line)) {
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
                std::cout << context << std::endl;
            }
            continue;
        }

        if (std::regex_match(line, match, test_regex)) {
            auto id = match[1].str();
            auto operation = match[2].str();
            std::vector<std::string> operands;
            auto operand_string{match[3].str()};
            boost::trim(operand_string);
            boost::split(operands, operand_string, boost::is_any_of("\t "), boost::token_compress_on);
            auto result = match[4];
            std::vector<std::string> conditions;
            auto condition_string{match[5].str()};
            boost::trim(condition_string);
            boost::split(conditions, condition_string, boost::is_any_of("\t "), boost::token_compress_on);
            process_test(id, operation, operands, result, conditions);
            continue;
        }


        throw std::runtime_error("Unrecognised line [" + line + "]");
    }
}

void test_file::process_test(const std::string& id,
                             const std::string& operation, 
                             const std::vector<std::string>& operands, 
                             const std::string& result, 
                             const std::vector<std::string>& conditions)
{
    // std::cout << "TEST " << id << " " << operation << " OP " << operands.size() << " -> " << result << " COND " << conditions.size() << std::endl;
    // for (const auto& operand : operands) {
    //     std::cout << "  " << operand << '\n';
    // }



}


