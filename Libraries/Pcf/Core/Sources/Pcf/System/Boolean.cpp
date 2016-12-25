#include "../../../Includes/Pcf/System/Boolean.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/Type.h"
#include "../../../Includes/Pcf/System/TypeCode.h"

using namespace System;

const bool Boolean::False;
const bool Boolean::True;
const String Boolean::FalseString = "False";
const String Boolean::TrueString = "True";

bool Boolean::Parse(const String& str) {
  bool value;
  if (TryParse(str, value) == false)
    throw FormatException(pcf_current_information);

  return value;
}

bool Boolean::TryParse(const String& str, bool& value) {
  String trimed  = str.TrimStart(' ').TrimEnd(' ');
  if (String::Compare(trimed, TrueString, true) != 0 && String::Compare(trimed, FalseString, true) != 0)
    return false;
  
  value = String::Compare(trimed, TrueString, true) == 0;
  return true;
}

bool Boolean::TryParse(const String& str, Boolean& value) {
  return TryParse(str, value.value);
}

bool Boolean::Equals(const ValueType& valueType) const {
  return is<Boolean>(valueType) && Equals((const Boolean&)valueType);
}

bool Boolean::Equals(const object& obj) const {
  return is<Boolean>(obj) && Equals((const Boolean&)obj);
}

String Boolean::ToString() const {
  return this->value == true ? TrueString : FalseString;
}

int32 Boolean::CompareTo(const Boolean& value) const {
  return this->value - value.value;
}

int32 Boolean::CompareTo(const IComparable& obj) const {
  if (!is<Boolean>(obj))
    return 1;

  return CompareTo(static_cast<const Boolean&>(obj));
}

TypeCode Boolean::GetTypeCode() const {
  return TypeCode::Boolean;
}

bool Boolean::ToBoolean(const IFormatProvider& provider) const {
  return this->value;
}

byte Boolean::ToByte(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

char32 Boolean::ToChar(const IFormatProvider& provider) const {
  return this->value == true ? '1' : '0';
}

DateTime Boolean::ToDateTime(const IFormatProvider& provider) const {
  return this->value == true ? DateTime::MaxValue : DateTime::MinValue;
}

double Boolean::ToDouble(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

int16 Boolean::ToInt16(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

int32 Boolean::ToInt32(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

int64 Boolean::ToInt64(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

uint16 Boolean::ToUInt16(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

uint32 Boolean::ToUInt32(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

uint64 Boolean::ToUInt64(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

sbyte Boolean::ToSByte(const IFormatProvider& provider) const {
  return this->value == true ? 1 : 0;
}

float Boolean::ToSingle(const IFormatProvider& provider) const {
  return (float)(this->value == true ? 1.0 : 0.0);
}

String Boolean::ToString(const IFormatProvider& provider) const {
  return ToString();
}

