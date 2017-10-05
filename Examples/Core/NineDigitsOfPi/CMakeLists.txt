cmake_minimum_required(VERSION 3.2)

project(NineDigitsOfPi)
find_package(Switch REQUIRED)
add_executable(NineDigitsOfPi NineDigitsOfPi.cpp)
target_link_libraries(NineDigitsOfPi Switch.Core)
