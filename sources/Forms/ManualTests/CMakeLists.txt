project(Switch.Forms.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.Forms.ManualTests ${SWITCH_GUI} Main.cpp)
set_target_properties(Switch.Forms.ManualTests PROPERTIES FOLDER sources/Forms)
target_link_libraries(Switch.Forms.ManualTests Switch.Forms)
