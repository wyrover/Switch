cmake_minimum_required(VERSION 3.2)

project(SeveralTestCases)

find_package(Switch REQUIRED)
add_executable(SeveralTestCases SeveralTestCases_TestCase1.cpp SeveralTestCases_TestCase2.cpp SeveralTestCases_TestCase3.cpp)
target_link_libraries(SeveralTestCases Switch.TUnit.Main)
