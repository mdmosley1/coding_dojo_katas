
add_library(arg_parser SHARED
arg_parser.cc)
target_include_directories(arg_parser PUBLIC ./)


add_executable (arg_parser_main arg_parser_main.cc )
target_link_libraries(arg_parser_main arg_parser)

