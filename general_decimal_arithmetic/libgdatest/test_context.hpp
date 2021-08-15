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
    bool clamp() const;

    void apply_rounding() const;

private:

    static int parse_rounding(const std::string& input);
    static int parse_min_exponent(const std::string& input);
    static unsigned int parse_max_exponent(const std::string& input);
    static unsigned int parse_precision(const std::string& input);
    static bool parse_clamp(const std::string& input);

    std::optional<int> m_rounding;
    std::optional<unsigned int> m_max_exponent;
    std::optional<int> m_min_exponent;
    std::optional<unsigned int> m_precision;
    bool m_clamp = false;

};

std::ostream& operator<<(std::ostream& os, test_context& context);

#endif


