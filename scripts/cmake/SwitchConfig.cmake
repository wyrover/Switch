include(${CMAKE_CURRENT_LIST_DIR}/Switch.cmake)  

get_filename_component(SWITCH_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(SWITCH_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CALL_STACK REQUIRED)
find_package(CURL REQUIRED)
find_package(EASYWSCLIENT REQUIRED)
find_package(GTEST REQUIRED)
find_package(JPEG REQUIRED)
find_package(RS232 REQUIRED)
find_package(ZLIB REQUIRED)
find_package(PNG REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/SwitchDependencies.cmake)

SET(SWITCH_LIBRARIES Switch.TUnit.Core Switch.System.Windows.Forms Switch.System.Drawing Switch.System Switch.Core)
SET(SWITCH_WITH_TUNIT_MAIN_LIBRARIES Switch.TUnit.Main ${SWITCH_LIBRARIES})

set(SWITCH_FOUND TRUE)
