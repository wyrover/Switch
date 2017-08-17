set(INCLUDE_FILES
  Includes/Pcf/System/Drawing/Drawing2D/DashStyle.hpp
  Includes/Pcf/System/Drawing/Imaging/ColorPalette.hpp
  Includes/Pcf/System/Drawing/Imaging/FrameDimension.hpp
  Includes/Pcf/System/Drawing/Imaging/ImageFlags.hpp
  Includes/Pcf/System/Drawing/Imaging/ImageFormat.hpp
  Includes/Pcf/System/Drawing/Imaging/PixelFormat.hpp
  Includes/Pcf/System/Drawing/Text/FontCollection.hpp
  Includes/Pcf/System/Drawing/Text/GenericFontFamilies.hpp
  Includes/Pcf/System/Drawing/Text/InstalledFontCollection.hpp
  Includes/Pcf/System/Drawing/Bitmap.hpp
  Includes/Pcf/System/Drawing/Brush.hpp
  Includes/Pcf/System/Drawing/CharacterRange.hpp
  Includes/Pcf/System/Drawing/Color.hpp
  Includes/Pcf/System/Drawing/ContentAlignment.hpp
  Includes/Pcf/System/Drawing/Font.hpp
  Includes/Pcf/System/Drawing/FontFamily.hpp
  Includes/Pcf/System/Drawing/FontStyle.hpp
  Includes/Pcf/System/Drawing/Graphics.hpp
  Includes/Pcf/System/Drawing/GraphicsUnit.hpp
  Includes/Pcf/System/Drawing/Image.hpp
  Includes/Pcf/System/Drawing/KnownColor.hpp
  Includes/Pcf/System/Drawing/Pen.hpp
  Includes/Pcf/System/Drawing/Point.hpp
  Includes/Pcf/System/Drawing/PointF.hpp
  Includes/Pcf/System/Drawing/Rectangle.hpp
  Includes/Pcf/System/Drawing/RectangleF.hpp
  Includes/Pcf/System/Drawing/SolidBrush.hpp
  Includes/Pcf/System/Drawing/Size.hpp
  Includes/Pcf/System/Drawing/SizeF.hpp
  Includes/Pcf/System/Drawing/SystemColors.hpp
  Includes/Pcf/Drawing.hpp
)

set(SOURCE_FILES
  Sources/__OS/DrawingApi.hpp
  Sources/__OS/DrawingApiFltk.cpp
  Sources/__OS/DrawingApiGtk.cpp
  Sources/__OS/DrawingApiWin32.cpp
  Sources/__OS/SystemColorsFltk.cpp
  Sources/__OS/SystemColorsGtk.cpp
  Sources/__OS/SystemColorsWin32.cpp
  Sources/Pcf/System/Drawing/Imaging/FrameDimension.cpp
  Sources/Pcf/System/Drawing/Imaging/ImageFormat.cpp
  Sources/Pcf/System/Drawing/Text/FontCollection.cpp
  Sources/Pcf/System/Drawing/Text/InstalledFontCollection.cpp
  Sources/Pcf/System/Drawing/Bmp.hpp
  Sources/Pcf/System/Drawing/Brush.cpp
  Sources/Pcf/System/Drawing/Color.cpp
  Sources/Pcf/System/Drawing/Font.cpp
  Sources/Pcf/System/Drawing/FontFamily.cpp
  Sources/Pcf/System/Drawing/Gif.hpp
  Sources/Pcf/System/Drawing/Graphics.cpp
  Sources/Pcf/System/Drawing/Image.cpp
  Sources/Pcf/System/Drawing/Jpg.hpp
  Sources/Pcf/System/Drawing/Pen.cpp
  Sources/Pcf/System/Drawing/Png.hpp
  Sources/Pcf/System/Drawing/Point.cpp
  Sources/Pcf/System/Drawing/PointF.cpp
  Sources/Pcf/System/Drawing/Rectangle.cpp
  Sources/Pcf/System/Drawing/RectangleF.cpp
  Sources/Pcf/System/Drawing/Size.cpp
  Sources/Pcf/System/Drawing/SizeF.cpp
  Sources/Pcf/System/Drawing/SolidBrush.cpp
  Sources/Pcf/System/Drawing/SystemColors.cpp
  Sources/Pcf/System/Drawing/Tif.hpp
)

if (APPLE)
set(COCOA_SOURCE_FILES
  Sources/__OS/DrawingApiCocoa.mm
  Sources/__OS/SystemColorsCocoa.mm
)
endif ()

source_group(Includes\\Pcf\\System REGULAR_EXPRESSION "/Includes/Pcf/System/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf\\System\\Drawing\\Drawing2D REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Drawing2D/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf\\System\\Drawing\\Text REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Text/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.hpp*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.hpp*")

source_group(Sources\\Pcf\\System REGULAR_EXPRESSION "/Sources/Pcf/System/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Drawing\\Text REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/Text/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\__OS REGULAR_EXPRESSION "/Sources/__OS/[-_,A-Za-z0-9]+\\.*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

add_library(Pcf.Drawing STATIC ${INCLUDE_FILES} ${SOURCE_FILES} ${COCOA_SOURCE_FILES})
target_include_directories(Pcf.Drawing PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
#target_link_libraries(Pcf.Drawing Pcf.Core ${JPEG_LIBRARIES} PNG::PNG ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
target_link_libraries(Pcf.Drawing Pcf.Core ${JPEG_LIBRARIES} ${PNG_LIBRARY} ${STANDARD_GRAPHIC_LINK_LIBRARIES} ${COCOA_FRAMEWORK})
set_target_properties(Pcf.Drawing PROPERTIES FOLDER Pcf/Drawing)

if (BUILD_TESTS)
  add_subdirectory("UnitTests")
endif()

install(TARGETS Pcf.Drawing EXPORT Pcf DESTINATION lib)
install(DIRECTORY "Includes/Pcf/." DESTINATION include/Pcf)
if(MSVC)
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Debug>:/Fd$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb>")
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Release>:/Fd$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
