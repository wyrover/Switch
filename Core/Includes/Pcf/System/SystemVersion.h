/// @file
/// @brief Contains Library Version.
#pragma once

#include "Version.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief Get Pcf library Version
  /// @return Pcf library Version
  const System::Version& GetVersion();
}

using namespace Pcf;
