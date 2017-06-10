#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/label.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Label : public Widget, public Gtk::Label {
  public:
    Label() {
      //LIGN_START);
      //this->set_justify(Gtk::JUSTIFY_LEFT);
      gtk_label_set_xalign (this->gobj(), textAlignLeft);
      gtk_label_set_yalign (this->gobj(), textAlignTop);
      this->RegisterEvent();
    }
    void Text(const string& text) override {this->set_label(text.c_str());}
    
  private:
    constexpr static float textAlignLeft = 0;
    constexpr static float textAlignMidle = 0.5;
    constexpr static float textAlignRigth = 1;
    constexpr static float textAlignTop = 0;
    constexpr static float textAlignCenter = 0.5;
    constexpr static float textAlignBottom = 1;
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
