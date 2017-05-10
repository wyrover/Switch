#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/scrolledwindow.h>

#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Panel : public Widget, public Gtk::ScrolledWindow {
  public:
    Panel() {
      this->add(this->fixed);
      
      this->signal_show().connect(pcf_delegate {
        this->fixed.show();
      });
    }
    
    const Gtk::Container& Container() const override {return this->fixed;}
   
    Gtk::Container& Container() override {return this->fixed;}
    
    void Text(const string& text) override {}
    
  private:
    Gtk::Fixed fixed;
  };
}

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  __OS::Panel* handle = new __OS::Panel();
  handle->Move(panel.Location().X, panel.Location().Y);
  handle->Text(panel.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel &panel) {
}

#endif
