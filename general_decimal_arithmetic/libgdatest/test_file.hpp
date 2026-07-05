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

                    test test;
                    test.id = line.id();
                    test.operation = line.operation();
                    test.operands = line.operands();
                    test.expected_result = line.expected_result();
                    test.expected_conditions = line.expected_conditions();

                    using traits = operation_traits<Bits>;
                    using limits = std::decimal::numeric_limits<typename traits::decimal_type>;

                    // if (context.precision() > limits::digits) {
                    //     std::cerr << "skipping due to precision " << *context.precision() << " v " << limits::digits << "\n"; 
                    //     m_results.record(result::skip);
                    //     continue;    
                    // }

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

                std::cerr << "failed to process line: " << text << '\n';
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

        if (test.operation == "min") {
            return min_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "max") {
            return max_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "remainder") {
            return remainder_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "remaindernear" || test.operation == "remainderNear") {
            return remainder_near_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "exp") {
            return exp_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "ln") {
            return log_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "samequantum") {
            return samequantum_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "compare") {
            return compare_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "comparetotal") {
            return comparetotal_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "comparetotmag") {
            return comparetotmag_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "rescale") {
            return rescale_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "tointegral") {
            return tointegral_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "toSci" || test.operation == "tosci") {
            return to_sci_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "toEng") {
            return to_eng_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "reduce") {
            return reduce_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "trim") {
            return trim_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "divideint") {
            return divideint_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "copy") {
            return copy_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "copyabs") {
            return copyabs_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "copynegate") {
            return copynegate_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "copysign") {
            return copysign_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "class") {
            return class_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "maxmag") {
            return maxmag_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "minmag") {
            return minmag_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "nextplus") {
            return nextplus_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "nextminus") {
            return nextminus_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "nexttoward") {
            return nexttoward_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "logb") {
            return logb_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "tointegralx") {
            return tointegralx_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "comparesig") {
            return comparesig_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "scaleb") {
            return scaleb_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "and") {
            return and_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "or") {
            return or_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "xor") {
            return xor_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "invert") {
            return invert_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "rotate") {
            return rotate_test<typename traits::decimal_type>::run(test);
        }

        if (test.operation == "shift") {
            return shift_test<typename traits::decimal_type>::run(test);
        }

        // randoms0.decTest
        // inexact0.decTest
        // testall0.decTest

        std::cerr << "skipping: " << test.id << '\n';

        return result::skip;
    }
   
    std::ifstream m_is;
    test_results& m_results;

};

} // namespace gda

#endif