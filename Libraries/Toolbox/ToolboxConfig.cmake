include(${CMAKE_CURRENT_LIST_DIR}/Toolbox.cmake)
get_filename_component(TOOLBOX_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)

include(${CMAKE_CURRENT_LIST_DIR}/Dependences.cmake)
set(PCF_INCLUDE_DIRS ${TOOLBOX_INCLUDE_DIRS} )
SET(TOOLBOX_LIBRARIES Pcf.Toolbox Pcf)    

set(Toolbox_FOUND TRUE)
set(TOOLBOX_FOUND TRUE)