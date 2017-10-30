project(Switch.System.ManualTests)

GRoupSources(.)

add_executable(Switch.System.ManualTests Main.cpp)
set_target_properties(Switch.System.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.ManualTests Switch.System)
