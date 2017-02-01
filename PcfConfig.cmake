include(${CMAKE_CURRENT_LIST_DIR}/Pcf.cmake)  

get_filename_component(Pcf_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(Pcf_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

if (APPLE)
  set(STANDARD_LINK_LIBRARIES dl)	
elseif(UNIX)
  set(STANDARD_LINK_LIBRARIES dl rt)
elseif(MSVC)
  set(STANDARD_LINK_LIBRARIES Ws2_32.lib Iphlpapi.lib Rpcrt4.lib)    
endif ()	

find_package(Threads REQUIRED)
find_package(call_stack REQUIRED)
find_package(CURL REQUIRED)
find_package(easywsclient REQUIRED)
find_package(Rs232 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(GTest REQUIRED)

SET(Pcf_LIBRARIES Pcf.TUnit ${GTEST_LIBRARIES} Pcf.Forms Pcf.Drawing ${JPEG_LIBRARIES} ${PNG_LIBRARIES} Pcf.Core ${call_stack_LIBRARIES} ${CURL_LIBRARIES} ${easywsclient_LIBRARIES} ${Rs232_LIBRARIES} ${ZLIB_LIBRARIES} Threads::Threads ${STANDARD_LINK_LIBRARIES})
SET(Pcf_WITH_TUNIT_MAIN_LIBRARIES Pcf.TUnit.Main ${Pcf_LIBRARIES})

set(Pcf_FOUND TRUE)
