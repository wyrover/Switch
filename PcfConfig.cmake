include(${CMAKE_CURRENT_LIST_DIR}/Pcf.cmake)  

get_filename_component(Pcf_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(Pcf_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_CURRENT_LIST_DIR}/PcfDependences.cmake)

SET(Pcf_LIBRARIES Pcf.TUnit Pcf.Forms Pcf.Drawing Pcf.Core)
SET(Pcf_WITH_TUNIT_MAIN_LIBRARIES Pcf.TUnit.Main ${Pcf_LIBRARIES})

set(Pcf_FOUND TRUE)
