#ifndef stddecimal_general_decimal_arithmetic_test_runner_tests_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_tests_hpp

#include <vector>
#include <set>
#include <decimal.hpp>
#include <decimal_cmath.hpp> 
#include "test_results.hpp"

namespace gda
{

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
    std::cerr << "RESULT FAILURE " 
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
    std::cerr << "EXCEPT FAILURE " << test.id << " " << test.operation << " " << test.expected_conditions_string << " expected " << test.expected_conditions << " (";
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

template<>
result evaluate_result(const test& test, bool expected, bool actual)
{
    if (expected != actual) {
        report_failure(test, expected, actual);
        return result::fail;        
    }

    return result::pass;
}

template<>
result evaluate_result(const test& test, int expected, int actual)
{
    if (expected != actual) {
        report_failure(test, expected, actual);
        return result::fail;        
    }

    return result::pass;
}

template<typename DecimalType>
class compare_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        // "compare" returns a decimal value (-1/0/1), not a native int, and propagates NaN (per
        // IEEE-754 compare-and-signal semantics) rather than ordering it - lhs/rhs's own
        // relational operators are unordered for NaN, so that case needs handling separately.
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        DecimalType actual;
        if (std::isnan(lhs)) {
            actual = lhs;
        }
        else if (std::isnan(rhs)) {
            actual = rhs;
        }
        else {
            actual = lhs < rhs ? DecimalType(-1) : (lhs > rhs ? DecimalType(1) : DecimalType(0));
        }
        return evaluate_result(test, expected, actual);
    }

};

// Unlike "compare", totalOrder is defined for every representable value including NaN, so there's
// no unordered case to special-case - but it's a boolean predicate ("is x <= y in total order"),
// not a three-way comparator, so the -1/0/1 result still needs composing from two calls.
template<typename DecimalType>
class comparetotal_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<int>(test.expected_result);
        int actual;
        if (std::decimal::total_order(lhs, rhs) && std::decimal::total_order(rhs, lhs)) {
            actual = 0;
        }
        else if (std::decimal::total_order(lhs, rhs)) {
            actual = -1;
        }
        else {
            actual = 1;
        }
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class comparetotmag_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto lhs = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto rhs = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<int>(test.expected_result);
        int actual;
        if (std::decimal::total_order_mag(lhs, rhs) && std::decimal::total_order_mag(rhs, lhs)) {
            actual = 0;
        }
        else if (std::decimal::total_order_mag(lhs, rhs)) {
            actual = -1;
        }
        else {
            actual = 1;
        }
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class tointegral_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = std::decimal::to_integral(x);
        return evaluate_result(test, expected, actual);
    }

};

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

template<typename DecimalType>
class square_root_test;

template<>
class square_root_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = sqrtd32(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class square_root_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = sqrtd64(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class square_root_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = sqrtd128(x);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class abs_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = std::decimal::abs(x);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class plus_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = +x;
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class minus_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = -x;
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class power_test;

template<>
class power_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::powd32(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class power_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::powd64(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class power_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::powd128(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class quantize_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto y = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<DecimalType>(test.expected_result);
        auto actual = std::decimal::quantize(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class samequantum_test
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<DecimalType>(test.operands[0]);
        auto y = boost::lexical_cast<DecimalType>(test.operands[1]);
        auto expected = boost::lexical_cast<bool>(test.expected_result);
        auto actual = std::decimal::samequantum(x, y);
        return evaluate_result(test, expected, actual);
    }

};

// "rescale x n" sets x's exponent to the integer n - exactly what quantize(x, y) already does
// when y has exponent n, so this reuses quantize rather than needing a new library primitive.
template<typename DecimalType>
class rescale_test;

template<>
class rescale_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto n = boost::lexical_cast<int>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        // make_decimal32(1, n) is arithmetic (coeff * 10^n via repeated multiplication), which
        // gets renormalized to whatever exponent the underlying multiply naturally produces, not
        // necessarily n itself. Parsing "1En" from a string preserves the exact requested
        // exponent, which quantize needs to target.
        auto target = boost::lexical_cast<std::decimal::decimal32>("1E" + std::to_string(n));
        auto actual = std::decimal::quantize(x, target);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class rescale_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto n = boost::lexical_cast<int>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto target = boost::lexical_cast<std::decimal::decimal64>("1E" + std::to_string(n));
        auto actual = std::decimal::quantize(x, target);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class rescale_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto n = boost::lexical_cast<int>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto target = boost::lexical_cast<std::decimal::decimal128>("1E" + std::to_string(n));
        auto actual = std::decimal::quantize(x, target);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class log_test;

template<>
class log_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::logd32(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class log_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::logd64(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class log_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::logd128(x);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class log10_test;

template<>
class log10_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::log10d32(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class log10_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::log10d64(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class log10_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::log10d128(x);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class fma_test;

template<>
class fma_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(3);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto z = boost::lexical_cast<std::decimal::decimal32>(test.operands[2]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::fmad32(x, y, z);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class fma_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(3);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto z = boost::lexical_cast<std::decimal::decimal64>(test.operands[2]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::fmad64(x, y, z);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class fma_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(3);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto z = boost::lexical_cast<std::decimal::decimal128>(test.operands[2]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::fmad128(x, y, z);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class min_test;

template<>
class min_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::fmind32(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class min_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::fmind64(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class min_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::fmind128(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class max_test;

template<>
class max_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::fmaxd32(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class max_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::fmaxd64(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class max_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::fmaxd128(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class remainder_test;

template<>
class remainder_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        // The General Decimal Arithmetic "remainder" operation uses truncated-quotient
        // semantics (like fmod), not IEEE-754 round-to-nearest (see "remainderNear" for that).
        auto actual = std::decimal::fmodd32(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class remainder_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::fmodd64(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class remainder_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::fmodd128(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class remainder_near_test;

template<>
class remainder_near_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal32>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::remainderd32(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class remainder_near_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal64>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::remainderd64(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class remainder_near_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(2);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto y = boost::lexical_cast<std::decimal::decimal128>(test.operands[1]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::remainderd128(x, y);
        return evaluate_result(test, expected, actual);
    }

};

template<typename DecimalType>
class exp_test;

template<>
class exp_test<std::decimal::decimal32>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal32>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal32>(test.expected_result);
        auto actual = std::decimal::expd32(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class exp_test<std::decimal::decimal64>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal64>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal64>(test.expected_result);
        auto actual = std::decimal::expd64(x);
        return evaluate_result(test, expected, actual);
    }

};

template<>
class exp_test<std::decimal::decimal128>
{
public:

    static result run(const test& test)
    {
        test.validate_operands(1);
        auto x = boost::lexical_cast<std::decimal::decimal128>(test.operands[0]);
        auto expected = boost::lexical_cast<std::decimal::decimal128>(test.expected_result);
        auto actual = std::decimal::expd128(x);
        return evaluate_result(test, expected, actual);
    }

};

} // namespace gda

#endif