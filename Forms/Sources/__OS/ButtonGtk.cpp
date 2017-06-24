#if defined(__linux__)

#include <gtkmm/button.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Button : public Widget, public Gtk::Button {
  public:
    Button() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  __OS::Button* handle = new __OS::Button();
  handle->Move(button.Location().X, button.Location().Y);
  handle->Text(button.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {

}

#endif
