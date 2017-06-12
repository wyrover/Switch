cmake_minimum_required(VERSION 3.5)

project(DirectorySeparatorChar)
find_package(Pcf REQUIRED)
add_executable(DirectorySeparatorChar DirectorySeparatorChar.cpp)
target_link_libraries(DirectorySeparatorChar Pcf.Core)
