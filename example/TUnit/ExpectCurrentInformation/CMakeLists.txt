cmake_minimum_required(VERSION 3.2)

project(ExpectCurrentInformation)

find_package(Switch REQUIRED)
add_executable(ExpectCurrentInformation ExpectCurrentInformation.cpp README.md)
target_link_libraries(ExpectCurrentInformation Switch.TUnit.Main)
