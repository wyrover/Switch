cmake_minimum_required(VERSION 3.2)

project(EnvironmentGetCommandLineArgs)
find_package(Pcf REQUIRED)
add_executable(EnvironmentGetCommandLineArgs EnvironmentGetCommandLineArgs.cpp)
target_link_libraries(EnvironmentGetCommandLineArgs Pcf.Core)
