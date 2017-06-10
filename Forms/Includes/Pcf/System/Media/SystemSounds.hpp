/// @file
/// @brief Contains Pcf::System::Media::SystemSounds class.
#pragma once

#include "SystemSound.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      class SystemSounds {
      public:
        static Property<SystemSound, ReadOnly> Asterisk;

        static Property<SystemSound, ReadOnly> Beep;

        static Property<SystemSound, ReadOnly> Exclamation;

        static Property<SystemSound, ReadOnly> Hand;

        static Property<SystemSound, ReadOnly> Question;
      };
    }
  }
}
