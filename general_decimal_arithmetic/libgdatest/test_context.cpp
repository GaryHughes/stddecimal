#include "test_context.hpp"
#include <decimal.hpp>
#include <iostream>
#include <boost/algorithm/string.hpp>

namespace gda
{

int test_context::parse_rounding(const std::string& input)
{
    std::string value{input};
    
    boost::algorithm::trim(value);
    boost::algorithm::to_lower(value);
   
    if (value == "ceiling" || value == "up") {
        return std::decimal::FE_DEC_UPWARD;
    }

    if (value == "down") {
        return std::decimal::FE_DEC_DOWNWARD;
    }

    if (value == "floor") {
        return std::decimal::FE_DEC_TOWARD_ZERO;
    } 
    // if (value == "half_down") {
    //     // return = ;
    // }
    
    if (value == "half_even") {
        return std::decimal::FE_DEC_TONEAREST;
    }

    if (value == "half_up") {
        return std::decimal::FE_DEC_TONEARESTFROMZERO;
    }
    // else if (value == "up") {
    //     return std::decimal::FE_DEC_UPWARD;
    // } 
    // else if (value == "05up") {
    // }

    throw std::runtime_error("unhandled rounding: " + value);
}

int test_context::parse_min_exponent(const std::string& input)
{
    std::string value{input};
    boost::algorithm::trim(value);
    try {
        return std::stoi(value);
    }
    catch (std::exception& ex) {
        throw std::runtime_error("unable to parse minExponent: " + value);        
    }
}

unsigned int test_context::parse_max_exponent(const std::string& input)
{
    std::string value{input};
    boost::algorithm::trim(value);
    try {
        return std::stoi(value);
    }
    catch (std::exception& ex) {
        throw std::runtime_error("unable to parse maxExponent: " + value);        
    }
}

unsigned int test_context::parse_precision(const std::string& input)
{
    std::string value{input};
    boost::algorithm::trim(value);
    try {
        return std::stoi(value);
    }
    catch (std::exception& ex) {
        throw std::runtime_error("unable to parse minExponent: " + value);        
    }
}

bool test_context::parse_clamp(const std::string& input)
{
    std::string value{input};
    boost::algorithm::trim(value);
    try {
        return std::stoi(value) != 0;
    }
    catch (std::exception& ex) {
        throw std::runtime_error("unable to parse clamp: " + value);        
    }
}

bool test_context::apply_directive(const std::string& name, const std::string& value)
{
    auto directive{name};
    boost::algorithm::to_lower(directive);

    if (directive == "dectest") {
        return false;
    }

    if (directive == "version") {
        return false;
    }

    if (directive == "extended") {
        return false;
    }

    if (directive == "precision") {
        m_precision = parse_precision(value);
        return true;
    }

    if (directive == "rounding") {
        m_rounding = parse_rounding(value);
        return true;
    }

    if (directive == "maxexponent") {
        m_max_exponent = parse_max_exponent(value);
        return true;
    }

    if (directive == "minexponent") {
        m_min_exponent = parse_min_exponent(value);
        return true;
    }

    if (directive == "clamp") {
        m_clamp = parse_clamp(value);
        return true;
    }

    throw std::runtime_error("unhandled directive: " + name);
}

const std::optional<int>& test_context::rounding() const
{
    return m_rounding;
}

const std::optional<unsigned int>& test_context::precision() const
{
    return m_precision;
}

const std::optional<int>& test_context::min_exponent() const
{
    return m_min_exponent;
}

const std::optional<unsigned int>& test_context::max_exponent() const
{
    return m_max_exponent;
}

bool test_context::clamp() const
{
    return m_clamp;
}

void test_context::apply_rounding() const
{
    if (!rounding()) {
        return;
    }

    if (std::decimal::fe_dec_setround(*rounding()) != 0) {
        throw std::runtime_error("Error setting rounding mode: " + std::to_string(*rounding()));
    }
}

} // namespace gda

std::ostream& operator<<(std::ostream& os, gda::test_context& context)
{
    os  << "context {\n"
        << "    rounding     : " << (context.rounding() ? std::to_string(*context.rounding()) : "") << '\n'
        << "    precision    : " << (context.precision() ? std::to_string(*context.precision()) : "") << '\n'
        << "    min exponent : " << (context.min_exponent() ? std::to_string(*context.min_exponent()) : "") << '\n'
        << "    max exponent : " << (context.max_exponent() ? std::to_string(*context.max_exponent()) : "") << '\n'
        << "    clamp:       : " << context.clamp() << '\n'
        << "}";
    return os;
}
