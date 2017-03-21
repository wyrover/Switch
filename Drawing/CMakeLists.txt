set(INCLUDE_FILES
  Includes/Pcf/System/Drawing/Drawing2D/DashStyle.h
  Includes/Pcf/System/Drawing/Imaging/ColorPalette.h
  Includes/Pcf/System/Drawing/Imaging/FrameDimension.h
  Includes/Pcf/System/Drawing/Imaging/ImageFlags.h
  Includes/Pcf/System/Drawing/Imaging/ImageFormat.h
  Includes/Pcf/System/Drawing/Imaging/PixelFormat.h
  Includes/Pcf/System/Drawing/Text/FontCollection.h
  Includes/Pcf/System/Drawing/Text/GenericFontFamilies.h
  Includes/Pcf/System/Drawing/Text/InstalledFontCollection.h
  Includes/Pcf/System/Drawing/Bitmap.h
  Includes/Pcf/System/Drawing/Brush.h
  Includes/Pcf/System/Drawing/CharacterRange.h
  Includes/Pcf/System/Drawing/Color.h
  Includes/Pcf/System/Drawing/ContentAlignment.h
  Includes/Pcf/System/Drawing/Font.h
  Includes/Pcf/System/Drawing/FontFamily.h
  Includes/Pcf/System/Drawing/FontStyle.h
  Includes/Pcf/System/Drawing/Graphics.h
  Includes/Pcf/System/Drawing/GraphicsUnit.h
  Includes/Pcf/System/Drawing/Image.h
  Includes/Pcf/System/Drawing/KnownColor.h
  Includes/Pcf/System/Drawing/Pen.h
  Includes/Pcf/System/Drawing/Point.h
  Includes/Pcf/System/Drawing/PointF.h
  Includes/Pcf/System/Drawing/Rectangle.h
  Includes/Pcf/System/Drawing/RectangleF.h
  Includes/Pcf/System/Drawing/SolidBrush.h
  Includes/Pcf/System/Drawing/Size.h
  Includes/Pcf/System/Drawing/SizeF.h
  Includes/Pcf/System/Drawing/SystemColors.h
  Includes/Pcf/Drawing.h
)

set(SOURCE_FILES
  Sources/__OS/DrawingApi.h
  Sources/__OS/DrawingApiWin32.cpp
  Sources/__OS/DrawingApiX.cpp
  Sources/Pcf/System/Drawing/Imaging/FrameDimension.cpp
  Sources/Pcf/System/Drawing/Imaging/ImageFormat.cpp
  Sources/Pcf/System/Drawing/Text/FontCollection.cpp
  Sources/Pcf/System/Drawing/Text/InstalledFontCollection.cpp
  Sources/Pcf/System/Drawing/Bmp.h
  Sources/Pcf/System/Drawing/Bitmap.cpp
  Sources/Pcf/System/Drawing/Brush.cpp
  Sources/Pcf/System/Drawing/Color.cpp
  Sources/Pcf/System/Drawing/Font.cpp
  Sources/Pcf/System/Drawing/FontFamily.cpp
  Sources/Pcf/System/Drawing/Gif.h
  Sources/Pcf/System/Drawing/Graphics.cpp
  Sources/Pcf/System/Drawing/Image.cpp
  Sources/Pcf/System/Drawing/Jpg.h
  Sources/Pcf/System/Drawing/Pen.cpp
  Sources/Pcf/System/Drawing/Png.h
  Sources/Pcf/System/Drawing/Point.cpp
  Sources/Pcf/System/Drawing/PointF.cpp
  Sources/Pcf/System/Drawing/Rectangle.cpp
  Sources/Pcf/System/Drawing/RectangleF.cpp
  Sources/Pcf/System/Drawing/Size.cpp
  Sources/Pcf/System/Drawing/SizeF.cpp
  Sources/Pcf/System/Drawing/SolidBrush.cpp
  Sources/Pcf/System/Drawing/SystemColor.cpp
  Sources/Pcf/System/Drawing/Tif.h
)

if (APPLE)
set(COCOA_SOURCE_FILES
  Sources/__OS/DrawingApiCocoa.mm
)
endif ()

source_group(Includes\\Pcf\\System REGULAR_EXPRESSION "/Includes/Pcf/System/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing\\Drawing2D REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Drawing2D/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing\\Text REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Text/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")

source_group(Sources\\Pcf\\System REGULAR_EXPRESSION "/Sources/Pcf/System/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Drawing\\Text REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/Text/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\__OS REGULAR_EXPRESSION "/Sources/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

find_package(JPEG REQUIRED)
find_package(PNG REQUIRED)

if (APPLE)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES "-framework Cocoa -framework Foundation")
elseif(UNIX)
  find_package(FLTK REQUIRED)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES ${FLTK_LIBRARIES})
elseif(MSVC)
  set(STANDARD_GRAPHIC_LINK_LIBRARIES Uxtheme)
endif ()

add_library(Pcf.Drawing STATIC ${INCLUDE_FILES} ${SOURCE_FILES} ${COCOA_SOURCE_FILES})
target_include_directories(Pcf.Drawing PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf.Drawing Pcf.Core ${JPEG_LIBRARIES} ${PNG_LIBRARIES} ${STANDARD_GRAPHIC_LINK_LIBRARIES})
set_target_properties(Pcf.Drawing PROPERTIES FOLDER Pcf/Drawing)

if (BUILD_DRAWING_UNIT_TESTS)
  add_subdirectory("UnitTests")
endif ()

install(TARGETS Pcf.Drawing EXPORT Pcf DESTINATION lib)
install(DIRECTORY "Includes/Pcf/." DESTINATION include/Pcf)
if(MSVC)
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
