cmake_minimum_required(VERSION 3.22)

project(PogLang)

add_library(lexer ./src/lexer.cpp)
add_library(token ./src/token.cpp)
add_library(utils ./src/utils.cpp)

add_executable(PogLang pog.cpp)

target_link_libraries(lexer token utils)
target_link_libraries(PogLang lexer token)

# enable testing functionality
#enable_testing()

# define tests
#add_test(
#  NAME gamer_testtwo
#  COMMAND $<TARGET_FILE:gamer_testtwo>
#)
#
#add_test(
#  NAME gamer_test
#  COMMAND $<TARGET_FILE:gamer_test>
#)

