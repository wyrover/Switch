/// @file
/// @brief Contains Switch::System::IO::Ports::SerialError enum.
#pragma once

#include "../../Enum.hpp"

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The System::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
    namespace IO {
      /// @brief The System::IO::Ports namespace contains classes for controlling serial ports. The most important class, SerialPort, provides a framework for synchronous and event-driven I/O, access to pin and break states, and access to serial driver properties. It can be used to wrap a Stream objects, allowing the serial port to be accessed by classes that use streams.
      /// The namespace includes enumerations that simplify the control of serial ports, such as Handshake, Parity, SerialPinChange, and StopBits.
      namespace Ports {
        /// @brief Specifie the SerialError values
        enum class SerialError {
          /// @brief An input buffer overflow has occurred. There is either no room in the input buffer, or a character was received after the end-of-file (EOF) character.
          RXOver = 1,
          /// @brief A character-buffer overrun has occurred. The next character is lost.
          Overrun = 2,
          /// @brief The hardware detected a parity error.
          RXParity = 4,
          /// @brief The hardware detected a framing error.
          Frame = 8,
          /// @brief The application tried to transmit a character, but the output buffer was full.
          TXFull = 256,
        };
      }
    }
  }
}

/// @cond
template<>
class EnumToStrings<System::IO::Ports::SerialError> {
public:
  void operator ()(System::Collections::Generic::SortedDictionary<int64, string>& values, bool& flags) {
    values = {{(int64)System::IO::Ports::SerialError::RXOver, "RXOver"}, {(int64)System::IO::Ports::SerialError::Overrun, "Overrun"}, {(int64)System::IO::Ports::SerialError::RXParity, "RXParity"}, {(int64)System::IO::Ports::SerialError::Frame, "Frame"}, {(int64)System::IO::Ports::SerialError::TXFull, "TXFull"}};
    flags = false;
  }
};
/// @endcond

using namespace Switch;
