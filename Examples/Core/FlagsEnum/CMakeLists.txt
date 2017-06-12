cmake_minimum_required(VERSION 3.5)

project(FlagsEnum)
find_package(Pcf REQUIRED)
add_executable(FlagsEnum FlagsEnum.cpp)
target_link_libraries(FlagsEnum Pcf.Core)
