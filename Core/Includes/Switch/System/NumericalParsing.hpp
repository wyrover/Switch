/// @file
/// @brief Contains Switch::System::NumericalParsing class.
#pragma once

#include "String.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    class pcf_public NumericalParsing {
    public:
      NumericalParsing() = delete;
      
      static int64 ParseSigned(const String& str, int32 base, int32 nbBits);
      
      static uint64 ParseUnsigned(const String& str, int32 base);
    };
    /// @endcond
  }
}

using namespace Switch;
