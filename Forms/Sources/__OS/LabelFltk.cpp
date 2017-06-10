#if defined(__use_fltk_interface__)
#include "WidgetFltk.hpp"

#include <FL/Fl_Box.H>

#include <Pcf/Undef.hpp>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Label : public __OS::Widget, public Fl_Box {
  public:
    Label(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Box(x, y, w, h, t) {}
    void draw() override {
      this->box(FL_FLAT_BOX);
      this->align(FL_ALIGN_TOP_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      this->Draw(*this);
    }
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Box::handle(event);
      this->Fl_Box::draw();
      return 1;
    }
  };
}

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  __OS::Label* handle = CreateControl<__OS::Label>(label);
  return (intptr)handle;
}

#endif
