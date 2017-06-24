#if defined(__linux__)

#include <gtkmm/fixed.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/window.h>

#include "WidgetGtk.hpp"
#include <Pcf/System/Random.hpp>

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
  form.Size= System::Drawing::Size(bounds.Width, bounds.Height);

  __OS::Form* handle = new __OS::Form();
  handle->Text(form.Text);
  return (intptr)handle;
}

#endif
