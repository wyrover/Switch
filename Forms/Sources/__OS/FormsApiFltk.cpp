#if !defined(__use_native_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

//________________________________________________________________________________________________________
//                                                                                                  Button

namespace __OS {
  class Button : public __OS::Widget, public Fl_Button {
  public:
    Button(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Button::handle(event);
      this->Fl_Button::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
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
}

//________________________________________________________________________________________________________
//                                                                                                checkBox

namespace __OS {
  class CheckBox : public __OS::Widget, public Fl_Check_Button {
  public:
    CheckBox(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Check_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Check_Button::handle(event);
      this->Fl_Check_Button::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::CheckBox::Create(const System::Windows::Forms::CheckBox& checkBox) {
  __OS::CheckBox* handle = CreateControl<__OS::CheckBox>(checkBox);
  return (intptr)handle;
}

void FormsApi::CheckBox::SetAutoCheck(const System::Windows::Forms::CheckBox& checkBox) {
  ((Fl_Check_Button&)((__OS::Widget*)checkBox.Handle())->ToWidget()).type(checkBox.AutoCheck ? FL_TOGGLE_BUTTON : FL_NORMAL_BUTTON);
}

void FormsApi::CheckBox::SetChecked(const System::Windows::Forms::CheckBox& checkBox) {
  ((Fl_Check_Button&)((__OS::Widget*)checkBox.Handle())->ToWidget()).value(checkBox.Checked);
}

//________________________________________________________________________________________________________
//                                                                                                 Control

namespace __OS {
  class Control : public __OS::Widget, public Fl_Widget {
  public:
    Control(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Widget(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Widget::handle(event);
      //this->Fl_Widget::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  __OS::Control* handle = CreateControl<__OS::Control>(control);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
  if (defWindowProcs.ContainsKey(message.HWnd) && message.Handle() != FL_NO_EVENT)
    message.Result = defWindowProcs[message.HWnd()]((int32_t)message.Handle);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.Handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::ContainerControl>(control)) {
      for (int index = 0; index < ((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).children(); index++)
        ((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).remove(index);
    }
    Message message = Message::Create((intptr)control.Handle, WM_DESTROY, 0, 0, 0, FL_NO_EVENT);
    const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
    delete (__OS::Widget*)control.Handle();
  }
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
  ((__OS::Widget*)hdc)->ToWidget().color(FromColor(System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc))().BackColor));
}

void FormsApi::Control::SetForeColor(intptr hdc) {
  ((__OS::Widget*)hdc)->ToWidget().labelcolor(FromColor(System::Windows::Forms::Control::FromHandle(GetHandleWindowFromDeviceContext(hdc))().ForeColor));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().color(FromColor(control.BackColor()));
}

void FormsApi::Control::SetClientSize(System::Windows::Forms::Control &control, const System::Drawing::Size &clientSize) {
  ((__OS::Widget*)control.Handle())->ToWidget().size(clientSize.Width, clientSize.Height);
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
    ((__OS::Widget*)control.Handle())->ToWidget().labelcolor(FromColor(control.ForeColor()));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control))
    ((__OS::Widget*)control.Handle())->ToWidget().position(control.Location().X, control.Location().Y + SystemInformation::GetCaptionHeight());
  else if (is<System::Windows::Forms::ProgressBar>(control)) {
    System::Drawing::Point offset;
    if (control.Parent() != null && !is<System::Windows::Forms::Form>(control.Parent()))
      offset = control.Parent()().Location;
    offset = System::Drawing::Point::Add(offset, {0, control.Height > 6 ? (control.Height - 6) / 2 : 0});
    ((__OS::Widget*)control.Handle())->ToWidget().position(control.Location().X + offset.X, control.Location().Y + offset.Y);
  } else
    ((__OS::Widget*)control.Handle())->ToWidget().position(control.Location().X, control.Location().Y);
}

void FormsApi::Control::SetParent(const System::Windows::Forms::Control& control) {
  if (((Fl_Group&)((__OS::Widget*)control.Handle())->ToWidget()).parent() != null)
    ((__OS::Widget*)control.Handle())->ToWidget().parent()->remove(((__OS::Widget*)control.Handle())->ToWidget());
  if (control.Parent() != null)
    ((Fl_Group&)((__OS::Widget*)control.Parent()().Handle())->ToWidget()).add(((__OS::Widget*)control.Handle())->ToWidget());
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
  if (is<System::Windows::Forms::Form>(control))
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, control.Size().Height - SystemInformation::GetCaptionHeight());
  else if (is<System::Windows::Forms::ProgressBar>(control)) {
    System::Drawing::Point offset;
    if (control.Parent() != null && !is<System::Windows::Forms::Form>(control.Parent()))
      offset = control.Parent()().Location;
    offset = System::Drawing::Point::Add(offset, {0, control.Height > 6 ? (control.Height - 6) / 2 : 0});
    ((__OS::Widget*)control.Handle())->ToWidget().position(control.Location().X + offset.X, control.Location().Y + offset.Y);
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, 6);
  } else
    ((__OS::Widget*)control.Handle())->ToWidget().size(control.Size().Width, control.Size().Height);
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().copy_label(control.Text().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ((__OS::Widget*)control.Handle())->ToWidget().show();
}

//________________________________________________________________________________________________________
//                                                                                                    Form

namespace __OS {
  class Form : public __OS::Widget, public Fl_Double_Window {
  public:
    Form(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Double_Window(x, y, w, h, t) {
      this->callback(CloseForm, this);
    }
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Double_Window::handle(event);
      this->Fl_Double_Window::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
    
  private:
    static void CloseForm(Fl_Widget* widget, void* param) {
      ((__OS::Form*)param)->Close(*((__OS::Form*)param));
    }
  };
}

void FormsApi::Form::Close(const System::Windows::Forms::Form& form) {
}

intptr FormsApi::Form::Create(const System::Windows::Forms::Form& form) {
  __OS::Form* handle = CreateControl<__OS::Form>(form);
  handle->position(form.Location().X, form.Location().Y + SystemInformation::GetCaptionHeight());
  handle->size(form.Size().Width, form.Size().Height - SystemInformation::GetCaptionHeight());
  handle->resizable(handle);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

//________________________________________________________________________________________________________
//                                                                                                   Label

namespace __OS {
  class Label : public __OS::Widget, public Fl_Box {
  public:
    Label(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Box(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Box::handle(event);
      this->Fl_Box::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Label::Create(const System::Windows::Forms::Label& label) {
  __OS::Label* handle = CreateControl<__OS::Label>(label);
  handle->box(FL_FLAT_BOX);
  return (intptr)handle;
}

//________________________________________________________________________________________________________
//                                                                                                   Panel

namespace __OS {
  class Panel : public __OS::Widget, public Fl_Scroll {
  public:
    Panel(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Scroll(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Scroll::handle(event);
      this->Fl_Scroll::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::Panel::Create(const System::Windows::Forms::Panel& panel) {
  __OS::Panel* handle = CreateControl<__OS::Panel>(panel);
  return (intptr)handle;
}

void FormsApi::Panel::SetBorderStyle(const System::Windows::Forms::Panel &panel) {
  switch (panel.BorderStyle) {
    case System::Windows::Forms::BorderStyle::None: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_NO_BOX : FL_FLAT_BOX); break;
    case System::Windows::Forms::BorderStyle::FixedSingle: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_BORDER_FRAME : FL_BORDER_BOX); break;
    case System::Windows::Forms::BorderStyle::Fixed3D: ((__OS::Panel*)panel.Handle())->box(panel.BackColor == Color::Transparent ? FL_DOWN_FRAME : FL_DOWN_BOX); break;
  }
}

//________________________________________________________________________________________________________
//                                                                                             ProgressBar

namespace __OS {
  class ProgressBar : public __OS::Widget, public Fl_Progress {
  public:
    ProgressBar(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Progress(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Progress::handle(event);
      this->Fl_Progress::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::ProgressBar::Create(const System::Windows::Forms::ProgressBar& progressBar) {
  __OS::ProgressBar* handle = CreateControl<__OS::ProgressBar>(progressBar);
  handle->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::ProgressBar::SetMaximum(const System::Windows::Forms::ProgressBar& progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).maximum(progressBar.Maximum);
}

void FormsApi::ProgressBar::SetMinimum(const System::Windows::Forms::ProgressBar &progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).minimum(progressBar.Minimum);
}

void FormsApi::ProgressBar::SetStyle(const System::Windows::Forms::ProgressBar &progressBar) {
  
}

void FormsApi::ProgressBar::SetValue(const System::Windows::Forms::ProgressBar &progressBar) {
  ((Fl_Progress&)((__OS::Widget*)progressBar.Handle())->ToWidget()).value(progressBar.Value);
}

//________________________________________________________________________________________________________
//                                                                                             RadioButton

namespace __OS {
  class RadioButton : public __OS::Widget, public Fl_Round_Button {
  public:
    RadioButton(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Round_Button(x, y, w, h, t) {}
    void draw() override {this->Draw(*this);}
    int handle(int event) override {return this->HandleEvent(event, *this);}
    int32 HandleControl(int32 event) override {
      if (event != FL_PAINT)
        return this->Fl_Round_Button::handle(event);
      this->Fl_Round_Button::draw();
      return 1;
    }
    const Fl_Widget& ToWidget() const override {return *this;}
    Fl_Widget& ToWidget() override {return *this;}
  };
}

intptr FormsApi::RadioButton::Create(const System::Windows::Forms::RadioButton& radioButton) {
  __OS::RadioButton* handle = CreateControl<__OS::RadioButton>(radioButton);
  if (System::Environment::OSVersion().Platform == System::PlatformID::MacOSX)
    handle->selection_color(FromColor(System::Drawing::SystemColors::Highlight));
  return (intptr)handle;
}

void FormsApi::RadioButton::SetAutoCheck(const System::Windows::Forms::RadioButton& radioButton) {
  ((Fl_Round_Button&)((__OS::Widget*)radioButton.Handle())->ToWidget()).type(radioButton.AutoCheck ? FL_RADIO_BUTTON : FL_NORMAL_BUTTON);
}

void FormsApi::RadioButton::SetChecked(const System::Windows::Forms::RadioButton& radioButton) {
  ((Fl_Round_Button&)((__OS::Widget*)radioButton.Handle())->ToWidget()).value(radioButton.Checked);
}

#endif
