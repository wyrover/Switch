cmake_minimum_required(VERSION 3.2)

project(HelloWorldTest)

find_package(Pcf REQUIRED)
add_executable(HelloWorldTest HelloWorldTest.cpp)
target_link_libraries(HelloWorldTest Pcf.TUnit.Main)
