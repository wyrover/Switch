#if defined(__linux__)

#include <gtkmm/checkbutton.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class CheckBox : public Widget, public Gtk::CheckButton {
  public:
    CheckBox() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  __OS::CheckBox* handle = new __OS::CheckBox();
  handle->Move(checkBox.Location().X, checkBox.Location().Y);
  handle->Text(checkBox.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
  
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  ((__OS::CheckBox*)checkBox.Handle())->set_active(checkBox.Checked);
  ((__OS::CheckBox*)checkBox.Handle())->set_inconsistent(checkBox.CheckState == System::Windows::Forms::CheckState::Indeterminate);
}

#endif
