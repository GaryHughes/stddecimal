add_definitions(-DBOOST_LOG_DYN_LINK)

add_executable(test_runner
               main.cpp
               )

target_link_libraries(test_runner
                      gdatest
                      decimal
                      Boost::program_options)