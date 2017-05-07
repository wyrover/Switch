#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Form : public __OS::Widget, public Fl_Double_Window {
  public:
    Form(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Double_Window(x, y, w, h, t) {
      this->callback(CloseForm, this);
    }
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Double_Window::handle(event);
      this->Fl_Double_Window::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
    
  private:
    static void CloseForm(Fl_Widget* widget, void* param) {
      ((__OS::Form*)param)->Close(*((__OS::Form*)param));
    }
  };
}

void FormsApi::Form::Close(const System::Windows::Forms::Form& form) {
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  __OS::Form* handle = CreateControl<__OS::Form>(form);
  handle->position(form.Location().X, form.Location().Y + SystemInformation::GetCaptionHeight());
  handle->size(form.Size().Width, form.Size().Height - SystemInformation::GetCaptionHeight());
  handle->resizable(handle);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

#endif
