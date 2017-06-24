#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/widget.h>

#include "WidgetGtk.hpp"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace __OS {
  class Control : public Widget, public Gtk::Widget {
  public:
    Control() {this->RegisterEvent();}
    void Text(const string& text) override {}
  };
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  __OS::Control* handle = new __OS::Control();
  handle->Move(control.Location().X, control.Location().Y);
  handle->Text(control.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {

}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
 delete (Gtk::Widget*)control.Handle();
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {

}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {

}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToClient = point - control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent() != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToClient -= workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToClient -= workControl().Parent()().Location();
  
  return pointToClient;
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  System::Drawing::Point pointToScreen = point + control.Location();
  ref<System::Windows::Forms::Control> workControl = control;
  while (workControl().Parent != null && !is<System::Windows::Forms::Form>(workControl().Parent())) {
    workControl = workControl().Parent();
    pointToScreen += workControl().Location();
  }
  
  if (workControl().Parent != null)
    pointToScreen += workControl().Parent()().Location();
  
  return pointToScreen;
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)control().Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::SystemColors::Highlight() : control().BackColor());
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->BackColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::SystemColors::Highlight() : control.BackColor());
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control &control) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(control.ClientSize().Width, control.ClientSize().Height);
  if (is<System::Windows::Forms::Form>(control))
    control.Size = System::Drawing::Size::Add(control.ClientSize, {0, SystemInformation::GetCaptionHeight()});
  else
    control.Size = control.ClientSize;
}

void FormsApi::Control::SetEnabled(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_sensitive(control.Enabled);
}

bool FormsApi::Control::SetFocus(const System::Windows::Forms::Control &control) {
  ((__OS::Widget*)control.Handle())->ToWidget().grab_focus();
  return true;
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)control().Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault ? System::Drawing::Color::White() : control().ForeColor());
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ForeColor(System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control).IsDefault ? System::Drawing::Color::White() : control.ForeColor());
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->Move(control.Location().X, control.Location().Y);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  if (control.Parent() != null) {
    //((__OS::Widget*)control.Handle())->ToWidget().reparent(((__OS::Widget*)control.Parent()().Handle())->Container());
    ((__OS::Widget*)control.Parent()().Handle())->Container().add(((__OS::Widget*)control.Handle())->ToWidget());
    SetLocation(control);
    SetVisible(control);
  }
}

void FormsApi::Control::SetSize(System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control)) {
    ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(control.Width, control.Height - SystemInformation::GetCaptionHeight());
    control.ClientSize = System::Drawing::Size::Subtract(control.Size, {0, SystemInformation::GetCaptionHeight()});
  } else {
    ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(control.Width, control.Height);
    control.ClientSize = control.Size;
  }
}

void FormsApi::Control::SetTabStop(const System::Windows::Forms::Control &control) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_can_focus(control.TabStop);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->Text(control.Text);
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
   ((Gtk::Widget*)control.Handle())->show();
}

#endif
