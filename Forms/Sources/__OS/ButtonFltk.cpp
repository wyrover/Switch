#if !defined(__use_native_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Button : public __OS::Widget, public Fl_Button {
  public:
    Button(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Button::handle(event);
      this->Fl_Button::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  __OS::Button* handle = CreateControl<__OS::Button>(button);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    handle->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {
}

#endif
