set(INCLUDE_FILES
  Includes/Pcf/TUnit/Constraints/Constraint.hpp
  Includes/Pcf/TUnit/Constraints/ConstraintExpression.hpp
  Includes/Pcf/TUnit/Constraints/ConstraintValue.hpp
  Includes/Pcf/TUnit/Constraints/Empty.hpp
  Includes/Pcf/TUnit/Constraints/EqualTo.hpp
  Includes/Pcf/TUnit.hpp
  Includes/Pcf/TUnit/Assert.hpp
  Includes/Pcf/TUnit/AssertionException.hpp
  Includes/Pcf/TUnit/AssertionResult.hpp
  Includes/Pcf/TUnit/Expect.hpp
  Includes/Pcf/TUnit/Is.hpp
  Includes/Pcf/TUnit/TestFixture.hpp
  Includes/Pcf/TUnit.hpp
)

set(SOURCE_FILES
  Sources/Pcf/TUnit/AssertionResult.cpp
  Sources/Pcf/TUnit/ConsoleEventListener.hpp
  Sources/Pcf/TUnit/ConsoleEventListener.cpp
  Sources/Pcf/TUnit/UnitTest.cpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes\\Pcf\\TUnit REGULAR_EXPRESSION "/Includes/Pcf/TUnit/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf\\TUnit\\Constraints REGULAR_EXPRESSION "/Includes/Pcf/TUnit/Constraints/[-_,A-Za-z0-9]+\\.hpp*")

source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\TUnit REGULAR_EXPRESSION "/Sources/Pcf/TUnit/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(Sources\\Pcf\\TUnit\\Constraints REGULAR_EXPRESSION "/Sources/Pcf/TUnit/Constraints/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf.TUnit STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Pcf.TUnit PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Pcf.TUnit GTest::GTest Pcf.Core)
target_link_libraries(Pcf.TUnit ${GTEST_LIBRARIES} Pcf.Core)
set_target_properties(Pcf.TUnit PROPERTIES FOLDER Pcf/TUnit)

if (BUILD_TUNIT_UNIT_TESTS)
add_subdirectory("UnitTests")
endif ()

install(TARGETS Pcf.TUnit EXPORT Pcf DESTINATION lib)
install(DIRECTORY "Includes/Pcf/." DESTINATION include/Pcf)
if(MSVC)
  target_compile_options(Pcf.TUnit PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.TUnit PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>Pcf.TUnit.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
