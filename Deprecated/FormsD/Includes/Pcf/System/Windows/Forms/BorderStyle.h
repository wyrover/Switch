/// @file
/// @brief Contains Pcf::System::Windows::Forms::BorderStyle enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
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

template<>
class EnumToStrings<System::Windows::FormsD::BorderStyle > {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::BorderStyle::None, "None"}, {(int64)System::Windows::FormsD::BorderStyle::FixedSingle, "FixedSingle"}, {(int64)System::Windows::FormsD::BorderStyle::Fixed3D, "Fixed3D"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
