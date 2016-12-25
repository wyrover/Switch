/// @file
/// @brief Contains Pcf::System::Windows::Forms::MouseButtons enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        enum class MouseButtons {
          None = 0,
          Left = 0x100000,
          Right = 0x200000,
          Middle = 0x400000,
          XButton1 = 0x800000,
          XButton2 = 0x1000000
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::FormsD::MouseButtons> : public TrueType {};

template<>
class EnumToStrings<System::Windows::FormsD::MouseButtons> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::MouseButtons::None, "None"}, {(int64)System::Windows::FormsD::MouseButtons::Left, "Left"}, {(int64)System::Windows::FormsD::MouseButtons::Right, "Right"}, {(int64)System::Windows::FormsD::MouseButtons::Middle, "Middle"}, {(int64)System::Windows::FormsD::MouseButtons::XButton1, "XButton1"}, {(int64)System::Windows::FormsD::MouseButtons::XButton2, "XButton2"}};
    flags = true;
  }
};
/// @endcond

using namespace Pcf;
