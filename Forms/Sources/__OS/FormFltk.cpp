#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Scroll.H>

#include <Pcf/Undef.h>
#include <Pcf/System/Random.h>

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

    void BackColor(const System::Drawing::Color& color) override {
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

intptr FormsApi::Form::Create(System::Windows::Forms::Form& form) {
  System::Drawing::Rectangle bounds = form.Bounds;
  Random random;
  switch (form.StartPosition) {
    case FormStartPosition::Manual: bounds = form.Bounds; break;
    case FormStartPosition::WindowsDefaultBounds: bounds = System::Drawing::Rectangle(System::Drawing::Rectangle(random.Next(50, 300), random.Next(50, 200), random.Next(640, 800), random.Next(480, 600))); break;
    case FormStartPosition::WindowsDefaultLocation: bounds = System::Drawing::Rectangle(System::Drawing::Rectangle(random.Next(50, 300), random.Next(50, 200), form.Width, form.Height)); break;
    default: break;
  }
  form.Location= System::Drawing::Point(bounds.Left, bounds.Top);

  __OS::Form* handle = CreateControl<__OS::Form>(form);
  handle->Fl_Window::resize(bounds.Left, bounds.Top, bounds.Width, bounds.Height);
  handle->resizable(handle->Container());
  return (intptr)handle;
}

#endif
