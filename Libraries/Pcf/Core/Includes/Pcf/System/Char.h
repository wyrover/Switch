/// @file
/// @brief Contains Pcf::System::Char struct.
#pragma once

#include "../Property.h"
#include "IComparable.h"
#include "IConvertible.h"
#include "Object.h"
#include "_String.h"
#include "ValueType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents a Unicode Character.
    struct pcf_public Char : public ValueType, public IComparable, public IConvertible {
      
    public:
      /// @brief Create a new instance of struct Char
      /// @remarks Char is initialized by default with character 0.
      Char() { }

      /// @brief Create a new instance of struct Char
      /// @param value Value for the Char.
      Char(char32 value) : value(value) { }

      /// @brief Represents the largest possible value of an Char (code point 0x0010FFFFu). This field is constant.
      static Property<char32, ReadOnly> MaxValue;
      
      /// @brief Represents the smallest possible value of Char 0 (0). This field is constant.
      static Property<char32, ReadOnly> MinValue;
      
      /// @brief Indicates whether the specified Unicode character is categorized as a control character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a control character; otherwise, false.
      static bool IsControl(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a control character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a control character; otherwise, false.
      static bool IsControl(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a digit character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a digit character; otherwise, false.
      static bool IsDigit(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a digit character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a digit character; otherwise, false.
      static bool IsDigit(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a letter character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a letter character; otherwise, false.
      static bool IsLetter(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a letter character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a letter character; otherwise, false.
      static bool IsLetter(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a letter or digit character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a letter or digit character; otherwise, false.
      static bool IsLetterOrDigit(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a letter or digit character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a letter or digit character; otherwise, false.
      static bool IsLetterOrDigit(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a lowercase letter character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a lowercase letter character; otherwise, false.
      static bool IsLower(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a lowercase letter character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a lowercase letter character; otherwise, false.
      static bool IsLower(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a punctuation character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a punctuation character; otherwise, false.
      static bool IsPunctuation(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a punctuation character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a punctuation character; otherwise, false.
      static bool IsPunctuation(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a separator character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a separator character; otherwise, false.
      static bool IsSeparator(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a separator character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a separator character; otherwise, false.
      static bool IsSeparator(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a symbol character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a symbol character; otherwise, false.
      static bool IsSymbol(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a symbol character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a symbol character; otherwise, false.
      static bool IsSymbol(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as an uppercase letter character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is an uppercase letter character; otherwise, false.
      static bool IsUpper(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as an uppercase letter character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is an uppercase letter character; otherwise, false.
      static bool IsUpper(const String& value, int32 index);

      /// @brief Indicates whether the specified Unicode character is categorized as a white Space character.
      /// @param value A Unicode character.
      /// @return Boolean true if value is a white space character; otherwise, false.
      static bool IsWhiteSpace(char32 value);

      /// @brief Indicates whether the character at the specified position in a specified String is categorized as a white space character.
      /// @param value A String.
      /// @param index The character position in value.
      /// @return Boolean true if the character at position index in value is a white space character; otherwise, false.
      static bool IsWhiteSpace(const String& value, int32 index);

      /// @brief Converts the specified String representation of a logical value to its 8-bit unsigned integer equivalent.
      /// @param s A String containing the value to convert.
      /// @return A 8-bit unsigned integer equivalent to the number contained in value.
      /// @exception ArgumentNullException The parameters value is null.
      /// @exception ArgumentException String must be exactly one character long.
      static char32 Parse(const String& s);

      /// @brief Converts the value of the specified String to its equivalent Unicode character. A return code indicates whether the conversion succeeded or failed.
      /// @param s A String that contains a single character, or null.
      /// @param result When this method returns, contains a Unicode character equivalent to the sole character in s, if the conversion succeeded, or an undefined value if the conversion failed. The conversion fails if the s parameter is null or the length of s is not 1. This parameter is passed uninitialized.
      /// @return true if the s parameter was converted successfully; otherwise, false.
      /// @remarks The TryParse method is like the Parse method, except the TryParse method does not throw an exception if the conversion fails.
      static bool TryParse(const String& s, char32& result);

      /// @brief Converts the value of the specified String to its equivalent Unicode character. A return code indicates whether the conversion succeeded or failed.
      /// @param s A String that contains a single character, or null.
      /// @param result When this method returns, contains a Unicode character equivalent to the sole character in s, if the conversion succeeded, or an undefined value if the conversion failed. The conversion fails if the s parameter is null or the length of s is not 1. This parameter is passed uninitialized.
      /// @return true if the s parameter was converted successfully; otherwise, false.
      /// @remarks The TryParse method is like the Parse method, except the TryParse method does not throw an exception if the conversion fails.
      static bool TryParse(const String& s, Char& result);

      /// @brief Converts the value of a Unicode character to its lowercase equivalent.
      /// @param value A Unicode character.
      /// @return Char The lowercase equivalent of value, or the unchanged value of value, if value is already lowercase or not alphabetic.
      static char32 ToLower(char32 value);

      /// @brief Converts the value of a Unicode character to its uppercase equivalent.
      /// @param value A Unicode character.
      /// @return Char The uppercase equivalent of value, or the unchanged value of value, if value is already lowercase or not alphabetic.
      static char32 ToUpper(char32 value);

      /// @brief Determines whether this instance of Char and a specified Object, which must also be a Char Object, have the same value.
      /// @param value The Char to compare with the current Object.
      /// @return Boolean true if the specified value is equal to the current Object. otherwise, false.
      /// @exception ArgumentNullException The parameters value is null.
      bool Equals(const Char& value) const;

      /// @brief Determines whether this instance of ValueType and a specified Object, which must also be a ValueType Object, have the same value.
      /// @param valueType The ValueType to compare with the current Object.
      /// @return bool true if the specified ValueType is equal to the current ValueType. otherwise, false.
      bool Equals(const ValueType& valueType) const override;

      /// @brief Determines whether this instance of Char and a specified Object, which must also be a Char Object, have the same value.
      /// @param obj The Object to compare with the current Object.
      /// @return Boolean true if the specified Object is equal to the current Object. otherwise, false.
      /// @exception ArgumentNullException The parameters obj is null.
      bool Equals(const Object& obj) const override;

      /// @brief Serves as a hash function for a particular type.
      /// @return Int32 A hash code for the current Object.
      /// @see Object
      int32 GetHashCode() const override;

      /// @brief Returns a String that represents the current Char.
      /// @return String A String that represents the current Char.
      String ToString() const override;

      /// @brief Compares this instance to a specified Char Object and returns an indication of their relative values.
      /// @param value An Char Object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// | result            | Condition                                                                   |
      /// |-------------------|-----------------------------------------------------------------------------|
      /// | Less than zero    | This instance is false and value is true.                                   |
      /// | Zero              | This instance and value are equal (either both are true or both are false). |
      /// | Greater than zero | This instance is true and value is false.  -or- value is null reference.    |
      int32 CompareTo(const Char& value) const;

      /// @brief Compares the current instance with another Object of the same type.
      /// @param obj An Object to compare with this instance.
      /// @return Int32 A 32-bit signed integer that indicates the relative order of the Objects being compared. The return value has these meanings:
      /// | result            | Condition                                                                 |
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
      /// @endcond
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

      char32 value = 0;

    public:
      /// @cond
      Char(const Char& value) : value(value.value) {}
      Char& operator =(const Char& value) {this->value= value.value; return *this;}
      //uint32 GetCode() const { return value; }
      char ToCChar() const { return static_cast<char>(this->value); }

      operator const char32() const { return this->value; }

      Char& operator++() {
        ++this->value;
        return *this;
      }

      const Char operator++(int) { return this->value++; }

      Char& operator--() {
        --this->value;
        return *this;
      }

      const Char operator--(int) { return this->value--; }
      /// @endcond
    };
  }
}

using namespace Pcf;
