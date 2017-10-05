cmake_minimum_required(VERSION 3.2)

project(Delegate)
find_package(Switch REQUIRED)
add_executable(Delegate Delegate.cpp)
target_link_libraries(Delegate Switch.Core)
