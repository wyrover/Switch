cmake_minimum_required(VERSION 3.2)

project(StringReader)
find_package(Pcf REQUIRED)
add_executable(StringReader StringReader.cpp)
target_link_libraries(StringReader Pcf.Core)
