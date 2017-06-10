set(INCLUDE_FILES
  Includes/Pcf/Pcf
  Includes/Pcf/Pcf.hpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.hpp*")

add_library(Pcf INTERFACE)
target_include_directories(Pcf INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf INTERFACE Pcf.Forms Pcf.TUnit)

add_custom_target(Pcf.Includes ALL SOURCES ${INCLUDE_FILES})

install(FILES Includes/Pcf/Pcf Includes/Pcf/Pcf.hpp DESTINATION include/Pcf)

set_target_properties(Pcf.Includes PROPERTIES FOLDER Pcf/Pcf)
