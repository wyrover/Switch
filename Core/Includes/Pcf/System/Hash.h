/// @file
/// @brief Contains Pcf::System::Hash class.
#pragma once

#include "../Any.h"
#include "../Static.h"
#include "../Types.h"
#include "../RefPtr.h"
#include "NullType.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Generate a hash code for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const object& value);
  
  /// @brief Generate a hash code for generic type T.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32  An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  template<typename T>
  int32 GetHashCode(const refptr<T>& value) {
    return *((int32*)value.ToPointer());
  }
  
  /// @brief Generate a hash code for void*.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const void* e);
  
  /// @brief Generate a hash code for NullType.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const System::NullType& value);
  
  /// @brief Generate a hash code for bool.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const bool& value);
  
  /// @brief Generate a hash code for signed 8-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const sbyte& value);
  
  /// @brief  Generate a hash code for char.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const char& value);
  
  /// @brief Generate a hash code for char16.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const char16& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const char32& value);
  
  /// @brief Generate a hash code for wchar.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const wchar& value);
  
  /// @brief Generate a hash code for signed 16-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const int16& value);
  
  /// @brief Generate a hash code for signed 32-bit integer.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const int32& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const int64& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const llong& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const byte& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const uint16& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const uint32& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const ullong& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const uint64& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const double& value);
  
  /// @brief Generate a hash code for char32.
  /// @param[in] value For which the hashcode is generated.
  /// @return int32 An integer value being the generated hashcode.
  /// @exception System::ArgumentNullException The parameters converter is null.
  int32 GetHashCode(const float& value);
}

using namespace Pcf;
