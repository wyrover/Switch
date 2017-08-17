cmake_minimum_required(VERSION 3.2)

project(EnvironmentSetEnvironmentVariable)
find_package(Pcf REQUIRED)
add_executable(EnvironmentSetEnvironmentVariable EnvironmentSetEnvironmentVariable.cpp)
target_link_libraries(EnvironmentSetEnvironmentVariable Pcf.Core)
