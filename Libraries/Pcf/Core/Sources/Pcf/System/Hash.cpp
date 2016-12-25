#include "../../../Includes/Pcf/System/Hash.h"
#include "../../../Includes/Pcf/System/Byte.h"
#include "../../../Includes/Pcf/System/Boolean.h"
#include "../../../Includes/Pcf/System/Decimal.h"
#include "../../../Includes/Pcf/System/Double.h"
#include "../../../Includes/Pcf/System/SByte.h"
#include "../../../Includes/Pcf/System/Int16.h"
#include "../../../Includes/Pcf/System/Int32.h"
#include "../../../Includes/Pcf/System/Int64.h"
#include "../../../Includes/Pcf/System/Single.h"
#include "../../../Includes/Pcf/System/UInt16.h"
#include "../../../Includes/Pcf/System/UInt32.h"
#include "../../../Includes/Pcf/System/UInt64.h"

using namespace System;

int32 System::Hash::GetHashCode(const IHashable& value) {
  return value.GetHashCode();
}

int32 System::Hash::GetHashCode(const void* value) {
  return *((int32*)&value);
}

int32 System::Hash::GetHashCode(const NullType&) {
  return 0;
}

int32 System::Hash::GetHashCode(const bool& value) {
  return System::Boolean(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const sbyte& value) {
  return System::SByte(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const int16& value) {
  return System::Int16(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const int32& value) {
  return System::Int32(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const int64& value) {
  return System::Int64(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const byte& value) {
  return System::Byte(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const uint16& value) {
  return System::UInt16(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const uint32& value) {
  return System::UInt32(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const uint64& value) {
  return System::UInt64(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const double& value) {
  return System::Double(value).GetHashCode();
}

int32 System::Hash::GetHashCode(const float& value) {
  return System::Single(value).GetHashCode();
}
