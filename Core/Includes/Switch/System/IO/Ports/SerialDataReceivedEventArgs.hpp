/// @file
/// @brief Contains Switch::System::IO::Ports::SerialDataReceivedEventArgs class.
#pragma once

#include "../../../Property.hpp"
#include "../../EventArgs.hpp"
#include "SerialData.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Provides data for the DataReceived event.
        /// @remarks This class is used with the DataReceived event.
        class _export SerialDataReceivedEventArgs : public System::EventArgs {
        public:
          SerialDataReceivedEventArgs(SerialData eventType) : eventType(eventType) {}
          SerialDataReceivedEventArgs(const SerialDataReceivedEventArgs& sdrea) : eventType(sdrea.eventType) {}

          /// @brief Gets the event type.
          /// @return One of the SerialData values.
          /// @remarks This property provides information about the event type that caused the DataReceived event.
          _property<SerialData, _readonly> EventType {
            _get {return this->eventType;}
          };

        private:
          SerialData eventType;
        };
      }
    }
  }
}

using namespace Switch;
