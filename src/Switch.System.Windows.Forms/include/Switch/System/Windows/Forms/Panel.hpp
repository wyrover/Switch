/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

#include "../../../SystemWindowsFormsExport.hpp"
#include "ContainerControl.hpp"
#include "BorderStyle.hpp"

/// @brief The Switch namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace Switch {
  /// @brief The Switch::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Switch::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Switch::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Switch::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Used to group collections of controls.
        class system_windows_forms_export_ Panel : public ContainerControl {
        public:
          Panel() {
            this->SetStyle(ControlStyles::UserPaint, false);
          }

          /// @cond
          Panel(const Panel& panel) : ContainerControl(panel), borderStyle(panel.borderStyle) {}
          /// @endcond

          property_<System::Windows::Forms::BorderStyle> BorderStyle {
            get_{return this->borderStyle;},
            set_{this->SetBorderStyle(value);}
          };

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override { return System::Drawing::Size(200, 100); }
          void SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle);

          /// @cond
          System::Windows::Forms::BorderStyle borderStyle = System::Windows::Forms::BorderStyle::None;
          /// @endcond
        };
      }
    }
  }
}
