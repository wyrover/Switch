#if __linux__
#include <Pcf/System/Diagnostics/Debug.h>
#include <Pcf/System/Collections/Generic/SortedDictionary.h>
#include <Pcf/System/Console.h>
#include <Pcf/System/Delegate.h>
#include <Pcf/System/NotImplementedException.h>
#include "../../Includes/Pcf/System/Windows/Forms/Application.h"
#include "../../Includes/Pcf/System/Windows/Forms/Control.h"
#include "FormsApi.h"

#include <FL/Fl.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_File_Icon.H>
#include <FL/Fl_Pixmap.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Window.H>
#undef None

#include "Exclamation.h"
#include "Information.h"
#include "Question.h"
#include "Stop.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace __OS;

namespace {
  static Fl_Pixmap exclamationIcon(Exclamation);
  static Fl_Pixmap informationIcon(Information);
  static Fl_Pixmap noneIcon(Information);
  static Fl_Pixmap questionIcon(Question);
  static Fl_Pixmap stopIcon(Stop);
  static int32 exitCode = 0;
  static int32 defaultTextSize = 12;
  static System::Collections::Generic::SortedDictionary<intptr, delegate<int32, int32>> defWindowProcs;
  static const int32 FL_PAINT = 255;

  static Fl_Color FromColor(const System::Drawing::Color& color) {
    return fl_rgb_color(as<byte>(color.R()), as<byte>(color.G()), as<byte>(color.B()));
  }

  static int32 GetMouseButtonState() {
    int32 flState = Fl::event_state();
    int32 state = 0;
    state += (flState & FL_CTRL) == FL_CTRL ? MK_CONTROL : 0;
    state += (flState & FL_BUTTON1) == FL_BUTTON1 ? MK_LBUTTON : 0;
    state += (flState & FL_BUTTON2) == FL_BUTTON2 ? MK_MBUTTON : 0;
    state += (flState & FL_BUTTON3) == FL_BUTTON3 ? MK_RBUTTON : 0;
    state += (flState & FL_SHIFT) == FL_SHIFT ? MK_SHIFT : 0;
    return state;
  }

  static int32 GetMouseWheelDelta() {
    static const int32 WHEEL_DELTA = 40;
    return -Fl::event_dy() * WHEEL_DELTA;
  }

  static int32 GetMouseXCoordinate() {
    return Fl::event_x_root();
  }

  static int32 GetMouseYCoordinate() {
    return Fl::event_y_root();
  }

  static int32 GetMouseXCoordinateRelativeToClientArea() {
    return Fl::event_x();
  }

  static int32 GetMouseYCoordinateRelativeToClientArea() {
    return Fl::event_y();
  }

  class FlWidget : public object {
  public:
    static const int32 notUsed = 0;

    int32 Close(FlWidget& control) {
      return control.events[FL_CLOSE](FL_CLOSE, control);
    }

    void Draw(FlWidget& control) {
      if (this->events.ContainsKey(FL_PAINT))
        this->events[FL_PAINT](FL_PAINT, control);
      else
        control.HandleControl(FL_PAINT);
    }

    int32 HandleEvent(int32 event, FlWidget& control) {
      if (this->events.ContainsKey(event))
        return this->events[event](event, control);
      return control.HandleControl(event);
    }

    virtual int32 HandleControl(int32 event) = 0;
    virtual const Fl_Widget& ToWidget() const = 0;
    virtual Fl_Widget& ToWidget() = 0;

  private:
     int32 WndProc(Message& message) {
      Reference<Control> control = Control::FromHandle(message.HWnd);
      if (control != null)
        control().WndProc(message);
      return 1;
    }

    int32 FlNoEvent(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlEnter(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_MOUSEENTER, notUsed, notUsed, 0, event);
      this->hover = true;
      return this->WndProc(message);
    }

