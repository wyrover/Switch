#include "../../Includes/Switch/Hash.hpp"
#include "../../Includes/Switch/System/Byte.hpp"
#include "../../Includes/Switch/System/Boolean.hpp"
#include "../../Includes/Switch/System/Decimal.hpp"
#include "../../Includes/Switch/System/Double.hpp"
#include "../../Includes/Switch/System/SByte.hpp"
#include "../../Includes/Switch/System/Int16.hpp"
#include "../../Includes/Switch/System/Int32.hpp"
#include "../../Includes/Switch/System/Int64.hpp"
#include "../../Includes/Switch/System/IntPtr.hpp"
#include "../../Includes/Switch/System/Single.hpp"
#include "../../Includes/Switch/System/UInt16.hpp"
#include "../../Includes/Switch/System/UInt32.hpp"
#include "../../Includes/Switch/System/UInt64.hpp"

int32 Switch::GetHashCode(const object& value) {
  return value.GetHashCode();
}

int32 Switch::GetHashCode(const void* value) {
  return *((int32*)&value);
}

int32 Switch::GetHashCode(const NullPtr&) {
  return 0;
}

int32 Switch::GetHashCode(const bool& value) {
  return System::Boolean(value).GetHashCode();
}

int32 Switch::GetHashCode(const sbyte& value) {
  return System::SByte(value).GetHashCode();
}

int32 Switch::GetHashCode(const char& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const char16& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const char32& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const wchar& value) {
  return System::Char(value).GetHashCode();
}

int32 Switch::GetHashCode(const int16& value) {
  return System::Int16(value).GetHashCode();
}

int32 Switch::GetHashCode(const int32& value) {
  return System::Int32(value).GetHashCode();
}

int32 Switch::GetHashCode(const int64& value) {
  return System::Int64(value).GetHashCode();
}

int32 Switch::GetHashCode(const llong& value) {
  return System::Int64(value).GetHashCode();
}

int32 Switch::GetHashCode(const byte& value) {
  return System::Byte(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint16& value) {
  return System::UInt16(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint32& value) {
  return System::UInt32(value).GetHashCode();
}

int32 Switch::GetHashCode(const uint64& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Switch::GetHashCode(const ullong& value) {
  return System::UInt64(value).GetHashCode();
}

int32 Switch::GetHashCode(const double& value) {
  return System::Double(value).GetHashCode();
}

int32 Switch::GetHashCode(const float& value) {
  return System::Single(value).GetHashCode();
}
