#if defined(__linux__)

#include <gtkmm/button.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace Native;

namespace Native {
  class Button : public Widget, public Gtk::Button {
  public:
    Button() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  Native::Button* handle = new Native::Button();
  handle->Move(button.Location().X, button.Location().Y);
  handle->Text(button.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {

}

#endif
