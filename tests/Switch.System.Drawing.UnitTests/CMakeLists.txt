project(Switch.System.Drawing.UnitTests)

set(SOURCE_FILES
  Switch/System/Drawing/ColorTest.cpp
  Switch/System/Drawing/PointTest.cpp
  Switch/System/Drawing/RectangleTest.cpp
  Switch/System/Drawing/SizeTest.cpp
  Switch/System/Drawing/SystemColorsTest.cpp
)

GroupSources(.)

add_executable(Switch.System.Drawing.UnitTests ${SOURCE_FILES})
target_link_libraries(Switch.System.Drawing.UnitTests Switch.TUnit.Main Switch.System.Drawing)
set_target_properties(Switch.System.Drawing.UnitTests PROPERTIES FOLDER tests)

add_test(NAME Switch.System.Drawing.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.System.Drawing.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.System.Drawing.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.System.Drawing.UnitTests>)
