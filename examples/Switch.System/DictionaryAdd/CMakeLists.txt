cmake_minimum_required(VERSION 3.2)

project(DictionaryAdd)
find_package(Switch REQUIRED)
add_executable(DictionaryAdd DictionaryAdd.cpp)
target_link_libraries(DictionaryAdd Switch.System)
