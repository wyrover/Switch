#if !defined(__use_native_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Label : public __OS::Widget, public Fl_Box {
  public:
    Label(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Box(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Box::handle(event);
      this->Fl_Box::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  __OS::Label* handle = CreateControl<__OS::Label>(label);
  handle->box(FL_FLAT_BOX);
  return (intptr)handle;
}

#endif
