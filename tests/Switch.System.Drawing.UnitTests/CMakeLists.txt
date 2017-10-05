set(SOURCE_FILES
  ColorTest.cpp
  PointTest.cpp
  RectangleTest.cpp
  SizeTest.cpp
  SystemColorsTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.System.Drawing.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.System.Drawing.UnitTests Switch.TUnit.Main Switch.TUnit Switch.System.Drawing)
set_target_properties(Switch.System.Drawing.UnitTests PROPERTIES FOLDER tests)

add_test(NAME Switch.System.Drawing.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.System.Drawing.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.System.Drawing.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.System.Drawing.UnitTests>)
