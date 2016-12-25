/// @file
/// @brief Contains Pcf::System::Windows::Forms::MenuItem class.
#pragma once

#include <Pcf/System/Array.h>
#include <Pcf/System/Collections/Generic/List.h>

#include "Menu.h"
#include "Shortcut.h"

class Fl_Widget;

/// @brief The Pcf library contains all fundamental classes to access Hardware, Os, System, and more.
namespace Pcf {
  /// @brief The Pcf::System namespace contains fundamental classes and base classes that define commonly-used value and reference data types, events and event handlers, interfaces, attributes, and processing exceptions.
  namespace System {
    /// @brief The Pcf::System::Windows namespaces including animation clients, user interface controls, data binding, and type conversion. Pcf::System::Windows::Forms and its child namespaces are used for developing Windows Forms applications.
    namespace Windows {
      /// @brief The Pcf::System::Windows::Forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple Mac Os X and Linux like Ubuntu operating system.
      namespace Forms {
        class MenuItem : public Menu {
        public:
          MenuItem();
          MenuItem(string text);
          MenuItem(string text, EventHandler onClick);
          MenuItem(string text, EventHandler onClick, Shortcut shortcut);
          MenuItem(string text, const Array<MenuItem>& items);
          MenuItem(const MenuItem& menuItem) : Menu(menuItem) {
            this->Click = menuItem.Click;
            this->label = menuItem.label;
            this->shortcut = menuItem.shortcut;
          }

          EventHandler Click;

          MenuItem& operator=(const MenuItem& menuItem) {
            static_cast<Menu&>(*this) = static_cast<const Menu&>(menuItem);
            this->Click = menuItem.Click;
            this->label = menuItem.label;
            this->shortcut = menuItem.shortcut;
            return *this;
          }

          Property<string> Text {
            pcf_get {return this->label;},
            pcf_set {this->label = value;}
          };

        private:
          friend class MainMenu;
          static void OnItemClick(Fl_Widget*, void*);
          void OnMenuItemAdded(const object& sender, const MenuItem& menuItem);
          string label;
          System::Windows::Forms::Shortcut shortcut = System::Windows::Forms::Shortcut::None;
        };

        class MenuItemCollection : public System::Collections::Generic::List<System::Windows::Forms::MenuItem> {
        public:
          using MenuItemEventHandler = TEventHandler<const MenuItem&>;
          
          /// @brief Adds an object to the end of the List<T>.
          /// @param value The object to be added to the end of the List<T>. The value can be null for reference types.
          /// @remarks List<T> accepts null as a valid value for reference types and allows duplicate elements.
          /// @remarks If Count already equals Capacity, the capacity of the List<T> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
          /// @remarks If Count is less than Capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is Count.
          /// @remarks The following code example demonstrates several properties and methods of the List<T> generic class, including the Add method. The default constructor is used to create a list of strings with a capacity of 0. The Capacity property is displayed, and then the Add method is used to add several items. The items are listed, and the Capacity property is displayed again, along with the Count property, to show that the capacity has been increased as needed.
          /// @remarks Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
          /// @include List.cpp
          void Add(const Pcf::System::Windows::Forms::MenuItem& value) override {
            System::Collections::Generic::List<System::Windows::Forms::MenuItem>::Add(value);
            MenuItemAdded(*this, value);
          }
          
          void AddRange	(const System::Collections::Generic::IEnumerable<System::Windows::Forms::MenuItem>& enumerable) {
            for (const System::Windows::Forms::MenuItem& item : enumerable)
              this->Add(item);
          }

          void Insert(int32 index, const Pcf::System::Windows::Forms::MenuItem& value) override {
            Pcf::System::Collections::Generic::List<System::Windows::Forms::MenuItem>::Insert(index, value);
            MenuItemAdded(*this, value);
          }
          
          /// @brief Removes the first occurrence of a specific object from the List<T>.
          /// @param item The object to remove from the List<(Of <(T>)>). The value can not be null.
          /// @return Boolean true if item is successfully removed; otherwise, false. This method also returns false if item was not found in the List<T>.
          bool Remove(const Pcf::System::Windows::Forms::MenuItem& item) override {
            bool result = System::Collections::Generic::List<System::Windows::Forms::MenuItem>::Remove(item);
            MenuItemRemoved(*this, item);
            return result;
          }
          
          int32 RemoveAll(const Predicate<const MenuItem&>& match) {
            //for (const System::Windows::Forms::MenuItem& )
            return System::Collections::Generic::List<System::Windows::Forms::MenuItem>::RemoveAll(match);
          }

          MenuItemEventHandler MenuItemAdded;
          MenuItemEventHandler MenuItemRemoved;
        };
      }
    }
  }
}
