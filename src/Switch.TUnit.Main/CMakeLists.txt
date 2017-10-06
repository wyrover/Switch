project(Switch.TUnit.Main)

GroupSources(.)

add_library(Switch.TUnit.Main STATIC src/Main.cpp)
target_link_libraries(Switch.TUnit.Main Switch.TUnit.Core)

set_target_properties(Switch.TUnit.Main PROPERTIES FOLDER src)

install(TARGETS Switch.TUnit.Main EXPORT Switch DESTINATION lib)
if(MSVC)
  target_compile_options(Switch.TUnit.Main PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Main>/Switch.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.TUnit.Main PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.TUnit.Main>/Switch.TUnit.Main.pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit.Main>/Switch.TUnit.Main${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.TUnit.Main>Switch.TUnit.Main.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
