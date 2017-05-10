#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/radiobutton.h>

#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class RadioButton : public Widget, public Gtk::RadioButton {
  public:
    RadioButton() {this->RegisterEvent();}
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  __OS::RadioButton* handle = new __OS::RadioButton();
  handle->Move(radioButton.Location().X, radioButton.Location().Y);
  handle->Text(radioButton.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
  if (radioButton.AutoCheck) {
    if (radioButton.Parent != null)
      ((__OS::RadioButton*)radioButton.Handle())->set_group(((__OS::Widget*)radioButton.Parent()().Handle())->RadioButtonGroup());
  } else
    ((__OS::RadioButton*)radioButton.Handle())->reset_group();
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((__OS::RadioButton*)radioButton.Handle())->set_active(radioButton.Checked);
}

#endif
