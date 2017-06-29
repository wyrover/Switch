#if defined(__linux__)

#include <gtkmm.h>

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
    guint marquee = 0;
    bool isMarquee = false;
  };

 int MarqueeProc(gpointer progressBar) {
    ((__OS::ProgressBar*)progressBar)->pulse();
    return 1;
  }
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  __OS::ProgressBar* handle = new __OS::ProgressBar();
  handle->Move(progressBar.Location().X, progressBar.Location().Y);
  handle->Text(progressBar.Text);
  handle->show();
 return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  // no implementation
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar &progressBar) {
    // no implementation
}

void FormsApi::ProgressBar::SetMarquee(const System::Windows::Forms::ProgressBar &progressBar) {
  if (progressBar.Style == ProgressBarStyle::Marquee) {
    ((__OS::ProgressBar*)progressBar.Handle())->isMarquee = true;
    ((__OS::ProgressBar*)progressBar.Handle())->marquee = g_timeout_add(progressBar.MarqueeAnimationSpeed(), MarqueeProc, (gpointer)progressBar.Handle());
  } else {
    if (((__OS::ProgressBar*)progressBar.Handle())->isMarquee == true) {
      g_source_remove(((__OS::ProgressBar*)progressBar.Handle())->marquee);
      ((__OS::ProgressBar*)progressBar.Handle())->isMarquee = false;
    }
  }
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar &progressBar) {
  ((__OS::ProgressBar*)progressBar.Handle())->set_fraction(double(progressBar.Value()) / (double(progressBar.Maximum()) - double(progressBar.Minimum)));
}

#endif
