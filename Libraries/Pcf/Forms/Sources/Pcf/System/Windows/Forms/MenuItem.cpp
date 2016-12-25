#include "../../../../../Includes/Pcf/System/Windows/Forms/MenuItem.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void MenuItem::OnMenuItemAdded(const object& sender, const MenuItem& menuItem) {
}

MenuItem::MenuItem() {
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MenuItem::OnMenuItemAdded);
}

MenuItem::MenuItem(string text) : label(text) {
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MenuItem::OnMenuItemAdded);
}

MenuItem::MenuItem(string text, EventHandler onClick) : label(text) {
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MenuItem::OnMenuItemAdded);
  this->Click += onClick;
}

MenuItem::MenuItem(string text, EventHandler onClick, Shortcut shortcut) : label(text), shortcut(shortcut) {
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MenuItem::OnMenuItemAdded);
  this->Click += onClick;
  this->shortcut = shortcut;
}

MenuItem::MenuItem(string text, const Array<MenuItem>& items) : label(text) {
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MenuItem::OnMenuItemAdded);
  this->MenuItems().AddRange(items);
}

void MenuItem::OnItemClick(Fl_Widget*, void* args) {
  MenuItem* menuItem = reinterpret_cast<MenuItem*>(args);
  menuItem->Click(*menuItem, EventArgs());
}

