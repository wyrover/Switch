/// @file
/// @brief Contains Pcf::System::Windows::Forms::PaintEventHandler event handler.
#pragma once

#include <Pcf/System/EventHandler.hpp>

#include "PaintEventArgs.hpp"

namespace Pcf {
  namespace System {
    namespace Windows {
      namespace Forms {
        using PaintEventHandler = GenericEventHandler<PaintEventArgs&>;
      }
    }
  }
}
