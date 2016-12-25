set(tests_files
./ColorTest.cpp
./Main.cpp
./PointTest.cpp
./RectangleTest.cpp
./SizeTest.cpp
./SystemColorsTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Drawing.UnitTests ${tests_files})

target_link_libraries(Pcf.Drawing.UnitTests Pcf.Drawing)

set_target_properties(Pcf.Drawing.UnitTests PROPERTIES FOLDER Pcf/Drawing)
