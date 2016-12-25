/// @file
/// @brief Contains Pcf::System::Windows::Forms::MainMenu class.
#pragma once

#include <Pcf/Ref.h>
#include <Pcf/System/Array.h>

#include "ContainerControl.h"
#include "Menu.h"
#include "MenuItem.h"

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace FormsD {
        /// @brief Represents a MainMenu.
        class MainMenu : public Menu {
        public:
          MainMenu();
          MainMenu(const ContainerControl& container);
          MainMenu(const Array<MenuItem>& menuItems);

          Property<System::Drawing::Size> Size {
            pcf_get {return this->GetSize();},
            pcf_set {this->SetSize(value);}
          };
          
        private:
          System::Drawing::Size GetSize() const;
          void SetSize(const Drawing::Size& size);
          
          System::Drawing::Size GetDefaultSize() const {return System::Drawing::Size(300, 20);}
          void OnMenuItemAdded(const object& sender, const MenuItem& menuItem);
          void AddMenuItem(const string& parent, MenuItemCollection& menuItems);
          Reference<ContainerControl> container;
          SharedPointer<IWidget> widget;
       };
      }
    }
  }
}
