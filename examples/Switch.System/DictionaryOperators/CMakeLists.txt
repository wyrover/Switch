cmake_minimum_required(VERSION 3.2)

project(DictionaryOperators)
find_package(Switch REQUIRED)
add_executable(DictionaryOperators DictionaryOperators.cpp)
target_link_libraries(DictionaryOperators Switch.System)
