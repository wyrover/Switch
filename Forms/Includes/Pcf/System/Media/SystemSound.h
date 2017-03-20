/// @file
/// @brief Contains Pcf::System::Media::SystemSound class.
#pragma once

#include <Pcf/Is.h>
#include <Pcf/Types.h>
#include <Pcf/System/Object.h>
#include "../Windows/Forms/MessageBoxIcon.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      class SystemSounds;

      /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
      class SystemSound : public object {
      public:
        SystemSound() {}

        void Play() const;

        bool Equals(const object& obj) const noexcept override {return is<SystemSound>(obj) && Equals((const SystemSound&)obj);}

        bool Equals(const SystemSound& sound) const noexcept {return this->type == sound.type;}

        intptr Tag() const {return (intptr)this->type;}

      private:
        friend class SystemSounds;
        SystemSound(System::Windows::Forms::MessageBoxIcon type) : type(type) {}
        System::Windows::Forms::MessageBoxIcon type = (System::Windows::Forms::MessageBoxIcon)0;
      };
    }
  }
}
