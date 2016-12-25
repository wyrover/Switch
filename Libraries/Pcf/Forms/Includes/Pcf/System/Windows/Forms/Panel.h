/// @file
/// @brief Contains Pcf::System::Windows::Forms::Panel class.
#pragma once

#include "BorderStyle.h"
#include "ScrollableControl.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Represents a standard Windows label.
        class Panel : public ScrollableControl {
        public:
          Panel();

          Property<System::Windows::Forms::BorderStyle> BorderStyle {
            pcf_get {return this->GetBorderStyle();},
            pcf_set {this->SetBorderStyle(value);}
          };
          
        protected:
          void SetBackColor(const System::Drawing::Color& color) override;
          System::Windows::Forms::BorderStyle GetBorderStyle() const;
          void SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle);
        };
      }
    }
  }
}
