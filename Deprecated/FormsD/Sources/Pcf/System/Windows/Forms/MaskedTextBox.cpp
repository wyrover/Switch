#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/MaskedTextBox.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetMaskedTextBox = Fltk::Widget<Fl_Input>;

MaskedTextBox::MaskedTextBox() : Control(UniquePointer<IWidget>::Create<WidgetMaskedTextBox>()) {
  this->widget().Callback += pcf_delegate(const object& sender, const EventArgs& e) {
    this->OnTextChanged(e);
  };
  this->Size = this->DefaultSize;
  this->BackColor = SystemColors::Window;
  this->ForeColor = SystemColors::WindowText;
#if __APPLE__
  WidgetMaskedTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(Color::FromArgb(100, 163, 205, 255)));
#else
  WidgetMaskedTextBox::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
#endif
  WidgetMaskedTextBox::ToWidget(this->widget()).when(FL_WHEN_CHANGED);
}

void MaskedTextBox::SetBackColor(const System::Drawing::Color& color) {
  if (this->BackColor != color) {
    this->transparent = color == System::Drawing::Color::Transparent;
    this->Control::SetBackColor(color);
    this->SetBorderStyle(this->BorderStyle);
  }
}

System::Windows::FormsD::BorderStyle MaskedTextBox::GetBorderStyle() const {
  switch (WidgetMaskedTextBox::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    default: return System::Windows::FormsD::BorderStyle::None;
  }
}

void MaskedTextBox::SetBorderStyle(Pcf::System::Windows::FormsD::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::FormsD::BorderStyle::None: WidgetMaskedTextBox::ToWidget(this->widget()).box(this->transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::FormsD::BorderStyle::FixedSingle: WidgetMaskedTextBox::ToWidget(this->widget()).box(this->transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::FormsD::BorderStyle::Fixed3D: WidgetMaskedTextBox::ToWidget(this->widget()).box(this->transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

string MaskedTextBox::GetText() const {
  return WidgetMaskedTextBox::ToWidget(this->widget()).value();
}

void MaskedTextBox::SetText(const string& text) {
  WidgetMaskedTextBox::ToWidget(this->widget()).value(text.Data());
}
