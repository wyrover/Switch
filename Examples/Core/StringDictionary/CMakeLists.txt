cmake_minimum_required(VERSION 3.2)

project(StringDictionary)
find_package(Pcf REQUIRED)
add_executable(StringDictionary StringDictionary.cpp)
target_link_libraries(StringDictionary Pcf.Core)
