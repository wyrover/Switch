cmake_minimum_required(VERSION 3.2)

project(ListExists)
find_package(Pcf REQUIRED)
add_executable(ListExists ListExists.cpp)
target_link_libraries(ListExists Pcf.Core)
