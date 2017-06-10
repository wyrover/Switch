#if defined(__use_fltk_interface__)

#include "WindowProcedureFltk.hpp"

#include <FL/Fl_Group.H>
#include <FL/Fl_Widget.H>

namespace __OS {
  static const int32 FL_PAINT = 255;

  class IWidget pcf_interface {
  public:
    virtual const Fl_Widget& ToWidget() const = 0;
    virtual Fl_Widget& ToWidget() = 0;
};

  class Widget : public IWidget {
  public:
    static const int32 notUsed = 0;
    
    virtual void BackColor(const System::Drawing::Color& color) {this->ToWidget().color(FromColor(color));}
    virtual void ForeColor(const System::Drawing::Color& color) {this->ToWidget().labelcolor(FromColor(color));}
    
    virtual const Fl_Group& Container() const {return as<Fl_Group>(this->ToWidget());}
    virtual Fl_Group& Container() {return as<Fl_Group>(this->ToWidget());}
    
    int32 Close(Widget& control) {return control.events[FL_CLOSE](FL_CLOSE, control);}

    void Draw(Widget& control) {
      if (this->events.ContainsKey(FL_PAINT))
        this->events[FL_PAINT](FL_PAINT, control);
      else
        control.HandleControl(FL_PAINT);
    }

    int32 HandleEvent(int32 event, Widget& control) {
      if (this->events.ContainsKey(event))
        return this->events[event](event, control);
      return control.HandleControl(event);
    }

    virtual int32 HandleControl(int32 event) {
      if (event != FL_PAINT)
        return this->ToWidget().handle(event);
      this->ToWidget().draw();
      return 1;
    }
    
    const Fl_Widget& ToWidget() const override {return as<Fl_Widget>(*this);}
    Fl_Widget& ToWidget() override {return as<Fl_Widget>(*this);}
    
    static Fl_Color FromColor(const System::Drawing::Color& color) {
      return fl_rgb_color(as<byte>(color.R()), as<byte>(color.G()), as<byte>(color.B()));
    }
    
  private:
    int32 WndProc(System::Windows::Forms::Message& message) {
      ref<System::Windows::Forms::Control> control = System::Windows::Forms::Control::FromHandle(message.HWnd);
      if (control != null)
        control().WndProc(message);
      return (int32)message.Result();
    }

    int32 FlNoEvent(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlEnter(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_MOUSEENTER, notUsed, notUsed, 0, event);
      this->hover = true;
      return this->WndProc(message);
    }

    int32 FlMove(int32 event, Widget& control) {
      if (this->hover) {
        System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_MOUSEHOVER, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
        this->WndProc(message);
      }
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_MOUSEMOVE, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlPush(int32 event, Widget& control) {
      this->mouseButton = WM_LBUTTONDOWN;
      if ((GetMouseButtonState() & MK_MBUTTON) == MK_MBUTTON) this->mouseButton = WM_MBUTTONDOWN;
      if ((GetMouseButtonState() & MK_RBUTTON) == MK_RBUTTON) this->mouseButton = WM_RBUTTONDOWN;
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, this->mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlRelease(int32 event, Widget& control) {
      if (this->mouseButton == WM_LBUTTONDOWN) this->mouseButton = WM_LBUTTONUP;
      if (this->mouseButton == WM_MBUTTONDOWN) this->mouseButton = WM_MBUTTONUP;
      if (this->mouseButton == WM_RBUTTONDOWN) this->mouseButton = WM_RBUTTONUP;
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, this->mouseButton, GetMouseButtonState(), (GetMouseYCoordinateRelativeToClientArea() << 16) + GetMouseXCoordinateRelativeToClientArea(), 0, event);
      return this->WndProc(message);
    }

    int32 FlMouseWheel(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_MOUSEHWHEEL, (GetMouseWheelDelta() << 16) + GetMouseButtonState(), (GetMouseYCoordinate() << 16) + GetMouseXCoordinate(), 0, event);
      return this->WndProc(message);
    }

