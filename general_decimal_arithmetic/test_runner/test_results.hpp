#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_results_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_results_hpp

#include <cstddef>

enum class result
{
    pass,
    fail,
    skip
};

class test_results
{
public:

    void record(result r) {
        switch (r) {
            case result::pass:
                m_passed++;
                break;
            case result::fail:
                m_failed++;
                break;
            case result::skip:
                m_skipped++;
                break;
        }
    }

    size_t passed() const { return m_passed; }
    size_t failed() const { return m_failed; }
    size_t skipped() const { return m_skipped; }

private:

    size_t m_passed = 0;
    size_t m_failed = 0;
    size_t m_skipped = 0;

};

#endif