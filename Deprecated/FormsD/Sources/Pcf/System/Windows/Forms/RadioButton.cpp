#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/RadioButton.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetRadioButton = Fltk::Widget<Fl_Radio_Round_Button>;

RadioButton::RadioButton() : ButtonBase(UniquePointer<IWidget>::Create<WidgetRadioButton>()) {
  this->Size = this->DefaultSize;
}

void RadioButton::SetChecked(bool checked) {
  if (this->checked != checked) {
    this->checked = checked;
    WidgetRadioButton::ToWidget(this->widget()).value(checked);
  }
}
