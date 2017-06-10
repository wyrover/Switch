/// @file
/// @brief Contains Pcf::System::NumberRepresentationBase enum.
#pragma once

#include "Enum.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Specifie the number representation base.
    enum class NumberRepresentationBase {
      /// @brief Binary (base 2)
      Binary = 2,
      /// @brief Octal (base 8)
      Octal = 8,
      /// @brief Decimal (base 10)
      Decimal = 10,
      /// @brief Hexadecimal (base 16)
      Hexadecimal = 16
    };
  }
}

/// @cond
template<>
class EnumToStrings<System::NumberRepresentationBase> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::NumberRepresentationBase::Binary, "Binary"}, {(int64)System::NumberRepresentationBase::Octal, "Octal"}, {(int64)System::NumberRepresentationBase::Decimal, "Decimal"}, {(int64)System::NumberRepresentationBase::Hexadecimal, "Hexadecimal"}};
    flags = false;
  }
};
/// @endcond

using namespace Pcf;
