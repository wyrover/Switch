cmake_minimum_required(VERSION 3.2)

project(SortedDictionaryOperators)
find_package(Switch REQUIRED)
add_executable(SortedDictionaryOperators SortedDictionaryOperators.cpp)
target_link_libraries(SortedDictionaryOperators Switch.System)
