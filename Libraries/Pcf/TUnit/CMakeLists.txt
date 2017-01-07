# Add include files here:
set(includeFiles
./Includes/Pcf/TUnit/Constraints/Constraint.h
./Includes/Pcf/TUnit/Constraints/ConstraintExpression.h
./Includes/Pcf/TUnit/Constraints/ConstraintValue.h
./Includes/Pcf/TUnit/Constraints/Empty.h
./Includes/Pcf/TUnit/Constraints/EqualTo.h
./Includes/Pcf/TUnit.h
./Includes/Pcf/TUnit/Assert.h
./Includes/Pcf/TUnit/AssertionException.h
./Includes/Pcf/TUnit/AssertionResult.h
./Includes/Pcf/TUnit/Constraints.h
./Includes/Pcf/TUnit/Expect.h
./Includes/Pcf/TUnit/Is.h
./Includes/Pcf/TUnit/ConsoleEventListener.h
./Includes/Pcf/TUnit/TestFixture.h
./Includes/Pcf/TUnit/UnitTest.h
./Includes/Pcf/Pcf
./Includes/Pcf/Pcf.h
./Includes/Pcf/TUnit.h
)

# Add source files here:
set(sourceFiles
./Sources/Pcf/TUnit/AssertionResult.cpp
./Sources/Pcf/TUnit/ConsoleEventListener.cpp
./Sources/Pcf/TUnit/Main.cpp
./Sources/Pcf/TUnit/UnitTest.cpp
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes\\Pcf\\TUnit REGULAR_EXPRESSION "/Includes/Pcf/TUnit/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\TUnit\\Constraints REGULAR_EXPRESSION "/Includes/Pcf/TUnit/Constraints/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\TUnit REGULAR_EXPRESSION "/Sources/Pcf/TUnit/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\TUnit\\Constraints REGULAR_EXPRESSION "/Sources/Pcf/TUnit/Constraints/[-_,A-Za-z0-9]+\\.c*")

if (BUILD_TUNIT_UNIT_TESTS)
  add_subdirectory("UnitTests")
endif ()

add_library(Pcf.TUnit STATIC ${includeFiles} ${sourceFiles})
target_include_directories(Pcf.TUnit PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf.TUnit gtest Pcf.Core)

set_target_properties(Pcf.TUnit PROPERTIES FOLDER Pcf/TUnit)

install(TARGETS Pcf.TUnit EXPORT Pcf DESTINATION lib)
install(DIRECTORY "./Includes/."  DESTINATION include)

if(MSVC)
  target_compile_options(Pcf.TUnit PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.TUnit PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>/Pcf.TUnit${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.TUnit>Pcf.TUnit.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
