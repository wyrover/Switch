# Add include files here:
set(include_files
./Includes/Osa/IO/Console.h
./Includes/Osa/Types/Any.h
./Includes/Osa/Types/boolean.h
./Includes/Osa/Types/byte.h
./Includes/Osa/Types/char32.h
./Includes/Osa/Types/decimal.h
./Includes/Osa/Types/int16.h
./Includes/Osa/Types/int32.h
./Includes/Osa/Types/int64.h
./Includes/Osa/Types/intptr.h
./Includes/Osa/Types/null.h
./Includes/Osa/Types/sbyte.h
./Includes/Osa/Types/single.h
./Includes/Osa/Types/type.h
./Includes/Osa/Types/uint16.h
./Includes/Osa/Types/uint32.h
./Includes/Osa/Types/uint64.h
./Includes/Osa/Types/uintptr.h
./Includes/Osa/Enum.h
./Includes/Osa/Foreach.h
./Includes/Osa/GTest.h
./Includes/Osa/IO.h
./Includes/Osa/Throw.h
./Includes/Osa/Types.h
./Includes/Osa/Using.h
./Includes/Osa/Var.h
./Includes/Pcf/Osa.h
./Includes/Pcf/Osa
)

# Add source files here:
set(source_files
./Sources/Osa/IO/Console.cpp
)

#Add include groups here:
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa REGULAR_EXPRESSION "/Includes/Osa/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Chrono REGULAR_EXPRESSION "/Includes/Osa/Chrono/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\IO REGULAR_EXPRESSION "/Includes/Osa/IO/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Memory REGULAR_EXPRESSION "/Includes/Osa/Memory/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Memory\\__Internal REGULAR_EXPRESSION "/Includes/Osa/Memory/__Internal/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Threading REGULAR_EXPRESSION "/Includes/Osa/Threading/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Processes REGULAR_EXPRESSION "/Includes/Osa/Processes/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Osa\\Types REGULAR_EXPRESSION "/Includes/Osa/Types/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa REGULAR_EXPRESSION "/Sources/Osa/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Chrono REGULAR_EXPRESSION "/Sources/Osa/Chrono/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\IO REGULAR_EXPRESSION "/Sources/Osa/IO/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Memory REGULAR_EXPRESSION "/Sources/Osa/Memory/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Memory\\__Internal REGULAR_EXPRESSION "/Sources/Osa/Memory/__Internal/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Threading REGULAR_EXPRESSION "/Sources/Osa/Threading/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Processes REGULAR_EXPRESSION "/Sources/Osa/Processes/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Osa\\Types REGULAR_EXPRESSION "/Sources/Osa/Types/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf.Osa STATIC ${include_files} ${source_files})

target_include_directories(Pcf.Osa PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)

target_link_libraries(Pcf.Osa gtest ${STANDARD_LINK_LIBRARIES})

set_target_properties(Pcf.Osa PROPERTIES FOLDER Pcf/Osa)

install(TARGETS Pcf.Osa EXPORT ${PROJECT_NAME} DESTINATION lib)
install (DIRECTORY "./Includes/." DESTINATION include)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:Pcf.Osa>/Pcf.Osa${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:Pcf.Osa>/Pcf.Osa.pdb")
  target_compile_options(Pcf.Osa PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(Pcf.Osa PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.Osa>/Pcf.Osa${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION bin CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.Osa>Pcf.Osa.pdb" DESTINATION bin CONFIGURATIONS Release OPTIONAL)
endif()
