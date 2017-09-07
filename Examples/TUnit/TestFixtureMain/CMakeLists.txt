cmake_minimum_required(VERSION 3.2)

project(TestFixtureMain)

find_package(Switch REQUIRED)
add_executable(TestFixtureMain TestFixtureMain.cpp README.md)
target_link_libraries(TestFixtureMain Switch.TUnit)
