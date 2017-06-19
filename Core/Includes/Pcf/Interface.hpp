/// @file
/// @brief Contains Pcf::Interface struct and #pcf_interface keyword.
#pragma once

#include "Types.hpp"
#include "System/Allocator.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Represent an interface class.
  struct pcf_public Interface {
    /// @cond
    virtual ~Interface() {}
    /// @endcond
  };

  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    template<typename T, int32 rank=1, typename TAllocator=System::Allocator<T>>
    class Array;

    template<typename T, int32 rank, typename TAllocator>
    class Array;
    /// @endcond
  }
  
  /// @brief This keyword is use to represent an interface.
  /// @par Examples
  /// @code
  /// class IStringable pcf_interface {
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
  /// @ingroup Pcf
  #define pcf_interface\
  : public Interface
}

using namespace Pcf;