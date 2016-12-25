/// @file
/// @brief Contains Pcf::System::Windows::Forms::AccessibleNavigation enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        /// @brief Specifie the AccessibleNavigation values
        enum class AccessibleNavigation {
          Up = 1,
          Down,
          Left,
          Right,
          Next,
          Previous,
          FirstChild,
          LastChild,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::FormsD::AccessibleNavigation> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::AccessibleNavigation::Up, "Up"}, {(int64)System::Windows::FormsD::AccessibleNavigation::Down, "Down"}, {(int64)System::Windows::FormsD::AccessibleNavigation::Left, "Left"}, {(int64)System::Windows::FormsD::AccessibleNavigation::Right, "Right"}, {(int64)System::Windows::FormsD::AccessibleNavigation::Next, "Next"}, {(int64)System::Windows::FormsD::AccessibleNavigation::Previous, "Previous"}, {(int64)System::Windows::FormsD::AccessibleNavigation::FirstChild, "FirstChild"}, {(int64)System::Windows::FormsD::AccessibleNavigation::LastChild, "LastChild"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
