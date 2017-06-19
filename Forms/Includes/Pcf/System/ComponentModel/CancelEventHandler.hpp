/// @file
/// @brief Contains Pcf::System::ComponentModel::CancelEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.hpp>

#include "CancelEventArgs.hpp"

namespace Pcf {
  namespace System {
    namespace ComponentModel {
      using CancelEventHandler = GenericEventHandler<CancelEventArgs&>;
    }
  }
}
