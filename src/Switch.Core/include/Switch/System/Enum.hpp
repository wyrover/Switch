/// @file
/// @brief Contains Switch::System::Enum class.
#pragma once

#include "../Types.hpp"
#include "FormatException.hpp"
#include "Type.hpp"
#include "Collections/Generic/KeyValuePair.hpp"
#include "Array.hpp"
#include "BoxEnum.hpp"
#include "_String.hpp"

namespace Switch {
  using FalseType = std::false_type;
  using TrueType = std::true_type;
}

/// @cond
template<typename T>
class EnumToStrings {
public:
  void operator()(System::Collections::Generic::Dictionary<int64, string>& values, bool& flags) {}
};

template <typename T, bool = std::is_enum<T>::value>
class AddFlagOperators;

template <typename T>
class AddFlagOperators<T, true> : public FalseType { };

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator+=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) + static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator-=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) - static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator &=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) & static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator |=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) | static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T & operator ^=(T& lhs, T rhs) {
  lhs = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) ^ static_cast<typename std::underlying_type<T>::type>(rhs));
  return lhs;
}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator+(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) + static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator-(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) - static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator &(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) & static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator |(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) | static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator ^(T lhs, T rhs) {return static_cast<T>(static_cast<typename std::underlying_type<T>::type>(lhs) ^ static_cast<typename std::underlying_type<T>::type>(rhs));}

template <typename T, typename std::enable_if<AddFlagOperators<T>::value>::type* = nullptr>
inline T operator ~(T rhs) {return static_cast<T>(~static_cast<typename std::underlying_type<T>::type>(rhs));}
/// @endcond

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Provides the base class for enumerations.
    template<typename T>
    class Enum : public BoxEnum<T> {
    public:
      Enum() {}
      Enum(T value) : BoxEnum<T>(value) {}
      
    private:
      virtual void InitValues(Collections::Generic::Dictionary<int64, String>& values) {
        EnumToStrings<T>()(values, Enum::flags);
      }
    };
    
    /// @cond
    template<typename T>
    String BoxEnum<T>::GetName(T value) {return Enum<T>(value).ToString();}
    
    template<typename T>
    T BoxEnum<T>::Parse(const String& value, bool ignoreCase) {
      Values();
      if (flags)
        return ParseFlags(value, ignoreCase);
        
      for (auto item : Values()) {
        if (String::Compare(value, item.Value(), ignoreCase) == 0)
          return (T)item.Key();
      }
      
      return (T)Int64::Parse(value);
    }
    
    template<typename T>
    T BoxEnum<T>::ParseFlags(const String& value, bool ignoreCase) {
      Array<String> values = value.Split(',');
      for (String& str : values)
        str = str.TrimStart(' ').TrimEnd(' ');
        
      if (values.Count == 1) {
        for (auto item : Values()) {
          if (String::Compare(value, item.Value(), ignoreCase) == 0)
            return (T)item.Key();
        }
        return (T)Int64::Parse(value);
      }
      
      int64 result = 0;
      for (String str : values) {
        bool found = false;
        for (auto item : Values()) {
          if (String::Compare(str, item.Value(), ignoreCase) == 0) {
            found = true;
            result |= item.Key();
            break;
          }
        }
        if (found == false)
          throw FormatException(_caller);
      }
      
      return (T)result;
    }
    
    template<typename T>
    int32 BoxEnum<T>::ToInt32(T value) { return Enum<T>(value).ToInt32(); }
    
    template<typename T>
    int64 BoxEnum<T>::ToInt64(T value) { return Enum<T>(value).ToInt64(); }
    
    template<typename T>
    Collections::Generic::Dictionary<int64, String>& BoxEnum<T>::Values() {
      Enum<T>().LoadValues();
      return BoxEnum<T>::values;
    }
    /// @endcond
  }
}

using namespace Switch;
