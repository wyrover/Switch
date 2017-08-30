cmake_minimum_required(VERSION 3.2)

project(Expect)

find_package(Switch REQUIRED)
add_executable(Expect Expect.cpp)
target_link_libraries(Expect Switch.TUnit.Main)
