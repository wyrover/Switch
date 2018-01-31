/// @file
/// @brief Contains Switch::System::Hash class.
#pragma once

#include "System/Object.hpp"
#include "Export.hpp"
#include "NullPtr.hpp"
#include "Static.hpp"
#include "Types.hpp"
#include "RefPtr.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Generate a String for const void*.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const void* e);

  /// @brief Generate a String for void*.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(void* e);

  /// @brief Generate a String for NullPtr.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const NullPtr& value);

  /// @brief Generate a String for bool.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const bool& value);

  /// @brief Generate a String for byte.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const byte& value);

  /// @brief  Generate a hash code for char.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char& value);

  /// @brief Generate a String for char16.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char16& value);

  /// @brief Generate a String for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char32& value);

  /// @brief Generate a String for wchar.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const wchar& value);

  /// @brief Generate a String for signed 16-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const int16& value);

  /// @brief Generate a String for signed 32-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const int32& value);

  /// @brief Generate a String for signed 64-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const int64& value);

  /// @brief Generate a String for intptr.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const intptr& value);

  /// @brief Generate a String for signed 8-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const sbyte& value);

  /// @brief Generate a String for signed 16-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const uint16& value);

  /// @brief Generate a String for signed 32-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const uint32& value);

  /// @brief Generate a String for signed 64-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const uint64& value);

  /// @brief Generate a String for uintptr.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const uintptr& value);

  /// @brief Generate a String for double-precision floating-point number.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  export_ string ToString(const double& value);

  /// @brief Generate a String for single-precision floating-point number.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  export_ string ToString(const float& value);

  /// @brief Generate a String for const char pointer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char* value);

  /// @brief Generate a String for const char16 pointer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char16* value);

  /// @brief Generate a String for const char32 pointer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const char32* value);

  /// @brief Generate a String for const wchar pointer.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ string ToString(const wchar* value);

  /// @brief Generate a String for string.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  export_ const string& ToString(const string& value);

  /// @cond
  struct StringerFromObject {
    template <typename Object>
    string operator()(const Object& value) {return value.ToString();}
  };

  struct StringerFromEnum {
    template <typename Enum>
    string operator()(const Enum& value) {return ToString(int64(value));}
  };

  struct StringerFromOther {
    template <typename Other>
    string operator()(const Other& value) {
      static_assert(true, "ToString not implemented");
      return "";
    }
  };
  /// @endcond

  /// @brief Generate a String for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename TValue>
  export_ string ToString(const TValue* value) {
    using Stringer = typename std::conditional<std::is_base_of<object, TValue>::value, StringerFromObject, typename std::conditional<std::is_enum<TValue>::value, StringerFromEnum, StringerFromOther>::type>::type;
    Stringer stringer;
    return stringer(*value);
  }

  /// @brief Generate a String for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return string A string value that represent value.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename TValue>
  export_ string ToString(const TValue& value) {
    using Stringer = typename std::conditional<std::is_base_of<object, TValue>::value, StringerFromObject, typename std::conditional<std::is_enum<TValue>::value, StringerFromEnum, StringerFromOther>::type>::type;
    Stringer stringer;
    return stringer(value);
  }

  /// @brief Generate a String for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32  An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename T>
  export_ string ToString(const refptr<T>& value) {
    return ToString(value());
  }
}

using namespace Switch;
