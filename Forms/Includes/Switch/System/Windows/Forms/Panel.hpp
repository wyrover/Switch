/// @file
/// @brief Contains Switch::System::Windows::Forms::Form class.
#pragma once

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
        class _export Panel : public ContainerControl {
        public:
          Panel() {
            this->SetStyle(ControlStyles::UserPaint, false);
          }
          
          /// @cond
          Panel(const Panel& panel) : ContainerControl(panel), borderStyle(panel.borderStyle) {}
          /// @endcond

          property<System::Windows::Forms::BorderStyle> BorderStyle {
            _get{return this->borderStyle;},
            _set{this->SetBorderStyle (value);}
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
