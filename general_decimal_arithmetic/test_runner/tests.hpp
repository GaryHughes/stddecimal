#ifndef stddecimal_general_decimal_arithmetic_test_runner_tests_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_tests_hpp

#include <vector>
#include <set>
#include <decimal.hpp>
#include <decimal_cmath.hpp> 
#include "test_results.hpp"

struct test
{
    std::string id;
    std::string operation;
    std::vector<std::string> operands; 
    std::string expected_result;
    std::string expected_conditions_string;
    std::decimal::fexcept_t expected_conditions;

    void validate_operands(size_t required_count) const
    {
        if (operands.size() != required_count) {
            throw std::runtime_error("incorrect number of operands, expected " + std::to_string(required_count) + " got " + std::to_string(operands.size()));
        }
    }
};

struct operation_32bit {
    using decimal_type = std::decimal::decimal32;
};

struct operation_64bit {
    using decimal_type = std::decimal::decimal64;
};

struct operation_128bit {
    using decimal_type = std::decimal::decimal128;
};

template<int bits> struct operation_traits;
template<> struct operation_traits<32>  : public operation_32bit {};
template<> struct operation_traits<64>  : public operation_64bit {};
template<> struct operation_traits<128>  : public operation_128bit {};

template<typename DecimalType>
void report_failure(const test& test, DecimalType expected, DecimalType actual)
{
    std::cerr << "FAILURE " 
              << test.id << " " 
              << test.operation << " ";
    for (const auto& operand : test.operands) {
        std::cerr << operand << " ";
    }
    std::cerr << "-> " << test.expected_result << " " << test.expected_conditions_string;
    // for (const auto& condition : test.conditions) {
    //     std::cerr << condition << " ";
    // }
    std::cerr << " (actual " << actual << ")\n";
}

void report_failure(const test& test, std::decimal::fexcept_t actual) 
{
    std::cerr << "FAILURE " << test.expected_conditions_string << " expected " << test.expected_conditions << " (";
    if (test.expected_conditions & std::decimal::FE_DEC_DIVBYZERO) { std::cerr << "FE_DEC_DIVBYZERO "; } 
    if (test.expected_conditions & std::decimal::FE_DEC_INEXACT) { std::cerr << "FE_DEC_INEXACT "; }
    if (test.expected_conditions & std::decimal::FE_DEC_INVALID) { std::cerr << "FE_DEC_INVALID "; }
    if (test.expected_conditions & std::decimal::FE_DEC_OVERFLOW) { std::cerr << "FE_DEC_OVERFLOW "; }
    if (test.expected_conditions & std::decimal::FE_DEC_UNDERFLOW) { std::cerr << "FE_DEC_UNDERFLOW "; }
    std::cerr << ") actual " << actual << " (";
    if (actual & std::decimal::FE_DEC_DIVBYZERO) { std::cerr << "FE_DEC_DIVBYZERO "; } 
    if (actual & std::decimal::FE_DEC_INEXACT) { std::cerr << "FE_DEC_INEXACT "; }
    if (actual & std::decimal::FE_DEC_INVALID) { std::cerr << "FE_DEC_INVALID "; }
    if (actual & std::decimal::FE_DEC_OVERFLOW) { std::cerr << "FE_DEC_OVERFLOW "; }
    if (actual & std::decimal::FE_DEC_UNDERFLOW) { std::cerr << "FE_DEC_UNDERFLOW "; }
    std::cerr << ")\n";
}

template<typename DecimalType>
result evaluate_result(const test& test, DecimalType expected, DecimalType actual)
{
    if (std::isnan(expected)) {
        if (!std::isnan(actual)) {
            report_failure(test, expected, actual);
            return result::fail;
        }    
    }
    else if (std::isinf(expected)) {
        if (!std::isinf(actual)) {
            report_failure(test, expected, actual);
            return result::fail;
        }
    }
    else if (expected != actual) {
        report_failure(test, expected, actual);
        return result::fail;        
    }

    return result::pass;
}    

template<typename DecimalType>
class add_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = lhs + rhs;
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class subtract_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = lhs - rhs;
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class multiply_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = lhs * rhs;
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class divide_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = lhs / rhs;
        return evaluate_result(test, expected, actual);
    }

};



#endif