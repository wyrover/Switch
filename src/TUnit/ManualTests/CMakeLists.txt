project(Switch.TUnit.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.TUnit.ManualTests ./Main.cpp)
set_target_properties(Switch.TUnit.ManualTests PROPERTIES FOLDER src/TUnit)
target_link_libraries(Switch.TUnit.ManualTests Switch.TUnit)
