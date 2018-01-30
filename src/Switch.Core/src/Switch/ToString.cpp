#include "../../include/Switch/ToString.hpp"
#include "../../include/Switch/System/Byte.hpp"
#include "../../include/Switch/System/Boolean.hpp"
#include "../../include/Switch/System/Char.hpp"
#include "../../include/Switch/System/Decimal.hpp"
#include "../../include/Switch/System/Double.hpp"
#include "../../include/Switch/System/SByte.hpp"
#include "../../include/Switch/System/Int16.hpp"
#include "../../include/Switch/System/Int32.hpp"
#include "../../include/Switch/System/Int64.hpp"
#include "../../include/Switch/System/IntPtr.hpp"
#include "../../include/Switch/System/Single.hpp"
#include "../../include/Switch/System/String.hpp"
#include "../../include/Switch/System/UInt16.hpp"
#include "../../include/Switch/System/UInt32.hpp"
#include "../../include/Switch/System/UInt64.hpp"

string Switch::ToString(const void* value) {
  return System::IntPtr((intptr)value).ToString();
}

string Switch::ToString(void* value) {
  return System::IntPtr((intptr)value).ToString();
}

string Switch::ToString(const NullPtr&) {
  return "(null)";
}

string Switch::ToString(const bool& value) {
  return System::Boolean(value).ToString();
}

string Switch::ToString(const byte& value) {
  return System::Byte(value).ToString();
}

string Switch::ToString(const char& value) {
  return System::Char(value).ToString();
}

string Switch::ToString(const char16& value) {
  return System::Char(value).ToString();
}

string Switch::ToString(const char32& value) {
  return System::Char(value).ToString();
}

string Switch::ToString(const wchar& value) {
  return System::Char(value).ToString();
}

string Switch::ToString(const int16& value) {
  return System::Int16(value).ToString();
}

string Switch::ToString(const int32& value) {
  return System::Int32(value).ToString();
}

string Switch::ToString(const int64& value) {
  return System::Int64(value).ToString();
}

string Switch::ToString(const intptr& value) {
  return System::IntPtr(value).ToString();
}

string Switch::ToString(const sbyte& value) {
  return System::SByte(value).ToString();
}

string Switch::ToString(const uint16& value) {
  return System::UInt16(value).ToString();
}

string Switch::ToString(const uint32& value) {
  return System::UInt32(value).ToString();
}

string Switch::ToString(const uint64& value) {
  return System::UInt64(value).ToString();
}

string Switch::ToString(const uintptr& value) {
  return System::UIntPtr(value).ToString();
}

string Switch::ToString(const double& value) {
  return System::Double(value).ToString();
}

string Switch::ToString(const float& value) {
  return System::Single(value).ToString();
}

string Switch::ToString(const char* value) {
  return System::String(value);
}

string Switch::ToString(const char16* value) {
  return System::String(value);
}

string Switch::ToString(const char32* value) {
  return System::String(value);
}

string Switch::ToString(const wchar* value) {
  return System::String(value);
}

const string& Switch::ToString(const string& value) {
  return value;
}

