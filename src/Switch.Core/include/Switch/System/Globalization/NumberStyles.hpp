/// @file
/// @brief Contains Switch::System::Globalization::NumberStyles enum.
#pragma once

#include "../Enum.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::Globalization namespace contains classes that define culture-related information, including language, country/region, calendars in use, format patterns for dates, currency, and numbers, and sort order for strings. These classes are useful for writing globalized (internationalized) applications. Classes such as StringInfo and TextInfo provide advanced globalization functionalities, including surrogate support and text element processing.
    namespace Globalization {
      /// @brief Determines the styles permitted in numeric string arguments that are passed to the Parse and TryParse methods of the integral and floating-point numeric types.
      /// This enumeration has a FlagsAttribute attribute that allows a bitwise combination of its member values.
      enum class NumberStyles {
        /// @brief Indicates that no style elements, such as leading or trailing white space, thousands separators, or a decimal separator, can be present in the parsed string. The string to be parsed must consist of integral decimal digits only.
        None = 0,
        /// @brief Indicates that leading white-space characters can be present in the parsed string. Valid white-space characters have the Unicode values U+0009, U+000A, U+000B, U+000C, U+000D, and U+0020. Note that this is a subset of the characters for which the Char.IsWhiteSpace method returns true.
        AllowLeadingWhite = 1,
        AllowTrailingWhite = 2,
        AllowLeadingSign = 4,
        AllowTrailingSign = 8,
        AllowParentheses = 16,
        AllowDecimalPoint = 32,
        AllowThousands = 64,
        AllowExponent = 128,
        AllowCurrencySymbol = 256,
        AllowHexSpecifier = 512,
        Integer = 7,
        HexNumber = 515,
        Number = 111,
        Float = 167,
        Currency = 383,
        Any = 511
      };
    }
  }
}

/// @cond
template <>
class AddFlagOperators<System::Globalization::NumberStyles> : public TrueType {};

template<>
class EnumToStrings<System::Globalization::NumberStyles> {
public:
  void operator ()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::Globalization::NumberStyles::None, "None"}, {(int64)System::Globalization::NumberStyles::AllowLeadingWhite, "AllowLeadingWhite"}, {(int64)System::Globalization::NumberStyles::AllowTrailingWhite, "AllowTrailingWhite"}, {(int64)System::Globalization::NumberStyles::AllowLeadingSign, "AllowLeadingSign"}, {(int64)System::Globalization::NumberStyles::AllowTrailingSign, "AllowTrailingSign"}, {(int64)System::Globalization::NumberStyles::AllowParentheses, "AllowParentheses"}, {(int64)System::Globalization::NumberStyles::AllowDecimalPoint, "AllowDecimalPoint"}, {(int64)System::Globalization::NumberStyles::AllowThousands, "AllowThousands"}, {(int64)System::Globalization::NumberStyles::AllowExponent, "AllowExponent"}, {(int64)System::Globalization::NumberStyles::AllowCurrencySymbol, "AllowCurrencySymbol"}, {(int64)System::Globalization::NumberStyles::AllowHexSpecifier, "AllowHexSpecifier"}, {(int64)System::Globalization::NumberStyles::Integer, "Integer"}, {(int64)System::Globalization::NumberStyles::HexNumber, "HexNumber"}, {(int64)System::Globalization::NumberStyles::Number, "Number"}, {(int64)System::Globalization::NumberStyles::Float, "Float"}, {(int64)System::Globalization::NumberStyles::Currency, "Currency"}, {(int64)System::Globalization::NumberStyles::Any, "Any"}};
    flags = true;
  }
};
/// @endcond

using namespace Switch;
