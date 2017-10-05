project(Switch.System.Windows.Forms.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

GroupSources(.)

add_executable(Switch.System.Windows.Forms.ManualTests ${SWITCH_GUI} Main.cpp)
set_target_properties(Switch.System.Windows.Forms.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.Windows.Forms.ManualTests Switch.System.Windows.Forms)
