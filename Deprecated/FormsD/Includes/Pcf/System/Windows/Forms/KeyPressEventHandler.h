/// @file
/// @brief Contains Pcf::System::Windows::Forms::KeyPressEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.h>

#include "KeyPressEventArgs.h"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace FormsD {
        using KeyPressEventHandler = TEventHandler<KeyPressEventArgs&>;
      }
    }
  }
}
