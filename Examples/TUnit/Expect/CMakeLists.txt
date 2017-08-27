cmake_minimum_required(VERSION 3.2)

project(Expect)

find_package(Pcf REQUIRED)
add_executable(Expect Expect.cpp)
target_link_libraries(Expect Pcf.TUnit.Main)
