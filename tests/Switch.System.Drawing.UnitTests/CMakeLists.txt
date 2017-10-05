set(SOURCE_FILES
  ColorTest.cpp
  PointTest.cpp
  RectangleTest.cpp
  SizeTest.cpp
  SystemColorsTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.Drawing.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.Drawing.UnitTests Switch.TUnit.Main Switch.TUnit Switch.Drawing)
set_target_properties(Switch.Drawing.UnitTests PROPERTIES FOLDER tests)

add_test(NAME Switch.Drawing.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.Drawing.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.Drawing.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.Drawing.UnitTests>)
