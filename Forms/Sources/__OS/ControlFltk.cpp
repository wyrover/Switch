#if defined(__use_fltk_interface__)
#include "WidgetFltk.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

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

#endif
