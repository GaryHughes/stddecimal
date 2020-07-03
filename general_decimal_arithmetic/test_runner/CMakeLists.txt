set(BOOST_VERSION_REQUIRED 1.72)

add_definitions(-DBOOST_LOG_DYN_LINK)

find_package(Boost ${BOOST_VERSION_REQUIRED} EXACT
    COMPONENTS 
    program_options
    REQUIRED
)

include_directories(
    "/usr/local/include"
    "${CMAKE_SOURCE_DIR}/libdecimal"
)

link_directories(
    ${Boost_LIBRARY_DIRS}
)

if(APPLE)

    set(BOOST_LIBS
        libboost_program_options-mt.dylib
    )

else()

    set(BOOST_LIBS
        libboost_program_options.so
    )
        
endif()

add_executable(test_runner
               main.cpp
               test_file.hpp
               test_context.hpp test_context.cpp
               test_results.hpp)

target_link_libraries(test_runner
                      decimal
                      ${BOOST_LIBS})