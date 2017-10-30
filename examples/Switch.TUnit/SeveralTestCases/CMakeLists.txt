cmake_minimum_required(VERSION 3.2)

project(SeveralTestCases)

find_package(Switch REQUIRED)
add_executable(SeveralTestCases SeveralTestCases.cpp)
target_link_libraries(SeveralTestCases Switch.TUnit.Main)
