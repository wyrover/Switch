project(Switch.TUnit.Core)
#set(LINK_LIBRARIES GTest::GTest Switch.Core)
set(LINK_LIBRARIES ${GTEST_LIBRARIES} Switch.Core)
MakeLibraryProject()
