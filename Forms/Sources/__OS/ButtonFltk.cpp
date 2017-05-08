#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Button : public __OS::Widget, public Fl_Button {
  public:
    Button(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {
      if (this->isDefault && event == FL_SHORTCUT && (Fl::event_key() == FL_Enter || Fl::event_key() == FL_KP_Enter)) {
        this->simulate_key_action();
        this->do_callback();
        return 1;
      } else
        return this->HandleEvent(event, *this);
    }
    
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Button::handle(event);
      this->Fl_Button::draw();
      return 1;
    }
    
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
    
    void SetIsDefault(bool isDefault) {this->isDefault = isDefault;}
    
  private:
    bool isDefault = false;
  };
}

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  __OS::Button* handle = CreateControl<__OS::Button>(button);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    handle->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {
  ((__OS::Button*)button.Handle())->SetIsDefault(button.IsDefault);
}

#endif
