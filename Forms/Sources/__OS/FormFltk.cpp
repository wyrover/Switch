#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>

#include <Pcf/Undef.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Form : public __OS::Widget, public Fl_Double_Window {
  public:
    Form(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Double_Window(x, y, w, h, t), container(0, 0, w, h, "") {
      this->end();
      this->add(container);
      this->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
      this->callback(CloseForm, this);
    }

    void Color(const System::Drawing::Color& color) override {
      this->Fl_Double_Window::color(FromColor(color));
      this->container.color(FromColor(color));
    }
    
    void draw() override {this->Draw(*this);}
    
    int handle(int event) override {return this->HandleEvent(event, *this);}
    
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Double_Window::handle(event);
      this->Fl_Double_Window::draw();
      return 1;
    }
    
    const Fl_Group& Container() const override {return this->container;}
    Fl_Group& Container() override {return this->container;}
    
  private:
    static void CloseForm(Fl_Widget* widget, void* param) {
      ((__OS::Form*)param)->Close(*((__OS::Form*)param));
    }
    Fl_Scroll container;
  };
}

void FormsApi::Form::Close(System::Windows::Forms::Form& form) {
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  __OS::Form* handle = CreateControl<__OS::Form>(form);
  handle->resizable(handle->Container());
  return (intptr)handle;
}

#endif
