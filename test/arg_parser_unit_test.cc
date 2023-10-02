#include <gtest/gtest.h>

// Include your header files with the tests to be performed
#include "arg_parser.hh"
#include <string>

// TODO:
// allow making flags optional or required

TEST(ArgParser, ReturnsErrorIfFlagIsNotRecognized) { 
  ArgParser argParse;
  std::string cmdLineArgs = "-i 12";
  // TODO: rewrite error handling to use std::optional instead of
  // return enum
  ASSERT_EQ(argParse.Parse(cmdLineArgs), ErrorCodes::UNRECOGNIZED_FLAG);
}

TEST(ArgParser, ReturnsErrorIfFlagMissing) { 
  ArgParser argParse;
  std::string cmdLineArgs = "- ";
  ASSERT_EQ(argParse.Parse(cmdLineArgs), ErrorCodes::UNRECOGNIZED_FLAG);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
