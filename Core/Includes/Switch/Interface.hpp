/// @file
/// @brief Contains Switch::Interface struct and #sw_interface keyword.
#pragma once

#include "Types.hpp"
#include "Allocator.hpp"
#include "NullPtr.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief Represent an interface class.
  struct sw_public Interface {
    /// @cond
    virtual ~Interface() {}
    /// @endcond
  };

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    template<typename T = NullPtr, int32 Rank = 1, typename TAllocator = Allocator<T>>
    class Array;
    /// @endcond
  }
  
  /// @brief This keyword is use to represent an interface.
  /// @par Examples
  /// @code
  /// class IStringable sw_interface {
  /// public:
  ///   virtual String ToString() const = 0;
  /// };
  ///
  /// class Foo : public object, public IStringable {
  /// public:
  ///   Foo() {}
  ///
  ///   String ToString() const override {return "Foo";}
  /// };
  /// @endcode
  /// @ingroup Switch
  #define sw_interface\
  : public Interface
}

using namespace Switch;
