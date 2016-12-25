/// @file
/// @brief Contains Pcf::System::Windows::Forms::Cursor class.
#pragma once

#include <Pcf/Is.h>
#include <Pcf/System/Object.h>
#include <Pcf/System/Int32.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        class Cursors;

        /// @brief Provides a collection of Cursor objects for use by a Windows Forms application.
        class Cursor : public object {
        public:
          using Handle = Int32;
          Cursor();

          /// @cond
          ~Cursor();
          /// @endcond

          const object& Tag() const {return handle;}

          bool Equals(const object& obj) const {return is<Cursor>(obj) && Equals((const Cursor&)obj);}

          bool Equals(const Cursor& cursor) const {return this->handle == cursor.handle;}

        private:
          friend class Cursors;
          Cursor(Handle handle) : handle(handle) {}
          Handle handle = 0;
        };
      }
    }
  }
}
