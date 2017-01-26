get_filename_component(SELF_DIR "${CMAKE_CURRENT_LIST_FILE}" PATH)
include(${SELF_DIR}/Pcf.cmake)
get_filename_component(Pcf_INCLUDE_DIRS "${SELF_DIR}/../../include/Pcf" ABSOLUTE)
#get_filename_component(Pcf_LIBRARIES_DIRS "${SELF_DIR}/../../lib/Pcf" ABSOLUTE)

if (APPLE)
  set(STANDARD_LINK_LIBRARIES pthread)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl pthread rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

SET(Pcf_LIBRARIES Pcf.Forms Pcf.Drawing Pcf.Core call_stack curl easywsclient gtest jpeglib libpng Rs232 zlib ${STANDARD_LINK_LIBRARIES})    

set(Pcf_FOUND TRUE)
