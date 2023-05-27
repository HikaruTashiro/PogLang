project(PogLang)

add_library(test ./src/teste/test.cpp)

add_executable(PogLang main.cpp)

target_link_libraries(PogLang PRIVATE test)
