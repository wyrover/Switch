/// @file
/// @brief Contains Pcf::System::Byte struct.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "IFormattable.h"
#include "Object.h"
#include "_String.h"
#include "ValueType.h"

/// @cond
/// @endcond

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    namespace Threading {
      class Interlocked;
    }
    /// @endcond

    /// @brief Represents a 8-bit unsigned integer.
    struct pcf_public Byte final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Create a new instance of struct Byte
      /// @remarks Byte is initialized by default to 0.
      Byte() {}

      /// @brief Create a new instance of struct Byte
      /// @param value Value for the Byte.
      Byte(byte value) : value(value) {}
      
      /// @brief Represents the largest possible value of an Byte 255 (0xFF). This field is constant.
      static Property<byte, ReadOnly> MaxValue;

      /// @brief Represents the smallest possible value of Byte 0 (0x00). This field is constant.
      static Property<byte, ReadOnly> MinValue;

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @return A 8-bit unsigned integer equivalent to the number contained in str.
      static byte Parse(const String& str);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return A 8-bit unsigned integer equivalent to the number contained in str.
      static byte Parse(const String& str, const int32 base);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, byte& retValue);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, Byte& retValue);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, byte& retValue);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param str A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param retValue When this method returns, contains the 8-bit unsigned integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if str was converted successfully; otherwise, false.
      static bool TryParse(const String& str, int32 base, Byte& retValue);

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current Byte.
      /// @return String A String that represents the current Byte.
      String ToString() const override;
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current Byte.
      /// @param format Format-control String.
      /// @return String A String that represents the current Byte.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified Byte object and returns an indication of their relative values.
      /// @param value An Byte object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// | result            | Condition                                                                   |
      /// |-------------------|-----------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and value is true.                                   |
      /// | Zero              | This instance and value are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and value is false.  -or- value is null reference.    |
      int32 CompareTo(const Byte& value) const;
      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// | result            | Condition                                                   ,             |
      /// |-------------------|---------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and obj is true.                                   |
      /// | Zero              | This instance and obj are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and obj is false.  -or- obj is null reference.      |
      int32 CompareTo(const IComparable& obj) const override;
      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override;

    private:
      /// @cond
      friend class Convert;
      friend class System::Threading::Interlocked;
      /// @endcond

      bool IsSigned() const override { return false; }

      bool ToBoolean(const IFormatProvider& provider) const override;
      byte ToByte(const IFormatProvider& provider) const override;
      char32 ToChar(const IFormatProvider& provider) const override;
      DateTime ToDateTime(const IFormatProvider& provider) const override;
      double ToDouble(const IFormatProvider& provider) const override;
      int16 ToInt16(const IFormatProvider& provider) const override;
      int32 ToInt32(const IFormatProvider& provider) const override;
      int64 ToInt64(const IFormatProvider& provider) const override;
      uint16 ToUInt16(const IFormatProvider& provider) const override;
      uint32 ToUInt32(const IFormatProvider& provider) const override;
      uint64 ToUInt64(const IFormatProvider& provider) const override;
      sbyte ToSByte(const IFormatProvider& provider) const override;
      float ToSingle(const IFormatProvider& provider) const override;
      String ToString(const IFormatProvider& provider) const override;

      byte value = 0;

    public:
      /// @cond
      Byte(const Byte& value) : value(value.value) {}
      operator const byte&() const { return this->value; }

      Byte& operator =(const Byte& value) {
        this->value = value.value;
        return *this;
      }
      
      Byte& operator +=(const Byte& value) {
        this->value += value.value;
        return *this;
      }

      Byte& operator -=(const Byte& value) {
        this->value -= value.value;
        return *this;
      }

      Byte& operator *=(const Byte& value) {
        this->value *= value.value;
        return *this;
      }

      Byte& operator /=(const Byte& value);

      Byte& operator %=(const Byte& value);

      Byte& operator &=(const Byte& value) {
        this->value &= value.value;
        return *this;
      }

      Byte& operator |=(const Byte& value) {
        this->value |= value.value;
        return *this;
      }

      Byte& operator ^=(const Byte& value) {
        this->value ^= value.value;
        return *this;
      }

      Byte& operator <<=(const Byte& value) {
        this->value <<= value.value;
        return *this;
      }

      Byte& operator >>=(const Byte& value) {
        this->value >>= value.value;
        return *this;
      }

      Byte& operator ++() {
        ++this->value;
        return *this;
      }

      const Byte operator ++(int) {
        return this->value++;
      }

      Byte& operator --() {
        --this->value;
        return *this;
      }

      const Byte operator --(int) {
        return this->value--;
      }
      /// @endcond
    };
  }
}

using namespace Pcf;
