cmake_minimum_required(VERSION 3.2)

project(TemplateMethod)
find_package(Pcf REQUIRED)
add_executable(TemplateMethod TemplateMethod.cpp)
target_link_libraries(TemplateMethod Pcf.Core)
