/// @file
/// @brief Contains Pcf::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Pcf/System/Enum.hpp>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the orientation of controls or elements of controls.
        enum class Orientation {
          /// @brief The control or element is oriented horizontally.
          Horizontal = 0,
          /// @brief The control or element is oriented vertically.
          Vertical = 1,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::Orientation> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::Orientation::Horizontal, "Horizontal"}, {(int64)System::Windows::Forms::Orientation::Vertical, "Vertical"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
