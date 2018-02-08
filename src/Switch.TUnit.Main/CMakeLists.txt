project(Switch.TUnit.Main)
set(LINK_LIBRARIES ${GTEST_LIBRARIES} Switch.TUnit.Core)
set(SWITCH_EXPORT SWITCH_TUNIT_MAIN_EXPORT)
MakeLibraryProject()
