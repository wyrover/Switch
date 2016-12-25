/// @file
/// @brief Contains Pcf::System::IFormatProvider interface.
#pragma once

#include "../Interface.h"
#include "Object.h"
#include "Type.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class Type;
    /// @endcond

    /// @interface IFormatProvider
    /// @brief Provides a mechanism for retrieving an object to control formatting.
    class IFormatProvider pcf_interface {
    public:
      /// @brief Returns an object that provides formatting services for the specified type.
      /// @param type An object that specifies the type of format object to return.
      /// @return object An instance of the object specified by formatType, if the IFormatProvider implementation can supply that type of object; otherwise, nullNothingnullptra null reference (Nothing in Visual Basic).
      virtual const Object& GetFormat(const Type& type) const = 0;
    };
  }
}

using namespace Pcf;
