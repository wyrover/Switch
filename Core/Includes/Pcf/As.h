/// @file
/// @brief Contains Pcf::as <> operator.
#pragma once

#include "Ref.h"
#include "RefPtr.h"
#include "UniquePtr.h"

/// @cond
void __throw_cast_exception__();
/// @endcond

namespace Pcf {
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  ref<TT> as(const ref<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  ref<TT> as(ref<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  refptr<TT> as(const refptr<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  refptr<TT> as(refptr<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  UniquePtr<TT> as(UniquePtr<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  UniquePtr<TT> as(UniquePtr<T>&& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  const TT& as(const T& value) {
    try {
      return dynamic_cast<const TT&>(value);
    } catch(...) {
      __throw_cast_exception__();
    }
    throw std::bad_cast();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  TT& as(T& value) {
    try {
      return dynamic_cast<TT&>(value);
    } catch(...) {
      __throw_cast_exception__();
    }
    throw std::bad_cast();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  const TT* as(const T* value) {
    if (value == null)
      return null;
    return &as<TT>(*value);
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// refptr<string> str = new Pcf::string("A new string");
  /// refptr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  TT* as(T* value) {
    if (value == null)
      return null;
    return &as<TT>(*value);
  }
}

using namespace Pcf;
