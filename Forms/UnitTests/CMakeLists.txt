set(SOURCE_FILES
  ApplicationTest.cpp
)

source_group(UnitTests REGULAR_EXPRESSION "/UnitTests/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(Pcf.Forms.UnitTests ${SOURCE_FILES})
set_target_properties(Pcf.Forms.UnitTests PROPERTIES FOLDER Pcf/Forms)
target_link_libraries(Pcf.Forms.UnitTests Pcf.Forms Pcf.TUnit)

add_test(NAME Pcf.Forms.UnitTests COMMAND $<TARGET_FILE_NAME:Pcf.Forms.UnitTests> --tunit_filter=*.* --tunit_output=xml:Pcf.Forms.UnitTests.xml WORKING_DIRECTORY $<TARGET_FILE_DIR:Pcf.Forms.UnitTests>)
