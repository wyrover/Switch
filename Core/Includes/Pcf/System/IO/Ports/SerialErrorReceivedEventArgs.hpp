/// @file
/// @brief Contains Pcf::System::IO::Ports::SerialErrorReceivedEventArgs class.
#pragma once

#include "../../../Property.hpp"
#include "../../EventArgs.hpp"
#include "SerialError.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Prepares data for the ErrorReceived event.
        /// @remarks This class is used with the ErrorReceived event.
        class pcf_public SerialErrorReceivedEventArgs : public System::EventArgs {
        public:
          SerialErrorReceivedEventArgs(SerialError eventType) : eventType(eventType) {}
          SerialErrorReceivedEventArgs(const SerialErrorReceivedEventArgs& serea) : eventType(serea.eventType) {}

          /// @brief Gets the event type.
          /// @return One of the SerialError values.
          /// @remarks This property provides information about the event type that caused the ErrorReceived event.
          Property<SerialError, ReadOnly> EventType {
            pcf_get {return this->eventType;}
          };

        private:
          SerialError eventType;
        };
      }
    }
  }
}

using namespace Pcf;
