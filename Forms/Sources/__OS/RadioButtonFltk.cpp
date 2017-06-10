#if defined(__use_fltk_interface__)
#include "WidgetFltk.hpp"

#include <FL/Fl_Round_Button.H>

#include <Pcf/Undef.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class RadioButton : public __OS::Widget, public Fl_Round_Button {
  public:
    RadioButton(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Round_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Round_Button::handle(event);
      this->Fl_Round_Button::draw();
      return 1;
    }
  };
}

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  __OS::RadioButton* handle = CreateControl<__OS::RadioButton>(radioButton);
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    handle->selection_color(__OS::Widget::FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((Fl_Round_Button&)((__OS::Widget*)radioButton.Handle())->ToWidget()).value(radioButton.Checked);
}

void FormsApi::RadioButton::SetGroup(const System::Windows::Forms::RadioButton& radioButton) {
}

#endif
