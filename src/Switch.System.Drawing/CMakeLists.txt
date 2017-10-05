set(INCLUDE_FILES
  include/Switch/System/Drawing/Drawing2D/DashStyle.hpp
  include/Switch/System/Drawing/Imaging/ColorPalette.hpp
  include/Switch/System/Drawing/Imaging/FrameDimension.hpp
  include/Switch/System/Drawing/Imaging/ImageFlags.hpp
  include/Switch/System/Drawing/Imaging/ImageFormat.hpp
  include/Switch/System/Drawing/Imaging/PixelFormat.hpp
  include/Switch/System/Drawing/Text/FontCollection.hpp
  include/Switch/System/Drawing/Text/GenericFontFamilies.hpp
  include/Switch/System/Drawing/Text/InstalledFontCollection.hpp
  include/Switch/System/Drawing/Bitmap.hpp
  include/Switch/System/Drawing/Brush.hpp
  include/Switch/System/Drawing/CharacterRange.hpp
  include/Switch/System/Drawing/Color.hpp
  include/Switch/System/Drawing/ContentAlignment.hpp
  include/Switch/System/Drawing/Font.hpp
  include/Switch/System/Drawing/FontFamily.hpp
  include/Switch/System/Drawing/FontStyle.hpp
  include/Switch/System/Drawing/Graphics.hpp
  include/Switch/System/Drawing/GraphicsUnit.hpp
  include/Switch/System/Drawing/Image.hpp
  include/Switch/System/Drawing/KnownColor.hpp
  include/Switch/System/Drawing/Pen.hpp
  include/Switch/System/Drawing/Point.hpp
  include/Switch/System/Drawing/PointF.hpp
  include/Switch/System/Drawing/Rectangle.hpp
  include/Switch/System/Drawing/RectangleF.hpp
  include/Switch/System/Drawing/SolidBrush.hpp
  include/Switch/System/Drawing/Size.hpp
  include/Switch/System/Drawing/SizeF.hpp
  include/Switch/System/Drawing/SystemColors.hpp
  include/Switch/Drawing.hpp
)

set(SOURCE_FILES
  src/__OS/DrawingApi.hpp
  src/__OS/DrawingApiGtk.cpp
  src/__OS/DrawingApiWin32.cpp
  src/__OS/SystemColorsGtk.cpp
  src/__OS/SystemColorsWin32.cpp
  src/Switch/System/Drawing/Imaging/FrameDimension.cpp
  src/Switch/System/Drawing/Imaging/ImageFormat.cpp
  src/Switch/System/Drawing/Text/FontCollection.cpp
  src/Switch/System/Drawing/Text/InstalledFontCollection.cpp
  src/Switch/System/Drawing/Bmp.hpp
  src/Switch/System/Drawing/Brush.cpp
  src/Switch/System/Drawing/Color.cpp
  src/Switch/System/Drawing/Font.cpp
  src/Switch/System/Drawing/FontFamily.cpp
  src/Switch/System/Drawing/Gif.hpp
  src/Switch/System/Drawing/Graphics.cpp
  src/Switch/System/Drawing/Image.cpp
  src/Switch/System/Drawing/Jpg.hpp
  src/Switch/System/Drawing/Pen.cpp
  src/Switch/System/Drawing/Png.hpp
  src/Switch/System/Drawing/Point.cpp
  src/Switch/System/Drawing/PointF.cpp
  src/Switch/System/Drawing/Rectangle.cpp
  src/Switch/System/Drawing/RectangleF.cpp
  src/Switch/System/Drawing/Size.cpp
  src/Switch/System/Drawing/SizeF.cpp
  src/Switch/System/Drawing/SolidBrush.cpp
  src/Switch/System/Drawing/SystemColors.cpp
  src/Switch/System/Drawing/Tif.hpp
)

if (APPLE)
set(COCOA_SOURCE_FILES
  src/__OS/DrawingApiCocoa.mm
  src/__OS/SystemColorsCocoa.mm
)
endif ()

source_group(include\\Switch\\System REGULAR_EXPRESSION "/include/Switch/System/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Drawing REGULAR_EXPRESSION "/include/Switch/System/Drawing/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Drawing\\Drawing2D REGULAR_EXPRESSION "/include/Switch/System/Drawing/Drawing2D/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/include/Switch/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch\\System\\Drawing\\Text REGULAR_EXPRESSION "/include/Switch/System/Drawing/Text/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "/include/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(include\\Switch REGULAR_EXPRESSION "/include/Switch/[-_,A-Za-z0-9]")
source_group(include REGULAR_EXPRESSION "/include/[-_,A-Za-z0-9]+\\.hpp*")

source_group(src\\Switch\\System REGULAR_EXPRESSION "/src/Switch/System/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\Switch\\System\\Drawing REGULAR_EXPRESSION "/src/Switch/System/Drawing/[-_,A-Za-z0-9]+\\.*")
source_group(src\\Switch\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/src/Switch/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.*")
source_group(src\\Switch\\System\\Drawing\\Text REGULAR_EXPRESSION "/src/Switch/System/Drawing/Text/[-_,A-Za-z0-9]+\\.*")
source_group(src\\Switch REGULAR_EXPRESSION "/src/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(src\\__OS REGULAR_EXPRESSION "/src/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(src REGULAR_EXPRESSION "/src/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.System.Drawing STATIC ${INCLUDE_FILES} ${SOURCE_FILES} ${COCOA_SOURCE_FILES})
target_include_directories(Switch.System.Drawing PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Switch.System.Drawing Switch.Core ${JPEG_LIBRARIES} PNG::PNG ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
target_link_libraries(Switch.System.Drawing Switch.Core ${JPEG_LIBRARIES} ${PNG_LIBRARY} ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
set_target_properties(Switch.System.Drawing PROPERTIES FOLDER src)

install(TARGETS Switch.System.Drawing EXPORT Switch DESTINATION lib)
install(DIRECTORY "include/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.System.Drawing PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.System.Drawing>/Switch.System.Drawing${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.System.Drawing PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.System.Drawing>/Switch.System.Drawing::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.System.Drawing>/Switch.System.Drawing${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.System.Drawing>/Switch.System.Drawing::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
