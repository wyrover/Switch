cmake_minimum_required(VERSION 3.5)

project(SomeControls)
find_package(Pcf REQUIRED)
add_executable(SomeControls ${PCF_GUI} SomeControls.cpp)
target_link_libraries(SomeControls Pcf.Forms)
