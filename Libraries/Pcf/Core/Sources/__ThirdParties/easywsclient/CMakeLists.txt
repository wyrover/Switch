
if (APPLE)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (UNIX)
  SET(CMAKE_CXX_FLAGS "-std=c++14 -Wall -WExtra -Wpedantic -Wdeprecated-declarations -Wno-unknown-pragmas -Wno-unused-parameter")
  set(CMAKE_CXX_FLAGS_DEBUG "-g -o0 -D_DEBUG -DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -DRELEASE")
elseif (MSVC)
  set(CMAKE_CXX_FLAGS "/DWIN32 /D_WINDOWS /DUNICODE /D_UNICODE /D_CRT_SECURE_NO_WARNINGS /D_CRT_NON_CONFORMING_SWPRINTFS /Zm1000 /bigobj /EHsc /GR /MP /Oy- /W4 /wd4100 /wd4244 /wd4267 /wd4312 /wd4355 /wd4456 /wd4458 /wd4477")
  set(CMAKE_CXX_FLAGS_DEBUG "/MTd /Od /Zi /RTC1 /D_DEBUG /DDEBUG")
  set(CMAKE_CXX_FLAGS_RELEASE "/MT /Gy /O2 /Oi /GL- /DNDEBUG /DRELEASE")
endif ()

project(easywsclient VERSION 1.0.0)

set(SOURCE_FILES
  easywsclient.hpp
  easywsclient.cpp
)

source_group(Sources REGULAR_EXPRESSION "/[-_,A-Za-z0-9]+\\.(h|c)*")

add_library(easywsclient STATIC ${SOURCE_FILES})
target_link_libraries(easywsclient ${STANDARD_LINK_LIBRARIES})
target_include_directories(easywsclient PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}> $<INSTALL_INTERFACE:include>)
set_target_properties(easywsclient PROPERTIES FOLDER Pcf/Core/__ThirdParties)

#install(EXPORT easywsclient DESTINATION cmake)  
#install(FILES easywsclientConfig.cmake DESTINATION cmake)
install(TARGETS easywsclient EXPORT Pcf DESTINATION lib)
#install (FILES easywsclient.hpp DESTINATION include/easywsclient)
if(MSVC)
  target_compile_options(easywsclient PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:easywsclient>/easywsclient${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(easywsclient PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:easywsclient>/easywsclient.pdb>")
  install(FILES "$<TARGET_FILE_DIR:easywsclient>/easywsclient${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:easywsclient>/easywsclient.pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
