/// @file
/// @brief Contains Pcf::System::Windows::Forms::Form class.
#pragma once

#include "ContainerControl.hpp"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        /// @brief Used to group collections of controls.
        class pcf_public GroupBox : public ContainerControl {
        public:
          GroupBox() {}

        protected:
          void CreateHandle() override;
          System::Drawing::Size GetDefaultSize() const override {return System::Drawing::Size(200, 100);}
        };
      }
    }
  }
}
