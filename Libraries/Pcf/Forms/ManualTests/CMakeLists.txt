project(Pcf.Forms.ManualTests)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

source_group(ManualTests REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Forms.ManualTests ./Main.cpp)
set_target_properties(Pcf.Forms.ManualTests PROPERTIES FOLDER Pcf/Forms)
target_link_libraries(Pcf.Forms.ManualTests Pcf.Forms)
