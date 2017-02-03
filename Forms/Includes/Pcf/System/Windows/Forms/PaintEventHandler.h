/// @file
/// @brief Contains Pcf::System::Windows::Forms::PaintEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.h>

#include "PaintEventArgs.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        using PaintEventHandler = TEventHandler<PaintEventArgs&>;
      }
    }
  }
}
