#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/CheckedListBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

namespace {
  using WidgetCheckedList = Fltk::Widget<Fl_Check_Browser>;
}

CheckedListBox::CheckedListBox() : ListControl(UniquePointer<IWidget>::Create<WidgetCheckedList>()) {
  this->BackColor = SystemColors::Window;
  this->Size = this->DefaultSize;
  this->items.ListBoxItemAdded += ObjectCollection::AddListBoxItemEventHandler(*this, &CheckedListBox::OnListBoxItemAdded);
  this->items.ListBoxItemCleared += ObjectCollection::ListBoxItemEventHandler(*this, &CheckedListBox::OnListBoxItemCleared);
  this->items.ListBoxItemRemoved += ObjectCollection::ListBoxItemEventHandler(*this, &CheckedListBox::OnListBoxItemRemoved);
}

System::Windows::FormsD::BorderStyle CheckedListBox::GetBorderStyle() const {
  static System::Collections::Generic::SortedDictionary<Fl_Boxtype, System::Windows::FormsD::BorderStyle> borderSyles = {{FL_NO_BOX, System::Windows::FormsD::BorderStyle::None}, {FL_FLAT_BOX, System::Windows::FormsD::BorderStyle::None}, {FL_BORDER_BOX, System::Windows::FormsD::BorderStyle::FixedSingle}, {FL_DOWN_BOX, System::Windows::FormsD::BorderStyle::Fixed3D}};
  if (!borderSyles.ContainsKey(WidgetCheckedList::ToWidget(this->widget()).box()))
    return System::Windows::FormsD::BorderStyle::None;
  return borderSyles[WidgetCheckedList::ToWidget(this->widget()).box()];
}

void CheckedListBox::SetBorderStyle(System::Windows::FormsD::BorderStyle borderStyle) {
  System::Collections::Generic::SortedDictionary<System::Windows::FormsD::BorderStyle, Fl_Boxtype> borderSyles = {{System::Windows::FormsD::BorderStyle::None, this->BackColor == System::Drawing::Color::Transparent ? FL_NO_BOX : FL_FLAT_BOX}, {System::Windows::FormsD::BorderStyle::FixedSingle, FL_BORDER_BOX}, {System::Windows::FormsD::BorderStyle::Fixed3D, FL_DOWN_BOX}};
  if (!borderSyles.ContainsKey(borderStyle))
    WidgetCheckedList::ToWidget(this->widget()).box(this->BackColor == System::Drawing::Color::Transparent ? FL_NO_BOX :  FL_FLAT_BOX);
  return WidgetCheckedList::ToWidget(this->widget()).box(borderSyles[borderStyle]);
}

int32 CheckedListBox::GetSelectedIndex() const {
  return WidgetCheckedList::ToWidget(this->widget()).value()-1;
}

void CheckedListBox::SetSelectedIndex(int32 selectedIndex) {
  if (selectedIndex < 0 || selectedIndex >= this->items.Count)
    throw IndexOutOfRangeException(pcf_current_information);
  //WidgetCheckedList::ToWidget(this->widget()).value(selectedIndex+1);
}

const object& CheckedListBox::GetSelectedItem() const {
  return *this->items[WidgetCheckedList::ToWidget(this->widget()).value()-1];
}

void CheckedListBox::OnListBoxItemAdded(const object& sender, const object& item, bool checked) {
  WidgetCheckedList::ToWidget(this->widget()).add(item.ToString().Data(), checked);
}

void CheckedListBox::OnListBoxItemCleared(const object& sender, const object&) {
  WidgetCheckedList::ToWidget(this->widget()).clear();
}

void CheckedListBox::OnListBoxItemRemoved(const object& sender, const object& index) {
  WidgetCheckedList::ToWidget(this->widget()).remove(as<Int32>(index)+1);
}
