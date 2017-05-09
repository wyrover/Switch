#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

#include <FL/Fl_Progress.H>

#include <Pcf/Undef.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class ProgressBar : public __OS::Widget, public Fl_Progress {
  public:
    ProgressBar(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Progress(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Progress::handle(event);
      this->Fl_Progress::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  __OS::ProgressBar* handle = CreateControl<__OS::ProgressBar>(progressBar);
  handle->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).maximum(progressBar.Maximum);
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar &progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).minimum(progressBar.Minimum);
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar &progressBar) {
  
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar &progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).value(progressBar.Value);
}

#endif
