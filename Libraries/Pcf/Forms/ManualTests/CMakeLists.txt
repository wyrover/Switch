set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(tests_files
./ButtonMT.cpp
)

source_group(ManualTests REGULAR_EXPRESSION "/ManualTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Forms.ManualTests WIN32 ${tests_files})

target_link_libraries(Pcf.Forms.ManualTests Pcf.Forms)

set_target_properties(Pcf.Forms.ManualTests PROPERTIES FOLDER Pcf/Forms)
