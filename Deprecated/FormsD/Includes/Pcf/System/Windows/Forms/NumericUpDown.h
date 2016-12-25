/// @file
/// @brief Contains Pcf::System::Windows::Forms::NumericUpDown class.
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
        /// @brief Represents a Windows numeric up down control.
        class NumericUpDown : public Control {
        public:
          NumericUpDown();

          Property<int32> DecimalPlaces {
            pcf_get {return this->decimalPlaces;},
            pcf_set {this->SetDecimalPlaces(value);}
          };
          
          Property<double> Increment {
            pcf_get {return this->increment;},
            pcf_set {this->SetIncrement(value);}
          };
          
          Property<double> Maximum {
            pcf_get {return this->maximum;},
            pcf_set {this->SetMaximum(value);}
          };
          
          Property<double> Minimum {
            pcf_get {return this->minimum;},
            pcf_set {this->SetMinimum(value);}
          };
          
          Property<double> Value {
            pcf_get {return this->value;},
            pcf_set {this->SetValue(value);}
          };
          
          EventHandler ValueChanged;
          
          virtual void OnValueChanged(const EventArgs& e) {
            this->ValueChanged(*this, e);
          }
          
        private:
          void SetDecimalPlaces(int32 decimalPlace);
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(120, 20);}
          void SetIncrement(double increment);
          void SetMaximum(double maximum);
          void SetMinimum(double minimum);
          void SetValue(double value);
          
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
          
          int32 decimalPlaces = 0;
          string strFormat;
          double increment = 1.0;
          double maximum = 100.0;
          double minimum = .0;
          double value = .0;
        };
      }
    }
  }
}
