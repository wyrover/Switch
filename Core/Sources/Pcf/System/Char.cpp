#include <cstdio>
#include <cwchar>
#include <cwctype>

#include "../../../Includes/Pcf/System/Char.h"
#include "../../../Includes/Pcf/System/Byte.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/InvalidCastException.h"
#include "../../../Includes/Pcf/System/OverflowException.h"
#include "../../../Includes/Pcf/System/SByte.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/TypeCode.h"
#include "../../__OS/CoreApi.h"

using namespace System;

Property<char32, ReadOnly> Char::MaxValue {
  [] {return 0x0010FFFFu;}
};

Property<char32, ReadOnly> Char::MinValue = {
  [] {return 0;}
};

bool Char::IsControl(char32 value) {
  return iscntrl(value) != 0;
}

bool Char::IsControl(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);

  return Char::IsControl(value[index]);
}

bool Char::IsDigit(char32 value) {
  return __OS::CoreApi::UnicodeCharacters::IsDigit(value);
}

bool Char::IsDigit(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsDigit(value[index]);
}

bool Char::IsLetter(char32 value) {
  return __OS::CoreApi::UnicodeCharacters::IsAlpha(value);
}

bool Char::IsLetter(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsLetter(value[index]);
}

bool Char::IsLetterOrDigit(char32 value) {
  return IsLetter(value) || IsDigit(value);
}

bool Char::IsLetterOrDigit(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsLetterOrDigit(value[index]);
}

bool Char::IsLower(char32 value) {
  return __OS::CoreApi::UnicodeEncodings::to_lower(value) == value;
}

bool Char::IsLower(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsLower(value[index]);
}

bool Char::IsPunctuation(char32 value) {
  return __OS::CoreApi::UnicodeCharacters::IsPunctuation(value);
}

bool Char::IsPunctuation(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsPunctuation(value[index]);
}

bool Char::IsSeparator(char32 value) {
  return isspace(value) || value == '\n';
}

bool Char::IsSeparator(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsSeparator(value[index]);
}

bool Char::IsSymbol(char32 value) {
  return (value == '+' || value == '-' || value == '*' || value == '/' || value == '%' || value == '$' || value == 0x9C);
}

bool Char::IsSymbol(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsSymbol(value[index]);
}

bool Char::IsUpper(char32 value) {
  return __OS::CoreApi::UnicodeEncodings::to_upper(value) == value;
}

bool Char::IsUpper(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsUpper(value[index]);
}

bool Char::IsWhiteSpace(char32 value) {
  return isspace(value) != 0;
}

bool Char::IsWhiteSpace(const String& value, int32 index) {
  if (index >= value.Length())
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Char::IsWhiteSpace(value[index]);
}

char32 Char::Parse(const String& value) {
  if (value.Length() != 1)
    throw FormatException(pcf_current_information);

  return value[0];
}

char32 Char::ToLower(char32 value) {
  return (char)tolower(value);
}

char32 Char::ToUpper(char32 value) {
  return (char)toupper(value);
}

bool Char::Equals(const Char& value) const {
  return this->value == value.value;
}

bool Char::Equals(const ValueType& valueType) const {
  return is<Char>(valueType) && Equals((const Char&)valueType);
}

bool Char::Equals(const object& obj) const {
  return is<Char>(obj) && Equals((const Char&)obj);
}

int32 Char::GetHashCode() const {
  return this->value;
}

String Char::ToString() const { 
  byte bytes[5];
  int32 count = __OS::CoreApi::UnicodeEncodings::UTF8::Encode(this->value, bytes);
  bytes[count] = 0;
  return String((char*)bytes);
}

int32 Char::CompareTo(const Char& value) const {
  return this->value - value.value;
}

int32 Char::CompareTo(const IComparable& obj) const {
  if (!is<Char>(obj))
    return 1;
  
  return CompareTo(static_cast<const Char&>(obj));
}

TypeCode Char::GetTypeCode() const {
  return TypeCode::Char;
}

bool Char::ToBoolean(const IFormatProvider& provider) const {
  throw InvalidCastException(pcf_current_information);
}

byte Char::ToByte(const IFormatProvider& provider) const {
  if (this->value > Byte::MaxValue)
    throw OverflowException(pcf_current_information);
  return static_cast<byte>(this->value);
}

char32 Char::ToChar(const IFormatProvider& provider) const {
  return this->value;
}

DateTime Char::ToDateTime(const IFormatProvider& provider) const {
  return DateTime(this->value);
}

double Char::ToDouble(const IFormatProvider& provider) const {
  return static_cast<double>(this->value);
}

int16 Char::ToInt16(const IFormatProvider& provider) const {
  return static_cast<int16>(this->value);
}

int32 Char::ToInt32(const IFormatProvider& provider) const {
  return this->value;
}

int64 Char::ToInt64(const IFormatProvider& provider) const {
  return this->value;
}

uint16 Char::ToUInt16(const IFormatProvider& provider) const {
  return static_cast<uint16>(this->value);
}

uint32 Char::ToUInt32(const IFormatProvider& provider) const {
  return this->value;
}
 
uint64 Char::ToUInt64(const IFormatProvider& provider) const {
  return this->value;
}

sbyte Char::ToSByte(const IFormatProvider& provider) const {
  if (this->value > static_cast<uint32>(SByte::MaxValue)) // MaxValue has to be positive...
    throw OverflowException(pcf_current_information);
  return static_cast<sbyte>(this->value);
}

float Char::ToSingle(const IFormatProvider& provider) const {
  return static_cast<float>(this->value);
}

String Char::ToString(const IFormatProvider& provider) const {
  return ToString();
}

