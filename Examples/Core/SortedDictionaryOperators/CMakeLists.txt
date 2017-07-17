cmake_minimum_required(VERSION 3.2)

project(SortedDictionaryOperators)
find_package(Pcf REQUIRED)
add_executable(SortedDictionaryOperators SortedDictionaryOperators.cpp)
target_link_libraries(SortedDictionaryOperators Pcf.Core)
