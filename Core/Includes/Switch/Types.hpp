/// @file
/// @brief Contains Switch::char16, Switch::int32, ... types.
#pragma once

#include <cstddef>
#include <cstdint>
#include <typeinfo>

#include "Public.hpp"

#if defined(NDEBUG)
#  define RELEASE 1
#else
#  define DEBUG 1
#endif

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represents a 16-bit unicode character.
  /// @ingroup Switch
  using char16 = char16_t;
  
  /// @brief Represents a 32-bit unicode character.
  /// @ingroup Switch
  using char32 = char32_t;
  
  /// @brief Represents a wide character.
  /// @ingroup Switch
  using wchar = wchar_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @ingroup Switch
  using decimal = long double;
  
  /// @brief Represents a 16-bit signed integer.
  /// @ingroup Switch
  using int16 = int16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @ingroup Switch
  using int32 = int32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @ingroup Switch
  using int64 = int64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @ingroup Switch
  using intptr = intptr_t;
  
  /// @brief Represents a null pointer value.
  /// @par Examples
  /// @code
  /// refptr<Foo> foo = ref_new<Foo>();
  /// ...
  /// foo = null; // release the reference pointer.
  /// @endcode
  /// @ingroup Switch
  static std::nullptr_t null;
  
  /// @brief Represents a 8-bit signed integer.
  /// @ingroup Switch
  using sbyte = int8_t;
  
  /// @brief Represents a size of any object in bytes
  /// @ingroup Switch
  using size = size_t;
  
  /// @brief Stores information about a type.
  /// @ingroup Switch
  using type = std::type_info;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @ingroup Switch
  using uint16 = uint16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @ingroup Switch
  using uint32 = uint32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @ingroup Switch
  using uint64 = uint64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @ingroup Switch
  using uintptr = uintptr_t;

  /// @cond
#if defined(__linux__) && defined(_LP64)
  using llong = long long int;
  using ullong = unsigned long long int;
#else
  using llong = long;
  using ullong = unsigned long;
#endif
/// @endcond
}

// On windows byte and boolean have definition (with different type for boolean) in global scope so if a new definition in Switch namespace and "using namepsace Switch" activate in header file, there are a confict.
// The solution remove using namespace Switch, but it's not that I want to mimic .net Framework.

/*
/// @brief Represents a boolean.
using boolean = bool;
*/

/// @brief Represents a 8-bit unsigned integer.
/// @ingroup Switch
using byte = uint8_t;

/// @brief Represents a 8-bit unsigned integer.
/// @ingroup Switch
using uchar = unsigned char;

/// @brief Represents a 16-bit unsigned integer.
/// @ingroup Switch
using ushort = unsigned short;

/// @brief Represents a 32-bit unsigned integer.
/// @ingroup Switch
using uint = unsigned int;

/// @brief Represents a 32-bit or 64-bit unsigned integer.
/// @ingroup Switch
using ulong = unsigned long;

using namespace Switch;
