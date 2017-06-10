/// @file
/// @brief Contains Pcf::System::ConsoleCancelEventHandler event handler.
#pragma once

#include "ConsoleCancelEventArgs.hpp"
#include "EventHandler.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief Represents the method that will handle the CancelKeyPress event of a System::Console.
    /// @param sender The source of the event.
    /// @param e A System::ConsoleCancelEventArgs object that contains the event data.
    using ConsoleCancelEventHandler = TEventHandler<ConsoleCancelEventArgs&>;
  }
}

using namespace Pcf;
