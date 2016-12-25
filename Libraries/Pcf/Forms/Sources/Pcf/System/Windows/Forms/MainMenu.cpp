#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MainMenu.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

using WidgetMainMenu = Fltk::Widget<Fl_Sys_Menu_Bar>;
//using WidgetMainMenu = Fltk::Widget<Fl_Menu_Bar>;

void MainMenu::OnMenuItemAdded(const object& sender, const MenuItem& menuItem) {
  if (this->container.IsNull())
    return;

  WidgetMainMenu::ToWidget(this->widget()).clear();
  for (MenuItem& item : this->MenuItems()) {
    WidgetMainMenu::ToWidget(this->widget()).add(item.Text().Data(), Fltk::Helper::ToFlShortcut(item.shortcut), &MenuItem::OnItemClick, &item, FL_SUBMENU);
    AddMenuItem(string::Format("{0}/", item.Text()), item.MenuItems());
  }
}

void MainMenu::AddMenuItem(const string& parent, MenuItemCollection& menuItems) {
  if (this->container.IsNull())
    return;

  int32 menuType = 0;
  Reference<MenuItem> previous;
  for (MenuItem& item : menuItems) {
    if (item.Text() == "-") {
      menuType |= FL_MENU_DIVIDER;
      continue;
    }
    
    if (!previous.IsNull()) {
      if (previous().MenuItems().Count())
        menuType |= FL_SUBMENU;
      
      WidgetMainMenu::ToWidget(this->widget()).add(string::Format("{0}{1}", parent, previous().Text()).Data(), Fltk::Helper::ToFlShortcut(previous().shortcut), &MenuItem::OnItemClick, reinterpret_cast<void*>(previous.ToPointer()), menuType);
      AddMenuItem(string::Format("{0}{1}/", parent, previous().Text()), previous().MenuItems());
      menuType &= ~FL_SUBMENU;
      menuType &= ~FL_MENU_DIVIDER;
    }

    previous = item;
  }

  if (!previous.IsNull()) {
    WidgetMainMenu::ToWidget(this->widget()).add(string::Format("{0}{1}", parent, previous().Text()).Data(), Fltk::Helper::ToFlShortcut(previous().shortcut), &MenuItem::OnItemClick, reinterpret_cast<void*>(const_cast<MenuItem*>(previous.ToPointer())), menuType);
    AddMenuItem(string::Format("{0}{1}/", parent, previous().Text()), previous().MenuItems());
    menuType &= ~FL_SUBMENU;
    menuType &= ~FL_MENU_DIVIDER;
  }
}

MainMenu::MainMenu() {
  this->widget = UniquePointer<IWidget>::Create<WidgetMainMenu>(0, 0, this->GetDefaultSize().Width(), this->GetDefaultSize().Height());
  WidgetMainMenu::ToWidget(this->widget()).color(Fltk::Helper::ToFlColor(SystemColors::MenuBar));
  WidgetMainMenu::ToWidget(this->widget()).textcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).labelcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MainMenu::OnMenuItemAdded);
}

MainMenu::MainMenu(const ContainerControl& container) : container(container) {
  this->widget = UniquePointer<IWidget>::Create<WidgetMainMenu>(0, 0, this->GetDefaultSize().Width(), this->GetDefaultSize().Height());
  //WidgetMainMenu::ToWidget(this->widget()).parent(const_cast<Fl_Group*>(&Fltk::Widget<Fl_Group>::ToWidget(this->container().Handle())));
  const_cast<Fl_Group*>(&Fltk::Widget<Fl_Group>::ToWidget(this->container().Handle()))->add(WidgetMainMenu::ToWidget(this->widget()));
  WidgetMainMenu::ToWidget(this->widget()).box(FL_FLAT_BOX);
  WidgetMainMenu::ToWidget(this->widget()).size(this->container().ClientSize().Width(), WidgetMainMenu::ToWidget(this->widget()).h());
  //WidgetMainMenu::ToWidget(this->widget()).color(Fltk::Helper::ToFlColor(SystemColors::MenuBar));
  WidgetMainMenu::ToWidget(this->widget()).color(Fltk::Helper::ToFlColor(SystemColors::Window));
  WidgetMainMenu::ToWidget(this->widget()).textcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).labelcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MainMenu::OnMenuItemAdded);

  this->widget->Paint += pcf_delegate(const object&, const EventArgs& e) {this->widget->Draw();};
}

MainMenu::MainMenu(const Array<MenuItem>& menuItems) {
  this->widget = UniquePointer<IWidget>::Create<WidgetMainMenu>(0, 0, this->GetDefaultSize().Width(), this->GetDefaultSize().Height());
  WidgetMainMenu::ToWidget(this->widget()).color(Fltk::Helper::ToFlColor(SystemColors::MenuBar));
  WidgetMainMenu::ToWidget(this->widget()).textcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).labelcolor(Fltk::Helper::ToFlColor(SystemColors::MenuText));
  WidgetMainMenu::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
  MenuItems().MenuItemAdded += MenuItemCollection::MenuItemEventHandler(*this, &MainMenu::OnMenuItemAdded);
  
  for (MenuItem item : menuItems) {
    this->MenuItems().Add(item);
  }
}

System::Drawing::Size MainMenu::GetSize() const {
  return System::Drawing::Size(WidgetMainMenu::ToWidget(this->widget()).w(), WidgetMainMenu::ToWidget(this->widget()).h());
}

void MainMenu::SetSize(const Drawing::Size& size) {
  WidgetMainMenu::ToWidget(this->widget()).size(size.Width(), size.Height());
}
