cmake_minimum_required(VERSION 3.2)

project(TestFixture2)

find_package(Switch REQUIRED)
add_executable(TestFixture2 TestFixture2.cpp)
target_link_libraries(TestFixture2 Switch.TUnit.Framework)
