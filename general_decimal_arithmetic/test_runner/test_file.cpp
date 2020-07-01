#include "test_file.hpp"
#include <fstream>
#include <regex>
#include <iostream>
#include <boost/algorithm/string/trim_all.hpp>

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
    const std::regex test_regex("^\\s*(\\S+)\\s+(\\S+)\\s+((\\S+)\\s+){1,3}->\\s+(\\S+)\\s*(.*)");
    
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
            std::cout << "DIRECTIVE " << match[1].str() << " : " << match[2].str() << std::endl;
            continue;
        }

        if (std::regex_match(line, match, test_regex)) {
            std::cout << "TEST " << match[1].str() << " " << match[2].str() << std::endl;
            continue;
        }


        std::cout << "UNKNOWN [" << line << "]" << std::endl;
    }
}


