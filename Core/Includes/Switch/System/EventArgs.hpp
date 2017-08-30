/// @file
/// @brief Contains Switch::System::EventArgs class.
#pragma once

#include "../Property.hpp"
#include "../Types.hpp"
#include "Object.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief EventArgs is the base class for classes containing event data.
    class sw_public EventArgs : public Object {
    public:
      /// @brief Represents an event with no event data.
      static Property<EventArgs, ReadOnly> Empty;

      /// @brief Create a new instance of class EventArgs
      EventArgs() {}
      
      /// @brief Create a new instance of class EventArgs
      EventArgs(const EventArgs&) {}
   };
  }
}

using namespace Switch;
