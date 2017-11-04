cmake_minimum_required(VERSION 3.2)

project(TestFixture3)

find_package(Switch REQUIRED)
add_executable(TestFixture3 TestFixture3.cpp)
target_link_libraries(TestFixture3 Switch.TUnit.Framework)
