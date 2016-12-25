/// @file
/// @brief Contains Pcf::System::Windows::Forms::TabPage class.
#pragma once

#include "Panel.h"

#include <Pcf/System/Drawing/SystemColors.h>

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows label.
        class TabPage : public Panel {
        public:
          TabPage() {
            this->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
            this->BackColor = System::Drawing::SystemColors::Control;
            this->Location(Drawing::Point(0, 20));
            this->Anchor = AnchorStyles(int32(AnchorStyles::Left) | int32(AnchorStyles::Top) | int32(AnchorStyles::Right) | int32(AnchorStyles::Bottom));
          }
          
          Property<bool> UseVisualStyleBackColor {
            pcf_get {return this->useVisualStyleBackColor;},
            pcf_set {
              this->useVisualStyleBackColor = value;
              if (!this->useVisualStyleBackColor)
                this->BackColor = System::Drawing::SystemColors::Control;
              else {
#if __APPLE__
                this->BackColor = System::Drawing::SystemColors::ControlLight;
#elif __linux__
                this->BackColor = System::Drawing::SystemColors::Control;
#else
                this->BackColor = System::Drawing::SystemColors::ControlLightLight;
#endif
              }
            }
          };

          /// @cond
          ~TabPage() {}
          /// @endcond

        private:
          void OnParentChanged(const System::EventArgs& e) override {
            if (this->HasParent)
              this->Size(Drawing::Size(this->Parent().Width(), this->Parent().Height() - 20));
            this->Panel::OnParentChanged(e);
          }
          
          bool useVisualStyleBackColor = false;
        };
      }
    }
  }
}
