/// @file
/// @brief Contains Pcf::System::Windows::Forms::RadioButton class.
#pragma once

#include "ButtonBase.h"

#include <Pcf/System/Drawing/SizeF.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a Windows button control.
        class RadioButton : public ButtonBase {
        public:
          RadioButton();

          Property<bool> Checked {
            pcf_get {return this->checked;},
            pcf_set {this->SetChecked(value);}
          };
          
        private:
          bool GetCanFocus() const override {return true;}
          
          void SetChecked(bool checked);
          
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(100, 23);}
          
          bool HasClickRaised(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }

          bool HasClickReplaceDoubleClick(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }

          bool HasDoubleClickRaised(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return false;
              case MouseButtons::Right: return false;
              case MouseButtons::Middle: return false;
              case MouseButtons::XButton1: return false;
              case MouseButtons::XButton2: return false;
              default: return false;
            }
          }
          
          System::Drawing::SizeF GetComputeSize() const override {
            System::Drawing::SizeF size = this->CreateGraphics().MeasureString(this->Text(), this->Font());
            size.Width += 23;
            if (size.Height < 23)
              size.Height = 23;
            return size;
          }
          
          bool checked = false;
        };
      }
    }
  }
}
