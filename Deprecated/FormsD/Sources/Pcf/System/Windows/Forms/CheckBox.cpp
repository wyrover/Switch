#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/CheckBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetCheckButton = Fltk::Widget<Fl_Check_Button>;

CheckBox::CheckBox() : ButtonBase(UniquePointer<IWidget>::Create<WidgetCheckButton>()) {
  this->Size = this->DefaultSize;
}

bool CheckBox::GetChecked() const {
  this->checked = WidgetCheckButton::ToWidget(this->widget()).value() != 0;
  return this->checked;
}

void CheckBox::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    WidgetCheckButton::ToWidget(this->widget()).value(checked);
  }
}
