#include "../../../Includes/Pcf/System/Byte.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/DivideByZeroException.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/TypeCode.h"
#include "../../../Includes/Pcf/System/NumericalFormat.h"
#include "../../../Includes/Pcf/System/NumericalParsing.h"

using namespace System;

#if !_WIN32
constexpr byte Byte::MaxValue;
constexpr byte Byte::MinValue;
#endif

byte Byte::Parse(const String& str) {
  return Parse(str, 10);
}

byte Byte::Parse(const String& str, const int32 base) {
  uint64 value = NumericalParsing::ParseUnsigned(str,base);
  return Convert::ToByte(value);
}

bool Byte::TryParse(const String& str, byte& retValue) {
  return TryParse(str, 10, retValue);
}

bool Byte::TryParse(const String& str, Byte& retValue) {
  return TryParse(str, 10, retValue);
}

bool Byte::TryParse(const String& str, int32 base, byte& value) {
  try {
    value = Parse(str, base);
  } catch(const Exception&) {
    return false;
  }
  return true;
}

bool Byte::TryParse(const String& str, int32 base, Byte& value) {
  try {
    value = Parse(str, base);
  } catch(const Exception&) {
    return false;
  }
  return true;
}

int32 Byte::GetHashCode() const {
  return this->value;
}

String Byte::ToString() const {
  return ToString("g", Reference<IFormatProvider>::Null());
}

String Byte::ToString(const String& format) const {
  return ToString(format, Reference<IFormatProvider>::Null());
}

String Byte::ToString(const String& format, const IFormatProvider&) const {
  uint64 arg = Convert::ToUInt64(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(arg,format);
    case 'b': return NumericalFormat::Format_B(arg, precision);
    case 'd': return NumericalFormat::Format_D(arg, precision);
    case 'f': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(arg, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 3;
      return NumericalFormat::Format_G(arg, precision, type == 'G');
    }
    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(arg, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(arg, precision);
    case 'x': return NumericalFormat::Format_X(arg, precision, false, 2);
    case 'X': return NumericalFormat::Format_X(arg, precision, true,  2);
  }
  return format;
}

int32 Byte::CompareTo(const Byte& value) const {
  return this->value - value.value;
}

int32 Byte::CompareTo(const IComparable& obj) const {
  if (!is<Byte>(obj))
    return 1;
  
  return CompareTo(static_cast<const Byte&>(obj));
}

TypeCode Byte::GetTypeCode() const {
  return TypeCode::Byte;
}

bool Byte::ToBoolean(const IFormatProvider& provider) const {
  return this->value != 0;
}

byte Byte::ToByte(const IFormatProvider& provider) const {
  return this->value;
}

char32 Byte::ToChar(const IFormatProvider& provider) const {
  return this->value;
}

DateTime Byte::ToDateTime(const IFormatProvider& provider) const {
  return DateTime(this->value);
}

double Byte::ToDouble(const IFormatProvider& provider) const {
  return this->value;
}

int16 Byte::ToInt16(const IFormatProvider& provider) const {
  return this->value;
}

int32 Byte::ToInt32(const IFormatProvider& provider) const {
  return this->value;
}

int64 Byte::ToInt64(const IFormatProvider& provider) const {
  return this->value;
}

uint16 Byte::ToUInt16(const IFormatProvider& provider) const {
  return this->value;
}

uint32 Byte::ToUInt32(const IFormatProvider& provider) const {
  return this->value;
}

uint64 Byte::ToUInt64(const IFormatProvider& provider) const {
  return this->value;
}

sbyte Byte::ToSByte(const IFormatProvider& provider) const {
  if (this->value > SByte::MaxValue)
    throw OverflowException(pcf_current_information);
  return this->value;
}

float Byte::ToSingle(const IFormatProvider& provider) const {
  return this->value;
}

String Byte::ToString(const IFormatProvider& provider) const {
  return ToString();
}

Byte& Byte::operator /=(const Byte& value) {
  if (value.value == 0)
    throw DivideByZeroException(pcf_current_information);

  this->value /= value.value;
  return *this;
}

Byte& Byte::operator %=(const Byte& value) {
  if (value.value == 0)
    throw DivideByZeroException(pcf_current_information);
  
  this->value %= value.value;
  return *this;
}


