#if defined(__linux__) && defined(__use_native_interface__)
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Delegate.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

#include <gtkmm.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  class GtkForm : public Gtk::Window {
  public:
    GtkForm() {
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->signal_show().connect([&] {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    Gtk::Container& Container() {return this->fixed;}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };

  Glib::refptr<Gtk::Application> application = Gtk::Application::create();
  GtkForm* mainForm;
  int32 exitCode = 0;

  Gdk::RGBA FromColor(const System::Drawing::Color& color) {
    Gdk::RGBA result;
    result.set_rgba(as<double>(color.R()) / 255, as<double>(color.G()) / 255, as<double>(color.B()) / 255, as<double>(color.A()) / 255);
    return result;
  }
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
   mainForm = (GtkForm*)form.data().handle;
}

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  exitCode = application->run(*mainForm);
}

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  return DialogResult::Cancel;
}

void FormsApi::Application::Start() {
}

void FormsApi::Application::Stop() {
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
  ((GtkForm*)form.Handle())->close();
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  GtkForm* gtkForm = new GtkForm();
  gtkForm->override_background_color(FromColor(form.BackColor));
  gtkForm->override_color(FromColor(form.ForeColor));
  return (intptr)gtkForm;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  return 0;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
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

void FormsApi::Control::SetBackColor(intptr hdc, const System::Drawing::Color& color) {
  ((Gtk::Widget*)hdc)->override_background_color(FromColor(color));
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
  ((Gtk::Widget*)hdc)->override_color(FromColor(color));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((Gtk::Widget*)control.data().handle)->override_background_color(FromColor(control.BackColor));
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((Gtk::Widget*)control.data().handle)->override_color(FromColor(control.BackColor));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
   ((Gtk::Widget*)control.data().handle)->show();
}

#endif
