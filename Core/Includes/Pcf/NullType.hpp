/// @file
/// @brief Contains Pcf::NullType struct.
#pragma once

#include "Public.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
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

using namespace Pcf;
