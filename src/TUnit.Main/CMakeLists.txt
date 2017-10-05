source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.TUnit.Main STATIC Sources/Main.cpp)
target_link_libraries(Switch.TUnit.Main Switch.TUnit)

set_target_properties(Switch.TUnit.Main PROPERTIES FOLDER src/TUnit.Main)

install(TARGETS Switch.TUnit.Main EXPORT Switch DESTINATION lib)
if(MSVC)
  target_compile_options(Switch.TUnit.Main PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Main>/Switch.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.TUnit.Main PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Main>/Switch.TUnit.Main.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>/Switch.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit>Switch.TUnit.Main.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
