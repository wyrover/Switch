#include <limits>
#include "../../../Includes/Pcf/System/UInt64.h"
#include "../../../Includes/Pcf/System/Byte.h"
#include "../../../Includes/Pcf/System/Char.h"
#include "../../../Includes/Pcf/System/DateTime.h"
#include "../../../Includes/Pcf/System/DivideByZeroException.h"
#include "../../../Includes/Pcf/System/Int16.h"
#include "../../../Includes/Pcf/System/UInt16.h"
#include "../../../Includes/Pcf/System/UInt32.h"
#include "../../../Includes/Pcf/System/NumericalFormat.h"
#include "../../../Includes/Pcf/System/NumericalParsing.h"
#include "../../../Includes/Pcf/System/SByte.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/TypeCode.h"

using namespace System;

Property<uint64, ReadOnly> UInt64::MaxValue{
  [] {return std::numeric_limits<uint64>::max();}
};

Property<uint64, ReadOnly> UInt64::MinValue{
  [] {return std::numeric_limits<uint64>::min();}
};

uint64 UInt64::Parse(const string& str) {
  return Parse(str,10);
}

uint64 UInt64::Parse(const string& str, const int32 base) {
  return NumericalParsing::ParseUnsigned(str, base);
}

bool UInt64::TryParse(const string& str, uint64& value) {
  return TryParse(str, 10, value);
}

bool UInt64::TryParse(const string& str, UInt64& value) {
  return TryParse(str, 10, value);
}

bool UInt64::TryParse(const string& str, int32 base, uint64& value) {
  try {
    value = Parse(str,base);
  } catch(const Exception&) {
    return false;
  }
  return true;
}

bool UInt64::TryParse(const string& str, int32 base, UInt64& value) {
  return TryParse(str, base, value.value);
}

int32 UInt64::GetHashCode() const {
  int32 hash = 0;

  hash += (int32)(this->value & 0x00000000FFFFFFFF);
  hash = hash ^ (int32)((this->value>>32) & 0x00000000FFFFFFFF);

  return hash;
}

string UInt64::ToString() const {
  return ToString("g", Reference<IFormatProvider>::Null());
}

string UInt64::ToString(const string& format) const {
  return ToString(format, Reference<IFormatProvider>::Null());
}

string UInt64::ToString(const string& format, const IFormatProvider&) const {
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(this->value,format);
    case 'b': return NumericalFormat::Format_B(this->value, precision);
    case 'd': return NumericalFormat::Format_D(this->value, precision);
    case 'f': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(this->value, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 20;
      return NumericalFormat::Format_G(this->value, precision, type == 'G');
    }
    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(this->value, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(this->value, precision);
    case 'x': return NumericalFormat::Format_X(this->value, precision, false,16);
    case 'X': return NumericalFormat::Format_X(this->value, precision, true,16);
  }
  return format;
}

int32 UInt64::CompareTo(const UInt64& value) const {
  if (this->value < value.value)
      return -1;

  if (this->value == value.value)
      return 0;
 
  return 1;
}

int32 UInt64::CompareTo(const IComparable& obj) const {
  if (!is<UInt64>(obj))
    return 1;

  return CompareTo((const UInt64 &)obj);
}

TypeCode UInt64::GetTypeCode() const {
  return TypeCode::UInt64;
}

bool UInt64::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte UInt64::ToByte(const IFormatProvider&) const {
  if (this->value > Byte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)this->value;
}

char32 UInt64::ToChar(const IFormatProvider&) const {
  if (this->value > Char::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return static_cast<uint32>(this->value);
}

DateTime UInt64::ToDateTime(const IFormatProvider&) const {
  if (this->value > static_cast<uint64>(DateTime::MaxValue.Ticks()))
    throw OverflowException(pcf_current_information);
  
  return DateTime((int64)this->value);
}

double UInt64::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 UInt64::ToInt16(const IFormatProvider&) const {
  if (this->value > (uint16)Int16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int16)this->value;
}

int32 UInt64::ToInt32(const IFormatProvider&) const {
  if (this->value > (uint32)Int32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int32)this->value;
}

int64 UInt64::ToInt64(const IFormatProvider&) const {
  if (this->value > (uint64)Int64::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int64)this->value;
}

uint16 UInt64::ToUInt16(const IFormatProvider&) const {
  if (this->value > (uint64)UInt16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint16)this->value;
}

uint32 UInt64::ToUInt32(const IFormatProvider&) const {
  if (this->value > UInt32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint32)this->value;
}

uint64 UInt64::ToUInt64(const IFormatProvider&) const {
  return this->value;
}

sbyte UInt64::ToSByte(const IFormatProvider&) const {
  if (this->value > (byte)SByte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)this->value;
}

float UInt64::ToSingle(const IFormatProvider&) const {
  return (float)this->value;
}

string UInt64::ToString(const IFormatProvider&) const {
  return ToString();
}

UInt64::operator uint64() const {
  return this->value;
}

UInt64& UInt64::operator =(const UInt64& value) {
  this->value = value.value;
  return *this;
}

UInt64& UInt64::operator +=(const UInt64& value) {
  this->value += value.value;
  return *this;
}

UInt64& UInt64::operator -=(const UInt64& value) {
  this->value -= value.value;
  return *this;
}

UInt64& UInt64::operator *=(const UInt64& value) {
  this->value *= value.value;
  return *this;
}

UInt64& UInt64::operator /=(const UInt64& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);

  this->value /= value.value;
  return *this;
}

UInt64& UInt64::operator %=(const UInt64& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);

  this->value %= value;
  return *this;
}

UInt64& UInt64::operator &=(const UInt64& value) {
   this->value &= value.value;
   return *this;
}

UInt64& UInt64::operator |=(const UInt64& value) {
   this->value |= value.value;
   return *this;
}

UInt64& UInt64::operator ^=(const UInt64& value) {
   this->value ^= value.value;
   return *this;
}

UInt64& UInt64::operator <<=(const UInt64& value) {
   this->value <<= value.value;
   return *this;
}

UInt64& UInt64::operator >>=(const UInt64& value) {
   this->value >>= value.value;
   return *this;
}

UInt64& UInt64::operator ++() {
  ++this->value;
  return *this;
}

const UInt64 UInt64::operator ++(int) {
  return this->value++;
}

UInt64& UInt64::operator --() {
  --this->value;
  return *this;
}

const UInt64 UInt64::operator --(int) {
  return this->value--;
}

