project(Pcf.Core.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Core.ManualTests ./Main.cpp)
set_target_properties(Pcf.Core.ManualTests PROPERTIES FOLDER Pcf/Core)
target_link_libraries(Pcf.Core.ManualTests Pcf.Core)
