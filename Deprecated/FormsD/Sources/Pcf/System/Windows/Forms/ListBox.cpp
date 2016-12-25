#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/ListBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetListBox = Fltk::Widget<Fl_Browser>;

ListBox::ListBox() : ListControl(UniquePointer<IWidget>::Create<WidgetListBox>()) {
  WidgetListBox::ToWidget(this->widget()).type(FL_HOLD_BROWSER);
  WidgetListBox::ToWidget(this->widget()).align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  this->Size = this->DefaultSize;
  this->BackColor = SystemColors::Window;
  WidgetListBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::HotTrack));

  this->items.ListBoxItemAdded += ObjectCollection::ListBoxItemEventHandler(*this, &ListBox::OnListBoxItemAdded);
  this->items.ListBoxItemCleared += ObjectCollection::ListBoxItemEventHandler(*this, &ListBox::OnListBoxItemCleared);
  this->items.ListBoxItemRemoved += ObjectCollection::ListBoxItemEventHandler(*this, &ListBox::OnListBoxItemRemoved);
}

System::Windows::FormsD::BorderStyle ListBox::GetBorderStyle() const {
  switch (WidgetListBox::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    default: return System::Windows::FormsD::BorderStyle::None;
  }
}

void ListBox::SetBorderStyle(System::Windows::FormsD::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::FormsD::BorderStyle::None: WidgetListBox::ToWidget(this->widget()).box(this->BackColor == System::Drawing::Color::Transparent ? FL_NO_BOX :  FL_FLAT_BOX); break;
    case System::Windows::FormsD::BorderStyle::FixedSingle: WidgetListBox::ToWidget(this->widget()).box(FL_BORDER_BOX); break;
    case System::Windows::FormsD::BorderStyle::Fixed3D: WidgetListBox::ToWidget(this->widget()).box(FL_DOWN_BOX); break;
  }
}

int32 ListBox::GetSelectedIndex() const {
  return WidgetListBox::ToWidget(this->widget()).value()-1;
}

void ListBox::SetSelectedIndex(int32 selectedIndex) {
  if (selectedIndex < 0 || selectedIndex >= this->items.Count)
    throw IndexOutOfRangeException(pcf_current_information);
  WidgetListBox::ToWidget(this->widget()).value(selectedIndex+1);
}

SharedPointer<object> ListBox::GetSelectedItem() const {
  return this->items[WidgetListBox::ToWidget(this->widget()).value()-1];
}

void ListBox::OnListBoxItemAdded(const object& sender, const object& item) {
  WidgetListBox::ToWidget(this->widget()).add(item.ToString().Data());
}

void ListBox::OnListBoxItemCleared(const object& sender, const object&) {
  WidgetListBox::ToWidget(this->widget()).clear();
}

void ListBox::OnListBoxItemRemoved(const object& sender, const object& index) {
  WidgetListBox::ToWidget(this->widget()).remove(as<Int32>(index)+1);
}
