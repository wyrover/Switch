project(Switch.Core.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

GroupSources(.)

add_executable(Switch.Core.ManualTests ./Main.cpp)
set_target_properties(Switch.Core.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.Core.ManualTests Switch.Core)
