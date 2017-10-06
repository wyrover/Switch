cmake_minimum_required(VERSION 3.2)

project(FlagsEnum)
find_package(Switch REQUIRED)
add_executable(FlagsEnum FlagsEnum.cpp)
target_link_libraries(FlagsEnum Switch.System)
