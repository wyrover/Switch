/// @file
/// @brief Contains Switch::Any class.
#pragma once

#include "Boxing.hpp"
#include "RefPtr.hpp"
#include "NullPtr.hpp"
#include "Types.hpp"
#include "System/Boolean.hpp"
#include "System/Byte.hpp"
#include "System/Char.hpp"
#include "System/Double.hpp"
#include "System/Enum.hpp"
#include "System/Int16.hpp"
#include "System/Int32.hpp"
#include "System/Int64.hpp"
#include "System/IntPtr.hpp"
#include "System/InvalidCastException.hpp"
#include "System/Hash.hpp"
#include "System/SByte.hpp"
#include "System/Single.hpp"
#include "System/UInt16.hpp"
#include "System/UInt32.hpp"
#include "System/UInt64.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Examples
  /// This example show how to use Any:
  /// @include Any.cpp
  class _public Any : public System::IComparable, public object {
    template <typename T, typename Bool>
    struct EnumOrOtherToAny {};
    
    template <typename T>
    struct EnumOrOtherToAny<T, std::true_type> {
      refptr<object> operator()(T value) {return new System::Enum<T>(value);}
    };
    
    template <typename T>
    struct EnumOrOtherToAny<T, std::false_type> {
      //refptr<object> operator()(T value) {return new System::IntPtr((intptr)&value);}
      refptr<object> operator()(T value) {return new Boxer<T>(value);}
    };
    
    template <typename T, typename Bool>
    struct ObjectOrOtherToAny {};
    
    template <typename T>
    struct ObjectOrOtherToAny<T, std::true_type> {
      refptr<object> operator()(T value) {return new T(value);}
    };
    
    template <typename T>
    struct ObjectOrOtherToAny<T, std::false_type> {
      refptr<object> operator()(T value) {return EnumOrOtherToAny<T, typename std::conditional<std::is_enum<T>::value, std::true_type, std::false_type>::type>()(value);}
    };
    
    template <typename T>
    struct ObjectOrEnumOrOtherToAny {
      refptr<object> operator()(T value) {return ObjectOrOtherToAny<T, typename std::conditional<std::is_base_of<object, T>::value, std::true_type, std::false_type>::type>()(value);}
    };
    
  public:
    /// @brief Initializes a new instance of the Any class to the specified value.
    /// @param value A vlue type.
    template<typename T>
    Any(T value) : value(ObjectOrEnumOrOtherToAny<T>()(value)) {}
    
    /// @cond
    Any() {}
    Any(const Any& any) : value(any.value) {}
    Any& operator=(const Any& any) {this->value = any.value; return *this;}
    Any(NullPtr value) {}
    Any(bool value) : value(new System::Boolean(value)) {}
    Any(byte value) : value(new System::Byte(value)) {}
    Any(char value) : value(new System::Char(value)) {}
    Any(wchar value) : value(new System::Char(value)) {}
    Any(char16 value) : value(new System::Char(value)) {}
    Any(char32 value) : value(new System::Char(value)) {}
    Any(double value) : value(new System::Double(value)) {}
    Any(int16 value) : value(new System::Int16(value)) {}
    Any(int32 value) : value(new System::Int32(value)) {}
    Any(int64 value) : value(new System::Int64(value)) {}
    Any(const char* value) : value(new System::String(value)) {}
    Any(char* value) : value(new System::String(value)) {}
    Any(const unsigned char* value) : value(new System::String((const char*)value)) {}
    Any(unsigned char* value) : value(new System::String((const char*)value)) {}
    Any(const wchar* value) : value(new System::String(value)) {}
    Any(wchar* value) : value(new System::String(value)) {}
    Any(const char16* value) : value(new System::String(value)) {}
    Any(char16* value) : value(new System::String(value)) {}
    Any(const char32* value) : value(new System::String(value)) {}
    Any(char32* value) : value(new System::String(value)) {}
    Any(const std::string& value) : value(new System::String(value)) {}
    Any(const std::wstring& value) : value(new System::String(value)) {}
    Any(const std::u16string& value) : value(new System::String(value)) {}
    Any(const std::u32string& value) : value(new System::String(value)) {}
    Any(sbyte value) : value(new System::SByte(value)) {}
    Any(float value) : value(new System::Single(value)) {}
    Any(uint16 value) : value(new System::UInt16(value)) {}
    Any(uint32 value) : value(new System::UInt32(value)) {}
    Any(uint64 value) : value(new System::UInt64(value)) {}
    Any(void* value) : value(new System::IntPtr((intptr)value)) {}
    Any(llong value) : value(sizeof(long) == 8 ? (object*)new System::Int64(value) : (object*)new System::Int32(value)) {}
    Any(ullong value) : value(sizeof(long) == 8 ? (object*)new System::UInt64(value) : (object*)new System::UInt32(value)) {}
    template<typename T, typename Attribute>
    Any(const property<T, Attribute>& value) : value(ObjectOrEnumOrOtherToAny<T>()(value())) {}
    template <typename T>
    operator T() const {
      if(!this->HasValue)
        throw System::InvalidOperationException(_current_information);
      return To<T>();
    }
    
    bool operator==(NullPtr value) const {return !this->HasValue();}
    bool operator==(bool value) const {return As<System::Boolean>() == value;}
    bool operator==(byte value) const {return As<System::Byte>() == value;}
    bool operator==(char value) const {return As<System::Char>() == char32(value);}
    bool operator==(wchar value) const {return As<System::Char>() == char32(value);}
    bool operator==(char16 value) const {return As<System::Char>() == value;}
    bool operator==(char32 value) const {return As<System::Char>() == value;}
    bool operator==(double value) const {return As<System::Double>() == value;}
    bool operator==(int16 value) const {return As<System::Int16>() == value;}
    bool operator==(int32 value) const {return As<System::Int32>() == value;}
    bool operator==(int64 value) const {return As<System::Int64>() == value;}
    bool operator==(const char* value) const {return As<System::String>() == value;}
    bool operator==(char* value) const {return As<System::String>() == value;}
    bool operator==(const wchar* value) const {return As<System::String>() == value;}
    bool operator==(wchar* value) const {return As<System::String>() == value;}
    bool operator==(const char16* value) const {return As<System::String>() == value;}
    bool operator==(char16* value) const {return As<System::String>() == value;}
    bool operator==(const char32* value) const {return As<System::String>() == value;}
    bool operator==(char32* value) const {return As<System::String>() == value;}
    bool operator==(const std::string& value) const {return As<System::String>() == value;}
    bool operator==(const std::wstring& value) const {return As<System::String>() == value;}
    bool operator==(const std::u16string& value) const {return As<System::String>() == value;}
    bool operator==(const std::u32string& value) const {return As<System::String>() == value;}
    bool operator==(sbyte value) const {return As<System::SByte>() == value;}
    bool operator==(float value) const {return As<System::Single>() == value;}
    bool operator==(uint16 value) const {return As<System::UInt16>() == value;}
    bool operator==(uint32 value) const {return As<System::UInt32>() == value;}
    bool operator==(uint64 value) const {return As<System::UInt64>() == value;}
    bool operator==(void* value) const {return As<System::IntPtr>() == (intptr)value;}
    bool operator==(llong value) const {return sizeof(long) == 8 ? As<System::Int64>() == value : As<System::Int32>() == value;}
    bool operator==(ullong value) const {return sizeof(long) == 8 ? As<System::UInt64>() == value : As<System::UInt32>() == value;}
    template<typename T>
    bool operator==(const T& value) const {return As<T>() == value;}
    template<typename T>
    bool operator!=(const T& value) const {return !this->operator==(value);}

    bool operator==(const Any& value) const {
      if(!this->HasValue && !value.HasValue) return true;
      return *this->value == *value.value;}
    bool operator!=(const Any& value) const {return !this->operator==(value);}
    
    /// @endcond

    /// @brief Gets a value indicating whether the current Nullable<T> object has a valid value of its underlying type.
    /// @return true if the current Nullable<T> object has a value; false if the current Nullable<T> object has no value.
    /// @remarks If the HasValue property is true, the value of the current Nullable<T> object can be accessed with the Value property. Otherwise, attempting to access its value throws an InvalidOperationException exception.
    property<bool, readonly> HasValue {
      _get {return !this->value.IsNull();}
    };
    
    /// @brief Gets the value of the current Any object if it has been assigned a valid underlying value.
    /// @return The value of the current Any object if the HasValue property is true. An exception is thrown if the HasValue property is false.
    /// @exception InvalidOperationException The HasValue property is false.
    property<const object&, readonly> Value {
      _get->const object& {
        if(!this->HasValue)
          throw System::InvalidOperationException(_current_information);
        return this->value.ToObject();
      }
    };
    
    /// @brief Used to static cast a type into another type. A To expression takes the following form:
    /// @par Examples
    /// @code
    /// refptr<string> str = new Switch::string("A new string");
    /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
    /// @endcode
    /// @exception InvalidOperationException The parameters is null.
    template<typename T>
    T& As() {
      if(!this->HasValue)
        throw System::InvalidOperationException(_current_information);
      return as<T>(this->value.ToObject());
    }
    
    /// @brief Used to static cast a type into another type. A To expression takes the following form:
    /// @par Examples
    /// @code
    /// refptr<string> str = new Switch::string("A new string");
    /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
    /// @endcode
    /// @exception InvalidOperationException The parameters is null.
    template<typename T>
    const T& As() const {
      if(!this->HasValue)
        throw System::InvalidOperationException(_current_information);
      return as<T>(this->value.ToObject());
    }
    
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 CompareTo(const IComparable& obj) const override {
      if (!is<Any>(obj)) return -1;
      return CompareTo(as<Any>(obj));
    }
    
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return int32 A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 CompareTo(const Any& obj) const {
      if (this->value < obj.value) return -1;
      if (this->value > obj.value) return 1;
      return 0;
    }
    
    /// @brief Serves as a hash function for a particular type.
    /// @return Int32 A hash code for the current Object.
    int32 GetHashCode() const override {
      if(!this->HasValue) return 0;
      return As<object>().GetHashCode();
    }
    
    /// @brief Determines whether this instance of Any and a specified Object, which must also be a Any Object, have the same value.
    /// @param obj The Object to compare with the current Object.
    /// @return true if the specified Object is equal to the current Object. otherwise, false.
    bool Equals(const object& obj) const override {
      if (is<Any>(obj))
        return Equals(as<Any>(obj));
      return *this->value == obj;
    }
    
    /// @brief Determines whether this instance of Any and a specified Object, which must also be an Any Object, have the same value.
    /// @param value The Any to compare with the current Object.
    /// @return true if the specified value is equal to the current Any. otherwise, false.
    bool Equals(const Any& value) const {
      if(!this->HasValue && !value.HasValue) return true;
      return *this->value == *value.value;
    }
    
    /// @brief Determines whether this instance of Any and a specified Object, which must also be an Any Object, have the same value.
    /// @param value The Any to compare with the current Object.
    /// @return true if the specified value is equal to the current Any. otherwise, false.
    template <typename T>
    bool Equals(T value) const {
      if(!this->HasValue) return false;
      return *this->value == value;
    }
    
    /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
    /// @par Examples
    /// @code
    /// System::Int32 i = 0;
    /// bool isInt32 = is<System::Int32>(i);
    /// @endcode
    /// @see Switch::System::Type
    template<typename T>
    bool Is() {
      if(!this->HasValue) return false;
      return is<T>(this->value.ToObject());
    }
    
    /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
    /// @par Examples
    /// @code
    /// System::Int32 i = 0;
    /// bool isInt32 = is<System::Int32>(i);
    /// @endcode
    /// @see Switch::System::Type
    template<typename T>
    bool Is() const {
      if(!this->HasValue) return false;
      return is<T>(this->value.ToObject());
    }
    
    /// @brief Returns the text representation of the value of the current Nullable<T> object.
    /// @return The text representation of the value of the current Nullable<T> object if the HasValue property is true, or an empty string ("") if the HasValue property is false.
    /// @remarks The ToString property returns the string yielded by calling the ToString property of the object returned by the Value property.
    string ToString() const override {
      if (this->HasValue == false)
        return "";
      return value->ToString();
    }
    
  private:
    template <typename T>
    T To() const {return *dynamic_cast<const T*>(this->value.ToPointer());}
    
    template <typename T>
    T To() {return *dynamic_cast<T*>(this->value.ToPointer());}
    
    refptr<object> value;
  };
  
  /// @cond
  template <>
  inline bool Any::To<bool>() const {
    return as<System::Boolean>(this->value.ToObject());
  }
  
  template <>
  inline byte Any::To<byte>() const {
    return as<System::Byte>(this->value.ToObject());
  }
  
  template <>
  inline char Any::To<char>() const {
    return (char)as<System::Char>(this->value.ToObject());
  }
  
  template <>
  inline char16 Any::To<char16>() const {
    return (char16)as<System::Char>(this->value.ToObject());
  }
  
  template <>
  inline char32 Any::To<char32>() const {
    return as<System::Char>(this->value.ToObject());
  }
  
  template <>
  inline wchar Any::To<wchar>() const {
    return (wchar)as<System::Char>(this->value.ToObject());
  }
  
  template <>
  inline double Any::To<double>() const {
    return as<System::Double>(this->value.ToObject());
  }
  
  template <>
  inline int16 Any::To<int16>() const {
    return as<System::Int16>(this->value.ToObject());
  }
  
  template <>
  inline int32 Any::To<int32>() const {
    return as<System::Int32>(this->value.ToObject());
  }
  
  template <>
  inline sbyte Any::To<sbyte>() const {
    return as<System::SByte>(this->value.ToObject());
  }
  
  template <>
  inline float Any::To<float>() const {
    return as<System::Single>(this->value.ToObject());
  }
  
  template <>
  inline string Any::To<string>() const {
    return this->ToString();
  }
  
  template <>
  inline int64 Any::To<int64>() const {
    return as<System::Int64>(this->value.ToObject());
  }
  
  template <>
  inline uint16 Any::To<uint16>() const {
    return as<System::UInt16>(this->value.ToObject());
  }
  
  template <>
  inline uint32 Any::To<uint32>() const {
    return as<System::UInt32>(this->value.ToObject());
  }
  
  template <>
  inline uint64 Any::To<uint64>() const {
    return as<System::UInt64>(this->value.ToObject());
  }
  /// @endcond

  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  T as(const Any& value) {
    return value.As<T>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Switch::string("A new string");
  /// refptr<System::IComparable> comparable = as<Switch::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  template<typename T>
  T as(Any& value) {
    return value.As<T>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  template<typename T>
  bool is(const Any& value) {
    return value.Is<T>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Switch::System::Type
  template<typename T>
  bool is(Any& value) {
    return value.Is<T>();
  }

  /// @cond
  template<>
  inline bool as<bool>(const Any& value) {
    return value.As<System::Boolean>();
  }
  
  template<>
  inline byte as<byte>(const Any& value) {
    return value.As<System::Byte>();
  }
  
  template<>
  inline char32 as<char32>(const Any& value) {
    return value.As<System::Char>();
  }
  
  template<>
  inline int16 as<int16>(const Any& value) {
    return value.As<System::Int16>();
  }
  
  template<>
  inline int32 as<int32>(const Any& value) {
    return value.As<System::Int32>();
  }
  
  template<>
  inline int64 as<int64>(const Any& value) {
    return value.As<System::Int64>();
  }
  
#if defined(__APPLE__)
  template<>
  inline intptr as<intptr>(const Any& value) {
    return value.As<System::IntPtr>();
  }
#endif
  
  template<>
  inline sbyte as<sbyte>(const Any& value) {
    return value.As<System::SByte>();
  }
  
  template<>
  inline uint16 as<uint16>(const Any& value) {
    return value.As<System::UInt16>();
  }
  
  template<>
  inline uint32 as<uint32>(const Any& value) {
    return value.As<System::UInt32>();
  }
  
  template<>
  inline uint64 as<uint64>(const Any& value) {
    return value.As<System::UInt64>();
  }
  
#if defined(__APPLE__)
  template<>
  inline uintptr as<uintptr>(const Any& value) {
    return value.As<System::UIntPtr>();
  }
#endif

  template<>
  inline bool as<bool>(Any& value) {
    return value.As<System::Boolean>();
  }
  
  template<>
  inline byte as<byte>(Any& value) {
    return value.As<System::Byte>();
  }
  
  template<>
  inline char32 as<char32>(Any& value) {
    return value.As<System::Char>();
  }
  
  template<>
  inline int16 as<int16>(Any& value) {
    return value.As<System::Int16>();
  }
  
  template<>
  inline int32 as<int32>(Any& value) {
    return value.As<System::Int32>();
  }
  
  template<>
  inline int64 as<int64>(Any& value) {
    return value.As<System::Int64>();
  }
  
#if defined(__APPLE__)
  template<>
  inline intptr as<intptr>(Any& value) {
    return value.As<System::IntPtr>();
  }
#endif
  
  template<>
  inline sbyte as<sbyte>(Any& value) {
    return value.As<System::SByte>();
  }
  
  template<>
  inline uint16 as<uint16>(Any& value) {
    return value.As<System::UInt16>();
  }
  
  template<>
  inline uint32 as<uint32>(Any& value) {
    return value.As<System::UInt32>();
  }
  
  template<>
  inline uint64 as<uint64>(Any& value) {
    return value.As<System::UInt64>();
  }
  
#if defined(__APPLE__)
  template<>
  inline uintptr as<uintptr>(Any& value) {
    return value.As<System::UIntPtr>();
  }
#endif
  /// @endcond

  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Examples
  /// This example show how to use any:
  /// @include Any.cpp
  using any = Any;
}

using namespace Switch;

#include "System/String.hpp"
