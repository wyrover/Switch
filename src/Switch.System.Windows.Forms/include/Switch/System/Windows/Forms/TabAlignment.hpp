/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Controls where the tabs will be located in a Tab Control.
        enum class TabAlignment {
          /// @biref Tabs will be located across the top of the control.
          Top = 0,
          /// @brief Tabs will be located across the bottom of the control.
          Bottom = 1,
          /// @brief Tabs will be located along the left edge of the control.
          Left = 2,
          /// @brief Tabs will be located along the right edge of the control.
          Right = 3,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::TabAlignment> {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::TabAlignment::Top, "Top"}, {(int64)System::Windows::Forms::TabAlignment::Bottom, "Bottom"}, {(int64)System::Windows::Forms::TabAlignment::Left, "Left"}, {(int64)System::Windows::Forms::TabAlignment::Right, "Right"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
