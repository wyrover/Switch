/// @file
/// @brief Contains Pcf::System::NullType struct.
#pragma once

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @cond
    struct pcf_public NullType {
      bool operator ==(const NullType&) const {return true;}
      bool operator !=(const NullType&) const {return false;}
      bool operator <(const NullType&) const {return false;}
      bool operator <=(const NullType&) const {return true;}
      bool operator >(const NullType&) const {return false;}
      bool operator >=(const NullType&) const {return true;}
    };
    /// @endcond
  }
}

using namespace Pcf;
