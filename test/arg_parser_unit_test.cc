#include <gtest/gtest.h>

// Include your header files with the tests to be performed
#include "arg_parser.hh"
#include <string>

// TODO:
// allow making flags optional or required

TEST(ArgParser, ParsesOneArg) { 
  ASSERT_EQ(ArgParse("a", "-a hello")('a'), "hello");
}

TEST(ArgParser, ParsesTwoArgs) { 
  auto args = ArgParse("ab", "-a hello -b there");

  ASSERT_EQ(args('a'), "hello");
  ASSERT_EQ(args('b'), "there");
}

TEST(ArgParser, ReturnsEmptyIfSchemaDoesNotMatchArgList) { 
  ASSERT_EQ(ArgParse("a", "-b 2")('b'), std::nullopt);
}

TEST(ArgParser, ReturnsEmptyIfUnrecognizedFlag) { 
  ASSERT_EQ(ArgParse("a", "-a 2")('b'), std::nullopt);
}

// TODO figure out if I can handle erros with std::oeptional

// TODO roll my own version of std expected for error handling

// TODO assign default values for flags that do not get assigned

// TODO return error if unrecognized flag is provided that doesn't match schema


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
