#if defined(__use_fltk_interface__)
#include "WidgetFltk.hpp"

#include <FL/Fl_Check_Button.H>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class CheckBox : public __OS::Widget, public Fl_Check_Button {
  public:
    CheckBox(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Check_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Check_Button::handle(event);
      if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && this->value() != 0) {
        Fl::set_color(FL_BACKGROUND2_COLOR, 0x56, 0x96, 0xF5);
        Fl::set_color(FL_SELECTION_COLOR, 0xFF, 0xFF, 0xFF);
      }
      this->Fl_Check_Button::draw();
      if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX) {
        Fl::set_color(FL_BACKGROUND2_COLOR, 0xFF, 0xFF, 0xFF);
        Fl::set_color(FL_SELECTION_COLOR, 0x56, 0x96, 0xF5);
      }
      return 1;
    }
  };
}

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  __OS::CheckBox* handle = CreateControl<__OS::CheckBox>(checkBox);
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
  ((Fl_Check_Button&)((__OS::Widget*)checkBox.Handle())->ToWidget()).type(checkBox.AutoCheck ? FL_TOGGLE_BUTTON : FL_NORMAL_BUTTON);
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  ((Fl_Check_Button&)((__OS::Widget*)checkBox.Handle())->ToWidget()).value(checkBox.Checked);
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX) {
    if (((__OS::CheckBox*)checkBox.Handle())->value() != 0) {
      ((__OS::CheckBox*)checkBox.Handle())->BackColor(System::Drawing::SystemColors::Highlight);
      ((__OS::CheckBox*)checkBox.Handle())->selection_color(__OS::Widget::FromColor(System::Drawing::SystemColors::HighlightText));
    } else {
      ((__OS::CheckBox*)checkBox.Handle())->BackColor(checkBox.BackColor);
      ((__OS::CheckBox*)checkBox.Handle())->selection_color(__OS::Widget::FromColor(checkBox.ForeColor));
    }
  }
}

#endif
