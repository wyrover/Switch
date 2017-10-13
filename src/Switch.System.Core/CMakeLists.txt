project(Switch.System.Core)

set(INCLUDE_FILES
  include/Switch/Switch.System.Core.hpp
  include/Switch/Switch.System.Core
)

set(SOURCE_FILES
  src/Switch/Switch.System.Core.cpp
)

GroupSources(.)

add_library(Switch.System.Core STATIC ${INCLUDE_FILES} ${SOURCE_FILES})
target_include_directories(Switch.System.Core PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch.System.Core Switch.System)
set_target_properties(Switch.System.Core PROPERTIES FOLDER src)
add_custom_command(TARGET Switch.System.Core POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:Switch.System.Core> ${CMAKE_HOME_DIRECTORY}/lib/$<TARGET_FILE_NAME:Switch.System.Core>)

install(TARGETS Switch.System.Core EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if (MSVC)
  target_compile_options(Switch.System.Core PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System.Core>/Switch.System.Core${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System.Core PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System.Core>/Switch.System.Core.pdb>")
  install(FILES $<TARGET_FILE_DIR:Switch.System.Core>/Switch.System.Core${CMAKE_DEBUG_POSTFIX}.pdb DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES $<TARGET_FILE_DIR:Switch.System.Core>/Switch.System.Core.pdb DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
