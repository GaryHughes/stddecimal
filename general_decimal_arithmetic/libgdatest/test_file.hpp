#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp

#include <string>
#include <vector>
#include <fstream>
#include "test_context.hpp"
#include "test_line.hpp"
#include "test_results.hpp"
#include "tests.hpp"
#include <iostream>
#include <boost/algorithm/string/trim_all.hpp>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/regex.hpp>
#include <decimal_numeric_limits.hpp>

namespace gda
{

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
        test_context context;

        while (m_is) 
        {
            std::string text;
        
            if (!std::getline(m_is, text)) {
                break;
            }

            try
            {
                test_line line(text);

                if (line.is_blank()) {
                    continue;
                }

                if (line.is_comment()) {
                    continue;
                }

                if (line.is_directive()) {
                    context.apply_directive(line.keyword(), line.value());
                    continue;
                }

                if (line.is_test()) {

                    if (context.clamp()) {
                        m_results.record(result::skip);
                        continue;
                    }

                    test test;
                    test.id = line.id();
                    test.operation = line.operation();
                    test.operands = line.operands();
                    test.expected_result = line.expected_result();
                    test.expected_conditions = line.expected_conditions();

                    using traits = operation_traits<Bits>;
                    using limits = std::decimal::numeric_limits<typename traits::decimal_type>;

                    if (context.precision() > limits::digits) {
                        m_results.record(result::skip);
                        continue;    
                    }

                    try {
                        context.apply_rounding();
                        // std::decimal::clear_exceptions(std::decimal::FE_DEC_ALL_EXCEPT);
                        std::decimal::set_exceptions(std::decimal::FE_DEC_DIVBYZERO | 
                                                    std::decimal::FE_DEC_INEXACT | 
                                                    std::decimal::FE_DEC_INVALID | 
                                                    std::decimal::FE_DEC_OVERFLOW | 
                                                    std::decimal::FE_DEC_UNDERFLOW);
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
                        std::cerr << "GENERIC EXCEPTION " << test.id << " " << ex.what() << std::endl;
                        m_results.record(result::skip);
                    }

                    continue;
                }
            }
            catch (std::exception& ex)
            {
                std::cerr << "failed to parse line: " + text << '\n';
            }   
        }
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

        if (test.operation == "fma") {
            return fma_test<typename traits::decimal_type>::run(test);
        }
      
        // comparetotal0.decTest	
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
        // trim0.decTest

        // std::cerr << "skipping: " << test.id << '\n';

        return result::skip;
    }
   
    std::ifstream m_is;
    test_results& m_results;

};

} // namespace gda

#endif