#include "../../../Includes/Pcf/System/Hash.h"
#include "../../../Includes/Pcf/System/Byte.h"
#include "../../../Includes/Pcf/System/Boolean.h"
#include "../../../Includes/Pcf/System/Decimal.h"
#include "../../../Includes/Pcf/System/Double.h"
#include "../../../Includes/Pcf/System/SByte.h"
#include "../../../Includes/Pcf/System/Int16.h"
#include "../../../Includes/Pcf/System/Int32.h"
#include "../../../Includes/Pcf/System/Int64.h"
#include "../../../Includes/Pcf/System/IntPtr.h"
#include "../../../Includes/Pcf/System/Single.h"
#include "../../../Includes/Pcf/System/UInt16.h"
#include "../../../Includes/Pcf/System/UInt32.h"
#include "../../../Includes/Pcf/System/UInt64.h"

int32 Pcf::GetHashCode(const object& value) {
  return value.GetHashCode();
}

int32 Pcf::GetHashCode(const void* value) {
  return *((int32*)&value);
}

int32 Pcf::GetHashCode(const System::NullType&) {
  return 0;
}

int32 Pcf::GetHashCode(const bool& value) {
  return System::Boolean(value).GetHashCode();
}

int32 Pcf::GetHashCode(const sbyte& value) {
  return System::SByte(value).GetHashCode();
}

int32 Pcf::GetHashCode(const char& value) {
  return System::Char(value).GetHashCode();
}

int32 Pcf::GetHashCode(const char16& value) {
  return System::Char(value).GetHashCode();
}

int32 Pcf::GetHashCode(const char32& value) {
  return System::Char(value).GetHashCode();
}

int32 Pcf::GetHashCode(const wchar& value) {
  return System::Char(value).GetHashCode();
}

int32 Pcf::GetHashCode(const int16& value) {
  return System::Int16(value).GetHashCode();
}

int32 Pcf::GetHashCode(const int32& value) {
  return System::Int32(value).GetHashCode();
}

int32 Pcf::GetHashCode(const int64& value) {
  return System::Int64(value).GetHashCode();
}

int32 Pcf::GetHashCode(const llong& value) {
  return System::Int64(value).GetHashCode();
}

int32 Pcf::GetHashCode(const byte& value) {
  return System::Byte(value).GetHashCode();
}

int32 Pcf::GetHashCode(const uint16& value) {
  return System::UInt16(value).GetHashCode();
}

int32 Pcf::GetHashCode(const uint32& value) {
  return System::UInt32(value).GetHashCode();
}

int32 Pcf::GetHashCode(const uint64& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Pcf::GetHashCode(const ullong& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Pcf::GetHashCode(const double& value) {
  return System::Double(value).GetHashCode();
}

int32 Pcf::GetHashCode(const float& value) {
  return System::Single(value).GetHashCode();
}
