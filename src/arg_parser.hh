#ifndef ARG_PARSER_H
#define ARG_PARSER_H

#include <string>
#include <sstream>
#include <set>
#include <iostream>
#include <algorithm>
#include <optional>
#include <functional>
#include <map>
#include <vector>

void split(const std::string &s, char delim, std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}


bool ValidateString(const std::string& newString, const std::string schema) {
  if (newString.size() < 2)
    return false;

  // find all flags and verify that no unrecognized flags were
  // passed
  for (int index = 0; index < newString.size()-1; ++index) {
    if (newString[index] == '-'){
      char nextLetter = newString[index+1];
      // if last char was a minus, then this char is the flag
      if (schema.find(nextLetter) == std::string::npos) {
	std::cout << "Arg " << nextLetter << " not recognized!" << std::endl;
	return false;
      }
    }
  }
  return true;
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

std::optional<std::string> Parse(std::map<char, std::string> flagsMap, char query) {
  if (flagsMap.find(query) == flagsMap.end())
    return std::nullopt;

  // for each element in schema, find the arg in args list. If it
  // exists, then store it in a map
  return flagsMap[query];
}

std::map<char, std::string> FindArgThatMatchesFlagInSchema(const char flag,
							   const std::vector<std::string>& argWords,
							   const std::map<char, std::string>& flagsMap ) {

  std::map<char, std::string> flagsMapCopy = flagsMap;

  std::string minus = "-";
  std::string query = minus.append(1, flag); // -a
    
  for (int w = 0; w < argWords.size(); ++w) {
    std::string word = argWords[w];
    if (word == query)
      flagsMapCopy[flag] = argWords[w+1];
  }
  return flagsMapCopy;
}

auto ArgParse(std::string schema, std::string args)
{
  std::map<char, std::string> flagsMap;

  const char whitespace = ' ';
  std::vector<std::string> argWords = split(args,whitespace);
  
  for (auto flag : schema) {
    flagsMap = FindArgThatMatchesFlagInSchema(flag, argWords, flagsMap);   }

  // for each element in the args list, check if it exists in the
  // scehma. If not, return return error.
  // if (!ValidateString(argsNoSpace, schema))
  //   return false;


  return [flagsMap](char query ) {
    return Parse(flagsMap, query);
  };
}

#endif /* ARG_PARSER_H */
