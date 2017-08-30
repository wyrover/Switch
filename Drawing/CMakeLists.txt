set(INCLUDE_FILES
  Includes/Switch/System/Drawing/Drawing2D/DashStyle.hpp
  Includes/Switch/System/Drawing/Imaging/ColorPalette.hpp
  Includes/Switch/System/Drawing/Imaging/FrameDimension.hpp
  Includes/Switch/System/Drawing/Imaging/ImageFlags.hpp
  Includes/Switch/System/Drawing/Imaging/ImageFormat.hpp
  Includes/Switch/System/Drawing/Imaging/PixelFormat.hpp
  Includes/Switch/System/Drawing/Text/FontCollection.hpp
  Includes/Switch/System/Drawing/Text/GenericFontFamilies.hpp
  Includes/Switch/System/Drawing/Text/InstalledFontCollection.hpp
  Includes/Switch/System/Drawing/Bitmap.hpp
  Includes/Switch/System/Drawing/Brush.hpp
  Includes/Switch/System/Drawing/CharacterRange.hpp
  Includes/Switch/System/Drawing/Color.hpp
  Includes/Switch/System/Drawing/ContentAlignment.hpp
  Includes/Switch/System/Drawing/Font.hpp
  Includes/Switch/System/Drawing/FontFamily.hpp
  Includes/Switch/System/Drawing/FontStyle.hpp
  Includes/Switch/System/Drawing/Graphics.hpp
  Includes/Switch/System/Drawing/GraphicsUnit.hpp
  Includes/Switch/System/Drawing/Image.hpp
  Includes/Switch/System/Drawing/KnownColor.hpp
  Includes/Switch/System/Drawing/Pen.hpp
  Includes/Switch/System/Drawing/Point.hpp
  Includes/Switch/System/Drawing/PointF.hpp
  Includes/Switch/System/Drawing/Rectangle.hpp
  Includes/Switch/System/Drawing/RectangleF.hpp
  Includes/Switch/System/Drawing/SolidBrush.hpp
  Includes/Switch/System/Drawing/Size.hpp
  Includes/Switch/System/Drawing/SizeF.hpp
  Includes/Switch/System/Drawing/SystemColors.hpp
  Includes/Switch/Drawing.hpp
)

set(SOURCE_FILES
  Sources/__OS/DrawingApi.hpp
  Sources/__OS/DrawingApiFltk.cpp
  Sources/__OS/DrawingApiGtk.cpp
  Sources/__OS/DrawingApiWin32.cpp
  Sources/__OS/SystemColorsFltk.cpp
  Sources/__OS/SystemColorsGtk.cpp
  Sources/__OS/SystemColorsWin32.cpp
  Sources/Switch/System/Drawing/Imaging/FrameDimension.cpp
  Sources/Switch/System/Drawing/Imaging/ImageFormat.cpp
  Sources/Switch/System/Drawing/Text/FontCollection.cpp
  Sources/Switch/System/Drawing/Text/InstalledFontCollection.cpp
  Sources/Switch/System/Drawing/Bmp.hpp
  Sources/Switch/System/Drawing/Brush.cpp
  Sources/Switch/System/Drawing/Color.cpp
  Sources/Switch/System/Drawing/Font.cpp
  Sources/Switch/System/Drawing/FontFamily.cpp
  Sources/Switch/System/Drawing/Gif.hpp
  Sources/Switch/System/Drawing/Graphics.cpp
  Sources/Switch/System/Drawing/Image.cpp
  Sources/Switch/System/Drawing/Jpg.hpp
  Sources/Switch/System/Drawing/Pen.cpp
  Sources/Switch/System/Drawing/Png.hpp
  Sources/Switch/System/Drawing/Point.cpp
  Sources/Switch/System/Drawing/PointF.cpp
  Sources/Switch/System/Drawing/Rectangle.cpp
  Sources/Switch/System/Drawing/RectangleF.cpp
  Sources/Switch/System/Drawing/Size.cpp
  Sources/Switch/System/Drawing/SizeF.cpp
  Sources/Switch/System/Drawing/SolidBrush.cpp
  Sources/Switch/System/Drawing/SystemColors.cpp
  Sources/Switch/System/Drawing/Tif.hpp
)

if (APPLE)
set(COCOA_SOURCE_FILES
  Sources/__OS/DrawingApiCocoa.mm
  Sources/__OS/SystemColorsCocoa.mm
)
endif ()

source_group(Includes\\Switch\\System REGULAR_EXPRESSION "/Includes/Switch/System/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Drawing REGULAR_EXPRESSION "/Includes/Switch/System/Drawing/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Drawing\\Drawing2D REGULAR_EXPRESSION "/Includes/Switch/System/Drawing/Drawing2D/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Includes/Switch/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch\\System\\Drawing\\Text REGULAR_EXPRESSION "/Includes/Switch/System/Drawing/Text/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Switch REGULAR_EXPRESSION "/Includes/Switch/[-_,A-Za-z0-9]")
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")

source_group(Sources\\Switch\\System REGULAR_EXPRESSION "/Sources/Switch/System/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Switch\\System\\Drawing REGULAR_EXPRESSION "/Sources/Switch/System/Drawing/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Switch\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Sources/Switch/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Switch\\System\\Drawing\\Text REGULAR_EXPRESSION "/Sources/Switch/System/Drawing/Text/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Switch REGULAR_EXPRESSION "/Sources/Switch/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\__OS REGULAR_EXPRESSION "/Sources/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_library(Switch.Drawing STATIC ${INCLUDE_FILES} ${SOURCE_FILES} ${COCOA_SOURCE_FILES})
target_include_directories(Switch.Drawing PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Switch.Drawing Switch.Core ${JPEG_LIBRARIES} PNG::PNG ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
target_link_libraries(Switch.Drawing Switch.Core ${JPEG_LIBRARIES} ${PNG_LIBRARY} ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
set_target_properties(Switch.Drawing PROPERTIES FOLDER Switch/Drawing)

if (BUILD_TESTS)
  add_subdirectory("UnitTests")
endif()

install(TARGETS Switch.Drawing EXPORT Switch DESTINATION lib)
install(DIRECTORY "Includes/Switch/." DESTINATION include/Switch)
if(MSVC)
  target_compile_options(Switch.Drawing PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Switch.Drawing>/Switch.Drawing${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Switch.Drawing PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Switch.Drawing>/Switch.Drawing::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Switch.Drawing>/Switch.Drawing${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Switch.Drawing>/Switch.Drawing::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
