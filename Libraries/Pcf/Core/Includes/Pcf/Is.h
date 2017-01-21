/// @file
/// @brief Contains Pcf::is <> operator.
#pragma once

#include "Ref.h"
#include "SharedPointer.h"
#include "UniquePointer.h"

namespace Pcf {
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(const Reference<T>& value) {
    return value.template Is<TT>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(Reference<T>& value) {
    return value.template Is<TT>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(const SharedPointer<T>& value) {
    return value.template Is<TT>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(SharedPointer<T>& value) {
    return value.template Is<TT>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(UniquePointer<T>& value) {
    return value.template Is<TT>();
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(const T& value) {
    try {
      return dynamic_cast<const TT*>(&value) != null;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(T& value) {
    try {
      return dynamic_cast<TT*>(&value) != null;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  /// @ingroup Pcf
  template<typename TT, typename T>
  bool is(const T* value) {
    try {
      if (value == null)
        return false;
      return dynamic_cast<const TT*>(value) != null;
    } catch (const std::bad_cast&) {
      return false;
    }
  }
  
  /// @brief Return true if specified value is the specified Type. A Is expression takes the following form:
  /// @par Examples
  /// @code
  /// System::Int32 i = 0;
  /// bool isInt32 = is<System::Int32>(i);
  /// @endcode
  /// @see Pcf::System::Type
  template<typename TT, typename T>
  bool is(T* value) {
    try {
      if (value == null)
        return false;
      return dynamic_cast<TT*>(value) != null;
    } catch(const std::bad_cast&) {
      return false;
    }
  }
}

using namespace Pcf;
