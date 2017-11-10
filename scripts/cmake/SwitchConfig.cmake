include(${CMAKE_CURRENT_LIST_DIR}/Switch.cmake)  

get_filename_component(Switch_INCLUDE_DIRS "${CMAKE_CURRENT_LIST_DIR}/../include" ABSOLUTE)
get_filename_component(Switch_LIBRARIES_DIRS "${CMAKE_CURRENT_LIST_DIR}/../lib" ABSOLUTE)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(call_stack REQUIRED)
find_package(CURL REQUIRED)
find_package(easywsclient REQUIRED)
find_package(GTest REQUIRED)
find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)
find_package(Rs232 REQUIRED)
find_package(ZLIB REQUIRED)

include(${CMAKE_CURRENT_LIST_DIR}/SwitchDependencies.cmake)

SET(Switch_LIBRARIES Switch.TUnit.Core Switch.System.Windows.Forms Switch.System.Drawing Switch.System Switch.Core)
SET(Switch_WITH_TUNIT_MAIN_LIBRARIES Switch.TUnit.Main ${Switch_LIBRARIES})

set(Switch_FOUND TRUE)
