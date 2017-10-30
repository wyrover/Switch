project(Switch.TUnit.ManualTests)

GroupSources(.)

add_executable(Switch.TUnit.ManualTests Main.cpp)
set_target_properties(Switch.TUnit.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.TUnit.ManualTests Switch.TUnit.Core)
