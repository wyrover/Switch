/// @file
/// @brief Contains Pcf::System::Windows::Forms::KeyPressEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.hpp>

#include "KeyPressEventArgs.hpp"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        using KeyPressEventHandler = TEventHandler<KeyPressEventArgs&>;
      }
    }
  }
}
