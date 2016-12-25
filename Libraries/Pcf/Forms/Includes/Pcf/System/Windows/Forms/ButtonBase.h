/// @file
/// @brief Contains Pcf::System::Windows::Forms::ButtonBase class.
#pragma once

#include "Control.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a Windows button control.
        class ButtonBase : public Control {
        public:
          ButtonBase() {}
          ButtonBase(UniquePointer<IWidget> widget) : Control(widget) {}
          ButtonBase(const string& text, int32 left, int32 top, int32 height, int32 width) : Control(text, left, top, height, width), autoElipsis(false) {}

          bool AutoElispis() const {
            return this->autoElipsis;
          }

          void AutoElipsis(bool autoElipsis) {
            this->autoElipsis = autoElipsis;
          }

        private:
          bool autoElipsis;
        };
      }
    }
  }
}
