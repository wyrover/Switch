cmake_minimum_required(VERSION 3.2)

project(SortedDictionaryAdd)
find_package(Pcf REQUIRED)
add_executable(SortedDictionaryAdd SortedDictionaryAdd.cpp)
target_link_libraries(SortedDictionaryAdd Pcf.Core)
