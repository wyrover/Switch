cmake_minimum_required(VERSION 3.2)

project(TestFixtureMain2)

find_package(Switch REQUIRED)
add_executable(TestFixtureMain2 TestFixtureMain2.cpp)
target_link_libraries(TestFixtureMain2 Switch.TUnit.Core)
