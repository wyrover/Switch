/// @file
/// @brief Contains Pcf::as <> operator.
#pragma once

#include "Ref.h"
#include "RefPtr.h"
#include "UniquePointer.h"

/// @cond
void __throw_cast_exception__();
/// @endcond

namespace Pcf {
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  Ref<TT> as(const Ref<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  Ref<TT> as(Ref<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  RefPtr<TT> as(const RefPtr<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  RefPtr<TT> as(RefPtr<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  UniquePointer<TT> as(UniquePointer<T>& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
  /// @endcode
  /// @exception ArgumentNullException The parameters is null.
  /// @ingroup Pcf
  template<typename TT, typename T>
  UniquePointer<TT> as(UniquePointer<T>&& value) {
    return value.template As<TT>();
  }
  
  /// @brief Used to static cast a type into another type. A To expression takes the following form:
  /// @par Examples
  /// @code
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
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
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
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
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
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
  /// RefPtr<string> str = new Pcf::string("A new string");
  /// RefPtr<System::IComparable> comparable = as<Pcf::System::IComparable>(str);
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
