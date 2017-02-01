set(SOURCE_FILES
  ColorTest.cpp
  PointTest.cpp
  RectangleTest.cpp
  SizeTest.cpp
  SystemColorsTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Drawing.UnitTests ${SOURCE_FILES})
target_link_libraries(Pcf.Drawing.UnitTests Pcf.TUnit.Main Pcf.TUnit Pcf.Drawing)
set_target_properties(Pcf.Drawing.UnitTests PROPERTIES FOLDER Pcf/Drawing)

add_test(NAME Pcf.Drawing.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.Drawing.UnitTests> --tunit_filter=*.* --tunit_output=xml:Pcf.Drawing.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.Drawing.UnitTests>)
