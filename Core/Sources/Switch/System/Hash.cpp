#include "../../../Includes/Pcf/System/Hash.hpp"
#include "../../../Includes/Pcf/System/Byte.hpp"
#include "../../../Includes/Pcf/System/Boolean.hpp"
#include "../../../Includes/Pcf/System/Decimal.hpp"
#include "../../../Includes/Pcf/System/Double.hpp"
#include "../../../Includes/Pcf/System/SByte.hpp"
#include "../../../Includes/Pcf/System/Int16.hpp"
#include "../../../Includes/Pcf/System/Int32.hpp"
#include "../../../Includes/Pcf/System/Int64.hpp"
#include "../../../Includes/Pcf/System/IntPtr.hpp"
#include "../../../Includes/Pcf/System/Single.hpp"
#include "../../../Includes/Pcf/System/UInt16.hpp"
#include "../../../Includes/Pcf/System/UInt32.hpp"
#include "../../../Includes/Pcf/System/UInt64.hpp"

int32 Pcf::GetHashCode(const object& value) {
  return value.GetHashCode();
}

int32 Pcf::GetHashCode(const void* value) {
  return *((int32*)&value);
}

int32 Pcf::GetHashCode(const NullPtr&) {
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
