/// @file
/// @brief Contains Switch::System::Media::SystemSound class.
#pragma once

#include <Switch/Is.hpp>
#include <Switch/Types.hpp>
#include <Switch/System/Object.hpp>
#include "../Windows/Forms/MessageBoxIcon.hpp"

struct __opaque_snd_access__;

/// @brief The Switch library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Media namespace contains classes for playing sound files and accessing sounds provided by the system.
    namespace Media {
      /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
      class SystemSound : public object {
      public:
        SystemSound() {}

        void Play() const;

        bool Equals(const object& obj) const override {return is<SystemSound>(obj) && Equals((const SystemSound&)obj);}

        bool Equals(const SystemSound& sound) const {return this->type == sound.type;}

        intptr Tag() const {return (intptr)this->type;}

      private:
        friend struct ::__opaque_snd_access__;
        SystemSound(System::Windows::Forms::MessageBoxIcon type) : type(type) {}
        System::Windows::Forms::MessageBoxIcon type = (System::Windows::Forms::MessageBoxIcon)0;
      };
    }
  }
}
