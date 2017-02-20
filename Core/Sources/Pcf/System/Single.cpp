#include <limits>
#include "../../../Includes/Pcf/System/Single.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/DivideByZeroException.h"
#include "../../../Includes/Pcf/System/Math.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/NumericalFormat.h"

using namespace System;

Property<float, ReadOnly> Single::Epsilon {
  [] {return 1.401298E-45F;}
};

Property<float, ReadOnly> Single::MaxValue {
  [] {return std::numeric_limits<float>::max();}
};

Property<float, ReadOnly> Single::MinValue {
  [] {return -std::numeric_limits<float>::max();}
};

Property<float, ReadOnly> Single::NaN {
  [] {return std::numeric_limits<float>::quiet_NaN();}
};

Property<float, ReadOnly> Single::NegativeInfinity {
  [] {return -std::numeric_limits<float>::infinity();}
};

Property<float, ReadOnly> Single::PositiveInfinity {
  [] {return std::numeric_limits<float>::infinity();}
};

float Single::Parse(const string& str) {
  return Convert::ToSingle(atof(str.ToCCharArray().Data()));
}

bool Single::IsInfinity(float value) {
  return (IsNegativeInfinity(value) || IsPositiveInfinity(value));
}

bool Single::IsNaN(float value) {
  return value != value;
}

bool Single::IsNegativeInfinity(float value) {
  return value == NegativeInfinity;
}

bool Single::IsPositiveInfinity(float value) {
  return value == PositiveInfinity;
}

bool Single::Equals(const Single& value) const {
  return (this->value == value.value);
}

bool Single::Equals(const object& obj) const {
  return is<Single>(obj) && Equals(static_cast<const Single&>(obj));
}

int32 Single::GetHashCode() const noexcept {
  return *((int32*)&this->value);
}

string Single::ToString() const {
  return ToString("G", Reference<IFormatProvider>::Null());
}

string Single::ToString(const string& format) const {
  return ToString(format, Reference<IFormatProvider>::Null());
}

string Single::ToString(const string& format, const IFormatProvider&) const {
  if (IsNaN(this->value))
    return "NaN";
  if (IsNegativeInfinity(this->value))
    return "-Infinity";
  if (IsPositiveInfinity(this->value))
    return "Infinity";

  double arg = Convert::ToDouble(this->value);
  int32 precision;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(arg,format);
    case 'b': throw FormatException(pcf_current_information);
    case 'd': throw FormatException(pcf_current_information);
    case 'f':
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(arg, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 7;
      return NumericalFormat::Format_G(arg, precision, type == 'G');
    }
    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(arg, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(arg, precision);
    case 'x': throw FormatException(pcf_current_information);
    case 'X': throw FormatException(pcf_current_information);
  }
  return format;
}

int32 Single::CompareTo(const Single& value) const {
  if (this->value > value.value)
    return 1;
  
  if (this->value < value.value)
   return  -1;

  return 0;
}

int32 Single::CompareTo(const IComparable& obj) const {
  if (!is<Single>(obj))
    return 1;

  return CompareTo(static_cast<const Single&>(obj));
}

TypeCode Single::GetTypeCode() const {
  return TypeCode::Single;
}

bool Single::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Single::ToByte(const IFormatProvider&) const {
  if (this->value < Byte::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Byte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)Math::Round(this->value);
}

char32 Single::ToChar(const IFormatProvider&) const {
  if (this->value < Char::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Char::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (char)Math::Round(this->value);
}

DateTime Single::ToDateTime(const IFormatProvider&) const {
  if (DateTime(static_cast<int64>(this->value)) < DateTime::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (DateTime(static_cast<int64>(this->value)) > DateTime::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return DateTime((int64)Math::Round(this->value));
}

double Single::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Single::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Int16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int16)Math::Round(this->value);
}

int32 Single::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Int32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int32)Math::Round(this->value);
}

int64 Single::ToInt64(const IFormatProvider&) const {
  if (this->value < Int64::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > Int64::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (int64)Math::Round(this->value);
}

uint16 Single::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > UInt16::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint16)Math::Round(this->value);
}

uint32 Single::ToUInt32(const IFormatProvider&) const {
  if (this->value < UInt32::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > UInt32::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint32)Math::Round(this->value);
}

uint64 Single::ToUInt64(const IFormatProvider&) const {
  if (this->value < UInt64::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > UInt64::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (uint64)Math::Round(this->value);
}

sbyte Single::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(pcf_current_information);
  
  if (this->value > SByte::MaxValue)
    throw OverflowException(pcf_current_information);
  
  return (sbyte)Math::Round(this->value);
}

float Single::ToSingle(const IFormatProvider&) const {
  return this->value;
}

string Single::ToString(const IFormatProvider&) const {
  return ToString();
}

Single::operator float() const {
  return this->value;
}

Single& Single::operator =(const Single& value) {
  this->value = value.value;
  return *this;
}

Single& Single::operator +=(const Single& value) {
  this->value += value.value;
  return *this;
}

Single& Single::operator -=(const Single& value) {
  this->value -= value.value;
  return *this;
}

Single& Single::operator*=(const Single& value) {
  this->value *= value.value;
  return *this;
}

Single& Single::operator /=(const Single& value) {
  if (value == 0)
    throw DivideByZeroException(pcf_current_information);
    
  this->value /= value.value;
  return *this;
}

Single& Single::operator++() {
  ++this->value;
  return *this;
}

const Single Single::operator++(int) {
  return this->value++;
}

Single& Single::operator--() {
  --this->value;
  return *this;
}

const Single Single::operator--(int) {
  return this->value--;
}

