cmake_minimum_required(VERSION 3.2)

project(TrackBar)
find_package(Switch REQUIRED)
add_executable(TrackBar ${SWITCH_GUI} TrackBar.cpp)
target_link_libraries(TrackBar Switch.System.Windows.Forms)
