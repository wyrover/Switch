/// @file
/// @brief Contains Switch::System::Windows::Forms::DragDropEffects enum.
#pragma once

#include <Switch/System/Enum.hpp>

namespace Switch {
  namespace System {
    namespace Windows {
      namespace Forms {
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
class AddFlagOperators<System::Windows::Forms::DragDropEffects> : public TrueType {};

template<>
class EnumToStrings<System::Windows::Forms::DragDropEffects> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Windows::Forms::DragDropEffects::None, "None"}, {(int64)System::Windows::Forms::DragDropEffects::Copy, "Copy"}, {(int64)System::Windows::Forms::DragDropEffects::Move, "Move"}, {(int64)System::Windows::Forms::DragDropEffects::Link, "Link"}, {(int64)System::Windows::Forms::DragDropEffects::Scroll, "Scroll"}, {(int64)System::Windows::Forms::DragDropEffects::All, "All"}};
    flags = true;
  }
};

/// @endcond

using namespace Switch;
