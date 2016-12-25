/// @file
/// @brief Contains Pcf::System::Windows::Forms::AccessibleNavigation enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
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
class EnumToStrings<System::Windows::Forms::AccessibleNavigation> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::AccessibleNavigation::Up, "Up"}, {(int64)System::Windows::Forms::AccessibleNavigation::Down, "Down"}, {(int64)System::Windows::Forms::AccessibleNavigation::Left, "Left"}, {(int64)System::Windows::Forms::AccessibleNavigation::Right, "Right"}, {(int64)System::Windows::Forms::AccessibleNavigation::Next, "Next"}, {(int64)System::Windows::Forms::AccessibleNavigation::Previous, "Previous"}, {(int64)System::Windows::Forms::AccessibleNavigation::FirstChild, "FirstChild"}, {(int64)System::Windows::Forms::AccessibleNavigation::LastChild, "LastChild"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
