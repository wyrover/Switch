#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Button.h"

#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::FormsD;

using WidgetButton = Fltk::Widget<Fl_Button>;

Button::Button() : ButtonBase(UniquePointer<IWidget>::Create<WidgetButton>()) {
  this->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
#if __APPLE__
  this->BackColor = Color::White;
  WidgetButton::ToWidget(this->widget()).selection_color(Fltk::Helper::ToFlColor(SystemColors::Highlight));
#endif
  this->Size = this->DefaultSize;
  this->widget().Callback += pcf_delegate(const object& sender, const EventArgs& e) {
    //this->OnClick(e);
  };
}

System::Windows::FormsD::AutoSizeMode Button::GetAutoSizeMode() const {
  return this->autoSizeMode;
}

void Button::SetAutoSizeMode(System::Windows::FormsD::AutoSizeMode autoSizeMode) {
  this->autoSizeMode = autoSizeMode;
}

void Button::SetTextAlign(System::Drawing::ContentAlignment textAlign) {
  this->textAlign = textAlign;
  switch(this->textAlign) {
    case System::Drawing::ContentAlignment::TopLeft: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::TopCenter: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_TOP | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::TopRight: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_TOP_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleLeft: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleCenter: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::MiddleRight: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::BottomLeft: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
    case System::Drawing::ContentAlignment::BottomCenter: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
    case System::Drawing::ContentAlignment::BottomRight: WidgetButton::ToWidget(this->widget()).align(FL_ALIGN_BOTTOM_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP); break;
  }
}
