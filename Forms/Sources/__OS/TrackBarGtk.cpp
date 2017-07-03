#if defined(__linux__)

#include <gtkmm.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class TrackBar : public Widget, public Gtk::Scale {
  public:
    TrackBar() {this->RegisterEvent();}
    TrackBar(Gtk::Orientation orientation) : Gtk::Scale(orientation) {this->RegisterEvent();}
    void BackColor(const System::Drawing::Color& color) override {
      this->signal_value_changed().connect(pcf_delegate {
        ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle((intptr)this);
        if (control == null) return;
        Message event = Message::Create((intptr)this, as<System::Windows::Forms::TrackBar>(control)().Orientation == Orientation::Vertical ? WM_VSCROLL : WM_HSCROLL, 0, (intptr)this, 0, 0);
        control().Parent()().WndProc(event);
      });
    }
    
    void Text(const string& text) override {}
  };
}

intptr FormsApi::TrackBar::Create(const System::Windows::Forms::TrackBar& trackBar) {
  __OS::TrackBar* handle = new __OS::TrackBar(trackBar.Orientation == Orientation::Horizontal ? Gtk::ORIENTATION_HORIZONTAL : Gtk::ORIENTATION_VERTICAL);
  handle->Move(trackBar.Location().X, trackBar.Location().Y);
  handle->Text(trackBar.Text);
  handle->set_draw_value(false);
  handle->show();
 return (intptr)handle;
}

void FormsApi::TrackBar::SetLargeChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void FormsApi::TrackBar::SetMaximum(const System::Windows::Forms::TrackBar& trackBar) {
  ((__OS::TrackBar*)trackBar.Handle())->set_range(trackBar.Minimum(), trackBar.Maximum());
}

void FormsApi::TrackBar::SetMinimum(const System::Windows::Forms::TrackBar &trackBar) {
  ((__OS::TrackBar*)trackBar.Handle())->set_range(trackBar.Minimum(), trackBar.Maximum());
}

void FormsApi::TrackBar::SetOrientation(const System::Windows::Forms::TrackBar& trackBar) {
}

void FormsApi::TrackBar::SetSmallChange(const System::Windows::Forms::TrackBar& trackBar) {
  // Not implemented on macOS
}

void FormsApi::TrackBar::SetTickFrequency(const System::Windows::Forms::TrackBar& trackBar) {
}

void FormsApi::TrackBar::SetTickStyle(const System::Windows::Forms::TrackBar& trackBar) {
  if (trackBar.Style == TickStyle::None)
    ((__OS::TrackBar*)trackBar.Handle())->clear_marks();
  else {
    Gtk::PositionType position = Gtk::POS_BOTTOM;
    if (trackBar.Orientation == Orientation::Horizontal)
      position = trackBar.Style == TickStyle::TopLeft ? Gtk::POS_TOP : Gtk::POS_BOTTOM;
    else
      position = trackBar.Style == TickStyle::TopLeft ? Gtk::POS_LEFT : Gtk::POS_RIGHT;

    for (int32 i = 0; i <= trackBar.Maximum - trackBar.Minimum; i +=  trackBar.TickFrequency)
      ((__OS::TrackBar*)trackBar.Handle())->add_mark(i, position, "");
  }
}

int32 FormsApi::TrackBar::GetValue(const System::Windows::Forms::TrackBar& trackBar) {
  return   ((__OS::TrackBar*)trackBar.Handle())->get_value();
}

void FormsApi::TrackBar::SetValue(const System::Windows::Forms::TrackBar &trackBar) {
  ((__OS::TrackBar*)trackBar.Handle())->set_value(trackBar.Value());
}

#endif
