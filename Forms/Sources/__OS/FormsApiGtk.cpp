#if (defined(__linux__) && defined(__use_native_interface__)) || defined(__use_gtk_interface__)
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

namespace __OS {
  class IWidget pcf_interface {
  public:
    virtual const Gtk::Container& Container() const = 0;
    virtual Gtk::Container& Container() = 0;

    virtual const Gtk::Widget& ToWidget() const = 0;
    virtual Gtk::Widget& ToWidget() = 0;

    virtual void Move(int32 x, int32 y) = 0;
    virtual void Show() = 0;
    virtual void Text(const string& text) = 0;
  };

  class Widget : public IWidget {
  public:
    const Gtk::Container& Container() const override {return as<Gtk::Container>(this->ToWidget());}
    Gtk::Container& Container() override {return as<Gtk::Container>(this->ToWidget());}
    
    const Gtk::Widget& ToWidget() const override {return as<Gtk::Widget>(*this);}
    Gtk::Widget& ToWidget() override {return as<Gtk::Widget>(*this);}
    
    void Move(int32 x, int32 y) override {
      if (is<Gtk::Fixed>(this->ToWidget().get_parent())) {
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_x(this->ToWidget()) = x;
        as<Gtk::Fixed>(this->ToWidget().get_parent())->child_property_y(this->ToWidget()) = y;
      }
    }
    
    void Show() override {
      return this->ToWidget().show();
    }
  };

  class Form : public Widget, public Gtk::Window {
  public:
    Form() {
      this->add(this->scrolledWindow);
      this->scrolledWindow.add(this->fixed);

      this->signal_show().connect([&] {
        this->scrolledWindow.show();
        this->fixed.show();
      });
    }

    const Gtk::Container& Container() const override {return this->fixed;}
    Gtk::Container& Container() override {return this->fixed;}

    void Move(int32 x, int32 y) override {
      this->Gtk::Window::move(x, y);
    }

    void Text(const string& text) override {
    }
    
  private:
    Gtk::ScrolledWindow scrolledWindow;
    Gtk::Fixed fixed;
  };
  
  class Button : public Widget, public Gtk::Button {
  public:
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
  
  class Control : public Widget, public Gtk::Widget {
  public:
    void Text(const string& text) override {}
  };
  
  class CheckBox : public Widget, public Gtk::CheckButton {
  public:
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
  
  class Label : public Widget, public Gtk::Label {
  public:
    void Text(const string& text) override {this->set_label(text.c_str());}
  };
  
  class Panel : public Widget, public Gtk::ScrolledWindow {
  public:
    void Text(const string& text) override {}
  };
  
  class ProgressBar : public Widget, public Gtk::ProgressBar {
  public:
    void Text(const string& text) override {}
  };
  
  class RadioButton : public Widget, public Gtk::RadioButton {
  public:
    void Text(const string& text) override {this->set_label(text.c_str());}
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
  __OS::Form* mainForm;
  int32 exitCode = 0;
}

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::AddForm(const System::Windows::Forms::Form& form) {
   mainForm = (__OS::Form*)form.Handle();
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

intptr FormsApi::Button::Create(const System::Windows::Forms::Button& button) {
  __OS::Button* handle = new __OS::Button();
  mainForm->Container().add(*handle);
  handle->Move(button.Location().X, button.Location().Y);
  handle->Text(button.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Button::SetIsDefault(const System::Windows::Forms::Button& button) {

}

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  __OS::CheckBox* handle = new __OS::CheckBox();
  mainForm->Container().add(*handle);
  handle->Move(checkBox.Location().X, checkBox.Location().Y);
  handle->Text(checkBox.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
  
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  __OS::Control* handle = new __OS::Control();
  mainForm->Container().add(*handle);
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
    ((__OS::Widget*)hdc)->ToWidget().override_background_color(FromColor(System::Drawing::SystemColors::Highlight));
  else
    ((__OS::Widget*)hdc)->ToWidget().override_background_color(FromColor(control().BackColor));
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control &control, const System::Drawing::Size &clientSize) {
  ((__OS::Widget*)control.Handle())->ToWidget().set_size_request(clientSize.Width, clientSize.Height);
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc));
  ((__OS::Widget*)hdc)->ToWidget().override_color(FromColor(control().ForeColor));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().override_background_color(FromColor(control.BackColor));
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().override_color(FromColor(control.ForeColor));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->Move(control.Location().X, control.Location().Y);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  if (control.Parent() != null)
    ((__OS::Widget*)control.Parent()().Handle())->Container().add(((__OS::Widget*)control.Handle())->ToWidget());
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

void FormsApi::Form::Close(const System::Windows::Forms::Form& form) {
  ((__OS::Form*)form.Handle())->close();
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  __OS::Form* handle = new __OS::Form();
  mainForm = handle;
  handle->Move(form.Location().X, form.Location().Y);
  handle->Text(form.Text);
  return (intptr)handle;
}

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  __OS::Label* handle = new __OS::Label();
  mainForm->Container().add(*handle);
  handle->Move(label.Location().X, label.Location().Y);
  handle->Text(label.Text);
  handle->show();
  return (intptr)handle;
}

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  __OS::Panel* handle = new __OS::Panel();
  mainForm->Container().add(*handle);
  handle->Move(panel.Location().X, panel.Location().Y);
  handle->Text(panel.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel &panel) {
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  __OS::ProgressBar* handle = new __OS::ProgressBar();
  mainForm->Container().add(*handle);
  handle->Move(progressBar.Location().X, progressBar.Location().Y);
  handle->Text(progressBar.Text);
  handle->show();
 return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {

}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar &progressBar) {

}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar &progressBar) {
  
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar &progressBar) {

}

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  __OS::RadioButton* handle = new __OS::RadioButton();
  mainForm->Container().add(*handle);
  handle->Move(radioButton.Location().X, radioButton.Location().Y);
  handle->Text(radioButton.Text);
  handle->show();
  return (intptr)handle;
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
  
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  
}

#endif
