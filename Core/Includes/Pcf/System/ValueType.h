/// @file
/// @brief Contains Pcf::System::ValueType class.
#pragma once

#include "Object.h"

/// @brief The Pcf namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class String;
    /// @endcond

    /// @brief Provides the base class for value types.
    struct pcf_public ValueType : public Object {
    };
  }
}

#include "_String.h"

using namespace Pcf;