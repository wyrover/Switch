set(INCLUDE_FILES
  include/Switch/TUnit/Constraints/Constraint.hpp
  include/Switch/TUnit/Constraints/ConstraintExpression.hpp
  include/Switch/TUnit/Constraints/ConstraintValue.hpp
  include/Switch/TUnit/Constraints/Empty.hpp
  include/Switch/TUnit/Constraints/EqualTo.hpp
  include/Switch/TUnit.hpp
  include/Switch/TUnit/Assert.hpp
  include/Switch/TUnit/AssertionException.hpp
  include/Switch/TUnit/AssertionResult.hpp
  include/Switch/TUnit/Expect.hpp
  include/Switch/TUnit/Is.hpp
  include/Switch/TUnit/TestFixture.hpp
  include/Switch/TUnit/UnitTest.hpp
  include/Switch/TUnit.hpp
)

set(SOURCE_FILES
  src/Switch/TUnit/AssertionResult.cpp
  src/Switch/TUnit/ConsoleEventListener.hpp
  src/Switch/TUnit/ConsoleEventListener.cpp
  src/Switch/TUnit/UnitTest.cpp
)

source_group(include REGULAR_EXPRESSION "/include/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "/include/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "/include/Switch/[-_,A-Za-z0-9]")
source_group(include\\Switch\\TUnit REGULAR_EXPRESSION "/include/Switch/TUnit/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\TUnit\\Constraints REGULAR_EXPRESSION "/include/Switch/TUnit/Constraints/[-_,A-Za-z0-9]+\\.hpp*")

source_group(src REGULAR_EXPRESSION "/src/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch REGULAR_EXPRESSION "/src/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\TUnit REGULAR_EXPRESSION "/src/Switch/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(src\\Switch\\TUnit\\Constraints REGULAR_EXPRESSION "/src/Switch/TUnit/Constraints/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.TUnit STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.TUnit PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Switch.TUnit GTest::GTest Switch.Core)
target_link_libraries(Switch.TUnit ${GTEST_LIBRARIES} Switch.Core)
set_target_properties(Switch.TUnit PROPERTIES FOLDER src)

if (BUILD_TESTS)
  add_subdirectory("ManualTests")
  add_subdirectory("UnitTests")
endif()

install(TARGETS Switch.TUnit EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.TUnit PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.TUnit PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>Switch.TUnit.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
