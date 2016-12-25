# Add include files here:
set(include_files
./Includes/Pcf/System/Drawing/Imaging/ColorPalette.h
./Includes/Pcf/System/Drawing/Imaging/FrameDimension.h
./Includes/Pcf/System/Drawing/Imaging/ImageFlags.h
./Includes/Pcf/System/Drawing/Imaging/ImageFormat.h
./Includes/Pcf/System/Drawing/Imaging/PixelFormat.h
./Includes/Pcf/System/Drawing/Bitmap.h
./Includes/Pcf/System/Drawing/Brush.h
./Includes/Pcf/System/Drawing/CharacterRange.h
./Includes/Pcf/System/Drawing/Color.h
./Includes/Pcf/System/Drawing/ContentAlignment.h
./Includes/Pcf/System/Drawing/Font.h
./Includes/Pcf/System/Drawing/FontFamily.h
./Includes/Pcf/System/Drawing/FontStyle.h
./Includes/Pcf/System/Drawing/Graphics.h
./Includes/Pcf/System/Drawing/Image.h
./Includes/Pcf/System/Drawing/Imaging.h
./Includes/Pcf/System/Drawing/KnownColor.h
./Includes/Pcf/System/Drawing/Pen.h
./Includes/Pcf/System/Drawing/Point.h
./Includes/Pcf/System/Drawing/PointF.h
./Includes/Pcf/System/Drawing/Rectangle.h
./Includes/Pcf/System/Drawing/RectangleF.h
./Includes/Pcf/System/Drawing/SolidBrush.h
./Includes/Pcf/System/Drawing/Size.h
./Includes/Pcf/System/Drawing/SizeF.h
./Includes/Pcf/System/Drawing/SystemColors.h
./Includes/Pcf/System/Drawing.h
./Includes/Pcf/Drawing.h
./Includes/Pcf/Pcf
./Includes/Pcf/Pcf.h
)

# Add source files here:
set(source_files
./Sources/Pcf/System/Drawing/Imaging/FrameDimension.cpp
./Sources/Pcf/System/Drawing/Imaging/ImageFormat.cpp
./Sources/Pcf/System/Drawing/Bmp.h
./Sources/Pcf/System/Drawing/Bitmap.cpp
./Sources/Pcf/System/Drawing/Color.cpp
./Sources/Pcf/System/Drawing/Font.cpp
./Sources/Pcf/System/Drawing/FontFamily.cpp
./Sources/Pcf/System/Drawing/Gif.h
./Sources/Pcf/System/Drawing/Graphics.cpp
./Sources/Pcf/System/Drawing/Image.cpp
./Sources/Pcf/System/Drawing/Jpg.h
./Sources/Pcf/System/Drawing/Png.h
./Sources/Pcf/System/Drawing/Point.cpp
./Sources/Pcf/System/Drawing/PointF.cpp
./Sources/Pcf/System/Drawing/Rectangle.cpp
./Sources/Pcf/System/Drawing/RectangleF.cpp
./Sources/Pcf/System/Drawing/Size.cpp
./Sources/Pcf/System/Drawing/SizeF.cpp
./Sources/Pcf/System/Drawing/SystemColor.cpp
./Sources/Pcf/System/Drawing/Tif.h
)

#Add include groups here:
source_group(Includes\\Pcf\\System REGULAR_EXPRESSION "/Includes/Pcf/System/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Includes/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]+\\.h*")
source_group(Includes\\Pcf REGULAR_EXPRESSION "/Includes/Pcf/[-_,A-Za-z0-9]")
source_group(Includes REGULAR_EXPRESSION "/Includes/[-_,A-Za-z0-9]+\\.h*")

#Add source groups here:
source_group(Sources\\Pcf\\System REGULAR_EXPRESSION "/Sources/Pcf/System/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources\\Pcf\\System\\Drawing REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf\\System\\Drawing\\Imaging REGULAR_EXPRESSION "/Sources/Pcf/System/Drawing/Imaging/[-_,A-Za-z0-9]+\\.*")
source_group(Sources\\Pcf REGULAR_EXPRESSION "/Sources/Pcf/[-_,A-Za-z0-9]+\\.c*")
source_group(Sources REGULAR_EXPRESSION "/Sources/[-_,A-Za-z0-9]+\\.c*")

if (BUILD_DRAWING_UNIT_TESTS)
  add_subdirectory("UnitTests")
endif ()

add_library(Pcf.Drawing STATIC ${include_files} ${source_files})
target_include_directories(Pcf.Drawing PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/Includes> $<INSTALL_INTERFACE:include>)
target_link_libraries(Pcf.Drawing jpeglib libpng zlib gel_button Fl_Gel_Tabs fltk Pcf.TUnit)

set_target_properties(Pcf.Drawing PROPERTIES FOLDER Pcf/Drawing)

install(TARGETS Pcf.Drawing EXPORT Pcf DESTINATION lib)
install(DIRECTORY "./Includes/." DESTINATION include)

if(MSVC)
  set(DEBUG_PDB "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb")
  set(RELEASE_PDB "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb")
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Debug>:/Fd${DEBUG_PDB}>")
  target_compile_options(Pcf.Drawing PRIVATE "$<$<CONFIG:Release>:/Fd${RELEASE_PDB}>")
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing${CMAKE_DEBUG_POSTFIX}.pdb" DESTINATION lib CONFIGURATIONS Debug OPTIONAL)
  install(FILES "$<TARGET_FILE_DIR:Pcf.Drawing>/Pcf.Drawing::pdb" DESTINATION lib CONFIGURATIONS Release OPTIONAL)
endif()
