/// @file
/// @brief Contains Pcf::System::Windows::Forms::ProgressBar class.
#pragma once

#include "Control.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a Windows progress bar control.
        class ProgressBar : public Control {
        public:
          ProgressBar();

          /// @cond
          ~ProgressBar();
          /// @endcond

          Property<int32> Maximum {
            pcf_get {return this->GetMaximum();},
            pcf_set {this->SetMaximum(value);}
          };
          
          Property<int32> Minimum {
            pcf_get {return this->GetMinimum();},
            pcf_set {this->SetMinimum(value);}
          };
          
          Property<int32> Value {
            pcf_get {return this->GetValue();},
            pcf_set {this->SetValue(value);}
          };
          
        private:
          void SetForeColor(const System::Drawing::Color& color) override;
          
          int32 GetMaximum() const;
          void SetMaximum(int32 maximum);
          
          int32 GetMinimum() const;
          void SetMinimum(int32 minimum);
          
          int32 GetValue() const;
          void SetValue(int32 value);
          
          bool HasClickRaised(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return true;
              case MouseButtons::Middle: return true;
              case MouseButtons::XButton1: return true;
              case MouseButtons::XButton2: return true;
              default: return true;
            }
          }

          bool HasClickReplaceDoubleClick(MouseButtons button) const override {
            switch (button) {
              case MouseButtons::Left: return true;
              case MouseButtons::Right: return true;
              case MouseButtons::Middle: return true;
              case MouseButtons::XButton1: return true;
              case MouseButtons::XButton2: return true;
              default: return true;
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
        };
      }
    }
  }
}
