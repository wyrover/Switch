project(Switch.Core.ManualTests)
add_executable(${PROJECT_NAME} Main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER tests)
target_link_libraries(${PROJECT_NAME} Switch.Core)
