/// @file
/// @brief Contains Pcf::System::IHashable interface.
#pragma once

#include "../Types.h"
#include "../Interface.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @interface IHashable
    /// @brief The IHashable interface is used to specify a hash value for an object instance.
    class IHashable pcf_interface {
    public:
      /// @brief Serves as a hash function for a particular type.
      /// @return int32 A hash code for the current Object.
      virtual int32 GetHashCode() const = 0;
    };
  }
}

using namespace Pcf;
