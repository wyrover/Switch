include(${CMAKE_CURRENT_LIST_DIR}/Pcf.cmake)
get_filename_component(PCF_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)

include(${CMAKE_CURRENT_LIST_DIR}/Dependences.cmake)
set(PCF_INCLUDE_DIRS ${PCF_INCLUDE_DIRS} )

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

SET(PCF_LIBRARIES Pcf Pcf.Forms Pcf.Drawing Pcf.Gal Pcf.Core call_stack gtest jpeglib pnglib zlibd fltk libcurl ${STANDARD_LINK_LIBRARIES})    

set(Pcf_FOUND TRUE)
set(PCF_FOUND TRUE)