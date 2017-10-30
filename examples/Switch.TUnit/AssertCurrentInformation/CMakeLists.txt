cmake_minimum_required(VERSION 3.2)

project(AssertCurrentInformation)

find_package(Switch REQUIRED)
add_executable(AssertCurrentInformation AssertCurrentInformation.cpp)
target_link_libraries(AssertCurrentInformation Switch.TUnit.Main)
