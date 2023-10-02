#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>
#include <set>
#include <iostream>
#include <algorithm>

enum class ErrorCodes{
  OK = 0,
  UNRECOGNIZED_FLAG = 1
};

class ArgParser
{
public:
  ArgParser();

  void AddOption(const char flag) {
    schema_.insert(flag);
  }

  std::string EraseWhiteSpace(const std::string& str)
  {
    const char whitespace = ' ';
    std::string strCopy = str;
    strCopy.erase(std::remove(strCopy.begin(), strCopy.end(), whitespace), strCopy.end());
    return strCopy;
  }

    /*
     (1) verify the provided cmd line args do not contain any
       unrecognized flags or minus signs with a char. Either of those
       is an error

     (2) For each flag in schema, find it in the provided arguments
       and save its value. If a required flag is not found, then
       that's an error.
    */

  ErrorCodes Parse(const std::string& cmdLineArgs) {
    // parse the arguments to find expected flags that were set in the
    // schema. Flags always have a minus sign prepended to them
    auto newString = EraseWhiteSpace(cmdLineArgs);

    if (newString.size() < 2)
      return ErrorCodes::UNRECOGNIZED_FLAG;

    // find all flags and verify that no unrecognized flags were
    // passed
    for (int index = 0; index < newString.size()-1; ++index) {
      if (newString[index] == '-'){
	char nextLetter = newString[index+1];
	// if last char was a minus, then this char is the flag
	if (schema_.find(nextLetter) == schema_.end()) {
	  std::cout << "Arg " << nextLetter << " not recognized!" << std::endl;
	  return ErrorCodes::UNRECOGNIZED_FLAG;
	}
      }
    }
    return ErrorCodes::OK;
  }

  bool HasArg(const char flag) {
    return false;
  }

private:

  // schema is a list of expected argument flags. 
  std::set<char> schema_;

};

#endif /* ARG_PARSER_H */
