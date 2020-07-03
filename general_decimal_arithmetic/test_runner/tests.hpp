#ifndef stddecimal_general_decimal_arithmetic_test_runner_tests_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_tests_hpp

#include <vector>
#include <string>
#include <decimal.hpp>
#include "test_results.hpp"

struct test
{
    std::string id;
    std::string operation; 
    std::vector<std::string> operands; 
    std::string expected_result;
    std::vector<std::string> conditions;

    void validate_operands(size_t required_count) const
    {
        if (operands.size() != 2) {
            throw std::runtime_error("incorrect number of operands, expected 2 got " + std::to_string(operands.size()));
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
        if (expected == actual) {
            return result::pass;
        }
        std::cerr << "FAIL " << lhs << " + " << rhs << " = " << actual << " (expected " << expected << ")" << std::endl;
        return result::fail;        
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
        if (expected == actual) {
            return result::pass;
        }
        return result::fail;        
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
        if (expected == actual) {
            return result::pass;
        }
        return result::fail;        
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
        if (expected == actual) {
            return result::pass;
        }
        return result::fail;        
    }

};



#endif