#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/fixed.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>

#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Form : public Widget, public Gtk::Window {
  public:
    Form() {
      this->RegisterEvent();
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);
      
      this->signal_show().connect(pcf_delegate {
        this->scrolledWindow.show();
        this->fixed.show();
      });
      
      this->signal_hide().connect(pcf_delegate {
        System::Windows::Forms::Control::FromHandle((intptr)this)().Visible = false;
      });
    }
    
    const Gtk::Container& Container() const override {return this->fixed;}
    
    Gtk::Container& Container() override {return this->fixed;}
    
    void Move(int32 x, int32 y) override {
      this->Gtk::Window::move(x, y);
    }
    
    void Text(const string& text) override {this->set_title(text.c_str());}
    
  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

void FormsApi::Form::Close(System::Windows::Forms::Form& form) {
  ((__OS::Form*)form.Handle())->close();
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  __OS::Form* handle = new __OS::Form();
  handle->Move(form.Location().X, form.Location().Y);
  handle->Text(form.Text);
  return (intptr)handle;
}

#endif
