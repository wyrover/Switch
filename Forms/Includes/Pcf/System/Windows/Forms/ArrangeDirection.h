/// @file
/// @brief Contains Pcf::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifies the direction the system uses to arrange minimized windows.
        enum class ArrangeDirection {
          /// @brief Arranges vertically, from top to bottom.
          Down = 0x0004,
          /// @brief Arranges horizontally, from left to right.
          Left = 0x0000,
          /// @brief Arranges horizontally, from right to left.
          Right = 0x0000,
          /// @brief Arranges vertically, from bottom to top.
          Up = 0x0004,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::Forms::ArrangeDirection> : public TrueType {};

template<>
class EnumToStrings<System::Windows::Forms::ArrangeDirection> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {/*{(int64)System::Windows::Forms::ArrangeDirection::Down, "Down"},*/ {(int64)System::Windows::Forms::ArrangeDirection::Left, "Left"}, /*{(int64)System::Windows::Forms::ArrangeDirection::Right, "Right"},*/ {(int64)System::Windows::Forms::ArrangeDirection::Up, "Up"},};
    flags = true;
  }
};
/// @endcond

using namespace Pcf;