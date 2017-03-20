/// @file
/// @brief Contains Pcf::System::Media::SystemSounds class.
#pragma once

#include "SystemSound.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      class SystemSounds {
      public:
        static const SystemSound Asterisk;

        static const SystemSound Beep;

        static const SystemSound Exclamation;

        static const SystemSound Hand;

        static const SystemSound Question;
      };
    }
  }
}
