set(BOOST_VERSION_REQUIRED 1.90)

add_definitions(-DBOOST_LOG_DYN_LINK)

find_package(Boost ${BOOST_VERSION_REQUIRED} EXACT
    COMPONENTS 
    program_options
    regex
    REQUIRED
)

if(APPLE)

    set(BOOST_LIBS
        libboost_program_options-mt.dylib
        libboost_refex-mt.dylib
    )

else()

    set(BOOST_LIBS
        libboost_program_options.so
        libboost_regex.so
    )
        
endif()

add_executable(test_runner
               main.cpp
               )

target_link_libraries(test_runner
                      gdatest
                      decimal
                      ${BOOST_LIBS})