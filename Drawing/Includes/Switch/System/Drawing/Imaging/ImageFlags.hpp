/// @file
/// @brief Contains Switch::System::Drawing::Imaging::ImageFlags enum.
#pragma once

#include <Switch/System/Enum.hpp>

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the System::Drawing::Drawing2D, System::Drawing::Imaging, and System::Drawing::Text namespaces.
    namespace Drawing {
      /// @brief The System::Drawing::Imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the System::Drawing namespace.
      namespace Imaging {
        /// @brief Specifies the attributes of the pixel data contained in an System::Drawing::Image object. The System::Drawing::Image::Flags property returns a member of this enumeration.
        enum class ImageFlags {
          /// @brief There is no format information.
          None = 0,
          /// @brief The pixel data is scalable.
          Scalable = 0b1,
          /// @brief The pixel data contains alpha information.
          HasAlpha = 0b10,
          /// @brief Specifies that the pixel data has alpha values other than 0 (transparent) and 255 (opaque).
          HasTranslucent = 0b100,
          /// @brief The pixel data is partially scalable, but there are some limitations.
          PartiallyScalable = 0b1000,
          /// @brief The pixel data uses an RGB color space.
          ColorSpaceRgb = 0b10000,
          /// @brief The pixel data uses a CMYK color space.
          ColorSpaceCmyk = 0b100000,
          /// @brief The pixel data is grayscale.
          ColorSpaceGray = 0b1000000,
          /// @brief Specifies that the image is stored using a YCBCR color space.
          ColorSpaceYcbcr = 0b10000000,
          /// @brief Specifies that the image is stored using a YCCK color space.
          ColorSpaceYcck = 0b100000000,
          /// @brief Specifies that dots per inch information is stored in the image.
          HasRealDpi = 0b1000000000000,
          /// @brief Specifies that the pixel size is stored in the image.
          HasRealPixelSize = 0b10000000000000,
          /// @brief The pixel data is read-only.
          ReadOnly = 0b10000000000000000,
          /// @brief The pixel data can be cached for faster access.
          Caching = 0b100000000000000000,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::Imaging::ImageFlags> : public TrueType {};

template<>
class EnumToStrings<System::Drawing::Imaging::ImageFlags> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Drawing::Imaging::ImageFlags::None, "None"}, {(int64)System::Drawing::Imaging::ImageFlags::Scalable, "Scalable"}, {(int64)System::Drawing::Imaging::ImageFlags::HasAlpha, "HasAlpha"}, {(int64)System::Drawing::Imaging::ImageFlags::HasTranslucent, "HasTranslucent"}, {(int64)System::Drawing::Imaging::ImageFlags::PartiallyScalable, "PartiallyScalable"}, {(int64)System::Drawing::Imaging::ImageFlags::ColorSpaceRgb, "ColorSpaceRgb"}, {(int64)System::Drawing::Imaging::ImageFlags::ColorSpaceCmyk, "ColorSpaceCmyk"}, {(int64)System::Drawing::Imaging::ImageFlags::ColorSpaceGray, "ColorSpaceGray"}, {(int64)System::Drawing::Imaging::ImageFlags::ColorSpaceYcbcr, "ColorSpaceYcbcr"}, {(int64)System::Drawing::Imaging::ImageFlags::ColorSpaceYcck, "ColorSpaceYcck"}, {(int64)System::Drawing::Imaging::ImageFlags::HasRealDpi, "HasRealDpi"}, {(int64)System::Drawing::Imaging::ImageFlags::HasRealPixelSize, "HasRealPixelSize"}, {(int64)System::Drawing::Imaging::ImageFlags::ReadOnly, "ReadOnly"}, {(int64)System::Drawing::Imaging::ImageFlags::Caching, "Caching"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
