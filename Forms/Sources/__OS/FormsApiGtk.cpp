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
  class _IWidget pcf_interface {
  public:
    virtual const Gtk::Widget& ToWidget() const = 0;
    virtual Gtk::Widget& ToWidget() = 0;
  };

  class _Widget : public _IWidget {
  public:
  };

  class _Form : public _Widget, public Gtk::Window {
  public:
    _Form() {
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->signal_show().connect([&] {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    Gtk::Container& Container() {return this->fixed;}

    const Gtk::Widget& ToWidget() const override {return *this;}
    Gtk::Widget& ToWidget() override {return *this;}

  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };

  class _Button : public _Widget, public Gtk::Button {
  public:
    _Button() {this->set_parent(this->emptyParent);}
    void move(int32 x, int32 y) {
      ((Gtk::Fixed*)this->get_parent())->child_property_x(*this) = x;
      ((Gtk::Fixed*)this->get_parent())->child_property_y(*this) = y;
    }
    const Gtk::Widget& ToWidget() const override {return *this;}
    Gtk::Widget& ToWidget() override {return *this;}
  private:
    Gtk::Fixed emptyParent;
  };

  Gdk::RGBA FromColor(const System::Drawing::Color& color) {
    Gdk::RGBA result;
    result.set_rgba(as<double>(color.R()) / 255, as<double>(color.G()) / 255, as<double>(color.B()) / 255, as<double>(color.A()) / 255);
    return result;
  }

  System::Drawing::Color ToColor(const Gdk::RGBA& color) {
    System::Drawing::Color result = System::Drawing::Color::FromArgb(color.get_alpha() * 255, color.get_red() * 255, color.get_green() * 255, color.get_blue() * 255);
    return result;
  }

  Glib::RefPtr<Gtk::Application> application = Gtk::Application::create();
  _Form* mainForm;
  int32 exitCode = 0;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
   mainForm = (_Form*)form.data().handle;
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
  ((_Form*)form.Handle())->close();
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  _Button* gtkButton = new _Button();
  gtkButton->set_parent(mainForm->Container());
  gtkButton->override_background_color(FromColor(button.BackColor));
  gtkButton->override_color(FromColor(button.ForeColor));
  gtkButton->move(button.data().location.X, button.data().location.Y);
  gtkButton->set_size_request(button.data().size.Width, button.data().size.Height);
  return (intptr)gtkButton;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  return 0;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  _Form* gtkForm = new _Form();
  gtkForm->override_background_color(FromColor(form.BackColor));
  gtkForm->override_color(FromColor(form.ForeColor));
  gtkForm->move(form.data().location.X, form.data().location.Y);
  gtkForm->set_size_request(form.data().size.Width, form.data().size.Height);
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
 delete (Gtk::Widget*)control.data().handle;
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
  if (control.data().handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::Form>(control)) {
      ((Gtk::Window*)control.data().handle)->move(control.data().location.X, control.data().location.Y);
    } else {
      ((Gtk::Fixed*)((Gtk::Widget*)control.data().handle)->get_parent())->child_property_x(*(Gtk::Widget*)control.data().handle) = control.data().location.X;
      ((Gtk::Fixed*)((Gtk::Widget*)control.data().handle)->get_parent())->child_property_y(*(Gtk::Widget*)control.data().handle) = control.data().location.Y;
    }
  }
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
   ((Gtk::Widget*)control.data().handle)->show();
}

#endif
