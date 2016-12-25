set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(tests_files
./Main.cpp
./ApplicationTest.cpp
./ControlTest.cpp
./CursorUT.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Forms.UnitTests ${tests_files})
set_target_properties(Pcf.Forms.UnitTests PROPERTIES FOLDER Pcf/Forms)
target_link_libraries(Pcf.Forms.UnitTests Pcf.Forms)

