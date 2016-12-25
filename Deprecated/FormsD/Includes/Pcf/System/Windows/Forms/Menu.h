/// @file
/// @brief Contains Pcf::System::Windows::Forms::Menu class.
#pragma once

#include "../../ComponentModel/Component.h"
#include "ControlEventHandler.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @cond
        class MenuItemCollection;
        /// @endcond

        class Menu : public System::ComponentModel::Component {
        public:
          Menu();
          //Menu(const Array<MenuItem>& items) {}
          
          Property<MenuItemCollection&> MenuItems {
            pcf_get->MenuItemCollection& {return this->GetMenuItems();},
            [&](MenuItemCollection& value) {this->SetMenuItems(value);}
          };

          const Menu& operator=(const Menu& menu);

        protected:
          Menu(const Menu& menu);

        private:
          MenuItemCollection& GetMenuItems();
          void SetMenuItems(MenuItemCollection& menuItems);
          UniquePointer<MenuItemCollection> menuItems;
        };
      }
    }
  }
}
