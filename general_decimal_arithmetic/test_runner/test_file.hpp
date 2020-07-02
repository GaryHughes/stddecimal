#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp

#include <string>
#include <vector>
#include <fstream>
#include "test_results.hpp"

struct test
{
    std::string id;
    std::string operation; 
    std::vector<std::string> operands; 
    std::string expected_result;
    std::vector<std::string> conditions;
};

class test_file
{
public:

    test_file(const std::string& filename, test_results& results);

    void process();

private:

    result process_test(const test& test);
   
    std::ifstream m_is;
    test_results& m_results;

};

#endif