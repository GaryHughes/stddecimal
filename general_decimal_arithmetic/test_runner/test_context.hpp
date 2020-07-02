#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_context_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_context_hpp

#include <iosfwd>
#include <string>
#include <optional>

class test_context
{
public:

    bool apply_directive(const std::string& name, const std::string& value);

    const std::optional<int>& rounding() const;
    const std::optional<unsigned int>& precision() const;
    const std::optional<int>& min_exponent() const;
    const std::optional<unsigned int>& max_exponent() const;

private:

    int parse_rounding(const std::string& value) const;
    int parse_min_exponent(const std::string& input) const;
    unsigned int parse_max_exponent(const std::string& input) const;
    unsigned int parse_precision(const std::string& input) const;

    std::optional<int> m_rounding;
    std::optional<unsigned int> m_max_exponent;
    std::optional<int> m_min_exponent;
    std::optional<unsigned int> m_precision;

};

std::ostream& operator<<(std::ostream& os, test_context& context);

#endif