    int32 FlMove(int32 event, FlWidget& control) {
      if (this->hover) {
        Message message = Message::Create((intptr)&control, WM_MOUSEHOVER, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
        this->WndProc(message);
      }
      Message message = Message::Create((intptr)&control, WM_MOUSEMOVE, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlPush(int32 event, FlWidget& control) {
      int32 mouseButton = WM_LBUTTONDOWN;
      if ((GetMouseButtonState() & MK_MBUTTON) == MK_MBUTTON)
        mouseButton = WM_MBUTTONDOWN;
      if ((GetMouseButtonState() & MK_RBUTTON) == MK_RBUTTON)
        mouseButton = WM_RBUTTONDOWN;
      Message message = Message::Create((intptr)&control, mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlRelease(int32 event, FlWidget& control) {
      int32 mouseButton = WM_LBUTTONUP;
      if ((GetMouseButtonState() & MK_MBUTTON) == MK_MBUTTON)
        mouseButton = WM_MBUTTONUP;
      if ((GetMouseButtonState() & MK_RBUTTON) == MK_RBUTTON)
        mouseButton = WM_RBUTTONUP;
      Message message = Message::Create((intptr)&control, mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlMouseWheel(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_MOUSEHWHEEL, (GetMouseWheelDelta() << 16) + GetMouseButtonState(), (GetMouseYCoordinate() << 16) + GetMouseXCoordinate(), 0, event);
      return this->WndProc(message);
    }

    int32 FlLeave(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_MOUSELEAVE, notUsed, notUsed, 0, event);
      this->hover = false;
      return this->WndProc(message);
    }

    int32 FlDrag(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFocus(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_SETFOCUS, this->previousHwndFocused, notUsed, 0, event);
      this->hwndFocused = (intptr)&control;
      return this->WndProc(message);
    }

    int32 FlUnfocus(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_KILLFOCUS, this->hwndFocused, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlKeyDown(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_KEYDOWN, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlKeyUp(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_KEYUP, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlClose(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_CLOSE, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlShortcut(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDeactivate(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlActivate(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlHide(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FLShow(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlPaste(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlSelectionClear(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndEnter(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndDrag(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndRelease(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndLeave(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlScreenConfiguartionChange(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFullscreen(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFormSizeChange(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFormMove(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlPaint(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_PAINT, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

  private:
    using FlEventHandler = delegate<int32, int32, FlWidget&>;
    System::Collections::Generic::SortedDictionary<int32, FlEventHandler> events {{FL_NO_EVENT, {*this, &FlWidget::FlNoEvent}}, {FL_ENTER, {*this, &FlWidget::FlEnter}}, {FL_MOVE, {*this, &FlWidget::FlMove}}, {FL_PUSH, {*this, &FlWidget::FlPush}}, {FL_RELEASE, {*this, &FlWidget::FlRelease}}, {FL_MOUSEWHEEL, {*this, &FlWidget::FlMouseWheel}}, {FL_LEAVE, {*this, &FlWidget::FlLeave}}, {FL_DRAG, {*this, &FlWidget::FlDrag}}, {FL_FOCUS, {*this, &FlWidget::FlFocus}}, {FL_UNFOCUS, {*this, &FlWidget::FlUnfocus}}, {FL_KEYDOWN, {*this, &FlWidget::FlKeyDown}}, {FL_KEYUP, {*this, &FlWidget::FlKeyUp}}, {FL_CLOSE, {*this, &FlWidget::FlClose}}, {FL_SHORTCUT, {*this, &FlWidget::FlShortcut}}, {FL_ACTIVATE, {*this, &FlWidget::FlActivate}}, {FL_DEACTIVATE, {*this, &FlWidget::FlDeactivate}}, {FL_HIDE, {*this, &FlWidget::FlHide}}, {FL_SHOW, {*this, &FlWidget::FLShow}}, {FL_SELECTIONCLEAR, {*this, &FlWidget::FlSelectionClear}}, {FL_DND_ENTER, {*this, &FlWidget::FlDndEnter}}, {FL_DND_DRAG, {*this, &FlWidget::FlDndDrag}}, {FL_DND_RELEASE, {*this, &FlWidget::FlDndRelease}}, {FL_DND_LEAVE, {*this, &FlWidget::FlDndLeave}}, {FL_SCREEN_CONFIGURATION_CHANGED, {*this, &FlWidget::FlScreenConfiguartionChange}}, {FL_FULLSCREEN, {*this, &FlWidget::FlFullscreen}}, {FL_PAINT, {*this, &FlWidget::FlPaint}}};
    bool hover = false;
    intptr hwndFocused = IntPtr::Zero;
    intptr previousHwndFocused = IntPtr::Zero;
  };

  class FlButton : public FlWidget, public Fl_Button {
  public:
    FlButton(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Button(x, y, w, h, t) {}
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

  class FlCheckBox : public FlWidget, public Fl_Check_Button {
  public:
    FlCheckBox(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Check_Button(x, y, w, h, t) {}
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

  class FlControl : public FlWidget, public Fl_Widget {
  public:
    FlControl(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Widget(x, y, w, h, t) {}
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

  static void CloseForm(Fl_Widget* widget, void* param);

  class FlForm : public FlWidget, public Fl_Double_Window {
  public:
    FlForm(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Double_Window(x, y, w, h, t) {
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
  };

  static void CloseForm(Fl_Widget* widget, void* param) {
    ((FlForm*)param)->Close(*((FlForm*)param));
  }

  class FlLabel : public FlWidget, public Fl_Box {
  public:
    FlLabel(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Box(x, y, w, h, t) {}
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

  class FlRadioButton : public FlWidget, public Fl_Round_Button {
  public:
    FlRadioButton(int32 x, int32 y, int32 w, int32 h, const char* t) : Fl_Round_Button(x, y, w, h, t) {}
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

bool FormsApi::Application::visualStylesEnabled = false;

void FormsApi::Application::Exit() {
  Environment::Exit(exitCode);
}

void FormsApi::Application::MessageLoop(EventHandler idle) {
  exitCode = Fl::run();
}

Fl_Pixmap& ToPixmap(MessageBoxIcon icon) {
  switch(icon) {
 case MessageBoxIcon::Exclamation : return exclamationIcon;
  case MessageBoxIcon::Information : return informationIcon;
  case MessageBoxIcon::None : return noneIcon;
  case MessageBoxIcon::Question : return questionIcon;
  case MessageBoxIcon::Stop : return stopIcon;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  fl_message_title(caption.c_str());
  fl_message_icon()->copy_label("");
  fl_message_hotspot(false);
  fl_message_icon()->align(FL_ALIGN_TEXT_NEXT_TO_IMAGE);
  fl_message_icon()->image(ToPixmap(icon));
  int result = fl_choice(message.c_str(), "No", "Yes", null);
  if (result == 0) return DialogResult::No;
  if (result == 1) return DialogResult::Yes;

  return DialogResult::None;
}

namespace {
  static int ApplicationHandler(int event) {
    return event == FL_SHORTCUT && Fl::event_key() == FL_Escape ? 1 : 0;
  }
}

void FormsApi::Application::Start() {
  Fl::get_system_colors();
  Fl_File_Icon::load_system_icons();
  Fl::lock();
  if (HasVisualStylesEnabled())
    Fl::scheme("gtk+");
  Fl::add_handler(ApplicationHandler);
}

void FormsApi::Application::Stop() {
  Fl::remove_handler(ApplicationHandler);
}

void FormsApi::Control::Close(const System::Windows::Forms::Form& form) {
}

template<typename T, typename TControl>
T* CreateControl(const TControl& control) {
  T* handle = new T(control.Location().X, control.Location().Y, control.Size().Width, control.Size().Height, control.Text().c_str());
  handle->color(FromColor(control.BackColor()));
  handle->labelcolor(FromColor(control.ForeColor()));
  handle->labelsize(defaultTextSize);
  handle->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  defWindowProcs.Add((intptr)handle, {*handle, &T::HandleControl});
  return handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Button& button) {
  FlButton* handle = CreateControl<FlButton>(button);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::CheckBox& checkBox) {
  FlCheckBox* handle = CreateControl<FlCheckBox>(checkBox);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Control& control) {
  FlControl* handle = CreateControl<FlControl>(control);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Form& form) {
  FlForm* handle = CreateControl<FlForm>(form);
  handle->resizable(handle);
  handle->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP | FL_ALIGN_WRAP);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::Label& label) {
  FlLabel* handle = CreateControl<FlLabel>(label);
  handle->box(FL_NO_BOX);
  return (intptr)handle;
}

intptr FormsApi::Control::Create(const System::Windows::Forms::RadioButton& radioButton) {
  FlRadioButton* handle = CreateControl<FlRadioButton>(radioButton);
  return (intptr)handle;
}

void FormsApi::Control::DefWndProc(System::Windows::Forms::Message& message) {
  if (defWindowProcs.ContainsKey(message.HWnd))
    message.Result = defWindowProcs[message.HWnd()](message.Handle);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::ContainerControl>(control)) {
      for (int index = 0; index < ((Fl_Group&)((FlWidget*)control.data().handle)->ToWidget()).children(); index++)
        ((Fl_Group&)((FlWidget*)control.data().handle)->ToWidget()).remove(index);
    }
    delete (FlWidget*)control.data().handle;
  }
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
  ((FlWidget*)hdc)->ToWidget().color(FromColor(color));
}

void FormsApi::Control::SetForeColor(intptr hdc, const System::Drawing::Color& color) {
  ((FlWidget*)hdc)->ToWidget().labelcolor(FromColor(color));
}

void FormsApi::Control::SetBackColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((FlWidget*)control.data().handle)->ToWidget().color(FromColor(control.BackColor()));
}

void FormsApi::Control::SetForeColor(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((FlWidget*)control.data().handle)->ToWidget().labelcolor(FromColor(control.ForeColor()));
}

void FormsApi::Control::SetLocation(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetSize(const System::Windows::Forms::Control& control) {
}

void FormsApi::Control::SetText(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero)
    ((FlWidget*)control.data().handle)->ToWidget().copy_label(control.Text().c_str());
}

void FormsApi::Control::SetVisible(const System::Windows::Forms::Control& control) {
  ((FlWidget*)control.data().handle)->ToWidget().show();
}

int32 FormsApi::SystemInformation::GetActiveWindowTrackingDelay() {
  return 0;
}

ArrangeDirection FormsApi::SystemInformation::GetArrangeDirection() {
  return ArrangeDirection::Left;
}

ArrangeStartingPosition FormsApi::SystemInformation::GetArrangeStartingPosition() {
  return ArrangeStartingPosition::Hide;
}

BootMode FormsApi::SystemInformation::GetBootMode() {
  return BootMode::Normal;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorder3DSize() {
  return System::Drawing::Size(1, 1);
}

int32 FormsApi::SystemInformation::GetBorderMultiplierFactor() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetBorderSize() {
  return System::Drawing::Size(1, 1);
}

System::Drawing::Size FormsApi::SystemInformation::GetCaptionButtonSize() {
  return System::Drawing::Size(16, 16);
}

int32 FormsApi::SystemInformation::GetCaptionHeight() {
  return 23;
}

int32 FormsApi::SystemInformation::GetCaretBlinkTime() {
  return 530;
}

int32 FormsApi::SystemInformation::GetCaretWidth() {
  return 1;
}

System::Drawing::Size FormsApi::SystemInformation::GetCursorSize() {
  return System::Drawing::Size(32, 32);
}

bool FormsApi::SystemInformation::GetDbcsEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetDebugOS() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetDoubleClickSize() {
  return System::Drawing::Size(4, 4);
}

int32 FormsApi::SystemInformation::GetDoubleClickTime() {
  return 500;
}

bool FormsApi::SystemInformation::GetDragFullWindows() {
  return true;
}

System::Drawing::Size FormsApi::SystemInformation::GetDragSize() {
  return System::Drawing::Size(4, 4);
}

System::Drawing::Size FormsApi::SystemInformation::GetFixedFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

int32 FormsApi::SystemInformation::GetFontSmoothingContrast() {
  return 1200;
}

int32 FormsApi::SystemInformation::GetFontSmoothingType() {
  return 2;
}

System::Drawing::Size FormsApi::SystemInformation::GetFrameBorderSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetHighContrast() {
  return false;
}

int32 FormsApi::SystemInformation::GetHorizontalFocusThickness() {
  return 1;
}

int32 FormsApi::SystemInformation::GetHorizontalResizeBorderThickness() {
  return 4;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarArrowWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarHeight() {
  return 17;
}

int32 FormsApi::SystemInformation::GetHorizontalScrollBarThumbWidth() {
  return 17;
}

int32 FormsApi::SystemInformation::GetIconHorizontalSpacing() {
  return 75;
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSize() {
  return System::Drawing::Size(64, 64);
}

System::Drawing::Size FormsApi::SystemInformation::GetIconSpacingSize() {
  return System::Drawing::Size(75, 75);
}

int32 FormsApi::SystemInformation::GetIconVerticalSpacing() {
  return 75;
}

bool FormsApi::SystemInformation::GetIsActiveWindowTrackingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsComboBoxAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsDropShadowEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsFlatMenuEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsFontSmoothingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsHotTrackingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsIconTitleWrappingEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsKeyboardPreferred() {
  return false;
}

bool FormsApi::SystemInformation::GetIsListBoxSmoothScrollingEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMenuFadeEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsMinimizeRestoreAnimationEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsSelectionFadeEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsSnapToDefaultEnabled() {
  return false;
}

bool FormsApi::SystemInformation::GetIsTitleBarGradientEnabled() {
  return true;
}

bool FormsApi::SystemInformation::GetIsToolTipAnimationEnabled() {
  return false;
}

int32 FormsApi::SystemInformation::GetKanjiWindowHeight() {
  return 0;
}

int32 FormsApi::SystemInformation::GetKeyboardDelay() {
  return 1;
}

int32 FormsApi::SystemInformation::GetKeyboardSpeed() {
  return 31;
}

System::Drawing::Size FormsApi::SystemInformation::GetMaxWindowTrackSize() {
  return System::Drawing::Size(0, 0);
}

bool FormsApi::SystemInformation::GetMenuAccessKeysUnderlined() {
  return false;
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuBarButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuButtonSize() {
  return System::Drawing::Size(19, 19);
}

System::Drawing::Size FormsApi::SystemInformation::GetMenuCheckSize() {
  return System::Drawing::Size(15, 15);
}

System::Drawing::Font FormsApi::SystemInformation::GetMenuFont() {
  return System::Drawing::Font::FromLogFont((intptr)0);
}

int32 FormsApi::SystemInformation::GetMenuHeight() {
  return 23;
}

#endif
