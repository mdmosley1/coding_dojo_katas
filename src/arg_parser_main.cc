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
    if (args(flag) != "")
      std::cout << flag << " : " << args(flag) << std::endl;
  }

  return 0;
}
