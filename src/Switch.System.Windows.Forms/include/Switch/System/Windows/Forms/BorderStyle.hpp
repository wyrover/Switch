/// @file
/// @brief Contains Switch::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
        /// @brief Specifie the BorderStyle values
        enum class BorderStyle {
          None,
          FixedSingle,
          Fixed3D,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::Windows::Forms::BorderStyle > {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::BorderStyle::None, "None"}, {(int64)System::Windows::Forms::BorderStyle::FixedSingle, "FixedSingle"}, {(int64)System::Windows::Forms::BorderStyle::Fixed3D, "Fixed3D"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
