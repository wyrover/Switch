#include "../../../Includes/Pcf/System/BitConverter.h"
#include "../../../Includes/Pcf/System/Convert.h"
#include "../../../Includes/Pcf/System/String.h"
#include "../../../Includes/Pcf/System/SystemException.h"
#include "../../../Includes/Pcf/System/Text/StringBuilder.h"

using namespace System;
using namespace System::Text;

Property<bool, ReadOnly> BitConverter::IsLittleEndian {
  [] {
    int32 endian = 1;
    return *(sbyte *)&endian == 1;
  }
};

int64 BitConverter::DoubleToInt64Bits(double value) {
  return *((int64*)&value);
}

Array<byte> BitConverter::GetBytes(Boolean value) {
  return {Convert::ToByte(value)};
}

Array<byte> BitConverter::GetBytes(Char value) {
  return GetBytes(((char32)value));
}

Array<byte> BitConverter::GetBytes(double value) {
  return GetBytes(DoubleToInt64Bits(value));
}

Array<byte> BitConverter::GetBytes(int16 value) {
  return GetBytes(uint16(value));
}

Array<byte> BitConverter::GetBytes(int32 value) {
  return GetBytes(uint32(value));
}

Array<byte> BitConverter::GetBytes(int64 value) {
  return GetBytes(uint64(value));
}

Array<byte> BitConverter::GetBytes(float value) {
  return GetBytes(SingleToInt32Bits(value));
}

Array<byte> BitConverter::GetBytes(uint16 value) {
  return {Convert::ToByte(value&0x00FF), Convert::ToByte((value&0xFF00)>> 8)};
}

Array<byte> BitConverter::GetBytes(uint32 value) {
  return {Convert::ToByte(value&0x000000FF), Convert::ToByte((value&0x0000FF00)>> 8), Convert::ToByte((value&0x00FF0000)>> 16), Convert::ToByte((value&0xFF000000)>> 24)};
}

Array<byte> BitConverter::GetBytes(uint64 value) {
  return {Convert::ToByte(value&0x00000000000000FF), Convert::ToByte((value&0x000000000000FF00)>> 8), Convert::ToByte((value&0x0000000000FF0000)>> 16), Convert::ToByte((value&0x00000000FF000000)>> 24), Convert::ToByte((value&0x000000FF00000000)>> 32), Convert::ToByte((value&0x0000FF0000000000)>> 40), Convert::ToByte((value&0x00FF000000000000)>> 48), Convert::ToByte((value&0xFF00000000000000)>> 56)};
}

Array<byte> BitConverter::GetBytes(llong value) {
  return GetBytes(uint32(value));
}

Array<byte> BitConverter::GetBytes(ullong value) {
  return GetBytes(uint32(value));
}

float BitConverter::Int32BitsToSingle(int32 value) {
  return *((float*)&value);
}

double BitConverter::Int64BitsToDouble(int64 value) {
  return *((double*)&value);
}

int32 BitConverter::SingleToInt32Bits(float value) {
  return *((int32*)&value);
}

bool BitConverter::ToBoolean(const Array<byte>& value, int32 startIndex) {
  if (startIndex < 0 || startIndex >= value.Length)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Convert::ToBoolean(value[startIndex]);
}

char32 BitConverter::ToChar(const Array<byte>& value, int32 startIndex) {
  return char32(ToUInt32(value, startIndex));
}

double BitConverter::ToDouble(const Array<byte>& value, int32 startIndex) {
  return Int64BitsToDouble(ToInt64(value, startIndex));
}

int16 BitConverter::ToInt16(const Array<byte>& value, int32 startIndex) {
  return int16(ToUInt16(value, startIndex));
}

int32 BitConverter::ToInt32(const Array<byte>& value, int32 startIndex) {
  return int32(ToUInt32(value, startIndex));
}

int64 BitConverter::ToInt64(const Array<byte>& value, int32 startIndex) {
  return int64(ToUInt64(value, startIndex));
}

float BitConverter::ToSingle(const Array<byte>& value, int32 startIndex) {
  return Int32BitsToSingle(ToInt32(value, startIndex));
}

uint16 BitConverter::ToUInt16(const Array<byte>& value, int32 startIndex) {
  if (startIndex == value.Length-1)
    throw ArgumentException(pcf_current_information);
  if (startIndex < 0 || startIndex > value.Length-1)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Convert::ToUInt16(value[startIndex]) + (Convert::ToUInt16(value[startIndex+1])<<8);
}

uint32 BitConverter::ToUInt32(const Array<byte>& value, int32 startIndex) {
  if (startIndex == value.Length-3)
    throw ArgumentException(pcf_current_information);
  if (startIndex < 0 || startIndex > value.Length-3)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Convert::ToUInt32(value[startIndex]) + (Convert::ToUInt32(value[startIndex+1])<<8) + (Convert::ToUInt32(value[startIndex+2])<<16) + (Convert::ToUInt32(value[startIndex+3])<<24);
}

uint64 BitConverter::ToUInt64(const Array<byte>& value, int32 startIndex) {
  if (startIndex == value.Length-7)
    throw ArgumentException(pcf_current_information);
  if (startIndex < 0 || startIndex > value.Length-7)
    throw ArgumentOutOfRangeException(pcf_current_information);
  
  return Convert::ToUInt64(value[startIndex]) + (Convert::ToUInt64(value[startIndex+1])<<8) + (Convert::ToUInt64(value[startIndex+2])<<16) + (Convert::ToUInt64(value[startIndex+3])<<24) + (Convert::ToUInt64(value[startIndex+4])<<32) + (Convert::ToUInt64(value[startIndex+5])<<40) + (Convert::ToUInt64(value[startIndex+6])<<48) + (Convert::ToUInt64(value[startIndex+7])<<56);
}

String BitConverter::ToString(const Array<byte>& value) {
  return ToString(value, 0, value.Length);
}

String BitConverter::ToString(const Array<byte>& value, int32 startIndex) {
  return ToString(value, startIndex, value.Length-startIndex);
}

String BitConverter::ToString(const Array<byte>& value, int32 startIndex, int32 length) {
  if (value.Length == 0 && startIndex == 0 && length == 0)
    return "";

  if (startIndex < 0 || length < 0 || startIndex >= value.Length)
    throw ArgumentOutOfRangeException(pcf_current_information);

  if (startIndex + length > value.Length)
    throw ArgumentException(pcf_current_information);
  
  StringBuilder str((startIndex + length)*3) ;
  for (int32 index = startIndex; index < startIndex + length; index++) {
    str.Append(Byte(value[index]).ToString("X2")).Append(index < startIndex + length-1 ? "-" : "");
  }

  return str.ToString();
}

