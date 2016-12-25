set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(tests_files
./Main.cpp
./ApplicationTest.cpp
./ControlTest.cpp
./CursorUT.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.FormsD.UnitTests ${tests_files})
set_target_properties(Pcf.FormsD.UnitTests PROPERTIES FOLDER Pcf/FormsD)
target_link_libraries(Pcf.FormsD.UnitTests Pcf.FormsD)

