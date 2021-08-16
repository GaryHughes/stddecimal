#include <iostream>
#include <vector>
#include <filesystem>
#include <libgen.h>
#include <boost/program_options.hpp>
#include <test_file.hpp>

namespace po = boost::program_options;

static const char * const option_help = "help";
static const char * const option_bits = "bits";
static const char * const option_files = "files";

using input_file_collection = std::vector<std::string>;

std::string tidy_filename(const std::string& filename)
{
    const std::string suffix = ".decTest";
    auto suffix_pos = filename.find(suffix);
    return filename.substr(0, suffix_pos);
}

int main(int argc, char**argv)
{
    try
    {
        po::options_description options;

        unsigned int bits = 0;
    
        options.add_options()
            (option_help, "display usage")
            (option_bits, po::value<unsigned int>(&bits)->required(), "the decimal width to test 32|64|128")
            (option_files, po::value<input_file_collection>());

        po::positional_options_description positional;
        positional.add(option_files, -1);

        po::variables_map variables;
        po::store(po::command_line_parser(argc, argv).options(options).positional(positional).run(), variables);
       
        po::notify(variables);

        if (variables.count(option_help) != 0U || 
            variables.count(option_files) == 0U ||
            (bits != 32 && bits != 64 && bits != 128))
        {
            std::cout << "usage: " << basename(static_cast<char*>(*argv)) << " [--help] --bits 32|64|128 FILE...\n" 
                      << options << std::endl;
            return 1;
        }

        gda::test_results total_results;

        for (const auto& filename : variables[option_files].as<input_file_collection>())
        {
            gda::test_results file_results;
    
            try
            {
                if (bits == 32) {
                    gda::test_file<32> file(filename, file_results);
                    file.process();
                }
                else if (bits == 64) {
                    gda::test_file<64> file(filename, file_results);
                    file.process();
                }
                else if (bits == 128) {
                    gda::test_file<128> file(filename, file_results);
                    file.process();
                }

                //std::cerr << filename << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cerr << "ERROR processing file " << filename << " : " << e.what() << std::endl;
            }

            std::cout << "decimal" << bits << "|" << tidy_filename(basename(const_cast<char*>(filename.c_str()))) << "|" << file_results.passed() << "|" << file_results.failed() << "|" << file_results.skipped() << "|" << std::endl;
        
            total_results.record(file_results);
        }

        // |decimal32| |0|0|0|
        std::cout << "decimal" << bits << "| |" << total_results.passed() << "|" << total_results.failed() << "|" << total_results.skipped() << "|" << std::endl;
    }
    catch (std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;    
        return 1;
    }

    return 0;
}


