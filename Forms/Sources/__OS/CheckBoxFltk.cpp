#if !defined(__use_native_interface__)
#include "WidgetFltk.h"

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
      this->Fl_Check_Button::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
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
}

#endif
