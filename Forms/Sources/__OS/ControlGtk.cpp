#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)

#include <gtkmm/widget.h>

#include "WidgetGtk.h"

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

System::Drawing::Size FormsApi::Control::GetClientSize(const System::Windows::Forms::Control &control) {
  return {};
}

intptr FormsApi::Control::GetHandleWindowFromDeviceContext(intptr hdc) {
  return hdc;
}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, bool invalidateChildren) {

}

void FormsApi::Control::Invalidate(const System::Windows::Forms::Control& control, const System::Drawing::Rectangle& rect, bool invalidateChildren) {

}

System::Drawing::Point FormsApi::Control::PointToClient(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

System::Drawing::Point FormsApi::Control::PointToScreen(const System::Windows::Forms::Control& control, const System::Drawing::Point& point) {
  return {};
}

void FormsApi::Control::SetBackColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX && is<System::Windows::Forms::Button>(control) && as<System::Windows::Forms::Button>(control)().IsDefault)
    ((__OS::Widget*)hdc)->BackColor(System::Drawing::SystemColors::Highlight);
  else
    ((__OS::Widget*)hdc)->BackColor(control().BackColor);
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control &control, const System::Drawing::Size &clientSize) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(clientSize.Width, clientSize.Height);
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)hdc)->ForeColor(control().ForeColor);
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->BackColor(control.BackColor);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
    ((__OS::Widget*)control.Handle())->ForeColor(control.ForeColor);
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

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(control.Size().Width, control.Size().Height);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->Text(control.Text);
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
   ((Gtk::Widget*)control.Handle())->show();
}

#endif
