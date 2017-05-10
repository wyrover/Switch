#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/label.h>

#include "WidgetGtk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Label : public Widget, public Gtk::Label {
  public:
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
}

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  __OS::Label* handle = new __OS::Label();
  handle->Move(label.Location().X, label.Location().Y);
  handle->Text(label.Text);
  handle->show();
  return (intptr)handle;
}

#endif
