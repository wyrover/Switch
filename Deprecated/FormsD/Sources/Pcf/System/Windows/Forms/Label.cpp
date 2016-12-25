#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Label.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetLabel = Fltk::Widget<Fl_Box>;

Label::Label() : Control(UniquePointer<IWidget>::Create<WidgetLabel>()) {
  this->Size = this->DefaultSize;
  this->TextAlign = System::Drawing::ContentAlignment::TopLeft;
  this->BackColor = System::Drawing::Color::Transparent;
}

void Label::SetBackColor(const System::Drawing::Color& color) {
  if (this->BackColor != color) {
    this->transparent = color == System::Drawing::Color::Transparent;
    this->Control::SetBackColor(color);
    this->SetBorderStyle(this->BorderStyle);
  }
}

System::Windows::FormsD::BorderStyle Label::GetBorderStyle() const {
  switch (WidgetLabel::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::FormsD::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::FormsD::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::FormsD::BorderStyle::Fixed3D; break;
    default: return System::Windows::FormsD::BorderStyle::None;
  }
}

void Label::SetBorderStyle(Pcf::System::Windows::FormsD::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::FormsD::BorderStyle::None: WidgetLabel::ToWidget(this->widget()).box(this->transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::FormsD::BorderStyle::FixedSingle: WidgetLabel::ToWidget(this->widget()).box(this->transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::FormsD::BorderStyle::Fixed3D: WidgetLabel::ToWidget(this->widget()).box(this->transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

void Label::SetTextAlign(System::Drawing::ContentAlignment textAlign) {
  this->textAlign = textAlign;
  switch(this->textAlign) {
    case System::Drawing::ContentAlignment::TopLeft: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::TopCenter: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::TopRight: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_TOP_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleLeft: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleCenter: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleRight: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::BottomLeft: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    case System::Drawing::ContentAlignment::BottomCenter: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::BottomRight: WidgetLabel::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
  }
}
