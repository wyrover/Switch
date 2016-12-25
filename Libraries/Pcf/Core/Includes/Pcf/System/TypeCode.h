/// @file
/// @brief Contains Pcf::System::TypeCode enum.
#pragma once

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @enum TypeCode
    /// @brief Specifies the type of an object.
    /// @see IConvertible
    enum class TypeCode {
      /// @brief A null reference.
      Empty = 0,
      /// @brief A general type representing any reference or value type not explicitly represented by another TypeCode.
      Object = 1,
      /// @brief A simple type representing Boolean values of true or false.
      Boolean = 2,
      /// @brief An integral type representing unsigned 8-bit integers with values between 0 and 255. The set of possible values for the System::TypeCode.Char type corresponds to the Unicode character set.
      Char = 3,
      /// @brief An integral type representing signed 8-bit integers with values between -128 and 127.
      SByte = 4,
      /// @brief An integral type representing unsigned 8-bit integers with values between 0 and 255.
      Byte = 5,
      /// @brief An integral type representing signed 16-bit integers with values between -32768 and 32767.
      Int16 = 6,
      /// @brief An integral type representing unsigned 16-bit integers with values between 0 and 65535.
      UInt16 = 7,
      /// @brief An integral type representing signed 32-bit integers with values between -2147483648 and 2147483647.
      Int32 = 8,
      /// @brief An integral type representing unsigned 32-bit integers with values between 0 and 4294967295.
      UInt32 = 9,
      /// @brief An integral type representing signed 64-bit integers with values between -9223372036854775808 and 9223372036854775807.
      Int64 = 10,
      /// @brief An integral type representing unsigned 64-bit integers with values between 0 and 18446744073709551615.
      UInt64 = 11,
      /// @brief A floating point type representing values ranging from approximately 1.5 x 10 -45 to 3.4 x 10 38 with a precision of 7 digits.
      Single = 12,
      /// @brief A floating point type representing values ranging from approximately 5.0 x 10 -324 to 1.7 x 10 308 with a precision of 15-16 digits.
      Double = 13,
      /// @brief A type representing a date and time value.
      DateTime = 14,
      /// @brief A sealed class type representing Unicode character strings.
      String = 15,
    };
  }
}

/*
#include "Enum.h"

/// @cond
template<>
class EnumToStrings<System::TypeCode> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::TypeCode::Empty, "Empty"}, {(int64)System::TypeCode::Object, "Object"}, {(int64)System::TypeCode::Boolean, "Boolean"}, {(int64)System::TypeCode::Char, "Char"}, {(int64)System::TypeCode::SByte, "SByte"}, {(int64)System::TypeCode::Byte, "Byte"}, {(int64)System::TypeCode::Int16, "Int16"}, {(int64)System::TypeCode::UInt16, "UInt16"}, {(int64)System::TypeCode::Int32, "Int32"}, {(int64)System::TypeCode::UInt32, "UInt32"}, {(int64)System::TypeCode::Int64, "Int64"}, {(int64)System::TypeCode::UInt64, "UInt64"}, {(int64)System::TypeCode::Single, "Single"}, {(int64)System::TypeCode::Double, "Double"}, {(int64)System::TypeCode::DateTime, "DateTime"}, {(int64)System::TypeCode::String, "String"}};
    flags = false;
  }
};
/// @endcond
 */

using namespace Pcf;
