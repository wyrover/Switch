cmake_minimum_required(VERSION 3.2)

project(TestFixture2)

find_package(Switch REQUIRED)
add_executable(TestFixtureWithoutTestHelpers TestFixtureWithoutTestHelpers.cpp)
target_link_libraries(TestFixtureWithoutTestHelpers Switch.TUnit.Framework)
