set(SOURCE_FILES
  ApplicationTest.cpp
  ControlTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Switch.Forms.UnitTests ${SOURCE_FILES})
set_target_properties(Switch.Forms.UnitTests PROPERTIES FOLDER Switch/Forms)
target_link_libraries(Switch.Forms.UnitTests Switch.TUnit.Main Switch.TUnit Switch.Forms)

add_test(NAME Switch.Forms.UnitTests COMMAND $<TARGET_FILE_NAME:Switch.Forms.UnitTests> --tunit_filter=*.* --tunit_output=xml:Switch.Forms.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Switch.Forms.UnitTests>)
