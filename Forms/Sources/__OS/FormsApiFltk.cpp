#if defined(__fltk__)
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
#include <FL/fl_draw.H>
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

  static System::Windows::Forms::Keys GetKeyCode() {
    using namespace System::Windows::Forms;
    System::Collections::Generic::SortedDictionary<int32, Keys> keys {
      {FL_BackSpace, Keys::Back}, {FL_Tab, Keys::Tab}, {FL_Iso_Key, Keys::OemBackslash},{FL_Enter, Keys::Enter}, {FL_Pause, Keys::Pause}, {FL_Scroll_Lock, Keys::Scroll}, {FL_Escape, Keys::Escape},
      {FL_Kana, Keys::Delete}, {FL_Eisu, Keys::Help}, {FL_Yen, Keys::D0}, {FL_JIS_Underscore, Keys::D1}, {FL_Home, Keys::Home}, {FL_Left, Keys::Left}, {FL_Up, Keys::Up}, {FL_Right, Keys::Right},
      {FL_Down, Keys::Down}, {FL_Page_Up, Keys::PageUp}, {FL_Page_Down, Keys::PageDown}, {FL_End, Keys::End}, {FL_Print, Keys::PrintScreen}, {FL_Insert, Keys::Insert}, {FL_Menu, Keys::Menu},
      {FL_Help, Keys::Help}, {FL_Num_Lock, Keys::NumLock}, {FL_KP + 0, Keys::NumPad0}, {FL_KP + 1, Keys::NumPad1}, {FL_KP + 2, Keys::NumPad2}, {FL_KP + 3, Keys::NumPad3}, {FL_KP + 4, Keys::NumPad4},
      {FL_KP + 5, Keys::NumPad5}, {FL_KP + 6, Keys::NumPad6}, {FL_KP + 7, Keys::NumPad7}, {FL_KP + 8, Keys::NumPad8}, {FL_KP + 9, Keys::NumPad9}, {FL_KP_Enter, Keys::Enter}, {FL_F+1, Keys::F1},
      {FL_F+2, Keys::F2}, {FL_F+3, Keys::F3}, {FL_F+4, Keys::F4}, {FL_F+5, Keys::F5}, {FL_F+6, Keys::F6}, {FL_F+7, Keys::F7}, {FL_F+8, Keys::F8}, {FL_F+9, Keys::F9}, {FL_F+10, Keys::F10},
      {FL_F+11, Keys::F11}, {FL_F+12, Keys::F12}, {FL_F+13, Keys::F13}, {FL_F+14, Keys::F14}, {FL_F+15, Keys::F15}, {FL_F+16, Keys::F16}, {FL_F+17, Keys::F17}, {FL_F+18, Keys::F18}, {FL_F+19, Keys::F19},
      {FL_F+20, Keys::F20}, {FL_F+21, Keys::F21}, {FL_F+22, Keys::F22}, {FL_F+23, Keys::F23}, {FL_F+24, Keys::F24}, {FL_Shift_L, Keys::ShiftKey /*Keys::LShiftKey*/}, {FL_Shift_R, Keys::ShiftKey /*Keys::RShiftKey*/},
      {FL_Control_L, Keys::ControlKey /*Keys::LControlKey*/}, {FL_Control_R, Keys::ControlKey /*Keys::RControlKey*/}, {FL_Caps_Lock, Keys::CapsLock},
      {FL_Meta_L, Keys::CommandKey /*Keys::LCommandKey*/}, {FL_Meta_R, Keys::CommandKey /*Keys::RCommandKey*/},
      {FL_Alt_L, Keys::Alt /*KeysLAlt*/}, {FL_Alt_R, Keys::Alt /*Keys::RAlt*/}, {FL_Delete, Keys::Delete}, {0x0027, Keys::OemQuotes}, {0xFFAA, Keys::Multiply}, {0xFFAB, Keys::Add}, {0xFFAD, Keys::Subtract},
      {0xFFAE, Keys::Decimal}, {0xFFAF, Keys::Divide}, {0xFFBD, Keys::Packet}, {0x0029, Keys::OemOpenBrackets}, {0x002C, Keys::Oemcomma}, {0x002D, Keys::OemMinus}, {0x002E, Keys::OemPeriod},
      {0x002F, Keys::OemQuestion}, {0x003A, Keys::Oemtilde}, {0x003B, Keys::OemSemicolon}, {0x003C, Keys::OemBackslash}, {0x003D, Keys::Oemplus}, {0x005B, Keys::OemOpenBrackets}, {0x005C, Keys::OemPipe},
      {0x005D, Keys::OemCloseBrackets}, {0x0060, Keys::Oemtilde}
    };

    int32 key = Fl::event_key();
    if (Fl::event_ctrl() && key >= 'a' && key <= 'z')
      key -= 96;
    if (key >= 'a' && key <= 'z')
      key -= 32;

    Keys keyCode = static_cast<Keys>(key);;
    if (keys.ContainsKey(key))
      keyCode = keys[key];

    if (Fl::event_command())
      keyCode |= static_cast<Keys>(0x80000);
    else
      keyCode &= static_cast<Keys>(~0x80000);

    if (Fl::event_alt())
      keyCode |= static_cast<Keys>(0x40000);
    else
      keyCode &= static_cast<Keys>(~0x40000);

    if (Fl::event_ctrl())
      keyCode |= static_cast<Keys>(0x20000);
    else
      keyCode &= static_cast<Keys>(~0x20000);

    if (Fl::event_shift())
      keyCode |= static_cast<Keys>(0x10000);
    else
      keyCode &= static_cast<Keys>(~0x10000);

    return keyCode;
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

  class IFlWidget pcf_interface {
  public:
    virtual const Fl_Widget& ToWidget() const = 0;
    virtual Fl_Widget& ToWidget() = 0;
  };

  class FlWidget : public IFlWidget {
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
      this->mouseButton = WM_LBUTTONDOWN;
      if ((GetMouseButtonState() & MK_MBUTTON) == MK_MBUTTON) this->mouseButton = WM_MBUTTONDOWN;
      if ((GetMouseButtonState() & MK_RBUTTON) == MK_RBUTTON) this->mouseButton = WM_RBUTTONDOWN;
      Message message = Message::Create((intptr)&control, this->mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlRelease(int32 event, FlWidget& control) {
      if (this->mouseButton == WM_LBUTTONDOWN) this->mouseButton = WM_LBUTTONUP;
      if (this->mouseButton == WM_MBUTTONDOWN) this->mouseButton = WM_MBUTTONUP;
      if (this->mouseButton == WM_RBUTTONDOWN) this->mouseButton = WM_RBUTTONUP;
      Message message = Message::Create((intptr)&control, this->mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
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
      Message message = Message::Create((intptr)&control, WM_KEYDOWN, (intptr)GetKeyCode(), 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlKeyUp(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_KEYUP, (intptr)GetKeyCode(), 0, 0, event);
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
      Message message = Message::Create((intptr)&control, WM_ACTIVATE, 0 /*WA_INACTIVE*/, (intptr)&control, 0, event);
      return this->WndProc(message);
    }

    int32 FlActivate(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_ACTIVATE, 1 /*WA_ACTIVE*/, (intptr)&control, 0, event);
      return this->WndProc(message);
    }

    int32 FlHide(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_SHOWWINDOW, 0 /*FALSE*/, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FLShow(int32 event, FlWidget& control) {
      Message message = Message::Create((intptr)&control, WM_SHOWWINDOW, 1 /*TRUE*/, 0, 0, event);
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
    int32 mouseButton = WM_LBUTTONDOWN;
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

void FormsApi::Application::MessageBeep(MessageBoxIcon type) {
  System::Collections::Generic::SortedDictionary<MessageBoxIcon, int32> beep = {{(MessageBoxIcon)0, FL_BEEP_DEFAULT}, {MessageBoxIcon::Error, FL_BEEP_ERROR}, {MessageBoxIcon::Question, FL_BEEP_QUESTION}, {MessageBoxIcon::Warning, FL_BEEP_MESSAGE}, {MessageBoxIcon::Information, FL_BEEP_NOTIFICATION}, {(MessageBoxIcon)0xFFFFFFFF, FL_BEEP_DEFAULT}};
  fl_beep(beep[type]);
}

namespace {
  DialogResult ShowMessageBoxAbortRetryIgnore(const string& message) {
    int result = fl_choice("%s", "Abort", "Retry", "Ignore", message.c_str());
    if (result == 0) return DialogResult::Abort;
    if (result == 2) return DialogResult::Ignore;
    return DialogResult::Retry;
  }

  DialogResult ShowMessageBoxOK(const string& message) {
    fl_choice("%s", "OK", null, null, message.c_str());
    return DialogResult::OK;
  }

  DialogResult ShowMessageBoxOKCancel(const string& message) {
    int result = fl_choice("%s", "Cancel", "OK", null, message.c_str());
    if (result == 0) return DialogResult::Cancel;
    return DialogResult::OK;
  }

  DialogResult ShowMessageBoxRetryCancel(const string& message) {
    int result = fl_choice("%s", "Cancel", "Retry", null, message.c_str());
    if (result == 0) return DialogResult::Cancel;
    return DialogResult::Retry;
  }

  DialogResult ShowMessageBoxYesNo(const string& message) {
    int result = fl_choice("%s", "No", "Yes", null, message.c_str());
    if (result == 0) return DialogResult::No;
    return DialogResult::Yes;
  }

  DialogResult ShowMessageBoxYesNoCancel(const string& message) {
    int result = fl_choice("%s", "No", "Yes", "Cancel", message.c_str());
    if (result == 0) return DialogResult::No;
    if (result == 2) return DialogResult::Cancel;
    return DialogResult::Yes;
  }
}

DialogResult FormsApi::Application::ShowMessageBox(const string& message, const string& caption, MessageBoxButtons buttons, MessageBoxIcon icon, MessageBoxDefaultButton defaultButton, MessageBoxOptions options, bool displayHelpButton) {
  static System::Collections::Generic::SortedDictionary<MessageBoxButtons, delegate<DialogResult, const string&>> showMessageBox = {{MessageBoxButtons::AbortRetryIgnore, ShowMessageBoxAbortRetryIgnore}, {MessageBoxButtons::OK, ShowMessageBoxOK}, {MessageBoxButtons::OKCancel, ShowMessageBoxOKCancel}, {MessageBoxButtons::RetryCancel, ShowMessageBoxRetryCancel}, {MessageBoxButtons::YesNo, ShowMessageBoxYesNo}, {MessageBoxButtons::YesNoCancel, ShowMessageBoxYesNoCancel}};
  static System::Collections::Generic::SortedDictionary<MessageBoxIcon, Fl_Pixmap*> messageBoxIcon = {{MessageBoxIcon::Exclamation, &exclamationIcon}, {MessageBoxIcon::Information, &informationIcon}, {MessageBoxIcon::None, &noneIcon}, {MessageBoxIcon::Question, &questionIcon}, {MessageBoxIcon::Stop, &stopIcon}};
  fl_message_icon()->align(FL_ALIGN_TEXT_NEXT_TO_IMAGE);
  fl_message_icon()->box(FL_NO_BOX);
  fl_message_icon()->hide();
  fl_message_icon()->label("");
  Fl_Group* messageBox = fl_message_icon()->parent();
  messageBox->color(FromColor(System::Drawing::Color::White));
  messageBox->labelsize(defaultTextSize);
  for (int index = 0; index < messageBox->children(); index++) {
    messageBox->child(index)->color(FromColor(System::Windows::Forms::Control::DefaultBackColor));
    messageBox->child(index)->labelsize(defaultTextSize);
  }

  fl_message_title(caption.c_str());
  if (icon != MessageBoxIcon::None) {
    fl_message_icon()->show();
    fl_message_icon()->image(messageBoxIcon[icon]);
  }
  return showMessageBox[buttons](message);
}

namespace {
  static int32 ApplicationHandler(int32 event) {
    return event == FL_SHORTCUT && Fl::event_key() == FL_Escape ? 1 : 0;
  }

  static void DrawLabel(const Fl_Label *label, int left, int top, int width, int height, Fl_Align align) {
    fl_font(label->font, label->size);
    fl_color((Fl_Color)label->color);
    fl_draw(label->value, left, top, width, height, align, label->image, 0 /*1 (default): replace patterns (like "@->") by symbols; 0: do not replace patterns by symbols*/);
  }

  static void MeasureLabel(const Fl_Label *label, int &width, int &height) {
    fl_font(label->font, label->size);
    fl_measure(label->value, width, height, 0 /*1 (default): replace patterns (like "@->") by symbols; 0: do not replace patterns by symbols*/);
  }
}

void FormsApi::Application::Start() {
  Fl_Window::default_xclass(System::IO::Path::GetFileName(System::Environment::GetCommandLineArgs()[0]).c_str());
  Fl::set_labeltype(FL_NORMAL_LABEL, DrawLabel, MeasureLabel);
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
  Message message = Message::Create((intptr)handle, WM_CREATE, 0, 0, 0, FL_NO_EVENT);
  const_cast<TControl&>(control).WndProc(message);
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
  handle->position(form.Location().X, form.Location().Y + SystemInformation::GetCaptionHeight());
  handle->size(form.Size().Width, form.Size().Height - SystemInformation::GetCaptionHeight());
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
  if (defWindowProcs.ContainsKey(message.HWnd) && message.Handle() != FL_NO_EVENT)
    message.Result = defWindowProcs[message.HWnd()](message.Handle);
}

void FormsApi::Control::Destroy(const System::Windows::Forms::Control& control) {
  if (control.data().handle != IntPtr::Zero) {
    if (is<System::Windows::Forms::ContainerControl>(control)) {
      for (int index = 0; index < ((Fl_Group&)((FlWidget*)control.data().handle)->ToWidget()).children(); index++)
        ((Fl_Group&)((FlWidget*)control.data().handle)->ToWidget()).remove(index);
    }
    Message message = Message::Create((intptr)control.data().handle, WM_DESTROY, 0, 0, 0, FL_NO_EVENT);
    const_cast<System::Windows::Forms::Control&>(control).WndProc(message);
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

#endif
