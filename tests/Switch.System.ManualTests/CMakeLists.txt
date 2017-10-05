project(Switch.System.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

GRoupSources(.)

add_executable(Switch.System.ManualTests ./Main.cpp)
set_target_properties(Switch.System.ManualTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.ManualTests Switch.System)
