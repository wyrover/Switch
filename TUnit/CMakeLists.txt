set(INCLUDE_FILES
  Includes/Switch/TUnit/Constraints/Constraint.hpp
  Includes/Switch/TUnit/Constraints/ConstraintExpression.hpp
  Includes/Switch/TUnit/Constraints/ConstraintValue.hpp
  Includes/Switch/TUnit/Constraints/Empty.hpp
  Includes/Switch/TUnit/Constraints/EqualTo.hpp
  Includes/Switch/TUnit.hpp
  Includes/Switch/TUnit/Assert.hpp
  Includes/Switch/TUnit/AssertionException.hpp
  Includes/Switch/TUnit/AssertionResult.hpp
  Includes/Switch/TUnit/Expect.hpp
  Includes/Switch/TUnit/Is.hpp
  Includes/Switch/TUnit/TestFixture.hpp
  Includes/Switch/TUnit/UnitTest.hpp
  Includes/Switch/TUnit.hpp
)

set(SOURCE_FILES
  Sources/Switch/TUnit/AssertionResult.cpp
  Sources/Switch/TUnit/ConsoleEventListener.hpp
  Sources/Switch/TUnit/ConsoleEventListener.cpp
  Sources/Switch/TUnit/UnitTest.cpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]")
source_group(Includes\\Switch\\TUnit REGULAR_EXPRESSION "/Includes/Switch/TUnit/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\TUnit\\Constraints REGULAR_EXPRESSION "/Includes/Switch/TUnit/Constraints/[-_,A-Za-z0-9]+\\.hpp*")

source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch REGULAR_EXPRESSION "/Sources/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\TUnit REGULAR_EXPRESSION "/Sources/Switch/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(Sources\\Switch\\TUnit\\Constraints REGULAR_EXPRESSION "/Sources/Switch/TUnit/Constraints/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.TUnit STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.TUnit PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Switch.TUnit GTest::GTest Switch.Core)
target_link_libraries(Switch.TUnit ${GTEST_LIBRARIES} Switch.Core)
set_target_properties(Switch.TUnit PROPERTIES FOLDER Switch/TUnit)

if (BUILD_TESTS)
  add_subdirectory("UnitTests")
endif()

install(TARGETS Switch.TUnit EXPORT Switch DESTINATION lib)
install(DIRECTORY "Includes/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.TUnit PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.TUnit PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>Switch.TUnit.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
