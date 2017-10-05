project(Switch.Core.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.Core.ManualTests ./Main.cpp)
set_target_properties(Switch.Core.ManualTests PROPERTIES FOLDER sources/Core)
target_link_libraries(Switch.Core.ManualTests Switch.Core)
