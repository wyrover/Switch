#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/GroupBox.h"

#include <Pcf/System/Drawing/Color.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

using WidgetGroup = Fltk::Widget<Fl_Group>;

GroupBox::GroupBox() : Control(UniquePointer<IWidget>::Create<WidgetGroup>()) {
  WidgetGroup::ToWidget(this->widget()).end();
  WidgetGroup::ToWidget(this->widget()).labeltype(FL_NO_LABEL);
  WidgetGroup::ToWidget(this->widget()).box(FL_NO_BOX);
  this->Size = this->GetDefaultSize();
}

void GroupBox::OnPaint(PaintEventArgs& e) {
  if (this->Text == "")
    e.Graphics().FillBox(System::Drawing::BoxType::Down, SolidBrush(this->BackColor), e.ClipRectangle);
  else {
    System::Drawing::Size textSize = e.Graphics().MeasureString(this->Text, this->Font).ToSize();
    e.Graphics().FillBox(System::Drawing::BoxType::Down, SolidBrush(this->BackColor), e.ClipRectangle().X, e.ClipRectangle().Y + (textSize.Height / 2), e.ClipRectangle().Width, e.ClipRectangle().Height - (textSize.Height / 2));
    e.Graphics().FillRectangle(SolidBrush(this->BackColor), 10, 0, textSize.Width, textSize.Height);
    e.Graphics().DrawString(this->Text, this->Font, SolidBrush(this->ForeColor), 15, 0);
  }

  this->::Control::OnPaint(e);
}
