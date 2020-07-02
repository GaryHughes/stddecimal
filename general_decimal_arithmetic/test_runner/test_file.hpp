#ifndef stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp
#define stddecimal_general_decimal_arithmetic_test_runner_test_file_hpp

#include <string>
#include <vector>

class test_file
{
public:

    void process(const std::string& filename);

private:

    void process_test(const std::string& id,
                      const std::string& operation, 
                      const std::vector<std::string>& operands, 
                      const std::string& result, 
                      const std::vector<std::string>& conditions);


};

#endif