/// @file
/// @brief Contains Pcf::System::Windows::Forms::CheckBox class.
#pragma once

#include <Pcf/System/Drawing/Color.h>
#include <Pcf/System/Drawing/Size.h>

#include "ButtonBase.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a Windows button control.
        class CheckBox : public ButtonBase {
        public:
          CheckBox();

          Property<bool> Checked {
            pcf_get {return this->GetChecked();},
            pcf_set {this->SetChecked(value);}
          };
          
        private:
          bool GetCanFocus() const override {return true;}
          
          bool GetChecked() const;
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
            size.Width += 17;
            if (size.Height < 17)
              size.Height = 17;
            return size;
          }
          
          mutable bool checked = false;
        };
      }
    }
  }
}
