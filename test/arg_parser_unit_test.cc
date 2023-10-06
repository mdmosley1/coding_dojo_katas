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

// TEST(ArgParser, ReturnsEmptyIfUnrecognizedFlag) { 
//   ASSERT_EQ(ArgParse("a", "-b 2"), std::function);
// }

/*
  Alternatively try an interface like this:


  std::map<char, T> ParseArgs(const std::string& schema, const std::string& args);

  Use like this:
  cmdArgs = "-i 12 -g -b red"
  schema = "i:gb:" // like get opt

  auto parsedArgs = ParsedArgs(schema, cmdArgs);

  use std::optional to make the return value empty if there was an
  error parsing arguments.

  With function currying, we could do something like:

  auto lambda = ParseArgs("i:", "-i 12");
  auto result = lambda("i") // 12

  OR even more simply as:

  auto result = ParseArgs("i:", "-i 12")("i"); // 12

  in case of failure, ParseArgs would return an empty lambda or
  std::function
 */ 

// TEST(ArgParser, ReturnsErrorIfFlagMissing) {
//   ArgParser argParse;
//   std::string cmdLineArgs = "- ";
//   ASSERT_EQ(argParse.Parse(cmdLineArgs).status, ErrorCodes::UNRECOGNIZED_FLAG);
// }

// TEST(ArgParser, ParsesOneFlag) {
//   ArgParser argParse;
//   std::string cmdLineArgs = "-i 12";

//   argParse.AddOption('i');
//   auto args = argParse.Parse(cmdLineArgs);

//   ASSERT_EQ(args.status, ErrorCodes::OK);

//   ASSERT_EQ(args.Get('i'), 12);
  

//   // if args.status == ErrorCodes::UNRECOGNIZED_FLAG, then flags were
//   // bad
//   ASSERT_EQ(argParse.Parse(cmdLineArgs).status, ErrorCodes::UNRECOGNIZED_FLAG);

  
  

//   //ASSERT_EQ(argParse.Parse(cmdLineArgs), ErrorCodes::UNRECOGNIZED_FLAG);
// }

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
