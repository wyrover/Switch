/// @file
/// @brief Contains Pcf::System::Media::SystemSound class.
#pragma once

#include <Pcf/Is.h>
#include <Pcf/System/Object.h>
#include <Pcf/System/Int32.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      class SystemSounds;

      /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
      class SystemSound : public object {
        static const int32 asterisk = 0;
        static const int32 beep = 1;
        static const int32 exclamation = 2;
        static const int32 hand = 3;
        static const int32 question = 4;
     
      public:
        using Handle = Int32;
        SystemSound() {}

        void Play() const;

        bool Equals(const object& obj) const {return is<SystemSound>(obj) && Equals((const SystemSound&)obj);}

        bool Equals(const SystemSound& sound) const {return this->handle == sound.handle;}

        const object& Tag() const {return handle;}

      private:
        friend class SystemSounds;
        SystemSound(Handle handle) : handle(handle) {}
        Handle handle = 1;
      };
    }
  }
}
