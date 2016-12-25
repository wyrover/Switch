/// @file
/// @brief Contains Pcf::System::Windows::Forms::DragDropEffects enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        /// @brief Specifie the DragDropEffects values
        enum class DragDropEffects {
          None = 0,
          Copy = 0b1,
          Move = 0x10,
          Link = 0b100,
          Scroll = 0b1000000000000000,
          All = 0b1000000000000111,
        };
      }
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Windows::FormsD::DragDropEffects> : public TrueType {};

template<>
class EnumToStrings<System::Windows::FormsD::DragDropEffects> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::FormsD::DragDropEffects::None, "None"}, {(int64)System::Windows::FormsD::DragDropEffects::Copy, "Copy"}, {(int64)System::Windows::FormsD::DragDropEffects::Move, "Move"}, {(int64)System::Windows::FormsD::DragDropEffects::Link, "Link"}, {(int64)System::Windows::FormsD::DragDropEffects::Scroll, "Scroll"}, {(int64)System::Windows::FormsD::DragDropEffects::All, "All"}};
    flags = true;
  }
};

/// @endcond

using namespace Pcf;
