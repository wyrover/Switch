cmake_minimum_required(VERSION 3.5)

project(DictionaryOperators)
find_package(Pcf REQUIRED)
add_executable(DictionaryOperators DictionaryOperators.cpp)
target_link_libraries(DictionaryOperators Pcf.Core)
