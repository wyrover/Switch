project(Switch.System.Drawing.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.System.Drawing.ManualTests ./Main.cpp)
set_target_properties(Switch.System.Drawing.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.Drawing.ManualTests Switch.System.Drawing)
