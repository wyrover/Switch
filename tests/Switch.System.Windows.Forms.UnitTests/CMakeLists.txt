set(SOURCE_FILES
  ApplicationTest.cpp
  ControlTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.System.Windows.Forms.UnitTests ${SOURCE_FILES})
set_target_properties(Switch.System.Windows.Forms.UnitTests PROPERTIES FOLDER tests)
target_link_libraries(Switch.System.Windows.Forms.UnitTests Switch.TUnit.Main Switch.TUnit Switch.System.Windows.Forms)

add_test(NAME Switch.System.Windows.Forms.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.System.Windows.Forms.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.System.Windows.Forms.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.System.Windows.Forms.UnitTests>)
