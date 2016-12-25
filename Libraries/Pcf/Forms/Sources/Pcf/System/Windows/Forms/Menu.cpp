#include "../../../../../Includes/Pcf/System/Windows/Forms/Menu.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MenuItem.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

Menu::Menu() : menuItems(UniquePointer<MenuItemCollection>::Create()) {
}

Menu::Menu(const Menu& menu) : menuItems(UniquePointer<MenuItemCollection>::Create(*menu.menuItems)) {
}

MenuItemCollection& Menu::GetMenuItems() {
  return *this->menuItems;
}

void Menu::SetMenuItems(MenuItemCollection& menuItems) {
  *this->menuItems = menuItems;
}

const Menu& Menu::operator=(const Menu& menu) {
  *this->menuItems = *menu.menuItems;
  return *this;
}