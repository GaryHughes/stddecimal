#include <iostream>
#include <vector>
#include <filesystem>
#include <libgen.h>
#include <boost/program_options.hpp>
#include "test_file.hpp"

namespace po = boost::program_options;

static const char* option_help = "help";
static const char* option_files = "files";

using input_file_collection = std::vector<std::string>;

int main(int argc, char**argv)
{
    try
    {
        po::options_description options;
    
        options.add_options()
            (option_help, "display usage")
            (option_files, po::value<input_file_collection>());

        po::positional_options_description positional;
        positional.add(option_files, -1);

        po::variables_map variables;
        po::store(po::command_line_parser(argc, argv).options(options).positional(positional).run(), variables);

        if (variables.count(option_help) || !variables.count(option_files))
        {
            std::cout << "usage: " << basename(const_cast<char*>(argv[0])) << " [--help] [FILE]...\n" 
                      << options << std::endl;
            return 1;
        }

        po::notify(variables);

        test_results results;

        for (const auto& filename : variables[option_files].as<input_file_collection>())
        {
            try
            {
                test_file file(filename, results);
                file.process();
                std::cout << filename << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "ERROR processing file " << filename << " : " << e.what() << std::endl;
            }
        }

        std::cout << "Passed: " << results.passed() << " Failed: " << results.failed() << " Skipped: " << results.skipped() << std::endl;

        return results.failed() > 0;
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;    
        return 1;
    }
}


