project(Switch.Core.ManualTests)

GroupSources(.)

add_executable(Switch.Core.ManualTests Main.cpp)
set_target_properties(Switch.Core.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.Core.ManualTests Switch.Core)
