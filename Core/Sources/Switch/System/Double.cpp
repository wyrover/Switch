#include <limits>
#include "../../../Includes/Switch/System/Double.hpp"
#include "../../../Includes/Switch/System/Byte.hpp"
#include "../../../Includes/Switch/System/Char.hpp"
#include "../../../Includes/Switch/System/DateTime.hpp"
#include "../../../Includes/Switch/System/DivideByZeroException.hpp"
#include "../../../Includes/Switch/System/Int16.hpp"
#include "../../../Includes/Switch/System/Int32.hpp"
#include "../../../Includes/Switch/System/Int64.hpp"
#include "../../../Includes/Switch/System/Math.hpp"
#include "../../../Includes/Switch/System/SByte.hpp"
#include "../../../Includes/Switch/System/Single.hpp"
#include "../../../Includes/Switch/System/SystemException.hpp"
#include "../../../Includes/Switch/System/TimeSpan.hpp"
#include "../../../Includes/Switch/System/UInt16.hpp"
#include "../../../Includes/Switch/System/UInt32.hpp"
#include "../../../Includes/Switch/System/UInt64.hpp"
#include "../../../Includes/Switch/System/NumericalFormat.hpp"

using namespace System;

property<double, readonly> Double::Epsilon {
  [] {return 4.94066e-324;}
};

property<double, readonly> Double::MaxValue {
  [] {return std::numeric_limits<double>::max();}
};

property<double, readonly> Double::MinValue {
  [] {return -std::numeric_limits<double>::max();}
};

property<double, readonly> Double::NaN {
  [] {return std::numeric_limits<double>::quiet_NaN();}
};

property<double, readonly> Double::NegativeInfinity {
  [] {return -std::numeric_limits<double>::infinity();}
};

property<double, readonly> Double::PositiveInfinity {
  [] {return std::numeric_limits<double>::infinity();}
};

double Double::Parse(const String& str) {
  return atof(str.Data());
}

bool Double::Equals(const Double& value) const {
  return this->value == value;
}

bool Double::Equals(const object& obj) const {
  return is<Double>(obj) && Equals(static_cast<const Double&>(obj));
}

int32 Double::GetHashCode() const {
  return Int64(*((int64*)&this->value)).GetHashCode();
}

String Double::ToString() const {
  return ToString("G", ref<IFormatProvider>::Null());
}

String Double::ToString(const String& format) const {
  return ToString(format, ref<IFormatProvider>::Null());
}

String Double::ToString(const String& format, const IFormatProvider&) const {
  if (IsNaN(this->value))
    return "NaN";
  if (IsNegativeInfinity(this->value))
    return "-Infinity";
  if (IsPositiveInfinity(this->value))
    return "Infinity";
  
  int32 precision;
  double arg = this->value;
  char32 type = NumericalFormat::GetFormatType(format, precision);
  switch(type) {
    case 0:   return NumericalFormat::Format_Custom(arg,format);
    case 'b': throw FormatException(_current_information);
    case 'd': throw FormatException(_current_information);
    case 'e': return NumericalFormat::Format_E(this->value, precision == 0 ? 15 : precision, false);
    case 'E': return NumericalFormat::Format_E(this->value, precision == 0 ? 15 : precision, true);
    case 'f':
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_F(this->value, precision);
    case 'g':
    case 'G': {
      if (precision == 0) precision = 15;
      return NumericalFormat::Format_G(arg, precision, type == 'G');
    }
    case 'n': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_N(this->value, precision);
    case 'p': 
      if (format.Length() == 1) precision = 2;
      return NumericalFormat::Format_P(this->value, precision);
    case 'x': 
    case 'X': throw FormatException(_current_information);
  }
  return format;
}

int32 Double::CompareTo(const Double& value) const {
  if (this->value > value)
    return 1;

  if (this->value < value.value)
    return -1;
  
  return 0;
}

int32 Double::CompareTo(const IComparable& obj) const {
  if (!is<Double>(obj))
    return 1;
  
  return CompareTo(static_cast<const Double&>(obj));
}

TypeCode Double::GetTypeCode() const {
  return TypeCode::Double;
}

bool Double::ToBoolean(const IFormatProvider&) const {
  return this->value != 0;
}

