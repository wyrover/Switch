/// @file
/// @brief Contains Pcf::System::Int16 struct.
#pragma once

#include "../Property.h"
#include "../Types.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "IFormattable.h"
#include "Object.h"
#include "_String.h"
#include "ValueType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a 16-bit signed integer.
    struct pcf_public Int16 final : public ValueType, public IComparable, public IConvertible, public IFormattable {
    public:
      /// @brief Represents the largest possible value of an Int16 32767 (0x7FFF). This field is constant.
      static Property<int16, ReadOnly> MaxValue;

      /// @brief Represents the smallest possible value of Int16 -32768 (0x8000). This field is constant.
      static Property<int16, ReadOnly> MinValue;

      /// @brief Create a new instance of struct Int16
      /// @remarks Int16 is initialized by default to 0.
      Int16() {}

       /// @brief Create a new instance of struct Int16
       /// @param value Value for the Int16.
      Int16(int16 value) : value(value) {}

      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent.
      /// @param value A String containing the value to convert.
      /// @return A 16-bit signed integer equivalent to the number contained in value.
      /// @exception ArgumentNullException The parameters value is null.
      static int16 Parse(const String& value);
      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent.
      /// @param value A String containing the value to convert.
      /// @param base The base of number to parse
      /// @return A 16-bit signed integer equivalent to the number contained in value.
      /// @exception ArgumentNullException The parameters value is null.
      static int16 Parse(const String& value, const int32 base);

      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param value A String containing the value to convert.
      /// @param retValue When this method returns, contains the 16-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& value, int16& retValue);

      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param value A String containing the value to convert.
      /// @param retValue When this method returns, contains the 16-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& value, Int16& retValue);

      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param value A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param retValue When this method returns, contains the 16-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& value, int32 base, int16& retValue);

      /// @brief Converts the specified String representation of a logical value to its 16-bit signed integer equivalent. A return value indicates whether the conversion succeeded.
      /// @param value A String containing the value to convert.
      /// @param base The base of number to parse
      /// @param retValue When this method returns, contains the 16-bit signed integer value equivalent to the number contained in str, if the conversion succeeded, or zero if the conversion failed. The conversion fails if the s parameter is null, is not in a format compliant with style, or represents a number less than MinValue or greater than MaxValue. This parameter is passed uninitialized.
      /// @return A Boolean true if value was converted successfully; otherwise, false.
      static bool TryParse(const String& value, int32 base, Int16& retValue);

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current object.
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current Int16.
      /// @return tring A String that represents the current Int16.
      String ToString() const override;

      /// @brief Returns a String that represents the current Int16 with a specified format and specified formatProvider.
      /// @param format Format-control String.
      /// @param formatProvider an IFormatProvider for specifie the format.
      /// @return tring A String that represents the current Int16.
      String ToString(const String& format, const IFormatProvider& formatProvider) const override;

      /// @brief Returns a String that represents the current Int16.
      /// @param format Format-control String.
      /// @return const String A String that represents the current Int16.
      String ToString(const String& format) const;

      /// @brief Compares this instance to a specified Int16 object and returns an indication of their relative values.
      /// @param value An Int16 object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      int32 CompareTo(const Int16& value) const;

      /// @brief Compares the current instance with another object of the same type.
      /// @param obj An object to compare with this instance.
      /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared. The return value has these meanings:
      /// Less than zero      This instance is less than value.
      /// Zero                This instance is equal to value.
      /// Greater than zero   This instance is greater than value.
      /// -or-
      /// obj is nullNothingnullptra null reference.
      int32 CompareTo(const IComparable& obj) const override;

      /// @brief Returns the TypeCode for this instance.
      /// @return TypeCode The enumerated constant that is the TypeCode of the class or value type that implements this interface.
      TypeCode GetTypeCode() const override;

    private:
      friend class Convert;
 
      virtual bool IsSigned() const override { return true; }

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

      int16 value = 0;

    public:
      /// @cond
      Int16(const Int16& value) : value(value.value) {}
      operator int16() const;
      Int16& operator =(const Int16& value);
      Int16& operator +=(const Int16& value);
      Int16& operator -=(const Int16& value);
      Int16& operator *=(const Int16& value);
      Int16& operator /=(const Int16& value);
      Int16& operator %=(const Int16& value);
      Int16& operator &=(const Int16& value);
      Int16& operator |=(const Int16& value);
      Int16& operator ^=(const Int16& value);
      Int16& operator <<=(const Int16& value);
      Int16& operator >>=(const Int16& value);
      Int16& operator ++();
      const Int16 operator ++(int);
      Int16& operator --();
      const Int16 operator --(int value);
      /// @endcond
    };
  }
}

using namespace Pcf;
