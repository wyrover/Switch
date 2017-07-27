cmake_minimum_required(VERSION 3.2)

project(FactoryMethod)
find_package(Pcf REQUIRED)
add_executable(FactoryMethod FactoryMethod.cpp)
target_link_libraries(FactoryMethod Pcf.Core)
