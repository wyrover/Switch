project(Switch.System.Windows.Forms.ManualTests)

GroupSources(.)

add_executable(Switch.System.Windows.Forms.ManualTests ${SWITCH_GUI} Main.cpp)
set_target_properties(Switch.System.Windows.Forms.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.Windows.Forms.ManualTests Switch.System.Windows.Forms)
