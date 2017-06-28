#if defined(__linux__)

#include <gtkmm/frame.h>
#include <gtkmm/scrolledwindow.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class GroupBox : public Widget, public Gtk::Frame {
  public:
    GroupBox() {
      this->RegisterEvent();
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);
      
      this->signal_show().connect(pcf_delegate {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }
    
    const Gtk::Container& Container() const override {return this->fixed;}
   
    Gtk::Container& Container() override {return this->fixed;}
    
    void Text(const string& text) override {}
    
  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
}

intptr FormsApi::GroupBox::Create(const System::Windows::Forms::GroupBox& groupBox) {
  __OS::GroupBox* handle = new __OS::GroupBox();
  handle->Move(groupBox.Location().X, groupBox.Location().Y);
  handle->Text(groupBox.Text);
  handle->show();
  return (intptr)handle;
}

#endif
