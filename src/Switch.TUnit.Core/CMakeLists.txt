project(Switch.TUnit.Core)

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

GroupSources(.)

add_library(Switch.TUnit.Core STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.TUnit.Core PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Switch.TUnit.Core GTest::GTest Switch.System)
target_link_libraries(Switch.TUnit.Core ${GTEST_LIBRARIES} Switch.System)
set_target_properties(Switch.TUnit.Core PROPERTIES FOLDER src)

install(TARGETS Switch.TUnit.Core EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.TUnit.Core PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Core>/Switch.TUnit.Core${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.TUnit.Core PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Core>/Switch.TUnit.Core.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit.Core>/Switch.TUnit.Core${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit.Core>Switch.TUnit.Core.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
