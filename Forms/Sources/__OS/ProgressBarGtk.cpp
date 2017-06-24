#if defined(__linux__)

#include <gtkmm/progressbar.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class ProgressBar : public Widget, public Gtk::ProgressBar {
  public:
    ProgressBar() {this->RegisterEvent();}
    void BackColor(const System::Drawing::Color& color) override {}
    
    void Text(const string& text) override {}
  };
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  __OS::ProgressBar* handle = new __OS::ProgressBar();
  handle->Move(progressBar.Location().X, progressBar.Location().Y);
  handle->Text(progressBar.Text);
  handle->show();
 return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {

}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar &progressBar) {

}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar &progressBar) {
  
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar &progressBar) {
  ((__OS::ProgressBar*)progressBar.Handle())->set_fraction(double(progressBar.Value()) / (double(progressBar.Maximum()) - double(progressBar.Minimum)));
}

#endif
