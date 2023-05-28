cmake_minimum_required(VERSION 3.22)

project(PogLang)

add_library(gamer ./src/gamer/gamer.cpp)

add_executable(PogLang main.cpp)

target_link_libraries(PogLang PRIVATE gamer)

add_executable(gamer_testtwo ./test/gamertwo/gamer_testtwo.cpp)
target_link_libraries(gamer_testtwo gamer)

add_executable(gamer_test ./test/gamer/gamer_test.cpp)
target_link_libraries(gamer_test gamer)
# enable testing functionality
enable_testing()

# define tests
add_test(
  NAME gamer_testtwo
  COMMAND $<TARGET_FILE:gamer_testtwo>
)

add_test(
  NAME gamer_test
  COMMAND $<TARGET_FILE:gamer_test>
)

