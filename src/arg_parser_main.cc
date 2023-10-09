#include "arg_parser.hh"

int main(int argc, char *argv[])
{
  std::string schema = "abc";
  
  std::string argList;
  for (int i = 0; i < argc; ++i) {
    argList.append(std::string(argv[i]) + " ");
  }

  auto args = ArgParse(schema, argList);

  for (auto flag : schema) {
    auto value = args(flag);
    if (value)
      std::cout << flag << " : " << *value << std::endl;
  }

  return 0;
}