    int32 FlLeave(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_MOUSELEAVE, notUsed, notUsed, 0, event);
      this->hover = false;
      return this->WndProc(message);
    }

    int32 FlDrag(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFocus(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_SETFOCUS, this->previousHwndFocused, notUsed, 0, event);
      this->hwndFocused = (intptr)&control;
      return this->WndProc(message);
    }

    int32 FlUnfocus(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_KILLFOCUS, this->hwndFocused, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlKeyDown(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_KEYDOWN, (intptr)GetKeyCode(), 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlKeyUp(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_KEYUP, (intptr)GetKeyCode(), 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlClose(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_CLOSE, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

    int32 FlShortcut(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDeactivate(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_ACTIVATE, 0 /*WA_INACTIVE*/, (intptr)&control, 0, event);
      return this->WndProc(message);
    }

    int32 FlActivate(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_ACTIVATE, 1 /*WA_ACTIVE*/, (intptr)&control, 0, event);
      return this->WndProc(message);
    }

    int32 FlHide(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_SHOWWINDOW, 0 /*FALSE*/, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FLShow(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_SHOWWINDOW, 1 /*TRUE*/, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlPaste(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlSelectionClear(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndEnter(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndDrag(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndRelease(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlDndLeave(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlScreenConfiguartionChange(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFullscreen(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFormSizeChange(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlFormMove(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_NULL, 0, 0, 0, event);
      return this->WndProc(message);
    }

    int32 FlPaint(int32 event, Widget& control) {
      System::Windows::Forms::Message message = System::Windows::Forms::Message::Create((intptr)&control, WM_PAINT, notUsed, notUsed, 0, event);
      return this->WndProc(message);
    }

    using FlEventHandler = delegate<int32, int32, Widget&>;
    System::Collections::Generic::SortedDictionary<int32, FlEventHandler> events {{FL_NO_EVENT, {*this, &Widget::FlNoEvent}}, {FL_ENTER, {*this, &Widget::FlEnter}}, {FL_MOVE, {*this, &Widget::FlMove}}, {FL_PUSH, {*this, &Widget::FlPush}}, {FL_RELEASE, {*this, &Widget::FlRelease}}, {FL_MOUSEWHEEL, {*this, &Widget::FlMouseWheel}}, {FL_LEAVE, {*this, &Widget::FlLeave}}, {FL_DRAG, {*this, &Widget::FlDrag}}, {FL_FOCUS, {*this, &Widget::FlFocus}}, {FL_UNFOCUS, {*this, &Widget::FlUnfocus}}, {FL_KEYDOWN, {*this, &Widget::FlKeyDown}}, {FL_KEYUP, {*this, &Widget::FlKeyUp}}, {FL_CLOSE, {*this, &Widget::FlClose}}, {FL_SHORTCUT, {*this, &Widget::FlShortcut}}, {FL_ACTIVATE, {*this, &Widget::FlActivate}}, {FL_DEACTIVATE, {*this, &Widget::FlDeactivate}}, {FL_HIDE, {*this, &Widget::FlHide}}, {FL_SHOW, {*this, &Widget::FLShow}}, {FL_SELECTIONCLEAR, {*this, &Widget::FlSelectionClear}}, {FL_DND_ENTER, {*this, &Widget::FlDndEnter}}, {FL_DND_DRAG, {*this, &Widget::FlDndDrag}}, {FL_DND_RELEASE, {*this, &Widget::FlDndRelease}}, {FL_DND_LEAVE, {*this, &Widget::FlDndLeave}}, {FL_SCREEN_CONFIGURATION_CHANGED, {*this, &Widget::FlScreenConfiguartionChange}}, {FL_FULLSCREEN, {*this, &Widget::FlFullscreen}}, {FL_PAINT, {*this, &Widget::FlPaint}}};
    bool hover = false;
    int32 mouseButton = WM_LBUTTONDOWN;
    intptr hwndFocused = System::IntPtr::Zero;
    intptr previousHwndFocused = System::IntPtr::Zero;
  };
}

#endif
