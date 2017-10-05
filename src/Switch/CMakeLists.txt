set(INCLUDE_FILES
  Includes/Switch/Switch
  Includes/Switch/Switch.hpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]+\\.hpp*")

add_library(Switch INTERFACE)
target_include_directories(Switch INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Switch INTERFACE Switch.Forms Switch.TUnit)

add_custom_target(Switch.Includes ALL SOURCES ${INCLUDE_FILES})

install(FILES Includes/Switch/Switch Includes/Switch/Switch.hpp DESTINATION include/Switch)

set_target_properties(Switch.Includes PROPERTIES FOLDER src/Switch)