byte Double::ToByte(const IFormatProvider&) const {
  if (this->value < (double)Byte::MinValue)
    throw OverflowException(_current_information);
  if (this->value > Byte::MaxValue)
    throw OverflowException(_current_information);
  return static_cast<sbyte>(Math::Round(this->value));
}

char32 Double::ToChar(const IFormatProvider&) const {
  if (this->value < Char::MinValue)
    throw OverflowException(_current_information);
  if (this->value > Char::MaxValue)
    throw OverflowException(_current_information);
  return static_cast<char>(Math::Round(this->value));
}

DateTime Double::ToDateTime(const IFormatProvider&) const {
  if (DateTime(static_cast<int64>(this->value)) < DateTime::MinValue)
    throw OverflowException(_current_information);
  if (DateTime(static_cast<int64>(this->value)) > DateTime::MaxValue)
    throw OverflowException(_current_information);
  return DateTime((int64)Math::Round(this->value));
}

double Double::ToDouble(const IFormatProvider&) const {
  return (double)this->value;
}

int16 Double::ToInt16(const IFormatProvider&) const {
  if (this->value < Int16::MinValue)
    throw OverflowException(_current_information);
  if (this->value > Int16::MaxValue)
    throw OverflowException(_current_information);
  return (int16)Math::Round(this->value);
}

int32 Double::ToInt32(const IFormatProvider&) const {
  if (this->value < Int32::MinValue)
    throw OverflowException(_current_information);
  if (this->value > Int32::MaxValue)
    throw OverflowException(_current_information);
  return (int32)Math::Round(this->value);
}

int64 Double::ToInt64(const IFormatProvider&) const {
  if (this->value < Int64::MinValue)
    throw OverflowException(_current_information);
  if (this->value > Int64::MaxValue)
    throw OverflowException(_current_information);
  return (int64)Math::Round(this->value);
}

uint16 Double::ToUInt16(const IFormatProvider&) const {
  if (this->value < UInt16::MinValue)
    throw OverflowException(_current_information);
  if (this->value > UInt16::MaxValue)
    throw OverflowException(_current_information);
  return (uint16)Math::Round(this->value);
}

uint32 Double::ToUInt32(const IFormatProvider&) const {
  if (this->value < UInt32::MinValue)
    throw OverflowException(_current_information);
  if (this->value > UInt32::MaxValue)
    throw OverflowException(_current_information);
  return (uint32)Math::Round(this->value);
}

uint64 Double::ToUInt64(const IFormatProvider&) const {
  if (this->value < UInt64::MinValue)
    throw OverflowException(_current_information);
  if (this->value > UInt64::MaxValue)
    throw OverflowException(_current_information);
  return (uint64)Math::Round(this->value);
}

sbyte Double::ToSByte(const IFormatProvider&) const {
  if (this->value < SByte::MinValue)
    throw OverflowException(_current_information);
  if (this->value > SByte::MaxValue)
    throw OverflowException(_current_information);
  return (sbyte)Math::Round(this->value);
}

float Double::ToSingle(const IFormatProvider&) const {
  if (this->value < Single::MinValue)
    throw OverflowException(_current_information);
  else if (this->value > Single::MaxValue)
    throw OverflowException(_current_information);
  return (float)this->value;
}

String Double::ToString(const IFormatProvider&) const {
  return ToString();
}

Double::operator double() const {
  return this->value;
}

Double& Double::operator =(const Double& value) {
  this->value = value.value;
  return *this;
}

Double& Double::operator +=(const Double& value) {
  this->value += value.value;
  return *this;
}

Double& Double::operator -=(const Double& value) {
  this->value -= value.value;
  return *this;
}

Double& Double::operator *=(const Double& value) {
  this->value *= value.value;
  return *this;
}

Double& Double::operator /=(const Double& value) {
  if (value == 0)
    throw DivideByZeroException(_current_information);

  this->value /= value.value;
  return *this;
}

Double& Double::operator ++() {
  ++this->value;
  return *this;
}

const Double Double::operator ++(int) {
  return this->value++;
}

Double& Double::operator --() {
  --this->value;
  return *this;
}

const Double Double::operator --(int ) {
  return this->value--;
}

