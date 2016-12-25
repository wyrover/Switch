
include(Common NO_POLICY_SCOPE)

project(PcfCode)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../${CMAKE_BUILD_TYPE})
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

AddTargetPlatformDefinitions()

Set (Files 
  Includes/MainForm.h
  Includes/GenerateSources.h
  Sources/GenerateSources.cpp
  Sources/MainForm.cpp
  Sources/Program.cpp
)

source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.(c|h)*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.(c|h)*")

add_executable(PcfCode WIN32 ${Files})
set_target_properties(PcfCode PROPERTIES FOLDER Tools/PcfCode)
target_link_libraries(PcfCode Pcf.Forms)
