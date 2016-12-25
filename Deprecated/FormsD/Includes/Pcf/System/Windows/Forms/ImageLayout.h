/// @file
/// @brief Contains Pcf::System::Windows::Forms::ImageLayout enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        /// @brief Specifies the position of the image on the control.
        enum class ImageLayout {
          /// @brief The image is left-aligned at the top across the control's client rectangle.
          None = 0,
          /// @brief The image is tiled across the control's client rectangle.
          Tile = 1,
          /// @brief The image is centered within the control's client rectangle.
          Center = 2,
          /// @brief The image is streched across the control's client rectangle.
          Stretch = 3,
          /// @brief The image is enlarged within the control's client rectangle.
          Zoom = 4
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::FormsD::ImageLayout> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::ImageLayout::None, "None"}, {(int64)System::Windows::FormsD::ImageLayout::Tile, "Tile"}, {(int64)System::Windows::FormsD::ImageLayout::Center, "Center"}, {(int64)System::Windows::FormsD::ImageLayout::Stretch, "Stretch"}, {(int64)System::Windows::FormsD::ImageLayout::Zoom, "Zoom"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
