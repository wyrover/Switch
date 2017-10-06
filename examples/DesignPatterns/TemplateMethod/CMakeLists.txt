cmake_minimum_required(VERSION 3.2)

project(TemplateMethod)
find_package(Switch REQUIRED)
add_executable(TemplateMethod TemplateMethod.cpp)
target_link_libraries(TemplateMethod Switch.System)
