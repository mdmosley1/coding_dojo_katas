#include <gtest/gtest.h>

// Include your header files with the tests to be performed
#include "arg_parser.hh"

TEST(ArgParser, ParsesOneArgument) { 
  ArgParser arg;
  ASSERT_EQ(1+1,2);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
