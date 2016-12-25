#include "FltkWidget.h"
#include "../../../../../Includes/Pcf/System/Windows/Forms/Panel.h"
#include <Pcf/System/Drawing/SystemColors.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

namespace {
  using WidgetPanel = Fltk::Widget<Fl_Scroll>;
}

Panel::Panel() : ScrollableControl(UniquePointer<IWidget>::Create<WidgetPanel>()) {
  WidgetPanel::ToWidget(this->widget()).end();
  this->BackColor = SystemColors::Control;
  this->BorderStyle = Pcf::System::Windows::Forms::BorderStyle::None;
  this->Size = System::Drawing::Size(200, 200);
}

void Panel::SetBackColor(const System::Drawing::Color& color) {
  if (this->BackColor != color) {
    WidgetPanel::ToWidget(this->widget()).transparent(color == System::Drawing::Color::Transparent);
    this->Control::SetBackColor(color);
    this->SetBorderStyle(this->BorderStyle);
  }
}

System::Windows::Forms::BorderStyle Panel::GetBorderStyle() const {
  switch (WidgetPanel::ToWidget(this->widget()).box()) {
    case FL_NO_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_FLAT_BOX: return System::Windows::Forms::BorderStyle::None; break;
    case FL_BORDER_BOX: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_BORDER_FRAME: return System::Windows::Forms::BorderStyle::FixedSingle; break;
    case FL_DOWN_BOX: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    case FL_DOWN_FRAME: return System::Windows::Forms::BorderStyle::Fixed3D; break;
    default: return System::Windows::Forms::BorderStyle::None;
  }
}

void Panel::SetBorderStyle(System::Windows::Forms::BorderStyle borderStyle) {
  switch (borderStyle) {
    case System::Windows::Forms::BorderStyle::None: WidgetPanel::ToWidget(this->widget()).box(WidgetPanel::ToWidget(this->widget()).transparent() ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::Forms::BorderStyle::FixedSingle: WidgetPanel::ToWidget(this->widget()).box(WidgetPanel::ToWidget(this->widget()).transparent() ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::Forms::BorderStyle::Fixed3D: WidgetPanel::ToWidget(this->widget()).box(WidgetPanel::ToWidget(this->widget()).transparent() ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}
