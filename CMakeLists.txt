cmake_minimum_required(VERSION 3.19)
project(Pyler)

set(CMAKE_CXX_STANDARD 20)

#find_package(FLEX)
#flex_target(Lexer lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp-tmp)

add_executable(Pyler main.cpp ${FLEX_lexer_OUTPUTS} lexer.h lexer.cpp tokens.h utils.h keywords.h parser.h)
#target_link_libraries(Pyler ${FLEX_LIBRARIES})