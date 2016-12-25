#pragma once

#include <type_traits>
#include "../Any.h"
#include "../Boxing.h"
#include "Convert.h"
#include "Enum.h"
#include "FormatProvider.h"
#include "SystemException.h"
#include "Type.h"

/// @cond
class __opaque_format_item__ {
  friend class Pcf::System::String;
#if __linux__ && _LP64
  using llint = long long int;
  using ullint = unsigned long long int;
#else
  using llint = long;
  using ullint = unsigned long;
#endif
  template <typename T, typename Bool>
  struct EnumOrOtherToAny {};
  
  template <typename T>
  struct EnumOrOtherToAny<T, std::true_type> {
    SharedPointer<object> operator()(T value) {return new System::Enum<T>(value);}
    //SharedPointer<object> operator()(T value);
  };
  
  template <typename T>
  struct EnumOrOtherToAny<T, std::false_type> {
    SharedPointer<object> operator()(T value) {return new System::IntPtr(*((int64**)&value));}
  };
  
  template <typename T, typename Bool>
  struct ObjectOrOtherToAny {};
  
  template <typename T>
  struct ObjectOrOtherToAny<T, std::true_type> {
    SharedPointer<object> operator()(T value) {return new T(value);}
  };
  
  template <typename T>
  struct ObjectOrOtherToAny<T, std::false_type> {
    SharedPointer<object> operator()(T value) {return EnumOrOtherToAny<T, typename std::conditional<std::is_enum<T>::value, std::true_type, std::false_type>::type>()(value);}
  };
  
  template <typename T>
  struct ObjectOrEnumOrOtherToAny {
    SharedPointer<object> operator()(T value) {return ObjectOrOtherToAny<T, typename std::conditional<std::is_base_of<object, T>::value, std::true_type, std::false_type>::type>()(value);}
  };
  
public:
  __opaque_format_item__() {}
  __opaque_format_item__(const __opaque_format_item__& any) : value(any.value) {}
  __opaque_format_item__& operator=(const __opaque_format_item__& any) {
    this->value = any.value;
    return *this;
  }
  bool operator==(const __opaque_format_item__& any) const {return value == any.value;}
  bool operator!=(const __opaque_format_item__& any) const {return value != any.value;}
 
private:
  __opaque_format_item__(byte value) : value(new System::Byte(value)) {}
  __opaque_format_item__(char value) : value(new System::Char(value)) {}
  __opaque_format_item__(wchar value) : value(new System::Char(value)) {}
  __opaque_format_item__(char16 value) : value(new System::Char(value)) {}
  __opaque_format_item__(char32 value) : value(new System::Char(value)) {}
  __opaque_format_item__(double value) : value(new System::Double(value)) {}
  __opaque_format_item__(int16 value) : value(new System::Int16(value)) {}
  __opaque_format_item__(int32 value) : value(new System::Int32(value)) {}
  __opaque_format_item__(int64 value) : value(new System::Int64(value)) {}
  __opaque_format_item__(bool value) : value(new System::Boolean(value)) {}
  __opaque_format_item__(const char* value) : value(new System::String(value)) {}
  __opaque_format_item__(char* value) : value(new System::String(value)) {}
  __opaque_format_item__(const unsigned char* value) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(unsigned char* value) : value(new System::String((const char*)value)) {}
  __opaque_format_item__(const wchar* value) : value(new System::String(value)) {}
  __opaque_format_item__(wchar* value) : value(new System::String(value)) {}
  __opaque_format_item__(const char16* value) : value(new System::String(value)) {}
  __opaque_format_item__(char16* value) : value(new System::String(value)) {}
  __opaque_format_item__(const char32* value) : value(new System::String(value)) {}
  __opaque_format_item__(char32* value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::string& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::wstring& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u16string& value) : value(new System::String(value)) {}
  __opaque_format_item__(const std::u32string& value) : value(new System::String(value)) {}
  __opaque_format_item__(sbyte value) : value(new System::SByte(value)) {}
  __opaque_format_item__(float value) : value(new System::Single(value)) {}
  __opaque_format_item__(uint16 value) : value(new System::UInt16(value)) {}
  __opaque_format_item__(uint32 value) : value(new System::UInt32(value)) {}
  __opaque_format_item__(uint64 value) : value(new System::UInt64(value)) {}
  __opaque_format_item__(void* value) : value(new System::IntPtr(value)) {}
  __opaque_format_item__(llint value) : value(sizeof(long) == 8 ? (object*)new System::Int64(value) : (object*)new System::Int32(value)) {}
  __opaque_format_item__(ullint value) : value(sizeof(long) == 8 ? (object*)new System::UInt64(value) : (object*)new System::UInt32(value)) {}
  __opaque_format_item__(Any value) : value(new Any(value)) {}
  template<typename T, typename Attribute>
  __opaque_format_item__(const Property<T, Attribute>& value) : __opaque_format_item__(value()) {}
  template<typename T>
  __opaque_format_item__(T value) : value(ObjectOrEnumOrOtherToAny<T>()(value)) {}
  
  const object& operator*() const {return *this->value;}
  object& operator*() {return *this->value;}
  const object& ToObject() const {return *this->value;}
  
private:
  SharedPointer<object> value;
};
/// @cond

template<typename T>
System::String System::String::Concat(const System::Collections::Generic::IEnumerable<T>& objs) {
  int32 size = 0;;
  for (T item : objs)
    size += static_cast<int32>(System::Convert::ToString(item).string.length());
  
  StringType str;
  str.reserve(size);
  for (T item : objs)
    str.append(System::Convert::ToString(item).string);
  return str.c_str();
}

template<typename T, int32 length>
System::String System::String::Concat(const T (&objs)[length]) {
  if (objs == null)
    throw ArgumentNullException(pcf_current_information);

  int32 size = 0;
  for (int32 i = 0; i < length; i ++)
    size += System::Convert::ToString(objs[i]).string.length();

  StringType str;
  str.reserve(size);
  for (int32 i = 0; i < length; i ++)
    str.append(System::Convert::ToString(objs[i]).string);
  return str.c_str();
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Array<T>& objs) {
  System::String str;
  bool first = true;
  for (int32 i = 0; i < objs.Length; i++) {
    if (first)
      first = false;
    else
      str += separator;
    str += System::Convert::ToString(objs[i]);
  }
  return str;
}

template<typename T>
System::String System::String::Join(const System::String& separator, const System::Collections::Generic::IEnumerable<T>& objs) {
  System::String str;
  bool first = true;
  System::Collections::Generic::Enumerator<T> enumerator = objs.GetEnumerator();
  while (enumerator.MoveNext()) {
    if (!first)
      str += separator;
    str += System::Convert::ToString(enumerator.Current);
    first = false;
  }
  return str;
}

template<typename T, int32 len>
System::String System::String::Join(const System::String& separator, const T (&objs)[len]) {
  System::String str;
  bool first = true;
 
  for(int32 i = 0; i < len; i++) {
    if (first)
      first = false;
    else
      str += separator;
    str += System::Convert::ToString(objs[i]);
  }
  return str;
}

template<typename ...Args>
System::String System::String::Format(const System::String& format, Args&&... args) {
  return System::String::FormatToString(System::FormatProvider(), format, System::Array<__opaque_format_item__> {args...});
}

template<typename ...Args>
System::String System::String::Format(const IFormatProvider& provider, const System::String& format, Args&&... args) {
  return System::String::FormatToString(provider, format, System::Array<__opaque_format_item__> {args...});
}

using namespace Pcf;
