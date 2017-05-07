#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Panel : public __OS::Widget, public Fl_Scroll {
  public:
    Panel(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Scroll(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Scroll::handle(event);
      this->Fl_Scroll::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  __OS::Panel* handle = CreateControl<__OS::Panel>(panel);
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel &panel) {
  switch (panel.BorderStyle) {
    case System::Windows::Forms::BorderStyle::None: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::Forms::BorderStyle::FixedSingle: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::Forms::BorderStyle::Fixed3D: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

#endif
