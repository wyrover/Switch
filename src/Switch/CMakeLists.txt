Project(Switch.)

set(INCLUDE_FILES
  include/Switch/Switch
  include/Switch/Switch.hpp
)

GroupSources(.)

add_library(Switch INTERFACE)
target_include_directories(Switch INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch INTERFACE Switch.Forms Switch.TUnit)

add_custom_target(Switch. ALL SOURCES ${INCLUDE_FILES})

install(FILES include/Switch/Switch include/Switch/Switch.hpp DESTINATION include/Switch)

set_target_properties(Switch. PROPERTIES FOLDER src)
