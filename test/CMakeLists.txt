project(arg_parser_unit_test)

# Locate and configure the testing framework (Google Test)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files and the main.cpp file
set(SOURCES
    arg_parser_unit_test.cc
)

# Create the test executable
add_executable(arg_parser_unit_test ${SOURCES})

# Link the test executable with Google Test and any other necessary libraries
target_link_libraries(arg_parser_unit_test
${GTEST_BOTH_LIBRARIES}
arg_parser
)

# Enable C++11 for the test executable
target_compile_features(arg_parser_unit_test PRIVATE cxx_std_11)



include(GoogleTest)
gtest_discover_tests(arg_parser_unit_test)
