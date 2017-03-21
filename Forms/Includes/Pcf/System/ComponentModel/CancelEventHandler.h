/// @file
/// @brief Contains Pcf::System::ComponentModel::CancelEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.h>

#include "CancelEventArgs.h"

namespace Pcf {
  namespace System {
    namespace ComponentModel {
      using CancelEventHandler = TEventHandler<CancelEventArgs&>;
    }
  }
}
