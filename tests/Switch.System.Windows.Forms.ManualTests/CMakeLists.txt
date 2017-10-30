project(Switch.System.Windows.Forms.ManualTests)
add_executable(${PROJECT_NAME} ${SWITCH_GUI} Main.cpp)
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER tests)
target_link_libraries(${PROJECT_NAME} Switch.System.Windows.Forms)
