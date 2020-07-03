#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp

#include <string>
#include <vector>
#include <fstream>
#include "test_results.hpp"
#include "tests.hpp"
#include <regex>
#include <iostream>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include "test_context.hpp"

template<int Bits>
class test_file
{
public:

    test_file(const std::string& filename, test_results& results)
    :   m_is(filename),
        m_results(results)
    {
        if (!m_is) {
            throw std::runtime_error("Unable to open test file '" + filename + "'");
        }
    }

    void process()
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

                if (context.clamp()) {
                    m_results.record(result::skip);
                    continue;
                }

                test test;
                test.id = match[1].str();
                test.operation = match[2].str();
                boost::algorithm::to_lower(test.operation);
                auto operand_string{match[3].str()};
                boost::trim(operand_string);
                boost::split(test.operands, operand_string, boost::is_any_of("\t "), boost::token_compress_on);
                test.expected_result = match[4];
                test.expected_conditions_string = match[5].str();
                boost::trim(test.expected_conditions_string);
                boost::algorithm::to_lower(test.expected_conditions_string);
                test.expected_conditions = parse_conditions(test.expected_conditions_string);
                try {
                    context.apply_rounding();
                    std::decimal::set_exceptions(std::decimal::FE_DEC_ALL_EXCEPT);
                    m_results.record(process_test(test));
                }
                catch (std::decimal::exception& ex) {
                    if (ex.flags() != test.expected_conditions) {
                        report_failure(test, ex.flags());
                        m_results.record(result::fail);
                    }
                    else {
                        m_results.record(result::pass);
                    }
                }
                catch (std::exception& ex) {
                    m_results.record(result::fail);
                }
                continue;
            }


            throw std::runtime_error("Unrecognised line [" + line + "]");
        }
    }

    std::decimal::fexcept_t parse_conditions(const std::string& condition_string)
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

private:

    result process_test(const test& test)
    {
        using traits = operation_traits<Bits>;

        if (test.operation == "add") {
            return add_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "subtract") {
            return subtract_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "divide") {
            return divide_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "multiply") {
            return multiply_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "squareroot") {
            return square_root_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "abs") {
            return abs_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "plus") {
            return plus_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "minus") {
            return minus_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "power") {
            return power_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "quantize") {
            return quantize_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "log10") {
            return log10_test<typename traits::decimal_type>::run(test);
        }

        // comparetotal0.decTest	
        // fma0.decTest		
        // max0.decTest		
        // randoms0.decTest	
        // rescale0.decTest	
        // inexact0.decTest	
        // min0.decTest		
        // reduce0.decTest		
        // rounding0.decTest	
        // testall0.decTest
        // base0.decTest		
        // divideint0.decTest	
        // ln0.decTest		
        // remainder0.decTest	
        // samequantum0.decTest	
        // tointegral0.decTest
        // compare0.decTest	
        // exp0.decTest		
        // randombound320.decTest	
        // remaindernear0.decTest	
        // squareroot0.decTest	
        // trim0.decTest

        std::cerr << "skipping: " << test.id << '\n';

        return result::skip;
    }
   
    std::ifstream m_is;
    test_results& m_results;

};

#endif