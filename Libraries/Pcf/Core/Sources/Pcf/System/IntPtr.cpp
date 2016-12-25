#include "../../../Includes/Pcf/System/IntPtr.h"
#include "../../../Includes/Pcf/System/Array.h"
#include "../../../Includes/Pcf/System/Int32.h"
#include "../../../Includes/Pcf/System/Int64.h"
#include "../../../Includes/Pcf/System/OverflowException.h"

using namespace System;

const IntPtr IntPtr::Zero;

Property<int32, ReadOnly> IntPtr::Size {
  [] {return static_cast<int32>(sizeof(void*));}
};

IntPtr::IntPtr(int32 value) {
  this->value = reinterpret_cast<void*>(value);
}

IntPtr::IntPtr(int64 value) {
  if (Size == 4 && (value < Int32::MinValue || value > Int32::MaxValue))
    throw OverflowException(pcf_current_information);

  this->value = reinterpret_cast<void*>(value);
}

IntPtr::IntPtr(void* value) {
  this->value = value;
}

bool IntPtr::Equals(const IntPtr& value) const {
  return this->value == value.value;
}

bool IntPtr::Equals(const object& obj) const {
  return is<IntPtr>(obj) && Equals(static_cast<const IntPtr&>(obj));
}

int32 IntPtr::GetHashCode() const {
  int64 handleValue = reinterpret_cast<size_t>(this->value);
  int32 hash = 0;

  hash = static_cast<int32>(handleValue & 0x00000000FFFFFFFF);
  hash = hash ^ static_cast<int32>((handleValue>>32) & 0x00000000FFFFFFFF);

  return hash;
}

int32 IntPtr::CompareTo(const IntPtr& value) const {
  return static_cast<int32>(reinterpret_cast<int64>(this->value) - reinterpret_cast<int64>(value.value));
}

int32 IntPtr::CompareTo(const IComparable& obj) const {
  if (!is<IntPtr>(obj))
    return 1;
  return CompareTo(static_cast<const IntPtr&>(obj));
}

int32 IntPtr::ToInt32() const {
  if (Size == 8 && (reinterpret_cast<int64>(this->value) < static_cast<int64>(Int32::MinValue) || reinterpret_cast<int64>(this->value) > static_cast<int64>(Int32::MaxValue)))
    throw OverflowException(pcf_current_information);

  return *((int32*)&this->value);
}

int64 IntPtr::ToInt64() const {
#if !(_WIN64 || _LP64)
  return reinterpret_cast<int32>(value);
#else
  return reinterpret_cast<int64>(value);
#endif
}

void* IntPtr::ToPointer() const {
  return this->value;
}

string IntPtr::ToString() const {
  return Int64(ToInt64()).ToString();
}

string IntPtr::ToString(const string& format) const {
  return Int64(ToInt64()).ToString(format);
}

string IntPtr::ToString(const string& format, const IFormatProvider& formatProvider) const {
  return Int64(ToInt64()).ToString(format);
}

IntPtr::operator void*() const {
  return this->value;
}

IntPtr& IntPtr::operator =(const IntPtr& value) {
  this->value = value.value;
  return *this;
}