/// @file
/// @brief Contains Pcf::System::Drawing::FontStyle enum.
#pragma once

#include <Pcf/System/Enum.h>

namespace Pcf {
  namespace System {
    namespace Drawing {
      /// @brief This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      enum class FontStyle {
        /// @brief Normal text.
        Regular = 0,
        /// @brief Bold text.
        Bold = 0b1,
        /// @brief Italic text.
        Italic = 0b10,
        /// @brief Underline text.
        Underline = 0b100,
        /// @brief Text with a line through the middle.
        Strikeout = 0b1000
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Drawing::FontStyle> : public TrueType {};

template<>
class EnumToStrings<System::Drawing::FontStyle> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Drawing::FontStyle::Regular, "Regular"}, {(int64)System::Drawing::FontStyle::Bold, "Bold"}, {(int64)System::Drawing::FontStyle::Italic, "Italic"}, {(int64)System::Drawing::FontStyle::Underline, "Underline"}, {(int64)System::Drawing::FontStyle::Strikeout, "Strikeout"}};
    flags = true;
  }
};
/// @endcond

using namespace Pcf;
