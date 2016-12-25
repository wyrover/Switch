#include "../../../Includes/Pcf/System/UIntPtr.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Int32.h"
#include "../../../Includes/Pcf/System/OverflowException.h"
#include "../../../Includes/Pcf/System/UInt32.h"
#include "../../../Includes/Pcf/System/UInt64.h"

using namespace System;

UIntPtr UIntPtr::Zero;

Property<int32, ReadOnly> UIntPtr::Size {
  [] {return static_cast<int32>(sizeof(void*));}
};

UIntPtr::UIntPtr(uint32 value) {
#if !(_WIN64 || _LP64)
  uint32 u = value;
#else
  uint64 u = value;
#endif
   this->value = reinterpret_cast<void*>(u);
}

UIntPtr::UIntPtr(uint64 value) {
  if (Size == 4 && ((int32)value < Int32::MinValue || (int32)value > Int32::MaxValue))
    throw OverflowException(pcf_current_information);

  this->value = *((void**)&value);
}

UIntPtr::UIntPtr(const void* value) {
  this->value = (void*)value;
}

bool UIntPtr::Equals(const UIntPtr& value) const {
  return this->value == value.value;
}

bool UIntPtr::Equals(const object& obj) const {
  return is<UIntPtr>(obj) && Equals(static_cast<const UIntPtr&>(obj));
}

int32 UIntPtr::GetHashCode() const {
  uint64 handleValue = reinterpret_cast<size_t>(this->value);
  int32 hash = 0;

  hash = static_cast<int32>(handleValue & 0x00000000FFFFFFFF);
  hash = hash ^ static_cast<int32>((handleValue>>32) & 0x00000000FFFFFFFF);

  return hash;
}

int32 UIntPtr::CompareTo(const UIntPtr& value) const {
  return static_cast<int32>(reinterpret_cast<int64>(this->value) - reinterpret_cast<int64>(static_cast<const UIntPtr&>(value).value));
}

int32 UIntPtr::CompareTo(const IComparable& obj) const {
  if (!is<UIntPtr>(obj))
    return 1;

  return CompareTo(static_cast<const UIntPtr&>(obj));
}

uint32 UIntPtr::ToUInt32() const {
  if (Size == 8 && reinterpret_cast<int64>(this->value) > static_cast<int64>(UInt32::MaxValue))
    throw OverflowException(pcf_current_information);

  return *((uint32*)&this->value);
}

uint64 UIntPtr::ToUInt64() const {
#if !(_WIN64 || _LP64)
  return reinterpret_cast<uint32>(this->value);
#else
  return reinterpret_cast<uint64>(this->value);
#endif
}

void* UIntPtr::ToPointer() const {
  return this->value;
}

string UIntPtr::ToString() const {
  return UInt64(ToUInt64()).ToString();
}

string UIntPtr::ToString(const string& format) const {
  return UInt64(ToUInt64()).ToString(format);
}

string UIntPtr::ToString(const string& format, const IFormatProvider& formatProvider) const {
  return UInt64(ToUInt64()).ToString(format);
}

UIntPtr::operator void*() const {
  return this->value;
}

UIntPtr& UIntPtr::operator =(const UIntPtr& value) {
  this->value = value.value;
  return *this;
}

